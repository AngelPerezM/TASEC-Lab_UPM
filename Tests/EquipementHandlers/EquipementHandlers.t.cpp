#include "EquipementHandlers/AnalogTempSensor.h"
#include "EquipementHandlers/OneWireTempSensor.h"
#include "EquipementHandlers/TC74TempSensor.h"
#include "EquipementHandlers/PressureSensor.h"
#include "GPS.t.h"
#include "Magnetometer.t.h"
#include "AccGyro.t.h"

#include <unistd.h>
#include <iostream>
#include <sys/time.h>

using namespace equipementHandlers;

void printBanner(const char *msg) {
  puts("················································································");
  std::cout << msg << std::endl;
  puts("················································································");
}

void test_tc74TempSensor () {
  TC74TempSensor tc74 (1);
  tc74.setNormalMode();
  for (int i = 0; i < 20; ++i) {
    std::cout << "TC74 Temp: " << static_cast<int16_t>(tc74.getTemperature()) << std::endl;
  }
}

void test_i2cTempSensor () {

  GroveAdcHat &adc = GroveAdcHat::getInstance();
  uint16_t all_raw_data [ADC_CHAN_NUM];

  adc.get_all_raw_data(all_raw_data);
  
  std::cout << "[" << all_raw_data[0];
  for(int i = 1; i < ADC_CHAN_NUM; ++i) {
    std::cout << ", " << all_raw_data[i];
  }
  std::cout << "]\n";

  AnalogTempSensor temp (0);
  for(int i = 0; i < 20; ++i) {
    std::cout << "Analog. temp. sensor: " << temp.getTempCelsius() << " ºC\n";
  }

  /*
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
  */

}

void test_1wTempSensor () {

  OneWireTempSensor ts;
  struct timeval t1, t2;
  double secs = 0;

  std::vector<float> temps;
  for (int i = 0; i < 2; ++i) {
    gettimeofday(&t1, NULL);
    temps = ts.getAllTempsCelsius();
    gettimeofday(&t2, NULL);
    secs = (((t2.tv_usec - t1.tv_usec)/1000000.0f)  + (t2.tv_sec - t1.tv_sec));
    for(float temp : temps) {
      std::cout << "Temp = " << temp << "ºC" << std::endl;
    }
    std::cout << " Calculated in " << secs << " seconds." << std::endl;
  }
}

void test_pressure() {
  PressureSensor ps(0, 0);
  int32_t p, t;

  for (int i = 0; i < 10; ++i) {
    ps.getPressureAndTemp(p, t);
    std::cout << "Pressure: " << p/1000.0 << " bar" << std::endl;
    std::cout << "Temperature: " << t/100 << "ºC" <<std::endl;
  }
}

int main () 
{
  printBanner("[TEST] I2CTempSensor:");
  test_i2cTempSensor();
  printBanner("[TEST] TC74:");
  test_tc74TempSensor();
//  printBanner("[TEST] GPS:");
//  test_gps();
  printBanner("[TEST] OneWireTempSensor:");
  test_1wTempSensor();

  printBanner("[TEST] Pressure:");
  test_pressure();

//  printBanner("[TEST] Magnetometer:");
//  test_mgt();

//  printBanner("[TEST] Accel and Gyro");
//  test_accGyro();

  return 0;
}
