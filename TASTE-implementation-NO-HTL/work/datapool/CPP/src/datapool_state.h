// Fill in this class with your context data (internal state):
// list all the variables you want global (per function instance)
#include "dataview-uniq.h"
#include <time.h> 
 
class datapool_state {
public:
  // Add your members here
  // int counter;
    asn1SccOBSW_DP_Data data;
    struct timespec mission_time_start;
 
};
