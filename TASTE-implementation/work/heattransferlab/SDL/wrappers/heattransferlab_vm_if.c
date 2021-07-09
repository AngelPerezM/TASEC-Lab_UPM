/* Body file for function HeatTransferLab
 * Generated by TASTE on 2021-07-08 21:13:24
 * Provided interfaces : configureParameters, getCurrentMode, setCurrentMode, tick
 * Required interfaces : KickTheDog, RecordHTLParams, RecoverHTLParams, RetreiveSingleData, StopSystem, getTime, setPowerH2
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 220776 54491 257250 78057
 * Timers              : 
 */
#include "heattransferlab_vm_if.h"
#include "C_ASN1_Types.h"
#ifdef __unix__
   #include <stdio.h>
#endif



extern void adainit(void);

extern void init_watchdog(void);
extern unsigned watchdog_initialized;
extern void init_datapool(void);
extern unsigned datapool_initialized;
extern void init_datapool(void);
extern unsigned datapool_initialized;
extern void init_datapool(void);
extern unsigned datapool_initialized;
extern void init_systemhandler(void);
extern unsigned systemhandler_initialized;
extern void init_datapool(void);
extern unsigned datapool_initialized;
extern void init_heater2(void);
extern unsigned heater2_initialized;
unsigned heattransferlab_initialized = 0;
void init_heattransferlab(void)
{
   if (0 == heattransferlab_initialized) {
      heattransferlab_initialized = 1;
      // Initialize Ada runtime to call elaboration functions
      adainit();
      // Iterate over all synchronous RIs, and call their parent's
      // init function. Multiple calls are prevented by the "init" guard.
      if (0 == watchdog_initialized) {
          init_watchdog();
      }
      if (0 == datapool_initialized) {
          init_datapool();
      }
      if (0 == datapool_initialized) {
          init_datapool();
      }
      if (0 == datapool_initialized) {
          init_datapool();
      }
      if (0 == systemhandler_initialized) {
          init_systemhandler();
      }
      if (0 == datapool_initialized) {
          init_datapool();
      }
      if (0 == heater2_initialized) {
          init_heater2();
      }
#ifdef __unix__
      puts ("[TASTE] Initialization completed for function HeatTransferLab");
#endif
      heattransferlab_initialized = 2;
   }
}
void heattransferlab_configureParameters
      (const char *IN_configuration, size_t IN_configuration_len)

{

   static asn1SccHTL_Config IN_CONFIGURATION;
#ifdef __unix__
   asn1SccHTL_Config_Initialize(&IN_CONFIGURATION);
#endif
   if (0 != Decode_NATIVE_HTL_Config (&IN_CONFIGURATION, (void *)IN_configuration, IN_configuration_len)) {
      #ifdef __unix__
         puts("Error decoding HTL-Config in function HeatTransferLab_configureParameters");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void heattransferlab_PI_configureParameters
      (const asn1SccHTL_Config *);




   // Call user code
   heattransferlab_PI_configureParameters (&IN_CONFIGURATION);

}
void heattransferlab_getCurrentMode
      (char *OUT_current_state, size_t *OUT_current_state_len)

{

   static asn1SccHTL_State OUT_CURRENT_STATE;
#ifdef __unix__
   asn1SccHTL_State_Initialize(&OUT_CURRENT_STATE);
#endif

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void heattransferlab_PI_getCurrentMode
      (asn1SccHTL_State *);




   // Call user code
   heattransferlab_PI_getCurrentMode (&OUT_CURRENT_STATE);

   *OUT_current_state_len = Encode_NATIVE_HTL_State
      ((void *)OUT_current_state,
       sizeof (asn1SccHTL_State),
       &OUT_CURRENT_STATE);
}
void heattransferlab_setCurrentMode
      (const char *IN_current_state, size_t IN_current_state_len)

{

   static asn1SccHTL_State IN_CURRENT_STATE;
#ifdef __unix__
   asn1SccHTL_State_Initialize(&IN_CURRENT_STATE);
#endif
   if (0 != Decode_NATIVE_HTL_State (&IN_CURRENT_STATE, (void *)IN_current_state, IN_current_state_len)) {
      #ifdef __unix__
         puts("Error decoding HTL-State in function HeatTransferLab_setCurrentMode");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void heattransferlab_PI_setCurrentMode
      (const asn1SccHTL_State *);




   // Call user code
   heattransferlab_PI_setCurrentMode (&IN_CURRENT_STATE);

}
void heattransferlab_tick()
{
   //  Directly call user code, no parameters to pass
   extern void heattransferlab_PI_tick(void);
   heattransferlab_PI_tick();
   // puts ("heattransferlab_tick called");
}

