/*******************************************************************************
 * ./HeaterHandler.h
 *
 * 09/mar/2021 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include "HeaterHandler.h"

#include <pigpio.h>
#include "Utils/Debug.h"
#include "Utils/FileLoggerFactory.h"

/* Function definitions
 *******************************************************************************/

namespace equipementHandlers {

  HeaterHandler::HeaterHandler(const int gpioPin, const char *fileName) : 
    fileLogger(FileLoggerFactory::getInstance().createFileLogger(fileName)),
    m_gpioPin(gpioPin)
  {
    m_heaterResistance_ohm = 108.9;
    m_maxVoltage_volts = 5.1;
    m_maxCurrent_amps = 2.5;

    if (gpioInitialise() < 0) {
        fileLogger.LOG(Emergency, "Could not initilize GPIO.");
    } else {
        gpioSetMode(gpioPin, PI_OUTPUT);
        if (gpioGetMode(gpioPin) == PI_OUTPUT) {
          fileLogger.LOG(Info, "Openned pin " + std::to_string(gpioPin) +
                               " in output mode.");
        }
    }
  }

  HeaterHandler::~HeaterHandler() {
    PRINT_DEBUG("begin\n");
    disengage();
  }

  void HeaterHandler::setPower(float power) {
    PRINT_DEBUG("Setting to power %f\n", power);
  }

  void HeaterHandler::engage() {
    if (0 == gpioWrite(m_gpioPin, 1)) {
      PRINT_DEBUG("Engaged.");
    } else {
      fileLogger.LOG(Emergency, "Could not set " + std::to_string(m_gpioPin) +
                                " HIGH.");
    }
  }

  void HeaterHandler::disengage() {
     if (0 == gpioWrite(m_gpioPin, 0)) {
      PRINT_DEBUG("Disengaged.");
    } else {
      fileLogger.LOG(Emergency, "Could not set " + std::to_string(m_gpioPin) +
                                " LOW.");
    }
  }

  float HeaterHandler::getHeaterResistance_ohm(void) const {
    return m_heaterResistance_ohm;
  }

  float HeaterHandler::getMaxVoltage_volts(void) const {
    return m_maxVoltage_volts;
  }

  float HeaterHandler::getMaxCurrent_amps(void) const {
    return m_maxCurrent_amps;
  }

  void HeaterHandler::setHeaterResistance_ohm(const float heaterResitance_ohm) {
    m_heaterResistance_ohm = heaterResitance_ohm;
  }

  void HeaterHandler::setMaxVoltage_volts(const float maxVoltage_ohm) {
    // TODO: what is the max voltage supported by the heater?
    m_maxVoltage_volts = maxVoltage_ohm;
  }

  void HeaterHandler::setMaxCurrent_amps(const float maxCurrent_amps) {
    // TODO: what is the max current supported by the heater?
    m_maxCurrent_amps = maxCurrent_amps;
  }
}
