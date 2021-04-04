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

  GroveAdcHat::GroveAdcHat(uint8_t bus_num) :
    fileLogger(FileLoggerFactory::getInstance().createFileLogger("/tmp/log.txt"))
  {
    try {
      bus = bhs::BusHandlerFactory::getInstance().createI2CHandler(bus_num);
    } catch (bhs::I2CException &e) {
      fileLogger.LOG(Emergency, e.what());
    }
  }

  GroveAdcHat::~GroveAdcHat() {
    // ;
  }

  void GroveAdcHat::get_all_raw_data(uint16_t all_raw_data [ADC_CHAN_NUM]) {
    std::cout << "get_all_raw_data begin" << std::endl;
    for(int i = 0; i < ADC_CHAN_NUM; ++i) {
      all_raw_data[i] = get_nchan_raw_data(i);
    }
    std::cout << "get_all_raw_data end" << std::endl;
  }

  uint16_t GroveAdcHat::get_nchan_raw_data(int n) {
    return get_nchan_data(REG_RAW_DATA_START + n);
  }

  uint16_t GroveAdcHat::get_nchan_vol_milli_data(int n) {
    return get_nchan_data(REG_VOL_START + n);
  }

  uint16_t GroveAdcHat::get_nchan_ratio_0_1_data(int n) {
    return get_nchan_data(REG_RTO_START + n);
  }

  // This ADC has little-endian byte ordering:
  // The ADC (slave) sends first the LSB and then the MSB data:
  // SLAVE:   | LSB |     | MSB |      |   |
  // MASTER:  |     | ACK |     | NACK | P |
  uint16_t GroveAdcHat::get_nchan_data(uint8_t reg) {
    uint16_t data = 0;
    try {
      int res = bus->readRegister(ADC_DEFAULT_IIC_ADDR, reg, (uint8_t *) &data, 2);
      if (2 != res) {
        data = 0;
      }
    } catch (bhs::I2CException &e){
      data = 0;
      fileLogger.LOG(Emergency, e.what());
    }
    
    return data;
  }

}
