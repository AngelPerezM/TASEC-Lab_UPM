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
#include"Utils/Debug.h"

/* Function definitions
 *******************************************************************************/

namespace equipementHandlers {
  PT1000::PT1000(int channel) : m_thermistorChannel(channel) {
    ;
  }

  float PT1000::getTempCelsius() {
    float temp;

    vccADCVolts = adc.get_nchan_vol_milli_data(m_vccChannel);
    thermistorADCVolts = adc.get_nchan_vol_milli_data(m_thermistorChannel);
    vccADCVolts /= 500.0;  // x2/1000 because of voltage divider
    thermistorADCVolts /= 1000.0;

    // IIR filter.
    if(!isTheFirstSample) {
      thermistorADCVolts = thermistorADCVolts*0.1 + thermistorADCVolts_old*0.9;
      thermistorADCVolts_old = thermistorADCVolts;

      vccADCVolts = vccADCVolts*0.1 + vccADCVolts_old*0.9;
      vccADCVolts_old = vccADCVolts;

      isTheFirstSample = false;
    }

    if (m_vccCorrection) {
      m_Vcc = vccADCVolts;
    }

    float rt = getThermistorOHM();
    PRINT_DEBUG("Resistance of thermistor = %f\n",rt);
    PRINT_DEBUG("V in ADC = %f\n", thermistorADCVolts);
    PRINT_DEBUG("V in Vcc = %f\n", m_Vcc);

    temp = (-a + sqrt( a*a - 4.0*b*(1.0-rt/R0) )) / (2.0*b);

    return temp;
  }

  /**
   * @return Returns the resistance value of the thermistor given the voltage.
   *
   * Vcc----BIAS---|------termistor-----GND
   *               |   resistance value
   *             volts
   */
  float PT1000::getThermistorOHM(void) {
    return ((thermistorADCVolts*R_BIAS) / (m_Vcc-thermistorADCVolts));
  }

  void PT1000::setThermistorChannel(const int channel) {
    if (channel < 8 && channel >= 0) {
      m_thermistorChannel = channel;
    } else {
      // TODO: file logger error.
    }
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

}
