// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#ifdef __unix__
   #include <stdio.h>
   #include "PrintTypesAsASN1.h"
   #include "timeInMS.h"
#endif
#include "C_ASN1_Types.h"
#include "dataview-uniq.h"

extern unsigned datapool_initialized;

void datapool_RI_notifyIMU
      (const asn1SccIMU_Queue *IN_imu_all_data);
void datapool_RI_notifyIMU
      (const asn1SccIMU_Queue *IN_imu_all_data)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1IMU_Queue ("INNERDATA: notifyimu::IMU_Queue::imu_all_data", IN_imu_all_data);
         puts(""); // add newline
         // Log message to DataLogger (corresponding PI: notifyIMU)
         printf ("INNER: datapool,datalogger,notifyimu,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter imu_all_data
   static asn1SccIMU_Queue IN_buf_imu_all_data;
   int size_IN_buf_imu_all_data =
      Encode_NATIVE_IMU_Queue
        ((void *)&IN_buf_imu_all_data,
          sizeof(asn1SccIMU_Queue),
          (asn1SccIMU_Queue *)IN_imu_all_data);
   if (-1 == size_IN_buf_imu_all_data) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in datapool_RI_notifyIMU, parameter imu_all_data");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_datapool_notifyimu
     (void *, size_t);

   vm_datapool_notifyimu
     ((void *)&IN_buf_imu_all_data, (size_t)size_IN_buf_imu_all_data);


}
void datapool_RI_notifyTempChanged
      (const asn1SccT_Float *IN_tempcelsius);
void datapool_RI_notifyTempChanged
      (const asn1SccT_Float *IN_tempcelsius)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1T_Float ("INNERDATA: notifytempchanged::T_Float::tempcelsius", IN_tempcelsius);
         puts(""); // add newline
         // Log message to Thermostat (corresponding PI: notifyTempChanged)
         printf ("INNER: datapool,thermostat,notifytempchanged,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter tempCelsius
   static asn1SccT_Float IN_buf_tempcelsius;
   int size_IN_buf_tempcelsius =
      Encode_NATIVE_T_Float
        ((void *)&IN_buf_tempcelsius,
          sizeof(asn1SccT_Float),
          (asn1SccT_Float *)IN_tempcelsius);
   if (-1 == size_IN_buf_tempcelsius) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in datapool_RI_notifyTempChanged, parameter tempCelsius");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_datapool_notifytempchanged
     (void *, size_t);

   vm_datapool_notifytempchanged
     ((void *)&IN_buf_tempcelsius, (size_t)size_IN_buf_tempcelsius);


}

