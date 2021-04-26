#ifndef GROVEADCHAT_H
#define GROVEADCHAT_H

/*******************************************************************************
 * ./GroveAdcHat.h
 * Author: Ángel Pérez
 *
 * 22/9/2020 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include <stdint.h>
#include <vector>

#include "Utils/FileLoggerFactory.h"
#include "BusHandlers/BusHandlerFactory.h"

using namespace utils;

/* Defines section
 *******************************************************************************/
#define ADC_DEFAULT_IIC_ADDR 0x04

#define ADC_CHAN_NUM 8

#define REG_RAW_DATA_START 0x10
#define REG_VOL_START 0x20
#define REG_RTO_START 0x30

#define REG_SET_ADDR 0xC0

namespace equipementHandlers {
  class GroveAdcHat {
    private:
      busHandlers::I2CHandler *bus;

      // CONSTRUCTOR
      GroveAdcHat(uint8_t bus_num = 1);

      GroveAdcHat(const GroveAdcHat &groveAdcHat) = delete;

      GroveAdcHat& operator=(const GroveAdcHat&) = delete;

      // DESTRUCTOR
      ~GroveAdcHat();

    public:
      /**
       * @param bus_num I2C identifier, i.e. /dev/i2c-<bus_num>
       */
      static GroveAdcHat& getInstance() {
        static GroveAdcHat gah(1);
        return gah;
      }

      // MANIPULATORS

      // ACCESORS
      void get_all_raw_data(uint16_t all_raw_data [ADC_CHAN_NUM]);

      /**
       * POST: [0, 4095]. 12 bit max
       */
      uint16_t get_nchan_raw_data(int n = 0);

      /**
       * POST: [0, 3300] mv
       */
      uint16_t get_nchan_vol_milli_data(int n = 0);

      /**
       * POST: [0, 1000] 0.1%
       */
      uint16_t get_nchan_ratio_0_1_data(int n = 0);

    private:
      uint16_t get_nchan_data(uint8_t reg);
      FileLogger *fileLogger;

  };

}
#endif
