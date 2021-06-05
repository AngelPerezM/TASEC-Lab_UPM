// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#ifdef __unix__
   #include <stdio.h>
   #include "PrintTypesAsASN1.h"
   #include "timeInMS.h"
#endif
#include "C_ASN1_Types.h"
#include "dataview-uniq.h"

extern unsigned gui_initialized;

void gui_RI_send_telecommand
      (const asn1SccTC_Heater *IN_tc);
void gui_RI_send_telecommand
      (const asn1SccTC_Heater *IN_tc)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1TC_Heater ("INNERDATA: send_telecommand::TC_Heater::tc", IN_tc);
         puts(""); // add newline
         // Log message to TC (corresponding PI: tc)
         printf ("INNER: gui,tc,send_telecommand,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter tc
   static char IN_buf_tc[asn1SccTC_Heater_REQUIRED_BYTES_FOR_ENCODING] = {0};
   int size_IN_buf_tc =
      Encode_UPER_TC_Heater
        ((void *)&IN_buf_tc,
          asn1SccTC_Heater_REQUIRED_BYTES_FOR_ENCODING,
          (asn1SccTC_Heater *)IN_tc);
   if (-1 == size_IN_buf_tc) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in gui_RI_send_telecommand, parameter tc");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_gui_send_telecommand
     (void *, size_t);

   vm_gui_send_telecommand
     ((void *)&IN_buf_tc, (size_t)size_IN_buf_tc);


}

