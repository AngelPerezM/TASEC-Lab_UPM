
/* Header file for function GPSReader in CPP language
 * Generated by TASTE on 2021-07-05 14:24:56
 * Context Parameters present : YES
 * Provided interfaces : readGPSData
 * Required interfaces : InsertCompleteGroup, getTime
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 144249 111993 172558 123450
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

void gpsreader_startup(void);

/* Provided interfaces */
void gpsreader_PI_readGPSData( );

/* Required interfaces */
extern void gpsreader_RI_InsertCompleteGroup( const asn1SccOBSW_DP_Data * );
extern void gpsreader_RI_getTime( asn1SccT_Double *, asn1SccT_Double * );


#ifdef __cplusplus
}
#endif

