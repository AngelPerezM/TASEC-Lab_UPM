#include "EquipementHandlers/Anemometer.h"
#include "PeriodicTask.h"
#include <unistd.h>
#include <iostream>
#include <sys/time.h>
#include <gtest/gtest.h>
#include <algorithm>
#include <functional>

using namespace equipementHandlers;

class AnemometerTest : public testing::Test {
  protected:
};

TEST_F (AnemometerTest, checkNOPulses) {

  // float normalTemperature = std::get<0>(GetParam());
  // int adcChannel = std::get<1>(GetParam());
  Anemometer a;

  a.startCounting();
  usleep(1500000);
  a.stopCounting();
  int counter = a.getCounter();
  ASSERT_EQ(counter, 0);
}
