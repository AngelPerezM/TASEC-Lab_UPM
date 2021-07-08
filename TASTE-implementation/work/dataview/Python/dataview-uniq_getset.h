#ifndef __GETSET_H__
#define __GETSET_H__

#include "dataview-uniq.h"

size_t GetStreamCurrentLength(BitStream *pBitStrm);
byte *GetBitstreamBuffer(BitStream *pBitStrm);
byte GetBufferByte(byte *p, size_t off);
void SetBufferByte(byte *p, size_t off, byte b);
void ResetStream(BitStream *pStrm);
BitStream *CreateStream(size_t bufferSize);
void DestroyStream(BitStream *pBitStrm);


/* INTEGER */
asn1SccSint T_Int16__Get(T_Int16* root);

/* INTEGER */
void T_Int16__Set(T_Int16* root, asn1SccSint value);

/* INTEGER */
asn1SccSint T_UInt16__Get(T_UInt16* root);

/* INTEGER */
void T_UInt16__Set(T_UInt16* root, asn1SccSint value);

/* INTEGER */
asn1SccSint T_UInt64__Get(T_UInt64* root);

/* INTEGER */
void T_UInt64__Set(T_UInt64* root, asn1SccSint value);

/* REAL */
double T_Float__Get(T_Float* root);

/* REAL */
void T_Float__Set(T_Float* root, double value);

/* REAL */
double T_Double__Get(T_Double* root);

/* REAL */
void T_Double__Set(T_Double* root, double value);

/* OCTETSTRING */
long File_Name__GetLength(File_Name* root);

/* OCTETSTRING */
void File_Name__SetLength(File_Name* root, long value);

/* OCTETSTRING_bytes */
byte File_Name__iDx_Get(File_Name* root, int iDx);

/* OCTETSTRING_bytes */
void File_Name__iDx_Set(File_Name* root, int iDx, byte value);

/* ENUMERATED */
int Content_Validity__Get(Content_Validity* root);

/* ENUMERATED */
void Content_Validity__Set(Content_Validity* root, int value);

/* INTEGER */
asn1SccSint WD_TIMEOUT__Get(WD_TIMEOUT* root);

/* INTEGER */
void WD_TIMEOUT__Set(WD_TIMEOUT* root, asn1SccSint value);

/* INTEGER */
asn1SccSint SPI_ID__bus_Get(SPI_ID* root);

/* INTEGER */
void SPI_ID__bus_Set(SPI_ID* root, asn1SccSint value);

/* INTEGER */
asn1SccSint SPI_ID__cs_Get(SPI_ID* root);

/* INTEGER */
void SPI_ID__cs_Set(SPI_ID* root, asn1SccSint value);

/* INTEGER */
asn1SccSint I2C_ID__bus_Get(I2C_ID* root);

/* INTEGER */
void I2C_ID__bus_Set(I2C_ID* root, asn1SccSint value);

/* INTEGER */
asn1SccSint I2C_ID__address_Get(I2C_ID* root);

/* INTEGER */
void I2C_ID__address_Set(I2C_ID* root, asn1SccSint value);

/* ENUMERATED */
int GPS_PVT__mode_Get(GPS_PVT* root);

/* ENUMERATED */
void GPS_PVT__mode_Set(GPS_PVT* root, int value);

/* REAL */
double GPS_PVT__date_and_time_Get(GPS_PVT* root);

/* REAL */
void GPS_PVT__date_and_time_Set(GPS_PVT* root, double value);

/* REAL */
double GPS_PVT__ept_Get(GPS_PVT* root);

/* REAL */
void GPS_PVT__ept_Set(GPS_PVT* root, double value);

/* REAL */
double GPS_PVT__latitude_Get(GPS_PVT* root);

/* REAL */
void GPS_PVT__latitude_Set(GPS_PVT* root, double value);

/* REAL */
double GPS_PVT__epy_Get(GPS_PVT* root);

/* REAL */
void GPS_PVT__epy_Set(GPS_PVT* root, double value);

/* REAL */
double GPS_PVT__longitude_Get(GPS_PVT* root);

/* REAL */
void GPS_PVT__longitude_Set(GPS_PVT* root, double value);

/* REAL */
double GPS_PVT__epx_Get(GPS_PVT* root);

/* REAL */
void GPS_PVT__epx_Set(GPS_PVT* root, double value);

/* REAL */
double GPS_PVT__altitude_Get(GPS_PVT* root);

/* REAL */
void GPS_PVT__altitude_Set(GPS_PVT* root, double value);

/* REAL */
double GPS_PVT__epv_Get(GPS_PVT* root);

/* REAL */
void GPS_PVT__epv_Set(GPS_PVT* root, double value);

/* REAL */
double GPS_PVT__course_Get(GPS_PVT* root);

/* REAL */
void GPS_PVT__course_Set(GPS_PVT* root, double value);

/* REAL */
double GPS_PVT__epd_Get(GPS_PVT* root);

/* REAL */
void GPS_PVT__epd_Set(GPS_PVT* root, double value);

/* REAL */
double GPS_PVT__speed_Get(GPS_PVT* root);

/* REAL */
void GPS_PVT__speed_Set(GPS_PVT* root, double value);

/* REAL */
double GPS_PVT__eps_Get(GPS_PVT* root);

/* REAL */
void GPS_PVT__eps_Set(GPS_PVT* root, double value);

/* REAL */
double GPS_PVT__climb_Get(GPS_PVT* root);

/* REAL */
void GPS_PVT__climb_Set(GPS_PVT* root, double value);

/* REAL */
double GPS_PVT__epc_Get(GPS_PVT* root);

/* REAL */
void GPS_PVT__epc_Set(GPS_PVT* root, double value);

/* INTEGER */
asn1SccSint MGT_Raw_Data__x_axis_Get(MGT_Raw_Data* root);

/* INTEGER */
void MGT_Raw_Data__x_axis_Set(MGT_Raw_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint MGT_Raw_Data__y_axis_Get(MGT_Raw_Data* root);

/* INTEGER */
void MGT_Raw_Data__y_axis_Set(MGT_Raw_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint MGT_Raw_Data__z_axis_Get(MGT_Raw_Data* root);

/* INTEGER */
void MGT_Raw_Data__z_axis_Set(MGT_Raw_Data* root, asn1SccSint value);

/* REAL */
double MGT_MilliGauss_Data__x_axis_Get(MGT_MilliGauss_Data* root);

/* REAL */
void MGT_MilliGauss_Data__x_axis_Set(MGT_MilliGauss_Data* root, double value);

/* REAL */
double MGT_MilliGauss_Data__y_axis_Get(MGT_MilliGauss_Data* root);

/* REAL */
void MGT_MilliGauss_Data__y_axis_Set(MGT_MilliGauss_Data* root, double value);

/* REAL */
double MGT_MilliGauss_Data__z_axis_Get(MGT_MilliGauss_Data* root);

/* REAL */
void MGT_MilliGauss_Data__z_axis_Set(MGT_MilliGauss_Data* root, double value);

/* INTEGER */
asn1SccSint ACC_Raw_Data__x_axis_Get(ACC_Raw_Data* root);

/* INTEGER */
void ACC_Raw_Data__x_axis_Set(ACC_Raw_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint ACC_Raw_Data__y_axis_Get(ACC_Raw_Data* root);

/* INTEGER */
void ACC_Raw_Data__y_axis_Set(ACC_Raw_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint ACC_Raw_Data__z_axis_Get(ACC_Raw_Data* root);

/* INTEGER */
void ACC_Raw_Data__z_axis_Set(ACC_Raw_Data* root, asn1SccSint value);

/* REAL */
double ACC_MilliG_Data__x_axis_Get(ACC_MilliG_Data* root);

/* REAL */
void ACC_MilliG_Data__x_axis_Set(ACC_MilliG_Data* root, double value);

/* REAL */
double ACC_MilliG_Data__y_axis_Get(ACC_MilliG_Data* root);

/* REAL */
void ACC_MilliG_Data__y_axis_Set(ACC_MilliG_Data* root, double value);

/* REAL */
double ACC_MilliG_Data__z_axis_Get(ACC_MilliG_Data* root);

/* REAL */
void ACC_MilliG_Data__z_axis_Set(ACC_MilliG_Data* root, double value);

/* INTEGER */
asn1SccSint GYRO_Raw_Data__x_axis_Get(GYRO_Raw_Data* root);

/* INTEGER */
void GYRO_Raw_Data__x_axis_Set(GYRO_Raw_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint GYRO_Raw_Data__y_axis_Get(GYRO_Raw_Data* root);

/* INTEGER */
void GYRO_Raw_Data__y_axis_Set(GYRO_Raw_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint GYRO_Raw_Data__z_axis_Get(GYRO_Raw_Data* root);

/* INTEGER */
void GYRO_Raw_Data__z_axis_Set(GYRO_Raw_Data* root, asn1SccSint value);

/* REAL */
double GYRO_MilliDPS_Data__x_axis_Get(GYRO_MilliDPS_Data* root);

/* REAL */
void GYRO_MilliDPS_Data__x_axis_Set(GYRO_MilliDPS_Data* root, double value);

/* REAL */
double GYRO_MilliDPS_Data__y_axis_Get(GYRO_MilliDPS_Data* root);

/* REAL */
void GYRO_MilliDPS_Data__y_axis_Set(GYRO_MilliDPS_Data* root, double value);

/* REAL */
double GYRO_MilliDPS_Data__z_axis_Get(GYRO_MilliDPS_Data* root);

/* REAL */
void GYRO_MilliDPS_Data__z_axis_Set(GYRO_MilliDPS_Data* root, double value);

/* Field mgt_raw selector */
MGT_Raw_Data* IMU_All_Data__mgt_raw_Get(IMU_All_Data* root);

/* INTEGER */
asn1SccSint IMU_All_Data__mgt_raw_x_axis_Get(IMU_All_Data* root);

/* INTEGER */
void IMU_All_Data__mgt_raw_x_axis_Set(IMU_All_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint IMU_All_Data__mgt_raw_y_axis_Get(IMU_All_Data* root);

/* INTEGER */
void IMU_All_Data__mgt_raw_y_axis_Set(IMU_All_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint IMU_All_Data__mgt_raw_z_axis_Get(IMU_All_Data* root);

/* INTEGER */
void IMU_All_Data__mgt_raw_z_axis_Set(IMU_All_Data* root, asn1SccSint value);

/* Field mgt_mgauss selector */
MGT_MilliGauss_Data* IMU_All_Data__mgt_mgauss_Get(IMU_All_Data* root);

/* REAL */
double IMU_All_Data__mgt_mgauss_x_axis_Get(IMU_All_Data* root);

/* REAL */
void IMU_All_Data__mgt_mgauss_x_axis_Set(IMU_All_Data* root, double value);

/* REAL */
double IMU_All_Data__mgt_mgauss_y_axis_Get(IMU_All_Data* root);

/* REAL */
void IMU_All_Data__mgt_mgauss_y_axis_Set(IMU_All_Data* root, double value);

/* REAL */
double IMU_All_Data__mgt_mgauss_z_axis_Get(IMU_All_Data* root);

/* REAL */
void IMU_All_Data__mgt_mgauss_z_axis_Set(IMU_All_Data* root, double value);

/* Field accel_raw selector */
ACC_Raw_Data* IMU_All_Data__accel_raw_Get(IMU_All_Data* root);

/* INTEGER */
asn1SccSint IMU_All_Data__accel_raw_x_axis_Get(IMU_All_Data* root);

/* INTEGER */
void IMU_All_Data__accel_raw_x_axis_Set(IMU_All_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint IMU_All_Data__accel_raw_y_axis_Get(IMU_All_Data* root);

/* INTEGER */
void IMU_All_Data__accel_raw_y_axis_Set(IMU_All_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint IMU_All_Data__accel_raw_z_axis_Get(IMU_All_Data* root);

/* INTEGER */
void IMU_All_Data__accel_raw_z_axis_Set(IMU_All_Data* root, asn1SccSint value);

/* Field accel_mg selector */
ACC_MilliG_Data* IMU_All_Data__accel_mg_Get(IMU_All_Data* root);

/* REAL */
double IMU_All_Data__accel_mg_x_axis_Get(IMU_All_Data* root);

/* REAL */
void IMU_All_Data__accel_mg_x_axis_Set(IMU_All_Data* root, double value);

/* REAL */
double IMU_All_Data__accel_mg_y_axis_Get(IMU_All_Data* root);

/* REAL */
void IMU_All_Data__accel_mg_y_axis_Set(IMU_All_Data* root, double value);

/* REAL */
double IMU_All_Data__accel_mg_z_axis_Get(IMU_All_Data* root);

/* REAL */
void IMU_All_Data__accel_mg_z_axis_Set(IMU_All_Data* root, double value);

/* Field gyro_raw selector */
GYRO_Raw_Data* IMU_All_Data__gyro_raw_Get(IMU_All_Data* root);

/* INTEGER */
asn1SccSint IMU_All_Data__gyro_raw_x_axis_Get(IMU_All_Data* root);

/* INTEGER */
void IMU_All_Data__gyro_raw_x_axis_Set(IMU_All_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint IMU_All_Data__gyro_raw_y_axis_Get(IMU_All_Data* root);

/* INTEGER */
void IMU_All_Data__gyro_raw_y_axis_Set(IMU_All_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint IMU_All_Data__gyro_raw_z_axis_Get(IMU_All_Data* root);

/* INTEGER */
void IMU_All_Data__gyro_raw_z_axis_Set(IMU_All_Data* root, asn1SccSint value);

/* Field gyro_mdps selector */
GYRO_MilliDPS_Data* IMU_All_Data__gyro_mdps_Get(IMU_All_Data* root);

/* REAL */
double IMU_All_Data__gyro_mdps_x_axis_Get(IMU_All_Data* root);

/* REAL */
void IMU_All_Data__gyro_mdps_x_axis_Set(IMU_All_Data* root, double value);

/* REAL */
double IMU_All_Data__gyro_mdps_y_axis_Get(IMU_All_Data* root);

/* REAL */
void IMU_All_Data__gyro_mdps_y_axis_Set(IMU_All_Data* root, double value);

/* REAL */
double IMU_All_Data__gyro_mdps_z_axis_Get(IMU_All_Data* root);

/* REAL */
void IMU_All_Data__gyro_mdps_z_axis_Set(IMU_All_Data* root, double value);

/* INTEGER */
asn1SccSint IMU_All_Data__temp_raw_Get(IMU_All_Data* root);

/* INTEGER */
void IMU_All_Data__temp_raw_Set(IMU_All_Data* root, asn1SccSint value);

/* REAL */
double IMU_All_Data__temp_celsius_Get(IMU_All_Data* root);

/* REAL */
void IMU_All_Data__temp_celsius_Set(IMU_All_Data* root, double value);

/* ENUMERATED */
int IMU_All_Data__mgt_valid_Get(IMU_All_Data* root);

/* ENUMERATED */
void IMU_All_Data__mgt_valid_Set(IMU_All_Data* root, int value);

/* ENUMERATED */
int IMU_All_Data__acc_valid_Get(IMU_All_Data* root);

/* ENUMERATED */
void IMU_All_Data__acc_valid_Set(IMU_All_Data* root, int value);

/* ENUMERATED */
int IMU_All_Data__gyro_valid_Get(IMU_All_Data* root);

/* ENUMERATED */
void IMU_All_Data__gyro_valid_Set(IMU_All_Data* root, int value);

/* ENUMERATED */
int IMU_All_Data__temp_valid_Get(IMU_All_Data* root);

/* ENUMERATED */
void IMU_All_Data__temp_valid_Set(IMU_All_Data* root, int value);

/* SEQUENCEOF/SETOF */
long TC74s_I2CBuses__GetLength(TC74s_I2CBuses* root);

/* SEQUENCEOF/SETOF */
void TC74s_I2CBuses__SetLength(TC74s_I2CBuses* root, long value);

/* INTEGER */
asn1SccSint TC74s_I2CBuses__iDx_Get(TC74s_I2CBuses* root, int iDx);

/* INTEGER */
void TC74s_I2CBuses__iDx_Set(TC74s_I2CBuses* root, int iDx, asn1SccSint value);

/* SEQUENCEOF/SETOF */
long TC74s_All_Data__GetLength(TC74s_All_Data* root);

/* SEQUENCEOF/SETOF */
void TC74s_All_Data__SetLength(TC74s_All_Data* root, long value);

/* REAL */
double TC74s_All_Data__iDx_temperature_Get(TC74s_All_Data* root, int iDx);

/* REAL */
void TC74s_All_Data__iDx_temperature_Set(TC74s_All_Data* root, int iDx, double value);

/* ENUMERATED */
int TC74s_All_Data__iDx_validity_Get(TC74s_All_Data* root, int iDx);

/* ENUMERATED */
void TC74s_All_Data__iDx_validity_Set(TC74s_All_Data* root, int iDx, int value);

/* SEQUENCEOF/SETOF */
long PT1000s_Channels__GetLength(PT1000s_Channels* root);

/* SEQUENCEOF/SETOF */
void PT1000s_Channels__SetLength(PT1000s_Channels* root, long value);

/* INTEGER */
asn1SccSint PT1000s_Channels__iDx_Get(PT1000s_Channels* root, int iDx);

/* INTEGER */
void PT1000s_Channels__iDx_Set(PT1000s_Channels* root, int iDx, asn1SccSint value);

/* SEQUENCEOF/SETOF */
long PT1000s_Raw_Data__GetLength(PT1000s_Raw_Data* root);

/* SEQUENCEOF/SETOF */
void PT1000s_Raw_Data__SetLength(PT1000s_Raw_Data* root, long value);

/* REAL */
double PT1000s_Raw_Data__iDx_vcc_volts_Get(PT1000s_Raw_Data* root, int iDx);

/* REAL */
void PT1000s_Raw_Data__iDx_vcc_volts_Set(PT1000s_Raw_Data* root, int iDx, double value);

/* REAL */
double PT1000s_Raw_Data__iDx_pt1000_Get(PT1000s_Raw_Data* root, int iDx);

/* REAL */
void PT1000s_Raw_Data__iDx_pt1000_Set(PT1000s_Raw_Data* root, int iDx, double value);

/* SEQUENCEOF/SETOF */
long PT1000s_Celsius_Data__GetLength(PT1000s_Celsius_Data* root);

/* SEQUENCEOF/SETOF */
void PT1000s_Celsius_Data__SetLength(PT1000s_Celsius_Data* root, long value);

/* REAL */
double PT1000s_Celsius_Data__iDx_Get(PT1000s_Celsius_Data* root, int iDx);

/* REAL */
void PT1000s_Celsius_Data__iDx_Set(PT1000s_Celsius_Data* root, int iDx, double value);

/* Field raw selector */
PT1000s_Raw_Data PT1000s_All_Data__raw_Get(PT1000s_All_Data* root);

/* Field raw selector */
void PT1000s_All_Data__raw_Set(PT1000s_All_Data* root, PT1000s_Raw_Data value);

/* SEQUENCEOF/SETOF */
long PT1000s_All_Data__raw_GetLength(PT1000s_All_Data* root);

/* SEQUENCEOF/SETOF */
void PT1000s_All_Data__raw_SetLength(PT1000s_All_Data* root, long value);

/* REAL */
double PT1000s_All_Data__raw_iDx_vcc_volts_Get(PT1000s_All_Data* root, int iDx);

/* REAL */
void PT1000s_All_Data__raw_iDx_vcc_volts_Set(PT1000s_All_Data* root, int iDx, double value);

/* REAL */
double PT1000s_All_Data__raw_iDx_pt1000_Get(PT1000s_All_Data* root, int iDx);

/* REAL */
void PT1000s_All_Data__raw_iDx_pt1000_Set(PT1000s_All_Data* root, int iDx, double value);

/* Field celsius selector */
PT1000s_Celsius_Data PT1000s_All_Data__celsius_Get(PT1000s_All_Data* root);

/* Field celsius selector */
void PT1000s_All_Data__celsius_Set(PT1000s_All_Data* root, PT1000s_Celsius_Data value);

/* SEQUENCEOF/SETOF */
long PT1000s_All_Data__celsius_GetLength(PT1000s_All_Data* root);

/* SEQUENCEOF/SETOF */
void PT1000s_All_Data__celsius_SetLength(PT1000s_All_Data* root, long value);

/* REAL */
double PT1000s_All_Data__celsius_iDx_Get(PT1000s_All_Data* root, int iDx);

/* REAL */
void PT1000s_All_Data__celsius_iDx_Set(PT1000s_All_Data* root, int iDx, double value);

/* Field validity selector */
PT1000s_All_Data_validity PT1000s_All_Data__validity_Get(PT1000s_All_Data* root);

/* Field validity selector */
void PT1000s_All_Data__validity_Set(PT1000s_All_Data* root, PT1000s_All_Data_validity value);

/* SEQUENCEOF/SETOF */
long PT1000s_All_Data__validity_GetLength(PT1000s_All_Data* root);

/* SEQUENCEOF/SETOF */
void PT1000s_All_Data__validity_SetLength(PT1000s_All_Data* root, long value);

/* ENUMERATED */
int PT1000s_All_Data__validity_iDx_Get(PT1000s_All_Data* root, int iDx);

/* ENUMERATED */
void PT1000s_All_Data__validity_iDx_Set(PT1000s_All_Data* root, int iDx, int value);

/* INTEGER */
asn1SccSint PS_Calibration_Data__c1_Get(PS_Calibration_Data* root);

/* INTEGER */
void PS_Calibration_Data__c1_Set(PS_Calibration_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint PS_Calibration_Data__c2_Get(PS_Calibration_Data* root);

/* INTEGER */
void PS_Calibration_Data__c2_Set(PS_Calibration_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint PS_Calibration_Data__c3_Get(PS_Calibration_Data* root);

/* INTEGER */
void PS_Calibration_Data__c3_Set(PS_Calibration_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint PS_Calibration_Data__c4_Get(PS_Calibration_Data* root);

/* INTEGER */
void PS_Calibration_Data__c4_Set(PS_Calibration_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint PS_Calibration_Data__c5_Get(PS_Calibration_Data* root);

/* INTEGER */
void PS_Calibration_Data__c5_Set(PS_Calibration_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint PS_Calibration_Data__c6_Get(PS_Calibration_Data* root);

/* INTEGER */
void PS_Calibration_Data__c6_Set(PS_Calibration_Data* root, asn1SccSint value);

/* REAL */
double PS_Calibration_Data__sens_t1_Get(PS_Calibration_Data* root);

/* REAL */
void PS_Calibration_Data__sens_t1_Set(PS_Calibration_Data* root, double value);

/* REAL */
double PS_Calibration_Data__off_t1_Get(PS_Calibration_Data* root);

/* REAL */
void PS_Calibration_Data__off_t1_Set(PS_Calibration_Data* root, double value);

/* REAL */
double PS_Calibration_Data__tcs_Get(PS_Calibration_Data* root);

/* REAL */
void PS_Calibration_Data__tcs_Set(PS_Calibration_Data* root, double value);

/* REAL */
double PS_Calibration_Data__tco_Get(PS_Calibration_Data* root);

/* REAL */
void PS_Calibration_Data__tco_Set(PS_Calibration_Data* root, double value);

/* REAL */
double PS_Calibration_Data__tref_Get(PS_Calibration_Data* root);

/* REAL */
void PS_Calibration_Data__tref_Set(PS_Calibration_Data* root, double value);

/* REAL */
double PS_Calibration_Data__temp_sens_Get(PS_Calibration_Data* root);

/* REAL */
void PS_Calibration_Data__temp_sens_Set(PS_Calibration_Data* root, double value);

/* INTEGER */
asn1SccSint PS_Raw_Data__d1_Get(PS_Raw_Data* root);

/* INTEGER */
void PS_Raw_Data__d1_Set(PS_Raw_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint PS_Raw_Data__d2_Get(PS_Raw_Data* root);

/* INTEGER */
void PS_Raw_Data__d2_Set(PS_Raw_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint PS_Processed_Data__pressure_Get(PS_Processed_Data* root);

/* INTEGER */
void PS_Processed_Data__pressure_Set(PS_Processed_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint PS_Processed_Data__temp_Get(PS_Processed_Data* root);

/* INTEGER */
void PS_Processed_Data__temp_Set(PS_Processed_Data* root, asn1SccSint value);

/* Field calib selector */
PS_Calibration_Data* PS_All_Data__calib_Get(PS_All_Data* root);

/* INTEGER */
asn1SccSint PS_All_Data__calib_c1_Get(PS_All_Data* root);

/* INTEGER */
void PS_All_Data__calib_c1_Set(PS_All_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint PS_All_Data__calib_c2_Get(PS_All_Data* root);

/* INTEGER */
void PS_All_Data__calib_c2_Set(PS_All_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint PS_All_Data__calib_c3_Get(PS_All_Data* root);

/* INTEGER */
void PS_All_Data__calib_c3_Set(PS_All_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint PS_All_Data__calib_c4_Get(PS_All_Data* root);

/* INTEGER */
void PS_All_Data__calib_c4_Set(PS_All_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint PS_All_Data__calib_c5_Get(PS_All_Data* root);

/* INTEGER */
void PS_All_Data__calib_c5_Set(PS_All_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint PS_All_Data__calib_c6_Get(PS_All_Data* root);

/* INTEGER */
void PS_All_Data__calib_c6_Set(PS_All_Data* root, asn1SccSint value);

/* REAL */
double PS_All_Data__calib_sens_t1_Get(PS_All_Data* root);

/* REAL */
void PS_All_Data__calib_sens_t1_Set(PS_All_Data* root, double value);

/* REAL */
double PS_All_Data__calib_off_t1_Get(PS_All_Data* root);

/* REAL */
void PS_All_Data__calib_off_t1_Set(PS_All_Data* root, double value);

/* REAL */
double PS_All_Data__calib_tcs_Get(PS_All_Data* root);

/* REAL */
void PS_All_Data__calib_tcs_Set(PS_All_Data* root, double value);

/* REAL */
double PS_All_Data__calib_tco_Get(PS_All_Data* root);

/* REAL */
void PS_All_Data__calib_tco_Set(PS_All_Data* root, double value);

/* REAL */
double PS_All_Data__calib_tref_Get(PS_All_Data* root);

/* REAL */
void PS_All_Data__calib_tref_Set(PS_All_Data* root, double value);

/* REAL */
double PS_All_Data__calib_temp_sens_Get(PS_All_Data* root);

/* REAL */
void PS_All_Data__calib_temp_sens_Set(PS_All_Data* root, double value);

/* Field raw selector */
PS_Raw_Data* PS_All_Data__raw_Get(PS_All_Data* root);

/* INTEGER */
asn1SccSint PS_All_Data__raw_d1_Get(PS_All_Data* root);

/* INTEGER */
void PS_All_Data__raw_d1_Set(PS_All_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint PS_All_Data__raw_d2_Get(PS_All_Data* root);

/* INTEGER */
void PS_All_Data__raw_d2_Set(PS_All_Data* root, asn1SccSint value);

/* Field processed selector */
PS_Processed_Data* PS_All_Data__processed_Get(PS_All_Data* root);

/* INTEGER */
asn1SccSint PS_All_Data__processed_pressure_Get(PS_All_Data* root);

/* INTEGER */
void PS_All_Data__processed_pressure_Set(PS_All_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint PS_All_Data__processed_temp_Get(PS_All_Data* root);

/* INTEGER */
void PS_All_Data__processed_temp_Set(PS_All_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint PS_All_Data__exist_validity_Get(PS_All_Data* root);

/* INTEGER */
void PS_All_Data__exist_validity_Set(PS_All_Data* root, asn1SccSint value);

/* ENUMERATED */
int PS_All_Data__validity_Get(PS_All_Data* root);

/* ENUMERATED */
void PS_All_Data__validity_Set(PS_All_Data* root, int value);

/* REAL */
double Heater_Data__power_watts_Get(Heater_Data* root);

/* REAL */
void Heater_Data__power_watts_Set(Heater_Data* root, double value);

/* ENUMERATED */
int Heater_Data__validity_Get(Heater_Data* root);

/* ENUMERATED */
void Heater_Data__validity_Set(Heater_Data* root, int value);

/* ENUMERATED */
int Heater_On_Off__Get(Heater_On_Off* root);

/* ENUMERATED */
void Heater_On_Off__Set(Heater_On_Off* root, int value);

/* ENUMERATED */
int HTL_State__Get(HTL_State* root);

/* ENUMERATED */
void HTL_State__Set(HTL_State* root, int value);

/* INTEGER */
asn1SccSint HTL_Config__exist_press_5km_Get(HTL_Config* root);

/* INTEGER */
void HTL_Config__exist_press_5km_Set(HTL_Config* root, asn1SccSint value);

/* REAL */
double HTL_Config__press_5km_Get(HTL_Config* root);

/* REAL */
void HTL_Config__press_5km_Set(HTL_Config* root, double value);

/* INTEGER */
asn1SccSint HTL_Config__exist_press_10km_Get(HTL_Config* root);

/* INTEGER */
void HTL_Config__exist_press_10km_Set(HTL_Config* root, asn1SccSint value);

/* REAL */
double HTL_Config__press_10km_Get(HTL_Config* root);

/* REAL */
void HTL_Config__press_10km_Set(HTL_Config* root, double value);

/* INTEGER */
asn1SccSint HTL_Config__exist_press_18km_Get(HTL_Config* root);

/* INTEGER */
void HTL_Config__exist_press_18km_Set(HTL_Config* root, asn1SccSint value);

/* REAL */
double HTL_Config__press_18km_Get(HTL_Config* root);

/* REAL */
void HTL_Config__press_18km_Set(HTL_Config* root, double value);

/* INTEGER */
asn1SccSint HTL_Config__exist_a1_duration_emergency_secs_Get(HTL_Config* root);

/* INTEGER */
void HTL_Config__exist_a1_duration_emergency_secs_Set(HTL_Config* root, asn1SccSint value);

/* REAL */
double HTL_Config__a1_duration_emergency_secs_Get(HTL_Config* root);

/* REAL */
void HTL_Config__a1_duration_emergency_secs_Set(HTL_Config* root, double value);

/* INTEGER */
asn1SccSint HTL_Config__exist_a1_duration_max_secs_Get(HTL_Config* root);

/* INTEGER */
void HTL_Config__exist_a1_duration_max_secs_Set(HTL_Config* root, asn1SccSint value);

/* REAL */
double HTL_Config__a1_duration_max_secs_Get(HTL_Config* root);

/* REAL */
void HTL_Config__a1_duration_max_secs_Set(HTL_Config* root, double value);

/* INTEGER */
asn1SccSint HTL_Config__exist_a2_duration_max_secs_Get(HTL_Config* root);

/* INTEGER */
void HTL_Config__exist_a2_duration_max_secs_Set(HTL_Config* root, asn1SccSint value);

/* REAL */
double HTL_Config__a2_duration_max_secs_Get(HTL_Config* root);

/* REAL */
void HTL_Config__a2_duration_max_secs_Set(HTL_Config* root, double value);

/* INTEGER */
asn1SccSint HTL_Config__exist_f1_duration_secs_Get(HTL_Config* root);

/* INTEGER */
void HTL_Config__exist_f1_duration_secs_Set(HTL_Config* root, asn1SccSint value);

/* INTEGER */
asn1SccSint HTL_Config__f1_duration_secs_Get(HTL_Config* root);

/* INTEGER */
void HTL_Config__f1_duration_secs_Set(HTL_Config* root, asn1SccSint value);

/* INTEGER */
asn1SccSint HTL_Config__exist_f2_duration_secs_Get(HTL_Config* root);

/* INTEGER */
void HTL_Config__exist_f2_duration_secs_Set(HTL_Config* root, asn1SccSint value);

/* INTEGER */
asn1SccSint HTL_Config__f2_duration_secs_Get(HTL_Config* root);

/* INTEGER */
void HTL_Config__f2_duration_secs_Set(HTL_Config* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__exist_gps_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__exist_gps_Set(OBSW_DP_Data* root, asn1SccSint value);

/* Field gps selector */
OBSW_DP_Data_gps* OBSW_DP_Data__gps_Get(OBSW_DP_Data* root);

/* Field data selector */
GPS_PVT* OBSW_DP_Data__gps_data_Get(OBSW_DP_Data* root);

/* ENUMERATED */
int OBSW_DP_Data__gps_data_mode_Get(OBSW_DP_Data* root);

/* ENUMERATED */
void OBSW_DP_Data__gps_data_mode_Set(OBSW_DP_Data* root, int value);

/* REAL */
double OBSW_DP_Data__gps_data_date_and_time_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__gps_data_date_and_time_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__gps_data_ept_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__gps_data_ept_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__gps_data_latitude_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__gps_data_latitude_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__gps_data_epy_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__gps_data_epy_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__gps_data_longitude_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__gps_data_longitude_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__gps_data_epx_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__gps_data_epx_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__gps_data_altitude_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__gps_data_altitude_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__gps_data_epv_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__gps_data_epv_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__gps_data_course_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__gps_data_course_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__gps_data_epd_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__gps_data_epd_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__gps_data_speed_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__gps_data_speed_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__gps_data_eps_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__gps_data_eps_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__gps_data_climb_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__gps_data_climb_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__gps_data_epc_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__gps_data_epc_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__gps_gps_time_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__gps_gps_time_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__gps_mission_time_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__gps_mission_time_Set(OBSW_DP_Data* root, double value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__exist_imu_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__exist_imu_Set(OBSW_DP_Data* root, asn1SccSint value);

/* Field imu selector */
OBSW_DP_Data_imu* OBSW_DP_Data__imu_Get(OBSW_DP_Data* root);

/* Field data selector */
IMU_All_Data* OBSW_DP_Data__imu_data_Get(OBSW_DP_Data* root);

/* Field mgt_raw selector */
MGT_Raw_Data* OBSW_DP_Data__imu_data_mgt_raw_Get(OBSW_DP_Data* root);

/* INTEGER */
asn1SccSint OBSW_DP_Data__imu_data_mgt_raw_x_axis_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__imu_data_mgt_raw_x_axis_Set(OBSW_DP_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__imu_data_mgt_raw_y_axis_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__imu_data_mgt_raw_y_axis_Set(OBSW_DP_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__imu_data_mgt_raw_z_axis_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__imu_data_mgt_raw_z_axis_Set(OBSW_DP_Data* root, asn1SccSint value);

/* Field mgt_mgauss selector */
MGT_MilliGauss_Data* OBSW_DP_Data__imu_data_mgt_mgauss_Get(OBSW_DP_Data* root);

/* REAL */
double OBSW_DP_Data__imu_data_mgt_mgauss_x_axis_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__imu_data_mgt_mgauss_x_axis_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__imu_data_mgt_mgauss_y_axis_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__imu_data_mgt_mgauss_y_axis_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__imu_data_mgt_mgauss_z_axis_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__imu_data_mgt_mgauss_z_axis_Set(OBSW_DP_Data* root, double value);

/* Field accel_raw selector */
ACC_Raw_Data* OBSW_DP_Data__imu_data_accel_raw_Get(OBSW_DP_Data* root);

/* INTEGER */
asn1SccSint OBSW_DP_Data__imu_data_accel_raw_x_axis_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__imu_data_accel_raw_x_axis_Set(OBSW_DP_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__imu_data_accel_raw_y_axis_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__imu_data_accel_raw_y_axis_Set(OBSW_DP_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__imu_data_accel_raw_z_axis_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__imu_data_accel_raw_z_axis_Set(OBSW_DP_Data* root, asn1SccSint value);

/* Field accel_mg selector */
ACC_MilliG_Data* OBSW_DP_Data__imu_data_accel_mg_Get(OBSW_DP_Data* root);

/* REAL */
double OBSW_DP_Data__imu_data_accel_mg_x_axis_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__imu_data_accel_mg_x_axis_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__imu_data_accel_mg_y_axis_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__imu_data_accel_mg_y_axis_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__imu_data_accel_mg_z_axis_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__imu_data_accel_mg_z_axis_Set(OBSW_DP_Data* root, double value);

/* Field gyro_raw selector */
GYRO_Raw_Data* OBSW_DP_Data__imu_data_gyro_raw_Get(OBSW_DP_Data* root);

/* INTEGER */
asn1SccSint OBSW_DP_Data__imu_data_gyro_raw_x_axis_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__imu_data_gyro_raw_x_axis_Set(OBSW_DP_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__imu_data_gyro_raw_y_axis_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__imu_data_gyro_raw_y_axis_Set(OBSW_DP_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__imu_data_gyro_raw_z_axis_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__imu_data_gyro_raw_z_axis_Set(OBSW_DP_Data* root, asn1SccSint value);

/* Field gyro_mdps selector */
GYRO_MilliDPS_Data* OBSW_DP_Data__imu_data_gyro_mdps_Get(OBSW_DP_Data* root);

/* REAL */
double OBSW_DP_Data__imu_data_gyro_mdps_x_axis_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__imu_data_gyro_mdps_x_axis_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__imu_data_gyro_mdps_y_axis_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__imu_data_gyro_mdps_y_axis_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__imu_data_gyro_mdps_z_axis_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__imu_data_gyro_mdps_z_axis_Set(OBSW_DP_Data* root, double value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__imu_data_temp_raw_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__imu_data_temp_raw_Set(OBSW_DP_Data* root, asn1SccSint value);

/* REAL */
double OBSW_DP_Data__imu_data_temp_celsius_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__imu_data_temp_celsius_Set(OBSW_DP_Data* root, double value);

/* ENUMERATED */
int OBSW_DP_Data__imu_data_mgt_valid_Get(OBSW_DP_Data* root);

/* ENUMERATED */
void OBSW_DP_Data__imu_data_mgt_valid_Set(OBSW_DP_Data* root, int value);

/* ENUMERATED */
int OBSW_DP_Data__imu_data_acc_valid_Get(OBSW_DP_Data* root);

/* ENUMERATED */
void OBSW_DP_Data__imu_data_acc_valid_Set(OBSW_DP_Data* root, int value);

/* ENUMERATED */
int OBSW_DP_Data__imu_data_gyro_valid_Get(OBSW_DP_Data* root);

/* ENUMERATED */
void OBSW_DP_Data__imu_data_gyro_valid_Set(OBSW_DP_Data* root, int value);

/* ENUMERATED */
int OBSW_DP_Data__imu_data_temp_valid_Get(OBSW_DP_Data* root);

/* ENUMERATED */
void OBSW_DP_Data__imu_data_temp_valid_Set(OBSW_DP_Data* root, int value);

/* REAL */
double OBSW_DP_Data__imu_gps_time_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__imu_gps_time_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__imu_mission_time_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__imu_mission_time_Set(OBSW_DP_Data* root, double value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__exist_tc74s_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__exist_tc74s_Set(OBSW_DP_Data* root, asn1SccSint value);

/* Field tc74s selector */
OBSW_DP_Data_tc74s* OBSW_DP_Data__tc74s_Get(OBSW_DP_Data* root);

/* Field data selector */
TC74s_All_Data OBSW_DP_Data__tc74s_data_Get(OBSW_DP_Data* root);

/* Field data selector */
void OBSW_DP_Data__tc74s_data_Set(OBSW_DP_Data* root, TC74s_All_Data value);

/* SEQUENCEOF/SETOF */
long OBSW_DP_Data__tc74s_data_GetLength(OBSW_DP_Data* root);

/* SEQUENCEOF/SETOF */
void OBSW_DP_Data__tc74s_data_SetLength(OBSW_DP_Data* root, long value);

/* REAL */
double OBSW_DP_Data__tc74s_data_iDx_temperature_Get(OBSW_DP_Data* root, int iDx);

/* REAL */
void OBSW_DP_Data__tc74s_data_iDx_temperature_Set(OBSW_DP_Data* root, int iDx, double value);

/* ENUMERATED */
int OBSW_DP_Data__tc74s_data_iDx_validity_Get(OBSW_DP_Data* root, int iDx);

/* ENUMERATED */
void OBSW_DP_Data__tc74s_data_iDx_validity_Set(OBSW_DP_Data* root, int iDx, int value);

/* REAL */
double OBSW_DP_Data__tc74s_gps_time_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__tc74s_gps_time_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__tc74s_mission_time_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__tc74s_mission_time_Set(OBSW_DP_Data* root, double value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__exist_pt1000s_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__exist_pt1000s_Set(OBSW_DP_Data* root, asn1SccSint value);

/* Field pt1000s selector */
OBSW_DP_Data_pt1000s* OBSW_DP_Data__pt1000s_Get(OBSW_DP_Data* root);

/* Field data selector */
PT1000s_All_Data* OBSW_DP_Data__pt1000s_data_Get(OBSW_DP_Data* root);

/* Field raw selector */
PT1000s_Raw_Data OBSW_DP_Data__pt1000s_data_raw_Get(OBSW_DP_Data* root);

/* Field raw selector */
void OBSW_DP_Data__pt1000s_data_raw_Set(OBSW_DP_Data* root, PT1000s_Raw_Data value);

/* SEQUENCEOF/SETOF */
long OBSW_DP_Data__pt1000s_data_raw_GetLength(OBSW_DP_Data* root);

/* SEQUENCEOF/SETOF */
void OBSW_DP_Data__pt1000s_data_raw_SetLength(OBSW_DP_Data* root, long value);

/* REAL */
double OBSW_DP_Data__pt1000s_data_raw_iDx_vcc_volts_Get(OBSW_DP_Data* root, int iDx);

/* REAL */
void OBSW_DP_Data__pt1000s_data_raw_iDx_vcc_volts_Set(OBSW_DP_Data* root, int iDx, double value);

/* REAL */
double OBSW_DP_Data__pt1000s_data_raw_iDx_pt1000_Get(OBSW_DP_Data* root, int iDx);

/* REAL */
void OBSW_DP_Data__pt1000s_data_raw_iDx_pt1000_Set(OBSW_DP_Data* root, int iDx, double value);

/* Field celsius selector */
PT1000s_Celsius_Data OBSW_DP_Data__pt1000s_data_celsius_Get(OBSW_DP_Data* root);

/* Field celsius selector */
void OBSW_DP_Data__pt1000s_data_celsius_Set(OBSW_DP_Data* root, PT1000s_Celsius_Data value);

/* SEQUENCEOF/SETOF */
long OBSW_DP_Data__pt1000s_data_celsius_GetLength(OBSW_DP_Data* root);

/* SEQUENCEOF/SETOF */
void OBSW_DP_Data__pt1000s_data_celsius_SetLength(OBSW_DP_Data* root, long value);

/* REAL */
double OBSW_DP_Data__pt1000s_data_celsius_iDx_Get(OBSW_DP_Data* root, int iDx);

/* REAL */
void OBSW_DP_Data__pt1000s_data_celsius_iDx_Set(OBSW_DP_Data* root, int iDx, double value);

/* Field validity selector */
PT1000s_All_Data_validity OBSW_DP_Data__pt1000s_data_validity_Get(OBSW_DP_Data* root);

/* Field validity selector */
void OBSW_DP_Data__pt1000s_data_validity_Set(OBSW_DP_Data* root, PT1000s_All_Data_validity value);

/* SEQUENCEOF/SETOF */
long OBSW_DP_Data__pt1000s_data_validity_GetLength(OBSW_DP_Data* root);

/* SEQUENCEOF/SETOF */
void OBSW_DP_Data__pt1000s_data_validity_SetLength(OBSW_DP_Data* root, long value);

/* ENUMERATED */
int OBSW_DP_Data__pt1000s_data_validity_iDx_Get(OBSW_DP_Data* root, int iDx);

/* ENUMERATED */
void OBSW_DP_Data__pt1000s_data_validity_iDx_Set(OBSW_DP_Data* root, int iDx, int value);

/* REAL */
double OBSW_DP_Data__pt1000s_gps_time_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__pt1000s_gps_time_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__pt1000s_mission_time_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__pt1000s_mission_time_Set(OBSW_DP_Data* root, double value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__exist_ps1_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__exist_ps1_Set(OBSW_DP_Data* root, asn1SccSint value);

/* Field ps1 selector */
OBSW_DP_Data_ps1* OBSW_DP_Data__ps1_Get(OBSW_DP_Data* root);

/* Field data selector */
PS_All_Data* OBSW_DP_Data__ps1_data_Get(OBSW_DP_Data* root);

/* Field calib selector */
PS_Calibration_Data* OBSW_DP_Data__ps1_data_calib_Get(OBSW_DP_Data* root);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_calib_c1_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps1_data_calib_c1_Set(OBSW_DP_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_calib_c2_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps1_data_calib_c2_Set(OBSW_DP_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_calib_c3_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps1_data_calib_c3_Set(OBSW_DP_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_calib_c4_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps1_data_calib_c4_Set(OBSW_DP_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_calib_c5_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps1_data_calib_c5_Set(OBSW_DP_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_calib_c6_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps1_data_calib_c6_Set(OBSW_DP_Data* root, asn1SccSint value);

/* REAL */
double OBSW_DP_Data__ps1_data_calib_sens_t1_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__ps1_data_calib_sens_t1_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__ps1_data_calib_off_t1_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__ps1_data_calib_off_t1_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__ps1_data_calib_tcs_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__ps1_data_calib_tcs_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__ps1_data_calib_tco_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__ps1_data_calib_tco_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__ps1_data_calib_tref_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__ps1_data_calib_tref_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__ps1_data_calib_temp_sens_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__ps1_data_calib_temp_sens_Set(OBSW_DP_Data* root, double value);

/* Field raw selector */
PS_Raw_Data* OBSW_DP_Data__ps1_data_raw_Get(OBSW_DP_Data* root);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_raw_d1_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps1_data_raw_d1_Set(OBSW_DP_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_raw_d2_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps1_data_raw_d2_Set(OBSW_DP_Data* root, asn1SccSint value);

/* Field processed selector */
PS_Processed_Data* OBSW_DP_Data__ps1_data_processed_Get(OBSW_DP_Data* root);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_processed_pressure_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps1_data_processed_pressure_Set(OBSW_DP_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_processed_temp_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps1_data_processed_temp_Set(OBSW_DP_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_exist_validity_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps1_data_exist_validity_Set(OBSW_DP_Data* root, asn1SccSint value);

/* ENUMERATED */
int OBSW_DP_Data__ps1_data_validity_Get(OBSW_DP_Data* root);

/* ENUMERATED */
void OBSW_DP_Data__ps1_data_validity_Set(OBSW_DP_Data* root, int value);

/* REAL */
double OBSW_DP_Data__ps1_gps_time_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__ps1_gps_time_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__ps1_mission_time_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__ps1_mission_time_Set(OBSW_DP_Data* root, double value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__exist_ps2_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__exist_ps2_Set(OBSW_DP_Data* root, asn1SccSint value);

/* Field ps2 selector */
OBSW_DP_Data_ps2* OBSW_DP_Data__ps2_Get(OBSW_DP_Data* root);

/* Field data selector */
PS_All_Data* OBSW_DP_Data__ps2_data_Get(OBSW_DP_Data* root);

/* Field calib selector */
PS_Calibration_Data* OBSW_DP_Data__ps2_data_calib_Get(OBSW_DP_Data* root);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_calib_c1_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps2_data_calib_c1_Set(OBSW_DP_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_calib_c2_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps2_data_calib_c2_Set(OBSW_DP_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_calib_c3_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps2_data_calib_c3_Set(OBSW_DP_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_calib_c4_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps2_data_calib_c4_Set(OBSW_DP_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_calib_c5_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps2_data_calib_c5_Set(OBSW_DP_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_calib_c6_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps2_data_calib_c6_Set(OBSW_DP_Data* root, asn1SccSint value);

/* REAL */
double OBSW_DP_Data__ps2_data_calib_sens_t1_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__ps2_data_calib_sens_t1_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__ps2_data_calib_off_t1_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__ps2_data_calib_off_t1_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__ps2_data_calib_tcs_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__ps2_data_calib_tcs_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__ps2_data_calib_tco_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__ps2_data_calib_tco_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__ps2_data_calib_tref_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__ps2_data_calib_tref_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__ps2_data_calib_temp_sens_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__ps2_data_calib_temp_sens_Set(OBSW_DP_Data* root, double value);

/* Field raw selector */
PS_Raw_Data* OBSW_DP_Data__ps2_data_raw_Get(OBSW_DP_Data* root);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_raw_d1_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps2_data_raw_d1_Set(OBSW_DP_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_raw_d2_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps2_data_raw_d2_Set(OBSW_DP_Data* root, asn1SccSint value);

/* Field processed selector */
PS_Processed_Data* OBSW_DP_Data__ps2_data_processed_Get(OBSW_DP_Data* root);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_processed_pressure_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps2_data_processed_pressure_Set(OBSW_DP_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_processed_temp_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps2_data_processed_temp_Set(OBSW_DP_Data* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_exist_validity_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps2_data_exist_validity_Set(OBSW_DP_Data* root, asn1SccSint value);

/* ENUMERATED */
int OBSW_DP_Data__ps2_data_validity_Get(OBSW_DP_Data* root);

/* ENUMERATED */
void OBSW_DP_Data__ps2_data_validity_Set(OBSW_DP_Data* root, int value);

/* REAL */
double OBSW_DP_Data__ps2_gps_time_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__ps2_gps_time_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__ps2_mission_time_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__ps2_mission_time_Set(OBSW_DP_Data* root, double value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__exist_heater1_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__exist_heater1_Set(OBSW_DP_Data* root, asn1SccSint value);

/* Field heater1 selector */
OBSW_DP_Data_heater1* OBSW_DP_Data__heater1_Get(OBSW_DP_Data* root);

/* Field data selector */
Heater_Data* OBSW_DP_Data__heater1_data_Get(OBSW_DP_Data* root);

/* REAL */
double OBSW_DP_Data__heater1_data_power_watts_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__heater1_data_power_watts_Set(OBSW_DP_Data* root, double value);

/* ENUMERATED */
int OBSW_DP_Data__heater1_data_validity_Get(OBSW_DP_Data* root);

/* ENUMERATED */
void OBSW_DP_Data__heater1_data_validity_Set(OBSW_DP_Data* root, int value);

/* REAL */
double OBSW_DP_Data__heater1_gps_time_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__heater1_gps_time_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__heater1_mission_time_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__heater1_mission_time_Set(OBSW_DP_Data* root, double value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__exist_heater2_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__exist_heater2_Set(OBSW_DP_Data* root, asn1SccSint value);

/* Field heater2 selector */
OBSW_DP_Data_heater2* OBSW_DP_Data__heater2_Get(OBSW_DP_Data* root);

/* Field data selector */
Heater_Data* OBSW_DP_Data__heater2_data_Get(OBSW_DP_Data* root);

/* REAL */
double OBSW_DP_Data__heater2_data_power_watts_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__heater2_data_power_watts_Set(OBSW_DP_Data* root, double value);

/* ENUMERATED */
int OBSW_DP_Data__heater2_data_validity_Get(OBSW_DP_Data* root);

/* ENUMERATED */
void OBSW_DP_Data__heater2_data_validity_Set(OBSW_DP_Data* root, int value);

/* REAL */
double OBSW_DP_Data__heater2_gps_time_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__heater2_gps_time_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__heater2_mission_time_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__heater2_mission_time_Set(OBSW_DP_Data* root, double value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__exist_anemometer_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__exist_anemometer_Set(OBSW_DP_Data* root, asn1SccSint value);

/* Field anemometer selector */
OBSW_DP_Data_anemometer* OBSW_DP_Data__anemometer_Get(OBSW_DP_Data* root);

/* INTEGER */
asn1SccSint OBSW_DP_Data__anemometer_data_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__anemometer_data_Set(OBSW_DP_Data* root, asn1SccSint value);

/* REAL */
double OBSW_DP_Data__anemometer_gps_time_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__anemometer_gps_time_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__anemometer_mission_time_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__anemometer_mission_time_Set(OBSW_DP_Data* root, double value);

/* ENUMERATED */
int OBSW_DP_Filter__Get(OBSW_DP_Filter* root);

/* ENUMERATED */
void OBSW_DP_Filter__Set(OBSW_DP_Filter* root, int value);

/* CHOICE selector */
int OBSW_DP_SingleData__kind_Get(OBSW_DP_SingleData* root);

/* CHOICE selector */
void OBSW_DP_SingleData__kind_Set(OBSW_DP_SingleData* root, int value);

/* Field gps selector */
OBSW_DP_SingleData_gps* OBSW_DP_SingleData__gps_Get(OBSW_DP_SingleData* root);

/* Field data selector */
GPS_PVT* OBSW_DP_SingleData__gps_data_Get(OBSW_DP_SingleData* root);

/* ENUMERATED */
int OBSW_DP_SingleData__gps_data_mode_Get(OBSW_DP_SingleData* root);

/* ENUMERATED */
void OBSW_DP_SingleData__gps_data_mode_Set(OBSW_DP_SingleData* root, int value);

/* REAL */
double OBSW_DP_SingleData__gps_data_date_and_time_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__gps_data_date_and_time_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__gps_data_ept_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__gps_data_ept_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__gps_data_latitude_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__gps_data_latitude_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__gps_data_epy_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__gps_data_epy_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__gps_data_longitude_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__gps_data_longitude_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__gps_data_epx_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__gps_data_epx_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__gps_data_altitude_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__gps_data_altitude_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__gps_data_epv_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__gps_data_epv_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__gps_data_course_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__gps_data_course_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__gps_data_epd_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__gps_data_epd_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__gps_data_speed_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__gps_data_speed_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__gps_data_eps_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__gps_data_eps_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__gps_data_climb_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__gps_data_climb_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__gps_data_epc_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__gps_data_epc_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__gps_gps_time_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__gps_gps_time_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__gps_mission_time_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__gps_mission_time_Set(OBSW_DP_SingleData* root, double value);

/* Field imu selector */
OBSW_DP_SingleData_imu* OBSW_DP_SingleData__imu_Get(OBSW_DP_SingleData* root);

/* Field data selector */
IMU_All_Data* OBSW_DP_SingleData__imu_data_Get(OBSW_DP_SingleData* root);

/* Field mgt_raw selector */
MGT_Raw_Data* OBSW_DP_SingleData__imu_data_mgt_raw_Get(OBSW_DP_SingleData* root);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__imu_data_mgt_raw_x_axis_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__imu_data_mgt_raw_x_axis_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__imu_data_mgt_raw_y_axis_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__imu_data_mgt_raw_y_axis_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__imu_data_mgt_raw_z_axis_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__imu_data_mgt_raw_z_axis_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* Field mgt_mgauss selector */
MGT_MilliGauss_Data* OBSW_DP_SingleData__imu_data_mgt_mgauss_Get(OBSW_DP_SingleData* root);

/* REAL */
double OBSW_DP_SingleData__imu_data_mgt_mgauss_x_axis_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__imu_data_mgt_mgauss_x_axis_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__imu_data_mgt_mgauss_y_axis_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__imu_data_mgt_mgauss_y_axis_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__imu_data_mgt_mgauss_z_axis_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__imu_data_mgt_mgauss_z_axis_Set(OBSW_DP_SingleData* root, double value);

/* Field accel_raw selector */
ACC_Raw_Data* OBSW_DP_SingleData__imu_data_accel_raw_Get(OBSW_DP_SingleData* root);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__imu_data_accel_raw_x_axis_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__imu_data_accel_raw_x_axis_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__imu_data_accel_raw_y_axis_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__imu_data_accel_raw_y_axis_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__imu_data_accel_raw_z_axis_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__imu_data_accel_raw_z_axis_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* Field accel_mg selector */
ACC_MilliG_Data* OBSW_DP_SingleData__imu_data_accel_mg_Get(OBSW_DP_SingleData* root);

/* REAL */
double OBSW_DP_SingleData__imu_data_accel_mg_x_axis_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__imu_data_accel_mg_x_axis_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__imu_data_accel_mg_y_axis_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__imu_data_accel_mg_y_axis_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__imu_data_accel_mg_z_axis_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__imu_data_accel_mg_z_axis_Set(OBSW_DP_SingleData* root, double value);

/* Field gyro_raw selector */
GYRO_Raw_Data* OBSW_DP_SingleData__imu_data_gyro_raw_Get(OBSW_DP_SingleData* root);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__imu_data_gyro_raw_x_axis_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__imu_data_gyro_raw_x_axis_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__imu_data_gyro_raw_y_axis_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__imu_data_gyro_raw_y_axis_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__imu_data_gyro_raw_z_axis_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__imu_data_gyro_raw_z_axis_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* Field gyro_mdps selector */
GYRO_MilliDPS_Data* OBSW_DP_SingleData__imu_data_gyro_mdps_Get(OBSW_DP_SingleData* root);

/* REAL */
double OBSW_DP_SingleData__imu_data_gyro_mdps_x_axis_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__imu_data_gyro_mdps_x_axis_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__imu_data_gyro_mdps_y_axis_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__imu_data_gyro_mdps_y_axis_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__imu_data_gyro_mdps_z_axis_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__imu_data_gyro_mdps_z_axis_Set(OBSW_DP_SingleData* root, double value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__imu_data_temp_raw_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__imu_data_temp_raw_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* REAL */
double OBSW_DP_SingleData__imu_data_temp_celsius_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__imu_data_temp_celsius_Set(OBSW_DP_SingleData* root, double value);

/* ENUMERATED */
int OBSW_DP_SingleData__imu_data_mgt_valid_Get(OBSW_DP_SingleData* root);

/* ENUMERATED */
void OBSW_DP_SingleData__imu_data_mgt_valid_Set(OBSW_DP_SingleData* root, int value);

/* ENUMERATED */
int OBSW_DP_SingleData__imu_data_acc_valid_Get(OBSW_DP_SingleData* root);

/* ENUMERATED */
void OBSW_DP_SingleData__imu_data_acc_valid_Set(OBSW_DP_SingleData* root, int value);

/* ENUMERATED */
int OBSW_DP_SingleData__imu_data_gyro_valid_Get(OBSW_DP_SingleData* root);

/* ENUMERATED */
void OBSW_DP_SingleData__imu_data_gyro_valid_Set(OBSW_DP_SingleData* root, int value);

/* ENUMERATED */
int OBSW_DP_SingleData__imu_data_temp_valid_Get(OBSW_DP_SingleData* root);

/* ENUMERATED */
void OBSW_DP_SingleData__imu_data_temp_valid_Set(OBSW_DP_SingleData* root, int value);

/* REAL */
double OBSW_DP_SingleData__imu_gps_time_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__imu_gps_time_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__imu_mission_time_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__imu_mission_time_Set(OBSW_DP_SingleData* root, double value);

/* Field tc74s selector */
OBSW_DP_SingleData_tc74s* OBSW_DP_SingleData__tc74s_Get(OBSW_DP_SingleData* root);

/* Field data selector */
TC74s_All_Data OBSW_DP_SingleData__tc74s_data_Get(OBSW_DP_SingleData* root);

/* Field data selector */
void OBSW_DP_SingleData__tc74s_data_Set(OBSW_DP_SingleData* root, TC74s_All_Data value);

/* SEQUENCEOF/SETOF */
long OBSW_DP_SingleData__tc74s_data_GetLength(OBSW_DP_SingleData* root);

/* SEQUENCEOF/SETOF */
void OBSW_DP_SingleData__tc74s_data_SetLength(OBSW_DP_SingleData* root, long value);

/* REAL */
double OBSW_DP_SingleData__tc74s_data_iDx_temperature_Get(OBSW_DP_SingleData* root, int iDx);

/* REAL */
void OBSW_DP_SingleData__tc74s_data_iDx_temperature_Set(OBSW_DP_SingleData* root, int iDx, double value);

/* ENUMERATED */
int OBSW_DP_SingleData__tc74s_data_iDx_validity_Get(OBSW_DP_SingleData* root, int iDx);

/* ENUMERATED */
void OBSW_DP_SingleData__tc74s_data_iDx_validity_Set(OBSW_DP_SingleData* root, int iDx, int value);

/* REAL */
double OBSW_DP_SingleData__tc74s_gps_time_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__tc74s_gps_time_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__tc74s_mission_time_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__tc74s_mission_time_Set(OBSW_DP_SingleData* root, double value);

/* Field pt1000s selector */
OBSW_DP_SingleData_pt1000s* OBSW_DP_SingleData__pt1000s_Get(OBSW_DP_SingleData* root);

/* Field data selector */
PT1000s_All_Data* OBSW_DP_SingleData__pt1000s_data_Get(OBSW_DP_SingleData* root);

/* Field raw selector */
PT1000s_Raw_Data OBSW_DP_SingleData__pt1000s_data_raw_Get(OBSW_DP_SingleData* root);

/* Field raw selector */
void OBSW_DP_SingleData__pt1000s_data_raw_Set(OBSW_DP_SingleData* root, PT1000s_Raw_Data value);

/* SEQUENCEOF/SETOF */
long OBSW_DP_SingleData__pt1000s_data_raw_GetLength(OBSW_DP_SingleData* root);

/* SEQUENCEOF/SETOF */
void OBSW_DP_SingleData__pt1000s_data_raw_SetLength(OBSW_DP_SingleData* root, long value);

/* REAL */
double OBSW_DP_SingleData__pt1000s_data_raw_iDx_vcc_volts_Get(OBSW_DP_SingleData* root, int iDx);

/* REAL */
void OBSW_DP_SingleData__pt1000s_data_raw_iDx_vcc_volts_Set(OBSW_DP_SingleData* root, int iDx, double value);

/* REAL */
double OBSW_DP_SingleData__pt1000s_data_raw_iDx_pt1000_Get(OBSW_DP_SingleData* root, int iDx);

/* REAL */
void OBSW_DP_SingleData__pt1000s_data_raw_iDx_pt1000_Set(OBSW_DP_SingleData* root, int iDx, double value);

/* Field celsius selector */
PT1000s_Celsius_Data OBSW_DP_SingleData__pt1000s_data_celsius_Get(OBSW_DP_SingleData* root);

/* Field celsius selector */
void OBSW_DP_SingleData__pt1000s_data_celsius_Set(OBSW_DP_SingleData* root, PT1000s_Celsius_Data value);

/* SEQUENCEOF/SETOF */
long OBSW_DP_SingleData__pt1000s_data_celsius_GetLength(OBSW_DP_SingleData* root);

/* SEQUENCEOF/SETOF */
void OBSW_DP_SingleData__pt1000s_data_celsius_SetLength(OBSW_DP_SingleData* root, long value);

/* REAL */
double OBSW_DP_SingleData__pt1000s_data_celsius_iDx_Get(OBSW_DP_SingleData* root, int iDx);

/* REAL */
void OBSW_DP_SingleData__pt1000s_data_celsius_iDx_Set(OBSW_DP_SingleData* root, int iDx, double value);

/* Field validity selector */
PT1000s_All_Data_validity OBSW_DP_SingleData__pt1000s_data_validity_Get(OBSW_DP_SingleData* root);

/* Field validity selector */
void OBSW_DP_SingleData__pt1000s_data_validity_Set(OBSW_DP_SingleData* root, PT1000s_All_Data_validity value);

/* SEQUENCEOF/SETOF */
long OBSW_DP_SingleData__pt1000s_data_validity_GetLength(OBSW_DP_SingleData* root);

/* SEQUENCEOF/SETOF */
void OBSW_DP_SingleData__pt1000s_data_validity_SetLength(OBSW_DP_SingleData* root, long value);

/* ENUMERATED */
int OBSW_DP_SingleData__pt1000s_data_validity_iDx_Get(OBSW_DP_SingleData* root, int iDx);

/* ENUMERATED */
void OBSW_DP_SingleData__pt1000s_data_validity_iDx_Set(OBSW_DP_SingleData* root, int iDx, int value);

/* REAL */
double OBSW_DP_SingleData__pt1000s_gps_time_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__pt1000s_gps_time_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__pt1000s_mission_time_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__pt1000s_mission_time_Set(OBSW_DP_SingleData* root, double value);

/* Field ps1 selector */
OBSW_DP_SingleData_ps1* OBSW_DP_SingleData__ps1_Get(OBSW_DP_SingleData* root);

/* Field data selector */
PS_All_Data* OBSW_DP_SingleData__ps1_data_Get(OBSW_DP_SingleData* root);

/* Field calib selector */
PS_Calibration_Data* OBSW_DP_SingleData__ps1_data_calib_Get(OBSW_DP_SingleData* root);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__ps1_data_calib_c1_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__ps1_data_calib_c1_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__ps1_data_calib_c2_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__ps1_data_calib_c2_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__ps1_data_calib_c3_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__ps1_data_calib_c3_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__ps1_data_calib_c4_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__ps1_data_calib_c4_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__ps1_data_calib_c5_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__ps1_data_calib_c5_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__ps1_data_calib_c6_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__ps1_data_calib_c6_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* REAL */
double OBSW_DP_SingleData__ps1_data_calib_sens_t1_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__ps1_data_calib_sens_t1_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__ps1_data_calib_off_t1_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__ps1_data_calib_off_t1_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__ps1_data_calib_tcs_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__ps1_data_calib_tcs_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__ps1_data_calib_tco_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__ps1_data_calib_tco_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__ps1_data_calib_tref_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__ps1_data_calib_tref_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__ps1_data_calib_temp_sens_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__ps1_data_calib_temp_sens_Set(OBSW_DP_SingleData* root, double value);

/* Field raw selector */
PS_Raw_Data* OBSW_DP_SingleData__ps1_data_raw_Get(OBSW_DP_SingleData* root);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__ps1_data_raw_d1_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__ps1_data_raw_d1_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__ps1_data_raw_d2_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__ps1_data_raw_d2_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* Field processed selector */
PS_Processed_Data* OBSW_DP_SingleData__ps1_data_processed_Get(OBSW_DP_SingleData* root);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__ps1_data_processed_pressure_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__ps1_data_processed_pressure_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__ps1_data_processed_temp_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__ps1_data_processed_temp_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__ps1_data_exist_validity_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__ps1_data_exist_validity_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* ENUMERATED */
int OBSW_DP_SingleData__ps1_data_validity_Get(OBSW_DP_SingleData* root);

/* ENUMERATED */
void OBSW_DP_SingleData__ps1_data_validity_Set(OBSW_DP_SingleData* root, int value);

/* REAL */
double OBSW_DP_SingleData__ps1_gps_time_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__ps1_gps_time_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__ps1_mission_time_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__ps1_mission_time_Set(OBSW_DP_SingleData* root, double value);

/* Field ps2 selector */
OBSW_DP_SingleData_ps2* OBSW_DP_SingleData__ps2_Get(OBSW_DP_SingleData* root);

/* Field data selector */
PS_All_Data* OBSW_DP_SingleData__ps2_data_Get(OBSW_DP_SingleData* root);

/* Field calib selector */
PS_Calibration_Data* OBSW_DP_SingleData__ps2_data_calib_Get(OBSW_DP_SingleData* root);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__ps2_data_calib_c1_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__ps2_data_calib_c1_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__ps2_data_calib_c2_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__ps2_data_calib_c2_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__ps2_data_calib_c3_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__ps2_data_calib_c3_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__ps2_data_calib_c4_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__ps2_data_calib_c4_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__ps2_data_calib_c5_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__ps2_data_calib_c5_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__ps2_data_calib_c6_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__ps2_data_calib_c6_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* REAL */
double OBSW_DP_SingleData__ps2_data_calib_sens_t1_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__ps2_data_calib_sens_t1_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__ps2_data_calib_off_t1_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__ps2_data_calib_off_t1_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__ps2_data_calib_tcs_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__ps2_data_calib_tcs_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__ps2_data_calib_tco_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__ps2_data_calib_tco_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__ps2_data_calib_tref_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__ps2_data_calib_tref_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__ps2_data_calib_temp_sens_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__ps2_data_calib_temp_sens_Set(OBSW_DP_SingleData* root, double value);

/* Field raw selector */
PS_Raw_Data* OBSW_DP_SingleData__ps2_data_raw_Get(OBSW_DP_SingleData* root);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__ps2_data_raw_d1_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__ps2_data_raw_d1_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__ps2_data_raw_d2_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__ps2_data_raw_d2_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* Field processed selector */
PS_Processed_Data* OBSW_DP_SingleData__ps2_data_processed_Get(OBSW_DP_SingleData* root);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__ps2_data_processed_pressure_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__ps2_data_processed_pressure_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__ps2_data_processed_temp_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__ps2_data_processed_temp_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__ps2_data_exist_validity_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__ps2_data_exist_validity_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* ENUMERATED */
int OBSW_DP_SingleData__ps2_data_validity_Get(OBSW_DP_SingleData* root);

/* ENUMERATED */
void OBSW_DP_SingleData__ps2_data_validity_Set(OBSW_DP_SingleData* root, int value);

/* REAL */
double OBSW_DP_SingleData__ps2_gps_time_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__ps2_gps_time_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__ps2_mission_time_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__ps2_mission_time_Set(OBSW_DP_SingleData* root, double value);

/* Field heater1 selector */
OBSW_DP_SingleData_heater1* OBSW_DP_SingleData__heater1_Get(OBSW_DP_SingleData* root);

/* Field data selector */
Heater_Data* OBSW_DP_SingleData__heater1_data_Get(OBSW_DP_SingleData* root);

/* REAL */
double OBSW_DP_SingleData__heater1_data_power_watts_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__heater1_data_power_watts_Set(OBSW_DP_SingleData* root, double value);

/* ENUMERATED */
int OBSW_DP_SingleData__heater1_data_validity_Get(OBSW_DP_SingleData* root);

/* ENUMERATED */
void OBSW_DP_SingleData__heater1_data_validity_Set(OBSW_DP_SingleData* root, int value);

/* REAL */
double OBSW_DP_SingleData__heater1_gps_time_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__heater1_gps_time_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__heater1_mission_time_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__heater1_mission_time_Set(OBSW_DP_SingleData* root, double value);

/* Field heater2 selector */
OBSW_DP_SingleData_heater2* OBSW_DP_SingleData__heater2_Get(OBSW_DP_SingleData* root);

/* Field data selector */
Heater_Data* OBSW_DP_SingleData__heater2_data_Get(OBSW_DP_SingleData* root);

/* REAL */
double OBSW_DP_SingleData__heater2_data_power_watts_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__heater2_data_power_watts_Set(OBSW_DP_SingleData* root, double value);

/* ENUMERATED */
int OBSW_DP_SingleData__heater2_data_validity_Get(OBSW_DP_SingleData* root);

/* ENUMERATED */
void OBSW_DP_SingleData__heater2_data_validity_Set(OBSW_DP_SingleData* root, int value);

/* REAL */
double OBSW_DP_SingleData__heater2_gps_time_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__heater2_gps_time_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__heater2_mission_time_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__heater2_mission_time_Set(OBSW_DP_SingleData* root, double value);

/* Field anemometer selector */
OBSW_DP_SingleData_anemometer* OBSW_DP_SingleData__anemometer_Get(OBSW_DP_SingleData* root);

/* INTEGER */
asn1SccSint OBSW_DP_SingleData__anemometer_data_Get(OBSW_DP_SingleData* root);

/* INTEGER */
void OBSW_DP_SingleData__anemometer_data_Set(OBSW_DP_SingleData* root, asn1SccSint value);

/* REAL */
double OBSW_DP_SingleData__anemometer_gps_time_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__anemometer_gps_time_Set(OBSW_DP_SingleData* root, double value);

/* REAL */
double OBSW_DP_SingleData__anemometer_mission_time_Get(OBSW_DP_SingleData* root);

/* REAL */
void OBSW_DP_SingleData__anemometer_mission_time_Set(OBSW_DP_SingleData* root, double value);

/* SEQUENCEOF/SETOF */
long IMU_Queue__GetLength(IMU_Queue* root);

/* SEQUENCEOF/SETOF */
void IMU_Queue__SetLength(IMU_Queue* root, long value);

/* Field data selector */
IMU_All_Data* IMU_Queue__iDx_data_Get(IMU_Queue* root, int iDx);

/* Field mgt_raw selector */
MGT_Raw_Data* IMU_Queue__iDx_data_mgt_raw_Get(IMU_Queue* root, int iDx);

/* INTEGER */
asn1SccSint IMU_Queue__iDx_data_mgt_raw_x_axis_Get(IMU_Queue* root, int iDx);

/* INTEGER */
void IMU_Queue__iDx_data_mgt_raw_x_axis_Set(IMU_Queue* root, int iDx, asn1SccSint value);

/* INTEGER */
asn1SccSint IMU_Queue__iDx_data_mgt_raw_y_axis_Get(IMU_Queue* root, int iDx);

/* INTEGER */
void IMU_Queue__iDx_data_mgt_raw_y_axis_Set(IMU_Queue* root, int iDx, asn1SccSint value);

/* INTEGER */
asn1SccSint IMU_Queue__iDx_data_mgt_raw_z_axis_Get(IMU_Queue* root, int iDx);

/* INTEGER */
void IMU_Queue__iDx_data_mgt_raw_z_axis_Set(IMU_Queue* root, int iDx, asn1SccSint value);

/* Field mgt_mgauss selector */
MGT_MilliGauss_Data* IMU_Queue__iDx_data_mgt_mgauss_Get(IMU_Queue* root, int iDx);

/* REAL */
double IMU_Queue__iDx_data_mgt_mgauss_x_axis_Get(IMU_Queue* root, int iDx);

/* REAL */
void IMU_Queue__iDx_data_mgt_mgauss_x_axis_Set(IMU_Queue* root, int iDx, double value);

/* REAL */
double IMU_Queue__iDx_data_mgt_mgauss_y_axis_Get(IMU_Queue* root, int iDx);

/* REAL */
void IMU_Queue__iDx_data_mgt_mgauss_y_axis_Set(IMU_Queue* root, int iDx, double value);

/* REAL */
double IMU_Queue__iDx_data_mgt_mgauss_z_axis_Get(IMU_Queue* root, int iDx);

/* REAL */
void IMU_Queue__iDx_data_mgt_mgauss_z_axis_Set(IMU_Queue* root, int iDx, double value);

/* Field accel_raw selector */
ACC_Raw_Data* IMU_Queue__iDx_data_accel_raw_Get(IMU_Queue* root, int iDx);

/* INTEGER */
asn1SccSint IMU_Queue__iDx_data_accel_raw_x_axis_Get(IMU_Queue* root, int iDx);

/* INTEGER */
void IMU_Queue__iDx_data_accel_raw_x_axis_Set(IMU_Queue* root, int iDx, asn1SccSint value);

/* INTEGER */
asn1SccSint IMU_Queue__iDx_data_accel_raw_y_axis_Get(IMU_Queue* root, int iDx);

/* INTEGER */
void IMU_Queue__iDx_data_accel_raw_y_axis_Set(IMU_Queue* root, int iDx, asn1SccSint value);

/* INTEGER */
asn1SccSint IMU_Queue__iDx_data_accel_raw_z_axis_Get(IMU_Queue* root, int iDx);

/* INTEGER */
void IMU_Queue__iDx_data_accel_raw_z_axis_Set(IMU_Queue* root, int iDx, asn1SccSint value);

/* Field accel_mg selector */
ACC_MilliG_Data* IMU_Queue__iDx_data_accel_mg_Get(IMU_Queue* root, int iDx);

/* REAL */
double IMU_Queue__iDx_data_accel_mg_x_axis_Get(IMU_Queue* root, int iDx);

/* REAL */
void IMU_Queue__iDx_data_accel_mg_x_axis_Set(IMU_Queue* root, int iDx, double value);

/* REAL */
double IMU_Queue__iDx_data_accel_mg_y_axis_Get(IMU_Queue* root, int iDx);

/* REAL */
void IMU_Queue__iDx_data_accel_mg_y_axis_Set(IMU_Queue* root, int iDx, double value);

/* REAL */
double IMU_Queue__iDx_data_accel_mg_z_axis_Get(IMU_Queue* root, int iDx);

/* REAL */
void IMU_Queue__iDx_data_accel_mg_z_axis_Set(IMU_Queue* root, int iDx, double value);

/* Field gyro_raw selector */
GYRO_Raw_Data* IMU_Queue__iDx_data_gyro_raw_Get(IMU_Queue* root, int iDx);

/* INTEGER */
asn1SccSint IMU_Queue__iDx_data_gyro_raw_x_axis_Get(IMU_Queue* root, int iDx);

/* INTEGER */
void IMU_Queue__iDx_data_gyro_raw_x_axis_Set(IMU_Queue* root, int iDx, asn1SccSint value);

/* INTEGER */
asn1SccSint IMU_Queue__iDx_data_gyro_raw_y_axis_Get(IMU_Queue* root, int iDx);

/* INTEGER */
void IMU_Queue__iDx_data_gyro_raw_y_axis_Set(IMU_Queue* root, int iDx, asn1SccSint value);

/* INTEGER */
asn1SccSint IMU_Queue__iDx_data_gyro_raw_z_axis_Get(IMU_Queue* root, int iDx);

/* INTEGER */
void IMU_Queue__iDx_data_gyro_raw_z_axis_Set(IMU_Queue* root, int iDx, asn1SccSint value);

/* Field gyro_mdps selector */
GYRO_MilliDPS_Data* IMU_Queue__iDx_data_gyro_mdps_Get(IMU_Queue* root, int iDx);

/* REAL */
double IMU_Queue__iDx_data_gyro_mdps_x_axis_Get(IMU_Queue* root, int iDx);

/* REAL */
void IMU_Queue__iDx_data_gyro_mdps_x_axis_Set(IMU_Queue* root, int iDx, double value);

/* REAL */
double IMU_Queue__iDx_data_gyro_mdps_y_axis_Get(IMU_Queue* root, int iDx);

/* REAL */
void IMU_Queue__iDx_data_gyro_mdps_y_axis_Set(IMU_Queue* root, int iDx, double value);

/* REAL */
double IMU_Queue__iDx_data_gyro_mdps_z_axis_Get(IMU_Queue* root, int iDx);

/* REAL */
void IMU_Queue__iDx_data_gyro_mdps_z_axis_Set(IMU_Queue* root, int iDx, double value);

/* INTEGER */
asn1SccSint IMU_Queue__iDx_data_temp_raw_Get(IMU_Queue* root, int iDx);

/* INTEGER */
void IMU_Queue__iDx_data_temp_raw_Set(IMU_Queue* root, int iDx, asn1SccSint value);

/* REAL */
double IMU_Queue__iDx_data_temp_celsius_Get(IMU_Queue* root, int iDx);

/* REAL */
void IMU_Queue__iDx_data_temp_celsius_Set(IMU_Queue* root, int iDx, double value);

/* ENUMERATED */
int IMU_Queue__iDx_data_mgt_valid_Get(IMU_Queue* root, int iDx);

/* ENUMERATED */
void IMU_Queue__iDx_data_mgt_valid_Set(IMU_Queue* root, int iDx, int value);

/* ENUMERATED */
int IMU_Queue__iDx_data_acc_valid_Get(IMU_Queue* root, int iDx);

/* ENUMERATED */
void IMU_Queue__iDx_data_acc_valid_Set(IMU_Queue* root, int iDx, int value);

/* ENUMERATED */
int IMU_Queue__iDx_data_gyro_valid_Get(IMU_Queue* root, int iDx);

/* ENUMERATED */
void IMU_Queue__iDx_data_gyro_valid_Set(IMU_Queue* root, int iDx, int value);

/* ENUMERATED */
int IMU_Queue__iDx_data_temp_valid_Get(IMU_Queue* root, int iDx);

/* ENUMERATED */
void IMU_Queue__iDx_data_temp_valid_Set(IMU_Queue* root, int iDx, int value);

/* REAL */
double IMU_Queue__iDx_gps_time_Get(IMU_Queue* root, int iDx);

/* REAL */
void IMU_Queue__iDx_gps_time_Set(IMU_Queue* root, int iDx, double value);

/* REAL */
double IMU_Queue__iDx_mission_time_Get(IMU_Queue* root, int iDx);

/* REAL */
void IMU_Queue__iDx_mission_time_Set(IMU_Queue* root, int iDx, double value);

/* ENUMERATED */
int TM__state_htl_Get(TM* root);

/* ENUMERATED */
void TM__state_htl_Set(TM* root, int value);

/* Field heater1 selector */
Heater_Data* TM__heater1_Get(TM* root);

/* REAL */
double TM__heater1_power_watts_Get(TM* root);

/* REAL */
void TM__heater1_power_watts_Set(TM* root, double value);

/* ENUMERATED */
int TM__heater1_validity_Get(TM* root);

/* ENUMERATED */
void TM__heater1_validity_Set(TM* root, int value);

/* Field heater2 selector */
Heater_Data* TM__heater2_Get(TM* root);

/* REAL */
double TM__heater2_power_watts_Get(TM* root);

/* REAL */
void TM__heater2_power_watts_Set(TM* root, double value);

/* ENUMERATED */
int TM__heater2_validity_Get(TM* root);

/* ENUMERATED */
void TM__heater2_validity_Set(TM* root, int value);

/* Field tc74s selector */
TC74s_All_Data TM__tc74s_Get(TM* root);

/* Field tc74s selector */
void TM__tc74s_Set(TM* root, TC74s_All_Data value);

/* SEQUENCEOF/SETOF */
long TM__tc74s_GetLength(TM* root);

/* SEQUENCEOF/SETOF */
void TM__tc74s_SetLength(TM* root, long value);

/* REAL */
double TM__tc74s_iDx_temperature_Get(TM* root, int iDx);

/* REAL */
void TM__tc74s_iDx_temperature_Set(TM* root, int iDx, double value);

/* ENUMERATED */
int TM__tc74s_iDx_validity_Get(TM* root, int iDx);

/* ENUMERATED */
void TM__tc74s_iDx_validity_Set(TM* root, int iDx, int value);

/* Field pt1000s selector */
PT1000s_All_Data* TM__pt1000s_Get(TM* root);

/* Field raw selector */
PT1000s_Raw_Data TM__pt1000s_raw_Get(TM* root);

/* Field raw selector */
void TM__pt1000s_raw_Set(TM* root, PT1000s_Raw_Data value);

/* SEQUENCEOF/SETOF */
long TM__pt1000s_raw_GetLength(TM* root);

/* SEQUENCEOF/SETOF */
void TM__pt1000s_raw_SetLength(TM* root, long value);

/* REAL */
double TM__pt1000s_raw_iDx_vcc_volts_Get(TM* root, int iDx);

/* REAL */
void TM__pt1000s_raw_iDx_vcc_volts_Set(TM* root, int iDx, double value);

/* REAL */
double TM__pt1000s_raw_iDx_pt1000_Get(TM* root, int iDx);

/* REAL */
void TM__pt1000s_raw_iDx_pt1000_Set(TM* root, int iDx, double value);

/* Field celsius selector */
PT1000s_Celsius_Data TM__pt1000s_celsius_Get(TM* root);

/* Field celsius selector */
void TM__pt1000s_celsius_Set(TM* root, PT1000s_Celsius_Data value);

/* SEQUENCEOF/SETOF */
long TM__pt1000s_celsius_GetLength(TM* root);

/* SEQUENCEOF/SETOF */
void TM__pt1000s_celsius_SetLength(TM* root, long value);

/* REAL */
double TM__pt1000s_celsius_iDx_Get(TM* root, int iDx);

/* REAL */
void TM__pt1000s_celsius_iDx_Set(TM* root, int iDx, double value);

/* Field validity selector */
PT1000s_All_Data_validity TM__pt1000s_validity_Get(TM* root);

/* Field validity selector */
void TM__pt1000s_validity_Set(TM* root, PT1000s_All_Data_validity value);

/* SEQUENCEOF/SETOF */
long TM__pt1000s_validity_GetLength(TM* root);

/* SEQUENCEOF/SETOF */
void TM__pt1000s_validity_SetLength(TM* root, long value);

/* ENUMERATED */
int TM__pt1000s_validity_iDx_Get(TM* root, int iDx);

/* ENUMERATED */
void TM__pt1000s_validity_iDx_Set(TM* root, int iDx, int value);

/* Field gps selector */
GPS_PVT* TM__gps_Get(TM* root);

/* ENUMERATED */
int TM__gps_mode_Get(TM* root);

/* ENUMERATED */
void TM__gps_mode_Set(TM* root, int value);

/* REAL */
double TM__gps_date_and_time_Get(TM* root);

/* REAL */
void TM__gps_date_and_time_Set(TM* root, double value);

/* REAL */
double TM__gps_ept_Get(TM* root);

/* REAL */
void TM__gps_ept_Set(TM* root, double value);

/* REAL */
double TM__gps_latitude_Get(TM* root);

/* REAL */
void TM__gps_latitude_Set(TM* root, double value);

/* REAL */
double TM__gps_epy_Get(TM* root);

/* REAL */
void TM__gps_epy_Set(TM* root, double value);

/* REAL */
double TM__gps_longitude_Get(TM* root);

/* REAL */
void TM__gps_longitude_Set(TM* root, double value);

/* REAL */
double TM__gps_epx_Get(TM* root);

/* REAL */
void TM__gps_epx_Set(TM* root, double value);

/* REAL */
double TM__gps_altitude_Get(TM* root);

/* REAL */
void TM__gps_altitude_Set(TM* root, double value);

/* REAL */
double TM__gps_epv_Get(TM* root);

/* REAL */
void TM__gps_epv_Set(TM* root, double value);

/* REAL */
double TM__gps_course_Get(TM* root);

/* REAL */
void TM__gps_course_Set(TM* root, double value);

/* REAL */
double TM__gps_epd_Get(TM* root);

/* REAL */
void TM__gps_epd_Set(TM* root, double value);

/* REAL */
double TM__gps_speed_Get(TM* root);

/* REAL */
void TM__gps_speed_Set(TM* root, double value);

/* REAL */
double TM__gps_eps_Get(TM* root);

/* REAL */
void TM__gps_eps_Set(TM* root, double value);

/* REAL */
double TM__gps_climb_Get(TM* root);

/* REAL */
void TM__gps_climb_Set(TM* root, double value);

/* REAL */
double TM__gps_epc_Get(TM* root);

/* REAL */
void TM__gps_epc_Set(TM* root, double value);

/* Field imu selector */
TM_imu* TM__imu_Get(TM* root);

/* Field mgt_mgauss selector */
MGT_MilliGauss_Data* TM__imu_mgt_mgauss_Get(TM* root);

/* REAL */
double TM__imu_mgt_mgauss_x_axis_Get(TM* root);

/* REAL */
void TM__imu_mgt_mgauss_x_axis_Set(TM* root, double value);

/* REAL */
double TM__imu_mgt_mgauss_y_axis_Get(TM* root);

/* REAL */
void TM__imu_mgt_mgauss_y_axis_Set(TM* root, double value);

/* REAL */
double TM__imu_mgt_mgauss_z_axis_Get(TM* root);

/* REAL */
void TM__imu_mgt_mgauss_z_axis_Set(TM* root, double value);

/* Field accel_mg selector */
ACC_MilliG_Data* TM__imu_accel_mg_Get(TM* root);

/* REAL */
double TM__imu_accel_mg_x_axis_Get(TM* root);

/* REAL */
void TM__imu_accel_mg_x_axis_Set(TM* root, double value);

/* REAL */
double TM__imu_accel_mg_y_axis_Get(TM* root);

/* REAL */
void TM__imu_accel_mg_y_axis_Set(TM* root, double value);

/* REAL */
double TM__imu_accel_mg_z_axis_Get(TM* root);

/* REAL */
void TM__imu_accel_mg_z_axis_Set(TM* root, double value);

/* Field gyro_mdps selector */
GYRO_MilliDPS_Data* TM__imu_gyro_mdps_Get(TM* root);

/* REAL */
double TM__imu_gyro_mdps_x_axis_Get(TM* root);

/* REAL */
void TM__imu_gyro_mdps_x_axis_Set(TM* root, double value);

/* REAL */
double TM__imu_gyro_mdps_y_axis_Get(TM* root);

/* REAL */
void TM__imu_gyro_mdps_y_axis_Set(TM* root, double value);

/* REAL */
double TM__imu_gyro_mdps_z_axis_Get(TM* root);

/* REAL */
void TM__imu_gyro_mdps_z_axis_Set(TM* root, double value);

/* REAL */
double TM__imu_temp_celsius_Get(TM* root);

/* REAL */
void TM__imu_temp_celsius_Set(TM* root, double value);

/* ENUMERATED */
int TM__imu_mgt_valid_Get(TM* root);

/* ENUMERATED */
void TM__imu_mgt_valid_Set(TM* root, int value);

/* ENUMERATED */
int TM__imu_acc_valid_Get(TM* root);

/* ENUMERATED */
void TM__imu_acc_valid_Set(TM* root, int value);

/* ENUMERATED */
int TM__imu_gyro_valid_Get(TM* root);

/* ENUMERATED */
void TM__imu_gyro_valid_Set(TM* root, int value);

/* ENUMERATED */
int TM__imu_temp_valid_Get(TM* root);

/* ENUMERATED */
void TM__imu_temp_valid_Set(TM* root, int value);

/* Field ps1 selector */
PS_Processed_Data* TM__ps1_Get(TM* root);

/* INTEGER */
asn1SccSint TM__ps1_pressure_Get(TM* root);

/* INTEGER */
void TM__ps1_pressure_Set(TM* root, asn1SccSint value);

/* INTEGER */
asn1SccSint TM__ps1_temp_Get(TM* root);

/* INTEGER */
void TM__ps1_temp_Set(TM* root, asn1SccSint value);

/* Field ps2 selector */
PS_Processed_Data* TM__ps2_Get(TM* root);

/* INTEGER */
asn1SccSint TM__ps2_pressure_Get(TM* root);

/* INTEGER */
void TM__ps2_pressure_Set(TM* root, asn1SccSint value);

/* INTEGER */
asn1SccSint TM__ps2_temp_Get(TM* root);

/* INTEGER */
void TM__ps2_temp_Set(TM* root, asn1SccSint value);

/* ENUMERATED */
int TM__ps1_validity_Get(TM* root);

/* ENUMERATED */
void TM__ps1_validity_Set(TM* root, int value);

/* ENUMERATED */
int TM__ps2_validity_Get(TM* root);

/* ENUMERATED */
void TM__ps2_validity_Set(TM* root, int value);

/* INTEGER */
asn1SccSint TM__anemometer_Get(TM* root);

/* INTEGER */
void TM__anemometer_Set(TM* root, asn1SccSint value);

/* ENUMERATED */
int TC_Heater__heater_Get(TC_Heater* root);

/* ENUMERATED */
void TC_Heater__heater_Set(TC_Heater* root, int value);

/* Field command selector */
TC_Heater_command* TC_Heater__command_Get(TC_Heater* root);

/* CHOICE selector */
int TC_Heater__command_kind_Get(TC_Heater* root);

/* CHOICE selector */
void TC_Heater__command_kind_Set(TC_Heater* root, int value);

/* REAL */
double TC_Heater__command_power_manual_Get(TC_Heater* root);

/* REAL */
void TC_Heater__command_power_manual_Set(TC_Heater* root, double value);

/* ENUMERATED */
int TC_Heater__command_max_min_Get(TC_Heater* root);

/* ENUMERATED */
void TC_Heater__command_max_min_Set(TC_Heater* root, int value);

/* CHOICE selector */
int TC__kind_Get(TC* root);

/* CHOICE selector */
void TC__kind_Set(TC* root, int value);

/* Field heater_commands selector */
TC_heater_commands* TC__heater_commands_Get(TC* root);

/* Field heater_of_HTL selector */
TC_Heater* TC__heater_commands_heater_of_HTL_Get(TC* root);

/* ENUMERATED */
int TC__heater_commands_heater_of_HTL_heater_Get(TC* root);

/* ENUMERATED */
void TC__heater_commands_heater_of_HTL_heater_Set(TC* root, int value);

/* Field command selector */
TC_Heater_command* TC__heater_commands_heater_of_HTL_command_Get(TC* root);

/* CHOICE selector */
int TC__heater_commands_heater_of_HTL_command_kind_Get(TC* root);

/* CHOICE selector */
void TC__heater_commands_heater_of_HTL_command_kind_Set(TC* root, int value);

/* REAL */
double TC__heater_commands_heater_of_HTL_command_power_manual_Get(TC* root);

/* REAL */
void TC__heater_commands_heater_of_HTL_command_power_manual_Set(TC* root, double value);

/* ENUMERATED */
int TC__heater_commands_heater_of_HTL_command_max_min_Get(TC* root);

/* ENUMERATED */
void TC__heater_commands_heater_of_HTL_command_max_min_Set(TC* root, int value);

/* Field config_of_HTL selector */
HTL_Config* TC__heater_commands_config_of_HTL_Get(TC* root);

/* INTEGER */
asn1SccSint TC__heater_commands_config_of_HTL_exist_press_5km_Get(TC* root);

/* INTEGER */
void TC__heater_commands_config_of_HTL_exist_press_5km_Set(TC* root, asn1SccSint value);

/* REAL */
double TC__heater_commands_config_of_HTL_press_5km_Get(TC* root);

/* REAL */
void TC__heater_commands_config_of_HTL_press_5km_Set(TC* root, double value);

/* INTEGER */
asn1SccSint TC__heater_commands_config_of_HTL_exist_press_10km_Get(TC* root);

/* INTEGER */
void TC__heater_commands_config_of_HTL_exist_press_10km_Set(TC* root, asn1SccSint value);

/* REAL */
double TC__heater_commands_config_of_HTL_press_10km_Get(TC* root);

/* REAL */
void TC__heater_commands_config_of_HTL_press_10km_Set(TC* root, double value);

/* INTEGER */
asn1SccSint TC__heater_commands_config_of_HTL_exist_press_18km_Get(TC* root);

/* INTEGER */
void TC__heater_commands_config_of_HTL_exist_press_18km_Set(TC* root, asn1SccSint value);

/* REAL */
double TC__heater_commands_config_of_HTL_press_18km_Get(TC* root);

/* REAL */
void TC__heater_commands_config_of_HTL_press_18km_Set(TC* root, double value);

/* INTEGER */
asn1SccSint TC__heater_commands_config_of_HTL_exist_a1_duration_emergency_secs_Get(TC* root);

/* INTEGER */
void TC__heater_commands_config_of_HTL_exist_a1_duration_emergency_secs_Set(TC* root, asn1SccSint value);

/* REAL */
double TC__heater_commands_config_of_HTL_a1_duration_emergency_secs_Get(TC* root);

/* REAL */
void TC__heater_commands_config_of_HTL_a1_duration_emergency_secs_Set(TC* root, double value);

/* INTEGER */
asn1SccSint TC__heater_commands_config_of_HTL_exist_a1_duration_max_secs_Get(TC* root);

/* INTEGER */
void TC__heater_commands_config_of_HTL_exist_a1_duration_max_secs_Set(TC* root, asn1SccSint value);

/* REAL */
double TC__heater_commands_config_of_HTL_a1_duration_max_secs_Get(TC* root);

/* REAL */
void TC__heater_commands_config_of_HTL_a1_duration_max_secs_Set(TC* root, double value);

/* INTEGER */
asn1SccSint TC__heater_commands_config_of_HTL_exist_a2_duration_max_secs_Get(TC* root);

/* INTEGER */
void TC__heater_commands_config_of_HTL_exist_a2_duration_max_secs_Set(TC* root, asn1SccSint value);

/* REAL */
double TC__heater_commands_config_of_HTL_a2_duration_max_secs_Get(TC* root);

/* REAL */
void TC__heater_commands_config_of_HTL_a2_duration_max_secs_Set(TC* root, double value);

/* INTEGER */
asn1SccSint TC__heater_commands_config_of_HTL_exist_f1_duration_secs_Get(TC* root);

/* INTEGER */
void TC__heater_commands_config_of_HTL_exist_f1_duration_secs_Set(TC* root, asn1SccSint value);

/* INTEGER */
asn1SccSint TC__heater_commands_config_of_HTL_f1_duration_secs_Get(TC* root);

/* INTEGER */
void TC__heater_commands_config_of_HTL_f1_duration_secs_Set(TC* root, asn1SccSint value);

/* INTEGER */
asn1SccSint TC__heater_commands_config_of_HTL_exist_f2_duration_secs_Get(TC* root);

/* INTEGER */
void TC__heater_commands_config_of_HTL_exist_f2_duration_secs_Set(TC* root, asn1SccSint value);

/* INTEGER */
asn1SccSint TC__heater_commands_config_of_HTL_f2_duration_secs_Get(TC* root);

/* INTEGER */
void TC__heater_commands_config_of_HTL_f2_duration_secs_Set(TC* root, asn1SccSint value);

/* ENUMERATED */
int TC__system_commands_Get(TC* root);

/* ENUMERATED */
void TC__system_commands_Set(TC* root, int value);

/* ENUMERATED */
int HTL_GUI__state_Get(HTL_GUI* root);

/* ENUMERATED */
void HTL_GUI__state_Set(HTL_GUI* root, int value);

/* Field heater selector */
Heater_Data* HTL_GUI__heater_Get(HTL_GUI* root);

/* REAL */
double HTL_GUI__heater_power_watts_Get(HTL_GUI* root);

/* REAL */
void HTL_GUI__heater_power_watts_Set(HTL_GUI* root, double value);

/* ENUMERATED */
int HTL_GUI__heater_validity_Get(HTL_GUI* root);

/* ENUMERATED */
void HTL_GUI__heater_validity_Set(HTL_GUI* root, int value);

/* REAL */
double HTL_GUI__delta_T_Get(HTL_GUI* root);

/* REAL */
void HTL_GUI__delta_T_Set(HTL_GUI* root, double value);

/* Field pt1000s selector */
HTL_GUI_pt1000s* HTL_GUI__pt1000s_Get(HTL_GUI* root);

/* REAL */
double HTL_GUI__pt1000s_aire_abajo_Get(HTL_GUI* root);

/* REAL */
void HTL_GUI__pt1000s_aire_abajo_Set(HTL_GUI* root, double value);

/* REAL */
double HTL_GUI__pt1000s_aire_arriba_Get(HTL_GUI* root);

/* REAL */
void HTL_GUI__pt1000s_aire_arriba_Set(HTL_GUI* root, double value);

/* REAL */
double HTL_GUI__pt1000s_placa_abajo_Get(HTL_GUI* root);

/* REAL */
void HTL_GUI__pt1000s_placa_abajo_Set(HTL_GUI* root, double value);

/* REAL */
double HTL_GUI__pt1000s_placa_arriba_Get(HTL_GUI* root);

/* REAL */
void HTL_GUI__pt1000s_placa_arriba_Set(HTL_GUI* root, double value);

/* REAL */
double HTL_GUI__pt1000s_infinito_Get(HTL_GUI* root);

/* REAL */
void HTL_GUI__pt1000s_infinito_Set(HTL_GUI* root, double value);

/* REAL */
double HTL_GUI__pt1000s_exterior_Get(HTL_GUI* root);

/* REAL */
void HTL_GUI__pt1000s_exterior_Set(HTL_GUI* root, double value);

/* Field validity selector */
HTL_GUI_pt1000s_validity HTL_GUI__pt1000s_validity_Get(HTL_GUI* root);

/* Field validity selector */
void HTL_GUI__pt1000s_validity_Set(HTL_GUI* root, HTL_GUI_pt1000s_validity value);

/* SEQUENCEOF/SETOF */
long HTL_GUI__pt1000s_validity_GetLength(HTL_GUI* root);

/* SEQUENCEOF/SETOF */
void HTL_GUI__pt1000s_validity_SetLength(HTL_GUI* root, long value);

/* ENUMERATED */
int HTL_GUI__pt1000s_validity_iDx_Get(HTL_GUI* root, int iDx);

/* ENUMERATED */
void HTL_GUI__pt1000s_validity_iDx_Set(HTL_GUI* root, int iDx, int value);

/* Field tc74s selector */
HTL_GUI_tc74s* HTL_GUI__tc74s_Get(HTL_GUI* root);

/* REAL */
double HTL_GUI__tc74s_x_positive_Get(HTL_GUI* root);

/* REAL */
void HTL_GUI__tc74s_x_positive_Set(HTL_GUI* root, double value);

/* REAL */
double HTL_GUI__tc74s_x_negative_Get(HTL_GUI* root);

/* REAL */
void HTL_GUI__tc74s_x_negative_Set(HTL_GUI* root, double value);

/* REAL */
double HTL_GUI__tc74s_y_positive_Get(HTL_GUI* root);

/* REAL */
void HTL_GUI__tc74s_y_positive_Set(HTL_GUI* root, double value);

/* REAL */
double HTL_GUI__tc74s_y_negative_Get(HTL_GUI* root);

/* REAL */
void HTL_GUI__tc74s_y_negative_Set(HTL_GUI* root, double value);

/* REAL */
double HTL_GUI__tc74s_z_techo_Get(HTL_GUI* root);

/* REAL */
void HTL_GUI__tc74s_z_techo_Set(HTL_GUI* root, double value);

/* Field validity selector */
HTL_GUI_tc74s_validity HTL_GUI__tc74s_validity_Get(HTL_GUI* root);

/* Field validity selector */
void HTL_GUI__tc74s_validity_Set(HTL_GUI* root, HTL_GUI_tc74s_validity value);

/* SEQUENCEOF/SETOF */
long HTL_GUI__tc74s_validity_GetLength(HTL_GUI* root);

/* SEQUENCEOF/SETOF */
void HTL_GUI__tc74s_validity_SetLength(HTL_GUI* root, long value);

/* ENUMERATED */
int HTL_GUI__tc74s_validity_iDx_Get(HTL_GUI* root, int iDx);

/* ENUMERATED */
void HTL_GUI__tc74s_validity_iDx_Set(HTL_GUI* root, int iDx, int value);

/* INTEGER */
asn1SccSint Date_Time__day_Get(Date_Time* root);

/* INTEGER */
void Date_Time__day_Set(Date_Time* root, asn1SccSint value);

/* INTEGER */
asn1SccSint Date_Time__month_Get(Date_Time* root);

/* INTEGER */
void Date_Time__month_Set(Date_Time* root, asn1SccSint value);

/* INTEGER */
asn1SccSint Date_Time__year_Get(Date_Time* root);

/* INTEGER */
void Date_Time__year_Set(Date_Time* root, asn1SccSint value);

/* INTEGER */
asn1SccSint Date_Time__hour_Get(Date_Time* root);

/* INTEGER */
void Date_Time__hour_Set(Date_Time* root, asn1SccSint value);

/* INTEGER */
asn1SccSint Date_Time__minute_Get(Date_Time* root);

/* INTEGER */
void Date_Time__minute_Set(Date_Time* root, asn1SccSint value);

/* INTEGER */
asn1SccSint Date_Time__second_Get(Date_Time* root);

/* INTEGER */
void Date_Time__second_Set(Date_Time* root, asn1SccSint value);

/* Field gps selector */
GPS_PVT* ATT_GUI__gps_Get(ATT_GUI* root);

/* ENUMERATED */
int ATT_GUI__gps_mode_Get(ATT_GUI* root);

/* ENUMERATED */
void ATT_GUI__gps_mode_Set(ATT_GUI* root, int value);

/* REAL */
double ATT_GUI__gps_date_and_time_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__gps_date_and_time_Set(ATT_GUI* root, double value);

/* REAL */
double ATT_GUI__gps_ept_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__gps_ept_Set(ATT_GUI* root, double value);

/* REAL */
double ATT_GUI__gps_latitude_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__gps_latitude_Set(ATT_GUI* root, double value);

/* REAL */
double ATT_GUI__gps_epy_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__gps_epy_Set(ATT_GUI* root, double value);

/* REAL */
double ATT_GUI__gps_longitude_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__gps_longitude_Set(ATT_GUI* root, double value);

/* REAL */
double ATT_GUI__gps_epx_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__gps_epx_Set(ATT_GUI* root, double value);

/* REAL */
double ATT_GUI__gps_altitude_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__gps_altitude_Set(ATT_GUI* root, double value);

/* REAL */
double ATT_GUI__gps_epv_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__gps_epv_Set(ATT_GUI* root, double value);

/* REAL */
double ATT_GUI__gps_course_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__gps_course_Set(ATT_GUI* root, double value);

/* REAL */
double ATT_GUI__gps_epd_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__gps_epd_Set(ATT_GUI* root, double value);

/* REAL */
double ATT_GUI__gps_speed_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__gps_speed_Set(ATT_GUI* root, double value);

/* REAL */
double ATT_GUI__gps_eps_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__gps_eps_Set(ATT_GUI* root, double value);

/* REAL */
double ATT_GUI__gps_climb_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__gps_climb_Set(ATT_GUI* root, double value);

/* REAL */
double ATT_GUI__gps_epc_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__gps_epc_Set(ATT_GUI* root, double value);

/* Field gps_date_time selector */
Date_Time* ATT_GUI__gps_date_time_Get(ATT_GUI* root);

/* INTEGER */
asn1SccSint ATT_GUI__gps_date_time_day_Get(ATT_GUI* root);

/* INTEGER */
void ATT_GUI__gps_date_time_day_Set(ATT_GUI* root, asn1SccSint value);

/* INTEGER */
asn1SccSint ATT_GUI__gps_date_time_month_Get(ATT_GUI* root);

/* INTEGER */
void ATT_GUI__gps_date_time_month_Set(ATT_GUI* root, asn1SccSint value);

/* INTEGER */
asn1SccSint ATT_GUI__gps_date_time_year_Get(ATT_GUI* root);

/* INTEGER */
void ATT_GUI__gps_date_time_year_Set(ATT_GUI* root, asn1SccSint value);

/* INTEGER */
asn1SccSint ATT_GUI__gps_date_time_hour_Get(ATT_GUI* root);

/* INTEGER */
void ATT_GUI__gps_date_time_hour_Set(ATT_GUI* root, asn1SccSint value);

/* INTEGER */
asn1SccSint ATT_GUI__gps_date_time_minute_Get(ATT_GUI* root);

/* INTEGER */
void ATT_GUI__gps_date_time_minute_Set(ATT_GUI* root, asn1SccSint value);

/* INTEGER */
asn1SccSint ATT_GUI__gps_date_time_second_Get(ATT_GUI* root);

/* INTEGER */
void ATT_GUI__gps_date_time_second_Set(ATT_GUI* root, asn1SccSint value);

/* Field imu selector */
ATT_GUI_imu* ATT_GUI__imu_Get(ATT_GUI* root);

/* Field mgt_mgauss selector */
MGT_MilliGauss_Data* ATT_GUI__imu_mgt_mgauss_Get(ATT_GUI* root);

/* REAL */
double ATT_GUI__imu_mgt_mgauss_x_axis_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__imu_mgt_mgauss_x_axis_Set(ATT_GUI* root, double value);

/* REAL */
double ATT_GUI__imu_mgt_mgauss_y_axis_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__imu_mgt_mgauss_y_axis_Set(ATT_GUI* root, double value);

/* REAL */
double ATT_GUI__imu_mgt_mgauss_z_axis_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__imu_mgt_mgauss_z_axis_Set(ATT_GUI* root, double value);

/* Field accel_mg selector */
ACC_MilliG_Data* ATT_GUI__imu_accel_mg_Get(ATT_GUI* root);

/* REAL */
double ATT_GUI__imu_accel_mg_x_axis_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__imu_accel_mg_x_axis_Set(ATT_GUI* root, double value);

/* REAL */
double ATT_GUI__imu_accel_mg_y_axis_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__imu_accel_mg_y_axis_Set(ATT_GUI* root, double value);

/* REAL */
double ATT_GUI__imu_accel_mg_z_axis_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__imu_accel_mg_z_axis_Set(ATT_GUI* root, double value);

/* Field gyro_mdps selector */
GYRO_MilliDPS_Data* ATT_GUI__imu_gyro_mdps_Get(ATT_GUI* root);

/* REAL */
double ATT_GUI__imu_gyro_mdps_x_axis_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__imu_gyro_mdps_x_axis_Set(ATT_GUI* root, double value);

/* REAL */
double ATT_GUI__imu_gyro_mdps_y_axis_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__imu_gyro_mdps_y_axis_Set(ATT_GUI* root, double value);

/* REAL */
double ATT_GUI__imu_gyro_mdps_z_axis_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__imu_gyro_mdps_z_axis_Set(ATT_GUI* root, double value);

/* REAL */
double ATT_GUI__imu_temp_celsius_Get(ATT_GUI* root);

/* REAL */
void ATT_GUI__imu_temp_celsius_Set(ATT_GUI* root, double value);

/* ENUMERATED */
int ATT_GUI__imu_mgt_valid_Get(ATT_GUI* root);

/* ENUMERATED */
void ATT_GUI__imu_mgt_valid_Set(ATT_GUI* root, int value);

/* ENUMERATED */
int ATT_GUI__imu_acc_valid_Get(ATT_GUI* root);

/* ENUMERATED */
void ATT_GUI__imu_acc_valid_Set(ATT_GUI* root, int value);

/* ENUMERATED */
int ATT_GUI__imu_gyro_valid_Get(ATT_GUI* root);

/* ENUMERATED */
void ATT_GUI__imu_gyro_valid_Set(ATT_GUI* root, int value);

/* ENUMERATED */
int ATT_GUI__imu_temp_valid_Get(ATT_GUI* root);

/* ENUMERATED */
void ATT_GUI__imu_temp_valid_Set(ATT_GUI* root, int value);

/* REAL */
double PS_GUI__pressure_mbar_Get(PS_GUI* root);

/* REAL */
void PS_GUI__pressure_mbar_Set(PS_GUI* root, double value);

/* REAL */
double PS_GUI__temperature_celsius_Get(PS_GUI* root);

/* REAL */
void PS_GUI__temperature_celsius_Set(PS_GUI* root, double value);

/* ENUMERATED */
int PS_GUI__validity_Get(PS_GUI* root);

/* ENUMERATED */
void PS_GUI__validity_Set(PS_GUI* root, int value);

/* Field pressure_sensor_1 selector */
PS_GUI* ENV_GUI__pressure_sensor_1_Get(ENV_GUI* root);

/* REAL */
double ENV_GUI__pressure_sensor_1_pressure_mbar_Get(ENV_GUI* root);

/* REAL */
void ENV_GUI__pressure_sensor_1_pressure_mbar_Set(ENV_GUI* root, double value);

/* REAL */
double ENV_GUI__pressure_sensor_1_temperature_celsius_Get(ENV_GUI* root);

/* REAL */
void ENV_GUI__pressure_sensor_1_temperature_celsius_Set(ENV_GUI* root, double value);

/* ENUMERATED */
int ENV_GUI__pressure_sensor_1_validity_Get(ENV_GUI* root);

/* ENUMERATED */
void ENV_GUI__pressure_sensor_1_validity_Set(ENV_GUI* root, int value);

/* Field pressure_sensor_2 selector */
PS_GUI* ENV_GUI__pressure_sensor_2_Get(ENV_GUI* root);

/* REAL */
double ENV_GUI__pressure_sensor_2_pressure_mbar_Get(ENV_GUI* root);

/* REAL */
void ENV_GUI__pressure_sensor_2_pressure_mbar_Set(ENV_GUI* root, double value);

/* REAL */
double ENV_GUI__pressure_sensor_2_temperature_celsius_Get(ENV_GUI* root);

/* REAL */
void ENV_GUI__pressure_sensor_2_temperature_celsius_Set(ENV_GUI* root, double value);

/* ENUMERATED */
int ENV_GUI__pressure_sensor_2_validity_Get(ENV_GUI* root);

/* ENUMERATED */
void ENV_GUI__pressure_sensor_2_validity_Set(ENV_GUI* root, int value);

/* Field anemometer selector */
ENV_GUI_anemometer* ENV_GUI__anemometer_Get(ENV_GUI* root);

/* INTEGER */
asn1SccSint ENV_GUI__anemometer_global_counter_Get(ENV_GUI* root);

/* INTEGER */
void ENV_GUI__anemometer_global_counter_Set(ENV_GUI* root, asn1SccSint value);

/* REAL */
double ENV_GUI__anemometer_temperature_celsius_Get(ENV_GUI* root);

/* REAL */
void ENV_GUI__anemometer_temperature_celsius_Set(ENV_GUI* root, double value);

/* ENUMERATED */
int ENV_GUI__anemometer_temperature_validity_Get(ENV_GUI* root);

/* ENUMERATED */
void ENV_GUI__anemometer_temperature_validity_Set(ENV_GUI* root, int value);

/* Field heater selector */
Heater_Data* ENV_GUI__heater_Get(ENV_GUI* root);

/* REAL */
double ENV_GUI__heater_power_watts_Get(ENV_GUI* root);

/* REAL */
void ENV_GUI__heater_power_watts_Set(ENV_GUI* root, double value);

/* ENUMERATED */
int ENV_GUI__heater_validity_Get(ENV_GUI* root);

/* ENUMERATED */
void ENV_GUI__heater_validity_Set(ENV_GUI* root, int value);

/* INTEGER */
asn1SccSint T_Int32__Get(T_Int32* root);

/* INTEGER */
void T_Int32__Set(T_Int32* root, asn1SccSint value);

/* INTEGER */
asn1SccSint T_UInt32__Get(T_UInt32* root);

/* INTEGER */
void T_UInt32__Set(T_UInt32* root, asn1SccSint value);

/* INTEGER */
asn1SccSint T_Int8__Get(T_Int8* root);

/* INTEGER */
void T_Int8__Set(T_Int8* root, asn1SccSint value);

/* INTEGER */
asn1SccSint T_UInt8__Get(T_UInt8* root);

/* INTEGER */
void T_UInt8__Set(T_UInt8* root, asn1SccSint value);

/* BOOLEAN */
flag T_Boolean__Get(T_Boolean* root);

/* BOOLEAN */
void T_Boolean__Set(T_Boolean* root, flag value);

/* Helper functions for NATIVE encodings */

void SetDataFor_T_Int16(void *dest, void *src);
byte* MovePtrBySizeOf_T_Int16(byte *pData);
byte* CreateInstanceOf_T_Int16(void);
void DestroyInstanceOf_T_Int16(byte *pData);

void SetDataFor_T_UInt16(void *dest, void *src);
byte* MovePtrBySizeOf_T_UInt16(byte *pData);
byte* CreateInstanceOf_T_UInt16(void);
void DestroyInstanceOf_T_UInt16(byte *pData);

void SetDataFor_T_UInt64(void *dest, void *src);
byte* MovePtrBySizeOf_T_UInt64(byte *pData);
byte* CreateInstanceOf_T_UInt64(void);
void DestroyInstanceOf_T_UInt64(byte *pData);

void SetDataFor_T_Float(void *dest, void *src);
byte* MovePtrBySizeOf_T_Float(byte *pData);
byte* CreateInstanceOf_T_Float(void);
void DestroyInstanceOf_T_Float(byte *pData);

void SetDataFor_T_Double(void *dest, void *src);
byte* MovePtrBySizeOf_T_Double(byte *pData);
byte* CreateInstanceOf_T_Double(void);
void DestroyInstanceOf_T_Double(byte *pData);

void SetDataFor_File_Name(void *dest, void *src);
byte* MovePtrBySizeOf_File_Name(byte *pData);
byte* CreateInstanceOf_File_Name(void);
void DestroyInstanceOf_File_Name(byte *pData);

void SetDataFor_Content_Validity(void *dest, void *src);
byte* MovePtrBySizeOf_Content_Validity(byte *pData);
byte* CreateInstanceOf_Content_Validity(void);
void DestroyInstanceOf_Content_Validity(byte *pData);

void SetDataFor_WD_TIMEOUT(void *dest, void *src);
byte* MovePtrBySizeOf_WD_TIMEOUT(byte *pData);
byte* CreateInstanceOf_WD_TIMEOUT(void);
void DestroyInstanceOf_WD_TIMEOUT(byte *pData);

void SetDataFor_SPI_ID(void *dest, void *src);
byte* MovePtrBySizeOf_SPI_ID(byte *pData);
byte* CreateInstanceOf_SPI_ID(void);
void DestroyInstanceOf_SPI_ID(byte *pData);

void SetDataFor_I2C_ID(void *dest, void *src);
byte* MovePtrBySizeOf_I2C_ID(byte *pData);
byte* CreateInstanceOf_I2C_ID(void);
void DestroyInstanceOf_I2C_ID(byte *pData);

void SetDataFor_GPS_PVT(void *dest, void *src);
byte* MovePtrBySizeOf_GPS_PVT(byte *pData);
byte* CreateInstanceOf_GPS_PVT(void);
void DestroyInstanceOf_GPS_PVT(byte *pData);

void SetDataFor_MGT_Raw_Data(void *dest, void *src);
byte* MovePtrBySizeOf_MGT_Raw_Data(byte *pData);
byte* CreateInstanceOf_MGT_Raw_Data(void);
void DestroyInstanceOf_MGT_Raw_Data(byte *pData);

void SetDataFor_MGT_MilliGauss_Data(void *dest, void *src);
byte* MovePtrBySizeOf_MGT_MilliGauss_Data(byte *pData);
byte* CreateInstanceOf_MGT_MilliGauss_Data(void);
void DestroyInstanceOf_MGT_MilliGauss_Data(byte *pData);

void SetDataFor_ACC_Raw_Data(void *dest, void *src);
byte* MovePtrBySizeOf_ACC_Raw_Data(byte *pData);
byte* CreateInstanceOf_ACC_Raw_Data(void);
void DestroyInstanceOf_ACC_Raw_Data(byte *pData);

void SetDataFor_ACC_MilliG_Data(void *dest, void *src);
byte* MovePtrBySizeOf_ACC_MilliG_Data(byte *pData);
byte* CreateInstanceOf_ACC_MilliG_Data(void);
void DestroyInstanceOf_ACC_MilliG_Data(byte *pData);

void SetDataFor_GYRO_Raw_Data(void *dest, void *src);
byte* MovePtrBySizeOf_GYRO_Raw_Data(byte *pData);
byte* CreateInstanceOf_GYRO_Raw_Data(void);
void DestroyInstanceOf_GYRO_Raw_Data(byte *pData);

void SetDataFor_GYRO_MilliDPS_Data(void *dest, void *src);
byte* MovePtrBySizeOf_GYRO_MilliDPS_Data(byte *pData);
byte* CreateInstanceOf_GYRO_MilliDPS_Data(void);
void DestroyInstanceOf_GYRO_MilliDPS_Data(byte *pData);

void SetDataFor_IMU_All_Data(void *dest, void *src);
byte* MovePtrBySizeOf_IMU_All_Data(byte *pData);
byte* CreateInstanceOf_IMU_All_Data(void);
void DestroyInstanceOf_IMU_All_Data(byte *pData);

void SetDataFor_TC74s_I2CBuses(void *dest, void *src);
byte* MovePtrBySizeOf_TC74s_I2CBuses(byte *pData);
byte* CreateInstanceOf_TC74s_I2CBuses(void);
void DestroyInstanceOf_TC74s_I2CBuses(byte *pData);

void SetDataFor_TC74s_All_Data(void *dest, void *src);
byte* MovePtrBySizeOf_TC74s_All_Data(byte *pData);
byte* CreateInstanceOf_TC74s_All_Data(void);
void DestroyInstanceOf_TC74s_All_Data(byte *pData);

void SetDataFor_PT1000s_Channels(void *dest, void *src);
byte* MovePtrBySizeOf_PT1000s_Channels(byte *pData);
byte* CreateInstanceOf_PT1000s_Channels(void);
void DestroyInstanceOf_PT1000s_Channels(byte *pData);

void SetDataFor_PT1000s_Raw_Data(void *dest, void *src);
byte* MovePtrBySizeOf_PT1000s_Raw_Data(byte *pData);
byte* CreateInstanceOf_PT1000s_Raw_Data(void);
void DestroyInstanceOf_PT1000s_Raw_Data(byte *pData);

void SetDataFor_PT1000s_Celsius_Data(void *dest, void *src);
byte* MovePtrBySizeOf_PT1000s_Celsius_Data(byte *pData);
byte* CreateInstanceOf_PT1000s_Celsius_Data(void);
void DestroyInstanceOf_PT1000s_Celsius_Data(byte *pData);

void SetDataFor_PT1000s_All_Data(void *dest, void *src);
byte* MovePtrBySizeOf_PT1000s_All_Data(byte *pData);
byte* CreateInstanceOf_PT1000s_All_Data(void);
void DestroyInstanceOf_PT1000s_All_Data(byte *pData);

void SetDataFor_PS_Calibration_Data(void *dest, void *src);
byte* MovePtrBySizeOf_PS_Calibration_Data(byte *pData);
byte* CreateInstanceOf_PS_Calibration_Data(void);
void DestroyInstanceOf_PS_Calibration_Data(byte *pData);

void SetDataFor_PS_Raw_Data(void *dest, void *src);
byte* MovePtrBySizeOf_PS_Raw_Data(byte *pData);
byte* CreateInstanceOf_PS_Raw_Data(void);
void DestroyInstanceOf_PS_Raw_Data(byte *pData);

void SetDataFor_PS_Processed_Data(void *dest, void *src);
byte* MovePtrBySizeOf_PS_Processed_Data(byte *pData);
byte* CreateInstanceOf_PS_Processed_Data(void);
void DestroyInstanceOf_PS_Processed_Data(byte *pData);

void SetDataFor_PS_All_Data(void *dest, void *src);
byte* MovePtrBySizeOf_PS_All_Data(byte *pData);
byte* CreateInstanceOf_PS_All_Data(void);
void DestroyInstanceOf_PS_All_Data(byte *pData);

void SetDataFor_Heater_Data(void *dest, void *src);
byte* MovePtrBySizeOf_Heater_Data(byte *pData);
byte* CreateInstanceOf_Heater_Data(void);
void DestroyInstanceOf_Heater_Data(byte *pData);

void SetDataFor_Heater_On_Off(void *dest, void *src);
byte* MovePtrBySizeOf_Heater_On_Off(byte *pData);
byte* CreateInstanceOf_Heater_On_Off(void);
void DestroyInstanceOf_Heater_On_Off(byte *pData);

void SetDataFor_HTL_State(void *dest, void *src);
byte* MovePtrBySizeOf_HTL_State(byte *pData);
byte* CreateInstanceOf_HTL_State(void);
void DestroyInstanceOf_HTL_State(byte *pData);

void SetDataFor_HTL_Config(void *dest, void *src);
byte* MovePtrBySizeOf_HTL_Config(byte *pData);
byte* CreateInstanceOf_HTL_Config(void);
void DestroyInstanceOf_HTL_Config(byte *pData);

void SetDataFor_OBSW_DP_Data(void *dest, void *src);
byte* MovePtrBySizeOf_OBSW_DP_Data(byte *pData);
byte* CreateInstanceOf_OBSW_DP_Data(void);
void DestroyInstanceOf_OBSW_DP_Data(byte *pData);

void SetDataFor_OBSW_DP_Filter(void *dest, void *src);
byte* MovePtrBySizeOf_OBSW_DP_Filter(byte *pData);
byte* CreateInstanceOf_OBSW_DP_Filter(void);
void DestroyInstanceOf_OBSW_DP_Filter(byte *pData);

void SetDataFor_OBSW_DP_SingleData(void *dest, void *src);
byte* MovePtrBySizeOf_OBSW_DP_SingleData(byte *pData);
byte* CreateInstanceOf_OBSW_DP_SingleData(void);
void DestroyInstanceOf_OBSW_DP_SingleData(byte *pData);

void SetDataFor_IMU_Queue(void *dest, void *src);
byte* MovePtrBySizeOf_IMU_Queue(byte *pData);
byte* CreateInstanceOf_IMU_Queue(void);
void DestroyInstanceOf_IMU_Queue(byte *pData);

void SetDataFor_TM(void *dest, void *src);
byte* MovePtrBySizeOf_TM(byte *pData);
byte* CreateInstanceOf_TM(void);
void DestroyInstanceOf_TM(byte *pData);

void SetDataFor_TC_Heater(void *dest, void *src);
byte* MovePtrBySizeOf_TC_Heater(byte *pData);
byte* CreateInstanceOf_TC_Heater(void);
void DestroyInstanceOf_TC_Heater(byte *pData);

void SetDataFor_TC(void *dest, void *src);
byte* MovePtrBySizeOf_TC(byte *pData);
byte* CreateInstanceOf_TC(void);
void DestroyInstanceOf_TC(byte *pData);

void SetDataFor_HTL_GUI(void *dest, void *src);
byte* MovePtrBySizeOf_HTL_GUI(byte *pData);
byte* CreateInstanceOf_HTL_GUI(void);
void DestroyInstanceOf_HTL_GUI(byte *pData);

void SetDataFor_Date_Time(void *dest, void *src);
byte* MovePtrBySizeOf_Date_Time(byte *pData);
byte* CreateInstanceOf_Date_Time(void);
void DestroyInstanceOf_Date_Time(byte *pData);

void SetDataFor_ATT_GUI(void *dest, void *src);
byte* MovePtrBySizeOf_ATT_GUI(byte *pData);
byte* CreateInstanceOf_ATT_GUI(void);
void DestroyInstanceOf_ATT_GUI(byte *pData);

void SetDataFor_PS_GUI(void *dest, void *src);
byte* MovePtrBySizeOf_PS_GUI(byte *pData);
byte* CreateInstanceOf_PS_GUI(void);
void DestroyInstanceOf_PS_GUI(byte *pData);

void SetDataFor_ENV_GUI(void *dest, void *src);
byte* MovePtrBySizeOf_ENV_GUI(byte *pData);
byte* CreateInstanceOf_ENV_GUI(void);
void DestroyInstanceOf_ENV_GUI(byte *pData);

void SetDataFor_T_Int32(void *dest, void *src);
byte* MovePtrBySizeOf_T_Int32(byte *pData);
byte* CreateInstanceOf_T_Int32(void);
void DestroyInstanceOf_T_Int32(byte *pData);

void SetDataFor_T_UInt32(void *dest, void *src);
byte* MovePtrBySizeOf_T_UInt32(byte *pData);
byte* CreateInstanceOf_T_UInt32(void);
void DestroyInstanceOf_T_UInt32(byte *pData);

void SetDataFor_T_Int8(void *dest, void *src);
byte* MovePtrBySizeOf_T_Int8(byte *pData);
byte* CreateInstanceOf_T_Int8(void);
void DestroyInstanceOf_T_Int8(byte *pData);

void SetDataFor_T_UInt8(void *dest, void *src);
byte* MovePtrBySizeOf_T_UInt8(byte *pData);
byte* CreateInstanceOf_T_UInt8(void);
void DestroyInstanceOf_T_UInt8(byte *pData);

void SetDataFor_T_Boolean(void *dest, void *src);
byte* MovePtrBySizeOf_T_Boolean(byte *pData);
byte* CreateInstanceOf_T_Boolean(void);
void DestroyInstanceOf_T_Boolean(byte *pData);

void SetDataFor_T_Null_Record(void *dest, void *src);
byte* MovePtrBySizeOf_T_Null_Record(byte *pData);
byte* CreateInstanceOf_T_Null_Record(void);
void DestroyInstanceOf_T_Null_Record(byte *pData);

void SetDataFor_int(void *dest, void *src);
byte* MovePtrBySizeOf_int(byte *pData);
byte* CreateInstanceOf_int(void);
void DestroyInstanceOf_int(byte *pData);


#endif
