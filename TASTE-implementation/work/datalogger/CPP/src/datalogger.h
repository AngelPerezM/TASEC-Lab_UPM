
/* Header file for function DataLogger in CPP language
 * Generated by TASTE on 2021-06-28 15:24:34
 * Context Parameters present : NO
 * Provided interfaces : RecordAllData, stop
 * Required interfaces : RetreiveAllData, getCurrentMode
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 161259 63041 186324 73791
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

void datalogger_startup(void);

/* Provided interfaces */
void datalogger_PI_RecordAllData( );
void datalogger_PI_stop( );

/* Required interfaces */
extern void datalogger_RI_RetreiveAllData( asn1SccOBSW_DP_Data * );
extern void datalogger_RI_getCurrentMode( asn1SccHTL_State * );


#ifdef __cplusplus
}
#endif

