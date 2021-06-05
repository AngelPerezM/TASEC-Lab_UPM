/* Header file for function I2CBusReader in CPP language
 * Generated by TASTE on 2021-06-05 19:03:24
 * Context Parameters present : NO
 * Provided interfaces : ReadData
 * Required interfaces : InsertCompleteGroup, getTime, readIMUdata, readPT1000Temps, readTC74Temps
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 218092 162474 248812 185351
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

#include "i2cbusreader.h"

// Function initialization - calls user startup code of all dependent functions
void init_i2cbusreader(void);


/* Provided interfaces */
void i2cbusreader_ReadData(void);


#ifdef __cplusplus
}
#endif

