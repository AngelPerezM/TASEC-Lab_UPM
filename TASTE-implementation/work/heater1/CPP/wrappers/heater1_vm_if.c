/* Body file for function Heater1
 * Generated by TASTE on 2021-07-06 13:54:18
 * Provided interfaces : getPowerH1, setOnOffH1, setPowerH1, stop
 * Required interfaces : 
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 144721 131456 172501 142952
 * Timers              : 
 */
#include "heater1_vm_if.h"
#include "C_ASN1_Types.h"
#ifdef __unix__
   #include <stdio.h>
#endif




unsigned heater1_initialized = 0;
void init_heater1(void)
{
   if (0 == heater1_initialized) {
      heater1_initialized = 1;
      // Call user code startup function
      extern void heater1_startup(void);
      heater1_startup();
#ifdef __unix__
      puts ("[TASTE] Initialization completed for function Heater1");
#endif
      heater1_initialized = 2;
   }
}
void heater1_getPowerH1
      (char *OUT_heater_data, size_t *OUT_heater_data_len)

{

   static asn1SccHeater_Data OUT_HEATER_DATA;
#ifdef __unix__
   asn1SccHeater_Data_Initialize(&OUT_HEATER_DATA);
#endif

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void heater1_PI_getPowerH1
      (asn1SccHeater_Data *);




   // Call user code
   heater1_PI_getPowerH1 (&OUT_HEATER_DATA);

   *OUT_heater_data_len = Encode_NATIVE_Heater_Data
      ((void *)OUT_heater_data,
       sizeof (asn1SccHeater_Data),
       &OUT_HEATER_DATA);
}
void heater1_setOnOffH1
      (const char *IN_command, size_t IN_command_len)

{

   static asn1SccHeater_On_Off IN_COMMAND;
#ifdef __unix__
   asn1SccHeater_On_Off_Initialize(&IN_COMMAND);
#endif
   if (0 != Decode_NATIVE_Heater_On_Off (&IN_COMMAND, (void *)IN_command, IN_command_len)) {
      #ifdef __unix__
         puts("Error decoding Heater-On-Off in function Heater1_setOnOffH1");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void heater1_PI_setOnOffH1
      (const asn1SccHeater_On_Off *);




   // Call user code
   heater1_PI_setOnOffH1 (&IN_COMMAND);

}
void heater1_setPowerH1
      (const char *IN_power, size_t IN_power_len)

{

   static asn1SccT_Float IN_POWER;
#ifdef __unix__
   asn1SccT_Float_Initialize(&IN_POWER);
#endif
   if (0 != Decode_NATIVE_T_Float (&IN_POWER, (void *)IN_power, IN_power_len)) {
      #ifdef __unix__
         puts("Error decoding T-Float in function Heater1_setPowerH1");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void heater1_PI_setPowerH1
      (const asn1SccT_Float *);




   // Call user code
   heater1_PI_setPowerH1 (&IN_POWER);

}
void heater1_stop()
{
   //  Directly call user code, no parameters to pass
   extern void heater1_PI_stop(void);
   heater1_PI_stop();
   // puts ("heater1_stop called");
}

