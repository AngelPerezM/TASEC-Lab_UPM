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
  public:

    void readPS(int nIters, int bus, int cs) {
      double elapsed = 0.0;

      PressureSensor ps (bus, cs);
      struct timespec period = {.tv_sec = 0, .tv_nsec = 500000000};  //500 ms;
      periodicTask
        (period, nIters,
         [&ps, &elapsed](void) {
         int32_t p;
         int32_t t;
         uint32_t d1, d2;
         struct timespec start, stop;
         clock_gettime(CLOCK_MONOTONIC, &start);

         int rc = ps.getPressureAndTemp(p, t, d1, d2);

         clock_gettime(CLOCK_MONOTONIC, &stop);
         elapsed = elapsed + ((stop.tv_sec - start.tv_sec)*1e3 + (stop.tv_nsec - start.tv_nsec)/1e6);

         std::cout << "Return code: " << rc << std::endl;
         std::cout << "Pressure: "<< p << std::endl;
         std::cout << "Temperature: "<< t << std::endl;
         std::cout << "d1: " << d1 << " d2: " << d2 << std::endl;
         ASSERT_NEAR(p, 93000, 3000);  // units: milibar*100
         }
        );

      std::cout << "Elapsed time: " << std::to_string(elapsed/nIters) << " ms" << std::endl; 
    }
};

TEST_F (PressureSensorTest, ValidatePS1Values) {
  readPS(100, 1, 1);
}

TEST_F (PressureSensorTest, ValidatePS2Values) {
  readPS(100, 1, 2);
}


