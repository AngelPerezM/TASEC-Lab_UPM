/* Body file for function Thermostat
 * Generated by TASTE on 2021-07-05 14:24:57
 * Provided interfaces : notifyTempChanged
 * Required interfaces : setOnOffH1
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 193223 63463 216706 74002
 * Timers              : 
 */
#include "thermostat_vm_if.h"
#include "C_ASN1_Types.h"
#ifdef __unix__
   #include <stdio.h>
#endif



extern void adainit(void);

extern void init_heater1(void);
extern unsigned heater1_initialized;
unsigned thermostat_initialized = 0;
void init_thermostat(void)
{
   if (0 == thermostat_initialized) {
      thermostat_initialized = 1;
      // Initialize Ada runtime to call elaboration functions
      adainit();
      // Iterate over all synchronous RIs, and call their parent's
      // init function. Multiple calls are prevented by the "init" guard.
      if (0 == heater1_initialized) {
          init_heater1();
      }
#ifdef __unix__
      puts ("[TASTE] Initialization completed for function Thermostat");
#endif
      thermostat_initialized = 2;
   }
}
void thermostat_notifyTempChanged
      (const char *IN_tempcelsius, size_t IN_tempcelsius_len)

{

   static asn1SccT_Float IN_TEMPCELSIUS;
#ifdef __unix__
   asn1SccT_Float_Initialize(&IN_TEMPCELSIUS);
#endif
   if (0 != Decode_NATIVE_T_Float (&IN_TEMPCELSIUS, (void *)IN_tempcelsius, IN_tempcelsius_len)) {
      #ifdef __unix__
         puts("Error decoding T-Float in function Thermostat_notifyTempChanged");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void thermostat_PI_notifyTempChanged
      (const asn1SccT_Float *);




   // Call user code
   thermostat_PI_notifyTempChanged (&IN_TEMPCELSIUS);

}

