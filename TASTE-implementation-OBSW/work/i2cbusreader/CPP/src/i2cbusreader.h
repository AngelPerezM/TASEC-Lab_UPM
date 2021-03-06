
/* Header file for function I2CBusReader in CPP language
 * Generated by TASTE on 2021-07-06 13:57:47
 * Context Parameters present : NO
 * Provided interfaces : ReadData, stop_IIC
 * Required interfaces : InsertCompleteGroup, getTime, readAccelAndGyro, readIMUTemp, readMgt, readOneTemp, readTC74Temps, stopIMU, stopPT1000s, stopTC74s
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 218092 162474 248812 185351
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

#pragma once

#include "dataview-uniq.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __unix__
   #include <stdlib.h>
   #include <stdio.h>
#endif

void i2cbusreader_startup(void);

/* Provided interfaces */
void i2cbusreader_PI_ReadData( );
void i2cbusreader_PI_stop_IIC( );

/* Required interfaces */
extern void i2cbusreader_RI_InsertCompleteGroup( const asn1SccOBSW_DP_Data * );
extern void i2cbusreader_RI_getTime( asn1SccT_Double *, asn1SccT_Double * );
extern void i2cbusreader_RI_readAccelAndGyro( asn1SccACC_MilliG_Data *, asn1SccACC_Raw_Data *, asn1SccContent_Validity *, asn1SccGYRO_MilliDPS_Data *, asn1SccGYRO_Raw_Data *, asn1SccContent_Validity * );
extern void i2cbusreader_RI_readIMUTemp( asn1SccT_Float *, asn1SccT_Int16 *, asn1SccContent_Validity * );
extern void i2cbusreader_RI_readMgt( asn1SccMGT_MilliGauss_Data *, asn1SccMGT_Raw_Data *, asn1SccContent_Validity * );
extern void i2cbusreader_RI_readOneTemp( asn1SccT_Float *, asn1SccT_Float *, asn1SccT_Float *, asn1SccContent_Validity *, const asn1SccT_UInt8 * );
extern void i2cbusreader_RI_readTC74Temps( asn1SccTC74s_All_Data * );
extern void i2cbusreader_RI_stopIMU( );
extern void i2cbusreader_RI_stopPT1000s( );
extern void i2cbusreader_RI_stopTC74s( );


#ifdef __cplusplus
}
#endif

