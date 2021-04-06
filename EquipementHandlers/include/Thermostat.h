#ifndef THERMOSTAT_H
#define THERMOSTAT_H

/*******************************************************************************
 * 31/mar/2021 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include <stdint.h>
#include <gpiod.hpp>

#include "Utils/FileLogger.h"

using namespace utils;

namespace equipementHandlers {
  class Thermostat {
    private:
    FileLogger fileLogger;
    gpiod::chip chip;
    gpiod::line line;
    gpiod::line_request config;
    int m_currState;

    public:

      // CONSTRUCTOR
      Thermostat(const int gpioPin = 12, const char *fileName="/home/pi/log.txt");

      // DESTRUCTOR
      ~Thermostat();

      // ACCESORS
      int getStatus(void);

      // MANIPULATORS
      void engage(void);

      void disengage(void);

      enum : int {
          ENGAGED = 1,
          DISENGAGED = 0
      };
  };

}
#endif // THERMOSTAT_H
