#ifndef SPI_HANDLER_H
#define SPI_HANDLER_H

#include <stdint.h>
#include <linux/spi/spidev.h> // mode default arg

#include "Utils/B2SException.h"
using namespace utils;

#define SPI_PATH_LEN 21

namespace busHandlers {

  class SPIException : public B2SException {
    public:
      SPIException(const std::string &errorMsg, int errorCode, 
                   const char *func = __FUNCTION__ , const char *file = __FILE__,
                   int line = __LINE__):
        B2SException(errorMsg, errorCode, func, file, line)
      {
        ;
      }
      SPIException(const std::string &errorMsg, const char *func = __FUNCTION__,
                   const char *file = __FILE__, int line = __LINE__):
        B2SException(errorMsg, func, file, line)
      {
        ;
      }

  };

  class SPIHandler {
    private:
      int m_deviceFd;
      uint8_t m_mode;
      uint32_t m_speed; // clock in Hz
      uint8_t m_bitsPerWord;
      char m_deviceName[SPI_PATH_LEN];

    public:
      // CONSTRUCTORS
      /**
       * Default mode: CPOL = 0, CPHA = 0
       */
      SPIHandler(uint8_t busId, uint8_t cs, uint32_t speed,
                 uint8_t bitsPerWord = 8, uint8_t mode = SPI_MODE_0);

      // DESCTRUCTOR
      ~SPIHandler();

      // ACCESSORS
      bool isOpenned();
      /**
       * @return Number of bytes read. Otherwise, -1 is returned.
       */
      int read(uint8_t *rxBuffer, uint32_t nBytes, uint16_t delay_usecs = 0);
      int readRegister(uint8_t reg, uint8_t *rxBuffer, uint32_t nBytes,
                       uint16_t delay_usecs = 0);
      int getMode(uint8_t &mode);

      // MANIPULATORS

      /**
       * @return Number of bytes written. Otherwise, -1 is returned.
       */
      int write(const uint8_t *txBuffer, uint32_t nBytes,
                uint16_t delay_usecs = 0);
      int writeRegister(uint8_t reg, const uint8_t *txBuffer, uint32_t nBytes,
                        uint16_t delay_usecs = 0);
      int setMode(uint8_t mode);
      int setBitsPerWord(uint8_t bitsPerWord);

      /**
       * This function does an SPI data transmision.
       * Chip Select (CS) is not selected after the transfer.
       */
      int transfer(const uint8_t *txBuffer, uint8_t *rxBuffer, uint32_t nBytes,
                   uint16_t delay_usecs = 0);
 };
}

#endif // SPI_HANDLER_H
