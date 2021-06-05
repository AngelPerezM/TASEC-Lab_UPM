/*******************************************************************************
 * ./TC74TempSensor.h
 *
 * 09/mar/2021 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include "IMU.h"

#include <iostream>

namespace bhs = busHandlers;

/* Function definitions
 *******************************************************************************/

namespace equipementHandlers {

  IMU::IMU(uint8_t bus_num) 
    : magnetometer(bus_num), accAndGyro(bus_num)
  {
    ;
  }

  IMU::~IMU() {
    ;
  }

}
