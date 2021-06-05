// Fill in this class with your context data (internal state):
// list all the variables you want global (per function instance)
#include "dataview-uniq.h"
#include "EquipementHandlers/TC74TempSensor.h"
#include "Context-tc74sensors.h"
#include <vector>

using namespace equipementHandlers;

class tc74sensors_state {
public:
  // Add your members here
  // int counter;
    std::vector<TC74TempSensor> tc74_sensors;
    
    tc74sensors_state ()
    {
        for (int i = 0; i < n_of_TC74s; ++i) {
            tc74_sensors.push_back(TC74TempSensor(tc74sensors_ctxt.i2c_channels.arr[i]));
        }
    }
};
