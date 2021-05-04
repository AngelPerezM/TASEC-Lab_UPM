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
    spi(bus_num, cs, 1000000)
  {
    fileLogger = FileLoggerFactory::getInstance().createFileLogger(fileName);
  }

  // DESTRUCTOR
  MCP3008::~MCP3008() {

  }

  // MANIPULATORS

  // ACCESORS
  //
  uint16_t MCP3008::get_nchan_vol_milli_data(const uint8_t channel) {
    return get_nchan_raw_data(channel)*3300.0/1024.0;
  }

  uint16_t MCP3008::get_nchan_raw_data(const uint8_t channel) {
      PRINT_DEBUG("begin\n");
      uint16_t data = 0;
      try {
	
        uint8_t reg = CH_SE_BASE | (channel << 4);
        uint8_t txBuf[3] = {1, reg, 0}; // check page 21 fom datasheet.
	uint8_t rxBuf[3] ={0, 0, 0};

	// 1byte/transfer, NO delay between transfers, 3 transfers.
        spi.multiTransfer(txBuf, rxBuf, 1, 0, 3);
        data = ( (rxBuf[1] << 8) | (rxBuf[2]) );
      } catch (bhs::SPIException &e) {
	  std::cout << std::string(e.what());
          fileLogger->LOG(Emergency, "Could not read D1 value\n"+
                                     std::string(e.what()));
      }

      PRINT_DEBUG("end\n");
      return data;
  }

};
