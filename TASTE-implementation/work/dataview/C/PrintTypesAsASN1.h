#ifndef __PRINTTYPESASASN1_H__
#define __PRINTTYPESASASN1_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "dataview-uniq.h" // Generated by ASN1SCC

void PrintASN1T_Int16(const char *paramName, const asn1SccT_Int16 *pData);
void PrintASN1T_UInt16(const char *paramName, const asn1SccT_UInt16 *pData);
void PrintASN1T_UInt64(const char *paramName, const asn1SccT_UInt64 *pData);
void PrintASN1T_Float(const char *paramName, const asn1SccT_Float *pData);
void PrintASN1T_Double(const char *paramName, const asn1SccT_Double *pData);
void PrintASN1File_Name(const char *paramName, const asn1SccFile_Name *pData);
void PrintASN1Content_Validity(const char *paramName, const asn1SccContent_Validity *pData);
void PrintASN1SPI_ID(const char *paramName, const asn1SccSPI_ID *pData);
void PrintASN1I2C_ID(const char *paramName, const asn1SccI2C_ID *pData);
void PrintASN1GPS_PVT(const char *paramName, const asn1SccGPS_PVT *pData);
void PrintASN1MGT_Raw_Data(const char *paramName, const asn1SccMGT_Raw_Data *pData);
void PrintASN1MGT_MilliGauss_Data(const char *paramName, const asn1SccMGT_MilliGauss_Data *pData);
void PrintASN1ACC_Raw_Data(const char *paramName, const asn1SccACC_Raw_Data *pData);
void PrintASN1ACC_MilliG_Data(const char *paramName, const asn1SccACC_MilliG_Data *pData);
void PrintASN1GYRO_Raw_Data(const char *paramName, const asn1SccGYRO_Raw_Data *pData);
void PrintASN1GYRO_MilliDPS_Data(const char *paramName, const asn1SccGYRO_MilliDPS_Data *pData);
void PrintASN1IMU_All_Data(const char *paramName, const asn1SccIMU_All_Data *pData);
void PrintASN1TC74s_I2CBuses(const char *paramName, const asn1SccTC74s_I2CBuses *pData);
void PrintASN1TC74s_All_Data(const char *paramName, const asn1SccTC74s_All_Data *pData);
void PrintASN1PT1000s_Channels(const char *paramName, const asn1SccPT1000s_Channels *pData);
void PrintASN1PT1000s_Raw_Data(const char *paramName, const asn1SccPT1000s_Raw_Data *pData);
void PrintASN1PT1000s_Celsius_Data(const char *paramName, const asn1SccPT1000s_Celsius_Data *pData);
void PrintASN1PT1000s_All_Data(const char *paramName, const asn1SccPT1000s_All_Data *pData);
void PrintASN1PS_Calibration_Data(const char *paramName, const asn1SccPS_Calibration_Data *pData);
void PrintASN1PS_Raw_Data(const char *paramName, const asn1SccPS_Raw_Data *pData);
void PrintASN1PS_Processed_Data(const char *paramName, const asn1SccPS_Processed_Data *pData);
void PrintASN1PS_All_Data(const char *paramName, const asn1SccPS_All_Data *pData);
void PrintASN1Heater_Data(const char *paramName, const asn1SccHeater_Data *pData);
void PrintASN1Heater_On_Off(const char *paramName, const asn1SccHeater_On_Off *pData);
void PrintASN1HTL_State(const char *paramName, const asn1SccHTL_State *pData);
void PrintASN1HTL_Config(const char *paramName, const asn1SccHTL_Config *pData);
void PrintASN1OBSW_DP_Data(const char *paramName, const asn1SccOBSW_DP_Data *pData);
void PrintASN1OBSW_DP_Filter(const char *paramName, const asn1SccOBSW_DP_Filter *pData);
void PrintASN1OBSW_DP_SingleData(const char *paramName, const asn1SccOBSW_DP_SingleData *pData);
void PrintASN1IMU_Queue(const char *paramName, const asn1SccIMU_Queue *pData);
void PrintASN1TM(const char *paramName, const asn1SccTM *pData);
void PrintASN1TC_Heater(const char *paramName, const asn1SccTC_Heater *pData);
void PrintASN1TC(const char *paramName, const asn1SccTC *pData);
void PrintASN1HTL_GUI(const char *paramName, const asn1SccHTL_GUI *pData);
void PrintASN1Date_Time(const char *paramName, const asn1SccDate_Time *pData);
void PrintASN1ATT_GUI(const char *paramName, const asn1SccATT_GUI *pData);
void PrintASN1PS_GUI(const char *paramName, const asn1SccPS_GUI *pData);
void PrintASN1ENV_GUI(const char *paramName, const asn1SccENV_GUI *pData);
void PrintASN1T_Int32(const char *paramName, const asn1SccT_Int32 *pData);
void PrintASN1T_UInt32(const char *paramName, const asn1SccT_UInt32 *pData);
void PrintASN1T_Int8(const char *paramName, const asn1SccT_Int8 *pData);
void PrintASN1T_UInt8(const char *paramName, const asn1SccT_UInt8 *pData);
void PrintASN1T_Boolean(const char *paramName, const asn1SccT_Boolean *pData);
void PrintASN1T_Null_Record(const char *paramName, const asn1SccT_Null_Record *pData);

#ifdef __cplusplus
}
#endif

#endif
