/* Body file for function DataPool
 * Generated by TASTE on 2021-06-29 11:21:06
 * Provided interfaces : InsertCompleteGroup, RetreiveAllData, RetreiveSingleData, checkValidity, getTime, saveInNVMem
 * Required interfaces : notifyTempChanged
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 128343 90099 266922 105375
 * Timers              : 
 */
#include "datapool_vm_if.h"
#include "C_ASN1_Types.h"
#ifdef __unix__
   #include <stdio.h>
#endif




unsigned datapool_initialized = 0;
void init_datapool(void)
{
   if (0 == datapool_initialized) {
      datapool_initialized = 1;
      // Call user code startup function
      extern void datapool_startup(void);
      datapool_startup();
#ifdef __unix__
      puts ("[TASTE] Initialization completed for function DataPool");
#endif
      datapool_initialized = 2;
   }
}
void datapool_InsertCompleteGroup
      (const char *IN_alldata, size_t IN_alldata_len)

{

   static asn1SccOBSW_DP_Data IN_ALLDATA;
#ifdef __unix__
   asn1SccOBSW_DP_Data_Initialize(&IN_ALLDATA);
#endif
   if (0 != Decode_NATIVE_OBSW_DP_Data (&IN_ALLDATA, (void *)IN_alldata, IN_alldata_len)) {
      #ifdef __unix__
         puts("Error decoding OBSW-DP-Data in function DataPool_InsertCompleteGroup");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void datapool_PI_InsertCompleteGroup
      (const asn1SccOBSW_DP_Data *);




   // Call user code
   datapool_PI_InsertCompleteGroup (&IN_ALLDATA);

}
void datapool_RetreiveAllData
      (char *OUT_alldata, size_t *OUT_alldata_len)

{

   static asn1SccOBSW_DP_Data OUT_ALLDATA;
#ifdef __unix__
   asn1SccOBSW_DP_Data_Initialize(&OUT_ALLDATA);
#endif

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void datapool_PI_RetreiveAllData
      (asn1SccOBSW_DP_Data *);




   // Call user code
   datapool_PI_RetreiveAllData (&OUT_ALLDATA);

   *OUT_alldata_len = Encode_NATIVE_OBSW_DP_Data
      ((void *)OUT_alldata,
       sizeof (asn1SccOBSW_DP_Data),
       &OUT_ALLDATA);
}
void datapool_RetreiveSingleData
      (const char *IN_filter, size_t IN_filter_len,
       char *OUT_single_data, size_t *OUT_single_data_len)

{

   static asn1SccOBSW_DP_Filter IN_FILTER;
#ifdef __unix__
   asn1SccOBSW_DP_Filter_Initialize(&IN_FILTER);
#endif
   if (0 != Decode_NATIVE_OBSW_DP_Filter (&IN_FILTER, (void *)IN_filter, IN_filter_len)) {
      #ifdef __unix__
         puts("Error decoding OBSW-DP-Filter in function DataPool_RetreiveSingleData");
      #endif
      return;
   }
   static asn1SccOBSW_DP_SingleData OUT_SINGLE_DATA;
#ifdef __unix__
   asn1SccOBSW_DP_SingleData_Initialize(&OUT_SINGLE_DATA);
#endif

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void datapool_PI_RetreiveSingleData
      (const asn1SccOBSW_DP_Filter *,
       asn1SccOBSW_DP_SingleData *);




   // Call user code
   datapool_PI_RetreiveSingleData (&IN_FILTER, &OUT_SINGLE_DATA);

   *OUT_single_data_len = Encode_NATIVE_OBSW_DP_SingleData
      ((void *)OUT_single_data,
       sizeof (asn1SccOBSW_DP_SingleData),
       &OUT_SINGLE_DATA);
}
void datapool_checkValidity()
{
   //  Directly call user code, no parameters to pass
   extern void datapool_PI_checkValidity(void);
   datapool_PI_checkValidity();
   // puts ("datapool_checkvalidity called");
}
void datapool_getTime
      (char *OUT_gps_time, size_t *OUT_gps_time_len,
       char *OUT_mission_time, size_t *OUT_mission_time_len)

{

   static asn1SccT_Double OUT_GPS_TIME;
#ifdef __unix__
   asn1SccT_Double_Initialize(&OUT_GPS_TIME);
#endif
   static asn1SccT_Double OUT_MISSION_TIME;
#ifdef __unix__
   asn1SccT_Double_Initialize(&OUT_MISSION_TIME);
#endif

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void datapool_PI_getTime
      (asn1SccT_Double *,
       asn1SccT_Double *);




   // Call user code
   datapool_PI_getTime (&OUT_GPS_TIME, &OUT_MISSION_TIME);

   *OUT_gps_time_len = Encode_NATIVE_T_Double
      ((void *)OUT_gps_time,
       sizeof (asn1SccT_Double),
       &OUT_GPS_TIME);
   *OUT_mission_time_len = Encode_NATIVE_T_Double
      ((void *)OUT_mission_time,
       sizeof (asn1SccT_Double),
       &OUT_MISSION_TIME);
}
void datapool_saveInNVMem()
{
   //  Directly call user code, no parameters to pass
   extern void datapool_PI_saveInNVMem(void);
   datapool_PI_saveInNVMem();
   // puts ("datapool_saveinnvmem called");
}
