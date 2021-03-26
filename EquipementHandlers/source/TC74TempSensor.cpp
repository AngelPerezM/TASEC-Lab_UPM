/*******************************************************************************
 * ./TC74TempSensor.h
 *
 * 09/mar/2021 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include "TC74TempSensor.h"

#include <iostream>

namespace bhs = busHandlers;

/* Function definitions
 *******************************************************************************/

namespace equipementHandlers {

  TC74TempSensor::TC74TempSensor(uint8_t bus_num ) {
    bus = bhs::BusHandlerFactory::getInstance().createI2CHandler(bus_num);
    if(bus != NULL) {
      std::cout << "TC74: I2CHandler created." << std::endl;
    }

    if(bus->isOpenned()) {
      std::cout << "TC74: I2C Bus openned." << std::endl;
    }
  }

  TC74TempSensor::~TC74TempSensor() {
    ;
  }

  /**
   * @return Internal sensor temperature 2's complement.
   */
  int8_t TC74TempSensor::getTemperature() {
    uint8_t tempRegister;
    int res = bus->readRegister(I2C_ADDRESS, RTR, (&tempRegister), 1);
    if (res < 0) {
      std::cout << "TC74: Could not read temperature" << std::endl;
      // TODO: throw exception
    }
    return tempRegister;
  }

  bool TC74TempSensor::isDataReady() {
    bool isReady = false;
    uint8_t configRegister = 0;
    int res = bus->readRegister(I2C_ADDRESS, RWCR, (&configRegister), 1);
    if (1 == res) {
      isReady = configRegister & DATA_READY;
    } else {
      std::cout << "TC74: Could not read config register" << std::endl;
    }

    return isReady;
  }
  
  void TC74TempSensor::setMode(const uint8_t configRegister) {
    int ret = bus->writeRegister(I2C_ADDRESS, RWCR, (uint8_t *) &configRegister, 1);
    if (ret < 0) {
      std::cout << "TC74: Could NOT write to config register" << std::endl;
      // TODO: throw exception.
    } else {
      std::cout << "TC74 COULD write to config register" << std::endl;
    }
  }
  
  void TC74TempSensor::setStandbyMode() {
    uint8_t configRegister;
    bus->readRegister(I2C_ADDRESS, RWCR, &configRegister, 1);
    configRegister |= SBY_SWITCH;
    setMode(configRegister);
  }

  void TC74TempSensor::setNormalMode() {
    uint8_t configRegister;
    bus->readRegister(I2C_ADDRESS, RWCR, &configRegister, 1);
    configRegister |= ~SBY_SWITCH;
    setMode(configRegister);
  }

}
