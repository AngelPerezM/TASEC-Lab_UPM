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
  PT1000::PT1000(int channel) : m_channel(channel) {
    ;
  }

  float PT1000::getTempCelsius() {
    float temp = 0.0;

    float v_out = float(adc.get_nchan_vol_milli_data(m_channel)) / 1000.0;
    // float v_out = float (adc.get_nchan_raw_data(m_channel)*ADC_FSB);

    float rt = getThermistorOHM(v_out);
    PRINT_DEBUG("Resistance of thermistor = %f\n",rt);
    PRINT_DEBUG("V in ADC = %f\n", v_out);
    
    if (rt >= R0) { // The current temperature has to be greater than 0.
      temp = (-a + sqrt( pow(a,2) - 4.0*b*(1.0-rt/R0) )) / (2.0*b);
      PRINT_DEBUG("POSITIVA (RT = %f)\n", rt);
    } else {        // The current temperature has to be lower than 0.
      // TODO la cuártica.
      PRINT_DEBUG("NEGATIVA (RT = %f)\n", rt);
    }

    return temp;
  }

  /**
   * @return Returns the resistance value of the thermistor given the voltage.
   *
   * Vcc----BIAS---|------termistor-----GND
   *               |   resistance value
   *             volts
   */
  float PT1000::getThermistorOHM(float volts) {
    return ((volts*R_BIAS) / (m_Vcc-volts));
  }

  void PT1000::setChannel(const int channel) {
    if (channel < 8 && channel >= 0) {
      m_channel = channel;
    } else {
      // TODO: file logger error.
    }
  }

  void PT1000::setVoltageSource(const float Vcc) {
    m_Vcc = Vcc;
  }

}
