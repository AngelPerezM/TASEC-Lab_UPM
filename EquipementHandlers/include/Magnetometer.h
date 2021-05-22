#ifndef Magnetometer_H
#define Magnetometer_H

/*******************************************************************************
 * 11/mar/2021 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include <stdint.h>
#include <vector>

#include "BusHandlers/BusHandlerFactory.h"
#include "Utils/FileLoggerFactory.h"

using namespace utils;

namespace equipementHandlers {
  class Magnetometer {
    private:
      busHandlers::I2CHandler *bus = nullptr;
      float m_sensitivity;
      FileLogger *fileLogger;
      
      // Magnetometer I2C address.
      const int I2C_ADDRESS = 0x1C;

      // Magnetometer register address map:
      enum Register : uint8_t {
        // 16 bit, 2's complement. I think it is used for callibration 
        // (Ask David and Juan):
        OFFSET_X_REG_L_M = 0x05,
        OFFSET_X_REG_H_M = 0x06,
        OFFSET_Y_REG_L_M = 0x07,
        OFFSET_Y_REG_H_M = 0x08,
        OFFSET_Z_REG_L_M = 0x09,
        OFFSET_Z_REG_H_M = 0x0A,

        // read only, magnetic ID.
        WHO_AM_I_M = 0x0F,

        CTRL_REG1_M = 0x20,
        CTRL_REG2_M = 0x21,
        CTRL_REG3_M = 0x22,
        CTRL_REG4_M = 0x23,
        CTRL_REG5_M = 0x24,

        STATUS_REG_M = 0x27,

        OUT_X_L_M = 0x28,
        OUT_X_H_M = 0x29,
        OUT_Y_L_M = 0x2A,
        OUT_Y_H_M = 0x2B,
        OUT_Z_L_M = 0x2C,
        OUT_Z_H_M = 0x2D,

        INT_CFG_M = 0x30,
        INT_SRC_M = 0x31,
        INT_THS_L_M = 0x32,
        INT_THS_H_M = 0x33
      };

      uint8_t readRegister(uint8_t regAddress);
      void writeRegister(uint8_t regAddress, uint8_t value);
      void initialize (void);

    public:
      struct MagData {
        float xAxis;
        float yAxis;
        float zAxis;
      };

      // CONSTRUCTOR
      Magnetometer(uint8_t bus_num = 1, const char *fileLogName = "/home/pi/blackbox.log");

      // DESTRUCTOR
      ~Magnetometer();

      // MANIPULATORS
      void enableTemperatureCompensation (void);

      // ACCESORS

      /**
       * Reads WHO_AM_I_M register and checks if has the expected content.
       */
      bool testWhoAmI(void);

      bool isDataAvailable(uint8_t axis = 3);

      void readRawData(int16_t &x, int16_t &y, int16_t &z);

      float getSensitivity(void);

      /**
       * Output params unit: mgauss.
       */
      void readMiliGauss(float &x, float &y, float &z);

  };

}

#endif // Magnetometer_H
