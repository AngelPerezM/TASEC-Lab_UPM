#include "EquipementHandlers/TC74TempSensor.h"
#include "EquipementHandlers/GroveAdcHat.h"
#include "Utils/CSVWriter.h"

#include <unistd.h>
#include <iostream>
#include <sys/time.h>
#include "gtest/gtest.h"
#include <fstream>
#include <tuple>  // for multi params in TEST SUIT
#include <math.h>
#include <chrono> // To get curr time for log file name.


using namespace equipementHandlers;

class TC74Test : public testing::Test {
  protected:

    TC74Test() : tc74 (1, "/tmp/test_tc74.log")
    {
    }

    TC74TempSensor tc74;
};

TEST_F (TC74Test, MAXHzSampling) {
  int nSamples = 200;
  struct timespec begin, end;

  if(clock_gettime(CLOCK_MONOTONIC, &begin) < 0) {
    perror("clock_gettime");
  }
  for (int i = 0; i < nSamples; ++i) {
    (void) tc74.getTemperature();
  }
  if(clock_gettime(CLOCK_MONOTONIC, &end) < 0) {
    perror("clock_gettime");
  }

  float elapsed =( (end.tv_sec - begin.tv_sec)*1e3
                       + (end.tv_nsec-begin.tv_nsec)/1e6 ) / nSamples;
  std::cout << "Statistics: " << elapsed << " mseconds/sample." << std::endl;
}
