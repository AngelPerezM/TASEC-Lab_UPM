
/* Header file for function IMU in CPP language
 * Generated by TASTE on 2021-06-28 13:00:54
 * Context Parameters present : NO
 * Provided interfaces : readIMUdata, stop
 * Required interfaces : 
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 176000 161579 203431 170311
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

void imu_startup(void);

/* Provided interfaces */
void imu_PI_readIMUdata( asn1SccIMU_All_Data * );
void imu_PI_stop( );

/* Required interfaces */



#ifdef __cplusplus
}
#endif

