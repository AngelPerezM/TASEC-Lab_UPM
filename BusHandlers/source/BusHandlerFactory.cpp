#include "BusHandlerFactory.h"
#include <iostream>

namespace busHandlers {

  BusHandlerFactory::BusHandlerFactory() {
    std::cout << "BusHandlerFactory: empty constructor" << std::endl;
  }

  BusHandlerFactory::~BusHandlerFactory() {
    while(!i2cHandlers.empty())
    {
      std::unordered_map<uint8_t, I2CHandler*>::iterator 
        it = i2cHandlers.begin();
      delete it->second;
      i2cHandlers.erase(it);
    }
    std::cout << "BusHandlerFactory destructor end." << std::endl;
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
