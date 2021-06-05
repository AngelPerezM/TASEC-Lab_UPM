// Fill in this class with your context data (internal state):
// list all the variables you want global (per function instance)
#include "dataview-uniq.h"
#include "EquipementHandlers/HeaterHandler.h"
#include "Context-heater2.h"

using namespace equipementHandlers;
class heater2_state {
public:
  // Add your members here
  // int counter;
    HeaterHandler hh;

    heater2_state () : hh (heater2_ctxt.gpio_pin)
    {
      hh.setMaxPSVoltage_volts(12);
    }
};
