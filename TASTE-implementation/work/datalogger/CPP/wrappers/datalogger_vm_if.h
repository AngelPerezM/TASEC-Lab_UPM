/* Header file for function DataLogger in CPP language
 * Generated by TASTE on 2021-06-18 18:39:04
 * Context Parameters present : NO
 * Provided interfaces : RecordAllData
 * Required interfaces : RetreiveAllData, getCurrentMode
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 161259 63041 186324 73791
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

#include "datalogger.h"

// Function initialization - calls user startup code of all dependent functions
void init_datalogger(void);


/* Provided interfaces */
void datalogger_RecordAllData(void);


#ifdef __cplusplus
}
#endif

