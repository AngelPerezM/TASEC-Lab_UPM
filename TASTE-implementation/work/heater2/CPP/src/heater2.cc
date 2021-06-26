// Body file for function Heater2
// Generated by TASTE on 2021-05-19 10:54:57
// You can edit this file, it will not be overwritten
// Provided interfaces : getPowerH2, setPowerH2
// Required interfaces : 
// User-defined properties for this function:
//   |_ Taste::Active_Interfaces = any
//   |_ Taste::coordinates = 78082 159857 103722 169558
// Timers              : 

#include "heater2.h"
#include "heater2_state.h"
#include <iostream>

// Define and use function state inside this context structure
// avoid defining global/static variable elsewhere
heater2_state ctxt_heater2;
static bool stopped_h2 = false;


void heater2_startup(void)
{
   // Write your initialisation code, but DO NOT CALL REQUIRED INTERFACES
    std::cout << "[Heater2] Startup" << std::endl;
}

void heater2_PI_getPowerH2
      (asn1SccHeater_Data *OUT_heater_data)

{
    struct timespec start, stop;
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    OUT_heater_data->power_watts = ctxt_heater2.hh.getActualPower();
    OUT_heater_data->validity = asn1Sccvalid;
    
    clock_gettime(CLOCK_MONOTONIC, &stop);
    ctxt_heater2.et += ((stop.tv_sec - start.tv_sec)*1e3 + (stop.tv_nsec - start.tv_nsec)/1e6);
    ctxt_heater2.nIters++;
}

void heater2_PI_setPowerH2
      (const asn1SccT_Float *IN_power)

{
    (void) ctxt_heater2.hh.setPower(*IN_power);
}

void heater2_PI_setOnOffH2( const asn1SccHeater_On_Off *on_off ) {
    if (*on_off == asn1Sccon) {
        ctxt_heater2.hh.engage();
    } else {
        ctxt_heater2.hh.disengage();
    }
}

void heater2_PI_stop( ) {
    stopped_h2 = true;
    ctxt_heater2.~heater2_state();
}
