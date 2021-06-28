/* Body file for function Heater2
 * Generated by TASTE on 2021-06-28 13:00:54
 * Provided interfaces : getPowerH2, setOnOffH2, setPowerH2, stop
 * Required interfaces : 
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 144878 148334 171526 160468
 * Timers              : 
 */
#include "heater2_vm_if.h"
#include "C_ASN1_Types.h"
#ifdef __unix__
   #include <stdio.h>
#endif




unsigned heater2_initialized = 0;
void init_heater2(void)
{
   if (0 == heater2_initialized) {
      heater2_initialized = 1;
      // Call user code startup function
      extern void heater2_startup(void);
      heater2_startup();
#ifdef __unix__
      puts ("[TASTE] Initialization completed for function Heater2");
#endif
      heater2_initialized = 2;
   }
}
void heater2_getPowerH2
      (char *OUT_heater_data, size_t *OUT_heater_data_len)

{

   static asn1SccHeater_Data OUT_HEATER_DATA;
#ifdef __unix__
   asn1SccHeater_Data_Initialize(&OUT_HEATER_DATA);
#endif

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void heater2_PI_getPowerH2
      (asn1SccHeater_Data *);




   // Call user code
   heater2_PI_getPowerH2 (&OUT_HEATER_DATA);

   *OUT_heater_data_len = Encode_NATIVE_Heater_Data
      ((void *)OUT_heater_data,
       sizeof (asn1SccHeater_Data),
       &OUT_HEATER_DATA);
}
void heater2_setOnOffH2
      (const char *IN_command, size_t IN_command_len)

{

   static asn1SccHeater_On_Off IN_COMMAND;
#ifdef __unix__
   asn1SccHeater_On_Off_Initialize(&IN_COMMAND);
#endif
   if (0 != Decode_NATIVE_Heater_On_Off (&IN_COMMAND, (void *)IN_command, IN_command_len)) {
      #ifdef __unix__
         puts("Error decoding Heater-On-Off in function Heater2_setOnOffH2");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void heater2_PI_setOnOffH2
      (const asn1SccHeater_On_Off *);




   // Call user code
   heater2_PI_setOnOffH2 (&IN_COMMAND);

}
void heater2_setPowerH2
      (const char *IN_power, size_t IN_power_len)

{

   static asn1SccT_Float IN_POWER;
#ifdef __unix__
   asn1SccT_Float_Initialize(&IN_POWER);
#endif
   if (0 != Decode_NATIVE_T_Float (&IN_POWER, (void *)IN_power, IN_power_len)) {
      #ifdef __unix__
         puts("Error decoding T-Float in function Heater2_setPowerH2");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void heater2_PI_setPowerH2
      (const asn1SccT_Float *);




   // Call user code
   heater2_PI_setPowerH2 (&IN_POWER);

}
void heater2_stop()
{
   //  Directly call user code, no parameters to pass
   extern void heater2_PI_stop(void);
   heater2_PI_stop();
   // puts ("heater2_stop called");
}

