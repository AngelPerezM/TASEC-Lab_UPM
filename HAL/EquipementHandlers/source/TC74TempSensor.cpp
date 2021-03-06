/*******************************************************************************
 * ./TC74TempSensor.h
 *
 * 09/mar/2021 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include "TC74TempSensor.h"
#include "Utils/Debug.h"

#include <iostream>

namespace bhs = busHandlers;

/* Function definitions
 *******************************************************************************/

namespace equipementHandlers {

  TC74TempSensor::TC74TempSensor(uint8_t bus_num, const char *fileName)
  {
    fileLogger = FileLoggerFactory::getInstance().createFileLogger(fileName);
    try {
      bus = bhs::BusHandlerFactory::getInstance().createI2CHandler(bus_num);
      fileLogger->LOG(Info, "I2CHandler created.");
      bus_error = false;
      setNormalMode();
    } catch (bhs::I2CException &e) {
      bus_error = true;
      fileLogger->LOG(Emergency, e.what());
    }
  }

  TC74TempSensor::~TC74TempSensor() {
  }

  /**
   * @return Internal sensor temperature 2's complement.
   */
  int8_t TC74TempSensor::getTemperature() {
    if (bus_error) {
        return -1;
    }
    
    uint8_t tempRegister;
    try {
      bus->readRegister(I2C_ADDRESS, RTR, (&tempRegister), 1);
    } catch (bhs::I2CException &e) {
      fileLogger->LOG(Emergency, "Could not read temperature.");
      fileLogger->LOG(Emergency, e.what());
    }

    return tempRegister;
  }

  bool TC74TempSensor::isDataReady() {
    if (bus_error) {
        return false;
    }
    
    bool isReady = false;
    uint8_t configRegister = 0;
    try {
      bus->readRegister(I2C_ADDRESS, RWCR, (&configRegister), 1);
      isReady = configRegister & DATA_READY;
    } catch (bhs::I2CException &e) {
      fileLogger->LOG(Emergency, "Could not read config register.");
      fileLogger->LOG(Emergency, e.what());
    }

    return isReady;
  }
  
  void TC74TempSensor::setMode(const uint8_t configRegister) {
    if (bus_error) {
        return;
    }
    
    try {
      bus->writeRegister(I2C_ADDRESS, RWCR, (uint8_t *) &configRegister, 1);
      fileLogger->LOG(Info, "COULD write to config register");
    } catch (bhs::I2CException &e) {
      fileLogger->LOG(Emergency, "Could not write to config register");
      fileLogger->LOG(Emergency, e.what());
    }
  }
  
  void TC74TempSensor::setStandbyMode() {
    uint8_t configRegister = SBY_SWITCH;
    setMode(configRegister);
  }

  void TC74TempSensor::setNormalMode() {
    uint8_t configRegister = SBY_SWITCH & ~SBY_SWITCH;
    setMode(configRegister);
  }

}
