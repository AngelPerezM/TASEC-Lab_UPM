// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#ifdef __unix__
   #include <stdio.h>
   #include "PrintTypesAsASN1.h"
   #include "timeInMS.h"
#endif
#include "dataview-uniq.h"

extern unsigned rpi_partition_1_timer_manager_initialized;

void rpi_partition_1_timer_manager_RI_heattransferlab_f1_timeout(void);
void rpi_partition_1_timer_manager_RI_heattransferlab_f1_timeout(void)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to heattransferlab (corresponding PI: f1_timeout)
         printf ("INNER: rpi_partition_1_timer_manager,heattransferlab,heattransferlab_f1_timeout,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif


   // Call Middleware interface
   extern void vm_rpi_partition_1_timer_manager_heattransferlab_f1_timeout(void);
   vm_rpi_partition_1_timer_manager_heattransferlab_f1_timeout();

}
void rpi_partition_1_timer_manager_RI_heattransferlab_f2_timeout(void);
void rpi_partition_1_timer_manager_RI_heattransferlab_f2_timeout(void)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to heattransferlab (corresponding PI: f2_timeout)
         printf ("INNER: rpi_partition_1_timer_manager,heattransferlab,heattransferlab_f2_timeout,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif


   // Call Middleware interface
   extern void vm_rpi_partition_1_timer_manager_heattransferlab_f2_timeout(void);
   vm_rpi_partition_1_timer_manager_heattransferlab_f2_timeout();

}

