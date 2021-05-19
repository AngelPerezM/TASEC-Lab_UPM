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

  AccGyro::AccGyro(uint8_t bus_num)
  {

    fileLogger = FileLoggerFactory::getInstance().createFileLogger("/tmp/log.txt");

    try {
      bus = bhs::BusHandlerFactory::getInstance().createI2CHandler(bus_num);
      fileLogger->LOG(Info, "I2C handler created (bus: "+ std::to_string(bus_num) + ").");
      if (bus -> isOpenned()) {
        PRINT_DEBUG("I2C Bus openned\n");
      }
    } catch (I2CException &e) {
      fileLogger->LOG(Emergency, e.what());
    }

    if (!testWhoAmI()) {
      fileLogger->LOG(Error, "WHO_AM_I register does NOT have the expected value.");
    } else {
      fileLogger->LOG(Info, "WHO_AM_I register HAS the expected value.");
    }

    initialize();
    autocalibrate();
  }

  AccGyro::~AccGyro () {
    writeRegister(CTRL_REG1_G, 0x00);
    writeRegister(CTRL_REG6_XL, 0x00);
  }

  void AccGyro::initialize (void) {
    for ( int i = 0; i < 3; ++i) {
      m_gBiasRaw[i] = 0;
      m_aBiasRaw[i] = 0;
    }
    // Config from Mikrobus API:    
    // Operating mode: Accelerometer + Gyro.
    try {
      writeRegister(CTRL_REG3_G, 0x80); // 1000 0000

      // Gyroscope:
      // ODR = 119 Hz, low power mode, FS = +-2000 dps
      writeRegister(CTRL_REG1_G, 0x78); // 0111 1000

      // Accelerometer:
      // ODR = 119 Hz, low power mode, FS = +-16g, BW = ODR.
      writeRegister(CTRL_REG6_XL, 0x68); // 0110 1000

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
      
      readRawAccel(ax, ay, az);
      temp_aBiasRaw[0] += ax;
      temp_aBiasRaw[1] += ay;
      temp_aBiasRaw[2] += (az - (oneG));  // 1G  = gravity and facing up.
      
      readRawGyro(gx, gy, gz);
      temp_gBiasRaw[0] += gx;
      temp_gBiasRaw[1] += gy;
      temp_gBiasRaw[2] += gz;

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
    uint8_t temp = readRegister(CTRL_REG9);
    temp |= (1<<1);
    writeRegister(CTRL_REG9, temp);
  }

  void AccGyro::disableFIFO(void) {
    uint8_t temp = readRegister(CTRL_REG9);
    temp &= ~(1<<1);
    writeRegister(CTRL_REG9, temp);
  }

  void AccGyro::setFIFO(uint8_t mode, uint8_t fifoThs) {
    uint8_t th = (fifoThs <= 0x1F) ? fifoThs : 0x1F;
    writeRegister(FIFO_CTRL, ((mode & 0x7) << 5) | (th & 0x1F));
  }

  /*****************************************************************************
   * Temperature sensor:
   *****************************************************************************/

  /**
   * Vdd = 2.2 V, T = 25ºC (datasheet p14):
   *
   * The output of the temperature sensor is 0 (typ) at 25ºC.
   * Temperature sensitivity: 16 LSB/ºC
   * Precision: 11 bit 
   */
  float AccGyro::readTempCelsius(void) {
    return ( (((float) readRawTemp()) / 16.384f) + 25.0f );
  }

  int16_t AccGyro::readRawTemp(void) {
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
    int8_t bytes [6];

    if (isAccelAvailable()) {
      try {
        bus->readRegister(I2C_ADDRESS, OUT_X_L_XL, (uint8_t *) bytes,
                          sizeof(bytes));
        x = (bytes[1]<<8 | bytes[0]) - m_aBiasRaw[0];
        y = (bytes[3]<<8 | bytes[2]) - m_aBiasRaw[1];
        z = (bytes[5]<<8 | bytes[4]) - m_aBiasRaw[2];
      } catch (I2CException &e) {
        fileLogger->LOG(Emergency, "Could not read accel. data.");
        fileLogger->LOG(Emergency, e.what());
        x = y = z = 0;
      }
    } else {
      fileLogger->LOG(Error, "Accel data is not avilable.");
      x = y = z = 0;
    }
  }

  bool AccGyro::isAccelAvailable(void) {
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
    int8_t bytes[6];

    if (isGyroAvailable()) {
      try {
        bus->readRegister(I2C_ADDRESS, OUT_X_L_G, (uint8_t *) bytes,
                          sizeof(bytes));
        x = (bytes[1] << 8 | bytes[0]) - m_gBiasRaw[0];
        y = (bytes[3] << 8 | bytes[2]) - m_gBiasRaw[1];
        z = (bytes[5] << 8 | bytes[4]) - m_gBiasRaw[2];
      } catch (I2CException &e) {
        fileLogger->LOG(Emergency, "Could not read gyroscope data.");
        fileLogger->LOG(Emergency, e.what());
        x = y = z = 0;
      }
    } else {
      fileLogger->LOG(Error, "Gyro data is not avilable.");
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
    int16_t rawX, rawY, rawZ;
    readRawGyro(rawX, rawY, rawZ);

    x = float(rawX) * m_gyroSensitivity;
    y = float(rawY) * m_gyroSensitivity;
    z = float(rawZ) * m_gyroSensitivity;
  }

  bool AccGyro::isGyroAvailable(void) {
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
    bus->readRegister(I2C_ADDRESS, regAddress, (uint8_t *) &value, 1);

    return value;
  }

  void AccGyro::writeRegister(uint8_t regAddress, uint8_t value) {
    bus->writeRegister(I2C_ADDRESS, regAddress, (uint8_t *) &value, 1);
  }
}
