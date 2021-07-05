/* Body file for function TM
 * Generated by TASTE on 2021-07-05 14:24:57
 * Provided interfaces : HK_tick
 * Required interfaces : RetreiveAllData, getCurrentMode, tm
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 126239 46830 151739 64994
 * Timers              : 
 */
#include "tm_vm_if.h"
#ifdef __unix__
   #include <stdio.h>
#endif




extern void init_datapool(void);
extern unsigned datapool_initialized;
extern void init_heattransferlab(void);
extern unsigned heattransferlab_initialized;
unsigned tm_initialized = 0;
void init_tm(void)
{
   if (0 == tm_initialized) {
      tm_initialized = 1;
      // Call user code startup function
      extern void tm_startup(void);
      tm_startup();
      // Iterate over all synchronous RIs, and call their parent's
      // init function. Multiple calls are prevented by the "init" guard.
      if (0 == datapool_initialized) {
          init_datapool();
      }
      if (0 == heattransferlab_initialized) {
          init_heattransferlab();
      }
#ifdef __unix__
      puts ("[TASTE] Initialization completed for function TM");
#endif
      tm_initialized = 2;
   }
}
void tm_HK_tick()
{
   //  Directly call user code, no parameters to pass
   extern void tm_PI_HK_tick(void);
   tm_PI_HK_tick();
   // puts ("tm_hk_tick called");
}

