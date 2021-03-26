#ifndef I2C_HANDLER_H
#define I2C_HANDLER_H

#include <stdint.h>

#define I2C_PATH_LEN 20

namespace busHandlers {
  class I2CHandler {
    private:
      int m_deviceFd = -1;
      char m_deviceName[I2C_PATH_LEN];

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
