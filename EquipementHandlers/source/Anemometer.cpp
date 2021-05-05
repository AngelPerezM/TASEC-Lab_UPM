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
#include <iostream>

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
    stopCounting();
    pigpio_stop(m_gpioHandler);
  }

  void Anemometer::callbackFunction(int pi, unsigned int gpio, unsigned int edge,
                                    unsigned int /*tick*/, void *userData) {
    Anemometer *me = (Anemometer *) userData;
    if( pi == me->m_gpioHandler && gpio == me->m_gpioPin && edge == 1 ) {
      me->m_counter++;
      std::cout << "Counter = " << me->getCounter() << " <<<" << std::endl;
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
    if (m_callbackID == pigif_bad_malloc || 
        m_callbackID == pigif_bad_callback || 
        m_callbackID == pigif_duplicate_callback) 
    {
      fileLogger->LOG(Emergency, "Could not asociate GPIO "+std::to_string(m_gpioPin)+
                                 " rising edge event.");
      return -1;
    } 

    int rc = set_glitch_filter(m_gpioHandler, m_gpioPin, 1); // 25 microsecs.
    if (rc != 0) {
      // Do not worry if could no set filter.
      fileLogger->LOG(Error, "Could not set GPIO "+std::to_string(m_gpioPin)+
                           " glitch filter of 25 usecs.");
      return rc;
    }
    
    return 0;
  }

  int Anemometer::stopCounting(void) {
    int rc =  callback_cancel(m_callbackID);
    if (rc != 0) {
      fileLogger->LOG(Error, "Could not cancel callback.");
    }

    return rc;
  }

}
