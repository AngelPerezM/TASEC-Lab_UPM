/* Header file for function Heater1 in CPP language
 * Generated by TASTE on 2021-06-18 18:39:04
 * Context Parameters present : YES
 * Provided interfaces : getPowerH1, setOnOffH1, setPowerH1
 * Required interfaces : 
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 145830 131456 172501 142952
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

#include "heater1.h"

// Function initialization - calls user startup code of all dependent functions
void init_heater1(void);


/* Provided interfaces */
void heater1_getPowerH1
      (char *OUT_heater_data, size_t *OUT_heater_data_len);

void heater1_setOnOffH1
      (const char *IN_command, size_t IN_command_len);

void heater1_setPowerH1
      (const char *IN_power, size_t IN_power_len);


#ifdef __cplusplus
}
#endif

