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
  PressureSensor ps (1, 2);
  struct timespec period = {.tv_sec = 0, .tv_nsec = 500000000};  //500 ms;
  periodicTask
    (period, 25,
     [&ps](void) {
      int32_t p;
      int32_t t;
      uint32_t d1, d2;
      int rc = ps.getPressureAndTemp(p, t, d1, d2);

      std::cout << "Return code: " << rc << std::endl;
      std::cout << "Pressure: "<< p << std::endl;
      std::cout << "Temperature: "<< t << std::endl;
      std::cout << "d1: " << d1 << " d2: " << d2 << std::endl;
      ASSERT_NEAR(p, 93000, 3000);  // units: milibar*100
     }
    );
}

TEST_F (PressureSensorTest, ValidatePS2Values) {

  // float normalTemperature = std::get<0>(GetParam());
  // int adcChannel = std::get<1>(GetParam());
  PressureSensor ps(1, 2);  // SPI1, CS1
  struct timespec period = {.tv_sec = 0, .tv_nsec = 500000000};  //500 ms;
  periodicTask
    (period, 25,
     [&ps](void) {
      int32_t p;
      int32_t t;
      uint32_t d1, d2;
      int rc = ps.getPressureAndTemp(p, t, d1, d2);
      std::cout << "Return code: " << rc << std::endl;
      std::cout << "Pressure: "<< p << std::endl;
      std::cout << "Temperature: "<< t << std::endl;
      std::cout << "d1: " << d1 << " d2: " << d2 << std::endl;
      ASSERT_NEAR(p, 93000, 3000);  // units: milibar*100
     }
    );
}