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
void i2cbusreader_RI_readAccel
      (asn1SccACC_MilliG_Data  *OUT_acc_g,
       asn1SccACC_Raw_Data     *OUT_acc_raw,
       asn1SccContent_Validity *OUT_acc_validity);
void i2cbusreader_RI_readAccel
      (asn1SccACC_MilliG_Data  *OUT_acc_g,
       asn1SccACC_Raw_Data     *OUT_acc_raw,
       asn1SccContent_Validity *OUT_acc_validity)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to IMU (corresponding PI: readAccel)
         printf ("INNER: i2cbusreader,imu,readaccel,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif

   // Buffer for decoding parameter acc_g
   static asn1SccACC_MilliG_Data OUT_buf_acc_g;
   size_t      size_OUT_buf_acc_g = 0;
   // Buffer for decoding parameter acc_raw
   static asn1SccACC_Raw_Data OUT_buf_acc_raw;
   size_t      size_OUT_buf_acc_raw = 0;
   // Buffer for decoding parameter acc_validity
   static asn1SccContent_Validity OUT_buf_acc_validity;
   size_t      size_OUT_buf_acc_validity = 0;

   // Call Middleware interface
   extern void vm_i2cbusreader_readaccel
     (void *, size_t *,
      void *, size_t *,
      void *, size_t *);

   vm_i2cbusreader_readaccel
     ((void *)&OUT_buf_acc_g, &size_OUT_buf_acc_g,
      (void *)&OUT_buf_acc_raw, &size_OUT_buf_acc_raw,
      (void *)&OUT_buf_acc_validity, &size_OUT_buf_acc_validity);


   // Decode parameter acc_g
   if (0 != Decode_NATIVE_ACC_MilliG_Data
              (OUT_acc_g, (void *)&OUT_buf_acc_g, size_OUT_buf_acc_g)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in i2cbusreader_RI_readAccel, parameter acc_g");
#endif
      return;
  }
   // Decode parameter acc_raw
   if (0 != Decode_NATIVE_ACC_Raw_Data
              (OUT_acc_raw, (void *)&OUT_buf_acc_raw, size_OUT_buf_acc_raw)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in i2cbusreader_RI_readAccel, parameter acc_raw");
#endif
      return;
  }
   // Decode parameter acc_validity
   if (0 != Decode_NATIVE_Content_Validity
              (OUT_acc_validity, (void *)&OUT_buf_acc_validity, size_OUT_buf_acc_validity)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in i2cbusreader_RI_readAccel, parameter acc_validity");
#endif
      return;
  }
}
void i2cbusreader_RI_readGyro
      (asn1SccGYRO_MilliDPS_Data *OUT_gyro_mdps,
       asn1SccGYRO_Raw_Data      *OUT_gyro_raw,
       asn1SccContent_Validity   *OUT_gyro_validity);
void i2cbusreader_RI_readGyro
      (asn1SccGYRO_MilliDPS_Data *OUT_gyro_mdps,
       asn1SccGYRO_Raw_Data      *OUT_gyro_raw,
       asn1SccContent_Validity   *OUT_gyro_validity)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to IMU (corresponding PI: readGyro)
         printf ("INNER: i2cbusreader,imu,readgyro,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif

   // Buffer for decoding parameter gyro_mdps
   static asn1SccGYRO_MilliDPS_Data OUT_buf_gyro_mdps;
   size_t      size_OUT_buf_gyro_mdps = 0;
   // Buffer for decoding parameter gyro_raw
   static asn1SccGYRO_Raw_Data OUT_buf_gyro_raw;
   size_t      size_OUT_buf_gyro_raw = 0;
   // Buffer for decoding parameter gyro_validity
   static asn1SccContent_Validity OUT_buf_gyro_validity;
   size_t      size_OUT_buf_gyro_validity = 0;

   // Call Middleware interface
   extern void vm_i2cbusreader_readgyro
     (void *, size_t *,
      void *, size_t *,
      void *, size_t *);

   vm_i2cbusreader_readgyro
     ((void *)&OUT_buf_gyro_mdps, &size_OUT_buf_gyro_mdps,
      (void *)&OUT_buf_gyro_raw, &size_OUT_buf_gyro_raw,
      (void *)&OUT_buf_gyro_validity, &size_OUT_buf_gyro_validity);


   // Decode parameter gyro_mdps
   if (0 != Decode_NATIVE_GYRO_MilliDPS_Data
              (OUT_gyro_mdps, (void *)&OUT_buf_gyro_mdps, size_OUT_buf_gyro_mdps)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in i2cbusreader_RI_readGyro, parameter gyro_mdps");
#endif
      return;
  }
   // Decode parameter gyro_raw
   if (0 != Decode_NATIVE_GYRO_Raw_Data
              (OUT_gyro_raw, (void *)&OUT_buf_gyro_raw, size_OUT_buf_gyro_raw)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in i2cbusreader_RI_readGyro, parameter gyro_raw");
#endif
      return;
  }
   // Decode parameter gyro_validity
   if (0 != Decode_NATIVE_Content_Validity
              (OUT_gyro_validity, (void *)&OUT_buf_gyro_validity, size_OUT_buf_gyro_validity)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in i2cbusreader_RI_readGyro, parameter gyro_validity");
#endif
      return;
  }
}
void i2cbusreader_RI_readIMUTemp
      (asn1SccT_Float          *OUT_temp_celsius,
       asn1SccT_Int16          *OUT_temp_raw,
       asn1SccContent_Validity *OUT_validity);
void i2cbusreader_RI_readIMUTemp
      (asn1SccT_Float          *OUT_temp_celsius,
       asn1SccT_Int16          *OUT_temp_raw,
       asn1SccContent_Validity *OUT_validity)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to IMU (corresponding PI: readTemp)
         printf ("INNER: i2cbusreader,imu,readimutemp,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif

   // Buffer for decoding parameter temp_celsius
   static asn1SccT_Float OUT_buf_temp_celsius;
   size_t      size_OUT_buf_temp_celsius = 0;
   // Buffer for decoding parameter temp_raw
   static asn1SccT_Int16 OUT_buf_temp_raw;
   size_t      size_OUT_buf_temp_raw = 0;
   // Buffer for decoding parameter validity
   static asn1SccContent_Validity OUT_buf_validity;
   size_t      size_OUT_buf_validity = 0;

   // Call Middleware interface
   extern void vm_i2cbusreader_readimutemp
     (void *, size_t *,
      void *, size_t *,
      void *, size_t *);

   vm_i2cbusreader_readimutemp
     ((void *)&OUT_buf_temp_celsius, &size_OUT_buf_temp_celsius,
      (void *)&OUT_buf_temp_raw, &size_OUT_buf_temp_raw,
      (void *)&OUT_buf_validity, &size_OUT_buf_validity);


   // Decode parameter temp_celsius
   if (0 != Decode_NATIVE_T_Float
              (OUT_temp_celsius, (void *)&OUT_buf_temp_celsius, size_OUT_buf_temp_celsius)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in i2cbusreader_RI_readIMUTemp, parameter temp_celsius");
#endif
      return;
  }
   // Decode parameter temp_raw
   if (0 != Decode_NATIVE_T_Int16
              (OUT_temp_raw, (void *)&OUT_buf_temp_raw, size_OUT_buf_temp_raw)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in i2cbusreader_RI_readIMUTemp, parameter temp_raw");
#endif
      return;
  }
   // Decode parameter validity
   if (0 != Decode_NATIVE_Content_Validity
              (OUT_validity, (void *)&OUT_buf_validity, size_OUT_buf_validity)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in i2cbusreader_RI_readIMUTemp, parameter validity");
#endif
      return;
  }
}
void i2cbusreader_RI_readMgt
      (asn1SccMGT_MilliGauss_Data *OUT_mgt_mgauss,
       asn1SccMGT_Raw_Data        *OUT_mgt_raw,
       asn1SccContent_Validity    *OUT_validity);
void i2cbusreader_RI_readMgt
      (asn1SccMGT_MilliGauss_Data *OUT_mgt_mgauss,
       asn1SccMGT_Raw_Data        *OUT_mgt_raw,
       asn1SccContent_Validity    *OUT_validity)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         puts(""); // add newline
         // Log message to IMU (corresponding PI: readMgt)
         printf ("INNER: i2cbusreader,imu,readmgt,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif

   // Buffer for decoding parameter mgt_mgauss
   static asn1SccMGT_MilliGauss_Data OUT_buf_mgt_mgauss;
   size_t      size_OUT_buf_mgt_mgauss = 0;
   // Buffer for decoding parameter mgt_raw
   static asn1SccMGT_Raw_Data OUT_buf_mgt_raw;
   size_t      size_OUT_buf_mgt_raw = 0;
   // Buffer for decoding parameter validity
   static asn1SccContent_Validity OUT_buf_validity;
   size_t      size_OUT_buf_validity = 0;

   // Call Middleware interface
   extern void vm_i2cbusreader_readmgt
     (void *, size_t *,
      void *, size_t *,
      void *, size_t *);

   vm_i2cbusreader_readmgt
     ((void *)&OUT_buf_mgt_mgauss, &size_OUT_buf_mgt_mgauss,
      (void *)&OUT_buf_mgt_raw, &size_OUT_buf_mgt_raw,
      (void *)&OUT_buf_validity, &size_OUT_buf_validity);


   // Decode parameter mgt_mgauss
   if (0 != Decode_NATIVE_MGT_MilliGauss_Data
              (OUT_mgt_mgauss, (void *)&OUT_buf_mgt_mgauss, size_OUT_buf_mgt_mgauss)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in i2cbusreader_RI_readMgt, parameter mgt_mgauss");
#endif
      return;
  }
   // Decode parameter mgt_raw
   if (0 != Decode_NATIVE_MGT_Raw_Data
              (OUT_mgt_raw, (void *)&OUT_buf_mgt_raw, size_OUT_buf_mgt_raw)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in i2cbusreader_RI_readMgt, parameter mgt_raw");
#endif
      return;
  }
   // Decode parameter validity
   if (0 != Decode_NATIVE_Content_Validity
              (OUT_validity, (void *)&OUT_buf_validity, size_OUT_buf_validity)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in i2cbusreader_RI_readMgt, parameter validity");
#endif
      return;
  }
}
void i2cbusreader_RI_readOneTemp
      (asn1SccT_Float          *OUT_celsius,
       asn1SccT_Float          *OUT_adc_raw,
       asn1SccT_Float          *OUT_adc_vcc,
       asn1SccContent_Validity *OUT_validity,
       const asn1SccT_UInt8    *IN_identifier);
void i2cbusreader_RI_readOneTemp
      (asn1SccT_Float          *OUT_celsius,
       asn1SccT_Float          *OUT_adc_raw,
       asn1SccT_Float          *OUT_adc_vcc,
       asn1SccContent_Validity *OUT_validity,
       const asn1SccT_UInt8    *IN_identifier)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1T_UInt8 ("INNERDATA: readonetemp::T_UInt8::identifier", IN_identifier);
         puts(""); // add newline
         // Log message to PT1000Sensors (corresponding PI: readOneTemp)
         printf ("INNER: i2cbusreader,pt1000sensors,readonetemp,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter identifier
   static asn1SccT_UInt8 IN_buf_identifier;
   int size_IN_buf_identifier =
      Encode_NATIVE_T_UInt8
        ((void *)&IN_buf_identifier,
          sizeof(asn1SccT_UInt8),
          (asn1SccT_UInt8 *)IN_identifier);
   if (-1 == size_IN_buf_identifier) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in i2cbusreader_RI_readOneTemp, parameter identifier");
      #endif
        /* Crash the application due to message loss */
        abort();
   }

   // Buffer for decoding parameter celsius
   static asn1SccT_Float OUT_buf_celsius;
   size_t      size_OUT_buf_celsius = 0;
   // Buffer for decoding parameter adc_raw
   static asn1SccT_Float OUT_buf_adc_raw;
   size_t      size_OUT_buf_adc_raw = 0;
   // Buffer for decoding parameter adc_vcc
   static asn1SccT_Float OUT_buf_adc_vcc;
   size_t      size_OUT_buf_adc_vcc = 0;
   // Buffer for decoding parameter validity
   static asn1SccContent_Validity OUT_buf_validity;
   size_t      size_OUT_buf_validity = 0;

   // Call Middleware interface
   extern void vm_i2cbusreader_readonetemp
     (void *, size_t *,
      void *, size_t *,
      void *, size_t *,
      void *, size_t *,
      void *, size_t);

   vm_i2cbusreader_readonetemp
     ((void *)&OUT_buf_celsius, &size_OUT_buf_celsius,
      (void *)&OUT_buf_adc_raw, &size_OUT_buf_adc_raw,
      (void *)&OUT_buf_adc_vcc, &size_OUT_buf_adc_vcc,
      (void *)&OUT_buf_validity, &size_OUT_buf_validity,
      (void *)&IN_buf_identifier, (size_t)size_IN_buf_identifier);


   // Decode parameter celsius
   if (0 != Decode_NATIVE_T_Float
              (OUT_celsius, (void *)&OUT_buf_celsius, size_OUT_buf_celsius)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in i2cbusreader_RI_readOneTemp, parameter celsius");
#endif
      return;
  }
   // Decode parameter adc_raw
   if (0 != Decode_NATIVE_T_Float
              (OUT_adc_raw, (void *)&OUT_buf_adc_raw, size_OUT_buf_adc_raw)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in i2cbusreader_RI_readOneTemp, parameter adc_raw");
#endif
      return;
  }
   // Decode parameter adc_vcc
   if (0 != Decode_NATIVE_T_Float
              (OUT_adc_vcc, (void *)&OUT_buf_adc_vcc, size_OUT_buf_adc_vcc)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in i2cbusreader_RI_readOneTemp, parameter adc_vcc");
#endif
      return;
  }
   // Decode parameter validity
   if (0 != Decode_NATIVE_Content_Validity
              (OUT_validity, (void *)&OUT_buf_validity, size_OUT_buf_validity)) {
#ifdef __unix__
      puts ("[ERROR] ASN.1 Decoding failed in i2cbusreader_RI_readOneTemp, parameter validity");
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

