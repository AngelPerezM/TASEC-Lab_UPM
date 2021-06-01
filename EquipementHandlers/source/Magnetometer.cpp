/*******************************************************************************
 * 11/mar/2021 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include "Magnetometer.h"
#include "Utils/Debug.h"

#include <string>
#include <iostream>
#include <stdexcept>

namespace bhs = busHandlers;

namespace equipementHandlers {

  // CONSTRUCTOR
  Magnetometer::Magnetometer(uint8_t bus_num, const char *fileLogName)
  {

    fileLogger = FileLoggerFactory::getInstance().createFileLogger(fileLogName);
    try {
      bus = bhs::BusHandlerFactory::getInstance().createI2CHandler(bus_num);
      bus_error = false;
      if (bus->isOpenned()) {
        PRINT_DEBUG("I2C BUS is openned\n");
      }
    } catch (bhs::I2CException &e) {
      bus_error = true;
      fileLogger->LOG(Emergency, e.what());
    }

    if (!testWhoAmI()) {
      fileLogger->LOG(Error, "WHO_AM_I register does NOT have the expected value.");
    } else {
      fileLogger->LOG(Info, "WHO_AM_I register HAS the expected value.");
    }

    initialize();
  }

  // DESTRUCTOR
  Magnetometer::~Magnetometer() {
    // Power down mode.
    writeRegister(CTRL_REG3_M, 0x03);
  }

  /**
   * Config from Mikrobus API:
   */
  void Magnetometer::initialize (void) {
    if (bus_error) {
        return;
    }

    try {
    // 1101 0000: X and Y high performance mode (HPM), and  tempoerature
    // compensation enabled. Output Data Rate = 10 Hz.
    writeRegister(CTRL_REG1_M, 0xD0);

    // +- 4 gauss and normal mode.
    writeRegister(CTRL_REG2_M, 0x00); 

    // set to Continous convertion mode.
    writeRegister(CTRL_REG3_M, 0x00); 

    // 0000 1000: Z HPM and little endian. 
    writeRegister(CTRL_REG4_M, 0x08);

    // 0100 0000: Output regs do not update until LSB and MSB have been read.
    writeRegister(CTRL_REG5_M, 0x40);

    m_sensitivity = 0.14; // FS = +-4 gauss <-> 0.14 mgauss/LSB

    } catch (bhs::I2CException &e) {
      fileLogger->LOG(Emergency, e.what());
    }
  }

  // MANIPULATORS
  void Magnetometer::enableTemperatureCompensation (void) {
    if(bus_error) {
        return;
    }

    const uint8_t TEMP_COMP = 0x80;
    uint8_t regValue;

    regValue = readRegister(CTRL_REG1_M);
    regValue |= TEMP_COMP;
    try {
      writeRegister(CTRL_REG1_M, regValue);
    } catch (bhs::I2CException &e) {
      fileLogger->LOG(Warning, "Could not enable temperature compensation.");
      fileLogger->LOG(Error, e.what());
    }
  }

  // ACCESORS
  bool Magnetometer::testWhoAmI (void) {
    if (bus_error) {
        return false;
    }

    bool passedTest = false;
    uint8_t id; // will contain  WHO_AM_I register content.
    const uint8_t expectedId = 0x3D;

    try {
      id = readRegister(WHO_AM_I_M);
      passedTest = (id == expectedId);
    } catch (bhs::I2CException &e) {
      fileLogger->LOG(Emergency, "Could not read WHO_AM_I register.");
      fileLogger->LOG(Emergency, e.what());
      passedTest = false;
    }

    return passedTest;
  }

  /**
   * axis:
   *  0 = X axis,
   *  1 = Y axis,
   *  2 = Z axis,
   *  3 = All axis.
   */
  bool Magnetometer::isDataAvailable(uint8_t axis) {
    if (bus_error) {
        return false;
    }

    bool available = false;

    if ( axis < 4 && axis > 0) {
      const uint8_t reg = 1 << (axis);
      try {
        available = readRegister(STATUS_REG_M) & reg;
      } catch (bhs::I2CException &e) {
        fileLogger->LOG(Emergency, "Could not read STATUS_REG_M register.");
        fileLogger->LOG(Emergency, e.what());
        available = false;
      }
    } else {
      fileLogger->LOG(Error, "Argument axis " + std::to_string(axis) + " is invalid.");
    }

    return available;
  }

  void Magnetometer::readRawData(int16_t &x, int16_t &y, int16_t &z) {

    if (isDataAvailable() && !bus_error) {
      PRINT_DEBUG("Data is available.\n");
      // MSB = address autoincrement MSB = address autoincrement.
      uint8_t reg = OUT_X_L_M | 0x80;
      try {
        uint8_t bytes [6];
        bus->readRegister(I2C_ADDRESS, reg, (uint8_t *) bytes, sizeof(bytes));

        x = (bytes[1] << 8 | bytes[0]);
        y = (bytes[3] << 8 | bytes[2]);
        z = (bytes[5] << 8 | bytes[4]);
        PRINT_DEBUG("Raw data: %d, %d, %d\n", x, y, z);
      } catch (bhs::I2CException &e) {
        fileLogger->LOG(Emergency, "Could not read Magnetometer raw data.");
        fileLogger->LOG(Emergency, e.what());
        x = y = z = 0;
      }
    } else {
      fileLogger->LOG(Error, "Magnetometer Data is not available.");
      x = y = z = 0;
    }
  }

  float Magnetometer::getSensitivity(void) {
      return m_sensitivity;
  }

  /**
   * Output params unit: mgauss.
   */
  void Magnetometer::readMiliGauss(float &x, float &y, float &z) {
    int16_t rawX, rawY, rawZ;
    readRawData(rawX, rawY, rawZ);

    x = float(rawX) * m_sensitivity;
    y = float(rawY) * m_sensitivity;
    z = float(rawZ) * m_sensitivity;
  }

  /****************************************************************************
   * Auxiliary functions:
   *****************************************************************************/
  uint8_t Magnetometer::readRegister(uint8_t regAddress) {

    uint8_t value = 0;
    if(!bus_error) {
        bus->readRegister(I2C_ADDRESS, regAddress, (uint8_t *) &value, 1);
    }

    return value;
  }

  void Magnetometer::writeRegister(uint8_t regAddress, uint8_t value) {
    if (!bus_error) {
        bus->writeRegister(I2C_ADDRESS, regAddress, (uint8_t *) &value, 1);
    }
  }
}
