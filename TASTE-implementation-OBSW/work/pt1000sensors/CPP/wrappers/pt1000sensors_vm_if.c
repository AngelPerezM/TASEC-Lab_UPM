/* Body file for function PT1000Sensors
 * Generated by TASTE on 2021-07-06 13:54:18
 * Provided interfaces : readAllTemps, readOneTemp, stop
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
void pt1000sensors_readAllTemps
      (char *OUT_raw_and_celsius, size_t *OUT_raw_and_celsius_len)

{

   static asn1SccPT1000s_All_Data OUT_RAW_AND_CELSIUS;
#ifdef __unix__
   asn1SccPT1000s_All_Data_Initialize(&OUT_RAW_AND_CELSIUS);
#endif

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void pt1000sensors_PI_readAllTemps
      (asn1SccPT1000s_All_Data *);




   // Call user code
   pt1000sensors_PI_readAllTemps (&OUT_RAW_AND_CELSIUS);

   *OUT_raw_and_celsius_len = Encode_NATIVE_PT1000s_All_Data
      ((void *)OUT_raw_and_celsius,
       sizeof (asn1SccPT1000s_All_Data),
       &OUT_RAW_AND_CELSIUS);
}
void pt1000sensors_readOneTemp
      (char *OUT_celsius, size_t *OUT_celsius_len,
       char *OUT_adc_raw, size_t *OUT_adc_raw_len,
       char *OUT_adc_vcc, size_t *OUT_adc_vcc_len,
       char *OUT_validity, size_t *OUT_validity_len,
       const char *IN_identifier, size_t IN_identifier_len)

{

   static asn1SccT_Float OUT_CELSIUS;
#ifdef __unix__
   asn1SccT_Float_Initialize(&OUT_CELSIUS);
#endif
   static asn1SccT_Float OUT_ADC_RAW;
#ifdef __unix__
   asn1SccT_Float_Initialize(&OUT_ADC_RAW);
#endif
   static asn1SccT_Float OUT_ADC_VCC;
#ifdef __unix__
   asn1SccT_Float_Initialize(&OUT_ADC_VCC);
#endif
   static asn1SccContent_Validity OUT_VALIDITY;
#ifdef __unix__
   asn1SccContent_Validity_Initialize(&OUT_VALIDITY);
#endif
   static asn1SccT_UInt8 IN_IDENTIFIER;
#ifdef __unix__
   asn1SccT_UInt8_Initialize(&IN_IDENTIFIER);
#endif
   if (0 != Decode_NATIVE_T_UInt8 (&IN_IDENTIFIER, (void *)IN_identifier, IN_identifier_len)) {
      #ifdef __unix__
         puts("Error decoding T-UInt8 in function PT1000Sensors_readOneTemp");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void pt1000sensors_PI_readOneTemp
      (asn1SccT_Float *,
       asn1SccT_Float *,
       asn1SccT_Float *,
       asn1SccContent_Validity *,
       const asn1SccT_UInt8 *);




   // Call user code
   pt1000sensors_PI_readOneTemp (&OUT_CELSIUS, &OUT_ADC_RAW, &OUT_ADC_VCC, &OUT_VALIDITY, &IN_IDENTIFIER);

   *OUT_celsius_len = Encode_NATIVE_T_Float
      ((void *)OUT_celsius,
       sizeof (asn1SccT_Float),
       &OUT_CELSIUS);
   *OUT_adc_raw_len = Encode_NATIVE_T_Float
      ((void *)OUT_adc_raw,
       sizeof (asn1SccT_Float),
       &OUT_ADC_RAW);
   *OUT_adc_vcc_len = Encode_NATIVE_T_Float
      ((void *)OUT_adc_vcc,
       sizeof (asn1SccT_Float),
       &OUT_ADC_VCC);
   *OUT_validity_len = Encode_NATIVE_Content_Validity
      ((void *)OUT_validity,
       sizeof (asn1SccContent_Validity),
       &OUT_VALIDITY);
}
void pt1000sensors_stop()
{
   //  Directly call user code, no parameters to pass
   extern void pt1000sensors_PI_stop(void);
   pt1000sensors_PI_stop();
   // puts ("pt1000sensors_stop called");
}

