// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#ifdef __unix__
   #include <stdio.h>
   #include "PrintTypesAsASN1.h"
   #include "timeInMS.h"
#endif
#include "C_ASN1_Types.h"
#include "dataview-uniq.h"

extern unsigned datalogger_initialized;

void datalogger_RI_RetreiveAllData
      (asn1SccOBSW_DP_Data *OUT_alldata);
void datalogger_RI_RetreiveAllData
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
         printf ("INNER: datalogger,datapool,retreivealldata,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif

   // Buffer for decoding parameter allData
   static asn1SccOBSW_DP_Data OUT_buf_alldata;
   size_t      size_OUT_buf_alldata = 0;

   // Call Middleware interface
   extern void vm_datalogger_retreivealldata
     (void *, size_t *);

   vm_datalogger_retreivealldata
     ((void *)&OUT_buf_alldata, &size_OUT_buf_alldata);


   // Decode parameter allData
   if (0 != Decode_NATIVE_OBSW_DP_Data
              (OUT_alldata, (void *)&OUT_buf_alldata, size_OUT_buf_alldata)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in datalogger_RI_RetreiveAllData, parameter allData");
#endif
      return;
  }
}

