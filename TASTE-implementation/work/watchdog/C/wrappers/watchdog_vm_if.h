/* Header file for function Watchdog in C language
 * Generated by TASTE on 2021-07-08 17:30:09
 * Context Parameters present : YES
 * Provided interfaces : KickTheDog, stop
 * Required interfaces : 
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 192975 65036 214597 70512
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

/* The purpose of this file is to provide a wrapper around the user code,
 * with a single interface that is independent of the implementation language
 * of the function. The parameters of each PI are blackboxes encoded
 * in the form specified in the interface view (Native, uPER, or ACN)
*/

#pragma once
#if defined(__unix__) || defined (__MSP430__)
   #include <stdlib.h>
   #include <stdio.h>
#else
   typedef unsigned size_t;
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "watchdog.h"

// Function initialization - calls user startup code of all dependent functions
void init_watchdog(void);


/* Provided interfaces */
void watchdog_KickTheDog(void);
void watchdog_stop(void);


#ifdef __cplusplus
}
#endif

