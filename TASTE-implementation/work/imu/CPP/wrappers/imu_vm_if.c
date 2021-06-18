/* Body file for function IMU
 * Generated by TASTE on 2021-06-18 13:10:29
 * Provided interfaces : readIMUdata
 * Required interfaces : 
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 176000 161579 203431 170311
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
void imu_readIMUdata
      (char *OUT_all_data, size_t *OUT_all_data_len)

{

   static asn1SccIMU_All_Data OUT_ALL_DATA;
#ifdef __unix__
   asn1SccIMU_All_Data_Initialize(&OUT_ALL_DATA);
#endif

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void imu_PI_readIMUdata
      (asn1SccIMU_All_Data *);




   // Call user code
   imu_PI_readIMUdata (&OUT_ALL_DATA);

   *OUT_all_data_len = Encode_NATIVE_IMU_All_Data
      ((void *)OUT_all_data,
       sizeof (asn1SccIMU_All_Data),
       &OUT_ALL_DATA);
}

