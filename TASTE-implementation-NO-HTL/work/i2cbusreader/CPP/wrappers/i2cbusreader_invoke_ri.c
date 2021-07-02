// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#ifdef __unix__
   #include <stdio.h>
   #include "PrintTypesAsASN1.h"
   #include "timeInMS.h"
#endif
#include "C_ASN1_Types.h"
#include "dataview-uniq.h"

extern unsigned i2cbusreader_initialized;

void i2cbusreader_RI_InsertCompleteGroup
      (const asn1SccOBSW_DP_Data *IN_alldata);
void i2cbusreader_RI_InsertCompleteGroup
      (const asn1SccOBSW_DP_Data *IN_alldata)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1OBSW_DP_Data ("INNERDATA: insertcompletegroup::OBSW_DP_Data::alldata", IN_alldata);
         puts(""); // add newline
         // Log message to DataPool (corresponding PI: InsertCompleteGroup)
         printf ("INNER: i2cbusreader,datapool,insertcompletegroup,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter allData
   static asn1SccOBSW_DP_Data IN_buf_alldata;
   int size_IN_buf_alldata =
      Encode_NATIVE_OBSW_DP_Data
        ((void *)&IN_buf_alldata,
          sizeof(asn1SccOBSW_DP_Data),
          (asn1SccOBSW_DP_Data *)IN_alldata);
   if (-1 == size_IN_buf_alldata) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in i2cbusreader_RI_InsertCompleteGroup, parameter allData");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_i2cbusreader_insertcompletegroup
     (void *, size_t);

   vm_i2cbusreader_insertcompletegroup
     ((void *)&IN_buf_alldata, (size_t)size_IN_buf_alldata);


}
void i2cbusreader_RI_getTime
      (asn1SccT_Double *OUT_gps_time,
       asn1SccT_Double *OUT_mission_time);
void i2cbusreader_RI_getTime
      (asn1SccT_Double *OUT_gps_time,
       asn1SccT_Double *OUT_mission_time)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to DataPool (corresponding PI: getTime)
         printf ("INNER: i2cbusreader,datapool,gettime,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif

   // Buffer for decoding parameter gps_time
   static asn1SccT_Double OUT_buf_gps_time;
   size_t      size_OUT_buf_gps_time = 0;
   // Buffer for decoding parameter mission_time
   static asn1SccT_Double OUT_buf_mission_time;
   size_t      size_OUT_buf_mission_time = 0;

   // Call Middleware interface
   extern void vm_i2cbusreader_gettime
     (void *, size_t *,
      void *, size_t *);

   vm_i2cbusreader_gettime
     ((void *)&OUT_buf_gps_time, &size_OUT_buf_gps_time,
      (void *)&OUT_buf_mission_time, &size_OUT_buf_mission_time);


   // Decode parameter gps_time
   if (0 != Decode_NATIVE_T_Double
              (OUT_gps_time, (void *)&OUT_buf_gps_time, size_OUT_buf_gps_time)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in i2cbusreader_RI_getTime, parameter gps_time");
#endif
      return;
  }
   // Decode parameter mission_time
   if (0 != Decode_NATIVE_T_Double
              (OUT_mission_time, (void *)&OUT_buf_mission_time, size_OUT_buf_mission_time)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in i2cbusreader_RI_getTime, parameter mission_time");
#endif
      return;
  }
}
void i2cbusreader_RI_readIMUdata
      (asn1SccIMU_All_Data *OUT_all_data);
void i2cbusreader_RI_readIMUdata
      (asn1SccIMU_All_Data *OUT_all_data)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to IMU (corresponding PI: readIMUdata)
         printf ("INNER: i2cbusreader,imu,readimudata,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif

   // Buffer for decoding parameter all_data
   static asn1SccIMU_All_Data OUT_buf_all_data;
   size_t      size_OUT_buf_all_data = 0;

   // Call Middleware interface
   extern void vm_i2cbusreader_readimudata
     (void *, size_t *);

   vm_i2cbusreader_readimudata
     ((void *)&OUT_buf_all_data, &size_OUT_buf_all_data);


   // Decode parameter all_data
   if (0 != Decode_NATIVE_IMU_All_Data
              (OUT_all_data, (void *)&OUT_buf_all_data, size_OUT_buf_all_data)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in i2cbusreader_RI_readIMUdata, parameter all_data");
#endif
      return;
  }
}
void i2cbusreader_RI_readPT1000Temps
      (asn1SccPT1000s_All_Data *OUT_raw_and_celsius);
void i2cbusreader_RI_readPT1000Temps
      (asn1SccPT1000s_All_Data *OUT_raw_and_celsius)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to PT1000Sensors (corresponding PI: readTemps)
         printf ("INNER: i2cbusreader,pt1000sensors,readpt1000temps,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif

   // Buffer for decoding parameter raw_and_celsius
   static asn1SccPT1000s_All_Data OUT_buf_raw_and_celsius;
   size_t      size_OUT_buf_raw_and_celsius = 0;

   // Call Middleware interface
   extern void vm_i2cbusreader_readpt1000temps
     (void *, size_t *);

   vm_i2cbusreader_readpt1000temps
     ((void *)&OUT_buf_raw_and_celsius, &size_OUT_buf_raw_and_celsius);


   // Decode parameter raw_and_celsius
   if (0 != Decode_NATIVE_PT1000s_All_Data
              (OUT_raw_and_celsius, (void *)&OUT_buf_raw_and_celsius, size_OUT_buf_raw_and_celsius)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in i2cbusreader_RI_readPT1000Temps, parameter raw_and_celsius");
#endif
      return;
  }
}
void i2cbusreader_RI_readTC74Temps
      (asn1SccTC74s_All_Data *OUT_all_tc74s_data);
void i2cbusreader_RI_readTC74Temps
      (asn1SccTC74s_All_Data *OUT_all_tc74s_data)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to TC74Sensors (corresponding PI: readTempsCelsius)
         printf ("INNER: i2cbusreader,tc74sensors,readtc74temps,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif

   // Buffer for decoding parameter all_tc74s_data
   static asn1SccTC74s_All_Data OUT_buf_all_tc74s_data;
   size_t      size_OUT_buf_all_tc74s_data = 0;

   // Call Middleware interface
   extern void vm_i2cbusreader_readtc74temps
     (void *, size_t *);

   vm_i2cbusreader_readtc74temps
     ((void *)&OUT_buf_all_tc74s_data, &size_OUT_buf_all_tc74s_data);


   // Decode parameter all_tc74s_data
   if (0 != Decode_NATIVE_TC74s_All_Data
              (OUT_all_tc74s_data, (void *)&OUT_buf_all_tc74s_data, size_OUT_buf_all_tc74s_data)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in i2cbusreader_RI_readTC74Temps, parameter all_tc74s_data");
#endif
      return;
  }
}
void i2cbusreader_RI_stopIMU(void);
void i2cbusreader_RI_stopIMU(void)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to IMU (corresponding PI: stop)
         printf ("INNER: i2cbusreader,imu,stopimu,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif


   // Call Middleware interface
   extern void vm_i2cbusreader_stopimu(void);
   vm_i2cbusreader_stopimu();

}
void i2cbusreader_RI_stopPT1000s(void);
void i2cbusreader_RI_stopPT1000s(void)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to PT1000Sensors (corresponding PI: stop)
         printf ("INNER: i2cbusreader,pt1000sensors,stoppt1000s,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif


   // Call Middleware interface
   extern void vm_i2cbusreader_stoppt1000s(void);
   vm_i2cbusreader_stoppt1000s();

}
void i2cbusreader_RI_stopTC74s(void);
void i2cbusreader_RI_stopTC74s(void)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to TC74Sensors (corresponding PI: stop)
         printf ("INNER: i2cbusreader,tc74sensors,stoptc74s,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif


   // Call Middleware interface
   extern void vm_i2cbusreader_stoptc74s(void);
   vm_i2cbusreader_stoptc74s();

}

