#include "PeriodicTask.h"
#include <math.h>
#include <iostream>
#include <sys/time.h>

void periodicTask(struct timespec period, int nLoops, 
                  std::function<void(void)> task)
{
  std::cout << "Period: "<< period.tv_sec << " secs, "
            << period.tv_nsec << "nsecs" << std::endl;

  struct timespec next;
  if(clock_gettime(CLOCK_MONOTONIC, &next) < 0) {
    perror("clock_gettime");
  }
  
  for(int i = 0; i < nLoops; ++i) {
    if(clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &next, 0) < 0) {
      perror("clock_nanosleep");
    }
    task();
    next.tv_sec += period.tv_sec;
    next.tv_nsec += period.tv_nsec;
  }
}

struct timespec secondsToTimespec(float seconds) {
  struct timespec ts;
  float intPart;
  ts.tv_nsec = int (modff(seconds, &intPart) * 1.0E09);
  ts.tv_sec = intPart;
  return ts;
}

void periodicTask_frec(float frecuency, int nLoops,
                       std::function<void(void)> task) {

  float period = 1.0/frecuency;
  periodicTask(secondsToTimespec(period), nLoops, task);
}

void periodicTask_period(float period, int nLoops,
                         std::function<void(void)> task) {
  periodicTask(secondsToTimespec(period), nLoops, task);
}
