#ifndef HEATER_HANDLER_H
#define HEATER_HANDLER_H

/*******************************************************************************
 * 31/mar/2021 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include <stdint.h>

#include "Utils/FileLogger.h"

using namespace utils;

namespace equipementHandlers {
  class HeaterHandler {
    private:
    FileLogger *fileLogger;

    int m_gpioPin;
    int m_gpioHandler;

    int m_realRange;
    int m_range;
    int m_PWMFreq;

    // PS = power supply:
    float m_maxPSVoltage_volts = 5.1; // voltaje máximo brindado por la fuente.
    float m_maxPSCurrent_amps = 2.5;  // corriente máxima brindada por la fuente.

    float m_heaterResistance_ohm = 108.9; /**< Heater resistance value in OHMs. */
    float m_maxCurrent_amps;    /**< Current consumed with duty cycle = 100%. */
    float m_maxPower_watts;     /**< Power disipated with duty cycle = 100%. */

    float m_actualDC = 0;
    float m_actualPower = 0;

    bool hwPWMAvilable;

    float power2dutyCycle(float power);
    void calculateMaxPowerAndCurrent();
    void configPinModeAndPWM();
    int setDutyCycle(float dc);
    public:

      // CONSTRUCTOR
      HeaterHandler(const int gpioPin = 13,
                    const char *fileName = "/home/pi/blackbox.log",
                    const unsigned PWMFreq = 8000);

      // DESTRUCTOR
      ~HeaterHandler();

      // ACCESORS
      float getActualPower(void) const;

      float getActualDutyCycle(void) const;

      float getHeaterResistance_ohm(void) const;

      float getMaxPSVoltage_volts(void) const;

      float getMaxPSCurrent_amps(void) const;

      // MANIPULATORS
      int setPower(const float power);

      /**
       * Heater is on with maximum power (Duty cycle = 100%).
       */
      int engage();

      /**
       * Heater is off (Duty cycle = 0%).
       */
      int disengage();

      /**
       * Sets the PWM frequency to be applied with setPower.
       */
      void setPWMFreq(const unsigned PWMFreq);
      
      void setHeaterResistance_ohm(const float heaterResitance_ohm);

      void setMaxPSVoltage_volts(const float maxPSVoltage_ohm);
 
      void setMaxPSCurrent_amps(const float maxPSCurrent_amps);
  };

}
#endif // HEATER_HANDLER_H
