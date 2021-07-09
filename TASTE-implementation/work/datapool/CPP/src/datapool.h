
/* Header file for function DataPool in CPP language
 * Generated by TASTE on 2021-07-08 21:13:24
 * Context Parameters present : YES
 * Provided interfaces : InsertCompleteGroup, RecordHTLParams, RecoverHTLParams, RetreiveAllData, RetreiveSingleData, checkValidity, getTime, saveInNVMem
 * Required interfaces : notifyIMU, notifyTempChanged
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
void datapool_PI_RecordHTLParams( const asn1SccHTL_State *, const asn1SccT_Double *, const asn1SccT_Double * );
void datapool_PI_RecoverHTLParams( asn1SccHTL_State *, asn1SccT_Double *, asn1SccT_Double * );
void datapool_PI_RetreiveAllData( asn1SccOBSW_DP_Data * );
void datapool_PI_RetreiveSingleData( const asn1SccOBSW_DP_Filter *, asn1SccOBSW_DP_SingleData * );
void datapool_PI_checkValidity( );
void datapool_PI_getTime( asn1SccT_Double *, asn1SccT_Double * );
void datapool_PI_saveInNVMem( );

/* Required interfaces */
extern void datapool_RI_notifyIMU( const asn1SccIMU_Queue * );
extern void datapool_RI_notifyTempChanged( const asn1SccT_Float * );


#ifdef __cplusplus
}
#endif

