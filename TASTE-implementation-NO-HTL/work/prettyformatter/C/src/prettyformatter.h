
/* Header file for function PrettyFormatter in C language
 * Generated by TASTE on 2021-05-21 15:43:53
 * Context Parameters present : NO
 * Provided interfaces : sendTM
 * Required interfaces : printAllData
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 250580 83853 286503 106642
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

void prettyformatter_startup(void);

/* Provided interfaces */
void prettyformatter_PI_sendTM( void );

/* Required interfaces */
extern void prettyformatter_RI_printAllData( const asn1SccOBSW_DP_Data * );


#ifdef __cplusplus
}
#endif