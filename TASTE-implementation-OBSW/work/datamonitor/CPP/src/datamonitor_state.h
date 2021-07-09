// Fill in this class with your context data (internal state):
// list all the variables you want global (per function instance)
#include "dataview-uniq.h"

class datamonitor_state {
public:
  // Add your members here
  // int counter;
    asn1SccOBSW_DP_Data obsw_dp_data;
    bool firstSample = true;
    bool stopped_dm = false;
    
    datamonitor_state () 
    {
        obsw_dp_data.exist = {
            .gps = 0,
            .imu = 0,
            .tc74s = 0,
            .pt1000s = 0,
            .ps1 = 1,
            .ps2 = 1,
            .heater1 = 1,
            .heater2 = 1,
            .anemometer = 1
        };
    }
};
