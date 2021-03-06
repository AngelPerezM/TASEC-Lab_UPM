#include "I2CHandler.h"
#include "Utils/Debug.h"

#include <stdio.h>
#include <string.h> // memcpy
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#include <errno.h>

namespace busHandlers {

  I2CHandler::I2CHandler(uint8_t busId) :
    m_deviceFd(-1),
    m_deviceName(std::string("/dev/i2c-")+std::to_string(busId))
  {
    m_deviceFd = ::open(m_deviceName.c_str(), O_RDWR);
    if (m_deviceFd < 0) {
      m_deviceFd = -1;
      std::string errMsg (std::string("Could not open I2C driver ") +
                          m_deviceName);
      throw I2CException(errMsg, __FUNCTION__, __FILE__, __LINE__);
    }
  }

  I2CHandler::~I2CHandler() {
    ::close(m_deviceFd);
  }

  /**
   * LSB from rxBuffer is written first.
   */
  int I2CHandler::read(int slaveAddress, uint8_t *rxBuffer, int nBytes) {
    if (m_deviceFd < 0) {
      std::string errMsg (m_deviceName +
                          std::string(" could not be openned."));
      throw I2CException(errMsg, __FUNCTION__, __FILE__, __LINE__);
    }

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
      std::string errMsg (std::string("Could not read from ") + 
                          m_deviceName);
      throw I2CException(errMsg, errno, __FUNCTION__, __FILE__, __LINE__);
    }

    return rc; // number of messages completed.   return charsRead;
  }

  /**
   * Sends nBytes from txBuffer. LSB from txBuffer is send first.
   */
  int I2CHandler::write(int slaveAddress, uint8_t *txBuffer, int nBytes) {
    if (m_deviceFd < 0) {
      std::string errMsg (m_deviceName +
                          std::string(" could not be openned."));
      throw I2CException(errMsg, __FUNCTION__, __FILE__, __LINE__);
    }

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
      std::string errMsg (std::string("Could not write to ") +
                          m_deviceName);
      throw I2CException(errMsg, errno, __FUNCTION__, __FILE__, __LINE__);
    }

    return rc; // number of messages completed.
  }

  //
  // From https://www.kernel.org/doc/Documentation/i2c/dev-interface.rst
  //
  // Note that only a subset of the I2C and SMBus protocols can be achieved by
  // the means of read() and write() calls. In particular, so-called combined
  // transactions (mixing read and write messages in the same transaction)
  // aren't supported.
  int I2CHandler::readRegister(int slaveAddress, uint8_t reg, uint8_t *rxBuffer,
                               int nBytes)
  {
    if (m_deviceFd < 0) {
      std::string errMsg (m_deviceName +
                          std::string(" could not be openned."));
      throw I2CException(errMsg, __FUNCTION__, __FILE__, __LINE__);
    }
    
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
      std::string errMsg (std::string("Could not read register ") +
                          std::to_string(reg) + std::string(" from ") +
                          m_deviceName);
      throw I2CException(errMsg, errno, __FUNCTION__, __FILE__, __LINE__);
     }

    return rc; // number of messages completed.
  }

  int I2CHandler::writeRegister(int slaveAddress, uint8_t reg, uint8_t *txBuffer,
                                int nBytes)
  {
    if (m_deviceFd < 0) {
      std::string errMsg (m_deviceName +
                          std::string(" could not be openned."));
      throw I2CException(errMsg, __FUNCTION__, __FILE__, __LINE__);
    }
  
    //      +---LSB---+----MSB---+
    // buf: | address | txBuffer |
    //      +---dir---+---dir+1--+
    int ret = -1;
    int bufSize = 1 + nBytes;
    uint8_t buf [bufSize];
    buf[0] = reg;
    memcpy(buf + 1, txBuffer, nBytes);

    try {
        ret = write(slaveAddress, buf, bufSize); // n?? of messages compleated.
    } catch (I2CException &e) {
        throw I2CException(std::string(e.what())+"Could not write to register "+
                           std::to_string(reg) + " from device " +
                           m_deviceName, __FUNCTION__, __FILE__,
                           __LINE__);
    }

    return ret;

  }

  int I2CHandler::enable10BitAddressing() {
    if (m_deviceFd < 0) {
      std::string errMsg (m_deviceName +
                          std::string(" could not be openned."));
      throw I2CException(errMsg, __FUNCTION__, __FILE__, __LINE__);
    }

    int ret = -1;
    ret = ioctl(m_deviceFd, I2C_TENBIT, 1);
    if (ret < 0) {
        throw I2CException("Could not enable 10 bit addressing from device " +
                           m_deviceName, __FUNCTION__, __FILE__,
                           __LINE__);
    }

    return ret;
  }

  int I2CHandler::disable10BitAddressing() {
    if (m_deviceFd < 0) {
      std::string errMsg (m_deviceName +
                          std::string(" could not be openned."));
      throw I2CException(errMsg, __FUNCTION__, __FILE__, __LINE__);
    }

    int ret = -1;
    ret = ioctl(m_deviceFd, I2C_TENBIT, 0);
    if (ret < 0) {
        throw I2CException("Could not enable 10 bit addressing from device " +
                           m_deviceName, __FUNCTION__, __FILE__,
                           __LINE__);        
    }

    return ret;
  }

  bool I2CHandler::isOpenned() {
    return (m_deviceFd >= 0);
  }

}
