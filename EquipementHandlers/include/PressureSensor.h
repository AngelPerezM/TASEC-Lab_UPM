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
    public:

      struct CalibrationData {
        // Raw data:
        uint16_t c1,c2, c3, c4, c5, c6;
        // processsed raw data:
        float sensT1;
        float offT1;
        float tcs;
        float tco;
        float tRef;
        float tempSens;
      };

      enum OSR : uint8_t {
        OSR256 = 0x1,
        OSR512 = 0x2,
        OSR1024 = 0x4,
        OSR2048 = 0x6,
        OSR4096 = 0x8
      };

      // CONSTRUCTOR
      PressureSensor(uint8_t bus_num = 0, uint8_t cs = 0, OSR osr = OSR512,
                     const char *fileName = "/home/pi/blackbox.log");

      // DESTRUCTOR
      ~PressureSensor();

      // MANIPULATORS
      int reset(void);

      // ACCESORS

      int getTemperature(int32_t &temp);

      /**
       * Calculates temperature compensated pressure and also the temperature
       * of the chip.
       *
       * @param pressure output parameter, will contain the pressure measured in 
       * 10*microbar.
       * @param temp output parameter, will contain the temperature measured in
       * 100*ºC centicelsius?)
       */
      int getPressureAndTemp(int32_t &pressure, int32_t &temp, uint32_t &d1,
                             uint32_t &d2);
      /**
       * return true if data is valid, false if not.
       */
      bool getCalibData(CalibrationData &cd);

    private:

      bool isCalibDataValid = false;
      CalibrationData calibData;
      FileLogger *fileLogger;

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

      uint16_t adcDelays_usecs [5] = {600, 1170, 2280, 4540, 9040};

      bhs::SPIHandler spi;
      OSR m_osr;
      bool spiCreated = false;
        
      int readCalibrationData(void);

      int readPROM(uint8_t address, uint16_t &data);

      uint16_t getDelay(void);

      int readD1(uint32_t &d1);

      int readD2(uint32_t &d2);

  };

}

#endif // PRESSURE_SENSOR_H
