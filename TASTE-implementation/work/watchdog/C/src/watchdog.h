
/* Header file for function Watchdog in C language
 * Generated by TASTE on 2021-07-13 16:37:57
 * Context Parameters present : YES
 * Provided interfaces : KickTheDog, stop
 * Required interfaces : 
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 192975 65036 214597 70512
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
void watchdog_PI_KickTheDog( void );
void watchdog_PI_stop( void );

/* Required interfaces */



#ifdef __cplusplus
}
#endif
