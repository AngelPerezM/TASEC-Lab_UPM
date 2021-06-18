
/* Header file for function TC in CPP language
 * Generated by TASTE on 2021-06-18 14:58:11
 * Context Parameters present : NO
 * Provided interfaces : tc
 * Required interfaces : configureParameters, setPowerH1, setPowerH2
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 126299 67698 151810 83132
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

void tc_startup(void);

/* Provided interfaces */
void tc_PI_tc( const asn1SccTC * );

/* Required interfaces */
extern void tc_RI_configureParameters( const asn1SccHTL_Config * );
extern void tc_RI_setPowerH1( const asn1SccT_Float * );
extern void tc_RI_setPowerH2( const asn1SccT_Float * );


#ifdef __cplusplus
}
#endif

