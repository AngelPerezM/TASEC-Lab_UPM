#ifndef PT1000_H
#define PT1000_H

/*******************************************************************************
 * include/equipementHandlers/AnalogTempSensor.h
 * Author: Ángel Pérez
 *
 * 23/9/2020 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include "GroveAdcHat.h"

/* Defines section
 *******************************************************************************/
namespace equipementHandlers {
  class PT1000 {
    private:
      int m_channel;

      const float R0 = 1000.0; // 100 OHM at 0ºC
      const float R_BIAS = 953.0; // OHM

      const float a = 3.9083E-03;
      const float b = -5.775E-07;
      const float c = -4.183E-12;

      const float ADC_FSB = 3.3/4096.0;
      float m_Vcc = 5.0;

      GroveAdcHat &adc = GroveAdcHat::getInstance();
      
      float getThermistorOHM(float volts);
    public:
      // CONSTRUCTOR
      PT1000(int channel);

      // DESTRUCTOR
      ~PT1000() {};

      // MANIPULATORS
      void setChannel(const int channel);

      void setVoltageSource(const float Vcc);

      // ACCESORS
      float getTempCelsius();
  };
}

#endif // PT1000_H
