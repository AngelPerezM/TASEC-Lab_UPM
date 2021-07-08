// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#ifdef __unix__
   #include <stdio.h>
   #include "PrintTypesAsASN1.h"
   #include "timeInMS.h"
#endif
#include "dataview-uniq.h"

extern unsigned systemhandler_initialized;

void systemhandler_RI_stop_DL(void);
void systemhandler_RI_stop_DL(void)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to DataLogger (corresponding PI: stop)
         printf ("INNER: systemhandler,datalogger,stop_dl,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif


   // Call Middleware interface
   extern void vm_systemhandler_stop_dl(void);
   vm_systemhandler_stop_dl();

}
void systemhandler_RI_stop_DM(void);
void systemhandler_RI_stop_DM(void)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to DataMonitor (corresponding PI: stop_DM)
         printf ("INNER: systemhandler,datamonitor,stop_dm,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif


   // Call Middleware interface
   extern void vm_systemhandler_stop_dm(void);
   vm_systemhandler_stop_dm();

}
void systemhandler_RI_stop_IIC(void);
void systemhandler_RI_stop_IIC(void)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to I2CBusReader (corresponding PI: stop_IIC)
         printf ("INNER: systemhandler,i2cbusreader,stop_iic,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif


   // Call Middleware interface
   extern void vm_systemhandler_stop_iic(void);
   vm_systemhandler_stop_iic();

}
void systemhandler_RI_stop_WD(void);
void systemhandler_RI_stop_WD(void)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to Watchdog (corresponding PI: stop)
         printf ("INNER: systemhandler,watchdog,stop_wd,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif


   // Call Middleware interface
   extern void vm_systemhandler_stop_wd(void);
   vm_systemhandler_stop_wd();

}

