#include <unistd.h>
#include <iostream>
#include <sys/time.h>
#include <algorithm>
#include <functional>

#ifndef PERIODIC_TASK_H
#define PERIODIC_TASK_H

extern void periodicTask(struct timespec period, int nLoops, 
    std::function<void(void)> task)
{
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

  return;
}

#endif
