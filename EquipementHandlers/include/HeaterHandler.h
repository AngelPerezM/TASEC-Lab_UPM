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
    FileLogger fileLogger;

    int m_gpioPin;
    int m_gpioHandler;

    int m_realRange;
    int m_range;

    // PS = power supply:
    float m_maxPSVoltage_volts; // voltage máximo brindado por la fuente.
    float m_maxPSCurrent_amps;  // corriente máxima brindada por la fuente.

    float m_heaterResistance_ohm;
    float m_maxCurrent_amps;    // corriente consumida con duty cycle al 100%.
    float m_maxPower_watts;     // potencia disipada con duty cycle al 100%

    int power2dutyCycle(float power);
    void calculateMaxPowerAndCurrent();

    public:

      // CONSTRUCTOR
      HeaterHandler(const int gpioPin = 13,
                    const char *fileName = "/home/pi/log.txt");

      // DESTRUCTOR
      ~HeaterHandler();

      // MANIPULATORS
      void setPower(float power);

      // ACCESORS

      float getHeaterResistance_ohm(void) const;

      float getMaxPSVoltage_volts(void) const;

      float getMaxPSCurrent_amps(void) const;

      // Manipulators:

      void setHeaterResistance_ohm(const float heaterResitance_ohm);

      void setMaxPSVoltage_volts(const float maxPSVoltage_ohm);
 
      void setMaxPSCurrent_amps(const float maxPSCurrent_amps);

      void engage();

      void disengage();
  };

}
#endif // HEATER_HANDLER_H
