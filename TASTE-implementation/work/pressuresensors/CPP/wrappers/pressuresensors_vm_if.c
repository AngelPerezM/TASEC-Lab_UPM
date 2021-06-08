/* Body file for function PressureSensors
 * Generated by TASTE on 2021-06-07 19:06:14
 * Provided interfaces : readPressureAndTemp
 * Required interfaces : 
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 175029 124808 204231 135044
 * Timers              : 
 */
#include "pressuresensors_vm_if.h"
#include "C_ASN1_Types.h"
#ifdef __unix__
   #include <stdio.h>
#endif




unsigned pressuresensors_initialized = 0;
void init_pressuresensors(void)
{
   if (0 == pressuresensors_initialized) {
      pressuresensors_initialized = 1;
      // Call user code startup function
      extern void pressuresensors_startup(void);
      pressuresensors_startup();
#ifdef __unix__
      puts ("[TASTE] Initialization completed for function PressureSensors");
#endif
      pressuresensors_initialized = 2;
   }
}
void pressuresensors_readPressureAndTemp
      (char *OUT_ps1_data, size_t *OUT_ps1_data_len,
       char *OUT_ps2_data, size_t *OUT_ps2_data_len)

{

   static asn1SccPS_All_Data OUT_PS1_DATA;
#ifdef __unix__
   asn1SccPS_All_Data_Initialize(&OUT_PS1_DATA);
#endif
   static asn1SccPS_All_Data OUT_PS2_DATA;
#ifdef __unix__
   asn1SccPS_All_Data_Initialize(&OUT_PS2_DATA);
#endif

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void pressuresensors_PI_readPressureAndTemp
      (asn1SccPS_All_Data *,
       asn1SccPS_All_Data *);




   // Call user code
   pressuresensors_PI_readPressureAndTemp (&OUT_PS1_DATA, &OUT_PS2_DATA);

   *OUT_ps1_data_len = Encode_NATIVE_PS_All_Data
      ((void *)OUT_ps1_data,
       sizeof (asn1SccPS_All_Data),
       &OUT_PS1_DATA);
   *OUT_ps2_data_len = Encode_NATIVE_PS_All_Data
      ((void *)OUT_ps2_data,
       sizeof (asn1SccPS_All_Data),
       &OUT_PS2_DATA);
}

