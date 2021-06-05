// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#ifdef __unix__
   #include <stdio.h>
   #include "PrintTypesAsASN1.h"
   #include "timeInMS.h"
#endif
#include "C_ASN1_Types.h"
#include "dataview-uniq.h"

extern unsigned gpsreader_initialized;

void gpsreader_RI_InsertCompleteGroup
      (const asn1SccOBSW_DP_Data *IN_alldata);
void gpsreader_RI_InsertCompleteGroup
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
         printf ("INNER: gpsreader,datapool,insertcompletegroup,%lld\n", msc_time);
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
         puts ("[ERROR] ASN.1 Encoding failed in gpsreader_RI_InsertCompleteGroup, parameter allData");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_gpsreader_insertcompletegroup
     (void *, size_t);

   vm_gpsreader_insertcompletegroup
     ((void *)&IN_buf_alldata, (size_t)size_IN_buf_alldata);


}
void gpsreader_RI_getTime
      (asn1SccT_Double *OUT_gps_time,
       asn1SccT_Double *OUT_mission_time);
void gpsreader_RI_getTime
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
         printf ("INNER: gpsreader,datapool,gettime,%lld\n", msc_time);
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
   extern void vm_gpsreader_gettime
     (void *, size_t *,
      void *, size_t *);

   vm_gpsreader_gettime
     ((void *)&OUT_buf_gps_time, &size_OUT_buf_gps_time,
      (void *)&OUT_buf_mission_time, &size_OUT_buf_mission_time);


   // Decode parameter gps_time
   if (0 != Decode_NATIVE_T_Double
              (OUT_gps_time, (void *)&OUT_buf_gps_time, size_OUT_buf_gps_time)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in gpsreader_RI_getTime, parameter gps_time");
#endif
      return;
  }
   // Decode parameter mission_time
   if (0 != Decode_NATIVE_T_Double
              (OUT_mission_time, (void *)&OUT_buf_mission_time, size_OUT_buf_mission_time)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in gpsreader_RI_getTime, parameter mission_time");
#endif
      return;
  }
}

