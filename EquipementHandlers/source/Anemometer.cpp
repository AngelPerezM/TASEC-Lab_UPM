/*******************************************************************************
 * ./Anemometer.h
 *
 * 09/mar/2021 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include "Anemometer.h"

#include <pigpiod_if2.h>
#include "Utils/Debug.h"
#include "Utils/FileLoggerFactory.h"
#include <math.h> // sqrt
#include <string> // to_string()

/* Function definitions
 *******************************************************************************/

namespace equipementHandlers {

  Anemometer::Anemometer(const unsigned int gpioPin, const char *fileName) :     
    m_gpioPin(gpioPin)
  {
    setCounter(0);
    fileLogger = FileLoggerFactory::getInstance().createFileLogger(fileName);
    configGPIOPin();
  }

  void Anemometer::configGPIOPin(void) {
    m_gpioHandler = pigpio_start(NULL, NULL);
    if (m_gpioHandler < 0) {
      fileLogger->LOG(Emergency, "Could not initilize GPIO.");
      return;
    }

    if(set_mode(m_gpioHandler, m_gpioPin, PI_INPUT) < 0) {
      fileLogger->LOG(Emergency, "Could not set GPIO "+std::to_string(m_gpioPin)+
                                 " as input.");
      return;
    }

    if(set_pull_up_down(m_gpioHandler, m_gpioPin, PI_PUD_DOWN) < 0) {
      fileLogger->LOG(Emergency, "Could not set GPIO "+std::to_string(m_gpioPin)+
                                 " pull down resistor.");
      return;
    }
  }
  
  Anemometer::~Anemometer() {
    PRINT_DEBUG("begin\n");
    pigpio_stop(m_gpioHandler);
  }

  void Anemometer::callbackFunction(int pi, unsigned int gpio, unsigned int edge,
                                    unsigned int /*tick*/, void *userData) {
    Anemometer *me = (Anemometer *) userData;
    if( pi == me->m_gpioHandler && gpio == me->m_gpioPin && edge == 1 ) {
      me->m_counter++;
    }
  }

  int Anemometer::getCounter() const {
    return m_counter.load();
  }

  void Anemometer::setCounter(const int counter) {
    m_counter.store(counter);
  }

  int Anemometer::startCounting(void) {
    m_callbackID = callback_ex(m_gpioHandler, m_gpioPin, RISING_EDGE, callbackFunction, this);
    if (m_callbackID < 0) {
      fileLogger->LOG(Emergency, "Could not asociate GPIO "+std::to_string(m_gpioPin)+
                                 " rising edge event.");
      return -1;
    } 
    
    int rc = set_glitch_filter(m_gpioHandler, m_gpioPin, 25);
    if (rc < 0) {
      // 25 microsecs. Do not worry if could no set.
      fileLogger->LOG(Error, "Could not set GPIO "+std::to_string(m_gpioPin)+
                           " glitch filter of 25 usecs.");
      return rc;
    }

    return 0;
  }

  int Anemometer::stopCounting(void) {
    if(m_callbackID >= 0) {
      callback_cancel(m_callbackID);
      m_callbackID = -1;
      return 0;
    } else {
      return -1;
    }
  }

}
