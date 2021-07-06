// #include "AccGyro.t.h"
#include <unistd.h> // usleep
#include <iostream>
#include <errno.h>  // errno
#include <gtest/gtest.h>
#include "EquipementHandlers/AccGyro.h"
#include <time.h>

using namespace equipementHandlers;

class AccGyroTest:public testing::Test {
};

TEST_F (AccGyroTest, ReadAccGyro) {
  AccGyro ag (1);

  float accData[3];
  float gyroData[3];
  double elapsed = 0.0;
  int nIters = 25;

  for (int i = 0; i < nIters; ++i) {
    struct timespec start, stop;
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    ag.readAccelMiliG(accData[0], accData[1], accData[2]);
    ag.readGyroMiliDPS(gyroData[0], gyroData[1], gyroData[2]);

    clock_gettime(CLOCK_MONOTONIC, &stop);
    elapsed = elapsed + ((stop.tv_sec - start.tv_sec)*1e3 + (stop.tv_nsec - start.tv_nsec)/1e6);

    if ( accData[2] <= 1200 && accData[2] >= 800) {
      std::cout << "EUREKA: 1G (:^D)" << std::endl;
    }
    std::cout << "[AccGyro] Temp: " << ag.readTempCelsius() << std::endl;
    std::cout << "[Acc] X: " << accData[0]/1000.0 << ". " << 
                 "Y: " << accData[1]/1000.0 << ". " << 
                 "Z: " << accData[2]/1000.0 << std::endl;
    std::cout << "[Gyro] X: " << gyroData[0]/1000.0 << ". " << 
                 "Y: " << gyroData[1]/1000.0 << ". " <<
                 "Z: " << gyroData[2]/1000.0 << std::endl << std::endl;

    usleep(300000); // min: 8ms
  }

  std::cout << "Elapsed timem mean: " << std::to_string(elapsed/nIters) << " msecs" << std::endl;

}

