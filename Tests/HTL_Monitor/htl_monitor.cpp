#include "EquipementHandlers/PressureSensor.h"
#include "EquipementHandlers/PT1000.h"
#include "EquipementHandlers/TC74TempSensor.h"
#include "EquipementHandlers/MCP3008.h"
#include "Utils/CSVWriter.h"
#include <math.h>   // modf
#include <unistd.h> // Getopt
#include <stdlib.h> // strtof
#include <signal.h> // signal
#include <iostream>
#include <sys/time.h>
#include <string>
#include <iomanip>  // well formated output.
#include <chrono>   // time

using namespace utils;
using namespace equipementHandlers;

/* Global variabels:
 ******************************************************************************/
static std::string fileName;
static volatile sig_atomic_t keepRunning = true;
static PT1000 <MCP3008> pt1000(0);
static TC74TempSensor tc74(1);	// I2C1
static PressureSensor ps (0, 1, PressureSensor::OSR256);	// spi0, CE1.
static float reportFrecuencyHz = 1;
static CSVWriter csv (",");

/* Function declarations:
 ******************************************************************************/
void signal_handler(int signum);

static struct timespec secondsToTimespec(float seconds);

static bool parseArgs(int argc, char **argv);

static void startReport(void);

/* Inline and macros:
 *****************************************************************************/
static inline const std::string getCurrentDate() {
  time_t now = time(0);
  struct tm tstruct = *localtime(&now);
  char buf[81];
  strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);

  return buf;
}

static inline const std::string getCurrentTime() {
  time_t now = time(0);
  struct tm tstruct = *localtime(&now);
  char buf[81];
  strftime(buf, sizeof(buf), "%H-%M-%S", &tstruct);

  return buf;
}

/* Function definitions:
 ******************************************************************************/
int main(int argc, char **argv) {

  signal(SIGINT, signal_handler);

  keepRunning = parseArgs(argc, argv);
  if (keepRunning) {
    std::cout << "START" << std::endl;
    pt1000.activateVccCorrection(1); // channel 1 to read vcc.
    startReport();
    std::cout << "END" << std::endl;
  }

  return EXIT_SUCCESS;
}

static bool parseArgs(int argc, char **argv) {
  int c;

  while ( (c = getopt(argc, argv, "hf:n:")) != -1 ) {
    switch (c) {
      case 'f': 
	{
          reportFrecuencyHz = atof(optarg);
          if (reportFrecuencyHz < 0.0) {
	    reportFrecuencyHz = 1;
            std::cerr << "The report frequency of the counter can't be negative." << std::endl;
          }
          std::cout << "Report frecuency: "<< reportFrecuencyHz << "Hz" << std::endl;
	}

        break;

      case 'h':
	std::cout << "htl_monitor -f<report frequency> -n<n. of samples to compute PT1000 temperature>" << std::endl;
	std::cout << "  -f: Is the frequency (Hz) at which the data is sampled, displayed\n"
		  << "      on the screen, and saved in the csv file. Defualt value = 1Hz.\n"
		  << "  -n: Number of PT1000-ADC samples to be averaged and calculate\n"
		  << "      the temperature (i.e., FIR filter of n points). Defualt value = 5.\n"
		  << "  E.g: " << argv[0] << " -f1 -n10\n"
		  << "       The above command would record and show the measurements at 1hz frequency,\n"
		  << "       would take 10 samples from the PT1000 to calculate the temperature." 
		  << std::endl;
	return false;

      case 'n':
	{
	  int FIR_nsamples = atoi(optarg);
          if (FIR_nsamples < 0) {
	    FIR_nsamples = 5;
            std::cerr << "The number of samples for PT1000 temp computation can't be negative." << std::endl;
            std::cout << "Set to default value: 5" << std::endl;
          } else {
	    std::cout << "Setting number of samples to " << FIR_nsamples << std::endl;
	  }
  	  pt1000.setFIRNSamples(FIR_nsamples);
    	}

        break;

      default:
        std::cerr << "¿?" << std::endl;
        return false;
    }
  }

  if(argc == 1) {
    std::cout << "Set report frecuency to default value: "
              << std::to_string(reportFrecuencyHz) << "Hz" << std::endl;
  }

  return true;
}

void signal_handler(int signum) {
  if (signum == SIGINT) {
    keepRunning = false;
  }
}

static void startReport(void) {
  struct timespec period = secondsToTimespec(float(1.0/reportFrecuencyHz));
  struct timespec next;
  if(clock_gettime(CLOCK_MONOTONIC, &next) < 0) {
    perror("clock_gettime");
  }

  // >>>>
  fileName = "/home/pi/HTL_Monitor_Logs/"+
	     getCurrentDate()+"_"+getCurrentTime()+".csv";
  int nIters = 0;
  csv.newRow() << "Timepstamp" << "Pressure" << "Pressure sensor temp (Celsius)" 
	       << "PT1000 (Celsius)" << "TC74 (Celsius)";
  const int colWidth = 18;
  std::cout << std::setfill('*') << std::setw(4*colWidth) << "*" << std::endl;
  std::cout << std::setfill(' ') << std::fixed;
  std::cout << std::setw(colWidth) << "Pressure" 
	    << std::setw(colWidth) << "Press. temp" 
	    << std::setw(colWidth) << "PT1000"
	    << std::setw(colWidth) << "TC74" << std::endl;
  std::cout << std::setfill('*') << std::setw(4*colWidth) << "*" <<std::endl;
  std::cout << std::setfill(' ') << std::fixed;
  while(keepRunning) {
    if(clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &next, 0) < 0) {
      perror("clock_nanosleep");
    }
    
    int32_t ps_pressure, ps_temp;
    ps.getPressureAndTemp(ps_pressure, ps_temp);

    float ps_pressure_bar = float(ps_pressure/100000.0);
    float ps_temp_celsius = float(ps_temp)/100.0;
    float pt1000_temp_celsius = pt1000.getTempCelsius();
    float tc74_temp_celsius = tc74.getTemperature();
    // Show in the screen:
    std::cout << std::setw(colWidth) << std::to_string(ps_pressure_bar)+" bar"
              << std::setw(colWidth) << std::to_string(ps_temp_celsius)+" C"
              << std::setw(colWidth) << std::to_string(pt1000_temp_celsius)+" C"
              << std::setw(colWidth) << std::to_string(tc74_temp_celsius)+" C" << std::endl;   
   // Write in csv writer's buffer:
   csv.newRow() << getCurrentTime() << ps_pressure_bar << ps_temp_celsius 
	        << pt1000_temp_celsius << tc74_temp_celsius;
   nIters++;
   if(nIters % 10 == 0) {
     csv.writeToFile(fileName, true); // Flush buffer, or write to file.
   }
   // <<<<

   next = timespec_add(next, period);
  }
  std::cout << std::setfill('*') << std::setw(4*colWidth) << "*" << std::endl;
  csv.writeToFile(fileName, true);
}

static struct timespec secondsToTimespec(float seconds) {
  struct timespec ts;
  float intPart;
  ts.tv_nsec = int (modff(seconds, &intPart) * 1.0E09);
  ts.tv_sec = intPart;
  std::cout << ts.tv_sec << "'' " << ts.tv_nsec << " nsec" << std::endl;
  return ts;
}
