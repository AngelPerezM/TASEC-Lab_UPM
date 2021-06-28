
/* Header file for function TC74Sensors in CPP language
 * Generated by TASTE on 2021-06-28 13:00:54
 * Context Parameters present : YES
 * Provided interfaces : readTempsCelsius, stop
 * Required interfaces : 
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 144878 166341 171680 178732
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

void tc74sensors_startup(void);

/* Provided interfaces */
void tc74sensors_PI_readTempsCelsius( asn1SccTC74s_All_Data * );
void tc74sensors_PI_stop( );

/* Required interfaces */



#ifdef __cplusplus
}
#endif

