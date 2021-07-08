// Fill in this class with your context data (internal state):
// list all the variables you want global (per function instance)
#include "dataview-uniq.h"
#include <time.h> 
#include <fstream>
#include <iostream>
#include <string>
 
class datapool_state {
public:
    
    asn1SccOBSW_DP_Data data;
    struct timespec mission_time_start;
    
    std::fstream mission_time_nvram;
    std::string mission_time_fn = "/home/pi/PersistentVariables/mission_time.bin";
    asn1SccT_Double nvram_mission_time = 0.0;
    
    std::fstream htl_fs;
    std::string htl_fn = "/home/pi/PersistentVariables/htl.bin";
    
    asn1SccIMU_Queue imu_queue;
    int imu_queue_index = 0;
    
    datapool_state ()
    {
        mission_time_nvram.open(mission_time_fn,
                                std::ios::in | std::ios::out |
                                std::ios::binary | std::ios::ate);
        if (!mission_time_nvram.is_open()) {
            mission_time_nvram.open(mission_time_fn, std::ios::out | std::ios::binary | std::ios::ate);
        }
        
        
        htl_fs.open(htl_fn, std::ios::in | std::ios::out |
                            std::ios::binary | std::ios::ate);
        if (!htl_fs.is_open()) {
            htl_fs.open(htl_fn, std::ios::out | std::ios::binary | std::ios::ate);
        }
        
    }
 
};
