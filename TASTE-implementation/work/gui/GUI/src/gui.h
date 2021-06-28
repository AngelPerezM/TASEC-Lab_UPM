
/* Header file for function GUI in GUI language
 * Generated by TASTE on 2021-06-28 15:24:34
 * Context Parameters present : NO
 * Provided interfaces : Attitude_Data, Environmental_Data, HTL_Data
 * Required interfaces : send_telecommand, setCurrentMode
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 63058 80659 89364 100732
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

void gui_startup(void);

/* Provided interfaces */
void gui_PI_Attitude_Data( const asn1SccATT_GUI * );
void gui_PI_Environmental_Data( const asn1SccENV_GUI * );
void gui_PI_HTL_Data( const asn1SccHTL_GUI * );

/* Required interfaces */
extern void gui_RI_send_telecommand( const asn1SccTC * );
extern void gui_RI_setCurrentMode( const asn1SccHTL_State * );


#ifdef __cplusplus
}
#endif

