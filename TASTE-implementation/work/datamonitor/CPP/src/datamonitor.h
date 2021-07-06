
/* Header file for function DataMonitor in CPP language
 * Generated by TASTE on 2021-07-06 13:57:47
 * Context Parameters present : NO
 * Provided interfaces : ReadData, stop_DM
 * Required interfaces : InsertCompleteGroup, getPowerH1, getPowerH2, getTime, getTotalPulses, readPressureAndTemp, stopAnemo, stopH1, stopH2, stopPSs
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 217907 119914 249066 161413
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

void datamonitor_startup(void);

/* Provided interfaces */
void datamonitor_PI_ReadData( );
void datamonitor_PI_stop_DM( );

/* Required interfaces */
extern void datamonitor_RI_InsertCompleteGroup( const asn1SccOBSW_DP_Data * );
extern void datamonitor_RI_getPowerH1( asn1SccHeater_Data * );
extern void datamonitor_RI_getPowerH2( asn1SccHeater_Data * );
extern void datamonitor_RI_getTime( asn1SccT_Double *, asn1SccT_Double * );
extern void datamonitor_RI_getTotalPulses( asn1SccT_UInt64 * );
extern void datamonitor_RI_readPressureAndTemp( asn1SccPS_All_Data *, asn1SccPS_All_Data * );
extern void datamonitor_RI_stopAnemo( );
extern void datamonitor_RI_stopH1( );
extern void datamonitor_RI_stopH2( );
extern void datamonitor_RI_stopPSs( );


#ifdef __cplusplus
}
#endif

