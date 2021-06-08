/* Body file for function PT1000Sensors
 * Generated by TASTE on 2021-06-07 19:06:14
 * Provided interfaces : readTemps
 * Required interfaces : 
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 176834 177555 203757 185192
 * Timers              : 
 */
#include "pt1000sensors_vm_if.h"
#include "C_ASN1_Types.h"
#ifdef __unix__
   #include <stdio.h>
#endif




unsigned pt1000sensors_initialized = 0;
void init_pt1000sensors(void)
{
   if (0 == pt1000sensors_initialized) {
      pt1000sensors_initialized = 1;
      // Call user code startup function
      extern void pt1000sensors_startup(void);
      pt1000sensors_startup();
#ifdef __unix__
      puts ("[TASTE] Initialization completed for function PT1000Sensors");
#endif
      pt1000sensors_initialized = 2;
   }
}
void pt1000sensors_readTemps
      (char *OUT_raw_and_celsius, size_t *OUT_raw_and_celsius_len)

{

   static asn1SccPT1000s_All_Data OUT_RAW_AND_CELSIUS;
#ifdef __unix__
   asn1SccPT1000s_All_Data_Initialize(&OUT_RAW_AND_CELSIUS);
#endif

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void pt1000sensors_PI_readTemps
      (asn1SccPT1000s_All_Data *);




   // Call user code
   pt1000sensors_PI_readTemps (&OUT_RAW_AND_CELSIUS);

   *OUT_raw_and_celsius_len = Encode_NATIVE_PT1000s_All_Data
      ((void *)OUT_raw_and_celsius,
       sizeof (asn1SccPT1000s_All_Data),
       &OUT_RAW_AND_CELSIUS);
}

