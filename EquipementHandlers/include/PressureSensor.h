#ifndef PRESSURE_SENSOR_H
#define PRESSURE_SENSOR_H

/*******************************************************************************
 * 23/mar/2021 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include "BusHandlers/SPIHandler.h"
#include "Utils/FileLoggerFactory.h"

#include <cstdint>  // fixed size integers
#include <string>

using namespace utils;
namespace bhs = busHandlers;

namespace equipementHandlers {
  class PressureSensor {
    private:

      FileLogger fileLogger;

      enum Register : uint8_t {
        RESET = 0x1E,

        CONVERT_D1 = 0x40,  // OSR = 256.
        CONVERT_D2 = 0x50,  // OSR = 256.

        ADC_READ = 0x00,

        SENS_T1 = 0xA2,   // Pressure sensitivity.
        OFF_T1 = 0xA4,    // Pressure offset.
        TCS = 0xA6,       // Temp. coefficient of SENS.
        TCO = 0xA8,       // Temp. coefficient of OFF.
        T_REF = 0xAA,     // Reference temperature.
        TEMP_SENS = 0xAC  // Temp. coefficient of TREF.
      };

      enum OSR : uint8_t {
        OSR256 = 0x1,
        OSR512 = 0x2,
        OSR1024 = 0x4,
        OSR2048 = 0x6,
        OSR4096 = 0x8
      };

      uint16_t adcDelays_usecs [5] = {600, 1170, 2280, 4540, 9040};

      /**
       * Calibration data:
       */
      float sensT1;
      float offT1;
      float tcs;
      float tco;
      float tRef;
      float tempSens;

      bhs::SPIHandler spi;
      OSR m_osr;


    protected:

      void readCalibrationData(void);

      uint32_t readD1();

      uint32_t readD2();

      uint16_t readPROM(uint8_t address);

      uint16_t getDelay();

    public:

      // CONSTRUCTOR
      PressureSensor(uint8_t bus_num = 0, uint8_t cs = 0, OSR osr = OSR512,
                     const char *fileName = "/home/pi/log.txt");

      // DESTRUCTOR
      ~PressureSensor();

      // MANIPULATORS
      void reset(void);

      // ACCESORS

      int32_t getTemperature(void);

      /**
       * Calculates temperature compensated pressure and also the temperature
       * of the chip.
       */
      void getPressureAndTemp(int32_t &pressure, int32_t &temp);

  };

}

#endif // PRESSURE_SENSOR_H
