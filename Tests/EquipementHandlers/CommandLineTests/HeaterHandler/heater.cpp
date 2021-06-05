#include "EquipementHandlers/HeaterHandler.h"
#include <unistd.h>
#include <iostream> // getopt
#include <sys/time.h>
#include <signal.h> // signal
#include <stdlib.h> // strtof atoi

using namespace equipementHandlers;

/*
  hh.setPower(0.25);      // > 100%
  hh.setPower(0.23884/2); // 50%
  hh.setPower(0.23884/4); // 25 %

  hh.setPWMFreq(32000);
*/ 

static volatile sig_atomic_t keepRunning = true;
static float maxPSVoltage = 5.1;
static float maxPSCurrent = 2.5;

void signal_handler(int signum) {
  if (signum == SIGINT) {
    keepRunning = false;
  }
}

int main (int argc, char **argv)  
{
  float power = 0;
  unsigned int freq_hz = 8000;
  int duration_secs = -1;

  // Args parsing:
  if (argc < 2 || argc > 6) {
    std::cerr << "Usage: heater power <freq> <duration_secs> <maxPSVoltage> <maxPSCurrent>" << std::endl;
    return EXIT_FAILURE;
  }

  char *end;
  power = strtof(argv[1], &end); 
  if (end == argv[1]) {
    std::cerr << "Power must be a number" << std::endl;
  }
  if (argc >= 3) {
    freq_hz = unsigned (strtof(argv[2], &end));
    if (end == argv[2]) {
      std::cerr << "freq must be a number" << std::endl;
      return EXIT_FAILURE;
    }
  }
  if (argc >= 4) {
    duration_secs = int (strtof(argv[3], &end));
    if (end == argv[3]) {
      std::cerr << "duration_secs must be a number" << std::endl;
      return EXIT_FAILURE;
    }
  }
  if (argc >= 5) {
    maxPSVoltage = atof(argv[4]);
    if (maxPSVoltage < 0 ) {
      maxPSVoltage = 0;
      std::cerr << "error PS máx voltage negativo"  << std::endl;
    }
  }

  if(argc >= 6) {
    maxPSCurrent = atof(argv[5]);
    if (maxPSCurrent < 0) {
      maxPSCurrent = 0;
      std::cerr << "error PS max curren negativo" << std::endl;
    }
  }

  signal(SIGINT, signal_handler);

  std::cout << "freq: " << freq_hz << " power: "  << power << " duration_secs: " << duration_secs << std::endl;
  std::cout << "max PS voltage (V): " << maxPSVoltage << "\n"
            << "max PS current (A): " << maxPSCurrent << std::endl;
  HeaterHandler hh;

  hh.setMaxPSVoltage_volts(maxPSVoltage);
  hh.setMaxPSCurrent_amps(maxPSCurrent);
  hh.setPower(power);
  hh.setPWMFreq(freq_hz);


  // Set power in the requested time: 
  if (duration_secs > 0) {
    sleep(duration_secs);
  } else {
    while(keepRunning) {
      // Run until CTRL-C.
    }
  }

  hh.disengage();
  return EXIT_FAILURE;
}
