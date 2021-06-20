/* Body file for function PrettyFormat
 * Generated by TASTE on 2021-06-18 17:09:36
 * Provided interfaces : tm
 * Required interfaces : Attitude_Data, Environmental_Data, HTL_Data
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 62280 52618 89419 71439
 * Timers              : 
 */
#include "prettyformat_vm_if.h"
#include "C_ASN1_Types.h"
#ifdef __unix__
   #include <stdio.h>
#endif




unsigned prettyformat_initialized = 0;
void init_prettyformat(void)
{
   if (0 == prettyformat_initialized) {
      prettyformat_initialized = 1;
      // Call user code startup function
      extern void prettyformat_startup(void);
      prettyformat_startup();
#ifdef __unix__
      puts ("[TASTE] Initialization completed for function PrettyFormat");
#endif
      prettyformat_initialized = 2;
   }
}
void prettyformat_tm
      (const char *IN_tm, size_t IN_tm_len)

{

   static asn1SccTM IN_TM;
#ifdef __unix__
   asn1SccTM_Initialize(&IN_TM);
#endif
   if (0 != Decode_NATIVE_TM (&IN_TM, (void *)IN_tm, IN_tm_len)) {
      #ifdef __unix__
         puts("Error decoding TM in function PrettyFormat_tm");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void prettyformat_PI_tm
      (const asn1SccTM *);




   // Call user code
   prettyformat_PI_tm (&IN_TM);

}

