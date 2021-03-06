/* Body file for function TC74Sensors
 * Generated by TASTE on 2021-06-29 11:21:07
 * Provided interfaces : readTempsCelsius, stop
 * Required interfaces : 
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 144878 166341 171680 178732
 * Timers              : 
 */
#include "tc74sensors_vm_if.h"
#include "C_ASN1_Types.h"
#ifdef __unix__
   #include <stdio.h>
#endif




unsigned tc74sensors_initialized = 0;
void init_tc74sensors(void)
{
   if (0 == tc74sensors_initialized) {
      tc74sensors_initialized = 1;
      // Call user code startup function
      extern void tc74sensors_startup(void);
      tc74sensors_startup();
#ifdef __unix__
      puts ("[TASTE] Initialization completed for function TC74Sensors");
#endif
      tc74sensors_initialized = 2;
   }
}
void tc74sensors_readTempsCelsius
      (char *OUT_all_tc74s_data, size_t *OUT_all_tc74s_data_len)

{

   static asn1SccTC74s_All_Data OUT_ALL_TC74S_DATA;
#ifdef __unix__
   asn1SccTC74s_All_Data_Initialize(&OUT_ALL_TC74S_DATA);
#endif

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void tc74sensors_PI_readTempsCelsius
      (asn1SccTC74s_All_Data *);




   // Call user code
   tc74sensors_PI_readTempsCelsius (&OUT_ALL_TC74S_DATA);

   *OUT_all_tc74s_data_len = Encode_NATIVE_TC74s_All_Data
      ((void *)OUT_all_tc74s_data,
       sizeof (asn1SccTC74s_All_Data),
       &OUT_ALL_TC74S_DATA);
}
void tc74sensors_stop()
{
   //  Directly call user code, no parameters to pass
   extern void tc74sensors_PI_stop(void);
   tc74sensors_PI_stop();
   // puts ("tc74sensors_stop called");
}

