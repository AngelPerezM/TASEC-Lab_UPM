#include <gtest/gtest.h>

#include "VSourceTest.h"
#include "PT1000Test.h"
#include "GroveTempSensorTest.h"
#include "GPSTest.h"

INSTANTIATE_TEST_CASE_P(VSourceTestParams, VSourceTest,
                        testing::Values(std::make_tuple(200, 800000), // MAX: 1MHZ
                                        std::make_tuple(200, 100),
                                        std::make_tuple(200, 50), 
                                        std::make_tuple(200, 10)));
INSTANTIATE_TEST_CASE_P(PT1000TestParams, PT1000Test,
                        testing::Values(std::make_tuple(200, 800000)));
int main (int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}