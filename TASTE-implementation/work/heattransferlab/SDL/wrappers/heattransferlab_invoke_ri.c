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

void heattransferlab_RI_RetreiveAllData
      (asn1SccOBSW_DP_Data *OUT_alldata);
void heattransferlab_RI_RetreiveAllData
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
         printf ("INNER: heattransferlab,datapool,retreivealldata,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif

   // Buffer for decoding parameter allData
   static asn1SccOBSW_DP_Data OUT_buf_alldata;
   size_t      size_OUT_buf_alldata = 0;

   // Call Middleware interface
   extern void vm_heattransferlab_retreivealldata
     (void *, size_t *);

   vm_heattransferlab_retreivealldata
     ((void *)&OUT_buf_alldata, &size_OUT_buf_alldata);


   // Decode parameter allData
   if (0 != Decode_NATIVE_OBSW_DP_Data
              (OUT_alldata, (void *)&OUT_buf_alldata, size_OUT_buf_alldata)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in heattransferlab_RI_RetreiveAllData, parameter allData");
#endif
      return;
  }
}
void heattransferlab_RI_setOnOffH1
      (const asn1SccHeater_On_Off *IN_command);
void heattransferlab_RI_setOnOffH1
      (const asn1SccHeater_On_Off *IN_command)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1Heater_On_Off ("INNERDATA: setonoffh1::Heater_On_Off::command", IN_command);
         puts(""); // add newline
         // Log message to Heater1 (corresponding PI: setOnOffH1)
         printf ("INNER: heattransferlab,heater1,setonoffh1,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter command
   static asn1SccHeater_On_Off IN_buf_command;
   int size_IN_buf_command =
      Encode_NATIVE_Heater_On_Off
        ((void *)&IN_buf_command,
          sizeof(asn1SccHeater_On_Off),
          (asn1SccHeater_On_Off *)IN_command);
   if (-1 == size_IN_buf_command) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in heattransferlab_RI_setOnOffH1, parameter command");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_heattransferlab_setonoffh1
     (void *, size_t);

   vm_heattransferlab_setonoffh1
     ((void *)&IN_buf_command, (size_t)size_IN_buf_command);


}
void heattransferlab_RI_setPowerH1
      (const asn1SccT_Float *IN_power);
void heattransferlab_RI_setPowerH1
      (const asn1SccT_Float *IN_power)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1T_Float ("INNERDATA: setpowerh1::T_Float::power", IN_power);
         puts(""); // add newline
         // Log message to Heater1 (corresponding PI: setPowerH1)
         printf ("INNER: heattransferlab,heater1,setpowerh1,%lld\n", msc_time);
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
         puts ("[ERROR] ASN.1 Encoding failed in heattransferlab_RI_setPowerH1, parameter power");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_heattransferlab_setpowerh1
     (void *, size_t);

   vm_heattransferlab_setpowerh1
     ((void *)&IN_buf_power, (size_t)size_IN_buf_power);


}

