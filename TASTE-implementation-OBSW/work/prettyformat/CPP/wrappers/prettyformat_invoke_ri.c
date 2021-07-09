// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#ifdef __unix__
   #include <stdio.h>
   #include "PrintTypesAsASN1.h"
   #include "timeInMS.h"
#endif
#include "C_ASN1_Types.h"
#include "dataview-uniq.h"

extern unsigned prettyformat_initialized;

void prettyformat_RI_Attitude_Data
      (const asn1SccATT_GUI *IN_attitude_lab_data);
void prettyformat_RI_Attitude_Data
      (const asn1SccATT_GUI *IN_attitude_lab_data)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1ATT_GUI ("INNERDATA: attitude_data::ATT_GUI::attitude_lab_data", IN_attitude_lab_data);
         puts(""); // add newline
         // Log message to GUI (corresponding PI: Attitude_Data)
         printf ("INNER: prettyformat,gui,attitude_data,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter attitude_lab_data
   static asn1SccATT_GUI IN_buf_attitude_lab_data;
   int size_IN_buf_attitude_lab_data =
      Encode_NATIVE_ATT_GUI
        ((void *)&IN_buf_attitude_lab_data,
          sizeof(asn1SccATT_GUI),
          (asn1SccATT_GUI *)IN_attitude_lab_data);
   if (-1 == size_IN_buf_attitude_lab_data) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in prettyformat_RI_Attitude_Data, parameter attitude_lab_data");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_prettyformat_attitude_data
     (void *, size_t);

   vm_prettyformat_attitude_data
     ((void *)&IN_buf_attitude_lab_data, (size_t)size_IN_buf_attitude_lab_data);


}
void prettyformat_RI_Environmental_Data
      (const asn1SccENV_GUI *IN_env_lab_data);
void prettyformat_RI_Environmental_Data
      (const asn1SccENV_GUI *IN_env_lab_data)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1ENV_GUI ("INNERDATA: environmental_data::ENV_GUI::env_lab_data", IN_env_lab_data);
         puts(""); // add newline
         // Log message to GUI (corresponding PI: Environmental_Data)
         printf ("INNER: prettyformat,gui,environmental_data,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter env_lab_data
   static asn1SccENV_GUI IN_buf_env_lab_data;
   int size_IN_buf_env_lab_data =
      Encode_NATIVE_ENV_GUI
        ((void *)&IN_buf_env_lab_data,
          sizeof(asn1SccENV_GUI),
          (asn1SccENV_GUI *)IN_env_lab_data);
   if (-1 == size_IN_buf_env_lab_data) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in prettyformat_RI_Environmental_Data, parameter env_lab_data");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_prettyformat_environmental_data
     (void *, size_t);

   vm_prettyformat_environmental_data
     ((void *)&IN_buf_env_lab_data, (size_t)size_IN_buf_env_lab_data);


}
void prettyformat_RI_HTL_Data
      (const asn1SccHTL_GUI *IN_htl_data);
void prettyformat_RI_HTL_Data
      (const asn1SccHTL_GUI *IN_htl_data)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1HTL_GUI ("INNERDATA: htl_data::HTL_GUI::htl_data", IN_htl_data);
         puts(""); // add newline
         // Log message to GUI (corresponding PI: HTL_Data)
         printf ("INNER: prettyformat,gui,htl_data,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter htl_data
   static asn1SccHTL_GUI IN_buf_htl_data;
   int size_IN_buf_htl_data =
      Encode_NATIVE_HTL_GUI
        ((void *)&IN_buf_htl_data,
          sizeof(asn1SccHTL_GUI),
          (asn1SccHTL_GUI *)IN_htl_data);
   if (-1 == size_IN_buf_htl_data) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in prettyformat_RI_HTL_Data, parameter htl_data");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_prettyformat_htl_data
     (void *, size_t);

   vm_prettyformat_htl_data
     ((void *)&IN_buf_htl_data, (size_t)size_IN_buf_htl_data);


}

