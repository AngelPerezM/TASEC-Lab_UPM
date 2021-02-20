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
      I2CHandler();
      I2CHandler(uint8_t busId);

      // DESCTRUCTOR
      ~I2CHandler();

      // ACCESSORS
      bool isOpenned();

      int read(char *rxBuffer, int nBytes);
      int readDataTransaction(uint8_t reg, char *rxBuffer, int nBytes);

      // MANIPULATORS
      int write(char *txBuffer, int nBytes);
      int writeDataTransaction(uint8_t reg, char *txBuffer, int nBytes);

      int enable10BitAddressing();
      int disable10BitAddressing();

      int setSlaveAddress(int address);

      bool open();
      void close();

    private:
      void setMasterBusId(uint8_t busId);
  };
}

#endif // I2C_HANDLER_H
