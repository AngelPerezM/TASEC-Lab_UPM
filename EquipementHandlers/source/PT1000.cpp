/*******************************************************************************
 * source/equipementHandlers/AnalogTempSensor.cpp
 * Author: Ángel Pérez
 *
 * 23/9/2020 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include "PT1000.h"

/* Defines section
 *******************************************************************************/
#include<math.h>
#include<iostream>
#include<chrono>
#include "Utils/FileLoggerFactory.h"
#include "Utils/Debug.h"

/* Function definitions
 *******************************************************************************/

namespace equipementHandlers {
  PT1000::PT1000(int channel, const char* fileLogName) : m_thermistorChannel(channel) {
    fileLogger = FileLoggerFactory::getInstance().createFileLogger(fileLogName);
  }

  int PT1000::getTempCelsius(float &temp) {
    int nSamples = 0;
    
    vccADCVolts = 0;
    thermistorADCVolts = 0;

    // FIR FILTER:
    for ( int i = 0; i < m_nSamplesFilter; ++i) {
      uint16_t read1, read2;
      int rc = adc.get_nchan_vol_milli_data(m_vccChannel, read1);
      if (rc >= 0) {
        rc = adc.get_nchan_vol_milli_data(m_thermistorChannel, read2);
      }
      if (rc >= 0) {
        nSamples++;
        vccADCVolts += (float (read1));
        thermistorADCVolts += (float (read2));
      }
    }
    
    if (nSamples > 0) {
      vccADCVolts = vccADCVolts / (float (m_nSamplesFilter) * 500.0);
      thermistorADCVolts = thermistorADCVolts/ (float (m_nSamplesFilter) * 1000.0);

      if (m_vccCorrection) {
        m_Vcc = vccADCVolts;
      }

      float rt = thermistorVolts2OHM();
      PRINT_DEBUG("Resistance of thermistor = %f\n",rt);
      PRINT_DEBUG("V in ADC = %f\n", thermistorADCVolts);
      PRINT_DEBUG("V in Vcc = %f\n", m_Vcc);

      temp = (-a + sqrt( a*a - 4.0*b*(1.0-rt/R0) )) / (2.0*b);
    }

    return nSamples;
  }

  /**
   * @return Returns the resistance value of the thermistor given the voltage.
   *
   * Vcc----BIAS---|------termistor-----GND
   *               |   resistance value
   *             volts
   */
  float PT1000::thermistorVolts2OHM(void) {
    return ((thermistorADCVolts*R_BIAS) / (m_Vcc-thermistorADCVolts));
  }

  void PT1000::setThermistorChannel(const int channel) {
    if (channel < 8 && channel >= 0) {
      m_thermistorChannel = channel;
    } else {
      fileLogger->LOG(Error, "The requested channel("+std::to_string(channel)+") is not valid.");
    }
  }

  float PT1000::getLastVccReading () {
    return vccADCVolts;
  }

  float PT1000::getLastThermistorReading () {
    return thermistorADCVolts;
  }

  void PT1000::setVoltageSource(const float Vcc) {
    m_Vcc = Vcc;
  }

  void PT1000::activateVccCorrection(const int channel) {
    m_vccCorrection = true;
    m_vccChannel = channel;
  }

  void PT1000::deactivateVccCorrection(const float vcc) {
    m_vccCorrection = false;
    m_Vcc = vcc;
  }

  void PT1000::setFIRNSamples(const int nSamplesFilter) {
    m_nSamplesFilter = nSamplesFilter;
  }

}
