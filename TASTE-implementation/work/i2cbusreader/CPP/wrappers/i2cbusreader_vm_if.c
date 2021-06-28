/* Body file for function I2CBusReader
 * Generated by TASTE on 2021-06-28 15:23:52
 * Provided interfaces : ReadData, stop_IIC
 * Required interfaces : InsertCompleteGroup, getTime, readIMUdata, readPT1000Temps, readTC74Temps, stopIMU, stopPT1000s, stopTC74s
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 218092 162474 248812 185351
 * Timers              : 
 */
#include "i2cbusreader_vm_if.h"
#ifdef __unix__
   #include <stdio.h>
#endif




extern void init_datapool(void);
extern unsigned datapool_initialized;
extern void init_datapool(void);
extern unsigned datapool_initialized;
extern void init_imu(void);
extern unsigned imu_initialized;
extern void init_pt1000sensors(void);
extern unsigned pt1000sensors_initialized;
extern void init_tc74sensors(void);
extern unsigned tc74sensors_initialized;
extern void init_imu(void);
extern unsigned imu_initialized;
extern void init_pt1000sensors(void);
extern unsigned pt1000sensors_initialized;
extern void init_tc74sensors(void);
extern unsigned tc74sensors_initialized;
unsigned i2cbusreader_initialized = 0;
void init_i2cbusreader(void)
{
   if (0 == i2cbusreader_initialized) {
      i2cbusreader_initialized = 1;
      // Call user code startup function
      extern void i2cbusreader_startup(void);
      i2cbusreader_startup();
      // Iterate over all synchronous RIs, and call their parent's
      // init function. Multiple calls are prevented by the "init" guard.
      if (0 == datapool_initialized) {
          init_datapool();
      }
      if (0 == datapool_initialized) {
          init_datapool();
      }
      if (0 == imu_initialized) {
          init_imu();
      }
      if (0 == pt1000sensors_initialized) {
          init_pt1000sensors();
      }
      if (0 == tc74sensors_initialized) {
          init_tc74sensors();
      }
      if (0 == imu_initialized) {
          init_imu();
      }
      if (0 == pt1000sensors_initialized) {
          init_pt1000sensors();
      }
      if (0 == tc74sensors_initialized) {
          init_tc74sensors();
      }
#ifdef __unix__
      puts ("[TASTE] Initialization completed for function I2CBusReader");
#endif
      i2cbusreader_initialized = 2;
   }
}
void i2cbusreader_ReadData()
{
   //  Directly call user code, no parameters to pass
   extern void i2cbusreader_PI_ReadData(void);
   i2cbusreader_PI_ReadData();
   // puts ("i2cbusreader_readdata called");
}
void i2cbusreader_stop_IIC()
{
   //  Directly call user code, no parameters to pass
   extern void i2cbusreader_PI_stop_IIC(void);
   i2cbusreader_PI_stop_IIC();
   // puts ("i2cbusreader_stop_iic called");
}

