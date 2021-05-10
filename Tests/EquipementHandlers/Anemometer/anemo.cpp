#include "EquipementHandlers/Anemometer.h"
#include <math.h>   // modf
#include <unistd.h> // Getopt
#include <stdlib.h> // strtof
#include <signal.h> // signal
#include <iostream>
#include <sys/time.h>
#include <string>
using namespace equipementHandlers;

/* Global variabels:
 ******************************************************************************/
static volatile sig_atomic_t keepRunning = true;
static float reportFrecuencyHz;
static Anemometer a;

/* Function declarations:
 ******************************************************************************/
void signal_handler(int signum);

static struct timespec secondsToTimespec(float seconds);

static bool parseArgs(int argc, char **argv);

static void startReport(void);

/* Function definitions:
 ******************************************************************************/
int main(int argc, char **argv) {

  signal(SIGINT, signal_handler);

  keepRunning = parseArgs(argc, argv);
  
  std::cout << "START" << std::endl;
  startReport();
  std::cout << "END" << std::endl;
  return EXIT_SUCCESS;
}

static bool parseArgs(int argc, char **argv) {
  reportFrecuencyHz = 1;
  int c;
  while ( (c = getopt(argc, argv, "r:")) != -1 ) {
    switch (c) {
      case 'r':
        char *end;
        reportFrecuencyHz = strtof32(optarg, &end);
        if (reportFrecuencyHz < 0) {
          std::cerr << "The report frequency of the counter can't be negative." << std::endl;
          std::cout << "Set report frecuency to default value: "
                    << std::to_string(reportFrecuencyHz) << "Hz" << std::endl;
        } else if (end != NULL) {
          std::cerr << "The report frequency of the counter must be a number." << std::endl;
          std::cout << "Set report frecuency to default value: "
                    << std::to_string(reportFrecuencyHz) << "Hz" << std::endl;       
        }
        break;

      case '?':
        if(optopt == 'r') {
          std::cout << "Set report frecuency to default value: "
                    << std::to_string(reportFrecuencyHz) << "Hz" << std::endl;
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
  struct timespec period = secondsToTimespec(1.0/reportFrecuencyHz);
  struct timespec next;
  if(clock_gettime(CLOCK_MONOTONIC, &next) < 0) {
    perror("clock_gettime");
  }

  a.setCounter(0);
  a.startCounting();

  while(keepRunning) {
    if(clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &next, 0) < 0) {
      perror("clock_nanosleep");
    }
    std::cout << "Counter: "  << a.getCounter() << std::endl;
    next.tv_sec += period.tv_sec;
    next.tv_nsec += period.tv_nsec;
  } 
}

static struct timespec secondsToTimespec(float seconds) {
  struct timespec ts;
  float intPart;
  ts.tv_nsec = int (modff(seconds, &intPart) * 1.0E09);
  ts.tv_sec = intPart;
  return ts;
}
