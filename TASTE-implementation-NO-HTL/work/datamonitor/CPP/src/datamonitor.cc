// Body file for function DataMonitor
// Generated by TASTE on 2021-05-17 13:07:59
// You can edit this file, it will not be overwritten
// Provided interfaces : MayorCycle
// Required interfaces : InsertAllData, actualPowerH1, actualPowerH2, getCalibData, readAccelData, readGPSData, readGyroData, readMGTdata, readPressureAndTemp, readTempsCelsiusTC74, readTempsPT1000
// User-defined properties for this function:
//   |_ Taste::Active_Interfaces = any
//   |_ Taste::coordinates = 168843 119683 207740 181407
// Timers              : 

#include "datamonitor.h"
#include "datamonitor_state.h"
#include <iostream>
#include <string.h> // memset

// Define and use function state inside this context structure
// avoid defining global/static variable elsewhere
datamonitor_state ctxt_dm;
static bool stopped_dm = false;


void datamonitor_startup(void)
{    
    std::cout << "[DataMonitor] Startup" << std::endl;    
}

void datamonitor_PI_ReadData(void)
{
    if (stopped_dm) {
        return;
    }
    
    // Both pressure sensors:
    datamonitor_RI_readPressureAndTemp(&ctxt_dm.obsw_dp_data.ps1.data,
                                       &ctxt_dm.obsw_dp_data.ps2.data);
    datamonitor_RI_getTime(&ctxt_dm.obsw_dp_data.ps1.gps_time,
                           &ctxt_dm.obsw_dp_data.ps1.mission_time);
    datamonitor_RI_getTime(&ctxt_dm.obsw_dp_data.ps2.gps_time,
                           &ctxt_dm.obsw_dp_data.ps2.mission_time);

    // All Heater Handlers:
    datamonitor_RI_getPowerH1( &ctxt_dm.obsw_dp_data.heater1.data );
    datamonitor_RI_getTime(&ctxt_dm.obsw_dp_data.heater1.gps_time,
                           &ctxt_dm.obsw_dp_data.heater1.mission_time);
    datamonitor_RI_getPowerH2( &ctxt_dm.obsw_dp_data.heater2.data );
    datamonitor_RI_getTime(&ctxt_dm.obsw_dp_data.heater2.gps_time,
                           &ctxt_dm.obsw_dp_data.heater2.mission_time);
    
    // Anemo:
    datamonitor_RI_getTotalPulses( &ctxt_dm.obsw_dp_data.anemometer.data );
    datamonitor_RI_getTime(&ctxt_dm.obsw_dp_data.anemometer.gps_time,
                           &ctxt_dm.obsw_dp_data.anemometer.mission_time);
    
    // Send all data to data pool.
    datamonitor_RI_InsertCompleteGroup(&ctxt_dm.obsw_dp_data);
}

void datamonitor_PI_stop_DM( void ) {
    stopped_dm = true;
    datamonitor_RI_stopAnemo( );
    datamonitor_RI_stopH1( );
    datamonitor_RI_stopH2( );
    datamonitor_RI_stopPSs( );
}
