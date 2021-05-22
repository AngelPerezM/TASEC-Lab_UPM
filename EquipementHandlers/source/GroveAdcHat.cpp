/*******************************************************************************
 * ./GroveAdcHat.cpp
 * Author: Ángel Pérez
 *
 * 22/9/2020 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include "GroveAdcHat.h"
#include "Utils/Debug.h"

#include <iostream>

namespace bhs = busHandlers;

/* Function definitions
 *******************************************************************************/

namespace equipementHandlers {

  GroveAdcHat::GroveAdcHat(uint8_t bus_num)
  {

    fileLogger = FileLoggerFactory::getInstance().createFileLogger("/home/pi/blackbox_ADC_HAT.log");
    try {
      bus = bhs::BusHandlerFactory::getInstance().createI2CHandler(bus_num);
    } catch (bhs::I2CException &e) {
      fileLogger->LOG(Emergency, e.what());
    }
  }

  GroveAdcHat::~GroveAdcHat() {
    // ;
  }

  int GroveAdcHat::get_all_raw_data(uint16_t all_raw_data [ADC_CHAN_NUM]) {
    int rc = -1;
    for(int i = 0; i < ADC_CHAN_NUM; ++i) {
      if (get_nchan_raw_data(i, all_raw_data[i]) < 0) {
        rc = -1;
        all_raw_data[i] = 0;
      }
    }

    return rc;
  }

  int GroveAdcHat::get_nchan_raw_data(int n, uint16_t &raw_data) {
    return get_nchan_data(REG_RAW_DATA_START + n, raw_data);
  }

  int GroveAdcHat::get_nchan_vol_milli_data(int n, uint16_t &milli_data) {
    return get_nchan_data(REG_VOL_START + n, milli_data);
  }

  int GroveAdcHat::get_nchan_ratio_0_1_data(int n, uint16_t &ratio_data) {
    return get_nchan_data(REG_RTO_START + n, ratio_data);
  }

  // This ADC has little-endian byte ordering:
  // The ADC (slave) sends first the LSB and then the MSB data:
  // SLAVE:   | LSB |     | MSB |      |   |
  // MASTER:  |     | ACK |     | NACK | P |
  int GroveAdcHat::get_nchan_data(uint8_t reg, uint16_t &data) {
    int rc = -1;

    try {
      rc = bus->readRegister(ADC_DEFAULT_IIC_ADDR, reg, (uint8_t *) &data, 2);
      if (2 != rc) {
        data = 0;
      }
    } catch (bhs::I2CException &e){
      data = 0;
      fileLogger->LOG(Emergency, e.what());
    }
    
    return rc;
  }

}
