/*******************************************************************************
 * ./Anemometer.h
 *
 * 09/mar/2021 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include "Anemometer.h"

#include <pigpio.h>   // We are NOT using the pigpiod daemon.
#include "Utils/Debug.h"
#include "Utils/FileLoggerFactory.h"
#include <math.h>     // sqrt
#include <string>     // to_string()
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
    if (gpioInitialise() < 0) {
      fileLogger->LOG(Emergency, "Could not initilize GPIO.");
      return;
    }

    if(gpioSetMode(m_gpioPin, PI_INPUT) != 0) {
      fileLogger->LOG(Emergency, "Could not set GPIO "+std::to_string(m_gpioPin)+
                                 " as input.");
      return;
    }

    if(gpioSetPullUpDown(m_gpioPin, PI_PUD_DOWN) < 0) {
      fileLogger->LOG(Emergency, "Could not set GPIO "+std::to_string(m_gpioPin)+
                                 " pull down resistor.");
      return;
    }
  }
  
  Anemometer::~Anemometer() {
    PRINT_DEBUG("begin\n");
    stopCounting();
    gpioTerminate();
  }

  void Anemometer::callbackFunction(int gpio, int level, unsigned int /*tick*/, 
                                    void *userData) {
    Anemometer *me = (Anemometer *) userData;
    if( gpio == me->m_gpioPin && level == 1/*rising edge*/ ) {
      me->m_counter++;
      // std::cout << "<<< Counter = " << me->getCounter() << std::endl;
    }
  }

  int Anemometer::startCounting(void) {
    // -1 --> cancel the timeout.
    int rc = gpioSetISRFuncEx(m_gpioPin, RISING_EDGE, -1, callbackFunction, this);
    if ( rc != 0 ) {
      fileLogger->LOG(Emergency, "Could not asociate GPIO "+std::to_string(m_gpioPin)+
                                 " rising edge ISR.");
    }

    return rc;
  }

  int Anemometer::stopCounting(void) {
    int rc = gpioSetISRFunc(m_gpioPin, RISING_EDGE, -1, NULL);
    if (rc != 0) {
      fileLogger->LOG(Error, "Could not cancel callback.");
    }

    return rc;
  }

  int Anemometer::getCounter() const {
    return m_counter.load();
  }

  void Anemometer::setCounter(const int counter) {
    m_counter.store(counter);
  }
}
