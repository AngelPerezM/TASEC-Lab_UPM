/* Body file for function Watchdog
 * Generated by TASTE on 2021-07-08 17:30:09
 * Provided interfaces : KickTheDog, stop
 * Required interfaces : 
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 192975 65036 214597 70512
 * Timers              : 
 */
#include "watchdog_vm_if.h"
#ifdef __unix__
   #include <stdio.h>
#endif




unsigned watchdog_initialized = 0;
void init_watchdog(void)
{
   if (0 == watchdog_initialized) {
      watchdog_initialized = 1;
      // Call user code startup function
      extern void watchdog_startup(void);
      watchdog_startup();
#ifdef __unix__
      puts ("[TASTE] Initialization completed for function Watchdog");
#endif
      watchdog_initialized = 2;
   }
}
void watchdog_KickTheDog()
{
   //  Directly call user code, no parameters to pass
   extern void watchdog_PI_KickTheDog(void);
   watchdog_PI_KickTheDog();
   // puts ("watchdog_kickthedog called");
}
void watchdog_stop()
{
   //  Directly call user code, no parameters to pass
   extern void watchdog_PI_stop(void);
   watchdog_PI_stop();
   // puts ("watchdog_stop called");
}
