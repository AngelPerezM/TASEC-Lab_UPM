#include "EquipmentHandlers/AnalogTempSensor.h"
#include <unistd.h>
#include <iostream>
#include <sys/time.h>

using namespace equipmentHandlers;

int main () {
  GroveAdcHat &adc = GroveAdcHat::getInstance();
  uint16_t all_raw_data [ADC_CHAN_NUM];

  adc.get_all_raw_data(all_raw_data);
  
  std::cout << "[" << all_raw_data[0];
  for(int i = 1; i < ADC_CHAN_NUM; ++i) {
    std::cout << ", " << all_raw_data[i];
  }
  std::cout << "]\n";

  AnalogTempSensor temp (0);
  for(int i = 0; i < 10; ++i) {
    std::cout << "Analog. temp. sensor: " << temp.getTempCelsius() << " ºC\n";
  }

  struct timespec next, period;
  if(clock_gettime(CLOCK_MONOTONIC, &next) != 0) {
    perror("clock_gettime");
  }
  period.tv_sec = 1;
  period.tv_nsec = 0.0;
  
  std::cout << "Analog. temp. sensor:\n";
  for(;;) {
    if(clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &next, 0) != 0) {
      perror("clock_nanosleep");
    }
    std::cout << temp.getTempCelsius() << " ºC\r" << std::flush;
    next.tv_sec += period.tv_sec;
    next.tv_nsec += period.tv_nsec;
  }

  return 0;
}
