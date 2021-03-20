/*******************************************************************************
 * 11/mar/2021 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include "Magnetometer.h"
#include <iostream>
#include <stdexcept>

namespace bhs = busHandlers;

namespace equipementHandlers {

  // CONSTRUCTOR
  Magnetometer::Magnetometer(uint8_t bus_num) {
    bus = bhs::BusHandlerFactory::getInstance().createI2CHandler(bus_num);
    if(bus != NULL) {
      std::cout << "Magnetometer: I2CHandler created." << std::endl;
    }
    if(bus->isOpenned()) {
      std::cout << "Magnetometer: I2C Bus Openned." << std::endl;
    }

    if (!testWhoAmI()) {
      std::cout << "[ERROR] Magnetometer is corrupted." << std::endl;
    }

    // Config from Mikrobus API:

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
  }

  // DESTRUCTOR
  Magnetometer::~Magnetometer() {
    ;
  }

  // MANIPULATORS
  void Magnetometer::enableTemperatureCompensation (void) {
    const uint8_t TEMP_COMP = 0x80;
    uint8_t regValue;

    regValue = readRegister(CTRL_REG1_M);
    regValue |= TEMP_COMP;
    writeRegister(CTRL_REG1_M, regValue);
  }

  // ACCESORS
  bool Magnetometer::testWhoAmI (void) {
    bool passedTest = false;
    uint8_t id; // will contain  WHO_AM_I register content.
    const uint8_t expectedId = 0x3D;

    try {
      id = readRegister(WHO_AM_I_M);
      passedTest = (id == expectedId);
      if (!passedTest) {
        printf("Magnetometer: Expected id %d, but got %d\n", 
            (uint16_t) expectedId, (uint16_t) id);
      } else {
        std::cout << "Magnetometer: ID OK" << std::endl;
      }
    } catch (std::runtime_error &re) {
      std::cout << re.what() << std::endl;
      passedTest = false;
    }

    return passedTest;
  }

  bool Magnetometer::isZAxisAvailable() {
    const uint8_t ZDA = 0x04;
    return readRegister(STATUS_REG_M) & ZDA;
  }

  bool Magnetometer::isXAxisAvailable() {
    const uint8_t XDA = 0x01;
    return readRegister(STATUS_REG_M) & XDA;
  }

  bool Magnetometer::isYAxisAvailable() {
    const uint8_t YDA = 0x02;
    return readRegister(STATUS_REG_M) & YDA;
  }

  int16_t Magnetometer::readZAxis() {
    if (!isZAxisAvailable()) {
      std::cout << "Z data is not available" << std::endl;
      return 0;
    }

    int16_t result = 0;
    uint8_t zaxis [2];

    zaxis[0] = readRegister(OUT_Z_L_M);
    zaxis[1] = readRegister(OUT_Z_H_M);
    result = (zaxis[1] << 8) | zaxis[0];

    return result;
  }

  int16_t Magnetometer::readXAxis() {
    if (!isXAxisAvailable()) {
      std::cout << "X data is not available" << std::endl;
      return 0;
    }

    int16_t result = 0;
    uint8_t xaxis [2];

    xaxis[0] = readRegister(OUT_X_L_M);
    xaxis[1] = readRegister(OUT_X_H_M);
    result = (xaxis[1] << 8) | xaxis[0];

    return result;
  }

  int16_t Magnetometer::readYAxis() {
    if (!isYAxisAvailable()) {
      std::cout << "Y data is not available" << std::endl;
      return 0;
    }
 
    int16_t result = 0;
    uint8_t yaxis [2];

    yaxis[0] = readRegister(OUT_X_L_M);
    yaxis[1] = readRegister(OUT_X_H_M);
    result = (yaxis[1] << 8) | yaxis[0];

    return result;
  }

  Magnetometer::MagData Magnetometer::readAllAxis() {
    return {.xAxis = readXAxis(),
            .yAxis = readYAxis(), 
            .zAxis = readZAxis()
           };
  }

  // TODO: write the following functions in the I2C handler as generics.
  uint8_t Magnetometer::readRegister(uint8_t regAddress) {
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

  void Magnetometer::writeRegister(uint8_t regAddress, uint8_t value) {
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
