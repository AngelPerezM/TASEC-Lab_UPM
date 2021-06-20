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

void heattransferlab_RI_RESET_f1_timeout(void);
void heattransferlab_RI_RESET_f1_timeout(void)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to rpi_partition_1_Timer_Manager (corresponding PI: RESET_heattransferlab_f1_timeout)
         printf ("INNER: heattransferlab,rpi_partition_1_timer_manager,reset_f1_timeout,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif


   // Call Middleware interface
   extern void vm_heattransferlab_reset_f1_timeout(void);
   vm_heattransferlab_reset_f1_timeout();

}
void heattransferlab_RI_RESET_f2_timeout(void);
void heattransferlab_RI_RESET_f2_timeout(void)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to rpi_partition_1_Timer_Manager (corresponding PI: RESET_heattransferlab_f2_timeout)
         printf ("INNER: heattransferlab,rpi_partition_1_timer_manager,reset_f2_timeout,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif


   // Call Middleware interface
   extern void vm_heattransferlab_reset_f2_timeout(void);
   vm_heattransferlab_reset_f2_timeout();

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
void heattransferlab_RI_SET_f1_timeout
      (const asn1SccT_UInt32 *IN_val);
void heattransferlab_RI_SET_f1_timeout
      (const asn1SccT_UInt32 *IN_val)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1T_UInt32 ("INNERDATA: set_f1_timeout::T_UInt32::val", IN_val);
         puts(""); // add newline
         // Log message to rpi_partition_1_Timer_Manager (corresponding PI: SET_heattransferlab_f1_timeout)
         printf ("INNER: heattransferlab,rpi_partition_1_timer_manager,set_f1_timeout,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter Val
   static asn1SccT_UInt32 IN_buf_val;
   int size_IN_buf_val =
      Encode_NATIVE_T_UInt32
        ((void *)&IN_buf_val,
          sizeof(asn1SccT_UInt32),
          (asn1SccT_UInt32 *)IN_val);
   if (-1 == size_IN_buf_val) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in heattransferlab_RI_SET_f1_timeout, parameter Val");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_heattransferlab_set_f1_timeout
     (void *, size_t);

   vm_heattransferlab_set_f1_timeout
     ((void *)&IN_buf_val, (size_t)size_IN_buf_val);


}
void heattransferlab_RI_SET_f2_timeout
      (const asn1SccT_UInt32 *IN_val);
void heattransferlab_RI_SET_f2_timeout
      (const asn1SccT_UInt32 *IN_val)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1T_UInt32 ("INNERDATA: set_f2_timeout::T_UInt32::val", IN_val);
         puts(""); // add newline
         // Log message to rpi_partition_1_Timer_Manager (corresponding PI: SET_heattransferlab_f2_timeout)
         printf ("INNER: heattransferlab,rpi_partition_1_timer_manager,set_f2_timeout,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter Val
   static asn1SccT_UInt32 IN_buf_val;
   int size_IN_buf_val =
      Encode_NATIVE_T_UInt32
        ((void *)&IN_buf_val,
          sizeof(asn1SccT_UInt32),
          (asn1SccT_UInt32 *)IN_val);
   if (-1 == size_IN_buf_val) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in heattransferlab_RI_SET_f2_timeout, parameter Val");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_heattransferlab_set_f2_timeout
     (void *, size_t);

   vm_heattransferlab_set_f2_timeout
     ((void *)&IN_buf_val, (size_t)size_IN_buf_val);


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

