#include "BusHandlerFactory.h"
#include <iostream>
#include <Utils/Debug.h>

namespace busHandlers {

  BusHandlerFactory::BusHandlerFactory() {
    PRINT_DEBUG("BusHandlerFactory: empty constructor\n");
  }

  BusHandlerFactory::~BusHandlerFactory() {
    while(!i2cHandlers.empty())
    {
      std::unordered_map<uint8_t, I2CHandler*>::iterator it = i2cHandlers.begin();
      delete it->second;
      i2cHandlers.erase(it);
    }

    PRINT_DEBUG("BusHandlerFactory: empty constructor\n");
  }

  I2CHandler *BusHandlerFactory::createI2CHandler(uint8_t busId) {
    if(i2cHandlers.count(busId) == 0) {
      I2CHandler *i2c = new I2CHandler(busId);
      // i2cHandlers[busId] = i2c;
      i2cHandlers.insert(std::make_pair(busId, i2c));
    }
    return i2cHandlers.at(busId);
  }
  /*
     busHandlers::SPIHandler root::busHandlers::BusHandlerFactory::createSPIHandler(char* busName) {
     throw "Not yet implemented";
     }

     busHandlers::SerialPortHandler root::busHandlers::BusHandlerFactory::createSerialPortHandler(char* busName) {
     throw "Not yet implemented";
     }
     */
}
