// Fill in this class with your context data (internal state):
// list all the variables you want global (per function instance)
#include "dataview-uniq.h"
#include "EquipementHandlers/Anemometer.h"
#include "Context-anemometer.h"

using namespace equipementHandlers;

class anemometer_state {
public:
    Anemometer anemo;
    
    anemometer_state () : anemo(anemometer_ctxt.gpio_pin) {
        ;
    }
};
