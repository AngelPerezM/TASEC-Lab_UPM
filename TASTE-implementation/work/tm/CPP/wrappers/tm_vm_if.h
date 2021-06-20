/* Header file for function TM in CPP language
 * Generated by TASTE on 2021-06-18 18:39:04
 * Context Parameters present : NO
 * Provided interfaces : HK_tick
 * Required interfaces : RetreiveAllData, getCurrentMode, tm
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 126239 46830 151739 64994
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

#include "tm.h"

// Function initialization - calls user startup code of all dependent functions
void init_tm(void);


/* Provided interfaces */
void tm_HK_tick(void);


#ifdef __cplusplus
}
#endif

