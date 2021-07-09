// Fill in this class with your context data (internal state):
// list all the variables you want global (per function instance)
#include "dataview-uniq.h"

class i2cdevsreader_state {
public:
  // Add your members here
  // int counter;
    asn1SccOBSW_DP_Data obsw_dp_data;
    i2cdevsreader_state () {
        obsw_dp_data.exist = {
            .gps = 0,
            .imu = 0,
            .tc74s = 0,
            .pt1000s = 0,
            .ps1 = 0,
            .ps2 = 0,
            .heater1 = 0,
            .heater2 = 0,
            .anemometer = 0
        };
    }

};
