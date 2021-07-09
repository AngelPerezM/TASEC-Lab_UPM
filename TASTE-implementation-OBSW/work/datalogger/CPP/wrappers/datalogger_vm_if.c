/* Body file for function DataLogger
 * Generated by TASTE on 2021-07-06 13:54:18
 * Provided interfaces : RecordAllData, notifyIMU, stop
 * Required interfaces : RetreiveAllData, getCurrentMode
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 162204 63041 187269 77163
 * Timers              : 
 */
#include "datalogger_vm_if.h"
#include "C_ASN1_Types.h"
#ifdef __unix__
   #include <stdio.h>
#endif




extern void init_datapool(void);
extern unsigned datapool_initialized;
extern void init_heattransferlab(void);
extern unsigned heattransferlab_initialized;
unsigned datalogger_initialized = 0;
void init_datalogger(void)
{
   if (0 == datalogger_initialized) {
      datalogger_initialized = 1;
      // Call user code startup function
      extern void datalogger_startup(void);
      datalogger_startup();
      // Iterate over all synchronous RIs, and call their parent's
      // init function. Multiple calls are prevented by the "init" guard.
      if (0 == datapool_initialized) {
          init_datapool();
      }
      if (0 == heattransferlab_initialized) {
          init_heattransferlab();
      }
#ifdef __unix__
      puts ("[TASTE] Initialization completed for function DataLogger");
#endif
      datalogger_initialized = 2;
   }
}
void datalogger_RecordAllData()
{
   //  Directly call user code, no parameters to pass
   extern void datalogger_PI_RecordAllData(void);
   datalogger_PI_RecordAllData();
   // puts ("datalogger_recordalldata called");
}
void datalogger_notifyIMU
      (const char *IN_imu_all_data, size_t IN_imu_all_data_len)

{

   static asn1SccIMU_Queue IN_IMU_ALL_DATA;
#ifdef __unix__
   asn1SccIMU_Queue_Initialize(&IN_IMU_ALL_DATA);
#endif
   if (0 != Decode_NATIVE_IMU_Queue (&IN_IMU_ALL_DATA, (void *)IN_imu_all_data, IN_imu_all_data_len)) {
      #ifdef __unix__
         puts("Error decoding IMU-Queue in function DataLogger_notifyIMU");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void datalogger_PI_notifyIMU
      (const asn1SccIMU_Queue *);




   // Call user code
   datalogger_PI_notifyIMU (&IN_IMU_ALL_DATA);

}
void datalogger_stop()
{
   //  Directly call user code, no parameters to pass
   extern void datalogger_PI_stop(void);
   datalogger_PI_stop();
   // puts ("datalogger_stop called");
}

