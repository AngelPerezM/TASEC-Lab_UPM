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
#include "Utils/Debug.h"

#include <math.h> // pow
#include <iostream>
#include <unistd.h>

namespace equipementHandlers {
  // CONSTRUCTOR
  PressureSensor::PressureSensor(uint8_t bus_num, uint8_t cs, 
                                 PressureSensor::OSR osr, const char *fileName):
    spi(bus_num, cs, 10000000), m_osr(osr)
  {

    fileLogger = FileLoggerFactory::getInstance().createFileLogger(fileName);
    reset();
    readCalibrationData();
  }

  // DESTRUCTOR
  PressureSensor::~PressureSensor() {

  }

  // MANIPULATORS
  void PressureSensor::reset(void) {
    PRINT_DEBUG("begin\n");
    try {
      uint8_t reg = RESET;
      spi.write(&reg, sizeof(reg), 2800);
      usleep(2800); // por si las moscas.
    } catch (bhs::SPIException &e) {
      fileLogger->LOG(Emergency, "Could not reset pressure sensor\n"+
                                 std::string(e.what()));
    }
    PRINT_DEBUG("end\n");
  }

  // ACCESORS
  void PressureSensor::readCalibrationData(void) {
    try {
      uint16_t c1, c2, c3, c4, c5, c6;
      c1 = readPROM(SENS_T1);
      c2 = readPROM(OFF_T1);
      c3 = readPROM(TCS);
      c4 = readPROM(TCO);
      c5 = readPROM(T_REF);
      c6 = readPROM(TEMP_SENS);

      sensT1 = float(c1) * pow(2,15);   // c1 * 2^15
      offT1 = float(c2) * pow(2,16);    // c2 * 2^16
      tcs = float(c3) / pow(2,8);       // c3 / 2^8
      tco = float(c4) / pow(2,7);       // c4 / 2^7
      tRef = float(c5) * pow(2,8);      // c5 * 2^8
      tempSens = float(c6) / pow(2,23); // c6 / 2^23

      PRINT_DEBUG("Typical C1: 40127, actual: %d\n", c1);
      PRINT_DEBUG("Typical C2: 36924, actual: %d\n", c2);
      PRINT_DEBUG("Typical C3: 23317, actual: %d\n", c3);
      PRINT_DEBUG("Typical C4: 23282, actual: %d\n", c4);
      PRINT_DEBUG("Typical C5: 33464, actual: %d\n", c5);
      PRINT_DEBUG("Typical C6: 28312, actual: %d\n\n", c6);

      PRINT_DEBUG("Typical sensT1: 1314881536, actual: %f\n", sensT1);
      PRINT_DEBUG("Typical offT1: 2419851264, actual: %f\n", offT1);
      PRINT_DEBUG("Typical tcs: 91.08203125, actual: %f\n", tcs);
      PRINT_DEBUG("Typical tco: 181.890625, actual: %f\n", tco);
      PRINT_DEBUG("Typical tRef: 8566784, actual: %f\n", tRef);
      PRINT_DEBUG("Typical tempSens: 0.0033750534057617188, actual: %f\n", tempSens);
    } catch (bhs::SPIException &e) {
      fileLogger->LOG(Emergency, "Could not read calibration data\n"+
                                 std::string(e.what()));
    }

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
    PRINT_DEBUG("begin\n");

    uint32_t d1 = 0;

    try {
      uint8_t buf [3];
      uint8_t cmd = CONVERT_D1 | m_osr;
      spi.write(&cmd, sizeof(cmd), getDelay());
      spi.readRegister((uint8_t) ADC_READ, buf, sizeof(buf), 0);

      d1 = (buf[0] << 16 | buf[1] << 8 | buf [2]);
      PRINT_DEBUG("Typical D1: 9085466, actual: %d\n", d1);
    } catch (bhs::SPIException &e) {
      fileLogger->LOG(Emergency, "Could not read D1 value\n"+
                                 std::string(e.what()));
    }

    PRINT_DEBUG("end\n");
    return d1;
  }

  uint32_t PressureSensor::readD2(void) {
    PRINT_DEBUG("begin\n");

    uint32_t d2 = 0;

    try {
      uint8_t buf [3];
      uint8_t cmd = CONVERT_D2 | m_osr;

      spi.write(&cmd, sizeof(cmd), getDelay());
      spi.readRegister((uint8_t) ADC_READ, buf, sizeof(buf), 0);

      d2 = (buf[0] << 16 | buf[1] << 8 | buf [2]);
      PRINT_DEBUG("Typical D2: 8569150, actual: %d\n", d2);
    } catch (bhs::SPIException &e) {
      fileLogger->LOG(Emergency, "Could not read D2 value\n"+
                                 std::string(e.what()));
    }

    PRINT_DEBUG("end\n");
    return d2;
  }

  uint16_t PressureSensor::readPROM(uint8_t address) {
    PRINT_DEBUG("begin\n");

    uint16_t data = 0;
    try {
      uint8_t buf [2];
      int bytes = 0;
      bytes = spi.readRegister(address, buf, sizeof(buf), 0);
      std::cout << "\tRead " << bytes-1 << " bytes" << std::endl;
      data = ( (buf[0]) << 8 | buf[1] );
    } catch (bhs::SPIException &e) {
      fileLogger->LOG(Emergency, "Could not read PROM address "+
                                 std::string(e.what()));
    }

    PRINT_DEBUG("end\n");
    return data;
  }

  int32_t PressureSensor::getTemperature(void) {
    PRINT_DEBUG("begin\n");

    int32_t dT = readD2() - tRef;
    int32_t temp = (2000 + dT * tempSens);

    int32_t t2 = 0;
    if (temp < 2000) { // Temp < 20 ºC 
      t2 = (dT*dT) / pow(2,31);
    }

    PRINT_DEBUG("end\n");
    return temp-t2;
  }

  /**
   * @param pressure output parameter, will contain the pressure measured in 
   * 10*microbar.
   * @param temp output parameter, will contain the temperature measured in
   * 100*ºC (centicelsius?).
   */
  void PressureSensor::getPressureAndTemp(int32_t /*out*/ &pressure, 
      int32_t /*out*/ &temp)
  {
    PRINT_DEBUG("begin\n");

    int32_t dT = readD2() - tRef;
    int64_t off = offT1 + tco*dT;
    int64_t sens = sensT1 + tcs*dT;

    temp = (2000 + dT * tempSens);
    pressure = 0;

    int32_t t2 = 0;
    int64_t off2 = 0;
    int64_t sens2 = 0;

    if(temp < 2000) { // Temp < 20 ºC
      t2 = (dT*dT) / pow(2,31);
      off2 = 5 * pow((temp - 2000), 2.0) / 2;
      sens2 = off2 / 2;
      if (temp < 1500) {  // Temp < 15 ºC
        off2 += (7*pow((temp + 1500), 2.0));
        sens2 += (11*pow((temp + 1500), 2.0)/2.0);
      }
    }

    off -= off2;
    sens -= sens2;

    // Results:
    temp -= t2;
    pressure = ( ((readD1() * sens) / pow(2, 21)) - off ) / pow(2,15);

    PRINT_DEBUG("\tTypical dT 2366, actual %d\n", dT);
    PRINT_DEBUG("\tTypical TEMP 2007, actual %d\n", temp);
    PRINT_DEBUG("\tTypical OFF 2420281617, actual %ld\n", (long) off);
    PRINT_DEBUG("\tTypical SENS 1315097036, actual %ld\n", (long) sens);
    PRINT_DEBUG("\tTypical PRESSURE 100009, actual %d\n", pressure);

    PRINT_DEBUG("end\n");
  }

};
