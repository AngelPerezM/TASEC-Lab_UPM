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

      GroveAdcHat &adc = GroveAdcHat::getInstance();
      int m_thermistorChannel;
      int m_vccChannel;

      const float R0 = 1000.0; // 100 OHM at 0ºC
      const float R_BIAS = 953.0; // OHM

      const float a = 3.9083E-03;
      const float b = -5.775E-07;
      const float c = -4.183E-12;

      const float ADC_FSB = 3.3/4096.0;
      float m_Vcc = 5.1;
      bool m_vccCorrection = false;

      // Voltage from ADC channel connected to thermistor:
      float thermistorADCVolts;
      float thermistorADCVolts_old;

      // Voltage from ADC channel connected to Vcc.
      float vccADCVolts;
      float vccADCVolts_old;

      bool isTheFirstSample = true; // set to false after reading 1st sample.
      
      float getThermistorOHM(void);

    public:
      // CONSTRUCTOR
      PT1000(int channel);

      // DESTRUCTOR
      ~PT1000() {};

      // MANIPULATORS
      void setThermistorChannel(const int channel);

      void setVoltageSource(const float Vcc);

      void activateVccCorrection(const int channel);

      void deactivateVccCorrection(const float vcc);

      // ACCESORS
      float getTempCelsius();
  };
}

#endif // PT1000_H
