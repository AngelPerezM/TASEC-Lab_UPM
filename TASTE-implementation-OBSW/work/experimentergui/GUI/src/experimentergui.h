
/* Header file for function ExperimenterGUI in GUI language
 * Generated by TASTE on 2021-05-17 14:13:57
 * Context Parameters present : NO
 * Provided interfaces : printAllData
 * Required interfaces : 
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 222768 51546 249792 105399
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

#pragma once

#include "dataview-uniq.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __unix__
   #include <stdlib.h>
   #include <stdio.h>
#endif

void experimentergui_startup(void);

/* Provided interfaces */
void experimentergui_PI_printAllData( const asn1SccOBSW_DP_Data * );

/* Required interfaces */



#ifdef __cplusplus
}
#endif

