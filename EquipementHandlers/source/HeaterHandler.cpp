/*******************************************************************************
 * ./HeaterHandler.h
 *
 * 09/mar/2021 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include "HeaterHandler.h"

#include <pigpiod_if2.h>
#include "Utils/Debug.h"
#include "Utils/FileLoggerFactory.h"
#include <math.h> // sqrt

/* Function definitions
 *******************************************************************************/

namespace equipementHandlers {

  HeaterHandler::HeaterHandler(const int gpioPin, const char *fileName) : 
    fileLogger(FileLoggerFactory::getInstance().createFileLogger(fileName)),
    m_gpioPin(gpioPin)
  {

    m_maxPSVoltage_volts = 5.1;
    m_maxPSCurrent_amps = 2.5;

    m_heaterResistance_ohm = 108.9;
    calculateMaxPowerAndCurrent();

    m_gpioHandler = pigpio_start(NULL, NULL);

    if (m_gpioHandler < 0) {
        fileLogger.LOG(Emergency, "Could not initilize GPIO.");
    } else {
        set_mode(m_gpioHandler, m_gpioPin, PI_OUTPUT);
        if (get_mode(m_gpioHandler, m_gpioPin) == PI_OUTPUT) {
          fileLogger.LOG(Info, "Openned pin " + std::to_string(m_gpioPin) + " in output mode.");

          set_PWM_frequency(m_gpioHandler, m_gpioPin, 8000);  // 8KHz
          int freq = get_PWM_frequency(m_gpioHandler, m_gpioPin);
          m_realRange = get_PWM_real_range(m_gpioHandler, m_gpioPin);
          m_range = get_PWM_range(m_gpioHandler, m_gpioPin);
          fileLogger.LOG(Info, "PWM: freq = " + std::to_string(freq)+"\n" +
                               "     real range = "+std::to_string(m_realRange)+"\n"
                               "     range = " + std::to_string(m_range));
        }
    }
  }

  HeaterHandler::~HeaterHandler() {
    PRINT_DEBUG("begin\n");
    disengage();
  }

  /**
   * power: Watts to be consumed by the heater.
   */
  void HeaterHandler::setPower(float power) {
    PRINT_DEBUG("TODO: Setting to power %f\n", power);

    if(power > m_maxPower_watts) {
      fileLogger.LOG(Alert,
        "The power requested ("+std::to_string(power)+
        "W) exceeds the limit ("+std::to_string(m_maxPower_watts)+"W).");
      power = m_maxPower_watts;
    } else if (power < 0) {
      fileLogger.LOG(Alert,
        "The power requested ("+std::to_string(power)+") is negative.");
      power = 0;
    }

    int dc = power2dutyCycle(power);
    PRINT_DEBUG("Duty cycle calculated = %d*100/255 [percent]\n", dc);
    if(dc > m_range || dc < 0) {
      fileLogger.LOG(Alert,
          "dutyCycle calculated "+std::to_string(dc)+
          " is not valid according to the range.");
      dc = (dc > m_range)?(m_range):(0);
    }

    set_PWM_dutycycle(m_gpioHandler, m_gpioPin, dc);
  }

  int HeaterHandler::power2dutyCycle(float power) {
    float requestedVoltage = sqrt(power*m_heaterResistance_ohm); // volts
    float dutyCycle_percent = requestedVoltage / m_maxPSVoltage_volts;
    return (int) (m_range * dutyCycle_percent);
  }

  void HeaterHandler::calculateMaxPowerAndCurrent() {
    m_maxCurrent_amps = m_maxPSVoltage_volts/m_heaterResistance_ohm;
    m_maxPower_watts = m_maxPSVoltage_volts * m_maxCurrent_amps;
  }

  void HeaterHandler::engage() {
    if (0 == gpio_write(m_gpioHandler, m_gpioPin, 1)) {
      PRINT_DEBUG("Engaged.");
    } else {
      fileLogger.LOG(Emergency, "Could not set " + std::to_string(m_gpioPin) +
                                " HIGH.");
    }
  }

  void HeaterHandler::disengage() {
    if (0 == gpio_write(m_gpioHandler, m_gpioPin, 0)) {
      PRINT_DEBUG("Disengaged.");
    } else {
      fileLogger.LOG(Emergency, "Could not set " + std::to_string(m_gpioPin) +
                                " LOW.");
    }
  }

  float HeaterHandler::getHeaterResistance_ohm(void) const {
    return m_heaterResistance_ohm;
  }

  float HeaterHandler::getMaxPSVoltage_volts(void) const {
    return m_maxPSVoltage_volts;
  }

  float HeaterHandler::getMaxPSCurrent_amps(void) const {
    return m_maxPSCurrent_amps;
  }

  void HeaterHandler::setHeaterResistance_ohm(const float heaterResitance_ohm) {
    m_heaterResistance_ohm = heaterResitance_ohm;
    calculateMaxPowerAndCurrent();
  }

  void HeaterHandler::setMaxPSVoltage_volts(const float maxPSVoltage_ohm) {
    // TODO: what is the max voltage supported by the heater?
    m_maxPSVoltage_volts = maxPSVoltage_ohm;
    calculateMaxPowerAndCurrent();
  }

  void HeaterHandler::setMaxPSCurrent_amps(const float maxPSCurrent_amps) {
    // TODO: what is the max current supported by the heater?
    m_maxPSCurrent_amps = maxPSCurrent_amps;
    calculateMaxPowerAndCurrent();
  }
}
