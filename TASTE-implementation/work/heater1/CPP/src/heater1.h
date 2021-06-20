
/* Header file for function Heater1 in CPP language
 * Generated by TASTE on 2021-06-18 18:39:03
 * Context Parameters present : YES
 * Provided interfaces : getPowerH1, setOnOffH1, setPowerH1
 * Required interfaces : 
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 145830 131456 172501 142952
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

void heater1_startup(void);

/* Provided interfaces */
void heater1_PI_getPowerH1( asn1SccHeater_Data * );
void heater1_PI_setOnOffH1( const asn1SccHeater_On_Off * );
void heater1_PI_setPowerH1( const asn1SccT_Float * );

/* Required interfaces */



#ifdef __cplusplus
}
#endif

