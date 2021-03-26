#ifndef TC74TEMPSENSOR_H
#define TC74TEMPSENSOR_H

/*******************************************************************************
 * ./TC74TempSensor.h
 *
 * 09/mar/2021 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include <stdint.h>
#include <vector>

#include "BusHandlers/BusHandlerFactory.h"

/* Defines section
 *******************************************************************************/
#define TC74_IIC_ADDR 0x4D

namespace equipementHandlers {
  class TC74TempSensor {
    private:
      busHandlers::I2CHandler *bus = nullptr;

      const int I2C_ADDRESS = 0x4D;

      /**
       * Command to be send to the temp sensor.
       */
      enum Commands : uint8_t {
        RTR  = 0x00,  // Read temperature (TEMP)
        RWCR = 0x01   // Read/write configuration (CONFIG)
      };

      /**
       * To make bits within CONFIG register easy to read/write individually,
       * we define the following bitmasks
       */
      enum ConfigRegMasks : uint8_t {
        SBY_SWITCH = 0x80,  // STANDBY Switch. 1 = standby, 0 = normal.
        DATA_READY = 0x40   // Data Ready. 1 = ready, 0 = not ready.
      };

      void setMode(const uint8_t configRegister);

    public:

      // CONSTRUCTOR
      TC74TempSensor(uint8_t bus_num = 1);

      // DESTRUCTOR
      ~TC74TempSensor();

      // MANIPULATORS

      // ACCESORS

      /**
       *  Internal sensor temperature 2's complement.
       */
      int8_t getTemperature();

      bool isDataReady();

      // Manipulators:

      void setStandbyMode();

      void setNormalMode();

  };

}
#endif // TC74TEMPSENSOR_H
