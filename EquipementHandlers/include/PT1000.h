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
#include<math.h>
#include<iostream>
#include<chrono>
#include"Utils/Debug.h"


/* Defines section
 *******************************************************************************/
namespace equipementHandlers {
  template <class ADC>
  class PT1000 {
    private:

      // GroveAdcHat &adc = GroveAdcHat::getInstance();
      ADC &adc = ADC::getInstance();
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

      int m_nSamplesFilter = 5;
      // Voltage from ADC channel connected to thermistor:
      float thermistorADCVolts;
      // Voltage from ADC channel connected to Vcc.
      float vccADCVolts;

      bool isTheFirstSample = true; // set to false after reading 1st sample.
      
      float getThermistorOHM(void) {
    	return ((thermistorADCVolts*R_BIAS) / (m_Vcc-thermistorADCVolts));
      }

    public:
      // CONSTRUCTOR
      PT1000(int channel) : m_thermistorChannel(channel) {
      };
      // DESTRUCTOR
      ~PT1000() {};

      // MANIPULATORS
      void setThermistorChannel(const int channel) {
        if (channel < 8 && channel >= 0) {
          m_thermistorChannel = channel;
        } else {
          // TODO: log error.
        
        }
      };

      void setVoltageSource(const float Vcc) {
        m_Vcc = Vcc;
      };

      void activateVccCorrection(const int channel) {
        m_vccCorrection = true;
        m_vccChannel = channel;
      };

      void deactivateVccCorrection(const float vcc) {
        m_vccCorrection = false;
        m_Vcc = vcc;
      };

      void setFIRNSamples(const int nSamplesFilter) {
        m_nSamplesFilter = nSamplesFilter;
      };

      // ACCESORS
      float getTempCelsius() {
	      float temp;

	      vccADCVolts = 0;
	      thermistorADCVolts = 0;

        // FIR FILTER:
        for ( int i = 0; i < m_nSamplesFilter; ++i ) {
          vccADCVolts += adc.get_nchan_vol_milli_data(m_vccChannel);
          thermistorADCVolts += adc.get_nchan_vol_milli_data(m_thermistorChannel);
        }
        vccADCVolts = vccADCVolts / (float (m_nSamplesFilter) * 500.0);
        thermistorADCVolts = thermistorADCVolts/ (float (m_nSamplesFilter) * 1000.0);

        if (m_vccCorrection) {
          m_Vcc = vccADCVolts;
        }

        float rt = getThermistorOHM();
        PRINT_DEBUG("Resistance of thermistor = %f\n",rt);
        PRINT_DEBUG("V in ADC = %f\n", thermistorADCVolts);
        PRINT_DEBUG("V in Vcc = %f\n", m_Vcc);

        temp = (-a + sqrt( a*a - 4.0*b*(1.0-rt/R0) )) / (2.0*b);

        return temp;

      };
  };

}

#endif // PT1000_H
