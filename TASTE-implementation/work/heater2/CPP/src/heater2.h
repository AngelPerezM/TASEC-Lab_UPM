
/* Header file for function Heater2 in CPP language
 * Generated by TASTE on 2021-06-21 01:56:24
 * Context Parameters present : YES
 * Provided interfaces : getPowerH2, setOnOffH2, setPowerH2, stop
 * Required interfaces : 
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 144878 148334 171526 160468
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

#pragma once

#include "dataview-uniq.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __unix__
   #include <stdlib.h>
   #include <stdio.h>
#endif

void heater2_startup(void);

/* Provided interfaces */
void heater2_PI_getPowerH2( asn1SccHeater_Data * );
void heater2_PI_setOnOffH2( const asn1SccHeater_On_Off * );
void heater2_PI_setPowerH2( const asn1SccT_Float * );
void heater2_PI_stop( );

/* Required interfaces */



#ifdef __cplusplus
}
#endif

