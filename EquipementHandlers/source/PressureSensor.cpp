/*******************************************************************************
 * 23/mar/2021 - Version 1.0
 *
 * IMPORTANT:
 * =========
 * - This is a big endian slave.
 *******************************************************************************/

/* Include section
 *******************************************************************************/

#include "PressureSensor.h"
#include <math.h> // pow
#include <iostream>
#include <unistd.h>

namespace equipementHandlers {
  // CONSTRUCTOR
  PressureSensor::PressureSensor(uint8_t bus_num, uint8_t cs, PressureSensor::OSR osr) :
    spi(bus_num, cs, 10000000), m_osr(osr)
  {
    reset();
    readCalibrationData();
  }

  // DESTRUCTOR
  PressureSensor::~PressureSensor() {

  }

  // MANIPULATORS
  void PressureSensor::reset(void) {
    std::cout << "PressureSensor::reset: begin" << std::endl;
    uint8_t reg = RESET;
    spi.write(&reg, sizeof(reg), 2800);
    usleep(2800); // por si las moscas.
    std::cout << "PressureSensor::reset: end" << std::endl;    
  }

  // ACCESORS
  void PressureSensor::readCalibrationData(void) {
    uint16_t c1, c2, c3, c4, c5, c6;
    c1 = readPROM(SENS_T1);// usleep(3000);
    c2 = readPROM(OFF_T1);// usleep(3000);
    c3 = readPROM(TCS);// usleep(3000);
    c4 = readPROM(TCO);// usleep(3000);
    c5 = readPROM(T_REF);// usleep(3000);
    c6 = readPROM(TEMP_SENS);// usleep(3000);

    sensT1 = float(c1) * pow(2,15);   // c1 * 2^15
    offT1 = float(c2) * pow(2,16);    // c2 * 2^16
    tcs = float(c3) / pow(2,8);       // c3 / 2^8
    tco = float(c4) / pow(2,7);       // c4 / 2^7
    tRef = float(c5) * pow(2,8);      // c5 * 2^8
    tempSens = float(c6) / pow(2,23); // c6 / 2^23

#ifdef DEBUG
    std::cout << "\tTypical C1: 40127, actual: " << c1 << std::endl;
    std::cout << "\tTypical C2: 36924, actual: " << c2 << std::endl;
    std::cout << "\tTypical C3: 23317, actual: " << c3 << std::endl;
    std::cout << "\tTypical C4: 23282, actual: " << c4 << std::endl;
    std::cout << "\tTypical C5: 33464, actual: " << c5 << std::endl;
    std::cout << "\tTypical C6: 28312, actual: " << c6 << std::endl;
    puts("");
    std::cout << "\tTypical sensT1: 1314881536, actual: " << sensT1 << std::endl;
    std::cout << "\tTypical offT1: 2419851264, actual: " << offT1 << std::endl;
    std::cout << "\tTypical tcs: 91.08203125, actual: " << tcs << std::endl;
    std::cout << "\tTypical tco: 181.890625, actual: " << tco << std::endl;
    std::cout << "\tTypical tRef: 8566784, actual: " << tRef << std::endl;
    std::cout << "\tTypical tempSens: 0.0033750534057617188, actual: " << tempSens << std::endl;
#endif    

  }

  uint16_t PressureSensor::getDelay() {
    uint16_t index = (m_osr >> 1);
    if (index > 4) {
      std::cout << "Mal index!!!!" << std::endl;
      index = 0;
    }
    return adcDelays_usecs[index];
  }

  uint32_t PressureSensor::readD1(void) {
    std::cout << "PressureSensor::readD1: begin" << std::endl;

    uint8_t buf [3];
    uint8_t cmd = CONVERT_D1 | m_osr;
    uint32_t d1 = 0;

    spi.write(&cmd, sizeof(cmd), getDelay());
    spi.readRegister((uint8_t) ADC_READ, buf, sizeof(buf), 0);

    d1 = (buf[0] << 16 | buf[1] << 8 | buf [2]);
    std::cout << "\tTypical D1: 9085466, actual: " << d1 << std::endl;

    std::cout << "PressureSensor::readD1 end" << std::endl;
    return (buf[0] << 16 | buf[1] << 8 | buf [2]);
  }

  uint32_t PressureSensor::readD2(void) {
    std::cout << "PressureSensor::readD2: begin" << std::endl;
    uint8_t buf [3];
    uint8_t cmd = CONVERT_D2 | m_osr;
    uint32_t d2 = 0;

    spi.write(&cmd, sizeof(cmd), getDelay());
    spi.readRegister((uint8_t) ADC_READ, buf, sizeof(buf), 0);

    d2 = (buf[0] << 16 | buf[1] << 8 | buf [2]);
    std::cout << "\tTypical D2: 8569150, actual: " << d2 << std::endl;

    std::cout << "PressureSensor::readD2: end" << std::endl;
    return d2;
  }

  uint16_t PressureSensor::readPROM(uint8_t address) {

    std::cout << "PressureSensor::readPROM: begin" << std::endl;
    uint16_t data;
    uint8_t buf [2];

    int bytes = 0;
    bytes = spi.readRegister(address, buf, sizeof(buf), 0);
    std::cout << "\tRead " << bytes-1 << " bytes" << std::endl;
    data = ( (buf[0]) << 8 | buf[1] );

    std::cout << "PressureSensor::readPROM: end" << std::endl;
    return data;
  }

  int32_t PressureSensor::getTemperature(void) {
    int32_t dT = readD2() - tRef;
    int32_t temp = (2000 + dT * tempSens);

    int32_t t2 = 0;
    if (temp < 20) {
      t2 = (dT*dT) / pow(2,31);
    }

    return temp-t2;
  }

  void PressureSensor::getPressureAndTemp(int32_t /*out*/ &pressure, 
                                          int32_t /*out*/ &temp)
  {
    std::cout << "PressureSensor::getPressureAndTemp: begin" << std::endl;
    int32_t dT = readD2() - tRef;
    int64_t off = offT1 + tco*dT;
    int64_t sens = sensT1 + tcs*dT;

    temp = (2000 + dT * tempSens);
    pressure = 0;

    int32_t t2 = 0;
    int64_t off2 = 0;
    int64_t sens2 = 0;

    if(temp < 20) {
      t2 = (dT*dT) / pow(2,31);
      off2 = 5 * pow((temp - 2000), 2.0) / 2;
      sens2 = off2 / 2;
      if (temp < 15) {
        off2 += 7*pow((temp + 1500), 2.0);
        sens2 += 11*pow((temp + 1500), 2.0);
      }
    }

    off -= off2;
    sens -= sens2;

    // Results:
    temp -= t2;
    pressure = ( ((readD1() * sens) / pow(2, 21)) - off ) / pow(2,15);

    std::cout << "\tTypical dT 2366, actual " << dT << std::endl;
    std::cout << "\tTypical TEMP 2007, actual " << temp << std::endl;
    std::cout << "\tTypical OFF 2420281617, actual " << off << std::endl;
    std::cout << "\tTypical SENS 1315097036, actual " << sens << std::endl;
    std::cout << "\tTypical PRESSURE 2420281617, actual " << pressure << std::endl;

    std::cout << "PressureSensor::getPressureAndTemp: end" << std::endl;
  }

};
