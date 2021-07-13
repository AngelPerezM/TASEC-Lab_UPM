/* Body file for function DataMonitor
 * Generated by TASTE on 2021-07-13 16:37:57
 * Provided interfaces : ReadData, stop_DM
 * Required interfaces : InsertCompleteGroup, getPowerH1, getPowerH2, getTime, getTotalPulses, readPressureAndTemp, stopAnemo, stopH1, stopH2, stopPSs
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 217907 119914 249066 161413
 * Timers              : 
 */
#include "datamonitor_vm_if.h"
#ifdef __unix__
   #include <stdio.h>
#endif




extern void init_datapool(void);
extern unsigned datapool_initialized;
extern void init_heater1(void);
extern unsigned heater1_initialized;
extern void init_heater2(void);
extern unsigned heater2_initialized;
extern void init_datapool(void);
extern unsigned datapool_initialized;
extern void init_anemometer(void);
extern unsigned anemometer_initialized;
extern void init_pressuresensors(void);
extern unsigned pressuresensors_initialized;
extern void init_anemometer(void);
extern unsigned anemometer_initialized;
extern void init_heater1(void);
extern unsigned heater1_initialized;
extern void init_heater2(void);
extern unsigned heater2_initialized;
extern void init_pressuresensors(void);
extern unsigned pressuresensors_initialized;
unsigned datamonitor_initialized = 0;
void init_datamonitor(void)
{
   if (0 == datamonitor_initialized) {
      datamonitor_initialized = 1;
      // Call user code startup function
      extern void datamonitor_startup(void);
      datamonitor_startup();
      // Iterate over all synchronous RIs, and call their parent's
      // init function. Multiple calls are prevented by the "init" guard.
      if (0 == datapool_initialized) {
          init_datapool();
      }
      if (0 == heater1_initialized) {
          init_heater1();
      }
      if (0 == heater2_initialized) {
          init_heater2();
      }
      if (0 == datapool_initialized) {
          init_datapool();
      }
      if (0 == anemometer_initialized) {
          init_anemometer();
      }
      if (0 == pressuresensors_initialized) {
          init_pressuresensors();
      }
      if (0 == anemometer_initialized) {
          init_anemometer();
      }
      if (0 == heater1_initialized) {
          init_heater1();
      }
      if (0 == heater2_initialized) {
          init_heater2();
      }
      if (0 == pressuresensors_initialized) {
          init_pressuresensors();
      }
#ifdef __unix__
      puts ("[TASTE] Initialization completed for function DataMonitor");
#endif
      datamonitor_initialized = 2;
   }
}
void datamonitor_ReadData()
{
   //  Directly call user code, no parameters to pass
   extern void datamonitor_PI_ReadData(void);
   datamonitor_PI_ReadData();
   // puts ("datamonitor_readdata called");
}
void datamonitor_stop_DM()
{
   //  Directly call user code, no parameters to pass
   extern void datamonitor_PI_stop_DM(void);
   datamonitor_PI_stop_DM();
   // puts ("datamonitor_stop_dm called");
}

