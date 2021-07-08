// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#ifdef __unix__
   #include <stdio.h>
   #include "PrintTypesAsASN1.h"
   #include "timeInMS.h"
#endif
#include "C_ASN1_Types.h"
#include "dataview-uniq.h"

extern unsigned heattransferlab_initialized;

void heattransferlab_RI_KickTheDog(void);
void heattransferlab_RI_KickTheDog(void)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to Watchdog (corresponding PI: KickTheDog)
         printf ("INNER: heattransferlab,watchdog,kickthedog,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif


   // Call Middleware interface
   extern void vm_heattransferlab_kickthedog(void);
   vm_heattransferlab_kickthedog();

}
void heattransferlab_RI_RecordHTLParams
      (const asn1SccHTL_State *IN_htl_state,
       const asn1SccT_Double  *IN_f1_max_time,
       const asn1SccT_Double  *IN_f2_max_time);
void heattransferlab_RI_RecordHTLParams
      (const asn1SccHTL_State *IN_htl_state,
       const asn1SccT_Double  *IN_f1_max_time,
       const asn1SccT_Double  *IN_f2_max_time)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1HTL_State ("INNERDATA: recordhtlparams::HTL_State::htl_state", IN_htl_state);
         PrintASN1T_Double ("INNERDATA: recordhtlparams::T_Double::f1_max_time", IN_f1_max_time);
         PrintASN1T_Double ("INNERDATA: recordhtlparams::T_Double::f2_max_time", IN_f2_max_time);
         puts(""); // add newline
         // Log message to DataPool (corresponding PI: RecordHTLParams)
         printf ("INNER: heattransferlab,datapool,recordhtlparams,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter htl_state
   static asn1SccHTL_State IN_buf_htl_state;
   int size_IN_buf_htl_state =
      Encode_NATIVE_HTL_State
        ((void *)&IN_buf_htl_state,
          sizeof(asn1SccHTL_State),
          (asn1SccHTL_State *)IN_htl_state);
   if (-1 == size_IN_buf_htl_state) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in heattransferlab_RI_RecordHTLParams, parameter htl_state");
      #endif
        /* Crash the application due to message loss */
        abort();
   }
   // Encode parameter f1_max_time
   static asn1SccT_Double IN_buf_f1_max_time;
   int size_IN_buf_f1_max_time =
      Encode_NATIVE_T_Double
        ((void *)&IN_buf_f1_max_time,
          sizeof(asn1SccT_Double),
          (asn1SccT_Double *)IN_f1_max_time);
   if (-1 == size_IN_buf_f1_max_time) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in heattransferlab_RI_RecordHTLParams, parameter f1_max_time");
      #endif
        /* Crash the application due to message loss */
        abort();
   }
   // Encode parameter f2_max_time
   static asn1SccT_Double IN_buf_f2_max_time;
   int size_IN_buf_f2_max_time =
      Encode_NATIVE_T_Double
        ((void *)&IN_buf_f2_max_time,
          sizeof(asn1SccT_Double),
          (asn1SccT_Double *)IN_f2_max_time);
   if (-1 == size_IN_buf_f2_max_time) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in heattransferlab_RI_RecordHTLParams, parameter f2_max_time");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_heattransferlab_recordhtlparams
     (void *, size_t,
      void *, size_t,
      void *, size_t);

   vm_heattransferlab_recordhtlparams
     ((void *)&IN_buf_htl_state, (size_t)size_IN_buf_htl_state,
      (void *)&IN_buf_f1_max_time, (size_t)size_IN_buf_f1_max_time,
      (void *)&IN_buf_f2_max_time, (size_t)size_IN_buf_f2_max_time);


}
void heattransferlab_RI_RecoverHTLParams
      (asn1SccHTL_State *OUT_htl_state,
       asn1SccT_Double  *OUT_f1_max_time,
       asn1SccT_Double  *OUT_f2_max_time);
void heattransferlab_RI_RecoverHTLParams
      (asn1SccHTL_State *OUT_htl_state,
       asn1SccT_Double  *OUT_f1_max_time,
       asn1SccT_Double  *OUT_f2_max_time)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to DataPool (corresponding PI: RecoverHTLParams)
         printf ("INNER: heattransferlab,datapool,recoverhtlparams,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif

   // Buffer for decoding parameter htl_state
   static asn1SccHTL_State OUT_buf_htl_state;
   size_t      size_OUT_buf_htl_state = 0;
   // Buffer for decoding parameter f1_max_time
   static asn1SccT_Double OUT_buf_f1_max_time;
   size_t      size_OUT_buf_f1_max_time = 0;
   // Buffer for decoding parameter f2_max_time
   static asn1SccT_Double OUT_buf_f2_max_time;
   size_t      size_OUT_buf_f2_max_time = 0;

   // Call Middleware interface
   extern void vm_heattransferlab_recoverhtlparams
     (void *, size_t *,
      void *, size_t *,
      void *, size_t *);

   vm_heattransferlab_recoverhtlparams
     ((void *)&OUT_buf_htl_state, &size_OUT_buf_htl_state,
      (void *)&OUT_buf_f1_max_time, &size_OUT_buf_f1_max_time,
      (void *)&OUT_buf_f2_max_time, &size_OUT_buf_f2_max_time);


   // Decode parameter htl_state
   if (0 != Decode_NATIVE_HTL_State
              (OUT_htl_state, (void *)&OUT_buf_htl_state, size_OUT_buf_htl_state)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in heattransferlab_RI_RecoverHTLParams, parameter htl_state");
#endif
      return;
  }
   // Decode parameter f1_max_time
   if (0 != Decode_NATIVE_T_Double
              (OUT_f1_max_time, (void *)&OUT_buf_f1_max_time, size_OUT_buf_f1_max_time)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in heattransferlab_RI_RecoverHTLParams, parameter f1_max_time");
#endif
      return;
  }
   // Decode parameter f2_max_time
   if (0 != Decode_NATIVE_T_Double
              (OUT_f2_max_time, (void *)&OUT_buf_f2_max_time, size_OUT_buf_f2_max_time)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in heattransferlab_RI_RecoverHTLParams, parameter f2_max_time");
#endif
      return;
  }
}
void heattransferlab_RI_RetreiveSingleData
      (const asn1SccOBSW_DP_Filter *IN_filter,
       asn1SccOBSW_DP_SingleData   *OUT_single_data);
void heattransferlab_RI_RetreiveSingleData
      (const asn1SccOBSW_DP_Filter *IN_filter,
       asn1SccOBSW_DP_SingleData   *OUT_single_data)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1OBSW_DP_Filter ("INNERDATA: retreivesingledata::OBSW_DP_Filter::filter", IN_filter);
         puts(""); // add newline
         // Log message to DataPool (corresponding PI: RetreiveSingleData)
         printf ("INNER: heattransferlab,datapool,retreivesingledata,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter filter
   static asn1SccOBSW_DP_Filter IN_buf_filter;
   int size_IN_buf_filter =
      Encode_NATIVE_OBSW_DP_Filter
        ((void *)&IN_buf_filter,
          sizeof(asn1SccOBSW_DP_Filter),
          (asn1SccOBSW_DP_Filter *)IN_filter);
   if (-1 == size_IN_buf_filter) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in heattransferlab_RI_RetreiveSingleData, parameter filter");
      #endif
        /* Crash the application due to message loss */
        abort();
   }

   // Buffer for decoding parameter single_data
   static asn1SccOBSW_DP_SingleData OUT_buf_single_data;
   size_t      size_OUT_buf_single_data = 0;

   // Call Middleware interface
   extern void vm_heattransferlab_retreivesingledata
     (void *, size_t,
      void *, size_t *);

   vm_heattransferlab_retreivesingledata
     ((void *)&IN_buf_filter, (size_t)size_IN_buf_filter,
      (void *)&OUT_buf_single_data, &size_OUT_buf_single_data);


   // Decode parameter single_data
   if (0 != Decode_NATIVE_OBSW_DP_SingleData
              (OUT_single_data, (void *)&OUT_buf_single_data, size_OUT_buf_single_data)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in heattransferlab_RI_RetreiveSingleData, parameter single_data");
#endif
      return;
  }
}
void heattransferlab_RI_StopSystem(void);
void heattransferlab_RI_StopSystem(void)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to SystemHandler (corresponding PI: StopSystem)
         printf ("INNER: heattransferlab,systemhandler,stopsystem,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif


   // Call Middleware interface
   extern void vm_heattransferlab_stopsystem(void);
   vm_heattransferlab_stopsystem();

}
void heattransferlab_RI_getTime
      (asn1SccT_Double *OUT_gps_time,
       asn1SccT_Double *OUT_mission_time);
void heattransferlab_RI_getTime
      (asn1SccT_Double *OUT_gps_time,
       asn1SccT_Double *OUT_mission_time)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to DataPool (corresponding PI: getTime)
         printf ("INNER: heattransferlab,datapool,gettime,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif

   // Buffer for decoding parameter gps_time
   static asn1SccT_Double OUT_buf_gps_time;
   size_t      size_OUT_buf_gps_time = 0;
   // Buffer for decoding parameter mission_time
   static asn1SccT_Double OUT_buf_mission_time;
   size_t      size_OUT_buf_mission_time = 0;

   // Call Middleware interface
   extern void vm_heattransferlab_gettime
     (void *, size_t *,
      void *, size_t *);

   vm_heattransferlab_gettime
     ((void *)&OUT_buf_gps_time, &size_OUT_buf_gps_time,
      (void *)&OUT_buf_mission_time, &size_OUT_buf_mission_time);


   // Decode parameter gps_time
   if (0 != Decode_NATIVE_T_Double
              (OUT_gps_time, (void *)&OUT_buf_gps_time, size_OUT_buf_gps_time)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in heattransferlab_RI_getTime, parameter gps_time");
#endif
      return;
  }
   // Decode parameter mission_time
   if (0 != Decode_NATIVE_T_Double
              (OUT_mission_time, (void *)&OUT_buf_mission_time, size_OUT_buf_mission_time)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in heattransferlab_RI_getTime, parameter mission_time");
#endif
      return;
  }
}
void heattransferlab_RI_setPowerH2
      (const asn1SccT_Float *IN_power);
void heattransferlab_RI_setPowerH2
      (const asn1SccT_Float *IN_power)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1T_Float ("INNERDATA: setpowerh2::T_Float::power", IN_power);
         puts(""); // add newline
         // Log message to Heater2 (corresponding PI: setPowerH2)
         printf ("INNER: heattransferlab,heater2,setpowerh2,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter power
   static asn1SccT_Float IN_buf_power;
   int size_IN_buf_power =
      Encode_NATIVE_T_Float
        ((void *)&IN_buf_power,
          sizeof(asn1SccT_Float),
          (asn1SccT_Float *)IN_power);
   if (-1 == size_IN_buf_power) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in heattransferlab_RI_setPowerH2, parameter power");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_heattransferlab_setpowerh2
     (void *, size_t);

   vm_heattransferlab_setpowerh2
     ((void *)&IN_buf_power, (size_t)size_IN_buf_power);


}

