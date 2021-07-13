/* Header file for function TC74Sensors in CPP language
 * Generated by TASTE on 2021-07-13 16:37:57
 * Context Parameters present : YES
 * Provided interfaces : readTempsCelsius, stop
 * Required interfaces : 
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 144878 166341 171680 178732
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

#include "tc74sensors.h"

// Function initialization - calls user startup code of all dependent functions
void init_tc74sensors(void);


/* Provided interfaces */
void tc74sensors_readTempsCelsius
      (char *OUT_all_tc74s_data, size_t *OUT_all_tc74s_data_len);

void tc74sensors_stop(void);


#ifdef __cplusplus
}
#endif

