/* Header file for function IMU in CPP language
 * Generated by TASTE on 2021-07-13 16:37:57
 * Context Parameters present : NO
 * Provided interfaces : readAccel, readGyro, readMgt, readTemp, stop
 * Required interfaces : 
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 176000 162866 203431 171632
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

#include "imu.h"

// Function initialization - calls user startup code of all dependent functions
void init_imu(void);


/* Provided interfaces */
void imu_readAccel
      (char *OUT_acc_g, size_t *OUT_acc_g_len,
       char *OUT_acc_raw, size_t *OUT_acc_raw_len,
       char *OUT_acc_validity, size_t *OUT_acc_validity_len);

void imu_readGyro
      (char *OUT_gyro_mdps, size_t *OUT_gyro_mdps_len,
       char *OUT_gyro_raw, size_t *OUT_gyro_raw_len,
       char *OUT_gyro_validity, size_t *OUT_gyro_validity_len);

void imu_readMgt
      (char *OUT_mgt_mgauss, size_t *OUT_mgt_mgauss_len,
       char *OUT_mgt_raw, size_t *OUT_mgt_raw_len,
       char *OUT_validity, size_t *OUT_validity_len);

void imu_readTemp
      (char *OUT_temp_celsius, size_t *OUT_temp_celsius_len,
       char *OUT_temp_raw, size_t *OUT_temp_raw_len,
       char *OUT_validity, size_t *OUT_validity_len);

void imu_stop(void);


#ifdef __cplusplus
}
#endif

