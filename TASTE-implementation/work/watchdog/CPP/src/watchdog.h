
/* Header file for function Watchdog in CPP language
 * Generated by TASTE on 2021-07-07 13:37:32
 * Context Parameters present : NO
 * Provided interfaces : KickTheDog
 * Required interfaces : 
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 193046 62860 216706 68336
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

void watchdog_startup(void);

/* Provided interfaces */
void watchdog_PI_KickTheDog( );

/* Required interfaces */



#ifdef __cplusplus
}
#endif

