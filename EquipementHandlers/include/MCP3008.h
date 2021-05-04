#ifndef MCP3008_H
#define MCP3008_H

/*******************************************************************************
 * 03/may/2021 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include "BusHandlers/SPIHandler.h"
#include "Utils/FileLoggerFactory.h"

#include <cstdint>  // fixed size integers
#include <string>

using namespace utils;
namespace bhs = busHandlers;

namespace equipementHandlers {
  class MCP3008 {
    private:

      FileLogger *fileLogger;

      enum Register : uint8_t {
         CH_SE_BASE = 0x80, // 1000 XXXX
      };

      bhs::SPIHandler spi;

    public:

      // CONSTRUCTOR
      MCP3008(uint8_t bus_num = 0, uint8_t cs = 0,
              const char *fileName = "/home/pi/log.txt");

      // DESTRUCTOR
      ~MCP3008();


      // ACCESORS
      // @pre: 0 <= channel <= 7
      uint16_t get_nchan_raw_data(const uint8_t channel);
      uint16_t get_nchan_vol_milli_data(const uint8_t channel);

  };

}

#endif // PRESSURE_SENSOR_H
