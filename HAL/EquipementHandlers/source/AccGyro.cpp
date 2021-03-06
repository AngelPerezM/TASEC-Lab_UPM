/*******************************************************************************
 * 15/mar/2021 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include "AccGyro.h"
#include "Utils/Debug.h"

#include <string>
#include <iostream>
#include <stdexcept>
#include <cmath>  // NAN
#include <unistd.h>

namespace bhs = busHandlers;

namespace equipementHandlers {

  AccGyro::AccGyro(uint8_t bus_num, const char *fileLogName)
  {

    fileLogger = FileLoggerFactory::getInstance().createFileLogger(fileLogName);

    try {
      bus = bhs::BusHandlerFactory::getInstance().createI2CHandler(bus_num);
      fileLogger->LOG(Info, "I2C handler created (bus: "+ std::to_string(bus_num) + ").");

      bus_error = false;
      if (bus -> isOpenned()) {
        PRINT_DEBUG("I2C Bus openned\n");
      }

      if (!testWhoAmI()) {
        fileLogger->LOG(Error, "WHO_AM_I register does NOT have the expected value.");
      } else {
      fileLogger->LOG(Info, "WHO_AM_I register HAS the expected value.");
      }

      initialize();
    } catch (I2CException &e) {
      fileLogger->LOG(Emergency, e.what());
      bus_error = true;
    }
    // autocalibrate();
  }

  AccGyro::~AccGyro () {
    writeRegister(CTRL_REG1_G, 0x00);
    writeRegister(CTRL_REG6_XL, 0x00);
  }

  void AccGyro::initialize (void) {
    if (bus_error) {
        return;
    }

    for ( int i = 0; i < 3; ++i) {
      m_gBiasRaw[i] = 0;
      m_aBiasRaw[i] = 0;
    }
    // Config from Mikrobus API:    
    // Operating mode: Accelerometer + Gyro.
    try {
      
      // Low power mode
      writeRegister(CTRL_REG3_G, 0x80); // 1000 0000

      // Gyroscope:
      // Enable 3-axes of gyro:
      writeRegister(CTRL_REG4, 0x38);
      // ODR = 59.5 Hz, low power mode, FS = +-2000 dps
      writeRegister(CTRL_REG1_G, 0x58); // 0101 1000
      
      // Accelerometer
      // Enable 3-axes of accel:
      writeRegister(CTRL_REG5_XL, 0x38);
      // ODR = 50 Hz, low power mode, FS = +-16g, BW = ODR.
      writeRegister(CTRL_REG6_XL, 0x48); // 0100 1000

      // Output regs not updated until msb and lsb read.
      // Little endian, and register addres automatically incremented during
      // multiple byte access with a serial interface.
      writeRegister(CTRL_REG8, 0x44); // 0100 0100

      m_gyroSensitivity = 70.0; // +-2000 dps <-> 70 mdps/LSB
      m_accelSensitivity = 0.732; // +-16g <-> 0.732 mg/LSB

    } catch (I2CException &e) {
      fileLogger->LOG(Emergency, e.what());
    }
  }

  /**
   * Based on:
   * https://github.com/sparkfun/LSM9DS1_Breakout/blob/master/Libraries/Arduino/src/SparkFunLSM9DS1.cpp
   */
  void AccGyro::autocalibrate() {
    if (bus_error) {
        return;
    }
    uint8_t samples = 0;

    // Turn on FIFO and set threshold to 32 samples.
    enableFIFO();
    usleep(20000);
    setFIFO(1, 0x1F);

    usleep(1500000);  // Wait for data collection.
    samples = readRegister(FIFO_SRC) & 0x3F;

    // Discard first data:
    int16_t trash = 0;
    readRawGyro(trash, trash, trash);
    readRawAccel(trash, trash, trash);

    int16_t temp_aBiasRaw [3] = {0, 0 ,0};
    int16_t temp_gBiasRaw [3] = {0, 0, 0};
    int16_t oneG = 1000.0/(m_accelSensitivity);
    for (int i = 0; i < samples; ++i) {
      usleep(8403); // 1/ODR*1000000
      int16_t ax, ay, az, gx, gy, gz;
      
      readRawGyro(gx, gy, gz);
      temp_gBiasRaw[0] += gx;
      temp_gBiasRaw[1] += gy;
      temp_gBiasRaw[2] += gz;
      
      readRawAccel(ax, ay, az);
      temp_aBiasRaw[0] += ax;
      temp_aBiasRaw[1] += ay;
      temp_aBiasRaw[2] += (az - (oneG));  // 1G  = gravity and facing up.

      PRINT_DEBUG("Gyro read = %d %d %d\n", gx, gy, gz);
      PRINT_DEBUG("Bias Accel = %d %d %d\n\n", ax, ay, az);
    }

    PRINT_DEBUG("Samples: %d\n", (int) samples);
    for (int i = 0; i < 3 && (samples > 0); ++i) {      
      m_gBiasRaw[i] = temp_gBiasRaw[i] / (int16_t (samples));
      m_aBiasRaw[i] = temp_aBiasRaw[i] / (int16_t (samples));

      PRINT_DEBUG("Bias Gyro %d = %d\n", i, m_gBiasRaw[i]);
      PRINT_DEBUG("Bias Accel %d = %d\n", i, m_aBiasRaw[i]);
    }

    disableFIFO();
    usleep(20000);
    setFIFO(0, 0x00);
  }

  bool AccGyro::testWhoAmI(void) {
    if (bus_error) {
        return false;
    }

    bool passedTest = false;
    uint8_t id; // will contain  WHO_AM_I register content.
    const uint8_t expectedId = 0x68;

    try {
      id = readRegister(WHO_AM_I);
      passedTest = (id == expectedId);
    } catch (I2CException &e) {
      fileLogger->LOG(Emergency, "Could not read WHO_AM_I register.");
      fileLogger->LOG(Emergency, e.what());
      passedTest = false;
    }

    return passedTest;
  }

  void AccGyro::enableFIFO(void) {
    if (bus_error) {
        return;
    }

    uint8_t temp = readRegister(CTRL_REG9);
    temp |= (0x03);
    writeRegister(CTRL_REG9, temp);
  }

  void AccGyro::disableFIFO(void) {
    if (bus_error) {
        return;
    }

    uint8_t temp = readRegister(CTRL_REG9);
    temp &= ~(0x03);
    writeRegister(CTRL_REG9, temp);
  }

  void AccGyro::setFIFO(uint8_t mode, uint8_t fifoThs) {
    if (bus_error) {
        return;
    }

    uint8_t th = (fifoThs <= 0x1F) ? fifoThs : 0x1F;
    writeRegister(FIFO_CTRL, ((mode & 0x7) << 5) | (th & 0x1F));
  }
  
  int AccGyro::getNSamplesFIFO(void) {
     return (readRegister(FIFO_SRC) & 0x3F);
  }

  /*****************************************************************************
   * Temperature sensor:
   *****************************************************************************/

  /**
   * Vdd = 2.2 V, T = 25??C (datasheet p14):
   *
   * The output of the temperature sensor is 0 (typ) at 25??C.
   * Temperature sensitivity: 16 LSB/??C
   * Precision: 11 bit 
   */
  float AccGyro::readTempCelsius(void) {
    return ( (((float) readRawTemp()) / 16.384f) + 25.0f );
  }

  int16_t AccGyro::readRawTemp(void) {
    if (bus_error) {
        return 0;
    }

    int16_t rawTemp = 0;
    uint8_t bytes [2];

    if (isTempAvailable()) {
      try {
        bus->readRegister(I2C_ADDRESS, OUT_TEMP_L, (uint8_t *) &bytes,
                          sizeof(rawTemp));
        rawTemp = (((int16_t) bytes[1] << 12) | bytes[0] << 4) >> 4;
      } catch (I2CException &e) {
        fileLogger->LOG(Emergency, e.what());
      }
    } else {
      fileLogger->LOG(Info, "Temperature is not avilable.");
    }

    return rawTemp;
  }

  bool AccGyro::isTempAvailable(void) {
    if (bus_error) {
        return false;
    }

    bool avialable = false;
    try {
      uint8_t value = readRegister(STATUS_REG);
      avialable = value & 0x04;
    } catch (I2CException &e) {
      fileLogger->LOG(Emergency, e.what());
      avialable = false;
    }

    return avialable;
  }

  /*****************************************************************************
   * Accelerometer
   *****************************************************************************/

  /**
   * Returns acc data in mGs.
   */
  void AccGyro::readAccelMiliG(float &x, float &y, float &z) {
    if (bus_error) {
        return;
    } 

    int16_t rawX, rawY, rawZ;
    readRawAccel(rawX, rawY, rawZ);

    x = float(rawX) * m_accelSensitivity;
    y = float(rawY) * m_accelSensitivity;
    z = float(rawZ) * m_accelSensitivity;
  }

  float AccGyro::getAccelSensitivity(void) {
    return m_accelSensitivity;
  }

  void AccGyro::readRawAccel(int16_t &x, int16_t &y, int16_t &z) {
    if (bus_error) {
        return;
    }

    uint8_t bytes [6];

    try {
      bus->readRegister(I2C_ADDRESS, OUT_X_L_XL, (uint8_t *) bytes,
                        sizeof(bytes));
      x = ( (int (bytes[1])) <<8 | (bytes[0] & 0xFF)) - m_aBiasRaw[0];
      y = ( (int (bytes[3])) <<8 | (bytes[2] & 0xFF)) - m_aBiasRaw[1];
      z = ( (int (bytes[5])) <<8 | (bytes[4] & 0xFF)) - m_aBiasRaw[2];
      y = -y; // calibration.
    } catch (I2CException &e) {
      fileLogger->LOG(Emergency, "Could not read accel. data.");
      fileLogger->LOG(Emergency, e.what());
      x = y = z = 0;
    }
  }

  bool AccGyro::isAccelAvailable(void) {
    if (bus_error) {
        return false;
    }

    bool avialable = false;

    try {
    uint8_t value = readRegister(STATUS_REG);
      avialable = value & 0x01;
    } catch (std::runtime_error &re) {
      std::cout << re.what() << std::endl;
    }

    return avialable;
  }

  /*****************************************************************************
   * Gyroscope
   *****************************************************************************/

  void AccGyro::readRawGyro(int16_t &x, int16_t &y, int16_t &z) {
    if (bus_error) {
        return;
    }

    uint8_t bytes[6];

    try {
      bus->readRegister(I2C_ADDRESS, OUT_X_L_G, (uint8_t *) bytes,
                        sizeof(bytes));
      x = ( (int (bytes[1])) << 8 | (bytes[0] & 0xFF) ) - m_gBiasRaw[0];
      y = ( (int (bytes[3])) << 8 | (bytes[2] & 0xFF) ) - m_gBiasRaw[1];
      z = ( (int (bytes[5])) << 8 | (bytes[4] & 0xFF) ) - m_gBiasRaw[2];
      y = -y; // calibration.
    } catch (I2CException &e) {
      fileLogger->LOG(Emergency, "Could not read gyroscope data.");
      fileLogger->LOG(Emergency, e.what());
      x = y = z = 0;
    }
  }

  float AccGyro::getGyroSensitivity(void) {
    return m_gyroSensitivity;
  }

  /**
   * Return DegreesPerSeconds.
   */
  void AccGyro::readGyroMiliDPS(float &x, float &y, float &z) {
    if (bus_error) {
        return;
    }

    int16_t rawX, rawY, rawZ;
    readRawGyro(rawX, rawY, rawZ);

    x = float(rawX) * m_gyroSensitivity;
    y = float(rawY) * m_gyroSensitivity;
    z = float(rawZ) * m_gyroSensitivity;
  }

  bool AccGyro::isGyroAvailable(void) {
    if (bus_error) {
        return false;
    }

    bool available = false;

    try {
      uint8_t value = readRegister(STATUS_REG);
      available = value & 0x02;
    } catch (I2CException &e) {
      fileLogger->LOG(Emergency, e.what());
      available = false;
    }

    return available;
  }

  /****************************************************************************
   * Auxiliary functions:
   *****************************************************************************/
  uint8_t AccGyro::readRegister(uint8_t regAddress) {
    uint8_t value = 0;
    if (!bus_error) {
        bus->readRegister(I2C_ADDRESS, regAddress, (uint8_t *) &value, 1);
    }
    return value;
  }

  void AccGyro::writeRegister(uint8_t regAddress, uint8_t value) {
    if (!bus_error) {
        bus->writeRegister(I2C_ADDRESS, regAddress, (uint8_t *) &value, 1);
    }
  }
}
