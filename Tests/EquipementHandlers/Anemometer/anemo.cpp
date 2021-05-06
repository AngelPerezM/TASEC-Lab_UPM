#include "EquipementHandlers/Anemometer.h"
#include <unistd.h> // Getopt
#include <stdlib.h> // strtof
#include <iostream>
#include <sys/time.h>
#include <algorithm>
#include <functional>
#include <string>
using namespace equipementHandlers;

struct timespec secondsToTimespec(float seconds) {
  struct timespec ts;
  float intPart;
  ts.tv_nsec = int (modff(seconds, &intPart) * 1.0E09);
  ts.tv_sec = intPart;
  return ts;
}

int main(int argc, char **argv) {

  Anemometer a;
  float reportFrecuencyHz = 1;

  int c;
  switch ( (c = getopt(argc, argv, "c:")) != -1 ) {
    case 'c':
      reportFrecuencyHz = strtof32(optarg);
      if (reportFrecuencyHz < 0) {
          std::cerr << "The report frequency of the counter can't be negative." << std::endl;
          std::cout << "Set report frecuency to default value: "
                    << std::to_string(reportFrecuencyHz) << "Hz" << std::endl;
      }
    case '?':
      if(optopt == 'c') {
        std::cout << "Set report frecuency to default value: "
                  << std::to_string(reportFrecuencyHz) << "Hz" << std::endl;
      }
    default:
      abort();
  }

  struct timespec period = secondsToTimespec(1.0/reportFrecuencyHz);
  struct timespec next;
  if(clock_gettime(CLOCK_MONOTONIC, &next) < 0) {
    perror("clock_gettime");
  }

  a.setCounter(0);
  a.startCounting();
  while(1) {
    if(clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &next, 0) < 0) {
      perror("clock_nanosleep");
    }
    std::cout << "Counter: "  << a.getCounter();
    next.tv_sec += period.tv_sec;
    next.tv_nsec += period.tv_nsec;
  }

  return 0;
}
