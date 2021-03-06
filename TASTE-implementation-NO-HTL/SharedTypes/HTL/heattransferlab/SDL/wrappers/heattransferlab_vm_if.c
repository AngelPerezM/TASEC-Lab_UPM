/* Body file for function HeatTransferLab
 * Generated by TASTE on 2021-06-14 07:57:31
 * Provided interfaces : configureParameters, f1_timeout, f2_timeout, getCurrentMode, setCurrentMode, tick
 * Required interfaces : RESET_f1_timeout, RESET_f2_timeout, RetreiveSingleData, SET_f1_timeout, SET_f2_timeout, getTime, setOnOffH2, setPowerH2
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 159681 55746 209286 74329
 * Timers              : f1_timeout, f2_timeout
 */
#include "heattransferlab_vm_if.h"
#include "C_ASN1_Types.h"
#ifdef __unix__
   #include <stdio.h>
#endif



extern void adainit(void);

extern void init_x86_partition_timer_manager(void);
extern unsigned x86_partition_timer_manager_initialized;
extern void init_x86_partition_timer_manager(void);
extern unsigned x86_partition_timer_manager_initialized;
extern void init_datapool(void);
extern unsigned datapool_initialized;
extern void init_x86_partition_timer_manager(void);
extern unsigned x86_partition_timer_manager_initialized;
extern void init_x86_partition_timer_manager(void);
extern unsigned x86_partition_timer_manager_initialized;
extern void init_datapool(void);
extern unsigned datapool_initialized;
extern void init_equipmenthandlersmock(void);
extern unsigned equipmenthandlersmock_initialized;
extern void init_equipmenthandlersmock(void);
extern unsigned equipmenthandlersmock_initialized;
unsigned heattransferlab_initialized = 0;
void init_heattransferlab(void)
{
   if (0 == heattransferlab_initialized) {
      heattransferlab_initialized = 1;
      // Initialize Ada runtime to call elaboration functions
      adainit();
      // Iterate over all synchronous RIs, and call their parent's
      // init function. Multiple calls are prevented by the "init" guard.
      if (0 == x86_partition_timer_manager_initialized) {
          init_x86_partition_timer_manager();
      }
      if (0 == x86_partition_timer_manager_initialized) {
          init_x86_partition_timer_manager();
      }
      if (0 == datapool_initialized) {
          init_datapool();
      }
      if (0 == x86_partition_timer_manager_initialized) {
          init_x86_partition_timer_manager();
      }
      if (0 == x86_partition_timer_manager_initialized) {
          init_x86_partition_timer_manager();
      }
      if (0 == datapool_initialized) {
          init_datapool();
      }
      if (0 == equipmenthandlersmock_initialized) {
          init_equipmenthandlersmock();
      }
      if (0 == equipmenthandlersmock_initialized) {
          init_equipmenthandlersmock();
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
void heattransferlab_f1_timeout()
{
   //  Directly call user code, no parameters to pass
   extern void heattransferlab_PI_f1_timeout(void);
   heattransferlab_PI_f1_timeout();
   // puts ("heattransferlab_f1_timeout called");
}
void heattransferlab_f2_timeout()
{
   //  Directly call user code, no parameters to pass
   extern void heattransferlab_PI_f2_timeout(void);
   heattransferlab_PI_f2_timeout();
   // puts ("heattransferlab_f2_timeout called");
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

