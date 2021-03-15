#include "Magnetometer.t.h"
#include <unistd.h> // usleep
#include <iostream>
#include <errno.h>  // errno

#include "EquipementHandlers/Magnetometer.h"
using namespace equipementHandlers;

void test_mgt (void) {
  Magnetometer mgt (1);
  Magnetometer::MagData md;
  try {
    for (int i = 0; i < 100000; ++i) {
      md = mgt.readAllAxis();
      std::cout << "X: " << md.xAxis << ". " << "Y: " << md.yAxis << ". " << "Z: " << md.zAxis << std::endl;
      usleep(100000);
    }
  } catch (std::runtime_error &re){
    std::cout << "Could not read magnetometer data :(" << std::endl;
  }
}
