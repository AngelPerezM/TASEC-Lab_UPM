
/* Header file for function TM in CPP language
 * Generated by TASTE on 2021-07-06 13:57:48
 * Context Parameters present : NO
 * Provided interfaces : HK_tick
 * Required interfaces : RetreiveAllData, getCurrentMode, tm
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 126239 46830 151739 64994
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

void tm_startup(void);

/* Provided interfaces */
void tm_PI_HK_tick( );

/* Required interfaces */
extern void tm_RI_RetreiveAllData( asn1SccOBSW_DP_Data * );
extern void tm_RI_getCurrentMode( asn1SccHTL_State * );
extern void tm_RI_tm( const asn1SccTM * );


#ifdef __cplusplus
}
#endif
