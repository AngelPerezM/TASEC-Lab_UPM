#ifndef I2C_HANDLER_H
#define I2C_HANDLER_H

#include <stdint.h>
#include "Utils/B2SException.h"

using namespace utils;

namespace busHandlers { 

  class I2CException : public B2SException {
    public:
      I2CException(const std::string &errorMsg, int errorCode, 
                   const char *func, const char *file, int line):
        B2SException(errorMsg, errorCode, func, file, line)
      {
        ;
      }
      I2CException(const std::string &errorMsg, const char *func,
                   const char *file, int line):
        B2SException(errorMsg, func, file, line)
      {
        ;
      }
  };

  class I2CHandler {
    private:
      int m_deviceFd;
      std::string m_deviceName;

    public:
      // CONSTRUCTORS
      I2CHandler(uint8_t busId);

      // DESCTRUCTOR
      ~I2CHandler();

      // ACCESSORS
      bool isOpenned();

      /**
       * LSB from rxBuffer is written first.
       */
      int read(int slaveAddress, uint8_t *rxBuffer, int nBytes);
      int readRegister(int slaveAddress, uint8_t reg, uint8_t *rxBuffer, 
                       int nBytes);

      // MANIPULATORS

      /**
       * Sends nBytes from txBuffer. LSB from txBuffer is send first.
       */
      int write(int slaveAddress, uint8_t *txBuffer, int nBytes);
      int writeRegister(int slaveAddress, uint8_t reg, uint8_t *txBuffer,
                        int nBytes);

      int enable10BitAddressing();
      int disable10BitAddressing();
  };
}

#endif // I2C_HANDLER_H
