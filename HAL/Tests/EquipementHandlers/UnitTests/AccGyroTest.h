// #include "AccGyro.t.h"
#include <unistd.h> // usleep
#include <iostream>
#include <errno.h>  // errno
#include <gtest/gtest.h>
#include "EquipementHandlers/AccGyro.h"

using namespace equipementHandlers;

class AccGyroTest:public testing::Test {
};

TEST_F (AccGyroTest, ReadAccGyro) {
  AccGyro ag (1);

  float accData[3];
  float gyroData[3];

  for (int i = 0; i < 10; ++i) {
    ag.readAccelMiliG(accData[0], accData[1], accData[2]);
    ag.readGyroMiliDPS(gyroData[0], gyroData[1], gyroData[2]);

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

    usleep(700000);
  }

}
