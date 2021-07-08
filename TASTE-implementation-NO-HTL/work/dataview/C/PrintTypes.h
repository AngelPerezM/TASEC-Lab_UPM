#ifndef __PRINTTYPES_H__
#define __PRINTTYPES_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "dataview-uniq.h" // Generated by ASN1SCC

void PrintT_Int16(const char *paramName, const asn1SccT_Int16 *pData);
void PrintT_UInt16(const char *paramName, const asn1SccT_UInt16 *pData);
void PrintT_UInt64(const char *paramName, const asn1SccT_UInt64 *pData);
void PrintT_Float(const char *paramName, const asn1SccT_Float *pData);
void PrintT_Double(const char *paramName, const asn1SccT_Double *pData);
void PrintFile_Name(const char *paramName, const asn1SccFile_Name *pData);
void PrintContent_Validity(const char *paramName, const asn1SccContent_Validity *pData);
void PrintSPI_ID(const char *paramName, const asn1SccSPI_ID *pData);
void PrintI2C_ID(const char *paramName, const asn1SccI2C_ID *pData);
void PrintGPS_PVT(const char *paramName, const asn1SccGPS_PVT *pData);
void PrintMGT_Raw_Data(const char *paramName, const asn1SccMGT_Raw_Data *pData);
void PrintMGT_MilliGauss_Data(const char *paramName, const asn1SccMGT_MilliGauss_Data *pData);
void PrintACC_Raw_Data(const char *paramName, const asn1SccACC_Raw_Data *pData);
void PrintACC_MilliG_Data(const char *paramName, const asn1SccACC_MilliG_Data *pData);
void PrintGYRO_Raw_Data(const char *paramName, const asn1SccGYRO_Raw_Data *pData);
void PrintGYRO_MilliDPS_Data(const char *paramName, const asn1SccGYRO_MilliDPS_Data *pData);
void PrintIMU_All_Data(const char *paramName, const asn1SccIMU_All_Data *pData);
void PrintTC74s_I2CBuses(const char *paramName, const asn1SccTC74s_I2CBuses *pData);
void PrintTC74s_All_Data(const char *paramName, const asn1SccTC74s_All_Data *pData);
void PrintPT1000s_Channels(const char *paramName, const asn1SccPT1000s_Channels *pData);
void PrintPT1000s_Raw_Data(const char *paramName, const asn1SccPT1000s_Raw_Data *pData);
void PrintPT1000s_Celsius_Data(const char *paramName, const asn1SccPT1000s_Celsius_Data *pData);
void PrintPT1000s_All_Data(const char *paramName, const asn1SccPT1000s_All_Data *pData);
void PrintPS_Calibration_Data(const char *paramName, const asn1SccPS_Calibration_Data *pData);
void PrintPS_Raw_Data(const char *paramName, const asn1SccPS_Raw_Data *pData);
void PrintPS_Processed_Data(const char *paramName, const asn1SccPS_Processed_Data *pData);
void PrintPS_All_Data(const char *paramName, const asn1SccPS_All_Data *pData);
void PrintHeater_Data(const char *paramName, const asn1SccHeater_Data *pData);
void PrintHeater_On_Off(const char *paramName, const asn1SccHeater_On_Off *pData);
void PrintHTL_State(const char *paramName, const asn1SccHTL_State *pData);
void PrintHTL_Config(const char *paramName, const asn1SccHTL_Config *pData);
void PrintOBSW_DP_Data(const char *paramName, const asn1SccOBSW_DP_Data *pData);
void PrintOBSW_DP_Filter(const char *paramName, const asn1SccOBSW_DP_Filter *pData);
void PrintOBSW_DP_SingleData(const char *paramName, const asn1SccOBSW_DP_SingleData *pData);
void PrintTM(const char *paramName, const asn1SccTM *pData);
void PrintTC_Heater(const char *paramName, const asn1SccTC_Heater *pData);
void PrintTC(const char *paramName, const asn1SccTC *pData);
void PrintHTL_GUI(const char *paramName, const asn1SccHTL_GUI *pData);
void PrintDate_Time(const char *paramName, const asn1SccDate_Time *pData);
void PrintATT_GUI(const char *paramName, const asn1SccATT_GUI *pData);
void PrintPS_GUI(const char *paramName, const asn1SccPS_GUI *pData);
void PrintENV_GUI(const char *paramName, const asn1SccENV_GUI *pData);
void PrintT_Int32(const char *paramName, const asn1SccT_Int32 *pData);
void PrintT_UInt32(const char *paramName, const asn1SccT_UInt32 *pData);
void PrintT_Int8(const char *paramName, const asn1SccT_Int8 *pData);
void PrintT_UInt8(const char *paramName, const asn1SccT_UInt8 *pData);
void PrintT_Boolean(const char *paramName, const asn1SccT_Boolean *pData);
void PrintT_Null_Record(const char *paramName, const asn1SccT_Null_Record *pData);

#ifdef __cplusplus
}
#endif

#endif