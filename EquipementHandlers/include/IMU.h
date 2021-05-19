#ifndef IMU_H
#define IMU_H

/*******************************************************************************
 * 11/mar/2021 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include <stdint.h>
#include <vector>

#include "Magnetometer.h"
#include "AccGyro.h"

namespace equipementHandlers {
  class IMU {
    public:
      Magnetometer magnetometer;
      AccGyro accAndGyro;

      // CONSTRUCTOR
      IMU(uint8_t bus_num = 1);

      // DESTRUCTOR
      ~IMU();

      // MANIPULATORS

      // ACCESORS

      // Manipulators:

  };

}
#endif // IMU_H
