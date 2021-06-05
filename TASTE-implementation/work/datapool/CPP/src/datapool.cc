// Body file for function DataPool
// Generated by TASTE on 2021-05-17 12:48:29
// You can edit this file, it will not be overwritten
// Provided interfaces : InsertAllData, RetreiveAllData, RetreiveHTLData
// Required interfaces : notifyTempChanged
// User-defined properties for this function:
//   |_ Taste::Active_Interfaces = any
//   |_ Taste::coordinates = 73422 90233 210446 105509
// Timers              : 

#include "datapool.h"
#include "datapool_state.h"
#include "Context-datapool.h"

#include <iostream>

// Define and use function state inside this context structure
// avoid defining global/static variable elsewhere
datapool_state ctxt_datapool;

// Auxiliar functions:
////////////////////////////////////////////////////////////////////////////////

inline asn1SccT_Double get_mission_time () {
    struct timespec t_now;
    (void) clock_gettime( CLOCK_MONOTONIC, &t_now );
    return ( t_now.tv_sec - ctxt_datapool.mission_time_start.tv_sec ) +
           ( (t_now.tv_nsec - ctxt_datapool.mission_time_start.tv_nsec)/1e9 );
}

inline bool isOutdated(asn1SccT_Double dataTimestamp) {
    return (get_mission_time() - dataTimestamp) > datapool_ctxt.maxoutdatedsecs;
}


// Componennt interfaces implementation:
////////////////////////////////////////////////////////////////////////////////

void datapool_startup(void)
{
   // Write your initialisation code, but DO NOT CALL REQUIRED INTERFACES
    std::cout << "[DataPool] Startup" << std::endl;
    std::cout << "[DataPool] TODO: read file to get last boot experiment state." << std::endl;
    (void) clock_gettime( CLOCK_MONOTONIC, &ctxt_datapool.mission_time_start );
}

void datapool_PI_InsertCompleteGroup (const asn1SccOBSW_DP_Data *IN_alldata) {

    if (IN_alldata->exist.gps == 1) {
        ctxt_datapool.data.gps = IN_alldata->gps;
        std::cout << "modifies gps" << "\n";        
    }
    
    if (IN_alldata->exist.imu == 1) {
        ctxt_datapool.data.imu = IN_alldata->imu;
        std::cout << "modifies IMU" << "\n";
    }
    
    if (IN_alldata->exist.tc74s == 1) {
        ctxt_datapool.data.tc74s = IN_alldata->tc74s;
        std::cout << "modifies TC74" << "\n";
    }
    if (IN_alldata->exist.pt1000s == 1) {
        ctxt_datapool.data.pt1000s = IN_alldata->pt1000s;
        std::cout << "modifies PT1000s" << "\n";
    }
    if (IN_alldata->exist.ps1 == 1) {
        ctxt_datapool.data.ps1 = IN_alldata->ps1;
        std::cout << "modifies PS1" << "\n";
    }
    if (IN_alldata->exist.ps2 == 1) {
        ctxt_datapool.data.ps2 = IN_alldata->ps2;
        std::cout << "modifies PS2" << "\n";
    }
    if (IN_alldata->exist.heater1 == 1) {
       ctxt_datapool.data.heater1 = IN_alldata->heater1;
       std::cout << "modifies H1" << "\n";
    }
    if (IN_alldata->exist.heater2 == 1) {
       ctxt_datapool.data.heater2 = IN_alldata->heater2;
       std::cout << "modifies H2" << "\n";
    }
    if (IN_alldata->exist.anemometer == 1) {
        ctxt_datapool.data.anemometer = IN_alldata->anemometer;
       std::cout << "modifies anemometer" << "\n";
    }
}

void datapool_PI_RetreiveAllData (asn1SccOBSW_DP_Data *OUT_data) 
{
    *OUT_data = ctxt_datapool.data;
}

void datapool_PI_getTime( asn1SccT_Double *gps_time, asn1SccT_Double *mission_time )
{
    *gps_time = ctxt_datapool.data.gps.data.date_and_time;
    *mission_time = get_mission_time();
}

void datapool_PI_checkValidity( )
{
    if (isOutdated(ctxt_datapool.data.imu.mission_time)) {
        ctxt_datapool.data.imu.data.mgt_valid = asn1Sccinvalid;
        ctxt_datapool.data.imu.data.acc_valid = asn1Sccinvalid;
        ctxt_datapool.data.imu.data.gyro_valid = asn1Sccinvalid;
    }
    

    if (isOutdated(ctxt_datapool.data.tc74s.mission_time)) {
        for (int i = 0; i < n_of_TC74s; ++i) {
            ctxt_datapool.data.tc74s.data.arr[i].validity = asn1Sccinvalid;
        }
    }
    
    if (isOutdated(ctxt_datapool.data.pt1000s.mission_time)) {
        for (int i = 0; i < n_of_pt1000; ++i) {
            ctxt_datapool.data.pt1000s.data.validity.arr[i] = asn1Sccinvalid;
        }
    }

    ctxt_datapool.data.ps1.data.validity =
        isOutdated(ctxt_datapool.data.ps1.mission_time)? asn1Sccinvalid : asn1Sccvalid;
        
    ctxt_datapool.data.ps2.data.validity =
        isOutdated(ctxt_datapool.data.ps2.mission_time)? asn1Sccinvalid : asn1Sccvalid;
        
    ctxt_datapool.data.heater1.data.validity =
        isOutdated(ctxt_datapool.data.heater1.mission_time)? asn1Sccinvalid : asn1Sccvalid;
        
    ctxt_datapool.data.heater2.data.validity =
        isOutdated(ctxt_datapool.data.heater2.mission_time)? asn1Sccinvalid : asn1Sccvalid;
}
