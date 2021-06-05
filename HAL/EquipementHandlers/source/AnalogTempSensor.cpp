/*******************************************************************************
 * source/equipementHandlers/AnalogTempSensor.cpp
 * Author: Ángel Pérez
 *
 * 23/9/2020 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include "AnalogTempSensor.h"

/* Defines section
 *******************************************************************************/
#include<math.h>
#include<iostream>

/* Function definitions
 *******************************************************************************/

namespace equipementHandlers {
  AnalogTempSensor::AnalogTempSensor(int channel) : m_channel(channel) {
  }

  float AnalogTempSensor::getTempKelvin() {
    uint16_t ratio_data;
    adc.get_nchan_ratio_0_1_data(m_channel, ratio_data);
    float a = 1000.0/float(ratio_data);
    float ntc = (a-1.0)*R0;

   //  std::cout << "analogRead: " << a << ". ntc: "<< ntc << std::endl;

    float tempK = 1.0/( (::log(ntc/R0)/B) + (1/T0) );
    return tempK;
  }

  float AnalogTempSensor::getTempCelsius() {
    return getTempKelvin() - 273.15;
  }
}
