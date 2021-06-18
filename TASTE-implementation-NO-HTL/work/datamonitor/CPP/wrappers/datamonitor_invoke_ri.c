// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#ifdef __unix__
   #include <stdio.h>
   #include "PrintTypesAsASN1.h"
   #include "timeInMS.h"
#endif
#include "C_ASN1_Types.h"
#include "dataview-uniq.h"

extern unsigned datamonitor_initialized;

void datamonitor_RI_InsertCompleteGroup
      (const asn1SccOBSW_DP_Data *IN_alldata);
void datamonitor_RI_InsertCompleteGroup
      (const asn1SccOBSW_DP_Data *IN_alldata)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1OBSW_DP_Data ("INNERDATA: insertcompletegroup::OBSW_DP_Data::alldata", IN_alldata);
         puts(""); // add newline
         // Log message to DataPool (corresponding PI: InsertCompleteGroup)
         printf ("INNER: datamonitor,datapool,insertcompletegroup,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter allData
   static asn1SccOBSW_DP_Data IN_buf_alldata;
   int size_IN_buf_alldata =
      Encode_NATIVE_OBSW_DP_Data
        ((void *)&IN_buf_alldata,
          sizeof(asn1SccOBSW_DP_Data),
          (asn1SccOBSW_DP_Data *)IN_alldata);
   if (-1 == size_IN_buf_alldata) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in datamonitor_RI_InsertCompleteGroup, parameter allData");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_datamonitor_insertcompletegroup
     (void *, size_t);

   vm_datamonitor_insertcompletegroup
     ((void *)&IN_buf_alldata, (size_t)size_IN_buf_alldata);


}
void datamonitor_RI_getPowerH1
      (asn1SccHeater_Data *OUT_heater_data);
void datamonitor_RI_getPowerH1
      (asn1SccHeater_Data *OUT_heater_data)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to Heater1 (corresponding PI: getPowerH1)
         printf ("INNER: datamonitor,heater1,getpowerh1,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif

   // Buffer for decoding parameter heater_data
   static asn1SccHeater_Data OUT_buf_heater_data;
   size_t      size_OUT_buf_heater_data = 0;

   // Call Middleware interface
   extern void vm_datamonitor_getpowerh1
     (void *, size_t *);

   vm_datamonitor_getpowerh1
     ((void *)&OUT_buf_heater_data, &size_OUT_buf_heater_data);


   // Decode parameter heater_data
   if (0 != Decode_NATIVE_Heater_Data
              (OUT_heater_data, (void *)&OUT_buf_heater_data, size_OUT_buf_heater_data)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in datamonitor_RI_getPowerH1, parameter heater_data");
#endif
      return;
  }
}
void datamonitor_RI_getPowerH2
      (asn1SccHeater_Data *OUT_heater_data);
void datamonitor_RI_getPowerH2
      (asn1SccHeater_Data *OUT_heater_data)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to Heater2 (corresponding PI: getPowerH2)
         printf ("INNER: datamonitor,heater2,getpowerh2,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif

   // Buffer for decoding parameter heater_data
   static asn1SccHeater_Data OUT_buf_heater_data;
   size_t      size_OUT_buf_heater_data = 0;

   // Call Middleware interface
   extern void vm_datamonitor_getpowerh2
     (void *, size_t *);

   vm_datamonitor_getpowerh2
     ((void *)&OUT_buf_heater_data, &size_OUT_buf_heater_data);


   // Decode parameter heater_data
   if (0 != Decode_NATIVE_Heater_Data
              (OUT_heater_data, (void *)&OUT_buf_heater_data, size_OUT_buf_heater_data)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in datamonitor_RI_getPowerH2, parameter heater_data");
#endif
      return;
  }
}
void datamonitor_RI_getTime
      (asn1SccT_Double *OUT_gps_time,
       asn1SccT_Double *OUT_mission_time);
void datamonitor_RI_getTime
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
         printf ("INNER: datamonitor,datapool,gettime,%lld\n", msc_time);
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
   extern void vm_datamonitor_gettime
     (void *, size_t *,
      void *, size_t *);

   vm_datamonitor_gettime
     ((void *)&OUT_buf_gps_time, &size_OUT_buf_gps_time,
      (void *)&OUT_buf_mission_time, &size_OUT_buf_mission_time);


   // Decode parameter gps_time
   if (0 != Decode_NATIVE_T_Double
              (OUT_gps_time, (void *)&OUT_buf_gps_time, size_OUT_buf_gps_time)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in datamonitor_RI_getTime, parameter gps_time");
#endif
      return;
  }
   // Decode parameter mission_time
   if (0 != Decode_NATIVE_T_Double
              (OUT_mission_time, (void *)&OUT_buf_mission_time, size_OUT_buf_mission_time)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in datamonitor_RI_getTime, parameter mission_time");
#endif
      return;
  }
}
void datamonitor_RI_getTotalPulses
      (asn1SccT_UInt64 *OUT_noftotalpulses);
void datamonitor_RI_getTotalPulses
      (asn1SccT_UInt64 *OUT_noftotalpulses)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to Anemometer (corresponding PI: getTotalPulses)
         printf ("INNER: datamonitor,anemometer,gettotalpulses,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif

   // Buffer for decoding parameter nOfTotalPulses
   static asn1SccT_UInt64 OUT_buf_noftotalpulses;
   size_t      size_OUT_buf_noftotalpulses = 0;

   // Call Middleware interface
   extern void vm_datamonitor_gettotalpulses
     (void *, size_t *);

   vm_datamonitor_gettotalpulses
     ((void *)&OUT_buf_noftotalpulses, &size_OUT_buf_noftotalpulses);


   // Decode parameter nOfTotalPulses
   if (0 != Decode_NATIVE_T_UInt64
              (OUT_noftotalpulses, (void *)&OUT_buf_noftotalpulses, size_OUT_buf_noftotalpulses)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in datamonitor_RI_getTotalPulses, parameter nOfTotalPulses");
#endif
      return;
  }
}
void datamonitor_RI_readPressureAndTemp
      (asn1SccPS_All_Data *OUT_ps1_data,
       asn1SccPS_All_Data *OUT_ps2_data);
void datamonitor_RI_readPressureAndTemp
      (asn1SccPS_All_Data *OUT_ps1_data,
       asn1SccPS_All_Data *OUT_ps2_data)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to PressureSensors (corresponding PI: readPressureAndTemp)
         printf ("INNER: datamonitor,pressuresensors,readpressureandtemp,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif

   // Buffer for decoding parameter ps1_data
   static asn1SccPS_All_Data OUT_buf_ps1_data;
   size_t      size_OUT_buf_ps1_data = 0;
   // Buffer for decoding parameter ps2_data
   static asn1SccPS_All_Data OUT_buf_ps2_data;
   size_t      size_OUT_buf_ps2_data = 0;

   // Call Middleware interface
   extern void vm_datamonitor_readpressureandtemp
     (void *, size_t *,
      void *, size_t *);

   vm_datamonitor_readpressureandtemp
     ((void *)&OUT_buf_ps1_data, &size_OUT_buf_ps1_data,
      (void *)&OUT_buf_ps2_data, &size_OUT_buf_ps2_data);


   // Decode parameter ps1_data
   if (0 != Decode_NATIVE_PS_All_Data
              (OUT_ps1_data, (void *)&OUT_buf_ps1_data, size_OUT_buf_ps1_data)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in datamonitor_RI_readPressureAndTemp, parameter ps1_data");
#endif
      return;
  }
   // Decode parameter ps2_data
   if (0 != Decode_NATIVE_PS_All_Data
              (OUT_ps2_data, (void *)&OUT_buf_ps2_data, size_OUT_buf_ps2_data)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in datamonitor_RI_readPressureAndTemp, parameter ps2_data");
#endif
      return;
  }
}

