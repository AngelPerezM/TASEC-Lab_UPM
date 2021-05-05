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

  HeaterHandler::HeaterHandler(const int gpioPin, const char *fileName,
                               const unsigned PWMFreq) :     
    m_gpioPin(gpioPin),
    m_PWMFreq(PWMFreq)
  {

    fileLogger = FileLoggerFactory::getInstance().createFileLogger(fileName);
    calculateMaxPowerAndCurrent();
    m_gpioHandler = pigpio_start(NULL, NULL);

    if (m_gpioHandler < 0) {
      fileLogger->LOG(Emergency, "Could not initilize GPIO.");
    } else {
      configPinModeAndPWM();
    }
  }

  void HeaterHandler::configPinModeAndPWM() {
    int mode = PI_OUTPUT;

    // Enables hardware PWM if it is supported by the pin.
    hwPWMAvilable = m_gpioPin == 12 || m_gpioPin ==13 || m_gpioPin == 18;
    if (hwPWMAvilable) {
      fileLogger->LOG(Info, "Hardware PWM is available.");
      switch(m_gpioPin) {
        case 12:
          mode |= PI_ALT0; // PWM0
          break;
        case 13:
          mode |= PI_ALT0; // PWM1
          break;
        case 18:
          mode |= PI_ALT5; // PWM0
          break;
      }
    }

    set_mode(m_gpioHandler, m_gpioPin, mode);
    if (get_mode(m_gpioHandler, m_gpioPin) == mode) {
      fileLogger->LOG(Info, "Set mode of pin " + std::to_string(m_gpioPin) + " correctly.");
      
      if(!hwPWMAvilable) {
        set_PWM_frequency(m_gpioHandler, m_gpioPin, m_PWMFreq);
      } else {
        // The purpose of this call is to get the real range and range correct.
        hardware_PWM(m_gpioHandler, m_gpioPin, m_PWMFreq, 0); 
      }

      m_PWMFreq = get_PWM_frequency(m_gpioHandler, m_gpioPin);
      m_realRange = get_PWM_real_range(m_gpioHandler, m_gpioPin);
      m_range = get_PWM_range(m_gpioHandler, m_gpioPin);

      fileLogger->LOG(Info, "PWM: freq = " + std::to_string(m_PWMFreq)+"\n" +
                            "     real range = "+std::to_string(m_realRange)+"\n"
                            "     range = " + std::to_string(m_range));
    } else {
      fileLogger->LOG(Error, "Could not set mode of pin " + std::to_string(m_gpioPin) + ".");
    }
  }

  HeaterHandler::~HeaterHandler() {
    PRINT_DEBUG("begin\n");
    disengage();
    pigpio_stop(m_gpioHandler);
  }

  /**
   * power: Watts to be consumed by the heater.
   */
  void HeaterHandler::setPower(float power) {
    PRINT_DEBUG("TODO: Setting to power %f\n", power);

    if(power > m_maxPower_watts) {
      fileLogger->LOG(Alert,
        "The power requested ("+std::to_string(power)+
        "W) exceeds the limit ("+std::to_string(m_maxPower_watts)+"W).");
      power = m_maxPower_watts;
    } else if (power < 0) {
      fileLogger->LOG(Alert,
        "The power requested ("+std::to_string(power)+") is negative.");
      power = 0;
    }

    float dc = power2dutyCycle(power);
    PRINT_DEBUG("Duty cycle calculated = %f [percent]\n", dc);
    if(dc > 100.0 || dc < 0.0) {
      fileLogger->LOG(Alert,
          "dutyCycle calculated "+std::to_string(dc)+
          " is not valid according to the range.");
      dc = (dc > 100.0)?(100.0):(0.0);
    }

    int dcInRange = dc*m_range/100.0;
    if (hwPWMAvilable){
      hardware_PWM(m_gpioHandler, m_gpioPin, m_PWMFreq, dcInRange); 
    } else {
      set_PWM_dutycycle(m_gpioHandler, m_gpioPin, dcInRange);
    }

  }

  float HeaterHandler::power2dutyCycle(float power) {
    float requestedVoltage = sqrt(power*m_heaterResistance_ohm); // volts
    PRINT_DEBUG("Requested voltage: %f\n", requestedVoltage);
    float dutyCycle_percent = requestedVoltage / m_maxPSVoltage_volts * 100.0;
    PRINT_DEBUG("DC percent: %f\n", dutyCycle_percent);
    return (dutyCycle_percent);
  }

  void HeaterHandler::calculateMaxPowerAndCurrent() {
    m_maxCurrent_amps = m_maxPSVoltage_volts/m_heaterResistance_ohm;
    m_maxPower_watts = m_maxPSVoltage_volts * m_maxCurrent_amps;
  }

  void HeaterHandler::engage() {
    if (0 == gpio_write(m_gpioHandler, m_gpioPin, 1)) {
      PRINT_DEBUG("Engaged.");
    } else {
      fileLogger->LOG(Emergency, "Could not set " + std::to_string(m_gpioPin) +
                                " HIGH.");
    }
  }

  void HeaterHandler::disengage() {
    if (0 == gpio_write(m_gpioHandler, m_gpioPin, 0)) {
      PRINT_DEBUG("Disengaged.");
    } else {
      fileLogger->LOG(Emergency, "Could not set " + std::to_string(m_gpioPin) +
                                " LOW.");
    }
  }

  void HeaterHandler::setPWMFreq(const unsigned PWMFreq) {
    m_PWMFreq = PWMFreq;
    if(!hwPWMAvilable) {
      set_PWM_frequency(m_gpioHandler, m_gpioPin, m_PWMFreq);
      m_PWMFreq = get_PWM_frequency(m_gpioHandler, m_gpioPin);
    }
    m_realRange = get_PWM_real_range(m_gpioHandler, m_gpioPin);
    m_range = get_PWM_range(m_gpioHandler, m_gpioPin);
    fileLogger->LOG(Info, "PWM: freq = " + std::to_string(m_PWMFreq)+"\n" +
                         "     real range = "+std::to_string(m_realRange)+"\n"
                         "     range = " + std::to_string(m_range));
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
