#ifndef BUS_HANDLER_FACTORY_H
#define BUS_HANDLER_FACTORY_H

#include <unordered_map>
#include <stdint.h>

#include "I2CHandler.h"
// #include "SPIHandler.h"
// #include "SerialHandler.h"

namespace busHandlers {
  class BusHandlerFactory {
    private:
      std::unordered_map <uint8_t, I2CHandler *> i2cHandlers;

      BusHandlerFactory();

      BusHandlerFactory(const BusHandlerFactory&) = delete;

      BusHandlerFactory& operator=(const BusHandlerFactory&) = delete;

      ~BusHandlerFactory();

    public:
      
      /**
       * Sinc c++11 local static are thread safe.
       */
      static BusHandlerFactory &getInstance() {
        static BusHandlerFactory uniqueInstance;
        return uniqueInstance;
      }

      I2CHandler *createI2CHandler(uint8_t busId);

      // SPIHandler *createSPIHandler(char *busName);

      // SerialPortHandler *createSerialPortHandler(char* busname);

  };
}

#endif // BUS_HANDLER_FACTORY_H
