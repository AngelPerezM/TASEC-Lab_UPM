
/* Header file for function I2CBusReader in CPP language
 * Generated by TASTE on 2021-06-18 17:09:35
 * Context Parameters present : NO
 * Provided interfaces : ReadData
 * Required interfaces : InsertCompleteGroup, getTime, readIMUdata, readPT1000Temps, readTC74Temps
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

/* Required interfaces */
extern void i2cbusreader_RI_InsertCompleteGroup( const asn1SccOBSW_DP_Data * );
extern void i2cbusreader_RI_getTime( asn1SccT_Double *, asn1SccT_Double * );
extern void i2cbusreader_RI_readIMUdata( asn1SccIMU_All_Data * );
extern void i2cbusreader_RI_readPT1000Temps( asn1SccPT1000s_All_Data * );
extern void i2cbusreader_RI_readTC74Temps( asn1SccTC74s_All_Data * );


#ifdef __cplusplus
}
#endif

