// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#ifdef __unix__
   #include <stdio.h>
   #include "PrintTypesAsASN1.h"
   #include "timeInMS.h"
#endif
#include "C_ASN1_Types.h"
#include "dataview-uniq.h"

extern unsigned thermostat_initialized;

void thermostat_RI_setOnOffH1
      (const asn1SccHeater_On_Off *IN_command);
void thermostat_RI_setOnOffH1
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
         printf ("INNER: thermostat,heater1,setonoffh1,%lld\n", msc_time);
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
         puts ("[ERROR] ASN.1 Encoding failed in thermostat_RI_setOnOffH1, parameter command");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_thermostat_setonoffh1
     (void *, size_t);

   vm_thermostat_setonoffh1
     ((void *)&IN_buf_command, (size_t)size_IN_buf_command);


}

