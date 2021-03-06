/* Header file for function HeatTransferLab in SDL language
 * Generated by TASTE on 2021-06-14 07:57:31
 * Context Parameters present : NO
 * Provided interfaces : configureParameters, f1_timeout, f2_timeout, getCurrentMode, setCurrentMode, tick
 * Required interfaces : RESET_f1_timeout, RESET_f2_timeout, RetreiveSingleData, SET_f1_timeout, SET_f2_timeout, getTime, setOnOffH2, setPowerH2
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 159681 55746 209286 74329
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


// Function initialization - calls user startup code of all dependent functions
void init_heattransferlab(void);


/* Provided interfaces */
void heattransferlab_configureParameters
      (const char *IN_configuration, size_t IN_configuration_len);

void heattransferlab_f1_timeout(void);
void heattransferlab_f2_timeout(void);
void heattransferlab_getCurrentMode
      (char *OUT_current_state, size_t *OUT_current_state_len);

void heattransferlab_setCurrentMode
      (const char *IN_current_state, size_t IN_current_state_len);

void heattransferlab_tick(void);


#ifdef __cplusplus
}
#endif

