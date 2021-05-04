#include "EquipementHandlers/MCP3008.h"
#include "PeriodicTask.h"
#include <unistd.h>
#include <iostream>
#include <sys/time.h>
#include <gtest/gtest.h>
#include <algorithm>
#include <functional>

using namespace equipementHandlers;

class MCP3008Test : public testing::Test {
  protected:
};

TEST_F (MCP3008Test, PressureValidation) {

  // float normalTemperature = std::get<0>(GetParam());
  // int adcChannel = std::get<1>(GetParam());
  MCP3008 adc;

  struct timespec period = {.tv_sec = 1, .tv_nsec = 100000000};  //500 ms;
  periodicTask
    (period, 100,
     [&adc](void) {
     /*for (int i = 0; i < 100; ++i) {*/
       uint16_t data;
       std::cout << "[";
       for (uint8_t i = 0; i < 7; ++i) {
         data = adc.get_nchan_raw_data(i);
       	 std::cout << data << ", ";
       	 // ASSERT_NEAR(p, 93000, 3000);  // units: milibar*100
       }
       std::cout << "]" << std::endl;
       /*sleep(1);
     }*/
     }
    );
}
