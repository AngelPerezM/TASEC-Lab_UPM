// Fill in this class with your context data (internal state):
// list all the variables you want global (per function instance)
#include "dataview-uniq.h"
#include <time.h> 
#include <fstream>
#include <iostream>
 
class datapool_state {
public:
  // Add your members here
  // int counter;
    asn1SccOBSW_DP_Data data;
    struct timespec mission_time_start;
    std::fstream mission_time_nvram;
    
    datapool_state () : 
        mission_time_nvram("/home/pi/PersistentMemory/mission_time.bin", std::ios::in | std::ios::out | std::ios::binary)
    {
        
    }
 
};
