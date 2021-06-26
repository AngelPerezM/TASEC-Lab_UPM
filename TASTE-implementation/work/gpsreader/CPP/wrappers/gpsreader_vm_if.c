/* Body file for function GPSReader
 * Generated by TASTE on 2021-06-21 01:56:25
 * Provided interfaces : readGPSData
 * Required interfaces : InsertCompleteGroup, getTime
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 140910 111993 177945 123450
 * Timers              : 
 */
#include "gpsreader_vm_if.h"
#ifdef __unix__
   #include <stdio.h>
#endif




extern void init_datapool(void);
extern unsigned datapool_initialized;
extern void init_datapool(void);
extern unsigned datapool_initialized;
unsigned gpsreader_initialized = 0;
void init_gpsreader(void)
{
   if (0 == gpsreader_initialized) {
      gpsreader_initialized = 1;
      // Call user code startup function
      extern void gpsreader_startup(void);
      gpsreader_startup();
      // Iterate over all synchronous RIs, and call their parent's
      // init function. Multiple calls are prevented by the "init" guard.
      if (0 == datapool_initialized) {
          init_datapool();
      }
      if (0 == datapool_initialized) {
          init_datapool();
      }
#ifdef __unix__
      puts ("[TASTE] Initialization completed for function GPSReader");
#endif
      gpsreader_initialized = 2;
   }
}
void gpsreader_readGPSData()
{
   //  Directly call user code, no parameters to pass
   extern void gpsreader_PI_readGPSData(void);
   gpsreader_PI_readGPSData();
   // puts ("gpsreader_readgpsdata called");
}

