/*******************************************************************************
 * 15/mar/2021 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include "AccGyro.h"
#include <iostream>
#include <stdexcept>
#include <cmath>  // NAN

namespace bhs = busHandlers;

namespace equipementHandlers {

  // CONSTRUCTOR
  AccGyro::AccGyro(uint8_t bus_num) {
    bus = bhs::BusHandlerFactory::getInstance().createI2CHandler(bus_num);
    if (bus != NULL) {
      std::cout << "AccGyro: I2CHandler created." << std::endl;
    }
    if (bus -> isOpenned()) {
      std::cout << "AccGyro: I2C Bus openned" << std::endl;
    }

    if (!testWhoAmI()) {
      std::cout << "[ERROR] AccGyro is corrupted." << std::endl;
    }

    // Config from Mikrobus API:    
    // Operating mode: Accelerometer + Gyro.
    
    writeRegister(CTRL_REG3_G, 0x80); // 1000 0000
    
    // Accelerometer:
    // ODR = 119 Hz, low power mode, FS = +-2000 dps
    writeRegister(CTRL_REG1_G, 0x78); // 0111 1000

    // Gyroscope:
    // ODR = 119 Hz, low power mode, FS = +-16g, BW = ODR.
    writeRegister(CTRL_REG6_XL, 0x68); // 0110 1000

    // Output regs not updated until msb and lsb read.
    // Little endian, and register addres automatically incremented during
    // multiple byte access with a serial interface.
    writeRegister(CTRL_REG8, 0x44); // 0100 0100

    m_gyroSensitivity = 70.0; // +-2000 dps <-> 70 mdps/LSB
    m_accelSensitivity = 0.732; // +-16g <-> 0.732 mg/LSB

  }

  // DESTRUCTOR
  AccGyro::~AccGyro() {

  }

  // MANIPULATORS

  // ACCESORS
  bool AccGyro::testWhoAmI(void) {
    bool passedTest = false;
    uint8_t id; // will contain  WHO_AM_I register content.
    const uint8_t expectedId = 0x68;

    try {
      id = readRegister(WHO_AM_I);
      passedTest = (id == expectedId);
      if (!passedTest) {
        printf("AccGyro: Expected id %d, but got %d\n", 
            (uint16_t) expectedId, (uint16_t) id);
      } else {
        std::cout << "AccGyro: ID OK" << std::endl;
      }
    } catch (std::runtime_error &re) {
      std::cout << re.what() << std::endl;
      passedTest = false;
    }

    return passedTest;
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
    return ( ( ((float) readRawTemp()) / 16.384f) + 25.0f );
  }

  int16_t AccGyro::readRawTemp(void) {
    int16_t rawTemp = 0;
    uint8_t bytes [2];

    if (isTempAvailable()) {
      int ret = -1;
      ret = bus->readDataTransaction(I2C_ADDRESS, OUT_TEMP_L, (char *) &bytes,
                                     sizeof(rawTemp));
      rawTemp = (((int16_t) bytes[1] << 12) | bytes[0] << 4) >> 4;
      if (ret < 0) {
        throw std::runtime_error("AccGyro: Could not read temp.");
      }
    }

    return rawTemp;
  }

  bool AccGyro::isTempAvailable(void) {
    bool avialable = false;
    try {
      uint8_t value = readRegister(STATUS_REG);
      avialable = value & 0x04;
    } catch (std::runtime_error &re) {
      std::cout << re.what() << std::endl;
    }

    return avialable;
  }

  /*****************************************************************************
   * Accelerometer
   *****************************************************************************/

  /**
   * Returns acc data in Gs.
   */
  AccGyro::Data AccGyro::readAccel(void) {
    Data accelData = {.x = 0, .y = 0, .z = 0};
    int8_t bytes [6];

    if (isGyroAvailable()) {
      int ret = -1;
      ret = bus->readDataTransaction(I2C_ADDRESS, OUT_X_L_XL, (char*) bytes,
                                     sizeof(bytes));
      if (ret < 0) {
        throw std::runtime_error("AccGyro: Could not read accelerometer data.");
      } else {

        accelData.x = (float (bytes[1]<<8 | bytes[0])) * m_accelSensitivity / 1000.0;
        accelData.y = (float (bytes[3]<<8 | bytes[2])) * m_accelSensitivity / 1000.0;
        accelData.z = (float (bytes[5]<<8 | bytes[4])) * m_accelSensitivity / 1000.0;
      }
    }

    return accelData;
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

  /**
   * Return DegreesPerSeconds.
   */
  AccGyro::Data AccGyro::readGyro(void) {
    Data gyroData = {.x = 0, .y = 0, .z = 0};
    int8_t bytes[6];

    if (isGyroAvailable()) {
      int ret = -1;
      ret = bus->readDataTransaction(I2C_ADDRESS, OUT_X_L_G, (char *) bytes, 
                                     sizeof(bytes));
      if (ret < 0) {
        throw std::runtime_error("AccGyro: Could not read gyro data.");
      } else {
        gyroData.x = (float (bytes[1] << 8 | bytes[0])) * m_gyroSensitivity / 1000.0;
        gyroData.y = (float (bytes[3] << 8 | bytes[2])) * m_gyroSensitivity / 1000.0;
        gyroData.z = (float (bytes[5] << 8 | bytes[4])) * m_gyroSensitivity / 1000.0;
      }
    }

    return gyroData;
  }

  bool AccGyro::isGyroAvailable(void) {
    bool avialable = false;

    try {
      uint8_t value = readRegister(STATUS_REG);
      avialable = value & 0x02;
    } catch (std::runtime_error &re) {
      std::cout << re.what() << std::endl;
    }

    return avialable;
  }

  // TODO: write the following functions in the I2C handler as generics.
  uint8_t AccGyro::readRegister(uint8_t regAddress) {
    uint8_t value = 0;
    int ret = -1;

    bus->setSlaveAddress(I2C_ADDRESS);
    ret = bus->readDataTransaction(regAddress, (char *) &value, 1);
    if (ret < 0) {
      char err[81];
      sprintf(err, "Could not read from register %d", uint16_t (regAddress));
      throw std::runtime_error(err);
    }

    return value;
  }

  void AccGyro::writeRegister(uint8_t regAddress, uint8_t value) {
    int ret = -1;

    bus->setSlaveAddress(I2C_ADDRESS);
    ret = bus->writeDataTransaction(regAddress, (char *) &value, 1);
    if (ret < 0) {
      char err[81];
      sprintf(err, "Could not write to register %d", uint16_t (regAddress));
      throw std::runtime_error(err);
    }
  }
}
