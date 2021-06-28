
/* Header file for function PT1000Sensors in CPP language
 * Generated by TASTE on 2021-06-28 13:00:54
 * Context Parameters present : YES
 * Provided interfaces : readTemps, stop
 * Required interfaces : 
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 176834 177555 203757 185192
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

void pt1000sensors_startup(void);

/* Provided interfaces */
void pt1000sensors_PI_readTemps( asn1SccPT1000s_All_Data * );
void pt1000sensors_PI_stop( );

/* Required interfaces */



#ifdef __cplusplus
}
#endif

