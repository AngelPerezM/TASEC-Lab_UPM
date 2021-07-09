// Fill in this class with your context data (internal state):
// list all the variables you want global (per function instance)
#include "dataview-uniq.h"
#include "EquipementHandlers/HeaterHandler.h"
#include "Context-heater1.h"

using namespace equipementHandlers;
class heater1_state {
public:
  // Add your members here
  // int counter;
    HeaterHandler hh;

    heater1_state () : hh (heater1_ctxt.gpio_pin)
    {
      hh.setMaxPSVoltage_volts(12);
    }
    
    void stop ()
    {
        hh.~HeaterHandler();
    }
};
