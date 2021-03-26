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
    sprintf(m_deviceName, "/dev/i2c-%d", busId);
    m_deviceFd = ::open(m_deviceName, O_RDWR);
  }

  I2CHandler::~I2CHandler() {
    ::close(m_deviceFd);
  }

  /**
   * LSB from rxBuffer is written first.
   */
  int I2CHandler::read(int slaveAddress, uint8_t *rxBuffer, int nBytes) {
    int rc = -1;

    struct i2c_msg msg;
    struct i2c_rdwr_ioctl_data msgset;

    msg.addr = slaveAddress;
    msg.flags = I2C_M_RD /*| I2C_M_NOSTART*/;
    msg.len = nBytes;
    msg.buf = rxBuffer;

    msgset.msgs = &msg;
    msgset.nmsgs = 1;

    rc = ioctl(m_deviceFd, I2C_RDWR, &msgset);
    if( rc < 0 ) {
      perror("readDataTransaction");
    }

    return rc; // number of messages completed.   return charsRead;
  }

  /**
   * Sends nBytes from txBuffer. LSB from txBuffer is send first.
   */
  int I2CHandler::write(int slaveAddress, uint8_t *txBuffer, int nBytes) {
    struct i2c_msg msg;
    struct i2c_rdwr_ioctl_data msgset;

    msg.addr = slaveAddress;
    msg.flags = 0;
    msg.buf = txBuffer;
    msg.len = nBytes;

    msgset.msgs = &msg;
    msgset.nmsgs = 1;

    int rc = ioctl(m_deviceFd, I2C_RDWR, &msgset);
    if ( rc < 0 ) {
      perror("writeDataTransaction: Unable to send data");
    }

    return rc; // number of messages completed.
  }

  /**
   * From https://www.kernel.org/doc/Documentation/i2c/dev-interface.rst
   *
   * Note that only a subset of the I2C and SMBus protocols can be achieved by
   * the means of read() and write() calls. In particular, so-called combined
   * transactions (mixing read and write messages in the same transaction)
   * aren't supported.
   */
  int I2CHandler::readRegister(int slaveAddress, uint8_t reg, uint8_t *rxBuffer,
                               int nBytes)
  {
    struct i2c_msg msgs[2];
    struct i2c_rdwr_ioctl_data msgset;

    msgs[0].addr = slaveAddress;
    msgs[0].flags = 0;
    msgs[0].len = 1;
    msgs[0].buf = &reg;

    msgs[1].addr = slaveAddress;
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

  int I2CHandler::writeRegister(int slaveAddress, uint8_t reg, uint8_t *txBuffer,
                                int nBytes)
  {
    //      +---LSB---+----MSB---+
    // buf: | address | txBuffer |
    //      +---dir---+---dir+1--+
    int bufSize = 1 + nBytes;
    uint8_t buf [bufSize];
    buf[0] = reg;
    memcpy(buf + 1, txBuffer, nBytes);

    return write(slaveAddress, buf, bufSize); // number of messages completed.
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

  bool I2CHandler::isOpenned() {
    return (m_deviceFd >= 0);
  }

}
