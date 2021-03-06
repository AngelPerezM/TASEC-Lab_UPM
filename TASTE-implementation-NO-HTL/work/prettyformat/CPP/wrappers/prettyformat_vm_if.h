/* Header file for function PrettyFormat in CPP language
 * Generated by TASTE on 2021-06-29 11:21:06
 * Context Parameters present : NO
 * Provided interfaces : tm
 * Required interfaces : Attitude_Data, Environmental_Data, HTL_Data
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 62280 52618 89419 71439
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

#include "prettyformat.h"

// Function initialization - calls user startup code of all dependent functions
void init_prettyformat(void);


/* Provided interfaces */
void prettyformat_tm
      (const char *IN_tm, size_t IN_tm_len);


#ifdef __cplusplus
}
#endif

