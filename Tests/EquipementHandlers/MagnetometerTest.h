#include "Magnetometer.t.h"
#include <unistd.h> // usleep
#include <iostream>
#include <errno.h>  // errno

#include "EquipementHandlers/Magnetometer.h"
using namespace equipementHandlers;

void test_mgt (void) {
  Magnetometer mgt (1);
  for (int i = 0; i < 10; ++i) {
    float x, y, z;
    mgt.readMiliGauss(x, y, z);
    std::cout << "X: " << x/1000.0 << "Gauss, " << "Y: " << y/1000.0 << "Gauss. " 
      << "Z: " << z/1000.0 << "Gauss." << std::endl;
    usleep(100000);
  }
}
