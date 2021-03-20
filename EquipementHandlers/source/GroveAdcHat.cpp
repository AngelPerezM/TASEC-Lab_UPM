/*******************************************************************************
 * ./GroveAdcHat.cpp
 * Author: Ángel Pérez
 *
 * 22/9/2020 - Version 1.0
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include "GroveAdcHat.h"

#include <iostream>

namespace bhs = busHandlers;

/* Function definitions
 *******************************************************************************/

namespace equipementHandlers {

  GroveAdcHat::GroveAdcHat(uint8_t bus_num) {
    bus = bhs::BusHandlerFactory::getInstance().createI2CHandler(bus_num);
    if(bus != NULL)
      std::cout << "I2CHandler created." << std::endl;
    if(bus->isOpenned())
      std::cout << "ADC: I2C Bus Openned." << std::endl;
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

    bus->setSlaveAddress(ADC_DEFAULT_IIC_ADDR);
    int res = bus->readRegister(reg, (uint8_t *) &data, 2);
    if(2 != res) {
      data = 0;
    }

    return data;
  }

}
