// Fill in this class with your context data (internal state):
// list all the variables you want global (per function instance)
#include "dataview-uniq.h"

class i2cbusreader_state {
public:
  // Add your members here
  // int counter;
    asn1SccOBSW_DP_Data obsw_dp_data;
    i2cbusreader_state () {
        obsw_dp_data.exist = {
            .gps = 0,
            .imu = 1,
            .tc74s = 1,
            .pt1000s = 1,
            .ps1 = 0,
            .ps2 = 0,
            .heater1 = 0,
            .heater2 = 0,
            .anemometer = 0
        };
    }

};
