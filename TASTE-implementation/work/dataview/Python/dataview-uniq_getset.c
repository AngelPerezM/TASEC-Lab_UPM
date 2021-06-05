#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "dataview-uniq_getset.h"

size_t GetStreamCurrentLength(BitStream *pBitStrm) {
    return pBitStrm->currentByte + ((pBitStrm->currentBit+7)/8);
}

byte *GetBitstreamBuffer(BitStream *pBitStrm) {
    return pBitStrm->buf;
}

byte GetBufferByte(byte *p, size_t off) {
    assert(p);
    return p[off];
}

void SetBufferByte(byte *p, size_t off, byte b) {
    assert(p);
    p[off] = b;
}

void ResetStream(BitStream *pStrm) {
    assert(pStrm);
    assert(pStrm->count >= 0);
    pStrm->currentByte = 0;
    pStrm->currentBit = 0;
}

BitStream *CreateStream(size_t bufferSize) {
    BitStream *pBitStrm = malloc(sizeof(BitStream));
    assert(pBitStrm);
    pBitStrm->buf = malloc(bufferSize);
    assert(pBitStrm->buf);
    pBitStrm->count = bufferSize;
    memset(pBitStrm->buf, 0x0, bufferSize);
    ResetStream(pBitStrm);
    return pBitStrm;
}

void DestroyStream(BitStream *pBitStrm) {
    assert(pBitStrm);
    assert(pBitStrm->buf);
    free(pBitStrm->buf);
    free(pBitStrm);
}


/* INTEGER */
asn1SccSint T_Int16__Get(T_Int16* root)
{
    return (*root);
}

/* INTEGER */
void T_Int16__Set(T_Int16* root, asn1SccSint value)
{
    (*root) = value;
}

/* INTEGER */
asn1SccSint T_UInt16__Get(T_UInt16* root)
{
    return (*root);
}

/* INTEGER */
void T_UInt16__Set(T_UInt16* root, asn1SccSint value)
{
    (*root) = value;
}

/* INTEGER */
asn1SccSint T_UInt64__Get(T_UInt64* root)
{
    return (*root);
}

/* INTEGER */
void T_UInt64__Set(T_UInt64* root, asn1SccSint value)
{
    (*root) = value;
}

/* REAL */
double T_Float__Get(T_Float* root)
{
    return (*root);
}

/* REAL */
void T_Float__Set(T_Float* root, double value)
{
    (*root) = value;
}

/* REAL */
double T_Double__Get(T_Double* root)
{
    return (*root);
}

/* REAL */
void T_Double__Set(T_Double* root, double value)
{
    (*root) = value;
}

/* OCTETSTRING */
long File_Name__GetLength(File_Name* root)
{
    return 81;
}

/* OCTETSTRING */
void File_Name__SetLength(File_Name* root, long value)
{
    fprintf(stderr, "WARNING: setting length of fixed-length sequence\n");
}

/* OCTETSTRING_bytes */
byte File_Name__iDx_Get(File_Name* root, int iDx)
{
    return (*root).arr[iDx];
}

/* OCTETSTRING_bytes */
void File_Name__iDx_Set(File_Name* root, int iDx, byte value)
{
    (*root).arr[iDx] = value;
}

/* ENUMERATED */
int Content_Validity__Get(Content_Validity* root)
{
    return (*root);
}

/* ENUMERATED */
void Content_Validity__Set(Content_Validity* root, int value)
{
    (*root) = value;
}

/* INTEGER */
asn1SccSint SPI_ID__bus_Get(SPI_ID* root)
{
    return (*root).bus;
}

/* INTEGER */
void SPI_ID__bus_Set(SPI_ID* root, asn1SccSint value)
{
    (*root).bus = value;
}

/* INTEGER */
asn1SccSint SPI_ID__cs_Get(SPI_ID* root)
{
    return (*root).cs;
}

/* INTEGER */
void SPI_ID__cs_Set(SPI_ID* root, asn1SccSint value)
{
    (*root).cs = value;
}

/* INTEGER */
asn1SccSint I2C_ID__bus_Get(I2C_ID* root)
{
    return (*root).bus;
}

/* INTEGER */
void I2C_ID__bus_Set(I2C_ID* root, asn1SccSint value)
{
    (*root).bus = value;
}

/* INTEGER */
asn1SccSint I2C_ID__address_Get(I2C_ID* root)
{
    return (*root).address;
}

/* INTEGER */
void I2C_ID__address_Set(I2C_ID* root, asn1SccSint value)
{
    (*root).address = value;
}

/* ENUMERATED */
int GPS_PVT__mode_Get(GPS_PVT* root)
{
    return (*root).mode;
}

/* ENUMERATED */
void GPS_PVT__mode_Set(GPS_PVT* root, int value)
{
    (*root).mode = value;
}

/* REAL */
double GPS_PVT__date_and_time_Get(GPS_PVT* root)
{
    return (*root).date_and_time;
}

/* REAL */
void GPS_PVT__date_and_time_Set(GPS_PVT* root, double value)
{
    (*root).date_and_time = value;
}

/* REAL */
double GPS_PVT__ept_Get(GPS_PVT* root)
{
    return (*root).ept;
}

/* REAL */
void GPS_PVT__ept_Set(GPS_PVT* root, double value)
{
    (*root).ept = value;
}

/* REAL */
double GPS_PVT__latitude_Get(GPS_PVT* root)
{
    return (*root).latitude;
}

/* REAL */
void GPS_PVT__latitude_Set(GPS_PVT* root, double value)
{
    (*root).latitude = value;
}

/* REAL */
double GPS_PVT__epy_Get(GPS_PVT* root)
{
    return (*root).epy;
}

/* REAL */
void GPS_PVT__epy_Set(GPS_PVT* root, double value)
{
    (*root).epy = value;
}

/* REAL */
double GPS_PVT__longitude_Get(GPS_PVT* root)
{
    return (*root).longitude;
}

/* REAL */
void GPS_PVT__longitude_Set(GPS_PVT* root, double value)
{
    (*root).longitude = value;
}

/* REAL */
double GPS_PVT__epx_Get(GPS_PVT* root)
{
    return (*root).epx;
}

/* REAL */
void GPS_PVT__epx_Set(GPS_PVT* root, double value)
{
    (*root).epx = value;
}

/* REAL */
double GPS_PVT__altitude_Get(GPS_PVT* root)
{
    return (*root).altitude;
}

/* REAL */
void GPS_PVT__altitude_Set(GPS_PVT* root, double value)
{
    (*root).altitude = value;
}

/* REAL */
double GPS_PVT__epv_Get(GPS_PVT* root)
{
    return (*root).epv;
}

/* REAL */
void GPS_PVT__epv_Set(GPS_PVT* root, double value)
{
    (*root).epv = value;
}

/* REAL */
double GPS_PVT__course_Get(GPS_PVT* root)
{
    return (*root).course;
}

/* REAL */
void GPS_PVT__course_Set(GPS_PVT* root, double value)
{
    (*root).course = value;
}

/* REAL */
double GPS_PVT__epd_Get(GPS_PVT* root)
{
    return (*root).epd;
}

/* REAL */
void GPS_PVT__epd_Set(GPS_PVT* root, double value)
{
    (*root).epd = value;
}

/* REAL */
double GPS_PVT__speed_Get(GPS_PVT* root)
{
    return (*root).speed;
}

/* REAL */
void GPS_PVT__speed_Set(GPS_PVT* root, double value)
{
    (*root).speed = value;
}

/* REAL */
double GPS_PVT__eps_Get(GPS_PVT* root)
{
    return (*root).eps;
}

/* REAL */
void GPS_PVT__eps_Set(GPS_PVT* root, double value)
{
    (*root).eps = value;
}

/* REAL */
double GPS_PVT__climb_Get(GPS_PVT* root)
{
    return (*root).climb;
}

/* REAL */
void GPS_PVT__climb_Set(GPS_PVT* root, double value)
{
    (*root).climb = value;
}

/* REAL */
double GPS_PVT__epc_Get(GPS_PVT* root)
{
    return (*root).epc;
}

/* REAL */
void GPS_PVT__epc_Set(GPS_PVT* root, double value)
{
    (*root).epc = value;
}

/* INTEGER */
asn1SccSint MGT_Raw_Data__x_axis_Get(MGT_Raw_Data* root)
{
    return (*root).x_axis;
}

/* INTEGER */
void MGT_Raw_Data__x_axis_Set(MGT_Raw_Data* root, asn1SccSint value)
{
    (*root).x_axis = value;
}

/* INTEGER */
asn1SccSint MGT_Raw_Data__y_axis_Get(MGT_Raw_Data* root)
{
    return (*root).y_axis;
}

/* INTEGER */
void MGT_Raw_Data__y_axis_Set(MGT_Raw_Data* root, asn1SccSint value)
{
    (*root).y_axis = value;
}

/* INTEGER */
asn1SccSint MGT_Raw_Data__z_axis_Get(MGT_Raw_Data* root)
{
    return (*root).z_axis;
}

/* INTEGER */
void MGT_Raw_Data__z_axis_Set(MGT_Raw_Data* root, asn1SccSint value)
{
    (*root).z_axis = value;
}

/* REAL */
double MGT_MilliGauss_Data__x_axis_Get(MGT_MilliGauss_Data* root)
{
    return (*root).x_axis;
}

/* REAL */
void MGT_MilliGauss_Data__x_axis_Set(MGT_MilliGauss_Data* root, double value)
{
    (*root).x_axis = value;
}

/* REAL */
double MGT_MilliGauss_Data__y_axis_Get(MGT_MilliGauss_Data* root)
{
    return (*root).y_axis;
}

/* REAL */
void MGT_MilliGauss_Data__y_axis_Set(MGT_MilliGauss_Data* root, double value)
{
    (*root).y_axis = value;
}

/* REAL */
double MGT_MilliGauss_Data__z_axis_Get(MGT_MilliGauss_Data* root)
{
    return (*root).z_axis;
}

/* REAL */
void MGT_MilliGauss_Data__z_axis_Set(MGT_MilliGauss_Data* root, double value)
{
    (*root).z_axis = value;
}

/* INTEGER */
asn1SccSint ACC_Raw_Data__x_axis_Get(ACC_Raw_Data* root)
{
    return (*root).x_axis;
}

/* INTEGER */
void ACC_Raw_Data__x_axis_Set(ACC_Raw_Data* root, asn1SccSint value)
{
    (*root).x_axis = value;
}

/* INTEGER */
asn1SccSint ACC_Raw_Data__y_axis_Get(ACC_Raw_Data* root)
{
    return (*root).y_axis;
}

/* INTEGER */
void ACC_Raw_Data__y_axis_Set(ACC_Raw_Data* root, asn1SccSint value)
{
    (*root).y_axis = value;
}

/* INTEGER */
asn1SccSint ACC_Raw_Data__z_axis_Get(ACC_Raw_Data* root)
{
    return (*root).z_axis;
}

/* INTEGER */
void ACC_Raw_Data__z_axis_Set(ACC_Raw_Data* root, asn1SccSint value)
{
    (*root).z_axis = value;
}

/* REAL */
double ACC_MilliG_Data__x_axis_Get(ACC_MilliG_Data* root)
{
    return (*root).x_axis;
}

/* REAL */
void ACC_MilliG_Data__x_axis_Set(ACC_MilliG_Data* root, double value)
{
    (*root).x_axis = value;
}

/* REAL */
double ACC_MilliG_Data__y_axis_Get(ACC_MilliG_Data* root)
{
    return (*root).y_axis;
}

/* REAL */
void ACC_MilliG_Data__y_axis_Set(ACC_MilliG_Data* root, double value)
{
    (*root).y_axis = value;
}

/* REAL */
double ACC_MilliG_Data__z_axis_Get(ACC_MilliG_Data* root)
{
    return (*root).z_axis;
}

/* REAL */
void ACC_MilliG_Data__z_axis_Set(ACC_MilliG_Data* root, double value)
{
    (*root).z_axis = value;
}

/* INTEGER */
asn1SccSint GYRO_Raw_Data__x_axis_Get(GYRO_Raw_Data* root)
{
    return (*root).x_axis;
}

/* INTEGER */
void GYRO_Raw_Data__x_axis_Set(GYRO_Raw_Data* root, asn1SccSint value)
{
    (*root).x_axis = value;
}

/* INTEGER */
asn1SccSint GYRO_Raw_Data__y_axis_Get(GYRO_Raw_Data* root)
{
    return (*root).y_axis;
}

/* INTEGER */
void GYRO_Raw_Data__y_axis_Set(GYRO_Raw_Data* root, asn1SccSint value)
{
    (*root).y_axis = value;
}

/* INTEGER */
asn1SccSint GYRO_Raw_Data__z_axis_Get(GYRO_Raw_Data* root)
{
    return (*root).z_axis;
}

/* INTEGER */
void GYRO_Raw_Data__z_axis_Set(GYRO_Raw_Data* root, asn1SccSint value)
{
    (*root).z_axis = value;
}

/* REAL */
double GYRO_MilliDPS_Data__x_axis_Get(GYRO_MilliDPS_Data* root)
{
    return (*root).x_axis;
}

/* REAL */
void GYRO_MilliDPS_Data__x_axis_Set(GYRO_MilliDPS_Data* root, double value)
{
    (*root).x_axis = value;
}

/* REAL */
double GYRO_MilliDPS_Data__y_axis_Get(GYRO_MilliDPS_Data* root)
{
    return (*root).y_axis;
}

/* REAL */
void GYRO_MilliDPS_Data__y_axis_Set(GYRO_MilliDPS_Data* root, double value)
{
    (*root).y_axis = value;
}

/* REAL */
double GYRO_MilliDPS_Data__z_axis_Get(GYRO_MilliDPS_Data* root)
{
    return (*root).z_axis;
}

/* REAL */
void GYRO_MilliDPS_Data__z_axis_Set(GYRO_MilliDPS_Data* root, double value)
{
    (*root).z_axis = value;
}

/* Field mgt_raw selector */
MGT_Raw_Data* IMU_All_Data__mgt_raw_Get(IMU_All_Data* root)
{
    return &(*root).mgt_raw;
}

/* INTEGER */
asn1SccSint IMU_All_Data__mgt_raw_x_axis_Get(IMU_All_Data* root)
{
    return (*root).mgt_raw.x_axis;
}

/* INTEGER */
void IMU_All_Data__mgt_raw_x_axis_Set(IMU_All_Data* root, asn1SccSint value)
{
    (*root).mgt_raw.x_axis = value;
}

/* INTEGER */
asn1SccSint IMU_All_Data__mgt_raw_y_axis_Get(IMU_All_Data* root)
{
    return (*root).mgt_raw.y_axis;
}

/* INTEGER */
void IMU_All_Data__mgt_raw_y_axis_Set(IMU_All_Data* root, asn1SccSint value)
{
    (*root).mgt_raw.y_axis = value;
}

/* INTEGER */
asn1SccSint IMU_All_Data__mgt_raw_z_axis_Get(IMU_All_Data* root)
{
    return (*root).mgt_raw.z_axis;
}

/* INTEGER */
void IMU_All_Data__mgt_raw_z_axis_Set(IMU_All_Data* root, asn1SccSint value)
{
    (*root).mgt_raw.z_axis = value;
}

/* Field mgt_mgauss selector */
MGT_MilliGauss_Data* IMU_All_Data__mgt_mgauss_Get(IMU_All_Data* root)
{
    return &(*root).mgt_mgauss;
}

/* REAL */
double IMU_All_Data__mgt_mgauss_x_axis_Get(IMU_All_Data* root)
{
    return (*root).mgt_mgauss.x_axis;
}

/* REAL */
void IMU_All_Data__mgt_mgauss_x_axis_Set(IMU_All_Data* root, double value)
{
    (*root).mgt_mgauss.x_axis = value;
}

/* REAL */
double IMU_All_Data__mgt_mgauss_y_axis_Get(IMU_All_Data* root)
{
    return (*root).mgt_mgauss.y_axis;
}

/* REAL */
void IMU_All_Data__mgt_mgauss_y_axis_Set(IMU_All_Data* root, double value)
{
    (*root).mgt_mgauss.y_axis = value;
}

/* REAL */
double IMU_All_Data__mgt_mgauss_z_axis_Get(IMU_All_Data* root)
{
    return (*root).mgt_mgauss.z_axis;
}

/* REAL */
void IMU_All_Data__mgt_mgauss_z_axis_Set(IMU_All_Data* root, double value)
{
    (*root).mgt_mgauss.z_axis = value;
}

/* Field accel_raw selector */
ACC_Raw_Data* IMU_All_Data__accel_raw_Get(IMU_All_Data* root)
{
    return &(*root).accel_raw;
}

/* INTEGER */
asn1SccSint IMU_All_Data__accel_raw_x_axis_Get(IMU_All_Data* root)
{
    return (*root).accel_raw.x_axis;
}

/* INTEGER */
void IMU_All_Data__accel_raw_x_axis_Set(IMU_All_Data* root, asn1SccSint value)
{
    (*root).accel_raw.x_axis = value;
}

/* INTEGER */
asn1SccSint IMU_All_Data__accel_raw_y_axis_Get(IMU_All_Data* root)
{
    return (*root).accel_raw.y_axis;
}

/* INTEGER */
void IMU_All_Data__accel_raw_y_axis_Set(IMU_All_Data* root, asn1SccSint value)
{
    (*root).accel_raw.y_axis = value;
}

/* INTEGER */
asn1SccSint IMU_All_Data__accel_raw_z_axis_Get(IMU_All_Data* root)
{
    return (*root).accel_raw.z_axis;
}

/* INTEGER */
void IMU_All_Data__accel_raw_z_axis_Set(IMU_All_Data* root, asn1SccSint value)
{
    (*root).accel_raw.z_axis = value;
}

/* Field accel_mg selector */
ACC_MilliG_Data* IMU_All_Data__accel_mg_Get(IMU_All_Data* root)
{
    return &(*root).accel_mg;
}

/* REAL */
double IMU_All_Data__accel_mg_x_axis_Get(IMU_All_Data* root)
{
    return (*root).accel_mg.x_axis;
}

/* REAL */
void IMU_All_Data__accel_mg_x_axis_Set(IMU_All_Data* root, double value)
{
    (*root).accel_mg.x_axis = value;
}

/* REAL */
double IMU_All_Data__accel_mg_y_axis_Get(IMU_All_Data* root)
{
    return (*root).accel_mg.y_axis;
}

/* REAL */
void IMU_All_Data__accel_mg_y_axis_Set(IMU_All_Data* root, double value)
{
    (*root).accel_mg.y_axis = value;
}

/* REAL */
double IMU_All_Data__accel_mg_z_axis_Get(IMU_All_Data* root)
{
    return (*root).accel_mg.z_axis;
}

/* REAL */
void IMU_All_Data__accel_mg_z_axis_Set(IMU_All_Data* root, double value)
{
    (*root).accel_mg.z_axis = value;
}

/* Field gyro_raw selector */
GYRO_Raw_Data* IMU_All_Data__gyro_raw_Get(IMU_All_Data* root)
{
    return &(*root).gyro_raw;
}

/* INTEGER */
asn1SccSint IMU_All_Data__gyro_raw_x_axis_Get(IMU_All_Data* root)
{
    return (*root).gyro_raw.x_axis;
}

/* INTEGER */
void IMU_All_Data__gyro_raw_x_axis_Set(IMU_All_Data* root, asn1SccSint value)
{
    (*root).gyro_raw.x_axis = value;
}

/* INTEGER */
asn1SccSint IMU_All_Data__gyro_raw_y_axis_Get(IMU_All_Data* root)
{
    return (*root).gyro_raw.y_axis;
}

/* INTEGER */
void IMU_All_Data__gyro_raw_y_axis_Set(IMU_All_Data* root, asn1SccSint value)
{
    (*root).gyro_raw.y_axis = value;
}

/* INTEGER */
asn1SccSint IMU_All_Data__gyro_raw_z_axis_Get(IMU_All_Data* root)
{
    return (*root).gyro_raw.z_axis;
}

/* INTEGER */
void IMU_All_Data__gyro_raw_z_axis_Set(IMU_All_Data* root, asn1SccSint value)
{
    (*root).gyro_raw.z_axis = value;
}

/* Field gyro_mdps selector */
GYRO_MilliDPS_Data* IMU_All_Data__gyro_mdps_Get(IMU_All_Data* root)
{
    return &(*root).gyro_mdps;
}

/* REAL */
double IMU_All_Data__gyro_mdps_x_axis_Get(IMU_All_Data* root)
{
    return (*root).gyro_mdps.x_axis;
}

/* REAL */
void IMU_All_Data__gyro_mdps_x_axis_Set(IMU_All_Data* root, double value)
{
    (*root).gyro_mdps.x_axis = value;
}

/* REAL */
double IMU_All_Data__gyro_mdps_y_axis_Get(IMU_All_Data* root)
{
    return (*root).gyro_mdps.y_axis;
}

/* REAL */
void IMU_All_Data__gyro_mdps_y_axis_Set(IMU_All_Data* root, double value)
{
    (*root).gyro_mdps.y_axis = value;
}

/* REAL */
double IMU_All_Data__gyro_mdps_z_axis_Get(IMU_All_Data* root)
{
    return (*root).gyro_mdps.z_axis;
}

/* REAL */
void IMU_All_Data__gyro_mdps_z_axis_Set(IMU_All_Data* root, double value)
{
    (*root).gyro_mdps.z_axis = value;
}

/* INTEGER */
asn1SccSint IMU_All_Data__temp_raw_Get(IMU_All_Data* root)
{
    return (*root).temp_raw;
}

/* INTEGER */
void IMU_All_Data__temp_raw_Set(IMU_All_Data* root, asn1SccSint value)
{
    (*root).temp_raw = value;
}

/* REAL */
double IMU_All_Data__temp_celsius_Get(IMU_All_Data* root)
{
    return (*root).temp_celsius;
}

/* REAL */
void IMU_All_Data__temp_celsius_Set(IMU_All_Data* root, double value)
{
    (*root).temp_celsius = value;
}

/* ENUMERATED */
int IMU_All_Data__mgt_valid_Get(IMU_All_Data* root)
{
    return (*root).mgt_valid;
}

/* ENUMERATED */
void IMU_All_Data__mgt_valid_Set(IMU_All_Data* root, int value)
{
    (*root).mgt_valid = value;
}

/* ENUMERATED */
int IMU_All_Data__acc_valid_Get(IMU_All_Data* root)
{
    return (*root).acc_valid;
}

/* ENUMERATED */
void IMU_All_Data__acc_valid_Set(IMU_All_Data* root, int value)
{
    (*root).acc_valid = value;
}

/* ENUMERATED */
int IMU_All_Data__gyro_valid_Get(IMU_All_Data* root)
{
    return (*root).gyro_valid;
}

/* ENUMERATED */
void IMU_All_Data__gyro_valid_Set(IMU_All_Data* root, int value)
{
    (*root).gyro_valid = value;
}

/* ENUMERATED */
int IMU_All_Data__temp_valid_Get(IMU_All_Data* root)
{
    return (*root).temp_valid;
}

/* ENUMERATED */
void IMU_All_Data__temp_valid_Set(IMU_All_Data* root, int value)
{
    (*root).temp_valid = value;
}

/* SEQUENCEOF/SETOF */
long TC74s_I2CBuses__GetLength(TC74s_I2CBuses* root)
{
    return 5;
}

/* SEQUENCEOF/SETOF */
void TC74s_I2CBuses__SetLength(TC74s_I2CBuses* root, long value)
{
    fprintf(stderr, "WARNING: setting length of fixed-length sequence\n");
}

/* INTEGER */
asn1SccSint TC74s_I2CBuses__iDx_Get(TC74s_I2CBuses* root, int iDx)
{
    return (*root).arr[iDx];
}

/* INTEGER */
void TC74s_I2CBuses__iDx_Set(TC74s_I2CBuses* root, int iDx, asn1SccSint value)
{
    (*root).arr[iDx] = value;
}

/* SEQUENCEOF/SETOF */
long TC74s_All_Data__GetLength(TC74s_All_Data* root)
{
    return 5;
}

/* SEQUENCEOF/SETOF */
void TC74s_All_Data__SetLength(TC74s_All_Data* root, long value)
{
    fprintf(stderr, "WARNING: setting length of fixed-length sequence\n");
}

/* REAL */
double TC74s_All_Data__iDx_temperature_Get(TC74s_All_Data* root, int iDx)
{
    return (*root).arr[iDx].temperature;
}

/* REAL */
void TC74s_All_Data__iDx_temperature_Set(TC74s_All_Data* root, int iDx, double value)
{
    (*root).arr[iDx].temperature = value;
}

/* ENUMERATED */
int TC74s_All_Data__iDx_validity_Get(TC74s_All_Data* root, int iDx)
{
    return (*root).arr[iDx].validity;
}

/* ENUMERATED */
void TC74s_All_Data__iDx_validity_Set(TC74s_All_Data* root, int iDx, int value)
{
    (*root).arr[iDx].validity = value;
}

/* SEQUENCEOF/SETOF */
long PT1000s_Channels__GetLength(PT1000s_Channels* root)
{
    return 7;
}

/* SEQUENCEOF/SETOF */
void PT1000s_Channels__SetLength(PT1000s_Channels* root, long value)
{
    fprintf(stderr, "WARNING: setting length of fixed-length sequence\n");
}

/* INTEGER */
asn1SccSint PT1000s_Channels__iDx_Get(PT1000s_Channels* root, int iDx)
{
    return (*root).arr[iDx];
}

/* INTEGER */
void PT1000s_Channels__iDx_Set(PT1000s_Channels* root, int iDx, asn1SccSint value)
{
    (*root).arr[iDx] = value;
}

/* SEQUENCEOF/SETOF */
long PT1000s_Raw_Data__GetLength(PT1000s_Raw_Data* root)
{
    return 7;
}

/* SEQUENCEOF/SETOF */
void PT1000s_Raw_Data__SetLength(PT1000s_Raw_Data* root, long value)
{
    fprintf(stderr, "WARNING: setting length of fixed-length sequence\n");
}

/* REAL */
double PT1000s_Raw_Data__iDx_vcc_volts_Get(PT1000s_Raw_Data* root, int iDx)
{
    return (*root).arr[iDx].vcc_volts;
}

/* REAL */
void PT1000s_Raw_Data__iDx_vcc_volts_Set(PT1000s_Raw_Data* root, int iDx, double value)
{
    (*root).arr[iDx].vcc_volts = value;
}

/* REAL */
double PT1000s_Raw_Data__iDx_pt1000_Get(PT1000s_Raw_Data* root, int iDx)
{
    return (*root).arr[iDx].pt1000;
}

/* REAL */
void PT1000s_Raw_Data__iDx_pt1000_Set(PT1000s_Raw_Data* root, int iDx, double value)
{
    (*root).arr[iDx].pt1000 = value;
}

/* SEQUENCEOF/SETOF */
long PT1000s_Celsius_Data__GetLength(PT1000s_Celsius_Data* root)
{
    return 7;
}

/* SEQUENCEOF/SETOF */
void PT1000s_Celsius_Data__SetLength(PT1000s_Celsius_Data* root, long value)
{
    fprintf(stderr, "WARNING: setting length of fixed-length sequence\n");
}

/* REAL */
double PT1000s_Celsius_Data__iDx_Get(PT1000s_Celsius_Data* root, int iDx)
{
    return (*root).arr[iDx];
}

/* REAL */
void PT1000s_Celsius_Data__iDx_Set(PT1000s_Celsius_Data* root, int iDx, double value)
{
    (*root).arr[iDx] = value;
}

/* Field raw selector */
PT1000s_Raw_Data PT1000s_All_Data__raw_Get(PT1000s_All_Data* root)
{
    return (*root).raw;
}

/* Field raw selector */
void PT1000s_All_Data__raw_Set(PT1000s_All_Data* root, PT1000s_Raw_Data value)
{
    (*root).raw = value;
}

/* SEQUENCEOF/SETOF */
long PT1000s_All_Data__raw_GetLength(PT1000s_All_Data* root)
{
    return 7;
}

/* SEQUENCEOF/SETOF */
void PT1000s_All_Data__raw_SetLength(PT1000s_All_Data* root, long value)
{
    fprintf(stderr, "WARNING: setting length of fixed-length sequence\n");
}

/* REAL */
double PT1000s_All_Data__raw_iDx_vcc_volts_Get(PT1000s_All_Data* root, int iDx)
{
    return (*root).raw.arr[iDx].vcc_volts;
}

/* REAL */
void PT1000s_All_Data__raw_iDx_vcc_volts_Set(PT1000s_All_Data* root, int iDx, double value)
{
    (*root).raw.arr[iDx].vcc_volts = value;
}

/* REAL */
double PT1000s_All_Data__raw_iDx_pt1000_Get(PT1000s_All_Data* root, int iDx)
{
    return (*root).raw.arr[iDx].pt1000;
}

/* REAL */
void PT1000s_All_Data__raw_iDx_pt1000_Set(PT1000s_All_Data* root, int iDx, double value)
{
    (*root).raw.arr[iDx].pt1000 = value;
}

/* Field celsius selector */
PT1000s_Celsius_Data PT1000s_All_Data__celsius_Get(PT1000s_All_Data* root)
{
    return (*root).celsius;
}

/* Field celsius selector */
void PT1000s_All_Data__celsius_Set(PT1000s_All_Data* root, PT1000s_Celsius_Data value)
{
    (*root).celsius = value;
}

/* SEQUENCEOF/SETOF */
long PT1000s_All_Data__celsius_GetLength(PT1000s_All_Data* root)
{
    return 7;
}

/* SEQUENCEOF/SETOF */
void PT1000s_All_Data__celsius_SetLength(PT1000s_All_Data* root, long value)
{
    fprintf(stderr, "WARNING: setting length of fixed-length sequence\n");
}

/* REAL */
double PT1000s_All_Data__celsius_iDx_Get(PT1000s_All_Data* root, int iDx)
{
    return (*root).celsius.arr[iDx];
}

/* REAL */
void PT1000s_All_Data__celsius_iDx_Set(PT1000s_All_Data* root, int iDx, double value)
{
    (*root).celsius.arr[iDx] = value;
}

/* Field validity selector */
PT1000s_All_Data_validity PT1000s_All_Data__validity_Get(PT1000s_All_Data* root)
{
    return (*root).validity;
}

/* Field validity selector */
void PT1000s_All_Data__validity_Set(PT1000s_All_Data* root, PT1000s_All_Data_validity value)
{
    (*root).validity = value;
}

/* SEQUENCEOF/SETOF */
long PT1000s_All_Data__validity_GetLength(PT1000s_All_Data* root)
{
    return 7;
}

/* SEQUENCEOF/SETOF */
void PT1000s_All_Data__validity_SetLength(PT1000s_All_Data* root, long value)
{
    fprintf(stderr, "WARNING: setting length of fixed-length sequence\n");
}

/* ENUMERATED */
int PT1000s_All_Data__validity_iDx_Get(PT1000s_All_Data* root, int iDx)
{
    return (*root).validity.arr[iDx];
}

/* ENUMERATED */
void PT1000s_All_Data__validity_iDx_Set(PT1000s_All_Data* root, int iDx, int value)
{
    (*root).validity.arr[iDx] = value;
}

/* INTEGER */
asn1SccSint PS_Calibration_Data__c1_Get(PS_Calibration_Data* root)
{
    return (*root).c1;
}

/* INTEGER */
void PS_Calibration_Data__c1_Set(PS_Calibration_Data* root, asn1SccSint value)
{
    (*root).c1 = value;
}

/* INTEGER */
asn1SccSint PS_Calibration_Data__c2_Get(PS_Calibration_Data* root)
{
    return (*root).c2;
}

/* INTEGER */
void PS_Calibration_Data__c2_Set(PS_Calibration_Data* root, asn1SccSint value)
{
    (*root).c2 = value;
}

/* INTEGER */
asn1SccSint PS_Calibration_Data__c3_Get(PS_Calibration_Data* root)
{
    return (*root).c3;
}

/* INTEGER */
void PS_Calibration_Data__c3_Set(PS_Calibration_Data* root, asn1SccSint value)
{
    (*root).c3 = value;
}

/* INTEGER */
asn1SccSint PS_Calibration_Data__c4_Get(PS_Calibration_Data* root)
{
    return (*root).c4;
}

/* INTEGER */
void PS_Calibration_Data__c4_Set(PS_Calibration_Data* root, asn1SccSint value)
{
    (*root).c4 = value;
}

/* INTEGER */
asn1SccSint PS_Calibration_Data__c5_Get(PS_Calibration_Data* root)
{
    return (*root).c5;
}

/* INTEGER */
void PS_Calibration_Data__c5_Set(PS_Calibration_Data* root, asn1SccSint value)
{
    (*root).c5 = value;
}

/* INTEGER */
asn1SccSint PS_Calibration_Data__c6_Get(PS_Calibration_Data* root)
{
    return (*root).c6;
}

/* INTEGER */
void PS_Calibration_Data__c6_Set(PS_Calibration_Data* root, asn1SccSint value)
{
    (*root).c6 = value;
}

/* REAL */
double PS_Calibration_Data__sens_t1_Get(PS_Calibration_Data* root)
{
    return (*root).sens_t1;
}

/* REAL */
void PS_Calibration_Data__sens_t1_Set(PS_Calibration_Data* root, double value)
{
    (*root).sens_t1 = value;
}

/* REAL */
double PS_Calibration_Data__off_t1_Get(PS_Calibration_Data* root)
{
    return (*root).off_t1;
}

/* REAL */
void PS_Calibration_Data__off_t1_Set(PS_Calibration_Data* root, double value)
{
    (*root).off_t1 = value;
}

/* REAL */
double PS_Calibration_Data__tcs_Get(PS_Calibration_Data* root)
{
    return (*root).tcs;
}

/* REAL */
void PS_Calibration_Data__tcs_Set(PS_Calibration_Data* root, double value)
{
    (*root).tcs = value;
}

/* REAL */
double PS_Calibration_Data__tco_Get(PS_Calibration_Data* root)
{
    return (*root).tco;
}

/* REAL */
void PS_Calibration_Data__tco_Set(PS_Calibration_Data* root, double value)
{
    (*root).tco = value;
}

/* REAL */
double PS_Calibration_Data__tref_Get(PS_Calibration_Data* root)
{
    return (*root).tref;
}

/* REAL */
void PS_Calibration_Data__tref_Set(PS_Calibration_Data* root, double value)
{
    (*root).tref = value;
}

/* REAL */
double PS_Calibration_Data__temp_sens_Get(PS_Calibration_Data* root)
{
    return (*root).temp_sens;
}

/* REAL */
void PS_Calibration_Data__temp_sens_Set(PS_Calibration_Data* root, double value)
{
    (*root).temp_sens = value;
}

/* INTEGER */
asn1SccSint PS_Raw_Data__d1_Get(PS_Raw_Data* root)
{
    return (*root).d1;
}

/* INTEGER */
void PS_Raw_Data__d1_Set(PS_Raw_Data* root, asn1SccSint value)
{
    (*root).d1 = value;
}

/* INTEGER */
asn1SccSint PS_Raw_Data__d2_Get(PS_Raw_Data* root)
{
    return (*root).d2;
}

/* INTEGER */
void PS_Raw_Data__d2_Set(PS_Raw_Data* root, asn1SccSint value)
{
    (*root).d2 = value;
}

/* INTEGER */
asn1SccSint PS_Processed_Data__pressure_Get(PS_Processed_Data* root)
{
    return (*root).pressure;
}

/* INTEGER */
void PS_Processed_Data__pressure_Set(PS_Processed_Data* root, asn1SccSint value)
{
    (*root).pressure = value;
}

/* INTEGER */
asn1SccSint PS_Processed_Data__temp_Get(PS_Processed_Data* root)
{
    return (*root).temp;
}

/* INTEGER */
void PS_Processed_Data__temp_Set(PS_Processed_Data* root, asn1SccSint value)
{
    (*root).temp = value;
}

/* INTEGER */
asn1SccSint PS_All_Data__exist_calib_Get(PS_All_Data* root)
{
    return (*root).exist.calib;
}

/* INTEGER */
void PS_All_Data__exist_calib_Set(PS_All_Data* root, asn1SccSint value)
{
    (*root).exist.calib = value;
}

/* Field calib selector */
PS_Calibration_Data* PS_All_Data__calib_Get(PS_All_Data* root)
{
    return &(*root).calib;
}

/* INTEGER */
asn1SccSint PS_All_Data__calib_c1_Get(PS_All_Data* root)
{
    return (*root).calib.c1;
}

/* INTEGER */
void PS_All_Data__calib_c1_Set(PS_All_Data* root, asn1SccSint value)
{
    (*root).calib.c1 = value;
}

/* INTEGER */
asn1SccSint PS_All_Data__calib_c2_Get(PS_All_Data* root)
{
    return (*root).calib.c2;
}

/* INTEGER */
void PS_All_Data__calib_c2_Set(PS_All_Data* root, asn1SccSint value)
{
    (*root).calib.c2 = value;
}

/* INTEGER */
asn1SccSint PS_All_Data__calib_c3_Get(PS_All_Data* root)
{
    return (*root).calib.c3;
}

/* INTEGER */
void PS_All_Data__calib_c3_Set(PS_All_Data* root, asn1SccSint value)
{
    (*root).calib.c3 = value;
}

/* INTEGER */
asn1SccSint PS_All_Data__calib_c4_Get(PS_All_Data* root)
{
    return (*root).calib.c4;
}

/* INTEGER */
void PS_All_Data__calib_c4_Set(PS_All_Data* root, asn1SccSint value)
{
    (*root).calib.c4 = value;
}

/* INTEGER */
asn1SccSint PS_All_Data__calib_c5_Get(PS_All_Data* root)
{
    return (*root).calib.c5;
}

/* INTEGER */
void PS_All_Data__calib_c5_Set(PS_All_Data* root, asn1SccSint value)
{
    (*root).calib.c5 = value;
}

/* INTEGER */
asn1SccSint PS_All_Data__calib_c6_Get(PS_All_Data* root)
{
    return (*root).calib.c6;
}

/* INTEGER */
void PS_All_Data__calib_c6_Set(PS_All_Data* root, asn1SccSint value)
{
    (*root).calib.c6 = value;
}

/* REAL */
double PS_All_Data__calib_sens_t1_Get(PS_All_Data* root)
{
    return (*root).calib.sens_t1;
}

/* REAL */
void PS_All_Data__calib_sens_t1_Set(PS_All_Data* root, double value)
{
    (*root).calib.sens_t1 = value;
}

/* REAL */
double PS_All_Data__calib_off_t1_Get(PS_All_Data* root)
{
    return (*root).calib.off_t1;
}

/* REAL */
void PS_All_Data__calib_off_t1_Set(PS_All_Data* root, double value)
{
    (*root).calib.off_t1 = value;
}

/* REAL */
double PS_All_Data__calib_tcs_Get(PS_All_Data* root)
{
    return (*root).calib.tcs;
}

/* REAL */
void PS_All_Data__calib_tcs_Set(PS_All_Data* root, double value)
{
    (*root).calib.tcs = value;
}

/* REAL */
double PS_All_Data__calib_tco_Get(PS_All_Data* root)
{
    return (*root).calib.tco;
}

/* REAL */
void PS_All_Data__calib_tco_Set(PS_All_Data* root, double value)
{
    (*root).calib.tco = value;
}

/* REAL */
double PS_All_Data__calib_tref_Get(PS_All_Data* root)
{
    return (*root).calib.tref;
}

/* REAL */
void PS_All_Data__calib_tref_Set(PS_All_Data* root, double value)
{
    (*root).calib.tref = value;
}

/* REAL */
double PS_All_Data__calib_temp_sens_Get(PS_All_Data* root)
{
    return (*root).calib.temp_sens;
}

/* REAL */
void PS_All_Data__calib_temp_sens_Set(PS_All_Data* root, double value)
{
    (*root).calib.temp_sens = value;
}

/* Field raw selector */
PS_Raw_Data* PS_All_Data__raw_Get(PS_All_Data* root)
{
    return &(*root).raw;
}

/* INTEGER */
asn1SccSint PS_All_Data__raw_d1_Get(PS_All_Data* root)
{
    return (*root).raw.d1;
}

/* INTEGER */
void PS_All_Data__raw_d1_Set(PS_All_Data* root, asn1SccSint value)
{
    (*root).raw.d1 = value;
}

/* INTEGER */
asn1SccSint PS_All_Data__raw_d2_Get(PS_All_Data* root)
{
    return (*root).raw.d2;
}

/* INTEGER */
void PS_All_Data__raw_d2_Set(PS_All_Data* root, asn1SccSint value)
{
    (*root).raw.d2 = value;
}

/* Field processed selector */
PS_Processed_Data* PS_All_Data__processed_Get(PS_All_Data* root)
{
    return &(*root).processed;
}

/* INTEGER */
asn1SccSint PS_All_Data__processed_pressure_Get(PS_All_Data* root)
{
    return (*root).processed.pressure;
}

/* INTEGER */
void PS_All_Data__processed_pressure_Set(PS_All_Data* root, asn1SccSint value)
{
    (*root).processed.pressure = value;
}

/* INTEGER */
asn1SccSint PS_All_Data__processed_temp_Get(PS_All_Data* root)
{
    return (*root).processed.temp;
}

/* INTEGER */
void PS_All_Data__processed_temp_Set(PS_All_Data* root, asn1SccSint value)
{
    (*root).processed.temp = value;
}

/* ENUMERATED */
int PS_All_Data__validity_Get(PS_All_Data* root)
{
    return (*root).validity;
}

/* ENUMERATED */
void PS_All_Data__validity_Set(PS_All_Data* root, int value)
{
    (*root).validity = value;
}

/* REAL */
double Heater_Data__power_watts_Get(Heater_Data* root)
{
    return (*root).power_watts;
}

/* REAL */
void Heater_Data__power_watts_Set(Heater_Data* root, double value)
{
    (*root).power_watts = value;
}

/* ENUMERATED */
int Heater_Data__validity_Get(Heater_Data* root)
{
    return (*root).validity;
}

/* ENUMERATED */
void Heater_Data__validity_Set(Heater_Data* root, int value)
{
    (*root).validity = value;
}

/* ENUMERATED */
int Heater_On_Off__Get(Heater_On_Off* root)
{
    return (*root);
}

/* ENUMERATED */
void Heater_On_Off__Set(Heater_On_Off* root, int value)
{
    (*root) = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__exist_gps_Get(OBSW_DP_Data* root)
{
    return (*root).exist.gps;
}

/* INTEGER */
void OBSW_DP_Data__exist_gps_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).exist.gps = value;
}

/* Field gps selector */
OBSW_DP_Data_gps* OBSW_DP_Data__gps_Get(OBSW_DP_Data* root)
{
    return &(*root).gps;
}

/* Field data selector */
GPS_PVT* OBSW_DP_Data__gps_data_Get(OBSW_DP_Data* root)
{
    return &(*root).gps.data;
}

/* ENUMERATED */
int OBSW_DP_Data__gps_data_mode_Get(OBSW_DP_Data* root)
{
    return (*root).gps.data.mode;
}

/* ENUMERATED */
void OBSW_DP_Data__gps_data_mode_Set(OBSW_DP_Data* root, int value)
{
    (*root).gps.data.mode = value;
}

/* REAL */
double OBSW_DP_Data__gps_data_date_and_time_Get(OBSW_DP_Data* root)
{
    return (*root).gps.data.date_and_time;
}

/* REAL */
void OBSW_DP_Data__gps_data_date_and_time_Set(OBSW_DP_Data* root, double value)
{
    (*root).gps.data.date_and_time = value;
}

/* REAL */
double OBSW_DP_Data__gps_data_ept_Get(OBSW_DP_Data* root)
{
    return (*root).gps.data.ept;
}

/* REAL */
void OBSW_DP_Data__gps_data_ept_Set(OBSW_DP_Data* root, double value)
{
    (*root).gps.data.ept = value;
}

/* REAL */
double OBSW_DP_Data__gps_data_latitude_Get(OBSW_DP_Data* root)
{
    return (*root).gps.data.latitude;
}

/* REAL */
void OBSW_DP_Data__gps_data_latitude_Set(OBSW_DP_Data* root, double value)
{
    (*root).gps.data.latitude = value;
}

/* REAL */
double OBSW_DP_Data__gps_data_epy_Get(OBSW_DP_Data* root)
{
    return (*root).gps.data.epy;
}

/* REAL */
void OBSW_DP_Data__gps_data_epy_Set(OBSW_DP_Data* root, double value)
{
    (*root).gps.data.epy = value;
}

/* REAL */
double OBSW_DP_Data__gps_data_longitude_Get(OBSW_DP_Data* root)
{
    return (*root).gps.data.longitude;
}

/* REAL */
void OBSW_DP_Data__gps_data_longitude_Set(OBSW_DP_Data* root, double value)
{
    (*root).gps.data.longitude = value;
}

/* REAL */
double OBSW_DP_Data__gps_data_epx_Get(OBSW_DP_Data* root)
{
    return (*root).gps.data.epx;
}

/* REAL */
void OBSW_DP_Data__gps_data_epx_Set(OBSW_DP_Data* root, double value)
{
    (*root).gps.data.epx = value;
}

/* REAL */
double OBSW_DP_Data__gps_data_altitude_Get(OBSW_DP_Data* root)
{
    return (*root).gps.data.altitude;
}

/* REAL */
void OBSW_DP_Data__gps_data_altitude_Set(OBSW_DP_Data* root, double value)
{
    (*root).gps.data.altitude = value;
}

/* REAL */
double OBSW_DP_Data__gps_data_epv_Get(OBSW_DP_Data* root)
{
    return (*root).gps.data.epv;
}

/* REAL */
void OBSW_DP_Data__gps_data_epv_Set(OBSW_DP_Data* root, double value)
{
    (*root).gps.data.epv = value;
}

/* REAL */
double OBSW_DP_Data__gps_data_course_Get(OBSW_DP_Data* root)
{
    return (*root).gps.data.course;
}

/* REAL */
void OBSW_DP_Data__gps_data_course_Set(OBSW_DP_Data* root, double value)
{
    (*root).gps.data.course = value;
}

/* REAL */
double OBSW_DP_Data__gps_data_epd_Get(OBSW_DP_Data* root)
{
    return (*root).gps.data.epd;
}

/* REAL */
void OBSW_DP_Data__gps_data_epd_Set(OBSW_DP_Data* root, double value)
{
    (*root).gps.data.epd = value;
}

/* REAL */
double OBSW_DP_Data__gps_data_speed_Get(OBSW_DP_Data* root)
{
    return (*root).gps.data.speed;
}

/* REAL */
void OBSW_DP_Data__gps_data_speed_Set(OBSW_DP_Data* root, double value)
{
    (*root).gps.data.speed = value;
}

/* REAL */
double OBSW_DP_Data__gps_data_eps_Get(OBSW_DP_Data* root)
{
    return (*root).gps.data.eps;
}

/* REAL */
void OBSW_DP_Data__gps_data_eps_Set(OBSW_DP_Data* root, double value)
{
    (*root).gps.data.eps = value;
}

/* REAL */
double OBSW_DP_Data__gps_data_climb_Get(OBSW_DP_Data* root)
{
    return (*root).gps.data.climb;
}

/* REAL */
void OBSW_DP_Data__gps_data_climb_Set(OBSW_DP_Data* root, double value)
{
    (*root).gps.data.climb = value;
}

/* REAL */
double OBSW_DP_Data__gps_data_epc_Get(OBSW_DP_Data* root)
{
    return (*root).gps.data.epc;
}

/* REAL */
void OBSW_DP_Data__gps_data_epc_Set(OBSW_DP_Data* root, double value)
{
    (*root).gps.data.epc = value;
}

/* REAL */
double OBSW_DP_Data__gps_gps_time_Get(OBSW_DP_Data* root)
{
    return (*root).gps.gps_time;
}

/* REAL */
void OBSW_DP_Data__gps_gps_time_Set(OBSW_DP_Data* root, double value)
{
    (*root).gps.gps_time = value;
}

/* REAL */
double OBSW_DP_Data__gps_mission_time_Get(OBSW_DP_Data* root)
{
    return (*root).gps.mission_time;
}

/* REAL */
void OBSW_DP_Data__gps_mission_time_Set(OBSW_DP_Data* root, double value)
{
    (*root).gps.mission_time = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__exist_imu_Get(OBSW_DP_Data* root)
{
    return (*root).exist.imu;
}

/* INTEGER */
void OBSW_DP_Data__exist_imu_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).exist.imu = value;
}

/* Field imu selector */
OBSW_DP_Data_imu* OBSW_DP_Data__imu_Get(OBSW_DP_Data* root)
{
    return &(*root).imu;
}

/* Field data selector */
IMU_All_Data* OBSW_DP_Data__imu_data_Get(OBSW_DP_Data* root)
{
    return &(*root).imu.data;
}

/* Field mgt_raw selector */
MGT_Raw_Data* OBSW_DP_Data__imu_data_mgt_raw_Get(OBSW_DP_Data* root)
{
    return &(*root).imu.data.mgt_raw;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__imu_data_mgt_raw_x_axis_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.mgt_raw.x_axis;
}

/* INTEGER */
void OBSW_DP_Data__imu_data_mgt_raw_x_axis_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).imu.data.mgt_raw.x_axis = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__imu_data_mgt_raw_y_axis_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.mgt_raw.y_axis;
}

/* INTEGER */
void OBSW_DP_Data__imu_data_mgt_raw_y_axis_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).imu.data.mgt_raw.y_axis = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__imu_data_mgt_raw_z_axis_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.mgt_raw.z_axis;
}

/* INTEGER */
void OBSW_DP_Data__imu_data_mgt_raw_z_axis_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).imu.data.mgt_raw.z_axis = value;
}

/* Field mgt_mgauss selector */
MGT_MilliGauss_Data* OBSW_DP_Data__imu_data_mgt_mgauss_Get(OBSW_DP_Data* root)
{
    return &(*root).imu.data.mgt_mgauss;
}

/* REAL */
double OBSW_DP_Data__imu_data_mgt_mgauss_x_axis_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.mgt_mgauss.x_axis;
}

/* REAL */
void OBSW_DP_Data__imu_data_mgt_mgauss_x_axis_Set(OBSW_DP_Data* root, double value)
{
    (*root).imu.data.mgt_mgauss.x_axis = value;
}

/* REAL */
double OBSW_DP_Data__imu_data_mgt_mgauss_y_axis_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.mgt_mgauss.y_axis;
}

/* REAL */
void OBSW_DP_Data__imu_data_mgt_mgauss_y_axis_Set(OBSW_DP_Data* root, double value)
{
    (*root).imu.data.mgt_mgauss.y_axis = value;
}

/* REAL */
double OBSW_DP_Data__imu_data_mgt_mgauss_z_axis_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.mgt_mgauss.z_axis;
}

/* REAL */
void OBSW_DP_Data__imu_data_mgt_mgauss_z_axis_Set(OBSW_DP_Data* root, double value)
{
    (*root).imu.data.mgt_mgauss.z_axis = value;
}

/* Field accel_raw selector */
ACC_Raw_Data* OBSW_DP_Data__imu_data_accel_raw_Get(OBSW_DP_Data* root)
{
    return &(*root).imu.data.accel_raw;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__imu_data_accel_raw_x_axis_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.accel_raw.x_axis;
}

/* INTEGER */
void OBSW_DP_Data__imu_data_accel_raw_x_axis_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).imu.data.accel_raw.x_axis = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__imu_data_accel_raw_y_axis_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.accel_raw.y_axis;
}

/* INTEGER */
void OBSW_DP_Data__imu_data_accel_raw_y_axis_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).imu.data.accel_raw.y_axis = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__imu_data_accel_raw_z_axis_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.accel_raw.z_axis;
}

/* INTEGER */
void OBSW_DP_Data__imu_data_accel_raw_z_axis_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).imu.data.accel_raw.z_axis = value;
}

/* Field accel_mg selector */
ACC_MilliG_Data* OBSW_DP_Data__imu_data_accel_mg_Get(OBSW_DP_Data* root)
{
    return &(*root).imu.data.accel_mg;
}

/* REAL */
double OBSW_DP_Data__imu_data_accel_mg_x_axis_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.accel_mg.x_axis;
}

/* REAL */
void OBSW_DP_Data__imu_data_accel_mg_x_axis_Set(OBSW_DP_Data* root, double value)
{
    (*root).imu.data.accel_mg.x_axis = value;
}

/* REAL */
double OBSW_DP_Data__imu_data_accel_mg_y_axis_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.accel_mg.y_axis;
}

/* REAL */
void OBSW_DP_Data__imu_data_accel_mg_y_axis_Set(OBSW_DP_Data* root, double value)
{
    (*root).imu.data.accel_mg.y_axis = value;
}

/* REAL */
double OBSW_DP_Data__imu_data_accel_mg_z_axis_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.accel_mg.z_axis;
}

/* REAL */
void OBSW_DP_Data__imu_data_accel_mg_z_axis_Set(OBSW_DP_Data* root, double value)
{
    (*root).imu.data.accel_mg.z_axis = value;
}

/* Field gyro_raw selector */
GYRO_Raw_Data* OBSW_DP_Data__imu_data_gyro_raw_Get(OBSW_DP_Data* root)
{
    return &(*root).imu.data.gyro_raw;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__imu_data_gyro_raw_x_axis_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.gyro_raw.x_axis;
}

/* INTEGER */
void OBSW_DP_Data__imu_data_gyro_raw_x_axis_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).imu.data.gyro_raw.x_axis = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__imu_data_gyro_raw_y_axis_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.gyro_raw.y_axis;
}

/* INTEGER */
void OBSW_DP_Data__imu_data_gyro_raw_y_axis_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).imu.data.gyro_raw.y_axis = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__imu_data_gyro_raw_z_axis_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.gyro_raw.z_axis;
}

/* INTEGER */
void OBSW_DP_Data__imu_data_gyro_raw_z_axis_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).imu.data.gyro_raw.z_axis = value;
}

/* Field gyro_mdps selector */
GYRO_MilliDPS_Data* OBSW_DP_Data__imu_data_gyro_mdps_Get(OBSW_DP_Data* root)
{
    return &(*root).imu.data.gyro_mdps;
}

/* REAL */
double OBSW_DP_Data__imu_data_gyro_mdps_x_axis_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.gyro_mdps.x_axis;
}

/* REAL */
void OBSW_DP_Data__imu_data_gyro_mdps_x_axis_Set(OBSW_DP_Data* root, double value)
{
    (*root).imu.data.gyro_mdps.x_axis = value;
}

/* REAL */
double OBSW_DP_Data__imu_data_gyro_mdps_y_axis_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.gyro_mdps.y_axis;
}

/* REAL */
void OBSW_DP_Data__imu_data_gyro_mdps_y_axis_Set(OBSW_DP_Data* root, double value)
{
    (*root).imu.data.gyro_mdps.y_axis = value;
}

/* REAL */
double OBSW_DP_Data__imu_data_gyro_mdps_z_axis_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.gyro_mdps.z_axis;
}

/* REAL */
void OBSW_DP_Data__imu_data_gyro_mdps_z_axis_Set(OBSW_DP_Data* root, double value)
{
    (*root).imu.data.gyro_mdps.z_axis = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__imu_data_temp_raw_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.temp_raw;
}

/* INTEGER */
void OBSW_DP_Data__imu_data_temp_raw_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).imu.data.temp_raw = value;
}

/* REAL */
double OBSW_DP_Data__imu_data_temp_celsius_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.temp_celsius;
}

/* REAL */
void OBSW_DP_Data__imu_data_temp_celsius_Set(OBSW_DP_Data* root, double value)
{
    (*root).imu.data.temp_celsius = value;
}

/* ENUMERATED */
int OBSW_DP_Data__imu_data_mgt_valid_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.mgt_valid;
}

/* ENUMERATED */
void OBSW_DP_Data__imu_data_mgt_valid_Set(OBSW_DP_Data* root, int value)
{
    (*root).imu.data.mgt_valid = value;
}

/* ENUMERATED */
int OBSW_DP_Data__imu_data_acc_valid_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.acc_valid;
}

/* ENUMERATED */
void OBSW_DP_Data__imu_data_acc_valid_Set(OBSW_DP_Data* root, int value)
{
    (*root).imu.data.acc_valid = value;
}

/* ENUMERATED */
int OBSW_DP_Data__imu_data_gyro_valid_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.gyro_valid;
}

/* ENUMERATED */
void OBSW_DP_Data__imu_data_gyro_valid_Set(OBSW_DP_Data* root, int value)
{
    (*root).imu.data.gyro_valid = value;
}

/* ENUMERATED */
int OBSW_DP_Data__imu_data_temp_valid_Get(OBSW_DP_Data* root)
{
    return (*root).imu.data.temp_valid;
}

/* ENUMERATED */
void OBSW_DP_Data__imu_data_temp_valid_Set(OBSW_DP_Data* root, int value)
{
    (*root).imu.data.temp_valid = value;
}

/* REAL */
double OBSW_DP_Data__imu_gps_time_Get(OBSW_DP_Data* root)
{
    return (*root).imu.gps_time;
}

/* REAL */
void OBSW_DP_Data__imu_gps_time_Set(OBSW_DP_Data* root, double value)
{
    (*root).imu.gps_time = value;
}

/* REAL */
double OBSW_DP_Data__imu_mission_time_Get(OBSW_DP_Data* root)
{
    return (*root).imu.mission_time;
}

/* REAL */
void OBSW_DP_Data__imu_mission_time_Set(OBSW_DP_Data* root, double value)
{
    (*root).imu.mission_time = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__exist_tc74s_Get(OBSW_DP_Data* root)
{
    return (*root).exist.tc74s;
}

/* INTEGER */
void OBSW_DP_Data__exist_tc74s_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).exist.tc74s = value;
}

/* Field tc74s selector */
OBSW_DP_Data_tc74s* OBSW_DP_Data__tc74s_Get(OBSW_DP_Data* root)
{
    return &(*root).tc74s;
}

/* Field data selector */
TC74s_All_Data OBSW_DP_Data__tc74s_data_Get(OBSW_DP_Data* root)
{
    return (*root).tc74s.data;
}

/* Field data selector */
void OBSW_DP_Data__tc74s_data_Set(OBSW_DP_Data* root, TC74s_All_Data value)
{
    (*root).tc74s.data = value;
}

/* SEQUENCEOF/SETOF */
long OBSW_DP_Data__tc74s_data_GetLength(OBSW_DP_Data* root)
{
    return 5;
}

/* SEQUENCEOF/SETOF */
void OBSW_DP_Data__tc74s_data_SetLength(OBSW_DP_Data* root, long value)
{
    fprintf(stderr, "WARNING: setting length of fixed-length sequence\n");
}

/* REAL */
double OBSW_DP_Data__tc74s_data_iDx_temperature_Get(OBSW_DP_Data* root, int iDx)
{
    return (*root).tc74s.data.arr[iDx].temperature;
}

/* REAL */
void OBSW_DP_Data__tc74s_data_iDx_temperature_Set(OBSW_DP_Data* root, int iDx, double value)
{
    (*root).tc74s.data.arr[iDx].temperature = value;
}

/* ENUMERATED */
int OBSW_DP_Data__tc74s_data_iDx_validity_Get(OBSW_DP_Data* root, int iDx)
{
    return (*root).tc74s.data.arr[iDx].validity;
}

/* ENUMERATED */
void OBSW_DP_Data__tc74s_data_iDx_validity_Set(OBSW_DP_Data* root, int iDx, int value)
{
    (*root).tc74s.data.arr[iDx].validity = value;
}

/* REAL */
double OBSW_DP_Data__tc74s_gps_time_Get(OBSW_DP_Data* root)
{
    return (*root).tc74s.gps_time;
}

/* REAL */
void OBSW_DP_Data__tc74s_gps_time_Set(OBSW_DP_Data* root, double value)
{
    (*root).tc74s.gps_time = value;
}

/* REAL */
double OBSW_DP_Data__tc74s_mission_time_Get(OBSW_DP_Data* root)
{
    return (*root).tc74s.mission_time;
}

/* REAL */
void OBSW_DP_Data__tc74s_mission_time_Set(OBSW_DP_Data* root, double value)
{
    (*root).tc74s.mission_time = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__exist_pt1000s_Get(OBSW_DP_Data* root)
{
    return (*root).exist.pt1000s;
}

/* INTEGER */
void OBSW_DP_Data__exist_pt1000s_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).exist.pt1000s = value;
}

/* Field pt1000s selector */
OBSW_DP_Data_pt1000s* OBSW_DP_Data__pt1000s_Get(OBSW_DP_Data* root)
{
    return &(*root).pt1000s;
}

/* Field data selector */
PT1000s_All_Data* OBSW_DP_Data__pt1000s_data_Get(OBSW_DP_Data* root)
{
    return &(*root).pt1000s.data;
}

/* Field raw selector */
PT1000s_Raw_Data OBSW_DP_Data__pt1000s_data_raw_Get(OBSW_DP_Data* root)
{
    return (*root).pt1000s.data.raw;
}

/* Field raw selector */
void OBSW_DP_Data__pt1000s_data_raw_Set(OBSW_DP_Data* root, PT1000s_Raw_Data value)
{
    (*root).pt1000s.data.raw = value;
}

/* SEQUENCEOF/SETOF */
long OBSW_DP_Data__pt1000s_data_raw_GetLength(OBSW_DP_Data* root)
{
    return 7;
}

/* SEQUENCEOF/SETOF */
void OBSW_DP_Data__pt1000s_data_raw_SetLength(OBSW_DP_Data* root, long value)
{
    fprintf(stderr, "WARNING: setting length of fixed-length sequence\n");
}

/* REAL */
double OBSW_DP_Data__pt1000s_data_raw_iDx_vcc_volts_Get(OBSW_DP_Data* root, int iDx)
{
    return (*root).pt1000s.data.raw.arr[iDx].vcc_volts;
}

/* REAL */
void OBSW_DP_Data__pt1000s_data_raw_iDx_vcc_volts_Set(OBSW_DP_Data* root, int iDx, double value)
{
    (*root).pt1000s.data.raw.arr[iDx].vcc_volts = value;
}

/* REAL */
double OBSW_DP_Data__pt1000s_data_raw_iDx_pt1000_Get(OBSW_DP_Data* root, int iDx)
{
    return (*root).pt1000s.data.raw.arr[iDx].pt1000;
}

/* REAL */
void OBSW_DP_Data__pt1000s_data_raw_iDx_pt1000_Set(OBSW_DP_Data* root, int iDx, double value)
{
    (*root).pt1000s.data.raw.arr[iDx].pt1000 = value;
}

/* Field celsius selector */
PT1000s_Celsius_Data OBSW_DP_Data__pt1000s_data_celsius_Get(OBSW_DP_Data* root)
{
    return (*root).pt1000s.data.celsius;
}

/* Field celsius selector */
void OBSW_DP_Data__pt1000s_data_celsius_Set(OBSW_DP_Data* root, PT1000s_Celsius_Data value)
{
    (*root).pt1000s.data.celsius = value;
}

/* SEQUENCEOF/SETOF */
long OBSW_DP_Data__pt1000s_data_celsius_GetLength(OBSW_DP_Data* root)
{
    return 7;
}

/* SEQUENCEOF/SETOF */
void OBSW_DP_Data__pt1000s_data_celsius_SetLength(OBSW_DP_Data* root, long value)
{
    fprintf(stderr, "WARNING: setting length of fixed-length sequence\n");
}

/* REAL */
double OBSW_DP_Data__pt1000s_data_celsius_iDx_Get(OBSW_DP_Data* root, int iDx)
{
    return (*root).pt1000s.data.celsius.arr[iDx];
}

/* REAL */
void OBSW_DP_Data__pt1000s_data_celsius_iDx_Set(OBSW_DP_Data* root, int iDx, double value)
{
    (*root).pt1000s.data.celsius.arr[iDx] = value;
}

/* Field validity selector */
PT1000s_All_Data_validity OBSW_DP_Data__pt1000s_data_validity_Get(OBSW_DP_Data* root)
{
    return (*root).pt1000s.data.validity;
}

/* Field validity selector */
void OBSW_DP_Data__pt1000s_data_validity_Set(OBSW_DP_Data* root, PT1000s_All_Data_validity value)
{
    (*root).pt1000s.data.validity = value;
}

/* SEQUENCEOF/SETOF */
long OBSW_DP_Data__pt1000s_data_validity_GetLength(OBSW_DP_Data* root)
{
    return 7;
}

/* SEQUENCEOF/SETOF */
void OBSW_DP_Data__pt1000s_data_validity_SetLength(OBSW_DP_Data* root, long value)
{
    fprintf(stderr, "WARNING: setting length of fixed-length sequence\n");
}

/* ENUMERATED */
int OBSW_DP_Data__pt1000s_data_validity_iDx_Get(OBSW_DP_Data* root, int iDx)
{
    return (*root).pt1000s.data.validity.arr[iDx];
}

/* ENUMERATED */
void OBSW_DP_Data__pt1000s_data_validity_iDx_Set(OBSW_DP_Data* root, int iDx, int value)
{
    (*root).pt1000s.data.validity.arr[iDx] = value;
}

/* REAL */
double OBSW_DP_Data__pt1000s_gps_time_Get(OBSW_DP_Data* root)
{
    return (*root).pt1000s.gps_time;
}

/* REAL */
void OBSW_DP_Data__pt1000s_gps_time_Set(OBSW_DP_Data* root, double value)
{
    (*root).pt1000s.gps_time = value;
}

/* REAL */
double OBSW_DP_Data__pt1000s_mission_time_Get(OBSW_DP_Data* root)
{
    return (*root).pt1000s.mission_time;
}

/* REAL */
void OBSW_DP_Data__pt1000s_mission_time_Set(OBSW_DP_Data* root, double value)
{
    (*root).pt1000s.mission_time = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__exist_ps1_Get(OBSW_DP_Data* root)
{
    return (*root).exist.ps1;
}

/* INTEGER */
void OBSW_DP_Data__exist_ps1_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).exist.ps1 = value;
}

/* Field ps1 selector */
OBSW_DP_Data_ps1* OBSW_DP_Data__ps1_Get(OBSW_DP_Data* root)
{
    return &(*root).ps1;
}

/* Field data selector */
PS_All_Data* OBSW_DP_Data__ps1_data_Get(OBSW_DP_Data* root)
{
    return &(*root).ps1.data;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_exist_calib_Get(OBSW_DP_Data* root)
{
    return (*root).ps1.data.exist.calib;
}

/* INTEGER */
void OBSW_DP_Data__ps1_data_exist_calib_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).ps1.data.exist.calib = value;
}

/* Field calib selector */
PS_Calibration_Data* OBSW_DP_Data__ps1_data_calib_Get(OBSW_DP_Data* root)
{
    return &(*root).ps1.data.calib;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_calib_c1_Get(OBSW_DP_Data* root)
{
    return (*root).ps1.data.calib.c1;
}

/* INTEGER */
void OBSW_DP_Data__ps1_data_calib_c1_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).ps1.data.calib.c1 = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_calib_c2_Get(OBSW_DP_Data* root)
{
    return (*root).ps1.data.calib.c2;
}

/* INTEGER */
void OBSW_DP_Data__ps1_data_calib_c2_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).ps1.data.calib.c2 = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_calib_c3_Get(OBSW_DP_Data* root)
{
    return (*root).ps1.data.calib.c3;
}

/* INTEGER */
void OBSW_DP_Data__ps1_data_calib_c3_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).ps1.data.calib.c3 = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_calib_c4_Get(OBSW_DP_Data* root)
{
    return (*root).ps1.data.calib.c4;
}

/* INTEGER */
void OBSW_DP_Data__ps1_data_calib_c4_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).ps1.data.calib.c4 = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_calib_c5_Get(OBSW_DP_Data* root)
{
    return (*root).ps1.data.calib.c5;
}

/* INTEGER */
void OBSW_DP_Data__ps1_data_calib_c5_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).ps1.data.calib.c5 = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_calib_c6_Get(OBSW_DP_Data* root)
{
    return (*root).ps1.data.calib.c6;
}

/* INTEGER */
void OBSW_DP_Data__ps1_data_calib_c6_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).ps1.data.calib.c6 = value;
}

/* REAL */
double OBSW_DP_Data__ps1_data_calib_sens_t1_Get(OBSW_DP_Data* root)
{
    return (*root).ps1.data.calib.sens_t1;
}

/* REAL */
void OBSW_DP_Data__ps1_data_calib_sens_t1_Set(OBSW_DP_Data* root, double value)
{
    (*root).ps1.data.calib.sens_t1 = value;
}

/* REAL */
double OBSW_DP_Data__ps1_data_calib_off_t1_Get(OBSW_DP_Data* root)
{
    return (*root).ps1.data.calib.off_t1;
}

/* REAL */
void OBSW_DP_Data__ps1_data_calib_off_t1_Set(OBSW_DP_Data* root, double value)
{
    (*root).ps1.data.calib.off_t1 = value;
}

/* REAL */
double OBSW_DP_Data__ps1_data_calib_tcs_Get(OBSW_DP_Data* root)
{
    return (*root).ps1.data.calib.tcs;
}

/* REAL */
void OBSW_DP_Data__ps1_data_calib_tcs_Set(OBSW_DP_Data* root, double value)
{
    (*root).ps1.data.calib.tcs = value;
}

/* REAL */
double OBSW_DP_Data__ps1_data_calib_tco_Get(OBSW_DP_Data* root)
{
    return (*root).ps1.data.calib.tco;
}

/* REAL */
void OBSW_DP_Data__ps1_data_calib_tco_Set(OBSW_DP_Data* root, double value)
{
    (*root).ps1.data.calib.tco = value;
}

/* REAL */
double OBSW_DP_Data__ps1_data_calib_tref_Get(OBSW_DP_Data* root)
{
    return (*root).ps1.data.calib.tref;
}

/* REAL */
void OBSW_DP_Data__ps1_data_calib_tref_Set(OBSW_DP_Data* root, double value)
{
    (*root).ps1.data.calib.tref = value;
}

/* REAL */
double OBSW_DP_Data__ps1_data_calib_temp_sens_Get(OBSW_DP_Data* root)
{
    return (*root).ps1.data.calib.temp_sens;
}

/* REAL */
void OBSW_DP_Data__ps1_data_calib_temp_sens_Set(OBSW_DP_Data* root, double value)
{
    (*root).ps1.data.calib.temp_sens = value;
}

/* Field raw selector */
PS_Raw_Data* OBSW_DP_Data__ps1_data_raw_Get(OBSW_DP_Data* root)
{
    return &(*root).ps1.data.raw;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_raw_d1_Get(OBSW_DP_Data* root)
{
    return (*root).ps1.data.raw.d1;
}

/* INTEGER */
void OBSW_DP_Data__ps1_data_raw_d1_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).ps1.data.raw.d1 = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_raw_d2_Get(OBSW_DP_Data* root)
{
    return (*root).ps1.data.raw.d2;
}

/* INTEGER */
void OBSW_DP_Data__ps1_data_raw_d2_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).ps1.data.raw.d2 = value;
}

/* Field processed selector */
PS_Processed_Data* OBSW_DP_Data__ps1_data_processed_Get(OBSW_DP_Data* root)
{
    return &(*root).ps1.data.processed;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_processed_pressure_Get(OBSW_DP_Data* root)
{
    return (*root).ps1.data.processed.pressure;
}

/* INTEGER */
void OBSW_DP_Data__ps1_data_processed_pressure_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).ps1.data.processed.pressure = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps1_data_processed_temp_Get(OBSW_DP_Data* root)
{
    return (*root).ps1.data.processed.temp;
}

/* INTEGER */
void OBSW_DP_Data__ps1_data_processed_temp_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).ps1.data.processed.temp = value;
}

/* ENUMERATED */
int OBSW_DP_Data__ps1_data_validity_Get(OBSW_DP_Data* root)
{
    return (*root).ps1.data.validity;
}

/* ENUMERATED */
void OBSW_DP_Data__ps1_data_validity_Set(OBSW_DP_Data* root, int value)
{
    (*root).ps1.data.validity = value;
}

/* REAL */
double OBSW_DP_Data__ps1_gps_time_Get(OBSW_DP_Data* root)
{
    return (*root).ps1.gps_time;
}

/* REAL */
void OBSW_DP_Data__ps1_gps_time_Set(OBSW_DP_Data* root, double value)
{
    (*root).ps1.gps_time = value;
}

/* REAL */
double OBSW_DP_Data__ps1_mission_time_Get(OBSW_DP_Data* root)
{
    return (*root).ps1.mission_time;
}

/* REAL */
void OBSW_DP_Data__ps1_mission_time_Set(OBSW_DP_Data* root, double value)
{
    (*root).ps1.mission_time = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__exist_ps2_Get(OBSW_DP_Data* root)
{
    return (*root).exist.ps2;
}

/* INTEGER */
void OBSW_DP_Data__exist_ps2_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).exist.ps2 = value;
}

/* Field ps2 selector */
OBSW_DP_Data_ps2* OBSW_DP_Data__ps2_Get(OBSW_DP_Data* root)
{
    return &(*root).ps2;
}

/* Field data selector */
PS_All_Data* OBSW_DP_Data__ps2_data_Get(OBSW_DP_Data* root)
{
    return &(*root).ps2.data;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_exist_calib_Get(OBSW_DP_Data* root)
{
    return (*root).ps2.data.exist.calib;
}

/* INTEGER */
void OBSW_DP_Data__ps2_data_exist_calib_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).ps2.data.exist.calib = value;
}

/* Field calib selector */
PS_Calibration_Data* OBSW_DP_Data__ps2_data_calib_Get(OBSW_DP_Data* root)
{
    return &(*root).ps2.data.calib;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_calib_c1_Get(OBSW_DP_Data* root)
{
    return (*root).ps2.data.calib.c1;
}

/* INTEGER */
void OBSW_DP_Data__ps2_data_calib_c1_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).ps2.data.calib.c1 = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_calib_c2_Get(OBSW_DP_Data* root)
{
    return (*root).ps2.data.calib.c2;
}

/* INTEGER */
void OBSW_DP_Data__ps2_data_calib_c2_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).ps2.data.calib.c2 = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_calib_c3_Get(OBSW_DP_Data* root)
{
    return (*root).ps2.data.calib.c3;
}

/* INTEGER */
void OBSW_DP_Data__ps2_data_calib_c3_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).ps2.data.calib.c3 = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_calib_c4_Get(OBSW_DP_Data* root)
{
    return (*root).ps2.data.calib.c4;
}

/* INTEGER */
void OBSW_DP_Data__ps2_data_calib_c4_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).ps2.data.calib.c4 = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_calib_c5_Get(OBSW_DP_Data* root)
{
    return (*root).ps2.data.calib.c5;
}

/* INTEGER */
void OBSW_DP_Data__ps2_data_calib_c5_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).ps2.data.calib.c5 = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_calib_c6_Get(OBSW_DP_Data* root)
{
    return (*root).ps2.data.calib.c6;
}

/* INTEGER */
void OBSW_DP_Data__ps2_data_calib_c6_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).ps2.data.calib.c6 = value;
}

/* REAL */
double OBSW_DP_Data__ps2_data_calib_sens_t1_Get(OBSW_DP_Data* root)
{
    return (*root).ps2.data.calib.sens_t1;
}

/* REAL */
void OBSW_DP_Data__ps2_data_calib_sens_t1_Set(OBSW_DP_Data* root, double value)
{
    (*root).ps2.data.calib.sens_t1 = value;
}

/* REAL */
double OBSW_DP_Data__ps2_data_calib_off_t1_Get(OBSW_DP_Data* root)
{
    return (*root).ps2.data.calib.off_t1;
}

/* REAL */
void OBSW_DP_Data__ps2_data_calib_off_t1_Set(OBSW_DP_Data* root, double value)
{
    (*root).ps2.data.calib.off_t1 = value;
}

/* REAL */
double OBSW_DP_Data__ps2_data_calib_tcs_Get(OBSW_DP_Data* root)
{
    return (*root).ps2.data.calib.tcs;
}

/* REAL */
void OBSW_DP_Data__ps2_data_calib_tcs_Set(OBSW_DP_Data* root, double value)
{
    (*root).ps2.data.calib.tcs = value;
}

/* REAL */
double OBSW_DP_Data__ps2_data_calib_tco_Get(OBSW_DP_Data* root)
{
    return (*root).ps2.data.calib.tco;
}

/* REAL */
void OBSW_DP_Data__ps2_data_calib_tco_Set(OBSW_DP_Data* root, double value)
{
    (*root).ps2.data.calib.tco = value;
}

/* REAL */
double OBSW_DP_Data__ps2_data_calib_tref_Get(OBSW_DP_Data* root)
{
    return (*root).ps2.data.calib.tref;
}

/* REAL */
void OBSW_DP_Data__ps2_data_calib_tref_Set(OBSW_DP_Data* root, double value)
{
    (*root).ps2.data.calib.tref = value;
}

/* REAL */
double OBSW_DP_Data__ps2_data_calib_temp_sens_Get(OBSW_DP_Data* root)
{
    return (*root).ps2.data.calib.temp_sens;
}

/* REAL */
void OBSW_DP_Data__ps2_data_calib_temp_sens_Set(OBSW_DP_Data* root, double value)
{
    (*root).ps2.data.calib.temp_sens = value;
}

/* Field raw selector */
PS_Raw_Data* OBSW_DP_Data__ps2_data_raw_Get(OBSW_DP_Data* root)
{
    return &(*root).ps2.data.raw;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_raw_d1_Get(OBSW_DP_Data* root)
{
    return (*root).ps2.data.raw.d1;
}

/* INTEGER */
void OBSW_DP_Data__ps2_data_raw_d1_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).ps2.data.raw.d1 = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_raw_d2_Get(OBSW_DP_Data* root)
{
    return (*root).ps2.data.raw.d2;
}

/* INTEGER */
void OBSW_DP_Data__ps2_data_raw_d2_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).ps2.data.raw.d2 = value;
}

/* Field processed selector */
PS_Processed_Data* OBSW_DP_Data__ps2_data_processed_Get(OBSW_DP_Data* root)
{
    return &(*root).ps2.data.processed;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_processed_pressure_Get(OBSW_DP_Data* root)
{
    return (*root).ps2.data.processed.pressure;
}

/* INTEGER */
void OBSW_DP_Data__ps2_data_processed_pressure_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).ps2.data.processed.pressure = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__ps2_data_processed_temp_Get(OBSW_DP_Data* root)
{
    return (*root).ps2.data.processed.temp;
}

/* INTEGER */
void OBSW_DP_Data__ps2_data_processed_temp_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).ps2.data.processed.temp = value;
}

/* ENUMERATED */
int OBSW_DP_Data__ps2_data_validity_Get(OBSW_DP_Data* root)
{
    return (*root).ps2.data.validity;
}

/* ENUMERATED */
void OBSW_DP_Data__ps2_data_validity_Set(OBSW_DP_Data* root, int value)
{
    (*root).ps2.data.validity = value;
}

/* REAL */
double OBSW_DP_Data__ps2_gps_time_Get(OBSW_DP_Data* root)
{
    return (*root).ps2.gps_time;
}

/* REAL */
void OBSW_DP_Data__ps2_gps_time_Set(OBSW_DP_Data* root, double value)
{
    (*root).ps2.gps_time = value;
}

/* REAL */
double OBSW_DP_Data__ps2_mission_time_Get(OBSW_DP_Data* root)
{
    return (*root).ps2.mission_time;
}

/* REAL */
void OBSW_DP_Data__ps2_mission_time_Set(OBSW_DP_Data* root, double value)
{
    (*root).ps2.mission_time = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__exist_heater1_Get(OBSW_DP_Data* root)
{
    return (*root).exist.heater1;
}

/* INTEGER */
void OBSW_DP_Data__exist_heater1_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).exist.heater1 = value;
}

/* Field heater1 selector */
OBSW_DP_Data_heater1* OBSW_DP_Data__heater1_Get(OBSW_DP_Data* root)
{
    return &(*root).heater1;
}

/* Field data selector */
Heater_Data* OBSW_DP_Data__heater1_data_Get(OBSW_DP_Data* root)
{
    return &(*root).heater1.data;
}

/* REAL */
double OBSW_DP_Data__heater1_data_power_watts_Get(OBSW_DP_Data* root)
{
    return (*root).heater1.data.power_watts;
}

/* REAL */
void OBSW_DP_Data__heater1_data_power_watts_Set(OBSW_DP_Data* root, double value)
{
    (*root).heater1.data.power_watts = value;
}

/* ENUMERATED */
int OBSW_DP_Data__heater1_data_validity_Get(OBSW_DP_Data* root)
{
    return (*root).heater1.data.validity;
}

/* ENUMERATED */
void OBSW_DP_Data__heater1_data_validity_Set(OBSW_DP_Data* root, int value)
{
    (*root).heater1.data.validity = value;
}

/* REAL */
double OBSW_DP_Data__heater1_gps_time_Get(OBSW_DP_Data* root)
{
    return (*root).heater1.gps_time;
}

/* REAL */
void OBSW_DP_Data__heater1_gps_time_Set(OBSW_DP_Data* root, double value)
{
    (*root).heater1.gps_time = value;
}

/* REAL */
double OBSW_DP_Data__heater1_mission_time_Get(OBSW_DP_Data* root)
{
    return (*root).heater1.mission_time;
}

/* REAL */
void OBSW_DP_Data__heater1_mission_time_Set(OBSW_DP_Data* root, double value)
{
    (*root).heater1.mission_time = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__exist_heater2_Get(OBSW_DP_Data* root)
{
    return (*root).exist.heater2;
}

/* INTEGER */
void OBSW_DP_Data__exist_heater2_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).exist.heater2 = value;
}

/* Field heater2 selector */
OBSW_DP_Data_heater2* OBSW_DP_Data__heater2_Get(OBSW_DP_Data* root)
{
    return &(*root).heater2;
}

/* Field data selector */
Heater_Data* OBSW_DP_Data__heater2_data_Get(OBSW_DP_Data* root)
{
    return &(*root).heater2.data;
}

/* REAL */
double OBSW_DP_Data__heater2_data_power_watts_Get(OBSW_DP_Data* root)
{
    return (*root).heater2.data.power_watts;
}

/* REAL */
void OBSW_DP_Data__heater2_data_power_watts_Set(OBSW_DP_Data* root, double value)
{
    (*root).heater2.data.power_watts = value;
}

/* ENUMERATED */
int OBSW_DP_Data__heater2_data_validity_Get(OBSW_DP_Data* root)
{
    return (*root).heater2.data.validity;
}

/* ENUMERATED */
void OBSW_DP_Data__heater2_data_validity_Set(OBSW_DP_Data* root, int value)
{
    (*root).heater2.data.validity = value;
}

/* REAL */
double OBSW_DP_Data__heater2_gps_time_Get(OBSW_DP_Data* root)
{
    return (*root).heater2.gps_time;
}

/* REAL */
void OBSW_DP_Data__heater2_gps_time_Set(OBSW_DP_Data* root, double value)
{
    (*root).heater2.gps_time = value;
}

/* REAL */
double OBSW_DP_Data__heater2_mission_time_Get(OBSW_DP_Data* root)
{
    return (*root).heater2.mission_time;
}

/* REAL */
void OBSW_DP_Data__heater2_mission_time_Set(OBSW_DP_Data* root, double value)
{
    (*root).heater2.mission_time = value;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__exist_anemometer_Get(OBSW_DP_Data* root)
{
    return (*root).exist.anemometer;
}

/* INTEGER */
void OBSW_DP_Data__exist_anemometer_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).exist.anemometer = value;
}

/* Field anemometer selector */
OBSW_DP_Data_anemometer* OBSW_DP_Data__anemometer_Get(OBSW_DP_Data* root)
{
    return &(*root).anemometer;
}

/* INTEGER */
asn1SccSint OBSW_DP_Data__anemometer_data_Get(OBSW_DP_Data* root)
{
    return (*root).anemometer.data;
}

/* INTEGER */
void OBSW_DP_Data__anemometer_data_Set(OBSW_DP_Data* root, asn1SccSint value)
{
    (*root).anemometer.data = value;
}

/* REAL */
double OBSW_DP_Data__anemometer_gps_time_Get(OBSW_DP_Data* root)
{
    return (*root).anemometer.gps_time;
}

/* REAL */
void OBSW_DP_Data__anemometer_gps_time_Set(OBSW_DP_Data* root, double value)
{
    (*root).anemometer.gps_time = value;
}

/* REAL */
double OBSW_DP_Data__anemometer_mission_time_Get(OBSW_DP_Data* root)
{
    return (*root).anemometer.mission_time;
}

/* REAL */
void OBSW_DP_Data__anemometer_mission_time_Set(OBSW_DP_Data* root, double value)
{
    (*root).anemometer.mission_time = value;
}

/* Field heater1 selector */
Heater_Data* TM__heater1_Get(TM* root)
{
    return &(*root).heater1;
}

/* REAL */
double TM__heater1_power_watts_Get(TM* root)
{
    return (*root).heater1.power_watts;
}

/* REAL */
void TM__heater1_power_watts_Set(TM* root, double value)
{
    (*root).heater1.power_watts = value;
}

/* ENUMERATED */
int TM__heater1_validity_Get(TM* root)
{
    return (*root).heater1.validity;
}

/* ENUMERATED */
void TM__heater1_validity_Set(TM* root, int value)
{
    (*root).heater1.validity = value;
}

/* Field heater2 selector */
Heater_Data* TM__heater2_Get(TM* root)
{
    return &(*root).heater2;
}

/* REAL */
double TM__heater2_power_watts_Get(TM* root)
{
    return (*root).heater2.power_watts;
}

/* REAL */
void TM__heater2_power_watts_Set(TM* root, double value)
{
    (*root).heater2.power_watts = value;
}

/* ENUMERATED */
int TM__heater2_validity_Get(TM* root)
{
    return (*root).heater2.validity;
}

/* ENUMERATED */
void TM__heater2_validity_Set(TM* root, int value)
{
    (*root).heater2.validity = value;
}

/* Field tc74s selector */
TC74s_All_Data TM__tc74s_Get(TM* root)
{
    return (*root).tc74s;
}

/* Field tc74s selector */
void TM__tc74s_Set(TM* root, TC74s_All_Data value)
{
    (*root).tc74s = value;
}

/* SEQUENCEOF/SETOF */
long TM__tc74s_GetLength(TM* root)
{
    return 5;
}

/* SEQUENCEOF/SETOF */
void TM__tc74s_SetLength(TM* root, long value)
{
    fprintf(stderr, "WARNING: setting length of fixed-length sequence\n");
}

/* REAL */
double TM__tc74s_iDx_temperature_Get(TM* root, int iDx)
{
    return (*root).tc74s.arr[iDx].temperature;
}

/* REAL */
void TM__tc74s_iDx_temperature_Set(TM* root, int iDx, double value)
{
    (*root).tc74s.arr[iDx].temperature = value;
}

/* ENUMERATED */
int TM__tc74s_iDx_validity_Get(TM* root, int iDx)
{
    return (*root).tc74s.arr[iDx].validity;
}

/* ENUMERATED */
void TM__tc74s_iDx_validity_Set(TM* root, int iDx, int value)
{
    (*root).tc74s.arr[iDx].validity = value;
}

/* Field pt1000s selector */
PT1000s_All_Data* TM__pt1000s_Get(TM* root)
{
    return &(*root).pt1000s;
}

/* Field raw selector */
PT1000s_Raw_Data TM__pt1000s_raw_Get(TM* root)
{
    return (*root).pt1000s.raw;
}

/* Field raw selector */
void TM__pt1000s_raw_Set(TM* root, PT1000s_Raw_Data value)
{
    (*root).pt1000s.raw = value;
}

/* SEQUENCEOF/SETOF */
long TM__pt1000s_raw_GetLength(TM* root)
{
    return 7;
}

/* SEQUENCEOF/SETOF */
void TM__pt1000s_raw_SetLength(TM* root, long value)
{
    fprintf(stderr, "WARNING: setting length of fixed-length sequence\n");
}

/* REAL */
double TM__pt1000s_raw_iDx_vcc_volts_Get(TM* root, int iDx)
{
    return (*root).pt1000s.raw.arr[iDx].vcc_volts;
}

/* REAL */
void TM__pt1000s_raw_iDx_vcc_volts_Set(TM* root, int iDx, double value)
{
    (*root).pt1000s.raw.arr[iDx].vcc_volts = value;
}

/* REAL */
double TM__pt1000s_raw_iDx_pt1000_Get(TM* root, int iDx)
{
    return (*root).pt1000s.raw.arr[iDx].pt1000;
}

/* REAL */
void TM__pt1000s_raw_iDx_pt1000_Set(TM* root, int iDx, double value)
{
    (*root).pt1000s.raw.arr[iDx].pt1000 = value;
}

/* Field celsius selector */
PT1000s_Celsius_Data TM__pt1000s_celsius_Get(TM* root)
{
    return (*root).pt1000s.celsius;
}

/* Field celsius selector */
void TM__pt1000s_celsius_Set(TM* root, PT1000s_Celsius_Data value)
{
    (*root).pt1000s.celsius = value;
}

/* SEQUENCEOF/SETOF */
long TM__pt1000s_celsius_GetLength(TM* root)
{
    return 7;
}

/* SEQUENCEOF/SETOF */
void TM__pt1000s_celsius_SetLength(TM* root, long value)
{
    fprintf(stderr, "WARNING: setting length of fixed-length sequence\n");
}

/* REAL */
double TM__pt1000s_celsius_iDx_Get(TM* root, int iDx)
{
    return (*root).pt1000s.celsius.arr[iDx];
}

/* REAL */
void TM__pt1000s_celsius_iDx_Set(TM* root, int iDx, double value)
{
    (*root).pt1000s.celsius.arr[iDx] = value;
}

/* Field validity selector */
PT1000s_All_Data_validity TM__pt1000s_validity_Get(TM* root)
{
    return (*root).pt1000s.validity;
}

/* Field validity selector */
void TM__pt1000s_validity_Set(TM* root, PT1000s_All_Data_validity value)
{
    (*root).pt1000s.validity = value;
}

/* SEQUENCEOF/SETOF */
long TM__pt1000s_validity_GetLength(TM* root)
{
    return 7;
}

/* SEQUENCEOF/SETOF */
void TM__pt1000s_validity_SetLength(TM* root, long value)
{
    fprintf(stderr, "WARNING: setting length of fixed-length sequence\n");
}

/* ENUMERATED */
int TM__pt1000s_validity_iDx_Get(TM* root, int iDx)
{
    return (*root).pt1000s.validity.arr[iDx];
}

/* ENUMERATED */
void TM__pt1000s_validity_iDx_Set(TM* root, int iDx, int value)
{
    (*root).pt1000s.validity.arr[iDx] = value;
}

/* Field gps selector */
GPS_PVT* TM__gps_Get(TM* root)
{
    return &(*root).gps;
}

/* ENUMERATED */
int TM__gps_mode_Get(TM* root)
{
    return (*root).gps.mode;
}

/* ENUMERATED */
void TM__gps_mode_Set(TM* root, int value)
{
    (*root).gps.mode = value;
}

/* REAL */
double TM__gps_date_and_time_Get(TM* root)
{
    return (*root).gps.date_and_time;
}

/* REAL */
void TM__gps_date_and_time_Set(TM* root, double value)
{
    (*root).gps.date_and_time = value;
}

/* REAL */
double TM__gps_ept_Get(TM* root)
{
    return (*root).gps.ept;
}

/* REAL */
void TM__gps_ept_Set(TM* root, double value)
{
    (*root).gps.ept = value;
}

/* REAL */
double TM__gps_latitude_Get(TM* root)
{
    return (*root).gps.latitude;
}

/* REAL */
void TM__gps_latitude_Set(TM* root, double value)
{
    (*root).gps.latitude = value;
}

/* REAL */
double TM__gps_epy_Get(TM* root)
{
    return (*root).gps.epy;
}

/* REAL */
void TM__gps_epy_Set(TM* root, double value)
{
    (*root).gps.epy = value;
}

/* REAL */
double TM__gps_longitude_Get(TM* root)
{
    return (*root).gps.longitude;
}

/* REAL */
void TM__gps_longitude_Set(TM* root, double value)
{
    (*root).gps.longitude = value;
}

/* REAL */
double TM__gps_epx_Get(TM* root)
{
    return (*root).gps.epx;
}

/* REAL */
void TM__gps_epx_Set(TM* root, double value)
{
    (*root).gps.epx = value;
}

/* REAL */
double TM__gps_altitude_Get(TM* root)
{
    return (*root).gps.altitude;
}

/* REAL */
void TM__gps_altitude_Set(TM* root, double value)
{
    (*root).gps.altitude = value;
}

/* REAL */
double TM__gps_epv_Get(TM* root)
{
    return (*root).gps.epv;
}

/* REAL */
void TM__gps_epv_Set(TM* root, double value)
{
    (*root).gps.epv = value;
}

/* REAL */
double TM__gps_course_Get(TM* root)
{
    return (*root).gps.course;
}

/* REAL */
void TM__gps_course_Set(TM* root, double value)
{
    (*root).gps.course = value;
}

/* REAL */
double TM__gps_epd_Get(TM* root)
{
    return (*root).gps.epd;
}

/* REAL */
void TM__gps_epd_Set(TM* root, double value)
{
    (*root).gps.epd = value;
}

/* REAL */
double TM__gps_speed_Get(TM* root)
{
    return (*root).gps.speed;
}

/* REAL */
void TM__gps_speed_Set(TM* root, double value)
{
    (*root).gps.speed = value;
}

/* REAL */
double TM__gps_eps_Get(TM* root)
{
    return (*root).gps.eps;
}

/* REAL */
void TM__gps_eps_Set(TM* root, double value)
{
    (*root).gps.eps = value;
}

/* REAL */
double TM__gps_climb_Get(TM* root)
{
    return (*root).gps.climb;
}

/* REAL */
void TM__gps_climb_Set(TM* root, double value)
{
    (*root).gps.climb = value;
}

/* REAL */
double TM__gps_epc_Get(TM* root)
{
    return (*root).gps.epc;
}

/* REAL */
void TM__gps_epc_Set(TM* root, double value)
{
    (*root).gps.epc = value;
}

/* Field imu selector */
TM_imu* TM__imu_Get(TM* root)
{
    return &(*root).imu;
}

/* Field mgt_mgauss selector */
MGT_MilliGauss_Data* TM__imu_mgt_mgauss_Get(TM* root)
{
    return &(*root).imu.mgt_mgauss;
}

/* REAL */
double TM__imu_mgt_mgauss_x_axis_Get(TM* root)
{
    return (*root).imu.mgt_mgauss.x_axis;
}

/* REAL */
void TM__imu_mgt_mgauss_x_axis_Set(TM* root, double value)
{
    (*root).imu.mgt_mgauss.x_axis = value;
}

/* REAL */
double TM__imu_mgt_mgauss_y_axis_Get(TM* root)
{
    return (*root).imu.mgt_mgauss.y_axis;
}

/* REAL */
void TM__imu_mgt_mgauss_y_axis_Set(TM* root, double value)
{
    (*root).imu.mgt_mgauss.y_axis = value;
}

/* REAL */
double TM__imu_mgt_mgauss_z_axis_Get(TM* root)
{
    return (*root).imu.mgt_mgauss.z_axis;
}

/* REAL */
void TM__imu_mgt_mgauss_z_axis_Set(TM* root, double value)
{
    (*root).imu.mgt_mgauss.z_axis = value;
}

/* Field accel_mg selector */
ACC_MilliG_Data* TM__imu_accel_mg_Get(TM* root)
{
    return &(*root).imu.accel_mg;
}

/* REAL */
double TM__imu_accel_mg_x_axis_Get(TM* root)
{
    return (*root).imu.accel_mg.x_axis;
}

/* REAL */
void TM__imu_accel_mg_x_axis_Set(TM* root, double value)
{
    (*root).imu.accel_mg.x_axis = value;
}

/* REAL */
double TM__imu_accel_mg_y_axis_Get(TM* root)
{
    return (*root).imu.accel_mg.y_axis;
}

/* REAL */
void TM__imu_accel_mg_y_axis_Set(TM* root, double value)
{
    (*root).imu.accel_mg.y_axis = value;
}

/* REAL */
double TM__imu_accel_mg_z_axis_Get(TM* root)
{
    return (*root).imu.accel_mg.z_axis;
}

/* REAL */
void TM__imu_accel_mg_z_axis_Set(TM* root, double value)
{
    (*root).imu.accel_mg.z_axis = value;
}

/* Field gyro_mdps selector */
GYRO_MilliDPS_Data* TM__imu_gyro_mdps_Get(TM* root)
{
    return &(*root).imu.gyro_mdps;
}

/* REAL */
double TM__imu_gyro_mdps_x_axis_Get(TM* root)
{
    return (*root).imu.gyro_mdps.x_axis;
}

/* REAL */
void TM__imu_gyro_mdps_x_axis_Set(TM* root, double value)
{
    (*root).imu.gyro_mdps.x_axis = value;
}

/* REAL */
double TM__imu_gyro_mdps_y_axis_Get(TM* root)
{
    return (*root).imu.gyro_mdps.y_axis;
}

/* REAL */
void TM__imu_gyro_mdps_y_axis_Set(TM* root, double value)
{
    (*root).imu.gyro_mdps.y_axis = value;
}

/* REAL */
double TM__imu_gyro_mdps_z_axis_Get(TM* root)
{
    return (*root).imu.gyro_mdps.z_axis;
}

/* REAL */
void TM__imu_gyro_mdps_z_axis_Set(TM* root, double value)
{
    (*root).imu.gyro_mdps.z_axis = value;
}

/* REAL */
double TM__imu_temp_celsius_Get(TM* root)
{
    return (*root).imu.temp_celsius;
}

/* REAL */
void TM__imu_temp_celsius_Set(TM* root, double value)
{
    (*root).imu.temp_celsius = value;
}

/* ENUMERATED */
int TM__imu_mgt_valid_Get(TM* root)
{
    return (*root).imu.mgt_valid;
}

/* ENUMERATED */
void TM__imu_mgt_valid_Set(TM* root, int value)
{
    (*root).imu.mgt_valid = value;
}

/* ENUMERATED */
int TM__imu_acc_valid_Get(TM* root)
{
    return (*root).imu.acc_valid;
}

/* ENUMERATED */
void TM__imu_acc_valid_Set(TM* root, int value)
{
    (*root).imu.acc_valid = value;
}

/* ENUMERATED */
int TM__imu_gyro_valid_Get(TM* root)
{
    return (*root).imu.gyro_valid;
}

/* ENUMERATED */
void TM__imu_gyro_valid_Set(TM* root, int value)
{
    (*root).imu.gyro_valid = value;
}

/* ENUMERATED */
int TM__imu_temp_valid_Get(TM* root)
{
    return (*root).imu.temp_valid;
}

/* ENUMERATED */
void TM__imu_temp_valid_Set(TM* root, int value)
{
    (*root).imu.temp_valid = value;
}

/* Field ps1 selector */
PS_Processed_Data* TM__ps1_Get(TM* root)
{
    return &(*root).ps1;
}

/* INTEGER */
asn1SccSint TM__ps1_pressure_Get(TM* root)
{
    return (*root).ps1.pressure;
}

/* INTEGER */
void TM__ps1_pressure_Set(TM* root, asn1SccSint value)
{
    (*root).ps1.pressure = value;
}

/* INTEGER */
asn1SccSint TM__ps1_temp_Get(TM* root)
{
    return (*root).ps1.temp;
}

/* INTEGER */
void TM__ps1_temp_Set(TM* root, asn1SccSint value)
{
    (*root).ps1.temp = value;
}

/* Field ps2 selector */
PS_Processed_Data* TM__ps2_Get(TM* root)
{
    return &(*root).ps2;
}

/* INTEGER */
asn1SccSint TM__ps2_pressure_Get(TM* root)
{
    return (*root).ps2.pressure;
}

/* INTEGER */
void TM__ps2_pressure_Set(TM* root, asn1SccSint value)
{
    (*root).ps2.pressure = value;
}

/* INTEGER */
asn1SccSint TM__ps2_temp_Get(TM* root)
{
    return (*root).ps2.temp;
}

/* INTEGER */
void TM__ps2_temp_Set(TM* root, asn1SccSint value)
{
    (*root).ps2.temp = value;
}

/* ENUMERATED */
int TM__ps1_validity_Get(TM* root)
{
    return (*root).ps1_validity;
}

/* ENUMERATED */
void TM__ps1_validity_Set(TM* root, int value)
{
    (*root).ps1_validity = value;
}

/* ENUMERATED */
int TM__ps2_validity_Get(TM* root)
{
    return (*root).ps2_validity;
}

/* ENUMERATED */
void TM__ps2_validity_Set(TM* root, int value)
{
    (*root).ps2_validity = value;
}

/* INTEGER */
asn1SccSint TM__anemometer_Get(TM* root)
{
    return (*root).anemometer;
}

/* INTEGER */
void TM__anemometer_Set(TM* root, asn1SccSint value)
{
    (*root).anemometer = value;
}

/* ENUMERATED */
int TC_Heater__heater_Get(TC_Heater* root)
{
    return (*root).heater;
}

/* ENUMERATED */
void TC_Heater__heater_Set(TC_Heater* root, int value)
{
    (*root).heater = value;
}

/* Field command selector */
TC_Heater_command* TC_Heater__command_Get(TC_Heater* root)
{
    return &(*root).command;
}

/* CHOICE selector */
int TC_Heater__command_kind_Get(TC_Heater* root)
{
    return (*root).command.kind;
}

/* CHOICE selector */
void TC_Heater__command_kind_Set(TC_Heater* root, int value)
{
    (*root).command.kind = value;
}

/* REAL */
double TC_Heater__command_power_manual_Get(TC_Heater* root)
{
    return (*root).command.u.power_manual;
}

/* REAL */
void TC_Heater__command_power_manual_Set(TC_Heater* root, double value)
{
    (*root).command.u.power_manual = value;
}

/* ENUMERATED */
int TC_Heater__command_max_min_Get(TC_Heater* root)
{
    return (*root).command.u.max_min;
}

/* ENUMERATED */
void TC_Heater__command_max_min_Set(TC_Heater* root, int value)
{
    (*root).command.u.max_min = value;
}

/* Field heater selector */
Heater_Data* HTL_GUI__heater_Get(HTL_GUI* root)
{
    return &(*root).heater;
}

/* REAL */
double HTL_GUI__heater_power_watts_Get(HTL_GUI* root)
{
    return (*root).heater.power_watts;
}

/* REAL */
void HTL_GUI__heater_power_watts_Set(HTL_GUI* root, double value)
{
    (*root).heater.power_watts = value;
}

/* ENUMERATED */
int HTL_GUI__heater_validity_Get(HTL_GUI* root)
{
    return (*root).heater.validity;
}

/* ENUMERATED */
void HTL_GUI__heater_validity_Set(HTL_GUI* root, int value)
{
    (*root).heater.validity = value;
}

/* REAL */
double HTL_GUI__delta_T_Get(HTL_GUI* root)
{
    return (*root).delta_T;
}

/* REAL */
void HTL_GUI__delta_T_Set(HTL_GUI* root, double value)
{
    (*root).delta_T = value;
}

/* Field pt1000s selector */
HTL_GUI_pt1000s* HTL_GUI__pt1000s_Get(HTL_GUI* root)
{
    return &(*root).pt1000s;
}

/* REAL */
double HTL_GUI__pt1000s_aire_abajo_Get(HTL_GUI* root)
{
    return (*root).pt1000s.aire_abajo;
}

/* REAL */
void HTL_GUI__pt1000s_aire_abajo_Set(HTL_GUI* root, double value)
{
    (*root).pt1000s.aire_abajo = value;
}

/* REAL */
double HTL_GUI__pt1000s_aire_arriba_Get(HTL_GUI* root)
{
    return (*root).pt1000s.aire_arriba;
}

/* REAL */
void HTL_GUI__pt1000s_aire_arriba_Set(HTL_GUI* root, double value)
{
    (*root).pt1000s.aire_arriba = value;
}

/* REAL */
double HTL_GUI__pt1000s_placa_abajo_Get(HTL_GUI* root)
{
    return (*root).pt1000s.placa_abajo;
}

/* REAL */
void HTL_GUI__pt1000s_placa_abajo_Set(HTL_GUI* root, double value)
{
    (*root).pt1000s.placa_abajo = value;
}

/* REAL */
double HTL_GUI__pt1000s_placa_arriba_Get(HTL_GUI* root)
{
    return (*root).pt1000s.placa_arriba;
}

/* REAL */
void HTL_GUI__pt1000s_placa_arriba_Set(HTL_GUI* root, double value)
{
    (*root).pt1000s.placa_arriba = value;
}

/* REAL */
double HTL_GUI__pt1000s_infinito_Get(HTL_GUI* root)
{
    return (*root).pt1000s.infinito;
}

/* REAL */
void HTL_GUI__pt1000s_infinito_Set(HTL_GUI* root, double value)
{
    (*root).pt1000s.infinito = value;
}

/* REAL */
double HTL_GUI__pt1000s_exterior_Get(HTL_GUI* root)
{
    return (*root).pt1000s.exterior;
}

/* REAL */
void HTL_GUI__pt1000s_exterior_Set(HTL_GUI* root, double value)
{
    (*root).pt1000s.exterior = value;
}

/* REAL */
double HTL_GUI__pt1000s_vcc_volts_Get(HTL_GUI* root)
{
    return (*root).pt1000s.vcc_volts;
}

/* REAL */
void HTL_GUI__pt1000s_vcc_volts_Set(HTL_GUI* root, double value)
{
    (*root).pt1000s.vcc_volts = value;
}

/* Field validity selector */
HTL_GUI_pt1000s_validity HTL_GUI__pt1000s_validity_Get(HTL_GUI* root)
{
    return (*root).pt1000s.validity;
}

/* Field validity selector */
void HTL_GUI__pt1000s_validity_Set(HTL_GUI* root, HTL_GUI_pt1000s_validity value)
{
    (*root).pt1000s.validity = value;
}

/* SEQUENCEOF/SETOF */
long HTL_GUI__pt1000s_validity_GetLength(HTL_GUI* root)
{
    return 7;
}

/* SEQUENCEOF/SETOF */
void HTL_GUI__pt1000s_validity_SetLength(HTL_GUI* root, long value)
{
    fprintf(stderr, "WARNING: setting length of fixed-length sequence\n");
}

/* ENUMERATED */
int HTL_GUI__pt1000s_validity_iDx_Get(HTL_GUI* root, int iDx)
{
    return (*root).pt1000s.validity.arr[iDx];
}

/* ENUMERATED */
void HTL_GUI__pt1000s_validity_iDx_Set(HTL_GUI* root, int iDx, int value)
{
    (*root).pt1000s.validity.arr[iDx] = value;
}

/* Field tc74s selector */
HTL_GUI_tc74s* HTL_GUI__tc74s_Get(HTL_GUI* root)
{
    return &(*root).tc74s;
}

/* REAL */
double HTL_GUI__tc74s_x_positive_Get(HTL_GUI* root)
{
    return (*root).tc74s.x_positive;
}

/* REAL */
void HTL_GUI__tc74s_x_positive_Set(HTL_GUI* root, double value)
{
    (*root).tc74s.x_positive = value;
}

/* REAL */
double HTL_GUI__tc74s_x_negative_Get(HTL_GUI* root)
{
    return (*root).tc74s.x_negative;
}

/* REAL */
void HTL_GUI__tc74s_x_negative_Set(HTL_GUI* root, double value)
{
    (*root).tc74s.x_negative = value;
}

/* REAL */
double HTL_GUI__tc74s_y_positive_Get(HTL_GUI* root)
{
    return (*root).tc74s.y_positive;
}

/* REAL */
void HTL_GUI__tc74s_y_positive_Set(HTL_GUI* root, double value)
{
    (*root).tc74s.y_positive = value;
}

/* REAL */
double HTL_GUI__tc74s_y_negative_Get(HTL_GUI* root)
{
    return (*root).tc74s.y_negative;
}

/* REAL */
void HTL_GUI__tc74s_y_negative_Set(HTL_GUI* root, double value)
{
    (*root).tc74s.y_negative = value;
}

/* REAL */
double HTL_GUI__tc74s_z_techo_Get(HTL_GUI* root)
{
    return (*root).tc74s.z_techo;
}

/* REAL */
void HTL_GUI__tc74s_z_techo_Set(HTL_GUI* root, double value)
{
    (*root).tc74s.z_techo = value;
}

/* Field validity selector */
HTL_GUI_tc74s_validity HTL_GUI__tc74s_validity_Get(HTL_GUI* root)
{
    return (*root).tc74s.validity;
}

/* Field validity selector */
void HTL_GUI__tc74s_validity_Set(HTL_GUI* root, HTL_GUI_tc74s_validity value)
{
    (*root).tc74s.validity = value;
}

/* SEQUENCEOF/SETOF */
long HTL_GUI__tc74s_validity_GetLength(HTL_GUI* root)
{
    return 5;
}

/* SEQUENCEOF/SETOF */
void HTL_GUI__tc74s_validity_SetLength(HTL_GUI* root, long value)
{
    fprintf(stderr, "WARNING: setting length of fixed-length sequence\n");
}

/* ENUMERATED */
int HTL_GUI__tc74s_validity_iDx_Get(HTL_GUI* root, int iDx)
{
    return (*root).tc74s.validity.arr[iDx];
}

/* ENUMERATED */
void HTL_GUI__tc74s_validity_iDx_Set(HTL_GUI* root, int iDx, int value)
{
    (*root).tc74s.validity.arr[iDx] = value;
}

/* INTEGER */
asn1SccSint Date_Time__day_Get(Date_Time* root)
{
    return (*root).day;
}

/* INTEGER */
void Date_Time__day_Set(Date_Time* root, asn1SccSint value)
{
    (*root).day = value;
}

/* INTEGER */
asn1SccSint Date_Time__month_Get(Date_Time* root)
{
    return (*root).month;
}

/* INTEGER */
void Date_Time__month_Set(Date_Time* root, asn1SccSint value)
{
    (*root).month = value;
}

/* INTEGER */
asn1SccSint Date_Time__year_Get(Date_Time* root)
{
    return (*root).year;
}

/* INTEGER */
void Date_Time__year_Set(Date_Time* root, asn1SccSint value)
{
    (*root).year = value;
}

/* INTEGER */
asn1SccSint Date_Time__hour_Get(Date_Time* root)
{
    return (*root).hour;
}

/* INTEGER */
void Date_Time__hour_Set(Date_Time* root, asn1SccSint value)
{
    (*root).hour = value;
}

/* INTEGER */
asn1SccSint Date_Time__minute_Get(Date_Time* root)
{
    return (*root).minute;
}

/* INTEGER */
void Date_Time__minute_Set(Date_Time* root, asn1SccSint value)
{
    (*root).minute = value;
}

/* INTEGER */
asn1SccSint Date_Time__second_Get(Date_Time* root)
{
    return (*root).second;
}

/* INTEGER */
void Date_Time__second_Set(Date_Time* root, asn1SccSint value)
{
    (*root).second = value;
}

/* Field gps selector */
GPS_PVT* ATT_GUI__gps_Get(ATT_GUI* root)
{
    return &(*root).gps;
}

/* ENUMERATED */
int ATT_GUI__gps_mode_Get(ATT_GUI* root)
{
    return (*root).gps.mode;
}

/* ENUMERATED */
void ATT_GUI__gps_mode_Set(ATT_GUI* root, int value)
{
    (*root).gps.mode = value;
}

/* REAL */
double ATT_GUI__gps_date_and_time_Get(ATT_GUI* root)
{
    return (*root).gps.date_and_time;
}

/* REAL */
void ATT_GUI__gps_date_and_time_Set(ATT_GUI* root, double value)
{
    (*root).gps.date_and_time = value;
}

/* REAL */
double ATT_GUI__gps_ept_Get(ATT_GUI* root)
{
    return (*root).gps.ept;
}

/* REAL */
void ATT_GUI__gps_ept_Set(ATT_GUI* root, double value)
{
    (*root).gps.ept = value;
}

/* REAL */
double ATT_GUI__gps_latitude_Get(ATT_GUI* root)
{
    return (*root).gps.latitude;
}

/* REAL */
void ATT_GUI__gps_latitude_Set(ATT_GUI* root, double value)
{
    (*root).gps.latitude = value;
}

/* REAL */
double ATT_GUI__gps_epy_Get(ATT_GUI* root)
{
    return (*root).gps.epy;
}

/* REAL */
void ATT_GUI__gps_epy_Set(ATT_GUI* root, double value)
{
    (*root).gps.epy = value;
}

/* REAL */
double ATT_GUI__gps_longitude_Get(ATT_GUI* root)
{
    return (*root).gps.longitude;
}

/* REAL */
void ATT_GUI__gps_longitude_Set(ATT_GUI* root, double value)
{
    (*root).gps.longitude = value;
}

/* REAL */
double ATT_GUI__gps_epx_Get(ATT_GUI* root)
{
    return (*root).gps.epx;
}

/* REAL */
void ATT_GUI__gps_epx_Set(ATT_GUI* root, double value)
{
    (*root).gps.epx = value;
}

/* REAL */
double ATT_GUI__gps_altitude_Get(ATT_GUI* root)
{
    return (*root).gps.altitude;
}

/* REAL */
void ATT_GUI__gps_altitude_Set(ATT_GUI* root, double value)
{
    (*root).gps.altitude = value;
}

/* REAL */
double ATT_GUI__gps_epv_Get(ATT_GUI* root)
{
    return (*root).gps.epv;
}

/* REAL */
void ATT_GUI__gps_epv_Set(ATT_GUI* root, double value)
{
    (*root).gps.epv = value;
}

/* REAL */
double ATT_GUI__gps_course_Get(ATT_GUI* root)
{
    return (*root).gps.course;
}

/* REAL */
void ATT_GUI__gps_course_Set(ATT_GUI* root, double value)
{
    (*root).gps.course = value;
}

/* REAL */
double ATT_GUI__gps_epd_Get(ATT_GUI* root)
{
    return (*root).gps.epd;
}

/* REAL */
void ATT_GUI__gps_epd_Set(ATT_GUI* root, double value)
{
    (*root).gps.epd = value;
}

/* REAL */
double ATT_GUI__gps_speed_Get(ATT_GUI* root)
{
    return (*root).gps.speed;
}

/* REAL */
void ATT_GUI__gps_speed_Set(ATT_GUI* root, double value)
{
    (*root).gps.speed = value;
}

/* REAL */
double ATT_GUI__gps_eps_Get(ATT_GUI* root)
{
    return (*root).gps.eps;
}

/* REAL */
void ATT_GUI__gps_eps_Set(ATT_GUI* root, double value)
{
    (*root).gps.eps = value;
}

/* REAL */
double ATT_GUI__gps_climb_Get(ATT_GUI* root)
{
    return (*root).gps.climb;
}

/* REAL */
void ATT_GUI__gps_climb_Set(ATT_GUI* root, double value)
{
    (*root).gps.climb = value;
}

/* REAL */
double ATT_GUI__gps_epc_Get(ATT_GUI* root)
{
    return (*root).gps.epc;
}

/* REAL */
void ATT_GUI__gps_epc_Set(ATT_GUI* root, double value)
{
    (*root).gps.epc = value;
}

/* Field gps_date_time selector */
Date_Time* ATT_GUI__gps_date_time_Get(ATT_GUI* root)
{
    return &(*root).gps_date_time;
}

/* INTEGER */
asn1SccSint ATT_GUI__gps_date_time_day_Get(ATT_GUI* root)
{
    return (*root).gps_date_time.day;
}

/* INTEGER */
void ATT_GUI__gps_date_time_day_Set(ATT_GUI* root, asn1SccSint value)
{
    (*root).gps_date_time.day = value;
}

/* INTEGER */
asn1SccSint ATT_GUI__gps_date_time_month_Get(ATT_GUI* root)
{
    return (*root).gps_date_time.month;
}

/* INTEGER */
void ATT_GUI__gps_date_time_month_Set(ATT_GUI* root, asn1SccSint value)
{
    (*root).gps_date_time.month = value;
}

/* INTEGER */
asn1SccSint ATT_GUI__gps_date_time_year_Get(ATT_GUI* root)
{
    return (*root).gps_date_time.year;
}

/* INTEGER */
void ATT_GUI__gps_date_time_year_Set(ATT_GUI* root, asn1SccSint value)
{
    (*root).gps_date_time.year = value;
}

/* INTEGER */
asn1SccSint ATT_GUI__gps_date_time_hour_Get(ATT_GUI* root)
{
    return (*root).gps_date_time.hour;
}

/* INTEGER */
void ATT_GUI__gps_date_time_hour_Set(ATT_GUI* root, asn1SccSint value)
{
    (*root).gps_date_time.hour = value;
}

/* INTEGER */
asn1SccSint ATT_GUI__gps_date_time_minute_Get(ATT_GUI* root)
{
    return (*root).gps_date_time.minute;
}

/* INTEGER */
void ATT_GUI__gps_date_time_minute_Set(ATT_GUI* root, asn1SccSint value)
{
    (*root).gps_date_time.minute = value;
}

/* INTEGER */
asn1SccSint ATT_GUI__gps_date_time_second_Get(ATT_GUI* root)
{
    return (*root).gps_date_time.second;
}

/* INTEGER */
void ATT_GUI__gps_date_time_second_Set(ATT_GUI* root, asn1SccSint value)
{
    (*root).gps_date_time.second = value;
}

/* Field imu selector */
ATT_GUI_imu* ATT_GUI__imu_Get(ATT_GUI* root)
{
    return &(*root).imu;
}

/* Field mgt_mgauss selector */
MGT_MilliGauss_Data* ATT_GUI__imu_mgt_mgauss_Get(ATT_GUI* root)
{
    return &(*root).imu.mgt_mgauss;
}

/* REAL */
double ATT_GUI__imu_mgt_mgauss_x_axis_Get(ATT_GUI* root)
{
    return (*root).imu.mgt_mgauss.x_axis;
}

/* REAL */
void ATT_GUI__imu_mgt_mgauss_x_axis_Set(ATT_GUI* root, double value)
{
    (*root).imu.mgt_mgauss.x_axis = value;
}

/* REAL */
double ATT_GUI__imu_mgt_mgauss_y_axis_Get(ATT_GUI* root)
{
    return (*root).imu.mgt_mgauss.y_axis;
}

/* REAL */
void ATT_GUI__imu_mgt_mgauss_y_axis_Set(ATT_GUI* root, double value)
{
    (*root).imu.mgt_mgauss.y_axis = value;
}

/* REAL */
double ATT_GUI__imu_mgt_mgauss_z_axis_Get(ATT_GUI* root)
{
    return (*root).imu.mgt_mgauss.z_axis;
}

/* REAL */
void ATT_GUI__imu_mgt_mgauss_z_axis_Set(ATT_GUI* root, double value)
{
    (*root).imu.mgt_mgauss.z_axis = value;
}

/* Field accel_mg selector */
ACC_MilliG_Data* ATT_GUI__imu_accel_mg_Get(ATT_GUI* root)
{
    return &(*root).imu.accel_mg;
}

/* REAL */
double ATT_GUI__imu_accel_mg_x_axis_Get(ATT_GUI* root)
{
    return (*root).imu.accel_mg.x_axis;
}

/* REAL */
void ATT_GUI__imu_accel_mg_x_axis_Set(ATT_GUI* root, double value)
{
    (*root).imu.accel_mg.x_axis = value;
}

/* REAL */
double ATT_GUI__imu_accel_mg_y_axis_Get(ATT_GUI* root)
{
    return (*root).imu.accel_mg.y_axis;
}

/* REAL */
void ATT_GUI__imu_accel_mg_y_axis_Set(ATT_GUI* root, double value)
{
    (*root).imu.accel_mg.y_axis = value;
}

/* REAL */
double ATT_GUI__imu_accel_mg_z_axis_Get(ATT_GUI* root)
{
    return (*root).imu.accel_mg.z_axis;
}

/* REAL */
void ATT_GUI__imu_accel_mg_z_axis_Set(ATT_GUI* root, double value)
{
    (*root).imu.accel_mg.z_axis = value;
}

/* Field gyro_mdps selector */
GYRO_MilliDPS_Data* ATT_GUI__imu_gyro_mdps_Get(ATT_GUI* root)
{
    return &(*root).imu.gyro_mdps;
}

/* REAL */
double ATT_GUI__imu_gyro_mdps_x_axis_Get(ATT_GUI* root)
{
    return (*root).imu.gyro_mdps.x_axis;
}

/* REAL */
void ATT_GUI__imu_gyro_mdps_x_axis_Set(ATT_GUI* root, double value)
{
    (*root).imu.gyro_mdps.x_axis = value;
}

/* REAL */
double ATT_GUI__imu_gyro_mdps_y_axis_Get(ATT_GUI* root)
{
    return (*root).imu.gyro_mdps.y_axis;
}

/* REAL */
void ATT_GUI__imu_gyro_mdps_y_axis_Set(ATT_GUI* root, double value)
{
    (*root).imu.gyro_mdps.y_axis = value;
}

/* REAL */
double ATT_GUI__imu_gyro_mdps_z_axis_Get(ATT_GUI* root)
{
    return (*root).imu.gyro_mdps.z_axis;
}

/* REAL */
void ATT_GUI__imu_gyro_mdps_z_axis_Set(ATT_GUI* root, double value)
{
    (*root).imu.gyro_mdps.z_axis = value;
}

/* REAL */
double ATT_GUI__imu_temp_celsius_Get(ATT_GUI* root)
{
    return (*root).imu.temp_celsius;
}

/* REAL */
void ATT_GUI__imu_temp_celsius_Set(ATT_GUI* root, double value)
{
    (*root).imu.temp_celsius = value;
}

/* ENUMERATED */
int ATT_GUI__imu_mgt_valid_Get(ATT_GUI* root)
{
    return (*root).imu.mgt_valid;
}

/* ENUMERATED */
void ATT_GUI__imu_mgt_valid_Set(ATT_GUI* root, int value)
{
    (*root).imu.mgt_valid = value;
}

/* ENUMERATED */
int ATT_GUI__imu_acc_valid_Get(ATT_GUI* root)
{
    return (*root).imu.acc_valid;
}

/* ENUMERATED */
void ATT_GUI__imu_acc_valid_Set(ATT_GUI* root, int value)
{
    (*root).imu.acc_valid = value;
}

/* ENUMERATED */
int ATT_GUI__imu_gyro_valid_Get(ATT_GUI* root)
{
    return (*root).imu.gyro_valid;
}

/* ENUMERATED */
void ATT_GUI__imu_gyro_valid_Set(ATT_GUI* root, int value)
{
    (*root).imu.gyro_valid = value;
}

/* ENUMERATED */
int ATT_GUI__imu_temp_valid_Get(ATT_GUI* root)
{
    return (*root).imu.temp_valid;
}

/* ENUMERATED */
void ATT_GUI__imu_temp_valid_Set(ATT_GUI* root, int value)
{
    (*root).imu.temp_valid = value;
}

/* REAL */
double PS_GUI__pressure_mbar_Get(PS_GUI* root)
{
    return (*root).pressure_mbar;
}

/* REAL */
void PS_GUI__pressure_mbar_Set(PS_GUI* root, double value)
{
    (*root).pressure_mbar = value;
}

/* REAL */
double PS_GUI__temperature_celsius_Get(PS_GUI* root)
{
    return (*root).temperature_celsius;
}

/* REAL */
void PS_GUI__temperature_celsius_Set(PS_GUI* root, double value)
{
    (*root).temperature_celsius = value;
}

/* ENUMERATED */
int PS_GUI__validity_Get(PS_GUI* root)
{
    return (*root).validity;
}

/* ENUMERATED */
void PS_GUI__validity_Set(PS_GUI* root, int value)
{
    (*root).validity = value;
}

/* Field pressure_sensor_1 selector */
PS_GUI* ENV_GUI__pressure_sensor_1_Get(ENV_GUI* root)
{
    return &(*root).pressure_sensor_1;
}

/* REAL */
double ENV_GUI__pressure_sensor_1_pressure_mbar_Get(ENV_GUI* root)
{
    return (*root).pressure_sensor_1.pressure_mbar;
}

/* REAL */
void ENV_GUI__pressure_sensor_1_pressure_mbar_Set(ENV_GUI* root, double value)
{
    (*root).pressure_sensor_1.pressure_mbar = value;
}

/* REAL */
double ENV_GUI__pressure_sensor_1_temperature_celsius_Get(ENV_GUI* root)
{
    return (*root).pressure_sensor_1.temperature_celsius;
}

/* REAL */
void ENV_GUI__pressure_sensor_1_temperature_celsius_Set(ENV_GUI* root, double value)
{
    (*root).pressure_sensor_1.temperature_celsius = value;
}

/* ENUMERATED */
int ENV_GUI__pressure_sensor_1_validity_Get(ENV_GUI* root)
{
    return (*root).pressure_sensor_1.validity;
}

/* ENUMERATED */
void ENV_GUI__pressure_sensor_1_validity_Set(ENV_GUI* root, int value)
{
    (*root).pressure_sensor_1.validity = value;
}

/* Field pressure_sensor_2 selector */
PS_GUI* ENV_GUI__pressure_sensor_2_Get(ENV_GUI* root)
{
    return &(*root).pressure_sensor_2;
}

/* REAL */
double ENV_GUI__pressure_sensor_2_pressure_mbar_Get(ENV_GUI* root)
{
    return (*root).pressure_sensor_2.pressure_mbar;
}

/* REAL */
void ENV_GUI__pressure_sensor_2_pressure_mbar_Set(ENV_GUI* root, double value)
{
    (*root).pressure_sensor_2.pressure_mbar = value;
}

/* REAL */
double ENV_GUI__pressure_sensor_2_temperature_celsius_Get(ENV_GUI* root)
{
    return (*root).pressure_sensor_2.temperature_celsius;
}

/* REAL */
void ENV_GUI__pressure_sensor_2_temperature_celsius_Set(ENV_GUI* root, double value)
{
    (*root).pressure_sensor_2.temperature_celsius = value;
}

/* ENUMERATED */
int ENV_GUI__pressure_sensor_2_validity_Get(ENV_GUI* root)
{
    return (*root).pressure_sensor_2.validity;
}

/* ENUMERATED */
void ENV_GUI__pressure_sensor_2_validity_Set(ENV_GUI* root, int value)
{
    (*root).pressure_sensor_2.validity = value;
}

/* Field anemometer selector */
ENV_GUI_anemometer* ENV_GUI__anemometer_Get(ENV_GUI* root)
{
    return &(*root).anemometer;
}

/* INTEGER */
asn1SccSint ENV_GUI__anemometer_global_counter_Get(ENV_GUI* root)
{
    return (*root).anemometer.global_counter;
}

/* INTEGER */
void ENV_GUI__anemometer_global_counter_Set(ENV_GUI* root, asn1SccSint value)
{
    (*root).anemometer.global_counter = value;
}

/* REAL */
double ENV_GUI__anemometer_temperature_celsius_Get(ENV_GUI* root)
{
    return (*root).anemometer.temperature_celsius;
}

/* REAL */
void ENV_GUI__anemometer_temperature_celsius_Set(ENV_GUI* root, double value)
{
    (*root).anemometer.temperature_celsius = value;
}

/* ENUMERATED */
int ENV_GUI__anemometer_temperature_validity_Get(ENV_GUI* root)
{
    return (*root).anemometer.temperature_validity;
}

/* ENUMERATED */
void ENV_GUI__anemometer_temperature_validity_Set(ENV_GUI* root, int value)
{
    (*root).anemometer.temperature_validity = value;
}

/* Field heater selector */
Heater_Data* ENV_GUI__heater_Get(ENV_GUI* root)
{
    return &(*root).heater;
}

/* REAL */
double ENV_GUI__heater_power_watts_Get(ENV_GUI* root)
{
    return (*root).heater.power_watts;
}

/* REAL */
void ENV_GUI__heater_power_watts_Set(ENV_GUI* root, double value)
{
    (*root).heater.power_watts = value;
}

/* ENUMERATED */
int ENV_GUI__heater_validity_Get(ENV_GUI* root)
{
    return (*root).heater.validity;
}

/* ENUMERATED */
void ENV_GUI__heater_validity_Set(ENV_GUI* root, int value)
{
    (*root).heater.validity = value;
}

/* INTEGER */
asn1SccSint T_Int32__Get(T_Int32* root)
{
    return (*root);
}

/* INTEGER */
void T_Int32__Set(T_Int32* root, asn1SccSint value)
{
    (*root) = value;
}

/* INTEGER */
asn1SccSint T_UInt32__Get(T_UInt32* root)
{
    return (*root);
}

/* INTEGER */
void T_UInt32__Set(T_UInt32* root, asn1SccSint value)
{
    (*root) = value;
}

/* INTEGER */
asn1SccSint T_Int8__Get(T_Int8* root)
{
    return (*root);
}

/* INTEGER */
void T_Int8__Set(T_Int8* root, asn1SccSint value)
{
    (*root) = value;
}

/* INTEGER */
asn1SccSint T_UInt8__Get(T_UInt8* root)
{
    return (*root);
}

/* INTEGER */
void T_UInt8__Set(T_UInt8* root, asn1SccSint value)
{
    (*root) = value;
}

/* BOOLEAN */
flag T_Boolean__Get(T_Boolean* root)
{
    return (*root);
}

/* BOOLEAN */
void T_Boolean__Set(T_Boolean* root, flag value)
{
    (*root) = value;
}

/* Helper functions for NATIVE encodings */

void SetDataFor_T_Int16(void *dest, void *src)
{
    memcpy(dest, src, sizeof(T_Int16));
}

byte* MovePtrBySizeOf_T_Int16(byte *pData)
{
    return pData + sizeof(T_Int16);
}

byte* CreateInstanceOf_T_Int16() {
    T_Int16 *p = (T_Int16*)malloc(sizeof(T_Int16));
    T_Int16_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_T_Int16(byte *pData) {
    free(pData);
}

void SetDataFor_T_UInt16(void *dest, void *src)
{
    memcpy(dest, src, sizeof(T_UInt16));
}

byte* MovePtrBySizeOf_T_UInt16(byte *pData)
{
    return pData + sizeof(T_UInt16);
}

byte* CreateInstanceOf_T_UInt16() {
    T_UInt16 *p = (T_UInt16*)malloc(sizeof(T_UInt16));
    T_UInt16_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_T_UInt16(byte *pData) {
    free(pData);
}

void SetDataFor_T_UInt64(void *dest, void *src)
{
    memcpy(dest, src, sizeof(T_UInt64));
}

byte* MovePtrBySizeOf_T_UInt64(byte *pData)
{
    return pData + sizeof(T_UInt64);
}

byte* CreateInstanceOf_T_UInt64() {
    T_UInt64 *p = (T_UInt64*)malloc(sizeof(T_UInt64));
    T_UInt64_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_T_UInt64(byte *pData) {
    free(pData);
}

void SetDataFor_T_Float(void *dest, void *src)
{
    memcpy(dest, src, sizeof(T_Float));
}

byte* MovePtrBySizeOf_T_Float(byte *pData)
{
    return pData + sizeof(T_Float);
}

byte* CreateInstanceOf_T_Float() {
    T_Float *p = (T_Float*)malloc(sizeof(T_Float));
    T_Float_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_T_Float(byte *pData) {
    free(pData);
}

void SetDataFor_T_Double(void *dest, void *src)
{
    memcpy(dest, src, sizeof(T_Double));
}

byte* MovePtrBySizeOf_T_Double(byte *pData)
{
    return pData + sizeof(T_Double);
}

byte* CreateInstanceOf_T_Double() {
    T_Double *p = (T_Double*)malloc(sizeof(T_Double));
    T_Double_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_T_Double(byte *pData) {
    free(pData);
}

void SetDataFor_File_Name(void *dest, void *src)
{
    memcpy(dest, src, sizeof(File_Name));
}

byte* MovePtrBySizeOf_File_Name(byte *pData)
{
    return pData + sizeof(File_Name);
}

byte* CreateInstanceOf_File_Name() {
    File_Name *p = (File_Name*)malloc(sizeof(File_Name));
    File_Name_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_File_Name(byte *pData) {
    free(pData);
}

void SetDataFor_Content_Validity(void *dest, void *src)
{
    memcpy(dest, src, sizeof(Content_Validity));
}

byte* MovePtrBySizeOf_Content_Validity(byte *pData)
{
    return pData + sizeof(Content_Validity);
}

byte* CreateInstanceOf_Content_Validity() {
    Content_Validity *p = (Content_Validity*)malloc(sizeof(Content_Validity));
    Content_Validity_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_Content_Validity(byte *pData) {
    free(pData);
}

void SetDataFor_SPI_ID(void *dest, void *src)
{
    memcpy(dest, src, sizeof(SPI_ID));
}

byte* MovePtrBySizeOf_SPI_ID(byte *pData)
{
    return pData + sizeof(SPI_ID);
}

byte* CreateInstanceOf_SPI_ID() {
    SPI_ID *p = (SPI_ID*)malloc(sizeof(SPI_ID));
    SPI_ID_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_SPI_ID(byte *pData) {
    free(pData);
}

void SetDataFor_I2C_ID(void *dest, void *src)
{
    memcpy(dest, src, sizeof(I2C_ID));
}

byte* MovePtrBySizeOf_I2C_ID(byte *pData)
{
    return pData + sizeof(I2C_ID);
}

byte* CreateInstanceOf_I2C_ID() {
    I2C_ID *p = (I2C_ID*)malloc(sizeof(I2C_ID));
    I2C_ID_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_I2C_ID(byte *pData) {
    free(pData);
}

void SetDataFor_GPS_PVT(void *dest, void *src)
{
    memcpy(dest, src, sizeof(GPS_PVT));
}

byte* MovePtrBySizeOf_GPS_PVT(byte *pData)
{
    return pData + sizeof(GPS_PVT);
}

byte* CreateInstanceOf_GPS_PVT() {
    GPS_PVT *p = (GPS_PVT*)malloc(sizeof(GPS_PVT));
    GPS_PVT_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_GPS_PVT(byte *pData) {
    free(pData);
}

void SetDataFor_MGT_Raw_Data(void *dest, void *src)
{
    memcpy(dest, src, sizeof(MGT_Raw_Data));
}

byte* MovePtrBySizeOf_MGT_Raw_Data(byte *pData)
{
    return pData + sizeof(MGT_Raw_Data);
}

byte* CreateInstanceOf_MGT_Raw_Data() {
    MGT_Raw_Data *p = (MGT_Raw_Data*)malloc(sizeof(MGT_Raw_Data));
    MGT_Raw_Data_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_MGT_Raw_Data(byte *pData) {
    free(pData);
}

void SetDataFor_MGT_MilliGauss_Data(void *dest, void *src)
{
    memcpy(dest, src, sizeof(MGT_MilliGauss_Data));
}

byte* MovePtrBySizeOf_MGT_MilliGauss_Data(byte *pData)
{
    return pData + sizeof(MGT_MilliGauss_Data);
}

byte* CreateInstanceOf_MGT_MilliGauss_Data() {
    MGT_MilliGauss_Data *p = (MGT_MilliGauss_Data*)malloc(sizeof(MGT_MilliGauss_Data));
    MGT_MilliGauss_Data_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_MGT_MilliGauss_Data(byte *pData) {
    free(pData);
}

void SetDataFor_ACC_Raw_Data(void *dest, void *src)
{
    memcpy(dest, src, sizeof(ACC_Raw_Data));
}

byte* MovePtrBySizeOf_ACC_Raw_Data(byte *pData)
{
    return pData + sizeof(ACC_Raw_Data);
}

byte* CreateInstanceOf_ACC_Raw_Data() {
    ACC_Raw_Data *p = (ACC_Raw_Data*)malloc(sizeof(ACC_Raw_Data));
    ACC_Raw_Data_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_ACC_Raw_Data(byte *pData) {
    free(pData);
}

void SetDataFor_ACC_MilliG_Data(void *dest, void *src)
{
    memcpy(dest, src, sizeof(ACC_MilliG_Data));
}

byte* MovePtrBySizeOf_ACC_MilliG_Data(byte *pData)
{
    return pData + sizeof(ACC_MilliG_Data);
}

byte* CreateInstanceOf_ACC_MilliG_Data() {
    ACC_MilliG_Data *p = (ACC_MilliG_Data*)malloc(sizeof(ACC_MilliG_Data));
    ACC_MilliG_Data_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_ACC_MilliG_Data(byte *pData) {
    free(pData);
}

void SetDataFor_GYRO_Raw_Data(void *dest, void *src)
{
    memcpy(dest, src, sizeof(GYRO_Raw_Data));
}

byte* MovePtrBySizeOf_GYRO_Raw_Data(byte *pData)
{
    return pData + sizeof(GYRO_Raw_Data);
}

byte* CreateInstanceOf_GYRO_Raw_Data() {
    GYRO_Raw_Data *p = (GYRO_Raw_Data*)malloc(sizeof(GYRO_Raw_Data));
    GYRO_Raw_Data_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_GYRO_Raw_Data(byte *pData) {
    free(pData);
}

void SetDataFor_GYRO_MilliDPS_Data(void *dest, void *src)
{
    memcpy(dest, src, sizeof(GYRO_MilliDPS_Data));
}

byte* MovePtrBySizeOf_GYRO_MilliDPS_Data(byte *pData)
{
    return pData + sizeof(GYRO_MilliDPS_Data);
}

byte* CreateInstanceOf_GYRO_MilliDPS_Data() {
    GYRO_MilliDPS_Data *p = (GYRO_MilliDPS_Data*)malloc(sizeof(GYRO_MilliDPS_Data));
    GYRO_MilliDPS_Data_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_GYRO_MilliDPS_Data(byte *pData) {
    free(pData);
}

void SetDataFor_IMU_All_Data(void *dest, void *src)
{
    memcpy(dest, src, sizeof(IMU_All_Data));
}

byte* MovePtrBySizeOf_IMU_All_Data(byte *pData)
{
    return pData + sizeof(IMU_All_Data);
}

byte* CreateInstanceOf_IMU_All_Data() {
    IMU_All_Data *p = (IMU_All_Data*)malloc(sizeof(IMU_All_Data));
    IMU_All_Data_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_IMU_All_Data(byte *pData) {
    free(pData);
}

void SetDataFor_TC74s_I2CBuses(void *dest, void *src)
{
    memcpy(dest, src, sizeof(TC74s_I2CBuses));
}

byte* MovePtrBySizeOf_TC74s_I2CBuses(byte *pData)
{
    return pData + sizeof(TC74s_I2CBuses);
}

byte* CreateInstanceOf_TC74s_I2CBuses() {
    TC74s_I2CBuses *p = (TC74s_I2CBuses*)malloc(sizeof(TC74s_I2CBuses));
    TC74s_I2CBuses_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_TC74s_I2CBuses(byte *pData) {
    free(pData);
}

void SetDataFor_TC74s_All_Data(void *dest, void *src)
{
    memcpy(dest, src, sizeof(TC74s_All_Data));
}

byte* MovePtrBySizeOf_TC74s_All_Data(byte *pData)
{
    return pData + sizeof(TC74s_All_Data);
}

byte* CreateInstanceOf_TC74s_All_Data() {
    TC74s_All_Data *p = (TC74s_All_Data*)malloc(sizeof(TC74s_All_Data));
    TC74s_All_Data_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_TC74s_All_Data(byte *pData) {
    free(pData);
}

void SetDataFor_PT1000s_Channels(void *dest, void *src)
{
    memcpy(dest, src, sizeof(PT1000s_Channels));
}

byte* MovePtrBySizeOf_PT1000s_Channels(byte *pData)
{
    return pData + sizeof(PT1000s_Channels);
}

byte* CreateInstanceOf_PT1000s_Channels() {
    PT1000s_Channels *p = (PT1000s_Channels*)malloc(sizeof(PT1000s_Channels));
    PT1000s_Channels_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_PT1000s_Channels(byte *pData) {
    free(pData);
}

void SetDataFor_PT1000s_Raw_Data(void *dest, void *src)
{
    memcpy(dest, src, sizeof(PT1000s_Raw_Data));
}

byte* MovePtrBySizeOf_PT1000s_Raw_Data(byte *pData)
{
    return pData + sizeof(PT1000s_Raw_Data);
}

byte* CreateInstanceOf_PT1000s_Raw_Data() {
    PT1000s_Raw_Data *p = (PT1000s_Raw_Data*)malloc(sizeof(PT1000s_Raw_Data));
    PT1000s_Raw_Data_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_PT1000s_Raw_Data(byte *pData) {
    free(pData);
}

void SetDataFor_PT1000s_Celsius_Data(void *dest, void *src)
{
    memcpy(dest, src, sizeof(PT1000s_Celsius_Data));
}

byte* MovePtrBySizeOf_PT1000s_Celsius_Data(byte *pData)
{
    return pData + sizeof(PT1000s_Celsius_Data);
}

byte* CreateInstanceOf_PT1000s_Celsius_Data() {
    PT1000s_Celsius_Data *p = (PT1000s_Celsius_Data*)malloc(sizeof(PT1000s_Celsius_Data));
    PT1000s_Celsius_Data_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_PT1000s_Celsius_Data(byte *pData) {
    free(pData);
}

void SetDataFor_PT1000s_All_Data(void *dest, void *src)
{
    memcpy(dest, src, sizeof(PT1000s_All_Data));
}

byte* MovePtrBySizeOf_PT1000s_All_Data(byte *pData)
{
    return pData + sizeof(PT1000s_All_Data);
}

byte* CreateInstanceOf_PT1000s_All_Data() {
    PT1000s_All_Data *p = (PT1000s_All_Data*)malloc(sizeof(PT1000s_All_Data));
    PT1000s_All_Data_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_PT1000s_All_Data(byte *pData) {
    free(pData);
}

void SetDataFor_PS_Calibration_Data(void *dest, void *src)
{
    memcpy(dest, src, sizeof(PS_Calibration_Data));
}

byte* MovePtrBySizeOf_PS_Calibration_Data(byte *pData)
{
    return pData + sizeof(PS_Calibration_Data);
}

byte* CreateInstanceOf_PS_Calibration_Data() {
    PS_Calibration_Data *p = (PS_Calibration_Data*)malloc(sizeof(PS_Calibration_Data));
    PS_Calibration_Data_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_PS_Calibration_Data(byte *pData) {
    free(pData);
}

void SetDataFor_PS_Raw_Data(void *dest, void *src)
{
    memcpy(dest, src, sizeof(PS_Raw_Data));
}

byte* MovePtrBySizeOf_PS_Raw_Data(byte *pData)
{
    return pData + sizeof(PS_Raw_Data);
}

byte* CreateInstanceOf_PS_Raw_Data() {
    PS_Raw_Data *p = (PS_Raw_Data*)malloc(sizeof(PS_Raw_Data));
    PS_Raw_Data_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_PS_Raw_Data(byte *pData) {
    free(pData);
}

void SetDataFor_PS_Processed_Data(void *dest, void *src)
{
    memcpy(dest, src, sizeof(PS_Processed_Data));
}

byte* MovePtrBySizeOf_PS_Processed_Data(byte *pData)
{
    return pData + sizeof(PS_Processed_Data);
}

byte* CreateInstanceOf_PS_Processed_Data() {
    PS_Processed_Data *p = (PS_Processed_Data*)malloc(sizeof(PS_Processed_Data));
    PS_Processed_Data_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_PS_Processed_Data(byte *pData) {
    free(pData);
}

void SetDataFor_PS_All_Data(void *dest, void *src)
{
    memcpy(dest, src, sizeof(PS_All_Data));
}

byte* MovePtrBySizeOf_PS_All_Data(byte *pData)
{
    return pData + sizeof(PS_All_Data);
}

byte* CreateInstanceOf_PS_All_Data() {
    PS_All_Data *p = (PS_All_Data*)malloc(sizeof(PS_All_Data));
    PS_All_Data_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_PS_All_Data(byte *pData) {
    free(pData);
}

void SetDataFor_Heater_Data(void *dest, void *src)
{
    memcpy(dest, src, sizeof(Heater_Data));
}

byte* MovePtrBySizeOf_Heater_Data(byte *pData)
{
    return pData + sizeof(Heater_Data);
}

byte* CreateInstanceOf_Heater_Data() {
    Heater_Data *p = (Heater_Data*)malloc(sizeof(Heater_Data));
    Heater_Data_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_Heater_Data(byte *pData) {
    free(pData);
}

void SetDataFor_Heater_On_Off(void *dest, void *src)
{
    memcpy(dest, src, sizeof(Heater_On_Off));
}

byte* MovePtrBySizeOf_Heater_On_Off(byte *pData)
{
    return pData + sizeof(Heater_On_Off);
}

byte* CreateInstanceOf_Heater_On_Off() {
    Heater_On_Off *p = (Heater_On_Off*)malloc(sizeof(Heater_On_Off));
    Heater_On_Off_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_Heater_On_Off(byte *pData) {
    free(pData);
}

void SetDataFor_OBSW_DP_Data(void *dest, void *src)
{
    memcpy(dest, src, sizeof(OBSW_DP_Data));
}

byte* MovePtrBySizeOf_OBSW_DP_Data(byte *pData)
{
    return pData + sizeof(OBSW_DP_Data);
}

byte* CreateInstanceOf_OBSW_DP_Data() {
    OBSW_DP_Data *p = (OBSW_DP_Data*)malloc(sizeof(OBSW_DP_Data));
    OBSW_DP_Data_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_OBSW_DP_Data(byte *pData) {
    free(pData);
}

void SetDataFor_TM(void *dest, void *src)
{
    memcpy(dest, src, sizeof(TM));
}

byte* MovePtrBySizeOf_TM(byte *pData)
{
    return pData + sizeof(TM);
}

byte* CreateInstanceOf_TM() {
    TM *p = (TM*)malloc(sizeof(TM));
    TM_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_TM(byte *pData) {
    free(pData);
}

void SetDataFor_TC_Heater(void *dest, void *src)
{
    memcpy(dest, src, sizeof(TC_Heater));
}

byte* MovePtrBySizeOf_TC_Heater(byte *pData)
{
    return pData + sizeof(TC_Heater);
}

byte* CreateInstanceOf_TC_Heater() {
    TC_Heater *p = (TC_Heater*)malloc(sizeof(TC_Heater));
    TC_Heater_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_TC_Heater(byte *pData) {
    free(pData);
}

void SetDataFor_HTL_GUI(void *dest, void *src)
{
    memcpy(dest, src, sizeof(HTL_GUI));
}

byte* MovePtrBySizeOf_HTL_GUI(byte *pData)
{
    return pData + sizeof(HTL_GUI);
}

byte* CreateInstanceOf_HTL_GUI() {
    HTL_GUI *p = (HTL_GUI*)malloc(sizeof(HTL_GUI));
    HTL_GUI_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_HTL_GUI(byte *pData) {
    free(pData);
}

void SetDataFor_Date_Time(void *dest, void *src)
{
    memcpy(dest, src, sizeof(Date_Time));
}

byte* MovePtrBySizeOf_Date_Time(byte *pData)
{
    return pData + sizeof(Date_Time);
}

byte* CreateInstanceOf_Date_Time() {
    Date_Time *p = (Date_Time*)malloc(sizeof(Date_Time));
    Date_Time_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_Date_Time(byte *pData) {
    free(pData);
}

void SetDataFor_ATT_GUI(void *dest, void *src)
{
    memcpy(dest, src, sizeof(ATT_GUI));
}

byte* MovePtrBySizeOf_ATT_GUI(byte *pData)
{
    return pData + sizeof(ATT_GUI);
}

byte* CreateInstanceOf_ATT_GUI() {
    ATT_GUI *p = (ATT_GUI*)malloc(sizeof(ATT_GUI));
    ATT_GUI_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_ATT_GUI(byte *pData) {
    free(pData);
}

void SetDataFor_PS_GUI(void *dest, void *src)
{
    memcpy(dest, src, sizeof(PS_GUI));
}

byte* MovePtrBySizeOf_PS_GUI(byte *pData)
{
    return pData + sizeof(PS_GUI);
}

byte* CreateInstanceOf_PS_GUI() {
    PS_GUI *p = (PS_GUI*)malloc(sizeof(PS_GUI));
    PS_GUI_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_PS_GUI(byte *pData) {
    free(pData);
}

void SetDataFor_ENV_GUI(void *dest, void *src)
{
    memcpy(dest, src, sizeof(ENV_GUI));
}

byte* MovePtrBySizeOf_ENV_GUI(byte *pData)
{
    return pData + sizeof(ENV_GUI);
}

byte* CreateInstanceOf_ENV_GUI() {
    ENV_GUI *p = (ENV_GUI*)malloc(sizeof(ENV_GUI));
    ENV_GUI_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_ENV_GUI(byte *pData) {
    free(pData);
}

void SetDataFor_T_Int32(void *dest, void *src)
{
    memcpy(dest, src, sizeof(T_Int32));
}

byte* MovePtrBySizeOf_T_Int32(byte *pData)
{
    return pData + sizeof(T_Int32);
}

byte* CreateInstanceOf_T_Int32() {
    T_Int32 *p = (T_Int32*)malloc(sizeof(T_Int32));
    T_Int32_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_T_Int32(byte *pData) {
    free(pData);
}

void SetDataFor_T_UInt32(void *dest, void *src)
{
    memcpy(dest, src, sizeof(T_UInt32));
}

byte* MovePtrBySizeOf_T_UInt32(byte *pData)
{
    return pData + sizeof(T_UInt32);
}

byte* CreateInstanceOf_T_UInt32() {
    T_UInt32 *p = (T_UInt32*)malloc(sizeof(T_UInt32));
    T_UInt32_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_T_UInt32(byte *pData) {
    free(pData);
}

void SetDataFor_T_Int8(void *dest, void *src)
{
    memcpy(dest, src, sizeof(T_Int8));
}

byte* MovePtrBySizeOf_T_Int8(byte *pData)
{
    return pData + sizeof(T_Int8);
}

byte* CreateInstanceOf_T_Int8() {
    T_Int8 *p = (T_Int8*)malloc(sizeof(T_Int8));
    T_Int8_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_T_Int8(byte *pData) {
    free(pData);
}

void SetDataFor_T_UInt8(void *dest, void *src)
{
    memcpy(dest, src, sizeof(T_UInt8));
}

byte* MovePtrBySizeOf_T_UInt8(byte *pData)
{
    return pData + sizeof(T_UInt8);
}

byte* CreateInstanceOf_T_UInt8() {
    T_UInt8 *p = (T_UInt8*)malloc(sizeof(T_UInt8));
    T_UInt8_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_T_UInt8(byte *pData) {
    free(pData);
}

void SetDataFor_T_Boolean(void *dest, void *src)
{
    memcpy(dest, src, sizeof(T_Boolean));
}

byte* MovePtrBySizeOf_T_Boolean(byte *pData)
{
    return pData + sizeof(T_Boolean);
}

byte* CreateInstanceOf_T_Boolean() {
    T_Boolean *p = (T_Boolean*)malloc(sizeof(T_Boolean));
    T_Boolean_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_T_Boolean(byte *pData) {
    free(pData);
}

void SetDataFor_T_Null_Record(void *dest, void *src)
{
    memcpy(dest, src, sizeof(T_Null_Record));
}

byte* MovePtrBySizeOf_T_Null_Record(byte *pData)
{
    return pData + sizeof(T_Null_Record);
}

byte* CreateInstanceOf_T_Null_Record() {
    T_Null_Record *p = (T_Null_Record*)malloc(sizeof(T_Null_Record));
    T_Null_Record_Initialize(p);
    return (byte*)p;
}

void DestroyInstanceOf_T_Null_Record(byte *pData) {
    free(pData);
}

void SetDataFor_int(void *dest, void *src)
{
    memcpy(dest, src, sizeof(int));
}

byte* MovePtrBySizeOf_int(byte *pData)
{
    return pData + sizeof(int);
}

byte* CreateInstanceOf_int() {
    int *p = (int*)malloc(sizeof(int));
    *p = 0;
    return (byte*)p;
}

void DestroyInstanceOf_int(byte *pData) {
    free(pData);
}

