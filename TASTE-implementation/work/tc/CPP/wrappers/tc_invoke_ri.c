// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#ifdef __unix__
   #include <stdio.h>
   #include "PrintTypesAsASN1.h"
   #include "timeInMS.h"
#endif
#include "C_ASN1_Types.h"
#include "dataview-uniq.h"

extern unsigned tc_initialized;

void tc_RI_setPowerH1
      (const asn1SccT_Float *IN_power);
void tc_RI_setPowerH1
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
         printf ("INNER: tc,heater1,setpowerh1,%lld\n", msc_time);
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
         puts ("[ERROR] ASN.1 Encoding failed in tc_RI_setPowerH1, parameter power");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_tc_setpowerh1
     (void *, size_t);

   vm_tc_setpowerh1
     ((void *)&IN_buf_power, (size_t)size_IN_buf_power);


}
void tc_RI_setPowerH2
      (const asn1SccT_Float *IN_power);
void tc_RI_setPowerH2
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
         printf ("INNER: tc,heater2,setpowerh2,%lld\n", msc_time);
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
         puts ("[ERROR] ASN.1 Encoding failed in tc_RI_setPowerH2, parameter power");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_tc_setpowerh2
     (void *, size_t);

   vm_tc_setpowerh2
     ((void *)&IN_buf_power, (size_t)size_IN_buf_power);


}

