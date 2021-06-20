
/* Header file for function PressureSensors in CPP language
 * Generated by TASTE on 2021-06-18 14:58:11
 * Context Parameters present : YES
 * Provided interfaces : readPressureAndTemp
 * Required interfaces : 
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 175029 124808 204231 135044
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

void pressuresensors_startup(void);

/* Provided interfaces */
void pressuresensors_PI_readPressureAndTemp( asn1SccPS_All_Data *, asn1SccPS_All_Data * );

/* Required interfaces */



#ifdef __cplusplus
}
#endif

