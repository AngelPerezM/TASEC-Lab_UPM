/* Header file for function PressureSensors in CPP language
 * Generated by TASTE on 2021-06-18 14:58:12
 * Context Parameters present : YES
 * Provided interfaces : readPressureAndTemp
 * Required interfaces : 
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 175029 124808 204231 135044
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

#include "pressuresensors.h"

// Function initialization - calls user startup code of all dependent functions
void init_pressuresensors(void);


/* Provided interfaces */
void pressuresensors_readPressureAndTemp
      (char *OUT_ps1_data, size_t *OUT_ps1_data_len,
       char *OUT_ps2_data, size_t *OUT_ps2_data_len);


#ifdef __cplusplus
}
#endif

