// Fill in this class with your context data (internal state):
// list all the variables you want global (per function instance)
#include "dataview-uniq.h"
#include "EquipementHandlers/PT1000.h"
#include "Context-pt1000sensors.h"
#include <vector>
#include <iostream>

using namespace equipementHandlers;

class pt1000sensors_state {
public:
    std::vector <PT1000> all_pt1000;
    double et = 0.0;
    int nIters = 0.0;
    pt1000sensors_state () {
        for (int i = 0; i < n_of_pt1000 ; ++i) {
            all_pt1000.push_back(PT1000((int) pt1000sensors_ctxt.channels.arr[i],
                                        "/home/pi/blackbox.log"));
            all_pt1000[i].activateVccCorrection(pt1000sensors_ctxt.vcc_ch);
            all_pt1000[i].setFIRNSamples(50);
        }
    }
    
    void stop () {
        std::cout << "+-------------------------------------------------------------\n"
                  << "| PT10000s::readTemps = " << std::to_string(et/nIters) << "\n"
                  << "+-------------------------------------------------------------" << std::endl;
        for (int i = 0; i < n_of_pt1000 ; ++i) {
            all_pt1000[i].~PT1000();
        }
    }
};
