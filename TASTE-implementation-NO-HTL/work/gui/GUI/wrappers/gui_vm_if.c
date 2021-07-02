/* Body file for function GUI
 * Generated by TASTE on 2021-06-29 11:21:06
 * Provided interfaces : Attitude_Data, Environmental_Data, HTL_Data, Poll
 * Required interfaces : send_telecommand, setCurrentMode
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 63058 80659 89364 100732
 * Timers              : 
 */
#include "gui_vm_if.h"
#include "C_ASN1_Types.h"
#ifdef __unix__
   #include <stdio.h>
#endif




unsigned gui_initialized = 0;
void init_gui(void)
{
   if (0 == gui_initialized) {
      gui_initialized = 1;
      // Call user code startup function
      extern void gui_startup(void);
      gui_startup();
#ifdef __unix__
      puts ("[TASTE] Initialization completed for function GUI");
#endif
      gui_initialized = 2;
   }
}
void gui_Attitude_Data
      (const char *IN_attitude_lab_data, size_t IN_attitude_lab_data_len)

{

   static asn1SccATT_GUI IN_ATTITUDE_LAB_DATA;
#ifdef __unix__
   asn1SccATT_GUI_Initialize(&IN_ATTITUDE_LAB_DATA);
#endif
   if (0 != Decode_NATIVE_ATT_GUI (&IN_ATTITUDE_LAB_DATA, (void *)IN_attitude_lab_data, IN_attitude_lab_data_len)) {
      #ifdef __unix__
         puts("Error decoding ATT-GUI in function GUI_Attitude_Data");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void gui_PI_Attitude_Data
      (const asn1SccATT_GUI *);




   // Call user code
   gui_PI_Attitude_Data (&IN_ATTITUDE_LAB_DATA);

}
void gui_Environmental_Data
      (const char *IN_env_lab_data, size_t IN_env_lab_data_len)

{

   static asn1SccENV_GUI IN_ENV_LAB_DATA;
#ifdef __unix__
   asn1SccENV_GUI_Initialize(&IN_ENV_LAB_DATA);
#endif
   if (0 != Decode_NATIVE_ENV_GUI (&IN_ENV_LAB_DATA, (void *)IN_env_lab_data, IN_env_lab_data_len)) {
      #ifdef __unix__
         puts("Error decoding ENV-GUI in function GUI_Environmental_Data");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void gui_PI_Environmental_Data
      (const asn1SccENV_GUI *);




   // Call user code
   gui_PI_Environmental_Data (&IN_ENV_LAB_DATA);

}
void gui_HTL_Data
      (const char *IN_htl_data, size_t IN_htl_data_len)

{

   static asn1SccHTL_GUI IN_HTL_DATA;
#ifdef __unix__
   asn1SccHTL_GUI_Initialize(&IN_HTL_DATA);
#endif
   if (0 != Decode_NATIVE_HTL_GUI (&IN_HTL_DATA, (void *)IN_htl_data, IN_htl_data_len)) {
      #ifdef __unix__
         puts("Error decoding HTL-GUI in function GUI_HTL_Data");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void gui_PI_HTL_Data
      (const asn1SccHTL_GUI *);




   // Call user code
   gui_PI_HTL_Data (&IN_HTL_DATA);

}
void gui_Poll()
{
   //  Directly call user code, no parameters to pass
   extern void gui_PI_Poll(void);
   gui_PI_Poll();
   // puts ("gui_poll called");
}

