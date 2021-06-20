#ifndef __C_DATAVIEW_UNIQ_H__
#define __C_DATAVIEW_UNIQ_H__

#if defined( __unix__ ) || defined( __MSP430__ )
#include <stdlib.h> /* for size_t */
#else
typedef unsigned size_t;
#endif

#ifndef STATIC
#define STATIC
#endif


#include "dataview-uniq.h" // Space certified compiler generated

#include "../../system_config.h" // Choose ASN.1 Types to use

#ifdef __NEED_T_Int16_UPER
int Encode_UPER_T_Int16(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int16 *pSrc);
#endif

#ifdef __NEED_T_Int16_ACN
int Encode_ACN_T_Int16(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int16 *pSrc);
#endif

#ifdef __NEED_T_Int16_NATIVE
int Encode_NATIVE_T_Int16(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int16 *pSrc);
#endif

#ifdef __NEED_T_Int16_UPER
int Decode_UPER_T_Int16(asn1SccT_Int16 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int16_ACN
int Decode_ACN_T_Int16(asn1SccT_Int16 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int16_NATIVE
int Decode_NATIVE_T_Int16(asn1SccT_Int16 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt16_UPER
int Encode_UPER_T_UInt16(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt16 *pSrc);
#endif

#ifdef __NEED_T_UInt16_ACN
int Encode_ACN_T_UInt16(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt16 *pSrc);
#endif

#ifdef __NEED_T_UInt16_NATIVE
int Encode_NATIVE_T_UInt16(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt16 *pSrc);
#endif

#ifdef __NEED_T_UInt16_UPER
int Decode_UPER_T_UInt16(asn1SccT_UInt16 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt16_ACN
int Decode_ACN_T_UInt16(asn1SccT_UInt16 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt16_NATIVE
int Decode_NATIVE_T_UInt16(asn1SccT_UInt16 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt64_UPER
int Encode_UPER_T_UInt64(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt64 *pSrc);
#endif

#ifdef __NEED_T_UInt64_ACN
int Encode_ACN_T_UInt64(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt64 *pSrc);
#endif

#ifdef __NEED_T_UInt64_NATIVE
int Encode_NATIVE_T_UInt64(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt64 *pSrc);
#endif

#ifdef __NEED_T_UInt64_UPER
int Decode_UPER_T_UInt64(asn1SccT_UInt64 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt64_ACN
int Decode_ACN_T_UInt64(asn1SccT_UInt64 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt64_NATIVE
int Decode_NATIVE_T_UInt64(asn1SccT_UInt64 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Float_UPER
int Encode_UPER_T_Float(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Float *pSrc);
#endif

#ifdef __NEED_T_Float_ACN
int Encode_ACN_T_Float(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Float *pSrc);
#endif

#ifdef __NEED_T_Float_NATIVE
int Encode_NATIVE_T_Float(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Float *pSrc);
#endif

#ifdef __NEED_T_Float_UPER
int Decode_UPER_T_Float(asn1SccT_Float *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Float_ACN
int Decode_ACN_T_Float(asn1SccT_Float *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Float_NATIVE
int Decode_NATIVE_T_Float(asn1SccT_Float *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Double_UPER
int Encode_UPER_T_Double(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Double *pSrc);
#endif

#ifdef __NEED_T_Double_ACN
int Encode_ACN_T_Double(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Double *pSrc);
#endif

#ifdef __NEED_T_Double_NATIVE
int Encode_NATIVE_T_Double(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Double *pSrc);
#endif

#ifdef __NEED_T_Double_UPER
int Decode_UPER_T_Double(asn1SccT_Double *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Double_ACN
int Decode_ACN_T_Double(asn1SccT_Double *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Double_NATIVE
int Decode_NATIVE_T_Double(asn1SccT_Double *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_File_Name_UPER
int Encode_UPER_File_Name(void *pBuffer, size_t iMaxBufferSize, const asn1SccFile_Name *pSrc);
#endif

#ifdef __NEED_File_Name_ACN
int Encode_ACN_File_Name(void *pBuffer, size_t iMaxBufferSize, asn1SccFile_Name *pSrc);
#endif

#ifdef __NEED_File_Name_NATIVE
int Encode_NATIVE_File_Name(void *pBuffer, size_t iMaxBufferSize, const asn1SccFile_Name *pSrc);
#endif

#ifdef __NEED_File_Name_UPER
int Decode_UPER_File_Name(asn1SccFile_Name *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_File_Name_ACN
int Decode_ACN_File_Name(asn1SccFile_Name *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_File_Name_NATIVE
int Decode_NATIVE_File_Name(asn1SccFile_Name *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Content_Validity_UPER
int Encode_UPER_Content_Validity(void *pBuffer, size_t iMaxBufferSize, const asn1SccContent_Validity *pSrc);
#endif

#ifdef __NEED_Content_Validity_ACN
int Encode_ACN_Content_Validity(void *pBuffer, size_t iMaxBufferSize, asn1SccContent_Validity *pSrc);
#endif

#ifdef __NEED_Content_Validity_NATIVE
int Encode_NATIVE_Content_Validity(void *pBuffer, size_t iMaxBufferSize, const asn1SccContent_Validity *pSrc);
#endif

#ifdef __NEED_Content_Validity_UPER
int Decode_UPER_Content_Validity(asn1SccContent_Validity *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Content_Validity_ACN
int Decode_ACN_Content_Validity(asn1SccContent_Validity *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Content_Validity_NATIVE
int Decode_NATIVE_Content_Validity(asn1SccContent_Validity *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_SPI_ID_UPER
int Encode_UPER_SPI_ID(void *pBuffer, size_t iMaxBufferSize, const asn1SccSPI_ID *pSrc);
#endif

#ifdef __NEED_SPI_ID_ACN
int Encode_ACN_SPI_ID(void *pBuffer, size_t iMaxBufferSize, asn1SccSPI_ID *pSrc);
#endif

#ifdef __NEED_SPI_ID_NATIVE
int Encode_NATIVE_SPI_ID(void *pBuffer, size_t iMaxBufferSize, const asn1SccSPI_ID *pSrc);
#endif

#ifdef __NEED_SPI_ID_UPER
int Decode_UPER_SPI_ID(asn1SccSPI_ID *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_SPI_ID_ACN
int Decode_ACN_SPI_ID(asn1SccSPI_ID *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_SPI_ID_NATIVE
int Decode_NATIVE_SPI_ID(asn1SccSPI_ID *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_I2C_ID_UPER
int Encode_UPER_I2C_ID(void *pBuffer, size_t iMaxBufferSize, const asn1SccI2C_ID *pSrc);
#endif

#ifdef __NEED_I2C_ID_ACN
int Encode_ACN_I2C_ID(void *pBuffer, size_t iMaxBufferSize, asn1SccI2C_ID *pSrc);
#endif

#ifdef __NEED_I2C_ID_NATIVE
int Encode_NATIVE_I2C_ID(void *pBuffer, size_t iMaxBufferSize, const asn1SccI2C_ID *pSrc);
#endif

#ifdef __NEED_I2C_ID_UPER
int Decode_UPER_I2C_ID(asn1SccI2C_ID *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_I2C_ID_ACN
int Decode_ACN_I2C_ID(asn1SccI2C_ID *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_I2C_ID_NATIVE
int Decode_NATIVE_I2C_ID(asn1SccI2C_ID *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_GPS_PVT_UPER
int Encode_UPER_GPS_PVT(void *pBuffer, size_t iMaxBufferSize, const asn1SccGPS_PVT *pSrc);
#endif

#ifdef __NEED_GPS_PVT_ACN
int Encode_ACN_GPS_PVT(void *pBuffer, size_t iMaxBufferSize, asn1SccGPS_PVT *pSrc);
#endif

#ifdef __NEED_GPS_PVT_NATIVE
int Encode_NATIVE_GPS_PVT(void *pBuffer, size_t iMaxBufferSize, const asn1SccGPS_PVT *pSrc);
#endif

#ifdef __NEED_GPS_PVT_UPER
int Decode_UPER_GPS_PVT(asn1SccGPS_PVT *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_GPS_PVT_ACN
int Decode_ACN_GPS_PVT(asn1SccGPS_PVT *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_GPS_PVT_NATIVE
int Decode_NATIVE_GPS_PVT(asn1SccGPS_PVT *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_MGT_Raw_Data_UPER
int Encode_UPER_MGT_Raw_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccMGT_Raw_Data *pSrc);
#endif

#ifdef __NEED_MGT_Raw_Data_ACN
int Encode_ACN_MGT_Raw_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccMGT_Raw_Data *pSrc);
#endif

#ifdef __NEED_MGT_Raw_Data_NATIVE
int Encode_NATIVE_MGT_Raw_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccMGT_Raw_Data *pSrc);
#endif

#ifdef __NEED_MGT_Raw_Data_UPER
int Decode_UPER_MGT_Raw_Data(asn1SccMGT_Raw_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_MGT_Raw_Data_ACN
int Decode_ACN_MGT_Raw_Data(asn1SccMGT_Raw_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_MGT_Raw_Data_NATIVE
int Decode_NATIVE_MGT_Raw_Data(asn1SccMGT_Raw_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_MGT_MilliGauss_Data_UPER
int Encode_UPER_MGT_MilliGauss_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccMGT_MilliGauss_Data *pSrc);
#endif

#ifdef __NEED_MGT_MilliGauss_Data_ACN
int Encode_ACN_MGT_MilliGauss_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccMGT_MilliGauss_Data *pSrc);
#endif

#ifdef __NEED_MGT_MilliGauss_Data_NATIVE
int Encode_NATIVE_MGT_MilliGauss_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccMGT_MilliGauss_Data *pSrc);
#endif

#ifdef __NEED_MGT_MilliGauss_Data_UPER
int Decode_UPER_MGT_MilliGauss_Data(asn1SccMGT_MilliGauss_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_MGT_MilliGauss_Data_ACN
int Decode_ACN_MGT_MilliGauss_Data(asn1SccMGT_MilliGauss_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_MGT_MilliGauss_Data_NATIVE
int Decode_NATIVE_MGT_MilliGauss_Data(asn1SccMGT_MilliGauss_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ACC_Raw_Data_UPER
int Encode_UPER_ACC_Raw_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccACC_Raw_Data *pSrc);
#endif

#ifdef __NEED_ACC_Raw_Data_ACN
int Encode_ACN_ACC_Raw_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccACC_Raw_Data *pSrc);
#endif

#ifdef __NEED_ACC_Raw_Data_NATIVE
int Encode_NATIVE_ACC_Raw_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccACC_Raw_Data *pSrc);
#endif

#ifdef __NEED_ACC_Raw_Data_UPER
int Decode_UPER_ACC_Raw_Data(asn1SccACC_Raw_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ACC_Raw_Data_ACN
int Decode_ACN_ACC_Raw_Data(asn1SccACC_Raw_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ACC_Raw_Data_NATIVE
int Decode_NATIVE_ACC_Raw_Data(asn1SccACC_Raw_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ACC_MilliG_Data_UPER
int Encode_UPER_ACC_MilliG_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccACC_MilliG_Data *pSrc);
#endif

#ifdef __NEED_ACC_MilliG_Data_ACN
int Encode_ACN_ACC_MilliG_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccACC_MilliG_Data *pSrc);
#endif

#ifdef __NEED_ACC_MilliG_Data_NATIVE
int Encode_NATIVE_ACC_MilliG_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccACC_MilliG_Data *pSrc);
#endif

#ifdef __NEED_ACC_MilliG_Data_UPER
int Decode_UPER_ACC_MilliG_Data(asn1SccACC_MilliG_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ACC_MilliG_Data_ACN
int Decode_ACN_ACC_MilliG_Data(asn1SccACC_MilliG_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ACC_MilliG_Data_NATIVE
int Decode_NATIVE_ACC_MilliG_Data(asn1SccACC_MilliG_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_GYRO_Raw_Data_UPER
int Encode_UPER_GYRO_Raw_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccGYRO_Raw_Data *pSrc);
#endif

#ifdef __NEED_GYRO_Raw_Data_ACN
int Encode_ACN_GYRO_Raw_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccGYRO_Raw_Data *pSrc);
#endif

#ifdef __NEED_GYRO_Raw_Data_NATIVE
int Encode_NATIVE_GYRO_Raw_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccGYRO_Raw_Data *pSrc);
#endif

#ifdef __NEED_GYRO_Raw_Data_UPER
int Decode_UPER_GYRO_Raw_Data(asn1SccGYRO_Raw_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_GYRO_Raw_Data_ACN
int Decode_ACN_GYRO_Raw_Data(asn1SccGYRO_Raw_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_GYRO_Raw_Data_NATIVE
int Decode_NATIVE_GYRO_Raw_Data(asn1SccGYRO_Raw_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_GYRO_MilliDPS_Data_UPER
int Encode_UPER_GYRO_MilliDPS_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccGYRO_MilliDPS_Data *pSrc);
#endif

#ifdef __NEED_GYRO_MilliDPS_Data_ACN
int Encode_ACN_GYRO_MilliDPS_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccGYRO_MilliDPS_Data *pSrc);
#endif

#ifdef __NEED_GYRO_MilliDPS_Data_NATIVE
int Encode_NATIVE_GYRO_MilliDPS_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccGYRO_MilliDPS_Data *pSrc);
#endif

#ifdef __NEED_GYRO_MilliDPS_Data_UPER
int Decode_UPER_GYRO_MilliDPS_Data(asn1SccGYRO_MilliDPS_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_GYRO_MilliDPS_Data_ACN
int Decode_ACN_GYRO_MilliDPS_Data(asn1SccGYRO_MilliDPS_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_GYRO_MilliDPS_Data_NATIVE
int Decode_NATIVE_GYRO_MilliDPS_Data(asn1SccGYRO_MilliDPS_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_IMU_All_Data_UPER
int Encode_UPER_IMU_All_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccIMU_All_Data *pSrc);
#endif

#ifdef __NEED_IMU_All_Data_ACN
int Encode_ACN_IMU_All_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccIMU_All_Data *pSrc);
#endif

#ifdef __NEED_IMU_All_Data_NATIVE
int Encode_NATIVE_IMU_All_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccIMU_All_Data *pSrc);
#endif

#ifdef __NEED_IMU_All_Data_UPER
int Decode_UPER_IMU_All_Data(asn1SccIMU_All_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_IMU_All_Data_ACN
int Decode_ACN_IMU_All_Data(asn1SccIMU_All_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_IMU_All_Data_NATIVE
int Decode_NATIVE_IMU_All_Data(asn1SccIMU_All_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC74s_I2CBuses_UPER
int Encode_UPER_TC74s_I2CBuses(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC74s_I2CBuses *pSrc);
#endif

#ifdef __NEED_TC74s_I2CBuses_ACN
int Encode_ACN_TC74s_I2CBuses(void *pBuffer, size_t iMaxBufferSize, asn1SccTC74s_I2CBuses *pSrc);
#endif

#ifdef __NEED_TC74s_I2CBuses_NATIVE
int Encode_NATIVE_TC74s_I2CBuses(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC74s_I2CBuses *pSrc);
#endif

#ifdef __NEED_TC74s_I2CBuses_UPER
int Decode_UPER_TC74s_I2CBuses(asn1SccTC74s_I2CBuses *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC74s_I2CBuses_ACN
int Decode_ACN_TC74s_I2CBuses(asn1SccTC74s_I2CBuses *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC74s_I2CBuses_NATIVE
int Decode_NATIVE_TC74s_I2CBuses(asn1SccTC74s_I2CBuses *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC74s_All_Data_UPER
int Encode_UPER_TC74s_All_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC74s_All_Data *pSrc);
#endif

#ifdef __NEED_TC74s_All_Data_ACN
int Encode_ACN_TC74s_All_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccTC74s_All_Data *pSrc);
#endif

#ifdef __NEED_TC74s_All_Data_NATIVE
int Encode_NATIVE_TC74s_All_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC74s_All_Data *pSrc);
#endif

#ifdef __NEED_TC74s_All_Data_UPER
int Decode_UPER_TC74s_All_Data(asn1SccTC74s_All_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC74s_All_Data_ACN
int Decode_ACN_TC74s_All_Data(asn1SccTC74s_All_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC74s_All_Data_NATIVE
int Decode_NATIVE_TC74s_All_Data(asn1SccTC74s_All_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PT1000s_Channels_UPER
int Encode_UPER_PT1000s_Channels(void *pBuffer, size_t iMaxBufferSize, const asn1SccPT1000s_Channels *pSrc);
#endif

#ifdef __NEED_PT1000s_Channels_ACN
int Encode_ACN_PT1000s_Channels(void *pBuffer, size_t iMaxBufferSize, asn1SccPT1000s_Channels *pSrc);
#endif

#ifdef __NEED_PT1000s_Channels_NATIVE
int Encode_NATIVE_PT1000s_Channels(void *pBuffer, size_t iMaxBufferSize, const asn1SccPT1000s_Channels *pSrc);
#endif

#ifdef __NEED_PT1000s_Channels_UPER
int Decode_UPER_PT1000s_Channels(asn1SccPT1000s_Channels *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PT1000s_Channels_ACN
int Decode_ACN_PT1000s_Channels(asn1SccPT1000s_Channels *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PT1000s_Channels_NATIVE
int Decode_NATIVE_PT1000s_Channels(asn1SccPT1000s_Channels *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PT1000s_Raw_Data_UPER
int Encode_UPER_PT1000s_Raw_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPT1000s_Raw_Data *pSrc);
#endif

#ifdef __NEED_PT1000s_Raw_Data_ACN
int Encode_ACN_PT1000s_Raw_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPT1000s_Raw_Data *pSrc);
#endif

#ifdef __NEED_PT1000s_Raw_Data_NATIVE
int Encode_NATIVE_PT1000s_Raw_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPT1000s_Raw_Data *pSrc);
#endif

#ifdef __NEED_PT1000s_Raw_Data_UPER
int Decode_UPER_PT1000s_Raw_Data(asn1SccPT1000s_Raw_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PT1000s_Raw_Data_ACN
int Decode_ACN_PT1000s_Raw_Data(asn1SccPT1000s_Raw_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PT1000s_Raw_Data_NATIVE
int Decode_NATIVE_PT1000s_Raw_Data(asn1SccPT1000s_Raw_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PT1000s_Celsius_Data_UPER
int Encode_UPER_PT1000s_Celsius_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPT1000s_Celsius_Data *pSrc);
#endif

#ifdef __NEED_PT1000s_Celsius_Data_ACN
int Encode_ACN_PT1000s_Celsius_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPT1000s_Celsius_Data *pSrc);
#endif

#ifdef __NEED_PT1000s_Celsius_Data_NATIVE
int Encode_NATIVE_PT1000s_Celsius_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPT1000s_Celsius_Data *pSrc);
#endif

#ifdef __NEED_PT1000s_Celsius_Data_UPER
int Decode_UPER_PT1000s_Celsius_Data(asn1SccPT1000s_Celsius_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PT1000s_Celsius_Data_ACN
int Decode_ACN_PT1000s_Celsius_Data(asn1SccPT1000s_Celsius_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PT1000s_Celsius_Data_NATIVE
int Decode_NATIVE_PT1000s_Celsius_Data(asn1SccPT1000s_Celsius_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PT1000s_All_Data_UPER
int Encode_UPER_PT1000s_All_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPT1000s_All_Data *pSrc);
#endif

#ifdef __NEED_PT1000s_All_Data_ACN
int Encode_ACN_PT1000s_All_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPT1000s_All_Data *pSrc);
#endif

#ifdef __NEED_PT1000s_All_Data_NATIVE
int Encode_NATIVE_PT1000s_All_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPT1000s_All_Data *pSrc);
#endif

#ifdef __NEED_PT1000s_All_Data_UPER
int Decode_UPER_PT1000s_All_Data(asn1SccPT1000s_All_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PT1000s_All_Data_ACN
int Decode_ACN_PT1000s_All_Data(asn1SccPT1000s_All_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PT1000s_All_Data_NATIVE
int Decode_NATIVE_PT1000s_All_Data(asn1SccPT1000s_All_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PS_Calibration_Data_UPER
int Encode_UPER_PS_Calibration_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPS_Calibration_Data *pSrc);
#endif

#ifdef __NEED_PS_Calibration_Data_ACN
int Encode_ACN_PS_Calibration_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPS_Calibration_Data *pSrc);
#endif

#ifdef __NEED_PS_Calibration_Data_NATIVE
int Encode_NATIVE_PS_Calibration_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPS_Calibration_Data *pSrc);
#endif

#ifdef __NEED_PS_Calibration_Data_UPER
int Decode_UPER_PS_Calibration_Data(asn1SccPS_Calibration_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PS_Calibration_Data_ACN
int Decode_ACN_PS_Calibration_Data(asn1SccPS_Calibration_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PS_Calibration_Data_NATIVE
int Decode_NATIVE_PS_Calibration_Data(asn1SccPS_Calibration_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PS_Raw_Data_UPER
int Encode_UPER_PS_Raw_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPS_Raw_Data *pSrc);
#endif

#ifdef __NEED_PS_Raw_Data_ACN
int Encode_ACN_PS_Raw_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPS_Raw_Data *pSrc);
#endif

#ifdef __NEED_PS_Raw_Data_NATIVE
int Encode_NATIVE_PS_Raw_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPS_Raw_Data *pSrc);
#endif

#ifdef __NEED_PS_Raw_Data_UPER
int Decode_UPER_PS_Raw_Data(asn1SccPS_Raw_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PS_Raw_Data_ACN
int Decode_ACN_PS_Raw_Data(asn1SccPS_Raw_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PS_Raw_Data_NATIVE
int Decode_NATIVE_PS_Raw_Data(asn1SccPS_Raw_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PS_Processed_Data_UPER
int Encode_UPER_PS_Processed_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPS_Processed_Data *pSrc);
#endif

#ifdef __NEED_PS_Processed_Data_ACN
int Encode_ACN_PS_Processed_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPS_Processed_Data *pSrc);
#endif

#ifdef __NEED_PS_Processed_Data_NATIVE
int Encode_NATIVE_PS_Processed_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPS_Processed_Data *pSrc);
#endif

#ifdef __NEED_PS_Processed_Data_UPER
int Decode_UPER_PS_Processed_Data(asn1SccPS_Processed_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PS_Processed_Data_ACN
int Decode_ACN_PS_Processed_Data(asn1SccPS_Processed_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PS_Processed_Data_NATIVE
int Decode_NATIVE_PS_Processed_Data(asn1SccPS_Processed_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PS_All_Data_UPER
int Encode_UPER_PS_All_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPS_All_Data *pSrc);
#endif

#ifdef __NEED_PS_All_Data_ACN
int Encode_ACN_PS_All_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPS_All_Data *pSrc);
#endif

#ifdef __NEED_PS_All_Data_NATIVE
int Encode_NATIVE_PS_All_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPS_All_Data *pSrc);
#endif

#ifdef __NEED_PS_All_Data_UPER
int Decode_UPER_PS_All_Data(asn1SccPS_All_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PS_All_Data_ACN
int Decode_ACN_PS_All_Data(asn1SccPS_All_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PS_All_Data_NATIVE
int Decode_NATIVE_PS_All_Data(asn1SccPS_All_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Heater_Data_UPER
int Encode_UPER_Heater_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccHeater_Data *pSrc);
#endif

#ifdef __NEED_Heater_Data_ACN
int Encode_ACN_Heater_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccHeater_Data *pSrc);
#endif

#ifdef __NEED_Heater_Data_NATIVE
int Encode_NATIVE_Heater_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccHeater_Data *pSrc);
#endif

#ifdef __NEED_Heater_Data_UPER
int Decode_UPER_Heater_Data(asn1SccHeater_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Heater_Data_ACN
int Decode_ACN_Heater_Data(asn1SccHeater_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Heater_Data_NATIVE
int Decode_NATIVE_Heater_Data(asn1SccHeater_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Heater_On_Off_UPER
int Encode_UPER_Heater_On_Off(void *pBuffer, size_t iMaxBufferSize, const asn1SccHeater_On_Off *pSrc);
#endif

#ifdef __NEED_Heater_On_Off_ACN
int Encode_ACN_Heater_On_Off(void *pBuffer, size_t iMaxBufferSize, asn1SccHeater_On_Off *pSrc);
#endif

#ifdef __NEED_Heater_On_Off_NATIVE
int Encode_NATIVE_Heater_On_Off(void *pBuffer, size_t iMaxBufferSize, const asn1SccHeater_On_Off *pSrc);
#endif

#ifdef __NEED_Heater_On_Off_UPER
int Decode_UPER_Heater_On_Off(asn1SccHeater_On_Off *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Heater_On_Off_ACN
int Decode_ACN_Heater_On_Off(asn1SccHeater_On_Off *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Heater_On_Off_NATIVE
int Decode_NATIVE_Heater_On_Off(asn1SccHeater_On_Off *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HTL_State_UPER
int Encode_UPER_HTL_State(void *pBuffer, size_t iMaxBufferSize, const asn1SccHTL_State *pSrc);
#endif

#ifdef __NEED_HTL_State_ACN
int Encode_ACN_HTL_State(void *pBuffer, size_t iMaxBufferSize, asn1SccHTL_State *pSrc);
#endif

#ifdef __NEED_HTL_State_NATIVE
int Encode_NATIVE_HTL_State(void *pBuffer, size_t iMaxBufferSize, const asn1SccHTL_State *pSrc);
#endif

#ifdef __NEED_HTL_State_UPER
int Decode_UPER_HTL_State(asn1SccHTL_State *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HTL_State_ACN
int Decode_ACN_HTL_State(asn1SccHTL_State *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HTL_State_NATIVE
int Decode_NATIVE_HTL_State(asn1SccHTL_State *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HTL_Config_UPER
int Encode_UPER_HTL_Config(void *pBuffer, size_t iMaxBufferSize, const asn1SccHTL_Config *pSrc);
#endif

#ifdef __NEED_HTL_Config_ACN
int Encode_ACN_HTL_Config(void *pBuffer, size_t iMaxBufferSize, asn1SccHTL_Config *pSrc);
#endif

#ifdef __NEED_HTL_Config_NATIVE
int Encode_NATIVE_HTL_Config(void *pBuffer, size_t iMaxBufferSize, const asn1SccHTL_Config *pSrc);
#endif

#ifdef __NEED_HTL_Config_UPER
int Decode_UPER_HTL_Config(asn1SccHTL_Config *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HTL_Config_ACN
int Decode_ACN_HTL_Config(asn1SccHTL_Config *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HTL_Config_NATIVE
int Decode_NATIVE_HTL_Config(asn1SccHTL_Config *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_OBSW_DP_Data_UPER
int Encode_UPER_OBSW_DP_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccOBSW_DP_Data *pSrc);
#endif

#ifdef __NEED_OBSW_DP_Data_ACN
int Encode_ACN_OBSW_DP_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccOBSW_DP_Data *pSrc);
#endif

#ifdef __NEED_OBSW_DP_Data_NATIVE
int Encode_NATIVE_OBSW_DP_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccOBSW_DP_Data *pSrc);
#endif

#ifdef __NEED_OBSW_DP_Data_UPER
int Decode_UPER_OBSW_DP_Data(asn1SccOBSW_DP_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_OBSW_DP_Data_ACN
int Decode_ACN_OBSW_DP_Data(asn1SccOBSW_DP_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_OBSW_DP_Data_NATIVE
int Decode_NATIVE_OBSW_DP_Data(asn1SccOBSW_DP_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_OBSW_DP_SingleData_UPER
int Encode_UPER_OBSW_DP_SingleData(void *pBuffer, size_t iMaxBufferSize, const asn1SccOBSW_DP_SingleData *pSrc);
#endif

#ifdef __NEED_OBSW_DP_SingleData_ACN
int Encode_ACN_OBSW_DP_SingleData(void *pBuffer, size_t iMaxBufferSize, asn1SccOBSW_DP_SingleData *pSrc);
#endif

#ifdef __NEED_OBSW_DP_SingleData_NATIVE
int Encode_NATIVE_OBSW_DP_SingleData(void *pBuffer, size_t iMaxBufferSize, const asn1SccOBSW_DP_SingleData *pSrc);
#endif

#ifdef __NEED_OBSW_DP_SingleData_UPER
int Decode_UPER_OBSW_DP_SingleData(asn1SccOBSW_DP_SingleData *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_OBSW_DP_SingleData_ACN
int Decode_ACN_OBSW_DP_SingleData(asn1SccOBSW_DP_SingleData *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_OBSW_DP_SingleData_NATIVE
int Decode_NATIVE_OBSW_DP_SingleData(asn1SccOBSW_DP_SingleData *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_OBSW_DP_Filter_UPER
int Encode_UPER_OBSW_DP_Filter(void *pBuffer, size_t iMaxBufferSize, const asn1SccOBSW_DP_Filter *pSrc);
#endif

#ifdef __NEED_OBSW_DP_Filter_ACN
int Encode_ACN_OBSW_DP_Filter(void *pBuffer, size_t iMaxBufferSize, asn1SccOBSW_DP_Filter *pSrc);
#endif

#ifdef __NEED_OBSW_DP_Filter_NATIVE
int Encode_NATIVE_OBSW_DP_Filter(void *pBuffer, size_t iMaxBufferSize, const asn1SccOBSW_DP_Filter *pSrc);
#endif

#ifdef __NEED_OBSW_DP_Filter_UPER
int Decode_UPER_OBSW_DP_Filter(asn1SccOBSW_DP_Filter *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_OBSW_DP_Filter_ACN
int Decode_ACN_OBSW_DP_Filter(asn1SccOBSW_DP_Filter *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_OBSW_DP_Filter_NATIVE
int Decode_NATIVE_OBSW_DP_Filter(asn1SccOBSW_DP_Filter *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TM_UPER
int Encode_UPER_TM(void *pBuffer, size_t iMaxBufferSize, const asn1SccTM *pSrc);
#endif

#ifdef __NEED_TM_ACN
int Encode_ACN_TM(void *pBuffer, size_t iMaxBufferSize, asn1SccTM *pSrc);
#endif

#ifdef __NEED_TM_NATIVE
int Encode_NATIVE_TM(void *pBuffer, size_t iMaxBufferSize, const asn1SccTM *pSrc);
#endif

#ifdef __NEED_TM_UPER
int Decode_UPER_TM(asn1SccTM *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TM_ACN
int Decode_ACN_TM(asn1SccTM *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TM_NATIVE
int Decode_NATIVE_TM(asn1SccTM *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_UPER
int Encode_UPER_TC(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC *pSrc);
#endif

#ifdef __NEED_TC_ACN
int Encode_ACN_TC(void *pBuffer, size_t iMaxBufferSize, asn1SccTC *pSrc);
#endif

#ifdef __NEED_TC_NATIVE
int Encode_NATIVE_TC(void *pBuffer, size_t iMaxBufferSize, const asn1SccTC *pSrc);
#endif

#ifdef __NEED_TC_UPER
int Decode_UPER_TC(asn1SccTC *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_ACN
int Decode_ACN_TC(asn1SccTC *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TC_NATIVE
int Decode_NATIVE_TC(asn1SccTC *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HTL_GUI_UPER
int Encode_UPER_HTL_GUI(void *pBuffer, size_t iMaxBufferSize, const asn1SccHTL_GUI *pSrc);
#endif

#ifdef __NEED_HTL_GUI_ACN
int Encode_ACN_HTL_GUI(void *pBuffer, size_t iMaxBufferSize, asn1SccHTL_GUI *pSrc);
#endif

#ifdef __NEED_HTL_GUI_NATIVE
int Encode_NATIVE_HTL_GUI(void *pBuffer, size_t iMaxBufferSize, const asn1SccHTL_GUI *pSrc);
#endif

#ifdef __NEED_HTL_GUI_UPER
int Decode_UPER_HTL_GUI(asn1SccHTL_GUI *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HTL_GUI_ACN
int Decode_ACN_HTL_GUI(asn1SccHTL_GUI *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HTL_GUI_NATIVE
int Decode_NATIVE_HTL_GUI(asn1SccHTL_GUI *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Date_Time_UPER
int Encode_UPER_Date_Time(void *pBuffer, size_t iMaxBufferSize, const asn1SccDate_Time *pSrc);
#endif

#ifdef __NEED_Date_Time_ACN
int Encode_ACN_Date_Time(void *pBuffer, size_t iMaxBufferSize, asn1SccDate_Time *pSrc);
#endif

#ifdef __NEED_Date_Time_NATIVE
int Encode_NATIVE_Date_Time(void *pBuffer, size_t iMaxBufferSize, const asn1SccDate_Time *pSrc);
#endif

#ifdef __NEED_Date_Time_UPER
int Decode_UPER_Date_Time(asn1SccDate_Time *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Date_Time_ACN
int Decode_ACN_Date_Time(asn1SccDate_Time *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Date_Time_NATIVE
int Decode_NATIVE_Date_Time(asn1SccDate_Time *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ATT_GUI_UPER
int Encode_UPER_ATT_GUI(void *pBuffer, size_t iMaxBufferSize, const asn1SccATT_GUI *pSrc);
#endif

#ifdef __NEED_ATT_GUI_ACN
int Encode_ACN_ATT_GUI(void *pBuffer, size_t iMaxBufferSize, asn1SccATT_GUI *pSrc);
#endif

#ifdef __NEED_ATT_GUI_NATIVE
int Encode_NATIVE_ATT_GUI(void *pBuffer, size_t iMaxBufferSize, const asn1SccATT_GUI *pSrc);
#endif

#ifdef __NEED_ATT_GUI_UPER
int Decode_UPER_ATT_GUI(asn1SccATT_GUI *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ATT_GUI_ACN
int Decode_ACN_ATT_GUI(asn1SccATT_GUI *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ATT_GUI_NATIVE
int Decode_NATIVE_ATT_GUI(asn1SccATT_GUI *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PS_GUI_UPER
int Encode_UPER_PS_GUI(void *pBuffer, size_t iMaxBufferSize, const asn1SccPS_GUI *pSrc);
#endif

#ifdef __NEED_PS_GUI_ACN
int Encode_ACN_PS_GUI(void *pBuffer, size_t iMaxBufferSize, asn1SccPS_GUI *pSrc);
#endif

#ifdef __NEED_PS_GUI_NATIVE
int Encode_NATIVE_PS_GUI(void *pBuffer, size_t iMaxBufferSize, const asn1SccPS_GUI *pSrc);
#endif

#ifdef __NEED_PS_GUI_UPER
int Decode_UPER_PS_GUI(asn1SccPS_GUI *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PS_GUI_ACN
int Decode_ACN_PS_GUI(asn1SccPS_GUI *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PS_GUI_NATIVE
int Decode_NATIVE_PS_GUI(asn1SccPS_GUI *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ENV_GUI_UPER
int Encode_UPER_ENV_GUI(void *pBuffer, size_t iMaxBufferSize, const asn1SccENV_GUI *pSrc);
#endif

#ifdef __NEED_ENV_GUI_ACN
int Encode_ACN_ENV_GUI(void *pBuffer, size_t iMaxBufferSize, asn1SccENV_GUI *pSrc);
#endif

#ifdef __NEED_ENV_GUI_NATIVE
int Encode_NATIVE_ENV_GUI(void *pBuffer, size_t iMaxBufferSize, const asn1SccENV_GUI *pSrc);
#endif

#ifdef __NEED_ENV_GUI_UPER
int Decode_UPER_ENV_GUI(asn1SccENV_GUI *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ENV_GUI_ACN
int Decode_ACN_ENV_GUI(asn1SccENV_GUI *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ENV_GUI_NATIVE
int Decode_NATIVE_ENV_GUI(asn1SccENV_GUI *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int32_UPER
int Encode_UPER_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc);
#endif

#ifdef __NEED_T_Int32_ACN
int Encode_ACN_T_Int32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int32 *pSrc);
#endif

#ifdef __NEED_T_Int32_NATIVE
int Encode_NATIVE_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc);
#endif

#ifdef __NEED_T_Int32_UPER
int Decode_UPER_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int32_ACN
int Decode_ACN_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int32_NATIVE
int Decode_NATIVE_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt32_UPER
int Encode_UPER_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc);
#endif

#ifdef __NEED_T_UInt32_ACN
int Encode_ACN_T_UInt32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt32 *pSrc);
#endif

#ifdef __NEED_T_UInt32_NATIVE
int Encode_NATIVE_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc);
#endif

#ifdef __NEED_T_UInt32_UPER
int Decode_UPER_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt32_ACN
int Decode_ACN_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt32_NATIVE
int Decode_NATIVE_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int8_UPER
int Encode_UPER_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc);
#endif

#ifdef __NEED_T_Int8_ACN
int Encode_ACN_T_Int8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int8 *pSrc);
#endif

#ifdef __NEED_T_Int8_NATIVE
int Encode_NATIVE_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc);
#endif

#ifdef __NEED_T_Int8_UPER
int Decode_UPER_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int8_ACN
int Decode_ACN_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int8_NATIVE
int Decode_NATIVE_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt8_UPER
int Encode_UPER_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc);
#endif

#ifdef __NEED_T_UInt8_ACN
int Encode_ACN_T_UInt8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt8 *pSrc);
#endif

#ifdef __NEED_T_UInt8_NATIVE
int Encode_NATIVE_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc);
#endif

#ifdef __NEED_T_UInt8_UPER
int Decode_UPER_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt8_ACN
int Decode_ACN_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt8_NATIVE
int Decode_NATIVE_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Boolean_UPER
int Encode_UPER_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc);
#endif

#ifdef __NEED_T_Boolean_ACN
int Encode_ACN_T_Boolean(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Boolean *pSrc);
#endif

#ifdef __NEED_T_Boolean_NATIVE
int Encode_NATIVE_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc);
#endif

#ifdef __NEED_T_Boolean_UPER
int Decode_UPER_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Boolean_ACN
int Decode_ACN_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Boolean_NATIVE
int Decode_NATIVE_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Null_Record_UPER
int Encode_UPER_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Null_Record *pSrc);
#endif

#ifdef __NEED_T_Null_Record_ACN
int Encode_ACN_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Null_Record *pSrc);
#endif

#ifdef __NEED_T_Null_Record_NATIVE
int Encode_NATIVE_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Null_Record *pSrc);
#endif

#ifdef __NEED_T_Null_Record_UPER
int Decode_UPER_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Null_Record_ACN
int Decode_ACN_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Null_Record_NATIVE
int Decode_NATIVE_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize);
#endif


#endif
