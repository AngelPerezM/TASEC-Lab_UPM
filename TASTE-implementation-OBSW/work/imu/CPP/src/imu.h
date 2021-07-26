
/* Header file for function IMU in CPP language
 * Generated by TASTE on 2021-07-06 13:57:47
 * Context Parameters present : NO
 * Provided interfaces : readAccelAndGyro, readIMUdata, readMgt, readTemp, stop
 * Required interfaces : 
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 176000 162866 203431 170311
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
void imu_PI_readAccelAndGyro( asn1SccACC_MilliG_Data *, asn1SccACC_Raw_Data *, asn1SccContent_Validity *, asn1SccGYRO_MilliDPS_Data *, asn1SccGYRO_Raw_Data *, asn1SccContent_Validity * );
void imu_PI_readIMUdata( asn1SccIMU_All_Data * );
void imu_PI_readMgt( asn1SccMGT_MilliGauss_Data *, asn1SccMGT_Raw_Data *, asn1SccContent_Validity * );
void imu_PI_readTemp( asn1SccT_Float *, asn1SccT_Int16 *, asn1SccContent_Validity * );
void imu_PI_stop( );

/* Required interfaces */



#ifdef __cplusplus
}
#endif
