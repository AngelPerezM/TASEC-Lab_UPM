
/* Header file for function DataPool in CPP language
 * Generated by TASTE on 2021-06-05 19:03:23
 * Context Parameters present : YES
 * Provided interfaces : InsertCompleteGroup, RetreiveAllData, checkValidity, getTime
 * Required interfaces : notifyTempChanged
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 128343 90099 266922 105375
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

void datapool_startup(void);

/* Provided interfaces */
void datapool_PI_InsertCompleteGroup( const asn1SccOBSW_DP_Data * );
void datapool_PI_RetreiveAllData( asn1SccOBSW_DP_Data * );
void datapool_PI_checkValidity( );
void datapool_PI_getTime( asn1SccT_Double *, asn1SccT_Double * );

/* Required interfaces */
extern void datapool_RI_notifyTempChanged( const asn1SccT_Float * );


#ifdef __cplusplus
}
#endif

