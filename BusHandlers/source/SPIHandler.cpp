/**
 * SPI devices have a limited userspace API, supporting basic half-duplex
 * read() and write() access to SPI slave devices.  Using ioctl() requests,
 * full duplex transfers and device I/O configuration are also available
 *
 * IMPORTANT:
 * =========
 * All SPI transfers start with the relevant chipselect active.  Normally
 * it stays selected until after the last transfer in a message.  Drivers
 * can affect the chipselect signal using cs_change.
 *
 * (i) If the transfer isn't the last one in the message, this flag is
 * used to make the chipselect briefly go inactive in the middle of the
 * message.  Toggling chipselect in this way may be needed to terminate
 * a chip command, letting a single spi_message perform all of group of
 * chip transactions together.
 *
 * (ii) When the transfer is the last one in the message, the chip may
 * stay selected until the next transfer.  On multi-device SPI busses
 * with nothing blocking messages going to other devices, this is just
 * a performance hint; starting a message to another device deselects
 * this one.  But in other cases, this can be used to ensure correctness.
 * Some devices need protocol transactions to be built from a series of
 * spi_message submissions, where the content of one message is determined
 * by the results of previous messages and where the whole transaction
 * ends when the chipselect goes inactive.
 */

#include "SPIHandler.h"

#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <cstring>

#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/types.h>

namespace busHandlers {

  SPIHandler::SPIHandler(uint8_t busId, uint8_t cs, uint32_t speed, 
                         uint8_t bitsPerWord, uint8_t mode) :
    m_deviceFd(-1), m_speed(speed)
  {
    sprintf(m_deviceName, "/dev/spidev%d.%d", busId, cs);
    std::cout << "SPIHandler: Openning " << m_deviceName << std::endl;
    m_deviceFd = ::open(m_deviceName, O_RDWR);
    if (m_deviceFd < 0) {
      perror("Unable to open SPI driver.");
    }

    setMode(mode);
    setBitsPerWord(bitsPerWord);
  }

  SPIHandler::~SPIHandler() {
    ::close(m_deviceFd);
  }

  int SPIHandler::setMode(uint8_t mode) {
    int rc = ioctl(m_deviceFd, SPI_IOC_WR_MODE, &mode);
    if (rc < 0) {
      perror("setMode: Can not set SPI mode.");
    } else {
      m_mode = mode;
    }

    return rc;
  }

  int SPIHandler::setBitsPerWord(uint8_t bitsPerWord) {
    int rc = ioctl(m_deviceFd, SPI_IOC_WR_BITS_PER_WORD, &bitsPerWord);
    if (rc < 0) {
      perror("setBitsPerWord: Can not set bits per word");
    } else {
      m_bitsPerWord = bitsPerWord;
    }

    return rc;
  }

  int SPIHandler::getMode(uint8_t &mode) {
    int rc = -1;
    if (isOpenned()) {
      mode = m_mode;
      rc = 0;
    }

    return rc;
  }

  int SPIHandler::read(uint8_t *rxBuffer, uint32_t nBytes, uint16_t delay_usecs)
  {
    return transfer(0, rxBuffer, nBytes, delay_usecs);
  }

  int SPIHandler::readRegister(uint8_t reg, uint8_t *rxBuffer, uint32_t nBytes,
                               uint16_t delay_usecs)
  {
    int rc = registerOperation(reg, rxBuffer, nBytes, delay_usecs, READ);
    if (rc < 1) {
      perror("readRegister: Can not send spi message");
    }

    return rc;
  }

  int SPIHandler::write(const uint8_t *txBuffer, uint32_t nBytes,
                        uint16_t delay_usecs)
  {
    return transfer(txBuffer, 0, nBytes, delay_usecs);
  }

  int SPIHandler::writeRegister(uint8_t reg, const uint8_t *txBuffer,
                                uint32_t nBytes, uint16_t delay_usecs)
  {
    int rc = registerOperation(reg, (uint8_t *)(txBuffer), nBytes, delay_usecs, WRITE);
    if (rc < 1) {
      perror("readRegister: Can not send spi message");
    }
    return rc;
  }

  int SPIHandler::registerOperation(uint8_t reg, uint8_t *buf, uint32_t nBytes,
                                    uint16_t delay_usecs, bool read) {
    struct spi_ioc_transfer trs[2]; //transfers
    memset(&trs, 0, sizeof(trs));

    trs[0].tx_buf = __u64 (&reg);
    trs[0].tx_nbits = 8;
    trs[0].rx_buf = 0;  // Zero bytes received
    trs[0].rx_nbits = 0;
    trs[0].len = sizeof(reg);
    trs[0].speed_hz = m_speed;
    trs[0].delay_usecs = delay_usecs; // delay at the end of the first msg.
    trs[0].bits_per_word = m_bitsPerWord;
    trs[0].cs_change = 0; // see IMPORTANT case (i).

    if (read) {   // READ from register:
      trs[1].tx_buf = 0;  // Zero bytes transmitted
      trs[1].tx_nbits = 0;
      trs[1].rx_buf = __u64 (buf);
      trs[1].rx_nbits = nBytes*8;
    } else {    // WRITE to register:
      trs[1].tx_buf = __u64 (buf);
      trs[1].tx_nbits = nBytes*8;
      trs[1].rx_buf = 0;  // zero bytes received
      trs[1].rx_nbits = 0;
    }
    trs[1].len = nBytes;
    trs[1].speed_hz = m_speed;
    trs[1].delay_usecs = delay_usecs;
    trs[1].bits_per_word = m_bitsPerWord;
    trs[1].cs_change = 0; // see IMPORTANT case (ii).

    return ioctl(m_deviceFd, SPI_IOC_MESSAGE(2), &trs);
  }

  bool SPIHandler::isOpenned() {
    return (m_deviceFd >= 0);
  }

  int SPIHandler::transfer(const uint8_t *txBuffer, uint8_t *rxBuffer, uint32_t nBytes,
                           uint16_t delay_usecs)
  {
    struct spi_ioc_transfer tr;
    memset(&tr, 0, sizeof(tr));

    tr.tx_buf = (unsigned long) (txBuffer);
    tr.rx_buf = (unsigned long) (rxBuffer);
    tr.len = nBytes;
    tr.speed_hz = m_speed;
    tr.delay_usecs = delay_usecs;
    tr.bits_per_word = m_bitsPerWord;
    tr.cs_change = 0;

    int rc = ioctl(m_deviceFd, SPI_IOC_MESSAGE(1), &tr);
    if (rc < 1) {
      perror("transfer: Can not send spi message");
      printf("errno: %d\n", errno);
    }

    return rc;
  }

}
