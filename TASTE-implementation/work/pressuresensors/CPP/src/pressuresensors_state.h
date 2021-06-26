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
    asn1SccPS_Calibration_Data ps1_cd, ps2_cd;
    asn1SccContent_Validity ps1_cv, ps2_cv;
    
    PressureSensor ps1;
    PressureSensor ps2;
    
    double et = 0.0;
    int nIters = 0.0;  
    
    pressuresensors_state () :
        ps1(pressuresensors_ctxt.ps1_id.bus, pressuresensors_ctxt.ps1_id.cs,
            PressureSensor::OSR512),
        ps2(pressuresensors_ctxt.ps2_id.bus, pressuresensors_ctxt.ps2_id.cs,
            PressureSensor::OSR512)
    {
        ;
    }
    
    ~pressuresensors_state () {
        std::cout << "+-------------------------------------------------------------\n"
                  << "| PressureSensors::readPressureAndTemp = " << std::to_string(et/nIters) << "\n"
                  << "+-------------------------------------------------------------" << std::endl;
    }
};
