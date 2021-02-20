#include "I2CHandler.h"

#include <stdio.h>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/i2c-dev.h>

namespace busHandlers {
  I2CHandler::I2CHandler () {
    puts("busHandlers: empty constructor");
  }

  I2CHandler::I2CHandler(uint8_t busId) {
    setMasterBusId(busId);
  }

  I2CHandler::~I2CHandler() {
    ::close(m_deviceFd);
  }

  void I2CHandler::setMasterBusId(uint8_t busId) {
    puts("setMasterBusId begin");
    sprintf(m_deviceName, "/dev/i2c-%d", busId);
    puts("setMasterBusId end");
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

  int I2CHandler::read(char* rxBuffer, int nBytes) {
    int charsRead = 0;
    if(isOpenned()) {
      charsRead = ::read(m_deviceFd, rxBuffer, nBytes);
    }
    return charsRead;
  }    

  int I2CHandler::write(char* txBuffer, int nBytes) {
    int writtenChars = 0;
    if(isOpenned()) {
      writtenChars = ::write(m_deviceFd, txBuffer, nBytes);
    }
    return writtenChars;
  }

  int I2CHandler::readDataTransaction(uint8_t reg, char *rxBuffer, int nBytes) {
    int ret = -1;
    ret = write((char *) &reg, sizeof(reg));
    if(ret >= 0) {
      return read(rxBuffer, nBytes);
    }
    return ret;
  }

  int I2CHandler::writeDataTransaction(uint8_t reg, char *txBuffer, int nBytes) {
    int ret = -1;
    ret = write((char *)&reg, sizeof(reg));
    if(ret >= 0) {
      return write(txBuffer, nBytes);
    }
    return ret;
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
    ret = ioctl(m_deviceFd, I2C_SLAVE, address);
    return ret;
  }

  bool I2CHandler::isOpenned() {
    return (m_deviceFd >= 0);
  }

}
