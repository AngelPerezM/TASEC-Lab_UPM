/* Header file for function Thermostat in SDL language
 * Generated by TASTE on 2021-06-29 11:21:07
 * Context Parameters present : NO
 * Provided interfaces : notifyTempChanged
 * Required interfaces : setOnOffH1
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 193223 63463 216706 74002
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
void init_thermostat(void);


/* Provided interfaces */
void thermostat_notifyTempChanged
      (const char *IN_tempcelsius, size_t IN_tempcelsius_len);


#ifdef __cplusplus
}
#endif

