/*******************************************************************************
 * ./Thermostat.h
 *
 * 09/mar/2021 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include "Thermostat.h"

#include "Utils/Debug.h"
#include "Utils/FileLoggerFactory.h"

using namespace gpiod;

/* Function definitions
 *******************************************************************************/

namespace equipementHandlers {

  Thermostat::Thermostat(const int gpioPin, const char *fileName) : 
    fileLogger(FileLoggerFactory::getInstance().createFileLogger(fileName)),
    chip("0")
  {
    line = chip.get_line(gpioPin);

    config.request_type = gpiod::line_request::DIRECTION_OUTPUT;
    line.request(config);

    if (chip) {
      fileLogger.LOG(Info, "Openned chip: " + chip.name() + ", " + chip.label());
      if (line) {
        fileLogger.LOG(Info, "Openned line with offset: " +
                              std::to_string(line.offset()));
      } else {
        fileLogger.LOG(Emergency, "Could not open line " + std::to_string(gpioPin));
      }
    } else {
      fileLogger.LOG(Emergency, "Could not open chip 0");
    }


    line.set_value(1);
  }

  Thermostat::~Thermostat() {
    PRINT_DEBUG("begin\n");
    line.set_value(0);
    chip.~chip();
    line.~line();
  }


  void Thermostat::engage() {
    line.set_value(1);
    m_currState = ENGAGED;
  }

  void Thermostat::disengage() {
    line.set_value(0);
    m_currState = DISENGAGED;
  }

  int Thermostat::getStatus() {
    return m_currState;
  }
}
