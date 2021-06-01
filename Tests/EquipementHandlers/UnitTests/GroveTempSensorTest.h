#include "EquipementHandlers/AnalogTempSensor.h"
#include "PeriodicTask.h"
#include <unistd.h>
#include <iostream>
#include <sys/time.h>
#include <gtest/gtest.h>
#include <algorithm>
#include <functional>

using namespace equipementHandlers;

class GroveTempSensorTest : public testing::Test {
  protected:
};

TEST_F (GroveTempSensorTest, TemperatureVariation) {

  // float normalTemperature = std::get<0>(GetParam());
  // int adcChannel = std::get<1>(GetParam());
  AnalogTempSensor ats (6);
  struct timespec period = {.tv_sec = 0, .tv_nsec = 500000000};  //500 ms;
  periodicTask
    (period, 25, 
     [&ats](void) {
      float t = ats.getTempCelsius();
      std::cout << "T: "<< t << " ºC" << std::endl;
      ASSERT_NEAR(t, 21, 1.5);
     }
    );
}
