// Body file for function Anemometer
// Generated by TASTE on 2021-05-19 12:49:49
// You can edit this file, it will not be overwritten
// Provided interfaces : getTotalPulses
// Required interfaces : 
// User-defined properties for this function:
//   |_ Taste::Active_Interfaces = any
//   |_ Taste::coordinates = 121729 187437 146260 197139
// Timers              : 

#include "anemometer.h"
#include "anemometer_state.h"
#include <iostream>

// Define and use function state inside this context structure
// avoid defining global/static variable elsewhere
anemometer_state ctxt_anemometer;
static bool stopped_anemo = false;


void anemometer_startup(void)
{
   // Write your initialisation code, but DO NOT CALL REQUIRED INTERFACES
    std::cout << "[Anemometer] Startup" << std::endl;
    ctxt_anemometer.anemo.startCounting();
}

void anemometer_PI_getTotalPulses( asn1SccT_UInt64 *OUT_nPulses )
{
    if (stopped_anemo) {
        return;
    }
    
    struct timespec start, stop;
    clock_gettime(CLOCK_MONOTONIC, &start);
    
   // Write your code here
    *OUT_nPulses = ctxt_anemometer.anemo.getCounter();
    
    clock_gettime(CLOCK_MONOTONIC, &stop);
    ctxt_anemometer.et += ((stop.tv_sec - start.tv_sec)*1e3 + (stop.tv_nsec - start.tv_nsec)/1e6);
    ctxt_anemometer.nIters++;
}

void anemometer_PI_stop( ) {
    stopped_anemo = true;
    ctxt_anemometer.stop();
}
