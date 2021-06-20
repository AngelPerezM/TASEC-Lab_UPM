#ifndef __GETSET_H__
#define __GETSET_H__

#include "tasec_lab_b2space.h"

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

/* INTEGER */
asn1SccSint TC74s_All_Data__iDx_exist_validity_Get(TC74s_All_Data* root, int iDx);

/* INTEGER */
void TC74s_All_Data__iDx_exist_validity_Set(TC74s_All_Data* root, int iDx, asn1SccSint value);

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

/* INTEGER */
asn1SccSint PS_All_Data__exist_calib_Get(PS_All_Data* root);

/* INTEGER */
void PS_All_Data__exist_calib_Set(PS_All_Data* root, asn1SccSint value);

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

/* INTEGER */
asn1SccSint Heater_Data__exist_validity_Get(Heater_Data* root);

/* INTEGER */
void Heater_Data__exist_validity_Set(Heater_Data* root, asn1SccSint value);

/* ENUMERATED */
int Heater_Data__validity_Get(Heater_Data* root);

/* ENUMERATED */
void Heater_Data__validity_Set(Heater_Data* root, int value);

/* ENUMERATED */
int Content_Validity__Get(Content_Validity* root);

/* ENUMERATED */
void Content_Validity__Set(Content_Validity* root, int value);

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

/* INTEGER */
asn1SccSint OBSW_DP_Data__gps_exist_validity_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__gps_exist_validity_Set(OBSW_DP_Data* root, asn1SccSint value);

/* ENUMERATED */
int OBSW_DP_Data__gps_validity_Get(OBSW_DP_Data* root);

/* ENUMERATED */
void OBSW_DP_Data__gps_validity_Set(OBSW_DP_Data* root, int value);

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

/* REAL */
double OBSW_DP_Data__imu_timestamp_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__imu_timestamp_Set(OBSW_DP_Data* root, double value);

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

/* INTEGER */
asn1SccSint OBSW_DP_Data__tc74s_data_iDx_exist_validity_Get(OBSW_DP_Data* root, int iDx);

/* INTEGER */
void OBSW_DP_Data__tc74s_data_iDx_exist_validity_Set(OBSW_DP_Data* root, int iDx, asn1SccSint value);

/* ENUMERATED */
int OBSW_DP_Data__tc74s_data_iDx_validity_Get(OBSW_DP_Data* root, int iDx);

/* ENUMERATED */
void OBSW_DP_Data__tc74s_data_iDx_validity_Set(OBSW_DP_Data* root, int iDx, int value);

/* REAL */
double OBSW_DP_Data__tc74s_timestamp_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__tc74s_timestamp_Set(OBSW_DP_Data* root, double value);

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
double OBSW_DP_Data__pt1000s_timestamp_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__pt1000s_timestamp_Set(OBSW_DP_Data* root, double value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__exist_ps1_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__exist_ps1_Set(OBSW_DP_Data* root, asn1SccSint value);

/* Field ps1 selector */
OBSW_DP_Data_ps1* OBSW_DP_Data__ps1_Get(OBSW_DP_Data* root);

/* Field data selector */
PS_All_Data* OBSW_DP_Data__ps1_data_Get(OBSW_DP_Data* root);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_exist_calib_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps1_data_exist_calib_Set(OBSW_DP_Data* root, asn1SccSint value);

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
double OBSW_DP_Data__ps1_timestamp_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__ps1_timestamp_Set(OBSW_DP_Data* root, double value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__exist_ps2_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__exist_ps2_Set(OBSW_DP_Data* root, asn1SccSint value);

/* Field ps2 selector */
OBSW_DP_Data_ps2* OBSW_DP_Data__ps2_Get(OBSW_DP_Data* root);

/* Field data selector */
PS_All_Data* OBSW_DP_Data__ps2_data_Get(OBSW_DP_Data* root);

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_exist_calib_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__ps2_data_exist_calib_Set(OBSW_DP_Data* root, asn1SccSint value);

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
double OBSW_DP_Data__ps2_timestamp_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__ps2_timestamp_Set(OBSW_DP_Data* root, double value);

/* INTEGER */
asn1SccSint OBSW_DP_Data__exist_heater1_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__exist_heater1_Set(OBSW_DP_Data* root, asn1SccSint value);

/* Field heater1 selector */
OBSW_DP_Data_heater1* OBSW_DP_Data__heater1_Get(OBSW_DP_Data* root);

/* REAL */
double OBSW_DP_Data__heater1_data_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__heater1_data_Set(OBSW_DP_Data* root, double value);

/* REAL */
double OBSW_DP_Data__heater1_timestamp_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__heater1_timestamp_Set(OBSW_DP_Data* root, double value);

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

/* INTEGER */
asn1SccSint OBSW_DP_Data__heater2_data_exist_validity_Get(OBSW_DP_Data* root);

/* INTEGER */
void OBSW_DP_Data__heater2_data_exist_validity_Set(OBSW_DP_Data* root, asn1SccSint value);

/* ENUMERATED */
int OBSW_DP_Data__heater2_data_validity_Get(OBSW_DP_Data* root);

/* ENUMERATED */
void OBSW_DP_Data__heater2_data_validity_Set(OBSW_DP_Data* root, int value);

/* REAL */
double OBSW_DP_Data__heater2_timestamp_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__heater2_timestamp_Set(OBSW_DP_Data* root, double value);

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
double OBSW_DP_Data__anemometer_timestamp_Get(OBSW_DP_Data* root);

/* REAL */
void OBSW_DP_Data__anemometer_timestamp_Set(OBSW_DP_Data* root, double value);

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

void SetDataFor_Content_Validity(void *dest, void *src);
byte* MovePtrBySizeOf_Content_Validity(byte *pData);
byte* CreateInstanceOf_Content_Validity(void);
void DestroyInstanceOf_Content_Validity(byte *pData);

void SetDataFor_OBSW_DP_Data(void *dest, void *src);
byte* MovePtrBySizeOf_OBSW_DP_Data(byte *pData);
byte* CreateInstanceOf_OBSW_DP_Data(void);
void DestroyInstanceOf_OBSW_DP_Data(byte *pData);

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
