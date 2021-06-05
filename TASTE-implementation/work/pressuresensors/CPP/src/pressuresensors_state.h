// Fill in this class with your context data (internal state):
// list all the variables you want global (per function instance)
#include "dataview-uniq.h"
#include "Context-pressuresensors.h"
#include "EquipementHandlers/PressureSensor.h"

using namespace equipementHandlers;

class pressuresensors_state {
public:
  // Add your members here
  // int counter;
    PressureSensor ps1;
    PressureSensor ps2;
    
    pressuresensors_state () :
        ps1(pressuresensors_ctxt.ps1_id.bus, pressuresensors_ctxt.ps1_id.cs,
            PressureSensor::OSR512),
        ps2(pressuresensors_ctxt.ps2_id.bus, pressuresensors_ctxt.ps2_id.cs,
            PressureSensor::OSR512)
    {
        ;
    }
};
