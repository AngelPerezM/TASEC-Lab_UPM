#ifndef ANEMOMETER_H
#define ANEMOMETER_H

/*******************************************************************************
 * 04/may/2021 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include <stdint.h>
#include <atomic>
#include "Utils/FileLogger.h"

using namespace utils;

namespace equipementHandlers {
  class Anemometer {
    private:
    FileLogger *fileLogger;

    unsigned int m_gpioPin;
    int m_gpioHandler;
    int m_callbackID;

    std::atomic<int> m_counter;

    void configGPIOPin(void);
    static void callbackFunction(int pi, unsigned int gpio, unsigned int edge,
                                 unsigned int tick, void *userData);
    public:

      // CONSTRUCTOR
      Anemometer(const unsigned int gpioPin = 26,
                 const char *fileName = "/home/pi/log.txt");

      // DESTRUCTOR
      ~Anemometer();

      // ACCESORS
      int getCounter() const;

      // MANIPULATORS
      void setCounter(const int counter);

      int startCounting(void);

      int stopCounting(void);

  };

}
#endif // ANEMOMETER_H
