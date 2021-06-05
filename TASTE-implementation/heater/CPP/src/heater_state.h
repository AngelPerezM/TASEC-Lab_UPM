// Fill in this class with your context data (internal state):
// list all the variables you want global (per function instance)
#include "dataview-uniq.h"
#include "EquipementHandlers/HeaterHandler.h"
#include "Context-heater.h"

using namespace equipementHandlers;

class heater_state {
public:
  // Add your members here
  // int counter;
    HeaterHandler hh;
    
    heater_state () : hh (heater_ctxt.gpio_pin)
    {
      ;
    }
};
