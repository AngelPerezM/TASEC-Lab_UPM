#include "I2CHandler.h"

#include <stdio.h>
#include <string.h> // memcpy
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>

namespace busHandlers {

  I2CHandler::I2CHandler(uint8_t busId) {
    setMasterBusId(busId);
    open();
  }

  I2CHandler::~I2CHandler() {
    ::close(m_deviceFd);
  }

  void I2CHandler::setMasterBusId(uint8_t busId) {
    sprintf(m_deviceName, "/dev/i2c-%d", busId);
  }

  bool I2CHandler::open() {
    std::cout << "open begin.\n";
    close();
    m_deviceFd = ::open(m_deviceName, O_RDWR);
    return isOpenned();
  }

  void I2CHandler::close() {
    ::close(m_deviceFd);
    m_deviceFd = -1;
  }

  /**
   * LSB from rxBuffer is written first.
   */
  int I2CHandler::read(uint8_t *rxBuffer, int nBytes) {
    int charsRead = 0;
    if(isOpenned()) {
      charsRead = ::read(m_deviceFd, rxBuffer, nBytes);
    }
    return charsRead;
  }

  /**
   * Sends nBytes from txBuffer. LSB from txBuffer is send first.
   */
  int I2CHandler::write(uint8_t *txBuffer, int nBytes) {
    int writtenChars = 0;
    if(isOpenned()) {
      writtenChars = ::write(m_deviceFd, txBuffer, nBytes);
    }
    return writtenChars;
  }

  /**
   * From https://www.kernel.org/doc/Documentation/i2c/dev-interface.rst
   *
   * Note that only a subset of the I2C and SMBus protocols can be achieved by
   * the means of read() and write() calls. In particular, so-called combined
   * transactions (mixing read and write messages in the same transaction)
   * aren't supported.
   */
  int I2CHandler::readRegister(uint8_t reg, uint8_t *rxBuffer, int nBytes) {
    struct i2c_msg msgs[2];
    struct i2c_rdwr_ioctl_data msgset;

    msgs[0].addr = m_slaveAddress;
    msgs[0].flags = 0;
    msgs[0].len = 1;
    msgs[0].buf = &reg;

    msgs[1].addr = m_slaveAddress;
    msgs[1].flags = I2C_M_RD /*| I2C_M_NOSTART*/;
    msgs[1].len = nBytes;
    msgs[1].buf = rxBuffer;

    msgset.msgs = msgs;
    msgset.nmsgs = 2;

    int rc = ioctl(m_deviceFd, I2C_RDWR, &msgset);
    if( rc < 0 ) {
      perror("readDataTransaction");
      return -1;
     }

    return rc; // number of messages completed.
  }

  int I2CHandler::readRegister(int slaveAddress, uint8_t reg, uint8_t *rxBuffer,
                               int nBytes)
  {
    m_slaveAddress = slaveAddress;
    return (readRegister(reg, rxBuffer, nBytes));
  }

  int I2CHandler::writeRegister(uint8_t reg, uint8_t *txBuffer, int nBytes) {
    //         +---LSB---+----MSB---+
    // outbuf: | address | txBuffer |
    //         +---dir---+---dir+1--+
    int outbufSize = 1 + nBytes;
    uint8_t outbuf [outbufSize];
    outbuf[0] = reg;
    memcpy(outbuf + 1, txBuffer, nBytes);

    struct i2c_msg msg;
    struct i2c_rdwr_ioctl_data msgset;

    msg.addr = m_slaveAddress;
    msg.flags = 0;
    msg.len = outbufSize;
    msg.buf = outbuf;

    msgset.msgs = &msg;
    msgset.nmsgs = 1;

    int rc = ioctl(m_deviceFd, I2C_RDWR, &msgset);
    if ( rc < 0 ) {
      perror("writeDataTransaction: Unable to send data");
    }

    return rc; // number of messages completed.
  }

  int I2CHandler::writeRegister(int slaveAddress, uint8_t reg, uint8_t *txBuffer,
                                int nBytes)
  {
    m_slaveAddress = slaveAddress;
    return (writeRegister(reg, txBuffer, nBytes));
  }

  int I2CHandler::enable10BitAddressing() {
    int ret = -1;
    ret = ioctl(m_deviceFd, I2C_TENBIT, 1);
    return ret;
  }

  int I2CHandler::disable10BitAddressing() {
    int ret = -1;
    ret = ioctl(m_deviceFd, I2C_TENBIT, 0);
    return ret;
  }

  int I2CHandler::setSlaveAddress(int address) {
    int ret;
    m_slaveAddress = address;
    ret = ioctl(m_deviceFd, I2C_SLAVE, address);
    return ret;
  }

  bool I2CHandler::isOpenned() {
    return (m_deviceFd >= 0);
  }

}
