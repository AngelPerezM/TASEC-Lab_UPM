/* Header file for function DataMonitor in CPP language
 * Generated by TASTE on 2021-06-28 13:00:54
 * Context Parameters present : NO
 * Provided interfaces : ReadData, stop_DM
 * Required interfaces : InsertCompleteGroup, getPowerH1, getPowerH2, getTime, getTotalPulses, readPressureAndTemp, stopAnemo, stopH1, stopH2, stopPSs
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 217907 119914 249066 161413
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

#include "datamonitor.h"

// Function initialization - calls user startup code of all dependent functions
void init_datamonitor(void);


/* Provided interfaces */
void datamonitor_ReadData(void);
void datamonitor_stop_DM(void);


#ifdef __cplusplus
}
#endif

