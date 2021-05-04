#include "EquipementHandlers/PressureSensor.h"
#include "PeriodicTask.h"
#include <unistd.h>
#include <iostream>
#include <sys/time.h>
#include <gtest/gtest.h>
#include <algorithm>
#include <functional>

using namespace equipementHandlers;

class PressureSensorTest : public testing::Test {
  protected:
};

TEST_F (PressureSensorTest, ValidatePS1Values) {

  // float normalTemperature = std::get<0>(GetParam());
  // int adcChannel = std::get<1>(GetParam());
  PressureSensor ps;
  struct timespec period = {.tv_sec = 0, .tv_nsec = 500000000};  //500 ms;
  periodicTask
    (period, 25,
     [&ps](void) {
      int32_t p;
      int32_t t;
      ps.getPressureAndTemp(p, t);
      std::cout << "Pressure: "<< p << std::endl;
      std::cout << "Temperature: "<< t << std::endl;
      ASSERT_NEAR(p, 93000, 3000);  // units: milibar*100
     }
    );
}

TEST_F (PressureSensorTest, ValidatePS2Values) {

  // float normalTemperature = std::get<0>(GetParam());
  // int adcChannel = std::get<1>(GetParam());
  PressureSensor ps(1, 1);  // SPI1, CS1
  struct timespec period = {.tv_sec = 0, .tv_nsec = 500000000};  //500 ms;
  periodicTask
    (period, 25,
     [&ps](void) {
      int32_t p;
      int32_t t;
      ps.getPressureAndTemp(p, t);
      std::cout << "Pressure: "<< p << std::endl;
      std::cout << "Temperature: "<< t << std::endl;
      ASSERT_NEAR(p, 93000, 3000);  // units: milibar*100
     }
    );
}
