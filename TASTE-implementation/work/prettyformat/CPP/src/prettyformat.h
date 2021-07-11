
/* Header file for function PrettyFormat in CPP language
 * Generated by TASTE on 2021-07-11 20:23:12
 * Context Parameters present : NO
 * Provided interfaces : tm
 * Required interfaces : Attitude_Data, Environmental_Data, HTL_Data
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 62280 52618 89419 71439
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

void prettyformat_startup(void);

/* Provided interfaces */
void prettyformat_PI_tm( const asn1SccTM * );

/* Required interfaces */
extern void prettyformat_RI_Attitude_Data( const asn1SccATT_GUI * );
extern void prettyformat_RI_Environmental_Data( const asn1SccENV_GUI * );
extern void prettyformat_RI_HTL_Data( const asn1SccHTL_GUI * );


#ifdef __cplusplus
}
#endif

