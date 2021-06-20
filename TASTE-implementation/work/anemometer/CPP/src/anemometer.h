
/* Header file for function Anemometer in CPP language
 * Generated by TASTE on 2021-06-18 18:39:03
 * Context Parameters present : YES
 * Provided interfaces : getTotalPulses
 * Required interfaces : 
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 175029 143576 203645 153278
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

void anemometer_startup(void);

/* Provided interfaces */
void anemometer_PI_getTotalPulses( asn1SccT_UInt64 * );

/* Required interfaces */



#ifdef __cplusplus
}
#endif

