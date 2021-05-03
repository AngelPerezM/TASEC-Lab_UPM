/*******************************************************************************
 * 03/may/2021 - Version 1.0
 *
 * IMPORTANT:
 * =========
 * - This is a big endian slave.
 *******************************************************************************/

/* Include section
 *******************************************************************************/

#include "MCP3008.h"
#include "Utils/Debug.h"

#include <iostream>
#include <unistd.h>

namespace equipementHandlers {
  // CONSTRUCTOR
  MCP3008::MCP3008(uint8_t bus_num, uint8_t cs, const char *fileName):
    spi(bus_num, cs, 10000000)
  {
    fileLogger = FileLoggerFactory::getInstance().createFileLogger(fileName);
  }

  // DESTRUCTOR
  MCP3008::~MCP3008() {

  }

  // MANIPULATORS

  // ACCESORS
  uint16_t MCP3008::getDigitalData(const uint8_t channel) {
      PRINT_DEBUG("begin\n");
      uint16_t data = 0;
      try {
        uint8_t buf[2];
        uint8_t reg = CH_SE_BASE | (channel << 4);
        spi.readRegister(reg, buf, sizeof(buf), 0); // NO DELAY.
        data = ( ((buf[0] << 8) & 0xC0) | (buf[1] & 0xFF) );
      } catch (bhs::SPIException &e) {
          fileLogger->LOG(Emergency, "Could not read D1 value\n"+
                                     std::string(e.what()));
      }

      PRINT_DEBUG("end\n");
      return data;
  }

};
