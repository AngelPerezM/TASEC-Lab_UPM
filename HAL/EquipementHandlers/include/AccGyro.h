#ifndef AccGyro_H
#define AccGyro_H

/*******************************************************************************
 * 11/mar/2021 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include <stdint.h>
#include <vector>

#include "Utils/FileLoggerFactory.h"
#include "BusHandlers/BusHandlerFactory.h"
using namespace utils;
using namespace busHandlers;

namespace equipementHandlers {
  class AccGyro {
    private:
      busHandlers::I2CHandler *bus = nullptr;
      bool bus_error = true;      
      FileLogger *fileLogger;

      // Accelerometer/gyroscope I2C address.
      const int I2C_ADDRESS = 0x6A;  

      float m_accelSensitivity;
      float m_gyroSensitivity;

      int16_t m_aBiasRaw[3] = {0, 0, 0};
      int16_t m_gBiasRaw[3] = {0, 0, 0};

      // Accelerometer/gyroscope register address map.
      enum Register : uint8_t {
        ACT_THS = 0x04,
        ACT_DUR = 0x05,
        INT_GEN_CFG_XL = 0x06,
        INT_GEN_THS_X_XL = 0x07,
        INT_GEN_THS_Y_XL = 0x08,
        INT_GEN_THS_Z_XL = 0x09,
        INT_GEN_DUR_XL = 0x0A,
        REFERENCE_G = 0x0B,
        INT1_CTRL = 0x0C,
        INT2_CTRL = 0x0D,
        WHO_AM_I = 0x0F,
        CTRL_REG1_G = 0x10,
        CTRL_REG2_G = 0x11,
        CTRL_REG3_G = 0x12,
        ORIENT_CFG_G = 0x13,
        INT_GEN_SRC_G = 0x14,
        OUT_TEMP_L = 0x15,
        OUT_TEMP_H = 0x16,
        STATUS_REG = 0x17,
        OUT_X_L_G = 0x18,
        OUT_X_H_G = 0x19,
        OUT_Y_L_G = 0x1A,
        OUT_Y_H_G = 0x1B,
        OUT_Z_L_G = 0x1C,
        OUT_Z_H_G = 0x1D,
        CTRL_REG4 = 0x1E,
        CTRL_REG5_XL = 0x1F,
        CTRL_REG6_XL = 0x20,
        CTRL_REG7_XL = 0x21,
        CTRL_REG8 = 0x22,
        CTRL_REG9 = 0x23,
        CTRL_REG10 = 0x24,
        INT_GEN_SRC_XL = 0x26,
        STATUS_REG_CP = 0x27, // Same contents as STATUS_REG
        OUT_X_L_XL = 0x28,
        OUT_X_H_XL = 0x29,
        OUT_Y_L_XL = 0x2A,
        OUT_Y_H_XL = 0x2B,
        OUT_Z_L_XL = 0x2C,
        OUT_Z_H_XL = 0x2D,
        FIFO_CTRL = 0x2E,
        FIFO_SRC = 0x2F,
        INT_GEN_CFG_G = 0x30,
        INT_GEN_THS_XH_G = 0x31,
        INT_GEN_THS_XL_G = 0x32,
        INT_GEN_THS_YH_G = 0x33,
        INT_GEN_THS_YL_G = 0x34,
        INT_GEN_THS_ZH_G = 0x35,
        INT_GEN_THS_ZL_G = 0x36,
        INT_GEN_DUR_G = 0x37          
      };

      uint8_t readRegister(uint8_t regAddress);

      void writeRegister(uint8_t regAddress, uint8_t value);

      void initialize(void);
      
      void autocalibrate(void);
    public:

      // CONSTRUCTOR
      AccGyro(uint8_t bus_num = 1, const char *fileLogName = "/home/pi/blackbox.log");

      // DESTRUCTOR
      ~AccGyro();

      // MANIPULATORS
      void enableFIFO(void);

      void disableFIFO(void);

      void setFIFO(uint8_t mode, uint8_t fifoThs);

      // ACCESORS
      bool testWhoAmI(void);

      void readRawAccel(int16_t &x, int16_t &y, int16_t &z);

      float getAccelSensitivity(void);
      
      int getNSamplesFIFO(void);

      void readAccelMiliG(float &x, float &y, float &z);

      bool isAccelAvailable(void);

      void readRawGyro(int16_t &x, int16_t &y, int16_t &z);
      
      float getGyroSensitivity(void);

      void readGyroMiliDPS(float &x, float &y, float &z);

      bool isGyroAvailable(void);

      int16_t readRawTemp(void);

      float readTempCelsius(void);

      bool isTempAvailable(void);

  };

}
#endif // AccGyro_H
