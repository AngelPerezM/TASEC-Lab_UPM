// Body file for function Heater1
// Generated by TASTE on 2021-05-19 10:53:28
// You can edit this file, it will not be overwritten
// Provided interfaces : getPowerH1, setPowerH1
// Required interfaces : 
// User-defined properties for this function:
//   |_ Taste::Active_Interfaces = any
//   |_ Taste::coordinates = 78082 138929 102890 148354
// Timers              : 

#include "heater1.h"
#include "heater1_state.h"
#include <iostream>

// Define and use function state inside this context structure
// avoid defining global/static variable elsewhere
heater1_state ctxt_heater1;


void heater1_startup(void)
{
   // Write your initialisation code, but DO NOT CALL REQUIRED INTERFACES
    std::cout << "[Heater1] Startup" << std::endl;
}

void heater1_PI_getPowerH1
      (asn1SccHeater_Data *OUT_heater_data)

{
    OUT_heater_data->power_watts = ctxt_heater1.hh.getActualPower();
    OUT_heater_data->validity = asn1Sccvalid;
    std::cout << "GET POWER H1" << std::endl;
}

void heater1_PI_setPowerH1
      (const asn1SccT_Float *IN_power)

{
    (void) ctxt_heater1.hh.setPower(*IN_power);
    std::cout << "SET POWER H1" << std::endl;
}

void heater1_PI_setOnOffH1( const asn1SccT_Float * on_off ) {
     if (*on_off == asn1Sccon) {
        ctxt_heater1.hh.engage();
    } else {
        ctxt_heater1.hh.disengage();
    }   
}
