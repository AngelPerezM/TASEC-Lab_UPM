#ifdef __unix__
#include <stdio.h>
#endif

#include "PrintTypesAsASN1.h"

#ifdef __linux__
#include <pthread.h>

static pthread_mutex_t g_printing_mutex = PTHREAD_MUTEX_INITIALIZER;

#endif

void PrintASN1T_Int16(const char *paramName, const asn1SccT_Int16 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-Int16 ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData));
    #else
    printf("%d", (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_UInt16(const char *paramName, const asn1SccT_UInt16 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-UInt16 ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData));
    #else
    printf("%d", (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_UInt64(const char *paramName, const asn1SccT_UInt64 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-UInt64 ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData));
    #else
    printf("%d", (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_Float(const char *paramName, const asn1SccT_Float *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-Float ::= ", paramName);
    printf("%s ", paramName);
    printf("%f", (*pData));
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_Double(const char *paramName, const asn1SccT_Double *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-Double ::= ", paramName);
    printf("%s ", paramName);
    printf("%f", (*pData));
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1File_Name(const char *paramName, const asn1SccFile_Name *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s File-Name ::= ", paramName);
    printf("%s ", paramName);
    {
        int i;
        printf("'");
        for(i=0; i<81; i++)
            printf("%02x", (*pData).arr[i]);
        printf("'H");
    }

#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1Content_Validity(const char *paramName, const asn1SccContent_Validity *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s Content-Validity ::= ", paramName);
    printf("%s ", paramName);
    switch((*pData)) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData))");
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1SPI_ID(const char *paramName, const asn1SccSPI_ID *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s SPI-ID ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("bus ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).bus);
    #else
    printf("%d", (*pData).bus);
    #endif
    printf(", ");
    printf("cs ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).cs);
    #else
    printf("%d", (*pData).cs);
    #endif
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1I2C_ID(const char *paramName, const asn1SccI2C_ID *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s I2C-ID ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("bus ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).bus);
    #else
    printf("%d", (*pData).bus);
    #endif
    printf(", ");
    printf("address ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).address);
    #else
    printf("%d", (*pData).address);
    #endif
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1GPS_PVT(const char *paramName, const asn1SccGPS_PVT *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s GPS-PVT ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("mode ");
    switch((*pData).mode) {
    case 0:
        printf("not-seen");
        break;
    case 1:
        printf("no-fix");
        break;
    case 2:
        printf("two-dims");
        break;
    case 3:
        printf("three-dims");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).mode)");
    }
    printf(", ");
    printf("date-and-time ");
    printf("%f", (*pData).date_and_time);
    printf(", ");
    printf("ept ");
    printf("%f", (*pData).ept);
    printf(", ");
    printf("latitude ");
    printf("%f", (*pData).latitude);
    printf(", ");
    printf("epy ");
    printf("%f", (*pData).epy);
    printf(", ");
    printf("longitude ");
    printf("%f", (*pData).longitude);
    printf(", ");
    printf("epx ");
    printf("%f", (*pData).epx);
    printf(", ");
    printf("altitude ");
    printf("%f", (*pData).altitude);
    printf(", ");
    printf("epv ");
    printf("%f", (*pData).epv);
    printf(", ");
    printf("course ");
    printf("%f", (*pData).course);
    printf(", ");
    printf("epd ");
    printf("%f", (*pData).epd);
    printf(", ");
    printf("speed ");
    printf("%f", (*pData).speed);
    printf(", ");
    printf("eps ");
    printf("%f", (*pData).eps);
    printf(", ");
    printf("climb ");
    printf("%f", (*pData).climb);
    printf(", ");
    printf("epc ");
    printf("%f", (*pData).epc);
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1MGT_Raw_Data(const char *paramName, const asn1SccMGT_Raw_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s MGT-Raw-Data ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("x-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).x_axis);
    #else
    printf("%d", (*pData).x_axis);
    #endif
    printf(", ");
    printf("y-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).y_axis);
    #else
    printf("%d", (*pData).y_axis);
    #endif
    printf(", ");
    printf("z-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).z_axis);
    #else
    printf("%d", (*pData).z_axis);
    #endif
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1MGT_MilliGauss_Data(const char *paramName, const asn1SccMGT_MilliGauss_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s MGT-MilliGauss-Data ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("x-axis ");
    printf("%f", (*pData).x_axis);
    printf(", ");
    printf("y-axis ");
    printf("%f", (*pData).y_axis);
    printf(", ");
    printf("z-axis ");
    printf("%f", (*pData).z_axis);
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1ACC_Raw_Data(const char *paramName, const asn1SccACC_Raw_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s ACC-Raw-Data ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("x-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).x_axis);
    #else
    printf("%d", (*pData).x_axis);
    #endif
    printf(", ");
    printf("y-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).y_axis);
    #else
    printf("%d", (*pData).y_axis);
    #endif
    printf(", ");
    printf("z-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).z_axis);
    #else
    printf("%d", (*pData).z_axis);
    #endif
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1ACC_MilliG_Data(const char *paramName, const asn1SccACC_MilliG_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s ACC-MilliG-Data ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("x-axis ");
    printf("%f", (*pData).x_axis);
    printf(", ");
    printf("y-axis ");
    printf("%f", (*pData).y_axis);
    printf(", ");
    printf("z-axis ");
    printf("%f", (*pData).z_axis);
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1GYRO_Raw_Data(const char *paramName, const asn1SccGYRO_Raw_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s GYRO-Raw-Data ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("x-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).x_axis);
    #else
    printf("%d", (*pData).x_axis);
    #endif
    printf(", ");
    printf("y-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).y_axis);
    #else
    printf("%d", (*pData).y_axis);
    #endif
    printf(", ");
    printf("z-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).z_axis);
    #else
    printf("%d", (*pData).z_axis);
    #endif
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1GYRO_MilliDPS_Data(const char *paramName, const asn1SccGYRO_MilliDPS_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s GYRO-MilliDPS-Data ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("x-axis ");
    printf("%f", (*pData).x_axis);
    printf(", ");
    printf("y-axis ");
    printf("%f", (*pData).y_axis);
    printf(", ");
    printf("z-axis ");
    printf("%f", (*pData).z_axis);
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1IMU_All_Data(const char *paramName, const asn1SccIMU_All_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s IMU-All-Data ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("mgt-raw ");
    printf("{");
    printf("x-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).mgt_raw.x_axis);
    #else
    printf("%d", (*pData).mgt_raw.x_axis);
    #endif
    printf(", ");
    printf("y-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).mgt_raw.y_axis);
    #else
    printf("%d", (*pData).mgt_raw.y_axis);
    #endif
    printf(", ");
    printf("z-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).mgt_raw.z_axis);
    #else
    printf("%d", (*pData).mgt_raw.z_axis);
    #endif
    printf("}");
    printf(", ");
    printf("mgt-mgauss ");
    printf("{");
    printf("x-axis ");
    printf("%f", (*pData).mgt_mgauss.x_axis);
    printf(", ");
    printf("y-axis ");
    printf("%f", (*pData).mgt_mgauss.y_axis);
    printf(", ");
    printf("z-axis ");
    printf("%f", (*pData).mgt_mgauss.z_axis);
    printf("}");
    printf(", ");
    printf("accel-raw ");
    printf("{");
    printf("x-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).accel_raw.x_axis);
    #else
    printf("%d", (*pData).accel_raw.x_axis);
    #endif
    printf(", ");
    printf("y-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).accel_raw.y_axis);
    #else
    printf("%d", (*pData).accel_raw.y_axis);
    #endif
    printf(", ");
    printf("z-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).accel_raw.z_axis);
    #else
    printf("%d", (*pData).accel_raw.z_axis);
    #endif
    printf("}");
    printf(", ");
    printf("accel-mg ");
    printf("{");
    printf("x-axis ");
    printf("%f", (*pData).accel_mg.x_axis);
    printf(", ");
    printf("y-axis ");
    printf("%f", (*pData).accel_mg.y_axis);
    printf(", ");
    printf("z-axis ");
    printf("%f", (*pData).accel_mg.z_axis);
    printf("}");
    printf(", ");
    printf("gyro-raw ");
    printf("{");
    printf("x-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).gyro_raw.x_axis);
    #else
    printf("%d", (*pData).gyro_raw.x_axis);
    #endif
    printf(", ");
    printf("y-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).gyro_raw.y_axis);
    #else
    printf("%d", (*pData).gyro_raw.y_axis);
    #endif
    printf(", ");
    printf("z-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).gyro_raw.z_axis);
    #else
    printf("%d", (*pData).gyro_raw.z_axis);
    #endif
    printf("}");
    printf(", ");
    printf("gyro-mdps ");
    printf("{");
    printf("x-axis ");
    printf("%f", (*pData).gyro_mdps.x_axis);
    printf(", ");
    printf("y-axis ");
    printf("%f", (*pData).gyro_mdps.y_axis);
    printf(", ");
    printf("z-axis ");
    printf("%f", (*pData).gyro_mdps.z_axis);
    printf("}");
    printf(", ");
    printf("temp-raw ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).temp_raw);
    #else
    printf("%d", (*pData).temp_raw);
    #endif
    printf(", ");
    printf("temp-celsius ");
    printf("%f", (*pData).temp_celsius);
    printf(", ");
    printf("mgt-valid ");
    switch((*pData).mgt_valid) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).mgt_valid)");
    }
    printf(", ");
    printf("acc-valid ");
    switch((*pData).acc_valid) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).acc_valid)");
    }
    printf(", ");
    printf("gyro-valid ");
    switch((*pData).gyro_valid) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).gyro_valid)");
    }
    printf(", ");
    printf("temp-valid ");
    switch((*pData).temp_valid) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).temp_valid)");
    }
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1TC74s_I2CBuses(const char *paramName, const asn1SccTC74s_I2CBuses *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s TC74s-I2CBuses ::= ", paramName);
    printf("%s ", paramName);
    {
        int i1;
        printf("{");
        for(i1=0; i1<5; i1++) {
            if (i1) 
                printf(",");
            #if WORD_SIZE==8
            printf("%"PRId64, (*pData).arr[i1]);
            #else
            printf("%d", (*pData).arr[i1]);
            #endif
        }
        printf("}");
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1TC74s_All_Data(const char *paramName, const asn1SccTC74s_All_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s TC74s-All-Data ::= ", paramName);
    printf("%s ", paramName);
    {
        int i2;
        printf("{");
        for(i2=0; i2<5; i2++) {
            if (i2) 
                printf(",");
            printf("{");
            printf("temperature ");
            printf("%f", (*pData).arr[i2].temperature);
            printf(", ");
            printf("validity ");
            switch((*pData).arr[i2].validity) {
            case 0:
                printf("valid");
                break;
            case 1:
                printf("invalid");
                break;
            default:
                printf("Invalid value in ENUMERATED ((*pData).arr[i2].validity)");
            }
            printf("}");
        }
        printf("}");
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1PT1000s_Channels(const char *paramName, const asn1SccPT1000s_Channels *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s PT1000s-Channels ::= ", paramName);
    printf("%s ", paramName);
    {
        int i3;
        printf("{");
        for(i3=0; i3<7; i3++) {
            if (i3) 
                printf(",");
            #if WORD_SIZE==8
            printf("%"PRId64, (*pData).arr[i3]);
            #else
            printf("%d", (*pData).arr[i3]);
            #endif
        }
        printf("}");
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1PT1000s_Raw_Data(const char *paramName, const asn1SccPT1000s_Raw_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s PT1000s-Raw-Data ::= ", paramName);
    printf("%s ", paramName);
    {
        int i4;
        printf("{");
        for(i4=0; i4<7; i4++) {
            if (i4) 
                printf(",");
            printf("{");
            printf("vcc-volts ");
            printf("%f", (*pData).arr[i4].vcc_volts);
            printf(", ");
            printf("pt1000 ");
            printf("%f", (*pData).arr[i4].pt1000);
            printf("}");
        }
        printf("}");
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1PT1000s_Celsius_Data(const char *paramName, const asn1SccPT1000s_Celsius_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s PT1000s-Celsius-Data ::= ", paramName);
    printf("%s ", paramName);
    {
        int i5;
        printf("{");
        for(i5=0; i5<7; i5++) {
            if (i5) 
                printf(",");
            printf("%f", (*pData).arr[i5]);
        }
        printf("}");
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1PT1000s_All_Data(const char *paramName, const asn1SccPT1000s_All_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s PT1000s-All-Data ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("raw ");
    {
        int i6;
        printf("{");
        for(i6=0; i6<7; i6++) {
            if (i6) 
                printf(",");
            printf("{");
            printf("vcc-volts ");
            printf("%f", (*pData).raw.arr[i6].vcc_volts);
            printf(", ");
            printf("pt1000 ");
            printf("%f", (*pData).raw.arr[i6].pt1000);
            printf("}");
        }
        printf("}");
    }
    printf(", ");
    printf("celsius ");
    {
        int i7;
        printf("{");
        for(i7=0; i7<7; i7++) {
            if (i7) 
                printf(",");
            printf("%f", (*pData).celsius.arr[i7]);
        }
        printf("}");
    }
    printf(", ");
    printf("validity ");
    {
        int i8;
        printf("{");
        for(i8=0; i8<7; i8++) {
            if (i8) 
                printf(",");
            switch((*pData).validity.arr[i8]) {
            case 0:
                printf("valid");
                break;
            case 1:
                printf("invalid");
                break;
            default:
                printf("Invalid value in ENUMERATED ((*pData).validity.arr[i8])");
            }
        }
        printf("}");
    }
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1PS_Calibration_Data(const char *paramName, const asn1SccPS_Calibration_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s PS-Calibration-Data ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("c1 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).c1);
    #else
    printf("%d", (*pData).c1);
    #endif
    printf(", ");
    printf("c2 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).c2);
    #else
    printf("%d", (*pData).c2);
    #endif
    printf(", ");
    printf("c3 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).c3);
    #else
    printf("%d", (*pData).c3);
    #endif
    printf(", ");
    printf("c4 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).c4);
    #else
    printf("%d", (*pData).c4);
    #endif
    printf(", ");
    printf("c5 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).c5);
    #else
    printf("%d", (*pData).c5);
    #endif
    printf(", ");
    printf("c6 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).c6);
    #else
    printf("%d", (*pData).c6);
    #endif
    printf(", ");
    printf("sens-t1 ");
    printf("%f", (*pData).sens_t1);
    printf(", ");
    printf("off-t1 ");
    printf("%f", (*pData).off_t1);
    printf(", ");
    printf("tcs ");
    printf("%f", (*pData).tcs);
    printf(", ");
    printf("tco ");
    printf("%f", (*pData).tco);
    printf(", ");
    printf("tref ");
    printf("%f", (*pData).tref);
    printf(", ");
    printf("temp-sens ");
    printf("%f", (*pData).temp_sens);
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1PS_Raw_Data(const char *paramName, const asn1SccPS_Raw_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s PS-Raw-Data ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("d1 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).d1);
    #else
    printf("%d", (*pData).d1);
    #endif
    printf(", ");
    printf("d2 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).d2);
    #else
    printf("%d", (*pData).d2);
    #endif
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1PS_Processed_Data(const char *paramName, const asn1SccPS_Processed_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s PS-Processed-Data ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("pressure ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).pressure);
    #else
    printf("%d", (*pData).pressure);
    #endif
    printf(", ");
    printf("temp ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).temp);
    #else
    printf("%d", (*pData).temp);
    #endif
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1PS_All_Data(const char *paramName, const asn1SccPS_All_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s PS-All-Data ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("calib ");
    printf("{");
    printf("c1 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).calib.c1);
    #else
    printf("%d", (*pData).calib.c1);
    #endif
    printf(", ");
    printf("c2 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).calib.c2);
    #else
    printf("%d", (*pData).calib.c2);
    #endif
    printf(", ");
    printf("c3 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).calib.c3);
    #else
    printf("%d", (*pData).calib.c3);
    #endif
    printf(", ");
    printf("c4 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).calib.c4);
    #else
    printf("%d", (*pData).calib.c4);
    #endif
    printf(", ");
    printf("c5 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).calib.c5);
    #else
    printf("%d", (*pData).calib.c5);
    #endif
    printf(", ");
    printf("c6 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).calib.c6);
    #else
    printf("%d", (*pData).calib.c6);
    #endif
    printf(", ");
    printf("sens-t1 ");
    printf("%f", (*pData).calib.sens_t1);
    printf(", ");
    printf("off-t1 ");
    printf("%f", (*pData).calib.off_t1);
    printf(", ");
    printf("tcs ");
    printf("%f", (*pData).calib.tcs);
    printf(", ");
    printf("tco ");
    printf("%f", (*pData).calib.tco);
    printf(", ");
    printf("tref ");
    printf("%f", (*pData).calib.tref);
    printf(", ");
    printf("temp-sens ");
    printf("%f", (*pData).calib.temp_sens);
    printf("}");
    printf(", ");
    printf("raw ");
    printf("{");
    printf("d1 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).raw.d1);
    #else
    printf("%d", (*pData).raw.d1);
    #endif
    printf(", ");
    printf("d2 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).raw.d2);
    #else
    printf("%d", (*pData).raw.d2);
    #endif
    printf("}");
    printf(", ");
    printf("processed ");
    printf("{");
    printf("pressure ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).processed.pressure);
    #else
    printf("%d", (*pData).processed.pressure);
    #endif
    printf(", ");
    printf("temp ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).processed.temp);
    #else
    printf("%d", (*pData).processed.temp);
    #endif
    printf("}");
    printf(", ");
    printf("validity ");
    switch((*pData).validity) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).validity)");
    }
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1Heater_Data(const char *paramName, const asn1SccHeater_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s Heater-Data ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("power-watts ");
    printf("%f", (*pData).power_watts);
    printf(", ");
    printf("validity ");
    switch((*pData).validity) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).validity)");
    }
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1Heater_On_Off(const char *paramName, const asn1SccHeater_On_Off *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s Heater-On-Off ::= ", paramName);
    printf("%s ", paramName);
    switch((*pData)) {
    case 0:
        printf("on");
        break;
    case 1:
        printf("off");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData))");
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1HTL_State(const char *paramName, const asn1SccHTL_State *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s HTL-State ::= ", paramName);
    printf("%s ", paramName);
    switch((*pData)) {
    case 0:
        printf("a1");
        break;
    case 1:
        printf("a2");
        break;
    case 2:
        printf("f1");
        break;
    case 3:
        printf("f2");
        break;
    case 4:
        printf("f3");
        break;
    case 5:
        printf("error");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData))");
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1HTL_Config(const char *paramName, const asn1SccHTL_Config *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s HTL-Config ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("press-5km ");
    printf("%f", (*pData).press_5km);
    printf(", ");
    printf("press-10km ");
    printf("%f", (*pData).press_10km);
    printf(", ");
    printf("press-18km ");
    printf("%f", (*pData).press_18km);
    printf(", ");
    printf("a1-duration-emergency-secs ");
    printf("%f", (*pData).a1_duration_emergency_secs);
    printf(", ");
    printf("a1-duration-max-secs ");
    printf("%f", (*pData).a1_duration_max_secs);
    printf(", ");
    printf("a2-duration-max-secs ");
    printf("%f", (*pData).a2_duration_max_secs);
    printf(", ");
    printf("f1-duration-secs ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).f1_duration_secs);
    #else
    printf("%d", (*pData).f1_duration_secs);
    #endif
    printf(", ");
    printf("f2-duration-secs ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).f2_duration_secs);
    #else
    printf("%d", (*pData).f2_duration_secs);
    #endif
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1OBSW_DP_Data(const char *paramName, const asn1SccOBSW_DP_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s OBSW-DP-Data ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("gps ");
    printf("{");
    printf("data ");
    printf("{");
    printf("mode ");
    switch((*pData).gps.data.mode) {
    case 0:
        printf("not-seen");
        break;
    case 1:
        printf("no-fix");
        break;
    case 2:
        printf("two-dims");
        break;
    case 3:
        printf("three-dims");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).gps.data.mode)");
    }
    printf(", ");
    printf("date-and-time ");
    printf("%f", (*pData).gps.data.date_and_time);
    printf(", ");
    printf("ept ");
    printf("%f", (*pData).gps.data.ept);
    printf(", ");
    printf("latitude ");
    printf("%f", (*pData).gps.data.latitude);
    printf(", ");
    printf("epy ");
    printf("%f", (*pData).gps.data.epy);
    printf(", ");
    printf("longitude ");
    printf("%f", (*pData).gps.data.longitude);
    printf(", ");
    printf("epx ");
    printf("%f", (*pData).gps.data.epx);
    printf(", ");
    printf("altitude ");
    printf("%f", (*pData).gps.data.altitude);
    printf(", ");
    printf("epv ");
    printf("%f", (*pData).gps.data.epv);
    printf(", ");
    printf("course ");
    printf("%f", (*pData).gps.data.course);
    printf(", ");
    printf("epd ");
    printf("%f", (*pData).gps.data.epd);
    printf(", ");
    printf("speed ");
    printf("%f", (*pData).gps.data.speed);
    printf(", ");
    printf("eps ");
    printf("%f", (*pData).gps.data.eps);
    printf(", ");
    printf("climb ");
    printf("%f", (*pData).gps.data.climb);
    printf(", ");
    printf("epc ");
    printf("%f", (*pData).gps.data.epc);
    printf("}");
    printf(", ");
    printf("gps-time ");
    printf("%f", (*pData).gps.gps_time);
    printf(", ");
    printf("mission-time ");
    printf("%f", (*pData).gps.mission_time);
    printf("}");
    printf(", ");
    printf("imu ");
    printf("{");
    printf("data ");
    printf("{");
    printf("mgt-raw ");
    printf("{");
    printf("x-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).imu.data.mgt_raw.x_axis);
    #else
    printf("%d", (*pData).imu.data.mgt_raw.x_axis);
    #endif
    printf(", ");
    printf("y-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).imu.data.mgt_raw.y_axis);
    #else
    printf("%d", (*pData).imu.data.mgt_raw.y_axis);
    #endif
    printf(", ");
    printf("z-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).imu.data.mgt_raw.z_axis);
    #else
    printf("%d", (*pData).imu.data.mgt_raw.z_axis);
    #endif
    printf("}");
    printf(", ");
    printf("mgt-mgauss ");
    printf("{");
    printf("x-axis ");
    printf("%f", (*pData).imu.data.mgt_mgauss.x_axis);
    printf(", ");
    printf("y-axis ");
    printf("%f", (*pData).imu.data.mgt_mgauss.y_axis);
    printf(", ");
    printf("z-axis ");
    printf("%f", (*pData).imu.data.mgt_mgauss.z_axis);
    printf("}");
    printf(", ");
    printf("accel-raw ");
    printf("{");
    printf("x-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).imu.data.accel_raw.x_axis);
    #else
    printf("%d", (*pData).imu.data.accel_raw.x_axis);
    #endif
    printf(", ");
    printf("y-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).imu.data.accel_raw.y_axis);
    #else
    printf("%d", (*pData).imu.data.accel_raw.y_axis);
    #endif
    printf(", ");
    printf("z-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).imu.data.accel_raw.z_axis);
    #else
    printf("%d", (*pData).imu.data.accel_raw.z_axis);
    #endif
    printf("}");
    printf(", ");
    printf("accel-mg ");
    printf("{");
    printf("x-axis ");
    printf("%f", (*pData).imu.data.accel_mg.x_axis);
    printf(", ");
    printf("y-axis ");
    printf("%f", (*pData).imu.data.accel_mg.y_axis);
    printf(", ");
    printf("z-axis ");
    printf("%f", (*pData).imu.data.accel_mg.z_axis);
    printf("}");
    printf(", ");
    printf("gyro-raw ");
    printf("{");
    printf("x-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).imu.data.gyro_raw.x_axis);
    #else
    printf("%d", (*pData).imu.data.gyro_raw.x_axis);
    #endif
    printf(", ");
    printf("y-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).imu.data.gyro_raw.y_axis);
    #else
    printf("%d", (*pData).imu.data.gyro_raw.y_axis);
    #endif
    printf(", ");
    printf("z-axis ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).imu.data.gyro_raw.z_axis);
    #else
    printf("%d", (*pData).imu.data.gyro_raw.z_axis);
    #endif
    printf("}");
    printf(", ");
    printf("gyro-mdps ");
    printf("{");
    printf("x-axis ");
    printf("%f", (*pData).imu.data.gyro_mdps.x_axis);
    printf(", ");
    printf("y-axis ");
    printf("%f", (*pData).imu.data.gyro_mdps.y_axis);
    printf(", ");
    printf("z-axis ");
    printf("%f", (*pData).imu.data.gyro_mdps.z_axis);
    printf("}");
    printf(", ");
    printf("temp-raw ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).imu.data.temp_raw);
    #else
    printf("%d", (*pData).imu.data.temp_raw);
    #endif
    printf(", ");
    printf("temp-celsius ");
    printf("%f", (*pData).imu.data.temp_celsius);
    printf(", ");
    printf("mgt-valid ");
    switch((*pData).imu.data.mgt_valid) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).imu.data.mgt_valid)");
    }
    printf(", ");
    printf("acc-valid ");
    switch((*pData).imu.data.acc_valid) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).imu.data.acc_valid)");
    }
    printf(", ");
    printf("gyro-valid ");
    switch((*pData).imu.data.gyro_valid) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).imu.data.gyro_valid)");
    }
    printf(", ");
    printf("temp-valid ");
    switch((*pData).imu.data.temp_valid) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).imu.data.temp_valid)");
    }
    printf("}");
    printf(", ");
    printf("gps-time ");
    printf("%f", (*pData).imu.gps_time);
    printf(", ");
    printf("mission-time ");
    printf("%f", (*pData).imu.mission_time);
    printf("}");
    printf(", ");
    printf("tc74s ");
    printf("{");
    printf("data ");
    {
        int i9;
        printf("{");
        for(i9=0; i9<5; i9++) {
            if (i9) 
                printf(",");
            printf("{");
            printf("temperature ");
            printf("%f", (*pData).tc74s.data.arr[i9].temperature);
            printf(", ");
            printf("validity ");
            switch((*pData).tc74s.data.arr[i9].validity) {
            case 0:
                printf("valid");
                break;
            case 1:
                printf("invalid");
                break;
            default:
                printf("Invalid value in ENUMERATED ((*pData).tc74s.data.arr[i9].validity)");
            }
            printf("}");
        }
        printf("}");
    }
    printf(", ");
    printf("gps-time ");
    printf("%f", (*pData).tc74s.gps_time);
    printf(", ");
    printf("mission-time ");
    printf("%f", (*pData).tc74s.mission_time);
    printf("}");
    printf(", ");
    printf("pt1000s ");
    printf("{");
    printf("data ");
    printf("{");
    printf("raw ");
    {
        int i10;
        printf("{");
        for(i10=0; i10<7; i10++) {
            if (i10) 
                printf(",");
            printf("{");
            printf("vcc-volts ");
            printf("%f", (*pData).pt1000s.data.raw.arr[i10].vcc_volts);
            printf(", ");
            printf("pt1000 ");
            printf("%f", (*pData).pt1000s.data.raw.arr[i10].pt1000);
            printf("}");
        }
        printf("}");
    }
    printf(", ");
    printf("celsius ");
    {
        int i11;
        printf("{");
        for(i11=0; i11<7; i11++) {
            if (i11) 
                printf(",");
            printf("%f", (*pData).pt1000s.data.celsius.arr[i11]);
        }
        printf("}");
    }
    printf(", ");
    printf("validity ");
    {
        int i12;
        printf("{");
        for(i12=0; i12<7; i12++) {
            if (i12) 
                printf(",");
            switch((*pData).pt1000s.data.validity.arr[i12]) {
            case 0:
                printf("valid");
                break;
            case 1:
                printf("invalid");
                break;
            default:
                printf("Invalid value in ENUMERATED ((*pData).pt1000s.data.validity.arr[i12])");
            }
        }
        printf("}");
    }
    printf("}");
    printf(", ");
    printf("gps-time ");
    printf("%f", (*pData).pt1000s.gps_time);
    printf(", ");
    printf("mission-time ");
    printf("%f", (*pData).pt1000s.mission_time);
    printf("}");
    printf(", ");
    printf("ps1 ");
    printf("{");
    printf("data ");
    printf("{");
    printf("calib ");
    printf("{");
    printf("c1 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps1.data.calib.c1);
    #else
    printf("%d", (*pData).ps1.data.calib.c1);
    #endif
    printf(", ");
    printf("c2 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps1.data.calib.c2);
    #else
    printf("%d", (*pData).ps1.data.calib.c2);
    #endif
    printf(", ");
    printf("c3 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps1.data.calib.c3);
    #else
    printf("%d", (*pData).ps1.data.calib.c3);
    #endif
    printf(", ");
    printf("c4 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps1.data.calib.c4);
    #else
    printf("%d", (*pData).ps1.data.calib.c4);
    #endif
    printf(", ");
    printf("c5 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps1.data.calib.c5);
    #else
    printf("%d", (*pData).ps1.data.calib.c5);
    #endif
    printf(", ");
    printf("c6 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps1.data.calib.c6);
    #else
    printf("%d", (*pData).ps1.data.calib.c6);
    #endif
    printf(", ");
    printf("sens-t1 ");
    printf("%f", (*pData).ps1.data.calib.sens_t1);
    printf(", ");
    printf("off-t1 ");
    printf("%f", (*pData).ps1.data.calib.off_t1);
    printf(", ");
    printf("tcs ");
    printf("%f", (*pData).ps1.data.calib.tcs);
    printf(", ");
    printf("tco ");
    printf("%f", (*pData).ps1.data.calib.tco);
    printf(", ");
    printf("tref ");
    printf("%f", (*pData).ps1.data.calib.tref);
    printf(", ");
    printf("temp-sens ");
    printf("%f", (*pData).ps1.data.calib.temp_sens);
    printf("}");
    printf(", ");
    printf("raw ");
    printf("{");
    printf("d1 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps1.data.raw.d1);
    #else
    printf("%d", (*pData).ps1.data.raw.d1);
    #endif
    printf(", ");
    printf("d2 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps1.data.raw.d2);
    #else
    printf("%d", (*pData).ps1.data.raw.d2);
    #endif
    printf("}");
    printf(", ");
    printf("processed ");
    printf("{");
    printf("pressure ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps1.data.processed.pressure);
    #else
    printf("%d", (*pData).ps1.data.processed.pressure);
    #endif
    printf(", ");
    printf("temp ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps1.data.processed.temp);
    #else
    printf("%d", (*pData).ps1.data.processed.temp);
    #endif
    printf("}");
    printf(", ");
    printf("validity ");
    switch((*pData).ps1.data.validity) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).ps1.data.validity)");
    }
    printf("}");
    printf(", ");
    printf("gps-time ");
    printf("%f", (*pData).ps1.gps_time);
    printf(", ");
    printf("mission-time ");
    printf("%f", (*pData).ps1.mission_time);
    printf("}");
    printf(", ");
    printf("ps2 ");
    printf("{");
    printf("data ");
    printf("{");
    printf("calib ");
    printf("{");
    printf("c1 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps2.data.calib.c1);
    #else
    printf("%d", (*pData).ps2.data.calib.c1);
    #endif
    printf(", ");
    printf("c2 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps2.data.calib.c2);
    #else
    printf("%d", (*pData).ps2.data.calib.c2);
    #endif
    printf(", ");
    printf("c3 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps2.data.calib.c3);
    #else
    printf("%d", (*pData).ps2.data.calib.c3);
    #endif
    printf(", ");
    printf("c4 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps2.data.calib.c4);
    #else
    printf("%d", (*pData).ps2.data.calib.c4);
    #endif
    printf(", ");
    printf("c5 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps2.data.calib.c5);
    #else
    printf("%d", (*pData).ps2.data.calib.c5);
    #endif
    printf(", ");
    printf("c6 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps2.data.calib.c6);
    #else
    printf("%d", (*pData).ps2.data.calib.c6);
    #endif
    printf(", ");
    printf("sens-t1 ");
    printf("%f", (*pData).ps2.data.calib.sens_t1);
    printf(", ");
    printf("off-t1 ");
    printf("%f", (*pData).ps2.data.calib.off_t1);
    printf(", ");
    printf("tcs ");
    printf("%f", (*pData).ps2.data.calib.tcs);
    printf(", ");
    printf("tco ");
    printf("%f", (*pData).ps2.data.calib.tco);
    printf(", ");
    printf("tref ");
    printf("%f", (*pData).ps2.data.calib.tref);
    printf(", ");
    printf("temp-sens ");
    printf("%f", (*pData).ps2.data.calib.temp_sens);
    printf("}");
    printf(", ");
    printf("raw ");
    printf("{");
    printf("d1 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps2.data.raw.d1);
    #else
    printf("%d", (*pData).ps2.data.raw.d1);
    #endif
    printf(", ");
    printf("d2 ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps2.data.raw.d2);
    #else
    printf("%d", (*pData).ps2.data.raw.d2);
    #endif
    printf("}");
    printf(", ");
    printf("processed ");
    printf("{");
    printf("pressure ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps2.data.processed.pressure);
    #else
    printf("%d", (*pData).ps2.data.processed.pressure);
    #endif
    printf(", ");
    printf("temp ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps2.data.processed.temp);
    #else
    printf("%d", (*pData).ps2.data.processed.temp);
    #endif
    printf("}");
    printf(", ");
    printf("validity ");
    switch((*pData).ps2.data.validity) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).ps2.data.validity)");
    }
    printf("}");
    printf(", ");
    printf("gps-time ");
    printf("%f", (*pData).ps2.gps_time);
    printf(", ");
    printf("mission-time ");
    printf("%f", (*pData).ps2.mission_time);
    printf("}");
    printf(", ");
    printf("heater1 ");
    printf("{");
    printf("data ");
    printf("{");
    printf("power-watts ");
    printf("%f", (*pData).heater1.data.power_watts);
    printf(", ");
    printf("validity ");
    switch((*pData).heater1.data.validity) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).heater1.data.validity)");
    }
    printf("}");
    printf(", ");
    printf("gps-time ");
    printf("%f", (*pData).heater1.gps_time);
    printf(", ");
    printf("mission-time ");
    printf("%f", (*pData).heater1.mission_time);
    printf("}");
    printf(", ");
    printf("heater2 ");
    printf("{");
    printf("data ");
    printf("{");
    printf("power-watts ");
    printf("%f", (*pData).heater2.data.power_watts);
    printf(", ");
    printf("validity ");
    switch((*pData).heater2.data.validity) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).heater2.data.validity)");
    }
    printf("}");
    printf(", ");
    printf("gps-time ");
    printf("%f", (*pData).heater2.gps_time);
    printf(", ");
    printf("mission-time ");
    printf("%f", (*pData).heater2.mission_time);
    printf("}");
    printf(", ");
    printf("anemometer ");
    printf("{");
    printf("data ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).anemometer.data);
    #else
    printf("%d", (*pData).anemometer.data);
    #endif
    printf(", ");
    printf("gps-time ");
    printf("%f", (*pData).anemometer.gps_time);
    printf(", ");
    printf("mission-time ");
    printf("%f", (*pData).anemometer.mission_time);
    printf("}");
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1OBSW_DP_Filter(const char *paramName, const asn1SccOBSW_DP_Filter *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s OBSW-DP-Filter ::= ", paramName);
    printf("%s ", paramName);
    switch((*pData)) {
    case 0:
        printf("gps");
        break;
    case 1:
        printf("imu");
        break;
    case 2:
        printf("tc74s");
        break;
    case 3:
        printf("pt1000s");
        break;
    case 4:
        printf("ps1");
        break;
    case 5:
        printf("ps2");
        break;
    case 6:
        printf("heater1");
        break;
    case 7:
        printf("heater2");
        break;
    case 8:
        printf("anemometer");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData))");
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1OBSW_DP_SingleData(const char *paramName, const asn1SccOBSW_DP_SingleData *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s OBSW-DP-SingleData ::= ", paramName);
    printf("%s ", paramName);
    if ((*pData).kind == gps_PRESENT) {
        printf("gps:");
        printf("{");
        printf("data ");
        printf("{");
        printf("mode ");
        switch((*pData).u.gps.data.mode) {
        case 0:
            printf("not-seen");
            break;
        case 1:
            printf("no-fix");
            break;
        case 2:
            printf("two-dims");
            break;
        case 3:
            printf("three-dims");
            break;
        default:
            printf("Invalid value in ENUMERATED ((*pData).u.gps.data.mode)");
        }
        printf(", ");
        printf("date-and-time ");
        printf("%f", (*pData).u.gps.data.date_and_time);
        printf(", ");
        printf("ept ");
        printf("%f", (*pData).u.gps.data.ept);
        printf(", ");
        printf("latitude ");
        printf("%f", (*pData).u.gps.data.latitude);
        printf(", ");
        printf("epy ");
        printf("%f", (*pData).u.gps.data.epy);
        printf(", ");
        printf("longitude ");
        printf("%f", (*pData).u.gps.data.longitude);
        printf(", ");
        printf("epx ");
        printf("%f", (*pData).u.gps.data.epx);
        printf(", ");
        printf("altitude ");
        printf("%f", (*pData).u.gps.data.altitude);
        printf(", ");
        printf("epv ");
        printf("%f", (*pData).u.gps.data.epv);
        printf(", ");
        printf("course ");
        printf("%f", (*pData).u.gps.data.course);
        printf(", ");
        printf("epd ");
        printf("%f", (*pData).u.gps.data.epd);
        printf(", ");
        printf("speed ");
        printf("%f", (*pData).u.gps.data.speed);
        printf(", ");
        printf("eps ");
        printf("%f", (*pData).u.gps.data.eps);
        printf(", ");
        printf("climb ");
        printf("%f", (*pData).u.gps.data.climb);
        printf(", ");
        printf("epc ");
        printf("%f", (*pData).u.gps.data.epc);
        printf("}");
        printf(", ");
        printf("gps-time ");
        printf("%f", (*pData).u.gps.gps_time);
        printf(", ");
        printf("mission-time ");
        printf("%f", (*pData).u.gps.mission_time);
        printf("}");
    }
    else if ((*pData).kind == imu_PRESENT) {
        printf("imu:");
        printf("{");
        printf("data ");
        printf("{");
        printf("mgt-raw ");
        printf("{");
        printf("x-axis ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.imu.data.mgt_raw.x_axis);
        #else
        printf("%d", (*pData).u.imu.data.mgt_raw.x_axis);
        #endif
        printf(", ");
        printf("y-axis ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.imu.data.mgt_raw.y_axis);
        #else
        printf("%d", (*pData).u.imu.data.mgt_raw.y_axis);
        #endif
        printf(", ");
        printf("z-axis ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.imu.data.mgt_raw.z_axis);
        #else
        printf("%d", (*pData).u.imu.data.mgt_raw.z_axis);
        #endif
        printf("}");
        printf(", ");
        printf("mgt-mgauss ");
        printf("{");
        printf("x-axis ");
        printf("%f", (*pData).u.imu.data.mgt_mgauss.x_axis);
        printf(", ");
        printf("y-axis ");
        printf("%f", (*pData).u.imu.data.mgt_mgauss.y_axis);
        printf(", ");
        printf("z-axis ");
        printf("%f", (*pData).u.imu.data.mgt_mgauss.z_axis);
        printf("}");
        printf(", ");
        printf("accel-raw ");
        printf("{");
        printf("x-axis ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.imu.data.accel_raw.x_axis);
        #else
        printf("%d", (*pData).u.imu.data.accel_raw.x_axis);
        #endif
        printf(", ");
        printf("y-axis ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.imu.data.accel_raw.y_axis);
        #else
        printf("%d", (*pData).u.imu.data.accel_raw.y_axis);
        #endif
        printf(", ");
        printf("z-axis ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.imu.data.accel_raw.z_axis);
        #else
        printf("%d", (*pData).u.imu.data.accel_raw.z_axis);
        #endif
        printf("}");
        printf(", ");
        printf("accel-mg ");
        printf("{");
        printf("x-axis ");
        printf("%f", (*pData).u.imu.data.accel_mg.x_axis);
        printf(", ");
        printf("y-axis ");
        printf("%f", (*pData).u.imu.data.accel_mg.y_axis);
        printf(", ");
        printf("z-axis ");
        printf("%f", (*pData).u.imu.data.accel_mg.z_axis);
        printf("}");
        printf(", ");
        printf("gyro-raw ");
        printf("{");
        printf("x-axis ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.imu.data.gyro_raw.x_axis);
        #else
        printf("%d", (*pData).u.imu.data.gyro_raw.x_axis);
        #endif
        printf(", ");
        printf("y-axis ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.imu.data.gyro_raw.y_axis);
        #else
        printf("%d", (*pData).u.imu.data.gyro_raw.y_axis);
        #endif
        printf(", ");
        printf("z-axis ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.imu.data.gyro_raw.z_axis);
        #else
        printf("%d", (*pData).u.imu.data.gyro_raw.z_axis);
        #endif
        printf("}");
        printf(", ");
        printf("gyro-mdps ");
        printf("{");
        printf("x-axis ");
        printf("%f", (*pData).u.imu.data.gyro_mdps.x_axis);
        printf(", ");
        printf("y-axis ");
        printf("%f", (*pData).u.imu.data.gyro_mdps.y_axis);
        printf(", ");
        printf("z-axis ");
        printf("%f", (*pData).u.imu.data.gyro_mdps.z_axis);
        printf("}");
        printf(", ");
        printf("temp-raw ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.imu.data.temp_raw);
        #else
        printf("%d", (*pData).u.imu.data.temp_raw);
        #endif
        printf(", ");
        printf("temp-celsius ");
        printf("%f", (*pData).u.imu.data.temp_celsius);
        printf(", ");
        printf("mgt-valid ");
        switch((*pData).u.imu.data.mgt_valid) {
        case 0:
            printf("valid");
            break;
        case 1:
            printf("invalid");
            break;
        default:
            printf("Invalid value in ENUMERATED ((*pData).u.imu.data.mgt_valid)");
        }
        printf(", ");
        printf("acc-valid ");
        switch((*pData).u.imu.data.acc_valid) {
        case 0:
            printf("valid");
            break;
        case 1:
            printf("invalid");
            break;
        default:
            printf("Invalid value in ENUMERATED ((*pData).u.imu.data.acc_valid)");
        }
        printf(", ");
        printf("gyro-valid ");
        switch((*pData).u.imu.data.gyro_valid) {
        case 0:
            printf("valid");
            break;
        case 1:
            printf("invalid");
            break;
        default:
            printf("Invalid value in ENUMERATED ((*pData).u.imu.data.gyro_valid)");
        }
        printf(", ");
        printf("temp-valid ");
        switch((*pData).u.imu.data.temp_valid) {
        case 0:
            printf("valid");
            break;
        case 1:
            printf("invalid");
            break;
        default:
            printf("Invalid value in ENUMERATED ((*pData).u.imu.data.temp_valid)");
        }
        printf("}");
        printf(", ");
        printf("gps-time ");
        printf("%f", (*pData).u.imu.gps_time);
        printf(", ");
        printf("mission-time ");
        printf("%f", (*pData).u.imu.mission_time);
        printf("}");
    }
    else if ((*pData).kind == tc74s_PRESENT) {
        printf("tc74s:");
        printf("{");
        printf("data ");
        {
            int i13;
            printf("{");
            for(i13=0; i13<5; i13++) {
                if (i13) 
                    printf(",");
                printf("{");
                printf("temperature ");
                printf("%f", (*pData).u.tc74s.data.arr[i13].temperature);
                printf(", ");
                printf("validity ");
                switch((*pData).u.tc74s.data.arr[i13].validity) {
                case 0:
                    printf("valid");
                    break;
                case 1:
                    printf("invalid");
                    break;
                default:
                    printf("Invalid value in ENUMERATED ((*pData).u.tc74s.data.arr[i13].validity)");
                }
                printf("}");
            }
            printf("}");
        }
        printf(", ");
        printf("gps-time ");
        printf("%f", (*pData).u.tc74s.gps_time);
        printf(", ");
        printf("mission-time ");
        printf("%f", (*pData).u.tc74s.mission_time);
        printf("}");
    }
    else if ((*pData).kind == pt1000s_PRESENT) {
        printf("pt1000s:");
        printf("{");
        printf("data ");
        printf("{");
        printf("raw ");
        {
            int i14;
            printf("{");
            for(i14=0; i14<7; i14++) {
                if (i14) 
                    printf(",");
                printf("{");
                printf("vcc-volts ");
                printf("%f", (*pData).u.pt1000s.data.raw.arr[i14].vcc_volts);
                printf(", ");
                printf("pt1000 ");
                printf("%f", (*pData).u.pt1000s.data.raw.arr[i14].pt1000);
                printf("}");
            }
            printf("}");
        }
        printf(", ");
        printf("celsius ");
        {
            int i15;
            printf("{");
            for(i15=0; i15<7; i15++) {
                if (i15) 
                    printf(",");
                printf("%f", (*pData).u.pt1000s.data.celsius.arr[i15]);
            }
            printf("}");
        }
        printf(", ");
        printf("validity ");
        {
            int i16;
            printf("{");
            for(i16=0; i16<7; i16++) {
                if (i16) 
                    printf(",");
                switch((*pData).u.pt1000s.data.validity.arr[i16]) {
                case 0:
                    printf("valid");
                    break;
                case 1:
                    printf("invalid");
                    break;
                default:
                    printf("Invalid value in ENUMERATED ((*pData).u.pt1000s.data.validity.arr[i16])");
                }
            }
            printf("}");
        }
        printf("}");
        printf(", ");
        printf("gps-time ");
        printf("%f", (*pData).u.pt1000s.gps_time);
        printf(", ");
        printf("mission-time ");
        printf("%f", (*pData).u.pt1000s.mission_time);
        printf("}");
    }
    else if ((*pData).kind == ps1_PRESENT) {
        printf("ps1:");
        printf("{");
        printf("data ");
        printf("{");
        printf("calib ");
        printf("{");
        printf("c1 ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.ps1.data.calib.c1);
        #else
        printf("%d", (*pData).u.ps1.data.calib.c1);
        #endif
        printf(", ");
        printf("c2 ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.ps1.data.calib.c2);
        #else
        printf("%d", (*pData).u.ps1.data.calib.c2);
        #endif
        printf(", ");
        printf("c3 ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.ps1.data.calib.c3);
        #else
        printf("%d", (*pData).u.ps1.data.calib.c3);
        #endif
        printf(", ");
        printf("c4 ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.ps1.data.calib.c4);
        #else
        printf("%d", (*pData).u.ps1.data.calib.c4);
        #endif
        printf(", ");
        printf("c5 ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.ps1.data.calib.c5);
        #else
        printf("%d", (*pData).u.ps1.data.calib.c5);
        #endif
        printf(", ");
        printf("c6 ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.ps1.data.calib.c6);
        #else
        printf("%d", (*pData).u.ps1.data.calib.c6);
        #endif
        printf(", ");
        printf("sens-t1 ");
        printf("%f", (*pData).u.ps1.data.calib.sens_t1);
        printf(", ");
        printf("off-t1 ");
        printf("%f", (*pData).u.ps1.data.calib.off_t1);
        printf(", ");
        printf("tcs ");
        printf("%f", (*pData).u.ps1.data.calib.tcs);
        printf(", ");
        printf("tco ");
        printf("%f", (*pData).u.ps1.data.calib.tco);
        printf(", ");
        printf("tref ");
        printf("%f", (*pData).u.ps1.data.calib.tref);
        printf(", ");
        printf("temp-sens ");
        printf("%f", (*pData).u.ps1.data.calib.temp_sens);
        printf("}");
        printf(", ");
        printf("raw ");
        printf("{");
        printf("d1 ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.ps1.data.raw.d1);
        #else
        printf("%d", (*pData).u.ps1.data.raw.d1);
        #endif
        printf(", ");
        printf("d2 ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.ps1.data.raw.d2);
        #else
        printf("%d", (*pData).u.ps1.data.raw.d2);
        #endif
        printf("}");
        printf(", ");
        printf("processed ");
        printf("{");
        printf("pressure ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.ps1.data.processed.pressure);
        #else
        printf("%d", (*pData).u.ps1.data.processed.pressure);
        #endif
        printf(", ");
        printf("temp ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.ps1.data.processed.temp);
        #else
        printf("%d", (*pData).u.ps1.data.processed.temp);
        #endif
        printf("}");
        printf(", ");
        printf("validity ");
        switch((*pData).u.ps1.data.validity) {
        case 0:
            printf("valid");
            break;
        case 1:
            printf("invalid");
            break;
        default:
            printf("Invalid value in ENUMERATED ((*pData).u.ps1.data.validity)");
        }
        printf("}");
        printf(", ");
        printf("gps-time ");
        printf("%f", (*pData).u.ps1.gps_time);
        printf(", ");
        printf("mission-time ");
        printf("%f", (*pData).u.ps1.mission_time);
        printf("}");
    }
    else if ((*pData).kind == ps2_PRESENT) {
        printf("ps2:");
        printf("{");
        printf("data ");
        printf("{");
        printf("calib ");
        printf("{");
        printf("c1 ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.ps2.data.calib.c1);
        #else
        printf("%d", (*pData).u.ps2.data.calib.c1);
        #endif
        printf(", ");
        printf("c2 ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.ps2.data.calib.c2);
        #else
        printf("%d", (*pData).u.ps2.data.calib.c2);
        #endif
        printf(", ");
        printf("c3 ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.ps2.data.calib.c3);
        #else
        printf("%d", (*pData).u.ps2.data.calib.c3);
        #endif
        printf(", ");
        printf("c4 ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.ps2.data.calib.c4);
        #else
        printf("%d", (*pData).u.ps2.data.calib.c4);
        #endif
        printf(", ");
        printf("c5 ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.ps2.data.calib.c5);
        #else
        printf("%d", (*pData).u.ps2.data.calib.c5);
        #endif
        printf(", ");
        printf("c6 ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.ps2.data.calib.c6);
        #else
        printf("%d", (*pData).u.ps2.data.calib.c6);
        #endif
        printf(", ");
        printf("sens-t1 ");
        printf("%f", (*pData).u.ps2.data.calib.sens_t1);
        printf(", ");
        printf("off-t1 ");
        printf("%f", (*pData).u.ps2.data.calib.off_t1);
        printf(", ");
        printf("tcs ");
        printf("%f", (*pData).u.ps2.data.calib.tcs);
        printf(", ");
        printf("tco ");
        printf("%f", (*pData).u.ps2.data.calib.tco);
        printf(", ");
        printf("tref ");
        printf("%f", (*pData).u.ps2.data.calib.tref);
        printf(", ");
        printf("temp-sens ");
        printf("%f", (*pData).u.ps2.data.calib.temp_sens);
        printf("}");
        printf(", ");
        printf("raw ");
        printf("{");
        printf("d1 ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.ps2.data.raw.d1);
        #else
        printf("%d", (*pData).u.ps2.data.raw.d1);
        #endif
        printf(", ");
        printf("d2 ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.ps2.data.raw.d2);
        #else
        printf("%d", (*pData).u.ps2.data.raw.d2);
        #endif
        printf("}");
        printf(", ");
        printf("processed ");
        printf("{");
        printf("pressure ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.ps2.data.processed.pressure);
        #else
        printf("%d", (*pData).u.ps2.data.processed.pressure);
        #endif
        printf(", ");
        printf("temp ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.ps2.data.processed.temp);
        #else
        printf("%d", (*pData).u.ps2.data.processed.temp);
        #endif
        printf("}");
        printf(", ");
        printf("validity ");
        switch((*pData).u.ps2.data.validity) {
        case 0:
            printf("valid");
            break;
        case 1:
            printf("invalid");
            break;
        default:
            printf("Invalid value in ENUMERATED ((*pData).u.ps2.data.validity)");
        }
        printf("}");
        printf(", ");
        printf("gps-time ");
        printf("%f", (*pData).u.ps2.gps_time);
        printf(", ");
        printf("mission-time ");
        printf("%f", (*pData).u.ps2.mission_time);
        printf("}");
    }
    else if ((*pData).kind == heater1_PRESENT) {
        printf("heater1:");
        printf("{");
        printf("data ");
        printf("{");
        printf("power-watts ");
        printf("%f", (*pData).u.heater1.data.power_watts);
        printf(", ");
        printf("validity ");
        switch((*pData).u.heater1.data.validity) {
        case 0:
            printf("valid");
            break;
        case 1:
            printf("invalid");
            break;
        default:
            printf("Invalid value in ENUMERATED ((*pData).u.heater1.data.validity)");
        }
        printf("}");
        printf(", ");
        printf("gps-time ");
        printf("%f", (*pData).u.heater1.gps_time);
        printf(", ");
        printf("mission-time ");
        printf("%f", (*pData).u.heater1.mission_time);
        printf("}");
    }
    else if ((*pData).kind == heater2_PRESENT) {
        printf("heater2:");
        printf("{");
        printf("data ");
        printf("{");
        printf("power-watts ");
        printf("%f", (*pData).u.heater2.data.power_watts);
        printf(", ");
        printf("validity ");
        switch((*pData).u.heater2.data.validity) {
        case 0:
            printf("valid");
            break;
        case 1:
            printf("invalid");
            break;
        default:
            printf("Invalid value in ENUMERATED ((*pData).u.heater2.data.validity)");
        }
        printf("}");
        printf(", ");
        printf("gps-time ");
        printf("%f", (*pData).u.heater2.gps_time);
        printf(", ");
        printf("mission-time ");
        printf("%f", (*pData).u.heater2.mission_time);
        printf("}");
    }
    else if ((*pData).kind == anemometer_PRESENT) {
        printf("anemometer:");
        printf("{");
        printf("data ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.anemometer.data);
        #else
        printf("%d", (*pData).u.anemometer.data);
        #endif
        printf(", ");
        printf("gps-time ");
        printf("%f", (*pData).u.anemometer.gps_time);
        printf(", ");
        printf("mission-time ");
        printf("%f", (*pData).u.anemometer.mission_time);
        printf("}");
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1IMU_Queue(const char *paramName, const asn1SccIMU_Queue *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s IMU-Queue ::= ", paramName);
    printf("%s ", paramName);
    {
        int i17;
        printf("{");
        for(i17=0; i17<50; i17++) {
            if (i17) 
                printf(",");
            printf("{");
            printf("data ");
            printf("{");
            printf("mgt-raw ");
            printf("{");
            printf("x-axis ");
            #if WORD_SIZE==8
            printf("%"PRId64, (*pData).arr[i17].data.mgt_raw.x_axis);
            #else
            printf("%d", (*pData).arr[i17].data.mgt_raw.x_axis);
            #endif
            printf(", ");
            printf("y-axis ");
            #if WORD_SIZE==8
            printf("%"PRId64, (*pData).arr[i17].data.mgt_raw.y_axis);
            #else
            printf("%d", (*pData).arr[i17].data.mgt_raw.y_axis);
            #endif
            printf(", ");
            printf("z-axis ");
            #if WORD_SIZE==8
            printf("%"PRId64, (*pData).arr[i17].data.mgt_raw.z_axis);
            #else
            printf("%d", (*pData).arr[i17].data.mgt_raw.z_axis);
            #endif
            printf("}");
            printf(", ");
            printf("mgt-mgauss ");
            printf("{");
            printf("x-axis ");
            printf("%f", (*pData).arr[i17].data.mgt_mgauss.x_axis);
            printf(", ");
            printf("y-axis ");
            printf("%f", (*pData).arr[i17].data.mgt_mgauss.y_axis);
            printf(", ");
            printf("z-axis ");
            printf("%f", (*pData).arr[i17].data.mgt_mgauss.z_axis);
            printf("}");
            printf(", ");
            printf("accel-raw ");
            printf("{");
            printf("x-axis ");
            #if WORD_SIZE==8
            printf("%"PRId64, (*pData).arr[i17].data.accel_raw.x_axis);
            #else
            printf("%d", (*pData).arr[i17].data.accel_raw.x_axis);
            #endif
            printf(", ");
            printf("y-axis ");
            #if WORD_SIZE==8
            printf("%"PRId64, (*pData).arr[i17].data.accel_raw.y_axis);
            #else
            printf("%d", (*pData).arr[i17].data.accel_raw.y_axis);
            #endif
            printf(", ");
            printf("z-axis ");
            #if WORD_SIZE==8
            printf("%"PRId64, (*pData).arr[i17].data.accel_raw.z_axis);
            #else
            printf("%d", (*pData).arr[i17].data.accel_raw.z_axis);
            #endif
            printf("}");
            printf(", ");
            printf("accel-mg ");
            printf("{");
            printf("x-axis ");
            printf("%f", (*pData).arr[i17].data.accel_mg.x_axis);
            printf(", ");
            printf("y-axis ");
            printf("%f", (*pData).arr[i17].data.accel_mg.y_axis);
            printf(", ");
            printf("z-axis ");
            printf("%f", (*pData).arr[i17].data.accel_mg.z_axis);
            printf("}");
            printf(", ");
            printf("gyro-raw ");
            printf("{");
            printf("x-axis ");
            #if WORD_SIZE==8
            printf("%"PRId64, (*pData).arr[i17].data.gyro_raw.x_axis);
            #else
            printf("%d", (*pData).arr[i17].data.gyro_raw.x_axis);
            #endif
            printf(", ");
            printf("y-axis ");
            #if WORD_SIZE==8
            printf("%"PRId64, (*pData).arr[i17].data.gyro_raw.y_axis);
            #else
            printf("%d", (*pData).arr[i17].data.gyro_raw.y_axis);
            #endif
            printf(", ");
            printf("z-axis ");
            #if WORD_SIZE==8
            printf("%"PRId64, (*pData).arr[i17].data.gyro_raw.z_axis);
            #else
            printf("%d", (*pData).arr[i17].data.gyro_raw.z_axis);
            #endif
            printf("}");
            printf(", ");
            printf("gyro-mdps ");
            printf("{");
            printf("x-axis ");
            printf("%f", (*pData).arr[i17].data.gyro_mdps.x_axis);
            printf(", ");
            printf("y-axis ");
            printf("%f", (*pData).arr[i17].data.gyro_mdps.y_axis);
            printf(", ");
            printf("z-axis ");
            printf("%f", (*pData).arr[i17].data.gyro_mdps.z_axis);
            printf("}");
            printf(", ");
            printf("temp-raw ");
            #if WORD_SIZE==8
            printf("%"PRId64, (*pData).arr[i17].data.temp_raw);
            #else
            printf("%d", (*pData).arr[i17].data.temp_raw);
            #endif
            printf(", ");
            printf("temp-celsius ");
            printf("%f", (*pData).arr[i17].data.temp_celsius);
            printf(", ");
            printf("mgt-valid ");
            switch((*pData).arr[i17].data.mgt_valid) {
            case 0:
                printf("valid");
                break;
            case 1:
                printf("invalid");
                break;
            default:
                printf("Invalid value in ENUMERATED ((*pData).arr[i17].data.mgt_valid)");
            }
            printf(", ");
            printf("acc-valid ");
            switch((*pData).arr[i17].data.acc_valid) {
            case 0:
                printf("valid");
                break;
            case 1:
                printf("invalid");
                break;
            default:
                printf("Invalid value in ENUMERATED ((*pData).arr[i17].data.acc_valid)");
            }
            printf(", ");
            printf("gyro-valid ");
            switch((*pData).arr[i17].data.gyro_valid) {
            case 0:
                printf("valid");
                break;
            case 1:
                printf("invalid");
                break;
            default:
                printf("Invalid value in ENUMERATED ((*pData).arr[i17].data.gyro_valid)");
            }
            printf(", ");
            printf("temp-valid ");
            switch((*pData).arr[i17].data.temp_valid) {
            case 0:
                printf("valid");
                break;
            case 1:
                printf("invalid");
                break;
            default:
                printf("Invalid value in ENUMERATED ((*pData).arr[i17].data.temp_valid)");
            }
            printf("}");
            printf(", ");
            printf("gps-time ");
            printf("%f", (*pData).arr[i17].gps_time);
            printf(", ");
            printf("mission-time ");
            printf("%f", (*pData).arr[i17].mission_time);
            printf("}");
        }
        printf("}");
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1TM(const char *paramName, const asn1SccTM *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s TM ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("state-htl ");
    switch((*pData).state_htl) {
    case 0:
        printf("a1");
        break;
    case 1:
        printf("a2");
        break;
    case 2:
        printf("f1");
        break;
    case 3:
        printf("f2");
        break;
    case 4:
        printf("f3");
        break;
    case 5:
        printf("error");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).state_htl)");
    }
    printf(", ");
    printf("heater1 ");
    printf("{");
    printf("power-watts ");
    printf("%f", (*pData).heater1.power_watts);
    printf(", ");
    printf("validity ");
    switch((*pData).heater1.validity) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).heater1.validity)");
    }
    printf("}");
    printf(", ");
    printf("heater2 ");
    printf("{");
    printf("power-watts ");
    printf("%f", (*pData).heater2.power_watts);
    printf(", ");
    printf("validity ");
    switch((*pData).heater2.validity) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).heater2.validity)");
    }
    printf("}");
    printf(", ");
    printf("tc74s ");
    {
        int i18;
        printf("{");
        for(i18=0; i18<5; i18++) {
            if (i18) 
                printf(",");
            printf("{");
            printf("temperature ");
            printf("%f", (*pData).tc74s.arr[i18].temperature);
            printf(", ");
            printf("validity ");
            switch((*pData).tc74s.arr[i18].validity) {
            case 0:
                printf("valid");
                break;
            case 1:
                printf("invalid");
                break;
            default:
                printf("Invalid value in ENUMERATED ((*pData).tc74s.arr[i18].validity)");
            }
            printf("}");
        }
        printf("}");
    }
    printf(", ");
    printf("pt1000s ");
    printf("{");
    printf("raw ");
    {
        int i19;
        printf("{");
        for(i19=0; i19<7; i19++) {
            if (i19) 
                printf(",");
            printf("{");
            printf("vcc-volts ");
            printf("%f", (*pData).pt1000s.raw.arr[i19].vcc_volts);
            printf(", ");
            printf("pt1000 ");
            printf("%f", (*pData).pt1000s.raw.arr[i19].pt1000);
            printf("}");
        }
        printf("}");
    }
    printf(", ");
    printf("celsius ");
    {
        int i20;
        printf("{");
        for(i20=0; i20<7; i20++) {
            if (i20) 
                printf(",");
            printf("%f", (*pData).pt1000s.celsius.arr[i20]);
        }
        printf("}");
    }
    printf(", ");
    printf("validity ");
    {
        int i21;
        printf("{");
        for(i21=0; i21<7; i21++) {
            if (i21) 
                printf(",");
            switch((*pData).pt1000s.validity.arr[i21]) {
            case 0:
                printf("valid");
                break;
            case 1:
                printf("invalid");
                break;
            default:
                printf("Invalid value in ENUMERATED ((*pData).pt1000s.validity.arr[i21])");
            }
        }
        printf("}");
    }
    printf("}");
    printf(", ");
    printf("gps ");
    printf("{");
    printf("mode ");
    switch((*pData).gps.mode) {
    case 0:
        printf("not-seen");
        break;
    case 1:
        printf("no-fix");
        break;
    case 2:
        printf("two-dims");
        break;
    case 3:
        printf("three-dims");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).gps.mode)");
    }
    printf(", ");
    printf("date-and-time ");
    printf("%f", (*pData).gps.date_and_time);
    printf(", ");
    printf("ept ");
    printf("%f", (*pData).gps.ept);
    printf(", ");
    printf("latitude ");
    printf("%f", (*pData).gps.latitude);
    printf(", ");
    printf("epy ");
    printf("%f", (*pData).gps.epy);
    printf(", ");
    printf("longitude ");
    printf("%f", (*pData).gps.longitude);
    printf(", ");
    printf("epx ");
    printf("%f", (*pData).gps.epx);
    printf(", ");
    printf("altitude ");
    printf("%f", (*pData).gps.altitude);
    printf(", ");
    printf("epv ");
    printf("%f", (*pData).gps.epv);
    printf(", ");
    printf("course ");
    printf("%f", (*pData).gps.course);
    printf(", ");
    printf("epd ");
    printf("%f", (*pData).gps.epd);
    printf(", ");
    printf("speed ");
    printf("%f", (*pData).gps.speed);
    printf(", ");
    printf("eps ");
    printf("%f", (*pData).gps.eps);
    printf(", ");
    printf("climb ");
    printf("%f", (*pData).gps.climb);
    printf(", ");
    printf("epc ");
    printf("%f", (*pData).gps.epc);
    printf("}");
    printf(", ");
    printf("imu ");
    printf("{");
    printf("mgt-mgauss ");
    printf("{");
    printf("x-axis ");
    printf("%f", (*pData).imu.mgt_mgauss.x_axis);
    printf(", ");
    printf("y-axis ");
    printf("%f", (*pData).imu.mgt_mgauss.y_axis);
    printf(", ");
    printf("z-axis ");
    printf("%f", (*pData).imu.mgt_mgauss.z_axis);
    printf("}");
    printf(", ");
    printf("accel-mg ");
    printf("{");
    printf("x-axis ");
    printf("%f", (*pData).imu.accel_mg.x_axis);
    printf(", ");
    printf("y-axis ");
    printf("%f", (*pData).imu.accel_mg.y_axis);
    printf(", ");
    printf("z-axis ");
    printf("%f", (*pData).imu.accel_mg.z_axis);
    printf("}");
    printf(", ");
    printf("gyro-mdps ");
    printf("{");
    printf("x-axis ");
    printf("%f", (*pData).imu.gyro_mdps.x_axis);
    printf(", ");
    printf("y-axis ");
    printf("%f", (*pData).imu.gyro_mdps.y_axis);
    printf(", ");
    printf("z-axis ");
    printf("%f", (*pData).imu.gyro_mdps.z_axis);
    printf("}");
    printf(", ");
    printf("temp-celsius ");
    printf("%f", (*pData).imu.temp_celsius);
    printf(", ");
    printf("mgt-valid ");
    switch((*pData).imu.mgt_valid) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).imu.mgt_valid)");
    }
    printf(", ");
    printf("acc-valid ");
    switch((*pData).imu.acc_valid) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).imu.acc_valid)");
    }
    printf(", ");
    printf("gyro-valid ");
    switch((*pData).imu.gyro_valid) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).imu.gyro_valid)");
    }
    printf(", ");
    printf("temp-valid ");
    switch((*pData).imu.temp_valid) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).imu.temp_valid)");
    }
    printf("}");
    printf(", ");
    printf("ps1 ");
    printf("{");
    printf("pressure ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps1.pressure);
    #else
    printf("%d", (*pData).ps1.pressure);
    #endif
    printf(", ");
    printf("temp ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps1.temp);
    #else
    printf("%d", (*pData).ps1.temp);
    #endif
    printf("}");
    printf(", ");
    printf("ps2 ");
    printf("{");
    printf("pressure ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps2.pressure);
    #else
    printf("%d", (*pData).ps2.pressure);
    #endif
    printf(", ");
    printf("temp ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).ps2.temp);
    #else
    printf("%d", (*pData).ps2.temp);
    #endif
    printf("}");
    printf(", ");
    printf("ps1-validity ");
    switch((*pData).ps1_validity) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).ps1_validity)");
    }
    printf(", ");
    printf("ps2-validity ");
    switch((*pData).ps2_validity) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).ps2_validity)");
    }
    printf(", ");
    printf("anemometer ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).anemometer);
    #else
    printf("%d", (*pData).anemometer);
    #endif
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1TC_Heater(const char *paramName, const asn1SccTC_Heater *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s TC-Heater ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("heater ");
    switch((*pData).heater) {
    case 0:
        printf("heater-HTL");
        break;
    case 1:
        printf("heater-anemo");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).heater)");
    }
    printf(", ");
    printf("command ");
    if ((*pData).command.kind == power_manual_PRESENT) {
        printf("power-manual:");
        printf("%f", (*pData).command.u.power_manual);
    }
    else if ((*pData).command.kind == max_min_PRESENT) {
        printf("max-min:");
        switch((*pData).command.u.max_min) {
        case 0:
            printf("max");
            break;
        case 1:
            printf("min");
            break;
        default:
            printf("Invalid value in ENUMERATED ((*pData).command.u.max_min)");
        }
    }
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1TC(const char *paramName, const asn1SccTC *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s TC ::= ", paramName);
    printf("%s ", paramName);
    if ((*pData).kind == heater_commands_PRESENT) {
        printf("heater-commands:");
        printf("{");
        printf("heater-of-HTL ");
        printf("{");
        printf("heater ");
        switch((*pData).u.heater_commands.heater_of_HTL.heater) {
        case 0:
            printf("heater-HTL");
            break;
        case 1:
            printf("heater-anemo");
            break;
        default:
            printf("Invalid value in ENUMERATED ((*pData).u.heater_commands.heater_of_HTL.heater)");
        }
        printf(", ");
        printf("command ");
        if ((*pData).u.heater_commands.heater_of_HTL.command.kind == power_manual_PRESENT) {
            printf("power-manual:");
            printf("%f", (*pData).u.heater_commands.heater_of_HTL.command.u.power_manual);
        }
        else if ((*pData).u.heater_commands.heater_of_HTL.command.kind == max_min_PRESENT) {
            printf("max-min:");
            switch((*pData).u.heater_commands.heater_of_HTL.command.u.max_min) {
            case 0:
                printf("max");
                break;
            case 1:
                printf("min");
                break;
            default:
                printf("Invalid value in ENUMERATED ((*pData).u.heater_commands.heater_of_HTL.command.u.max_min)");
            }
        }
        printf("}");
        printf(", ");
        printf("config-of-HTL ");
        printf("{");
        printf("press-5km ");
        printf("%f", (*pData).u.heater_commands.config_of_HTL.press_5km);
        printf(", ");
        printf("press-10km ");
        printf("%f", (*pData).u.heater_commands.config_of_HTL.press_10km);
        printf(", ");
        printf("press-18km ");
        printf("%f", (*pData).u.heater_commands.config_of_HTL.press_18km);
        printf(", ");
        printf("a1-duration-emergency-secs ");
        printf("%f", (*pData).u.heater_commands.config_of_HTL.a1_duration_emergency_secs);
        printf(", ");
        printf("a1-duration-max-secs ");
        printf("%f", (*pData).u.heater_commands.config_of_HTL.a1_duration_max_secs);
        printf(", ");
        printf("a2-duration-max-secs ");
        printf("%f", (*pData).u.heater_commands.config_of_HTL.a2_duration_max_secs);
        printf(", ");
        printf("f1-duration-secs ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.heater_commands.config_of_HTL.f1_duration_secs);
        #else
        printf("%d", (*pData).u.heater_commands.config_of_HTL.f1_duration_secs);
        #endif
        printf(", ");
        printf("f2-duration-secs ");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.heater_commands.config_of_HTL.f2_duration_secs);
        #else
        printf("%d", (*pData).u.heater_commands.config_of_HTL.f2_duration_secs);
        #endif
        printf("}");
        printf("}");
    }
    else if ((*pData).kind == system_commands_PRESENT) {
        printf("system-commands:");
        switch((*pData).u.system_commands) {
        case 0:
            printf("stop");
            break;
        default:
            printf("Invalid value in ENUMERATED ((*pData).u.system_commands)");
        }
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1HTL_GUI(const char *paramName, const asn1SccHTL_GUI *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s HTL-GUI ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("state ");
    switch((*pData).state) {
    case 0:
        printf("a1");
        break;
    case 1:
        printf("a2");
        break;
    case 2:
        printf("f1");
        break;
    case 3:
        printf("f2");
        break;
    case 4:
        printf("f3");
        break;
    case 5:
        printf("error");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).state)");
    }
    printf(", ");
    printf("heater ");
    printf("{");
    printf("power-watts ");
    printf("%f", (*pData).heater.power_watts);
    printf(", ");
    printf("validity ");
    switch((*pData).heater.validity) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).heater.validity)");
    }
    printf("}");
    printf(", ");
    printf("delta-T ");
    printf("%f", (*pData).delta_T);
    printf(", ");
    printf("pt1000s ");
    printf("{");
    printf("aire-abajo ");
    printf("%f", (*pData).pt1000s.aire_abajo);
    printf(", ");
    printf("aire-arriba ");
    printf("%f", (*pData).pt1000s.aire_arriba);
    printf(", ");
    printf("placa-abajo ");
    printf("%f", (*pData).pt1000s.placa_abajo);
    printf(", ");
    printf("placa-arriba ");
    printf("%f", (*pData).pt1000s.placa_arriba);
    printf(", ");
    printf("infinito ");
    printf("%f", (*pData).pt1000s.infinito);
    printf(", ");
    printf("exterior ");
    printf("%f", (*pData).pt1000s.exterior);
    printf(", ");
    printf("validity ");
    {
        int i22;
        printf("{");
        for(i22=0; i22<6; i22++) {
            if (i22) 
                printf(",");
            switch((*pData).pt1000s.validity.arr[i22]) {
            case 0:
                printf("valid");
                break;
            case 1:
                printf("invalid");
                break;
            default:
                printf("Invalid value in ENUMERATED ((*pData).pt1000s.validity.arr[i22])");
            }
        }
        printf("}");
    }
    printf("}");
    printf(", ");
    printf("tc74s ");
    printf("{");
    printf("x-positive ");
    printf("%f", (*pData).tc74s.x_positive);
    printf(", ");
    printf("x-negative ");
    printf("%f", (*pData).tc74s.x_negative);
    printf(", ");
    printf("y-positive ");
    printf("%f", (*pData).tc74s.y_positive);
    printf(", ");
    printf("y-negative ");
    printf("%f", (*pData).tc74s.y_negative);
    printf(", ");
    printf("z-techo ");
    printf("%f", (*pData).tc74s.z_techo);
    printf(", ");
    printf("validity ");
    {
        int i23;
        printf("{");
        for(i23=0; i23<5; i23++) {
            if (i23) 
                printf(",");
            switch((*pData).tc74s.validity.arr[i23]) {
            case 0:
                printf("valid");
                break;
            case 1:
                printf("invalid");
                break;
            default:
                printf("Invalid value in ENUMERATED ((*pData).tc74s.validity.arr[i23])");
            }
        }
        printf("}");
    }
    printf("}");
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1Date_Time(const char *paramName, const asn1SccDate_Time *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s Date-Time ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("day ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).day);
    #else
    printf("%d", (*pData).day);
    #endif
    printf(", ");
    printf("month ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).month);
    #else
    printf("%d", (*pData).month);
    #endif
    printf(", ");
    printf("year ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).year);
    #else
    printf("%d", (*pData).year);
    #endif
    printf(", ");
    printf("hour ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).hour);
    #else
    printf("%d", (*pData).hour);
    #endif
    printf(", ");
    printf("minute ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).minute);
    #else
    printf("%d", (*pData).minute);
    #endif
    printf(", ");
    printf("second ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).second);
    #else
    printf("%d", (*pData).second);
    #endif
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1ATT_GUI(const char *paramName, const asn1SccATT_GUI *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s ATT-GUI ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("gps ");
    printf("{");
    printf("mode ");
    switch((*pData).gps.mode) {
    case 0:
        printf("not-seen");
        break;
    case 1:
        printf("no-fix");
        break;
    case 2:
        printf("two-dims");
        break;
    case 3:
        printf("three-dims");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).gps.mode)");
    }
    printf(", ");
    printf("date-and-time ");
    printf("%f", (*pData).gps.date_and_time);
    printf(", ");
    printf("ept ");
    printf("%f", (*pData).gps.ept);
    printf(", ");
    printf("latitude ");
    printf("%f", (*pData).gps.latitude);
    printf(", ");
    printf("epy ");
    printf("%f", (*pData).gps.epy);
    printf(", ");
    printf("longitude ");
    printf("%f", (*pData).gps.longitude);
    printf(", ");
    printf("epx ");
    printf("%f", (*pData).gps.epx);
    printf(", ");
    printf("altitude ");
    printf("%f", (*pData).gps.altitude);
    printf(", ");
    printf("epv ");
    printf("%f", (*pData).gps.epv);
    printf(", ");
    printf("course ");
    printf("%f", (*pData).gps.course);
    printf(", ");
    printf("epd ");
    printf("%f", (*pData).gps.epd);
    printf(", ");
    printf("speed ");
    printf("%f", (*pData).gps.speed);
    printf(", ");
    printf("eps ");
    printf("%f", (*pData).gps.eps);
    printf(", ");
    printf("climb ");
    printf("%f", (*pData).gps.climb);
    printf(", ");
    printf("epc ");
    printf("%f", (*pData).gps.epc);
    printf("}");
    printf(", ");
    printf("gps-date-time ");
    printf("{");
    printf("day ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).gps_date_time.day);
    #else
    printf("%d", (*pData).gps_date_time.day);
    #endif
    printf(", ");
    printf("month ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).gps_date_time.month);
    #else
    printf("%d", (*pData).gps_date_time.month);
    #endif
    printf(", ");
    printf("year ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).gps_date_time.year);
    #else
    printf("%d", (*pData).gps_date_time.year);
    #endif
    printf(", ");
    printf("hour ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).gps_date_time.hour);
    #else
    printf("%d", (*pData).gps_date_time.hour);
    #endif
    printf(", ");
    printf("minute ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).gps_date_time.minute);
    #else
    printf("%d", (*pData).gps_date_time.minute);
    #endif
    printf(", ");
    printf("second ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).gps_date_time.second);
    #else
    printf("%d", (*pData).gps_date_time.second);
    #endif
    printf("}");
    printf(", ");
    printf("imu ");
    printf("{");
    printf("mgt-mgauss ");
    printf("{");
    printf("x-axis ");
    printf("%f", (*pData).imu.mgt_mgauss.x_axis);
    printf(", ");
    printf("y-axis ");
    printf("%f", (*pData).imu.mgt_mgauss.y_axis);
    printf(", ");
    printf("z-axis ");
    printf("%f", (*pData).imu.mgt_mgauss.z_axis);
    printf("}");
    printf(", ");
    printf("accel-mg ");
    printf("{");
    printf("x-axis ");
    printf("%f", (*pData).imu.accel_mg.x_axis);
    printf(", ");
    printf("y-axis ");
    printf("%f", (*pData).imu.accel_mg.y_axis);
    printf(", ");
    printf("z-axis ");
    printf("%f", (*pData).imu.accel_mg.z_axis);
    printf("}");
    printf(", ");
    printf("gyro-mdps ");
    printf("{");
    printf("x-axis ");
    printf("%f", (*pData).imu.gyro_mdps.x_axis);
    printf(", ");
    printf("y-axis ");
    printf("%f", (*pData).imu.gyro_mdps.y_axis);
    printf(", ");
    printf("z-axis ");
    printf("%f", (*pData).imu.gyro_mdps.z_axis);
    printf("}");
    printf(", ");
    printf("temp-celsius ");
    printf("%f", (*pData).imu.temp_celsius);
    printf(", ");
    printf("mgt-valid ");
    switch((*pData).imu.mgt_valid) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).imu.mgt_valid)");
    }
    printf(", ");
    printf("acc-valid ");
    switch((*pData).imu.acc_valid) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).imu.acc_valid)");
    }
    printf(", ");
    printf("gyro-valid ");
    switch((*pData).imu.gyro_valid) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).imu.gyro_valid)");
    }
    printf(", ");
    printf("temp-valid ");
    switch((*pData).imu.temp_valid) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).imu.temp_valid)");
    }
    printf("}");
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1PS_GUI(const char *paramName, const asn1SccPS_GUI *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s PS-GUI ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("pressure-mbar ");
    printf("%f", (*pData).pressure_mbar);
    printf(", ");
    printf("temperature-celsius ");
    printf("%f", (*pData).temperature_celsius);
    printf(", ");
    printf("validity ");
    switch((*pData).validity) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).validity)");
    }
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1ENV_GUI(const char *paramName, const asn1SccENV_GUI *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s ENV-GUI ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("pressure-sensor-1 ");
    printf("{");
    printf("pressure-mbar ");
    printf("%f", (*pData).pressure_sensor_1.pressure_mbar);
    printf(", ");
    printf("temperature-celsius ");
    printf("%f", (*pData).pressure_sensor_1.temperature_celsius);
    printf(", ");
    printf("validity ");
    switch((*pData).pressure_sensor_1.validity) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).pressure_sensor_1.validity)");
    }
    printf("}");
    printf(", ");
    printf("pressure-sensor-2 ");
    printf("{");
    printf("pressure-mbar ");
    printf("%f", (*pData).pressure_sensor_2.pressure_mbar);
    printf(", ");
    printf("temperature-celsius ");
    printf("%f", (*pData).pressure_sensor_2.temperature_celsius);
    printf(", ");
    printf("validity ");
    switch((*pData).pressure_sensor_2.validity) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).pressure_sensor_2.validity)");
    }
    printf("}");
    printf(", ");
    printf("anemometer ");
    printf("{");
    printf("global-counter ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).anemometer.global_counter);
    #else
    printf("%d", (*pData).anemometer.global_counter);
    #endif
    printf(", ");
    printf("temperature-celsius ");
    printf("%f", (*pData).anemometer.temperature_celsius);
    printf(", ");
    printf("temperature-validity ");
    switch((*pData).anemometer.temperature_validity) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).anemometer.temperature_validity)");
    }
    printf("}");
    printf(", ");
    printf("heater ");
    printf("{");
    printf("power-watts ");
    printf("%f", (*pData).heater.power_watts);
    printf(", ");
    printf("validity ");
    switch((*pData).heater.validity) {
    case 0:
        printf("valid");
        break;
    case 1:
        printf("invalid");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).heater.validity)");
    }
    printf("}");
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_Int32(const char *paramName, const asn1SccT_Int32 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-Int32 ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData));
    #else
    printf("%d", (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_UInt32(const char *paramName, const asn1SccT_UInt32 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-UInt32 ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData));
    #else
    printf("%d", (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_Int8(const char *paramName, const asn1SccT_Int8 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-Int8 ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData));
    #else
    printf("%d", (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_UInt8(const char *paramName, const asn1SccT_UInt8 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-UInt8 ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData));
    #else
    printf("%d", (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_Boolean(const char *paramName, const asn1SccT_Boolean *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-Boolean ::= ", paramName);
    printf("%s ", paramName);
    printf("%s", (int)(*pData)?"TRUE":"FALSE");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_Null_Record(const char *paramName, const asn1SccT_Null_Record *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-Null-Record ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

