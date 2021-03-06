/* Body file for function IMU
 * Generated by TASTE on 2021-07-13 16:37:57
 * Provided interfaces : readAccel, readGyro, readMgt, readTemp, stop
 * Required interfaces : 
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 176000 162866 203431 171632
 * Timers              : 
 */
#include "imu_vm_if.h"
#include "C_ASN1_Types.h"
#ifdef __unix__
   #include <stdio.h>
#endif




unsigned imu_initialized = 0;
void init_imu(void)
{
   if (0 == imu_initialized) {
      imu_initialized = 1;
      // Call user code startup function
      extern void imu_startup(void);
      imu_startup();
#ifdef __unix__
      puts ("[TASTE] Initialization completed for function IMU");
#endif
      imu_initialized = 2;
   }
}
void imu_readAccel
      (char *OUT_acc_g, size_t *OUT_acc_g_len,
       char *OUT_acc_raw, size_t *OUT_acc_raw_len,
       char *OUT_acc_validity, size_t *OUT_acc_validity_len)

{

   static asn1SccACC_MilliG_Data OUT_ACC_G;
#ifdef __unix__
   asn1SccACC_MilliG_Data_Initialize(&OUT_ACC_G);
#endif
   static asn1SccACC_Raw_Data OUT_ACC_RAW;
#ifdef __unix__
   asn1SccACC_Raw_Data_Initialize(&OUT_ACC_RAW);
#endif
   static asn1SccContent_Validity OUT_ACC_VALIDITY;
#ifdef __unix__
   asn1SccContent_Validity_Initialize(&OUT_ACC_VALIDITY);
#endif

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void imu_PI_readAccel
      (asn1SccACC_MilliG_Data *,
       asn1SccACC_Raw_Data *,
       asn1SccContent_Validity *);




   // Call user code
   imu_PI_readAccel (&OUT_ACC_G, &OUT_ACC_RAW, &OUT_ACC_VALIDITY);

   *OUT_acc_g_len = Encode_NATIVE_ACC_MilliG_Data
      ((void *)OUT_acc_g,
       sizeof (asn1SccACC_MilliG_Data),
       &OUT_ACC_G);
   *OUT_acc_raw_len = Encode_NATIVE_ACC_Raw_Data
      ((void *)OUT_acc_raw,
       sizeof (asn1SccACC_Raw_Data),
       &OUT_ACC_RAW);
   *OUT_acc_validity_len = Encode_NATIVE_Content_Validity
      ((void *)OUT_acc_validity,
       sizeof (asn1SccContent_Validity),
       &OUT_ACC_VALIDITY);
}
void imu_readGyro
      (char *OUT_gyro_mdps, size_t *OUT_gyro_mdps_len,
       char *OUT_gyro_raw, size_t *OUT_gyro_raw_len,
       char *OUT_gyro_validity, size_t *OUT_gyro_validity_len)

{

   static asn1SccGYRO_MilliDPS_Data OUT_GYRO_MDPS;
#ifdef __unix__
   asn1SccGYRO_MilliDPS_Data_Initialize(&OUT_GYRO_MDPS);
#endif
   static asn1SccGYRO_Raw_Data OUT_GYRO_RAW;
#ifdef __unix__
   asn1SccGYRO_Raw_Data_Initialize(&OUT_GYRO_RAW);
#endif
   static asn1SccContent_Validity OUT_GYRO_VALIDITY;
#ifdef __unix__
   asn1SccContent_Validity_Initialize(&OUT_GYRO_VALIDITY);
#endif

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void imu_PI_readGyro
      (asn1SccGYRO_MilliDPS_Data *,
       asn1SccGYRO_Raw_Data *,
       asn1SccContent_Validity *);




   // Call user code
   imu_PI_readGyro (&OUT_GYRO_MDPS, &OUT_GYRO_RAW, &OUT_GYRO_VALIDITY);

   *OUT_gyro_mdps_len = Encode_NATIVE_GYRO_MilliDPS_Data
      ((void *)OUT_gyro_mdps,
       sizeof (asn1SccGYRO_MilliDPS_Data),
       &OUT_GYRO_MDPS);
   *OUT_gyro_raw_len = Encode_NATIVE_GYRO_Raw_Data
      ((void *)OUT_gyro_raw,
       sizeof (asn1SccGYRO_Raw_Data),
       &OUT_GYRO_RAW);
   *OUT_gyro_validity_len = Encode_NATIVE_Content_Validity
      ((void *)OUT_gyro_validity,
       sizeof (asn1SccContent_Validity),
       &OUT_GYRO_VALIDITY);
}
void imu_readMgt
      (char *OUT_mgt_mgauss, size_t *OUT_mgt_mgauss_len,
       char *OUT_mgt_raw, size_t *OUT_mgt_raw_len,
       char *OUT_validity, size_t *OUT_validity_len)

{

   static asn1SccMGT_MilliGauss_Data OUT_MGT_MGAUSS;
#ifdef __unix__
   asn1SccMGT_MilliGauss_Data_Initialize(&OUT_MGT_MGAUSS);
#endif
   static asn1SccMGT_Raw_Data OUT_MGT_RAW;
#ifdef __unix__
   asn1SccMGT_Raw_Data_Initialize(&OUT_MGT_RAW);
#endif
   static asn1SccContent_Validity OUT_VALIDITY;
#ifdef __unix__
   asn1SccContent_Validity_Initialize(&OUT_VALIDITY);
#endif

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void imu_PI_readMgt
      (asn1SccMGT_MilliGauss_Data *,
       asn1SccMGT_Raw_Data *,
       asn1SccContent_Validity *);




   // Call user code
   imu_PI_readMgt (&OUT_MGT_MGAUSS, &OUT_MGT_RAW, &OUT_VALIDITY);

   *OUT_mgt_mgauss_len = Encode_NATIVE_MGT_MilliGauss_Data
      ((void *)OUT_mgt_mgauss,
       sizeof (asn1SccMGT_MilliGauss_Data),
       &OUT_MGT_MGAUSS);
   *OUT_mgt_raw_len = Encode_NATIVE_MGT_Raw_Data
      ((void *)OUT_mgt_raw,
       sizeof (asn1SccMGT_Raw_Data),
       &OUT_MGT_RAW);
   *OUT_validity_len = Encode_NATIVE_Content_Validity
      ((void *)OUT_validity,
       sizeof (asn1SccContent_Validity),
       &OUT_VALIDITY);
}
void imu_readTemp
      (char *OUT_temp_celsius, size_t *OUT_temp_celsius_len,
       char *OUT_temp_raw, size_t *OUT_temp_raw_len,
       char *OUT_validity, size_t *OUT_validity_len)

{

   static asn1SccT_Float OUT_TEMP_CELSIUS;
#ifdef __unix__
   asn1SccT_Float_Initialize(&OUT_TEMP_CELSIUS);
#endif
   static asn1SccT_Int16 OUT_TEMP_RAW;
#ifdef __unix__
   asn1SccT_Int16_Initialize(&OUT_TEMP_RAW);
#endif
   static asn1SccContent_Validity OUT_VALIDITY;
#ifdef __unix__
   asn1SccContent_Validity_Initialize(&OUT_VALIDITY);
#endif

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void imu_PI_readTemp
      (asn1SccT_Float *,
       asn1SccT_Int16 *,
       asn1SccContent_Validity *);




   // Call user code
   imu_PI_readTemp (&OUT_TEMP_CELSIUS, &OUT_TEMP_RAW, &OUT_VALIDITY);

   *OUT_temp_celsius_len = Encode_NATIVE_T_Float
      ((void *)OUT_temp_celsius,
       sizeof (asn1SccT_Float),
       &OUT_TEMP_CELSIUS);
   *OUT_temp_raw_len = Encode_NATIVE_T_Int16
      ((void *)OUT_temp_raw,
       sizeof (asn1SccT_Int16),
       &OUT_TEMP_RAW);
   *OUT_validity_len = Encode_NATIVE_Content_Validity
      ((void *)OUT_validity,
       sizeof (asn1SccContent_Validity),
       &OUT_VALIDITY);
}
void imu_stop()
{
   //  Directly call user code, no parameters to pass
   extern void imu_PI_stop(void);
   imu_PI_stop();
   // puts ("imu_stop called");
}

