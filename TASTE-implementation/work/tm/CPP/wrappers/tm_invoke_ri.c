// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#ifdef __unix__
   #include <stdio.h>
   #include "PrintTypesAsASN1.h"
   #include "timeInMS.h"
#endif
#include "C_ASN1_Types.h"
#include "dataview-uniq.h"

extern unsigned tm_initialized;

void tm_RI_RetreiveAllData
      (asn1SccOBSW_DP_Data *OUT_alldata);
void tm_RI_RetreiveAllData
      (asn1SccOBSW_DP_Data *OUT_alldata)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to DataPool (corresponding PI: RetreiveAllData)
         printf ("INNER: tm,datapool,retreivealldata,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif

   // Buffer for decoding parameter allData
   static asn1SccOBSW_DP_Data OUT_buf_alldata;
   size_t      size_OUT_buf_alldata = 0;

   // Call Middleware interface
   extern void vm_tm_retreivealldata
     (void *, size_t *);

   vm_tm_retreivealldata
     ((void *)&OUT_buf_alldata, &size_OUT_buf_alldata);


   // Decode parameter allData
   if (0 != Decode_NATIVE_OBSW_DP_Data
              (OUT_alldata, (void *)&OUT_buf_alldata, size_OUT_buf_alldata)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in tm_RI_RetreiveAllData, parameter allData");
#endif
      return;
  }
}
void tm_RI_tm
      (const asn1SccTM *IN_tm);
void tm_RI_tm
      (const asn1SccTM *IN_tm)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1TM ("INNERDATA: tm::TM::tm", IN_tm);
         puts(""); // add newline
         // Log message to PrettyFormat (corresponding PI: tm)
         printf ("INNER: tm,prettyformat,tm,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter tm
   static asn1SccTM IN_buf_tm;
   int size_IN_buf_tm =
      Encode_NATIVE_TM
        ((void *)&IN_buf_tm,
          sizeof(asn1SccTM),
          (asn1SccTM *)IN_tm);
   if (-1 == size_IN_buf_tm) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in tm_RI_tm, parameter tm");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_tm_tm
     (void *, size_t);

   vm_tm_tm
     ((void *)&IN_buf_tm, (size_t)size_IN_buf_tm);


}

