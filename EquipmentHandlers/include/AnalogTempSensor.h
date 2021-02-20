#ifndef ANALOGTEMPSENSOR_H
#define ANALOGTEMPSENSOR_H

/*******************************************************************************
 * include/equipmentHandlers/AnalogTempSensor.h
 * Author: Ángel Pérez
 *
 * 23/9/2020 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include "GroveAdcHat.h"

/* Defines section
 *******************************************************************************/
namespace equipmentHandlers {
  class AnalogTempSensor {
    private:
      int m_channel;

      const int R0 = 100000; // 100K OHM at 25ºC
      const float T0 = 298.15; // 25ºC <> 298,15K
      const int B = 4275; // mean of [4250, 4299]

      GroveAdcHat &adc = GroveAdcHat::getInstance();

    public:
      // CONSTRUCTOR
      AnalogTempSensor(int channel);

      // DESTRUCTOR
      ~AnalogTempSensor() {};

      // MANIPULATORS

      // ACCESORS
      float getTempCelsius();

      float getTempKelvin();

  };
}

#endif // ANALOGTEMPSENSOR_H
