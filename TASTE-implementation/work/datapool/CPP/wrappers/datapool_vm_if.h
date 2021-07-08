/* Header file for function DataPool in CPP language
 * Generated by TASTE on 2021-07-08 17:30:09
 * Context Parameters present : YES
 * Provided interfaces : InsertCompleteGroup, RecordHTLParams, RecoverHTLParams, RetreiveAllData, RetreiveSingleData, checkValidity, getTime, saveInNVMem
 * Required interfaces : notifyIMU, notifyTempChanged
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 128343 90099 266922 105375
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

#include "datapool.h"

// Function initialization - calls user startup code of all dependent functions
void init_datapool(void);


/* Provided interfaces */
void datapool_InsertCompleteGroup
      (const char *IN_alldata, size_t IN_alldata_len);

void datapool_RecordHTLParams
      (const char *IN_htl_state, size_t IN_htl_state_len,
       const char *IN_f1_max_time, size_t IN_f1_max_time_len,
       const char *IN_f2_max_time, size_t IN_f2_max_time_len);

void datapool_RecoverHTLParams
      (char *OUT_htl_state, size_t *OUT_htl_state_len,
       char *OUT_f1_max_time, size_t *OUT_f1_max_time_len,
       char *OUT_f2_max_time, size_t *OUT_f2_max_time_len);

void datapool_RetreiveAllData
      (char *OUT_alldata, size_t *OUT_alldata_len);

void datapool_RetreiveSingleData
      (const char *IN_filter, size_t IN_filter_len,
       char *OUT_single_data, size_t *OUT_single_data_len);

void datapool_checkValidity(void);
void datapool_getTime
      (char *OUT_gps_time, size_t *OUT_gps_time_len,
       char *OUT_mission_time, size_t *OUT_mission_time_len);

void datapool_saveInNVMem(void);


#ifdef __cplusplus
}
#endif

