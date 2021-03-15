#ifndef SPI_HANDLER_H
#define SPI_HANDLER_H

#include <stdint.h>

#define I2C_PATH_LEN 20

namespace busHandlers {
  class I2CHandler {
    private:
      int m_deviceFd = -1;
      char m_deviceName[I2C_PATH_LEN];

    public:
      // CONSTRUCTORS
      SPIHandler();
      SPIHandler(uint8_t busId);

      // DESCTRUCTOR
      ~SPIHandler();

      // ACCESSORS
      bool isOpenned();

      int read(char *rxBuffer, int nBytes);
      int readDataTransaction(uint8_t reg, char *rxBuffer, int nBytes);

      // MANIPULATORS
      int write(char *txBuffer, int nBytes);
      int writeDataTransaction(uint8_t reg, char *txBuffer, int nBytes);

      int setSlaveAddress(int address);

    private:
      bool open();
      void close();
      void setMasterBusId(uint8_t busId);
  };
}

#endif // SPI_HANDLER_H
