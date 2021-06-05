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
      PressureSensor::OSR osr, const char *fileName)
    try : spi(bus_num, cs, 10000000), m_osr(osr)
    {
      spiCreated = true;
      fileLogger = FileLoggerFactory::getInstance().createFileLogger(fileName);
      reset();
      isCalibDataValid = (readCalibrationData() > 0);
      
      if (!isCalibDataValid) {
          fileLogger->LOG(Error, "Could not read calibration data, data must be not correct.");
      }
      
    } catch (bhs::SPIException &e) {
      spiCreated = false;
      fileLogger = FileLoggerFactory::getInstance().createFileLogger(fileName);
      fileLogger->LOG(Error, "Could not create SPI handler:\n" +
          std::string(e.what()));
    }

  // DESTRUCTOR
  PressureSensor::~PressureSensor() {

  }

  // MANIPULATORS
  int PressureSensor::reset(void) {
    PRINT_DEBUG("begin\n");
    if (!spiCreated) {
      fileLogger->LOG(Error, "SPI was not created");
      return -1;      
    }

    int rc = -1;
    try {
      uint8_t reg = RESET;
      rc = spi.write(&reg, sizeof(reg), 2800);
      usleep(2800); // por si las moscas.
    } catch (bhs::SPIException &e) {
      fileLogger->LOG(Emergency, "Could not reset pressure sensor\n"+
          std::string(e.what()));
    }

    PRINT_DEBUG("end\n");
    return rc;
  }

  // ACCESORS
  int PressureSensor::readCalibrationData(void) {
    if (!spiCreated) {
      fileLogger->LOG(Error, "SPI was not created");
      return -1;
    }

    int rc = readPROM(SENS_T1, calibData.c1);
    if (rc > 0) {
      rc = readPROM(OFF_T1, calibData.c2);
    }
    if (rc > 0) {
      rc = readPROM(TCS, calibData.c3);
    }
    if (rc > 0) {
      rc = readPROM(TCO, calibData.c4);
    }
    if (rc > 0) {
      rc = readPROM(T_REF, calibData.c5);
    }
    if (rc > 0) {
      rc = readPROM(TEMP_SENS, calibData.c6);
    }

    if (rc > 0) {
      calibData.sensT1 = float(calibData.c1) * pow(2,15);   // c1 * 2^15
      calibData.offT1 = float(calibData.c2) * pow(2,16);    // c2 * 2^16
      calibData.tcs = float(calibData.c3) / pow(2,8);       // c3 / 2^8
      calibData.tco = float(calibData.c4) / pow(2,7);       // c4 / 2^7
      calibData.tRef = float(calibData.c5) * pow(2,8);      // c5 * 2^8
      calibData.tempSens = float(calibData.c6) / pow(2,23); // c6 / 2^23

      PRINT_DEBUG("Typical C1: 40127, actual: %d\n", calibData.c1);
      PRINT_DEBUG("Typical C2: 36924, actual: %d\n", calibData.c2);
      PRINT_DEBUG("Typical C3: 23317, actual: %d\n", calibData.c3);
      PRINT_DEBUG("Typical C4: 23282, actual: %d\n", calibData.c4);
      PRINT_DEBUG("Typical C5: 33464, actual: %d\n", calibData.c5);
      PRINT_DEBUG("Typical C6: 28312, actual: %d\n\n", calibData.c6);

      PRINT_DEBUG("Typical sensT1: 1314881536, actual: %f\n", calibData.sensT1);
      PRINT_DEBUG("Typical offT1: 2419851264, actual: %f\n", calibData.offT1);
      PRINT_DEBUG("Typical tcs: 91.08203125, actual: %f\n", calibData.tcs);
      PRINT_DEBUG("Typical tco: 181.890625, actual: %f\n", calibData.tco);
      PRINT_DEBUG("Typical tRef: 8566784, actual: %f\n", calibData.tRef);
      PRINT_DEBUG("Typical tempSens: 0.0033750534057617188, actual: %f\n", calibData.tempSens);
    } else {
      fileLogger->LOG(Emergency, "Could not read calibration data");
    }
    
    return rc;

  }
  
  bool PressureSensor::getCalibData(CalibrationData &cd) {
      cd = this->calibData;
      return isCalibDataValid;
  }

  uint16_t PressureSensor::getDelay(void) {
    if (!spiCreated) {
      fileLogger->LOG(Error, "SPI was not created");
    }

    uint16_t index = (m_osr >> 1);
    if (index > 4) {
      std::cout << "Mal index!!!!" << std::endl;
      index = 0;
    }
    
    return adcDelays_usecs[index];
  }

  int PressureSensor::readD1(uint32_t &d1) {
    PRINT_DEBUG("begin\n");

    if (!spiCreated) {
      fileLogger->LOG(Error, "SPI was not created");
      return -1;      
    }

    int rc = -1;

    try {
      uint8_t buf [3];
      uint8_t cmd = CONVERT_D1 | m_osr;
      rc = spi.write(&cmd, sizeof(cmd), getDelay());
      rc = spi.readRegister((uint8_t) ADC_READ, buf, sizeof(buf), 0);

      d1 = (buf[0] << 16 | buf[1] << 8 | buf [2]);
      PRINT_DEBUG("Typical D1: 9085466, actual: %d\n", d1);
    } catch (bhs::SPIException &e) {
      rc = -1;
      fileLogger->LOG(Emergency, "Could not read D1 value\n"+
          std::string(e.what()));
    }

    PRINT_DEBUG("end\n");
    return rc;
  }

  int PressureSensor::readD2(uint32_t &d2) {
    PRINT_DEBUG("begin\n");
    if (!spiCreated) {
      fileLogger->LOG(Error, "SPI was not created");
      return -1;
    }

    int rc = -1;

    try {
      uint8_t buf [3];
      uint8_t cmd = CONVERT_D2 | m_osr;

      rc = spi.write(&cmd, sizeof(cmd), getDelay());
      rc = spi.readRegister((uint8_t) ADC_READ, buf, sizeof(buf), 0);

      d2 = (buf[0] << 16 | buf[1] << 8 | buf [2]);
      PRINT_DEBUG("Typical D2: 8569150, actual: %d\n", d2);
    } catch (bhs::SPIException &e) {
      rc = -1;
      fileLogger->LOG(Emergency, "Could not read D2 value\n"+
          std::string(e.what()));
    }

    PRINT_DEBUG("end\n");
    return rc;
  }

  int PressureSensor::readPROM(uint8_t address, uint16_t &data) {
    PRINT_DEBUG("begin\n");
    if (!spiCreated) {
      fileLogger->LOG(Error, "SPI was not created");
      return -1;
    }

    int rc = -1;
    try {
      uint8_t buf [2];
      rc = spi.readRegister(address, buf, sizeof(buf), 0);
      data = ( (buf[0]) << 8 | buf[1] );
    } catch (bhs::SPIException &e) {
      rc = -1;
      fileLogger->LOG(Emergency, "Could not read PROM address "+
          std::string(e.what()));
    }

    PRINT_DEBUG("end\n");
    return rc;
  }

  int32_t PressureSensor::getTemperature(int32_t &temp) {
    PRINT_DEBUG("begin\n");
    if (!spiCreated) {
      fileLogger->LOG(Error, "SPI was not created");
      return -1;
    }

    int rc = -1;
    int32_t dT;
    uint32_t d2;

    rc = readD2(d2);
    dT = d2- calibData.tRef;

    if (rc > 0) {
      temp = (2000 + dT * calibData.tempSens);

      int32_t t2 = 0;
      if (temp < 2000) { // Temp < 20 ºC 
        t2 = (dT*dT) / pow(2,31);
      }

      PRINT_DEBUG("end\n");
      temp = temp-t2;
    }

    return rc;
  }

  /**
   * @param pressure output parameter, will contain the pressure measured in 
   * 10*microbar.
   * @param temp output parameter, will contain the temperature measured in
   * 100*ºC (centicelsius?).
   */
  int PressureSensor::getPressureAndTemp(int32_t /*out*/ &pressure, 
      int32_t /*out*/ &temp, uint32_t /*out*/ &d1, uint32_t /*out*/ &d2)
  {
    PRINT_DEBUG("begin\n");
    if (!spiCreated) {
      fileLogger->LOG(Error, "SPI was not created");
      return -1;      
    }

    int rc = readD1(d1);
    if (rc > 0) {
      rc = readD2(d2);
    }

    if (rc > 0) {
      int32_t dT = d2 - calibData.tRef;
      int64_t off = calibData.offT1 + calibData.tco*dT;
      int64_t sens = calibData.sensT1 + calibData.tcs*dT;

      temp = (2000 + dT * calibData.tempSens);
      pressure = 0;

      int32_t t2 = 0;
      int64_t off2 = 0;
      int64_t sens2 = 0;

      if(temp < 2000) {     // Temp < 20 ºC
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
      pressure = ( ((d1 * sens) / pow(2, 21)) - off ) / pow(2,15);

      PRINT_DEBUG("\tTypical dT 2366, actual %d\n", dT);
      PRINT_DEBUG("\tTypical TEMP 2007, actual %d\n", temp);
      PRINT_DEBUG("\tTypical OFF 2420281617, actual %lld\n", (long long) off);
      PRINT_DEBUG("\tTypical SENS 1315097036, actual %lld\n", (long long) sens);
      PRINT_DEBUG("\tTypical PRESSURE 100009, actual %d\n", pressure);
    }

    PRINT_DEBUG("end\n");

    return rc;
  }

};
