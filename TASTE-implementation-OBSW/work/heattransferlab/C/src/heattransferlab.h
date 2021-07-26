
/* Header file for function HeatTransferLab in C language
 * Generated by TASTE on 2021-06-14 14:34:35
 * Context Parameters present : NO
 * Provided interfaces : configureParameters, getCurrentMode, setCurrentMode, tick
 * Required interfaces : getTime, setPowerH2
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 222060 53729 262688 74201
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

void heattransferlab_startup(void);

/* Provided interfaces */
void heattransferlab_PI_configureParameters( const asn1SccHTL_Config * );
void heattransferlab_PI_getCurrentMode( asn1SccHTL_State * );
void heattransferlab_PI_setCurrentMode( const asn1SccHTL_State * );
void heattransferlab_PI_tick( void );

/* Required interfaces */
extern void heattransferlab_RI_getTime( asn1SccT_Double *, asn1SccT_Double * );
extern void heattransferlab_RI_setPowerH2( const asn1SccT_Float * );


#ifdef __cplusplus
}
#endif