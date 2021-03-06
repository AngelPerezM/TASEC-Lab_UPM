/* Header file for function TC in CPP language
 * Generated by TASTE on 2021-06-29 11:21:07
 * Context Parameters present : NO
 * Provided interfaces : tc
 * Required interfaces : StopSystem, configureParameters, setPowerH1, setPowerH2
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 126771 68013 152282 83447
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

#include "tc.h"

// Function initialization - calls user startup code of all dependent functions
void init_tc(void);


/* Provided interfaces */
void tc_tc
      (const char *IN_tc, size_t IN_tc_len);


#ifdef __cplusplus
}
#endif

