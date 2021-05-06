#ifndef PERIODIC_TASK_H
#define PERIODIC_TASK_H

#include <unistd.h>
#include <algorithm>
#include <functional>

extern struct timespec secondsToTimespec(float seconds);

extern void periodicTask_frec(float frecuency, int nLoops,
                              std::function<void(void)> task);
  
extern void periodicTask_period(float period, int nLoops,
                                std::function<void(void)> task); 

extern void periodicTask(struct timespec period, int nLoops, 
                         std::function<void(void)> task);

#endif
