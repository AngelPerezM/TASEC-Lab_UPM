// Fill in this class with your context data (internal state):
// list all the variables you want global (per function instance)
#include "dataview-uniq.h"
#include "EquipementHandlers/Anemometer.h"
#include "Context-anemometer.h"
#include <iostream>

using namespace equipementHandlers;

class anemometer_state {
public:
    Anemometer anemo;

    double et = 0.0;
    int nIters = 0.0;  
    
    anemometer_state () : anemo(anemometer_ctxt.gpio_pin) {
        ;
    }
    
    void stop () {
        std::cout << "+-------------------------------------------------------------\n"
                  << "| Anemometer::getTotalPulses = " << std::to_string(et/nIters) << "\n"
                  << "+-------------------------------------------------------------" << std::endl;
        anemo.~Anemometer();
    }
};
