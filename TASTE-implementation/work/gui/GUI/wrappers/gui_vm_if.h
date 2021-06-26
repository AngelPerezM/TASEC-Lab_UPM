/* Header file for function GUI in GUI language
 * Generated by TASTE on 2021-06-21 01:56:25
 * Context Parameters present : NO
 * Provided interfaces : Attitude_Data, Environmental_Data, HTL_Data, Poll
 * Required interfaces : send_telecommand, setCurrentMode
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 63058 80659 89364 100732
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

#include "gui.h"

// Function initialization - calls user startup code of all dependent functions
void init_gui(void);


/* Provided interfaces */
void gui_Attitude_Data
      (const char *IN_attitude_lab_data, size_t IN_attitude_lab_data_len);

void gui_Environmental_Data
      (const char *IN_env_lab_data, size_t IN_env_lab_data_len);

void gui_HTL_Data
      (const char *IN_htl_data, size_t IN_htl_data_len);

void gui_Poll(void);


#ifdef __cplusplus
}
#endif

