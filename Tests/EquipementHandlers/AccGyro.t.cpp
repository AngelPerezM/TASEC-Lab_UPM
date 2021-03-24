#include "AccGyro.t.h"
#include <unistd.h> // usleep
#include <iostream>
#include <errno.h>  // errno

#include "EquipementHandlers/AccGyro.h"

using namespace equipementHandlers;

void test_accGyro (void) {
  AccGyro ag (1);
  AccGyro::Data accData;
  AccGyro::Data gyroData;

  try {
    for (int i = 0; i < 10; ++i) {
      accData = ag.readAccel();
      gyroData = ag.readGyro();

      if ( accData.z <= 5 && accData.z >= 0.1) {
        std::cout << "EUREKA: 1G-------------------------------------------------->" << std::endl;
      }
      std::cout << "[AccGyro] Temp: " << ag.readTempCelsius() << std::endl;
      std::cout << "[Acc] X: " << accData.x << ". " << "Y: " << accData.y << ". " << "Z: " << accData.z << std::endl;
      std::cout << "[Gyro] X: " << gyroData.x << ". " << "Y: " << gyroData.y << ". " << "Z: " << gyroData.z << std::endl << std::endl;

      usleep(500000);
    }
  } catch (std::runtime_error &re){
    std::cout << "Could not read data :(" << std::endl;
  }

}
