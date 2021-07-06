#ifdef __unix__
#include <stdio.h>
#endif
#include "PrintTypes.h"

#ifdef __linux__
#include <pthread.h>

static pthread_mutex_t g_printing_mutex = PTHREAD_MUTEX_INITIALIZER;

#endif

void PrintT_Int16(const char *paramName, const asn1SccT_Int16 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s %"PRId64"\n", paramName, (*pData));
    #else
    printf("%s %d\n", paramName, (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintT_UInt16(const char *paramName, const asn1SccT_UInt16 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s %"PRId64"\n", paramName, (*pData));
    #else
    printf("%s %d\n", paramName, (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintT_UInt64(const char *paramName, const asn1SccT_UInt64 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s %"PRId64"\n", paramName, (*pData));
    #else
    printf("%s %d\n", paramName, (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintT_Float(const char *paramName, const asn1SccT_Float *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s %f\n", paramName, (*pData));
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintT_Double(const char *paramName, const asn1SccT_Double *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s %f\n", paramName, (*pData));
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintFile_Name(const char *paramName, const asn1SccFile_Name *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    {
        int i;
        printf("%s ", paramName);
        for(i=0; i<81; i++)
            printf("%c", (*pData).arr[i]);
        printf("\n");
    }

#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintContent_Validity(const char *paramName, const asn1SccContent_Validity *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s %d\n", paramName, (int)(*pData));
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintSPI_ID(const char *paramName, const asn1SccSPI_ID *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s::bus %"PRId64"\n", paramName, (*pData).bus);
    #else
    printf("%s::bus %d\n", paramName, (*pData).bus);
    #endif
    #if WORD_SIZE==8
    printf("%s::cs %"PRId64"\n", paramName, (*pData).cs);
    #else
    printf("%s::cs %d\n", paramName, (*pData).cs);
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintI2C_ID(const char *paramName, const asn1SccI2C_ID *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s::bus %"PRId64"\n", paramName, (*pData).bus);
    #else
    printf("%s::bus %d\n", paramName, (*pData).bus);
    #endif
    #if WORD_SIZE==8
    printf("%s::address %"PRId64"\n", paramName, (*pData).address);
    #else
    printf("%s::address %d\n", paramName, (*pData).address);
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintGPS_PVT(const char *paramName, const asn1SccGPS_PVT *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s::mode %d\n", paramName, (int)(*pData).mode);
    printf("%s::date_and_time %f\n", paramName, (*pData).date_and_time);
    printf("%s::ept %f\n", paramName, (*pData).ept);
    printf("%s::latitude %f\n", paramName, (*pData).latitude);
    printf("%s::epy %f\n", paramName, (*pData).epy);
    printf("%s::longitude %f\n", paramName, (*pData).longitude);
    printf("%s::epx %f\n", paramName, (*pData).epx);
    printf("%s::altitude %f\n", paramName, (*pData).altitude);
    printf("%s::epv %f\n", paramName, (*pData).epv);
    printf("%s::course %f\n", paramName, (*pData).course);
    printf("%s::epd %f\n", paramName, (*pData).epd);
    printf("%s::speed %f\n", paramName, (*pData).speed);
    printf("%s::eps %f\n", paramName, (*pData).eps);
    printf("%s::climb %f\n", paramName, (*pData).climb);
    printf("%s::epc %f\n", paramName, (*pData).epc);
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintMGT_Raw_Data(const char *paramName, const asn1SccMGT_Raw_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s::x_axis %"PRId64"\n", paramName, (*pData).x_axis);
    #else
    printf("%s::x_axis %d\n", paramName, (*pData).x_axis);
    #endif
    #if WORD_SIZE==8
    printf("%s::y_axis %"PRId64"\n", paramName, (*pData).y_axis);
    #else
    printf("%s::y_axis %d\n", paramName, (*pData).y_axis);
    #endif
    #if WORD_SIZE==8
    printf("%s::z_axis %"PRId64"\n", paramName, (*pData).z_axis);
    #else
    printf("%s::z_axis %d\n", paramName, (*pData).z_axis);
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintMGT_MilliGauss_Data(const char *paramName, const asn1SccMGT_MilliGauss_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s::x_axis %f\n", paramName, (*pData).x_axis);
    printf("%s::y_axis %f\n", paramName, (*pData).y_axis);
    printf("%s::z_axis %f\n", paramName, (*pData).z_axis);
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintACC_Raw_Data(const char *paramName, const asn1SccACC_Raw_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s::x_axis %"PRId64"\n", paramName, (*pData).x_axis);
    #else
    printf("%s::x_axis %d\n", paramName, (*pData).x_axis);
    #endif
    #if WORD_SIZE==8
    printf("%s::y_axis %"PRId64"\n", paramName, (*pData).y_axis);
    #else
    printf("%s::y_axis %d\n", paramName, (*pData).y_axis);
    #endif
    #if WORD_SIZE==8
    printf("%s::z_axis %"PRId64"\n", paramName, (*pData).z_axis);
    #else
    printf("%s::z_axis %d\n", paramName, (*pData).z_axis);
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintACC_MilliG_Data(const char *paramName, const asn1SccACC_MilliG_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s::x_axis %f\n", paramName, (*pData).x_axis);
    printf("%s::y_axis %f\n", paramName, (*pData).y_axis);
    printf("%s::z_axis %f\n", paramName, (*pData).z_axis);
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintGYRO_Raw_Data(const char *paramName, const asn1SccGYRO_Raw_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s::x_axis %"PRId64"\n", paramName, (*pData).x_axis);
    #else
    printf("%s::x_axis %d\n", paramName, (*pData).x_axis);
    #endif
    #if WORD_SIZE==8
    printf("%s::y_axis %"PRId64"\n", paramName, (*pData).y_axis);
    #else
    printf("%s::y_axis %d\n", paramName, (*pData).y_axis);
    #endif
    #if WORD_SIZE==8
    printf("%s::z_axis %"PRId64"\n", paramName, (*pData).z_axis);
    #else
    printf("%s::z_axis %d\n", paramName, (*pData).z_axis);
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintGYRO_MilliDPS_Data(const char *paramName, const asn1SccGYRO_MilliDPS_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s::x_axis %f\n", paramName, (*pData).x_axis);
    printf("%s::y_axis %f\n", paramName, (*pData).y_axis);
    printf("%s::z_axis %f\n", paramName, (*pData).z_axis);
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintIMU_All_Data(const char *paramName, const asn1SccIMU_All_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s::mgt_raw::x_axis %"PRId64"\n", paramName, (*pData).mgt_raw.x_axis);
    #else
    printf("%s::mgt_raw::x_axis %d\n", paramName, (*pData).mgt_raw.x_axis);
    #endif
    #if WORD_SIZE==8
    printf("%s::mgt_raw::y_axis %"PRId64"\n", paramName, (*pData).mgt_raw.y_axis);
    #else
    printf("%s::mgt_raw::y_axis %d\n", paramName, (*pData).mgt_raw.y_axis);
    #endif
    #if WORD_SIZE==8
    printf("%s::mgt_raw::z_axis %"PRId64"\n", paramName, (*pData).mgt_raw.z_axis);
    #else
    printf("%s::mgt_raw::z_axis %d\n", paramName, (*pData).mgt_raw.z_axis);
    #endif
    printf("%s::mgt_mgauss::x_axis %f\n", paramName, (*pData).mgt_mgauss.x_axis);
    printf("%s::mgt_mgauss::y_axis %f\n", paramName, (*pData).mgt_mgauss.y_axis);
    printf("%s::mgt_mgauss::z_axis %f\n", paramName, (*pData).mgt_mgauss.z_axis);
    #if WORD_SIZE==8
    printf("%s::accel_raw::x_axis %"PRId64"\n", paramName, (*pData).accel_raw.x_axis);
    #else
    printf("%s::accel_raw::x_axis %d\n", paramName, (*pData).accel_raw.x_axis);
    #endif
    #if WORD_SIZE==8
    printf("%s::accel_raw::y_axis %"PRId64"\n", paramName, (*pData).accel_raw.y_axis);
    #else
    printf("%s::accel_raw::y_axis %d\n", paramName, (*pData).accel_raw.y_axis);
    #endif
    #if WORD_SIZE==8
    printf("%s::accel_raw::z_axis %"PRId64"\n", paramName, (*pData).accel_raw.z_axis);
    #else
    printf("%s::accel_raw::z_axis %d\n", paramName, (*pData).accel_raw.z_axis);
    #endif
    printf("%s::accel_mg::x_axis %f\n", paramName, (*pData).accel_mg.x_axis);
    printf("%s::accel_mg::y_axis %f\n", paramName, (*pData).accel_mg.y_axis);
    printf("%s::accel_mg::z_axis %f\n", paramName, (*pData).accel_mg.z_axis);
    #if WORD_SIZE==8
    printf("%s::gyro_raw::x_axis %"PRId64"\n", paramName, (*pData).gyro_raw.x_axis);
    #else
    printf("%s::gyro_raw::x_axis %d\n", paramName, (*pData).gyro_raw.x_axis);
    #endif
    #if WORD_SIZE==8
    printf("%s::gyro_raw::y_axis %"PRId64"\n", paramName, (*pData).gyro_raw.y_axis);
    #else
    printf("%s::gyro_raw::y_axis %d\n", paramName, (*pData).gyro_raw.y_axis);
    #endif
    #if WORD_SIZE==8
    printf("%s::gyro_raw::z_axis %"PRId64"\n", paramName, (*pData).gyro_raw.z_axis);
    #else
    printf("%s::gyro_raw::z_axis %d\n", paramName, (*pData).gyro_raw.z_axis);
    #endif
    printf("%s::gyro_mdps::x_axis %f\n", paramName, (*pData).gyro_mdps.x_axis);
    printf("%s::gyro_mdps::y_axis %f\n", paramName, (*pData).gyro_mdps.y_axis);
    printf("%s::gyro_mdps::z_axis %f\n", paramName, (*pData).gyro_mdps.z_axis);
    #if WORD_SIZE==8
    printf("%s::temp_raw %"PRId64"\n", paramName, (*pData).temp_raw);
    #else
    printf("%s::temp_raw %d\n", paramName, (*pData).temp_raw);
    #endif
    printf("%s::temp_celsius %f\n", paramName, (*pData).temp_celsius);
    printf("%s::mgt_valid %d\n", paramName, (int)(*pData).mgt_valid);
    printf("%s::acc_valid %d\n", paramName, (int)(*pData).acc_valid);
    printf("%s::gyro_valid %d\n", paramName, (int)(*pData).gyro_valid);
    printf("%s::temp_valid %d\n", paramName, (int)(*pData).temp_valid);
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintTC74s_I2CBuses(const char *paramName, const asn1SccTC74s_I2CBuses *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    {
        int i1;
        for(i1=0; i1<5; i1++) {
            #if WORD_SIZE==8
            printf("%s::Elem %"PRId64"\n", paramName, (*pData).arr[i1]);
            #else
            printf("%s::Elem %d\n", paramName, (*pData).arr[i1]);
            #endif
        }
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintTC74s_All_Data(const char *paramName, const asn1SccTC74s_All_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    {
        int i2;
        for(i2=0; i2<5; i2++) {
            printf("%s::Elem::temperature %f\n", paramName, (*pData).arr[i2].temperature);
            printf("%s::Elem::validity %d\n", paramName, (int)(*pData).arr[i2].validity);
        }
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintPT1000s_Channels(const char *paramName, const asn1SccPT1000s_Channels *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    {
        int i3;
        for(i3=0; i3<7; i3++) {
            #if WORD_SIZE==8
            printf("%s::Elem %"PRId64"\n", paramName, (*pData).arr[i3]);
            #else
            printf("%s::Elem %d\n", paramName, (*pData).arr[i3]);
            #endif
        }
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintPT1000s_Raw_Data(const char *paramName, const asn1SccPT1000s_Raw_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    {
        int i4;
        for(i4=0; i4<7; i4++) {
            printf("%s::Elem::vcc_volts %f\n", paramName, (*pData).arr[i4].vcc_volts);
            printf("%s::Elem::pt1000 %f\n", paramName, (*pData).arr[i4].pt1000);
        }
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintPT1000s_Celsius_Data(const char *paramName, const asn1SccPT1000s_Celsius_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    {
        int i5;
        for(i5=0; i5<7; i5++) {
            printf("%s::Elem %f\n", paramName, (*pData).arr[i5]);
        }
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintPT1000s_All_Data(const char *paramName, const asn1SccPT1000s_All_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    {
        int i6;
        for(i6=0; i6<7; i6++) {
            printf("%s::raw::Elem::vcc_volts %f\n", paramName, (*pData).raw.arr[i6].vcc_volts);
            printf("%s::raw::Elem::pt1000 %f\n", paramName, (*pData).raw.arr[i6].pt1000);
        }
    }
    {
        int i7;
        for(i7=0; i7<7; i7++) {
            printf("%s::celsius::Elem %f\n", paramName, (*pData).celsius.arr[i7]);
        }
    }
    {
        int i8;
        for(i8=0; i8<7; i8++) {
            printf("%s::validity::Elem %d\n", paramName, (int)(*pData).validity.arr[i8]);
        }
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintPS_Calibration_Data(const char *paramName, const asn1SccPS_Calibration_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s::c1 %"PRId64"\n", paramName, (*pData).c1);
    #else
    printf("%s::c1 %d\n", paramName, (*pData).c1);
    #endif
    #if WORD_SIZE==8
    printf("%s::c2 %"PRId64"\n", paramName, (*pData).c2);
    #else
    printf("%s::c2 %d\n", paramName, (*pData).c2);
    #endif
    #if WORD_SIZE==8
    printf("%s::c3 %"PRId64"\n", paramName, (*pData).c3);
    #else
    printf("%s::c3 %d\n", paramName, (*pData).c3);
    #endif
    #if WORD_SIZE==8
    printf("%s::c4 %"PRId64"\n", paramName, (*pData).c4);
    #else
    printf("%s::c4 %d\n", paramName, (*pData).c4);
    #endif
    #if WORD_SIZE==8
    printf("%s::c5 %"PRId64"\n", paramName, (*pData).c5);
    #else
    printf("%s::c5 %d\n", paramName, (*pData).c5);
    #endif
    #if WORD_SIZE==8
    printf("%s::c6 %"PRId64"\n", paramName, (*pData).c6);
    #else
    printf("%s::c6 %d\n", paramName, (*pData).c6);
    #endif
    printf("%s::sens_t1 %f\n", paramName, (*pData).sens_t1);
    printf("%s::off_t1 %f\n", paramName, (*pData).off_t1);
    printf("%s::tcs %f\n", paramName, (*pData).tcs);
    printf("%s::tco %f\n", paramName, (*pData).tco);
    printf("%s::tref %f\n", paramName, (*pData).tref);
    printf("%s::temp_sens %f\n", paramName, (*pData).temp_sens);
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintPS_Raw_Data(const char *paramName, const asn1SccPS_Raw_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s::d1 %"PRId64"\n", paramName, (*pData).d1);
    #else
    printf("%s::d1 %d\n", paramName, (*pData).d1);
    #endif
    #if WORD_SIZE==8
    printf("%s::d2 %"PRId64"\n", paramName, (*pData).d2);
    #else
    printf("%s::d2 %d\n", paramName, (*pData).d2);
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintPS_Processed_Data(const char *paramName, const asn1SccPS_Processed_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s::pressure %"PRId64"\n", paramName, (*pData).pressure);
    #else
    printf("%s::pressure %d\n", paramName, (*pData).pressure);
    #endif
    #if WORD_SIZE==8
    printf("%s::temp %"PRId64"\n", paramName, (*pData).temp);
    #else
    printf("%s::temp %d\n", paramName, (*pData).temp);
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintPS_All_Data(const char *paramName, const asn1SccPS_All_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s::calib::c1 %"PRId64"\n", paramName, (*pData).calib.c1);
    #else
    printf("%s::calib::c1 %d\n", paramName, (*pData).calib.c1);
    #endif
    #if WORD_SIZE==8
    printf("%s::calib::c2 %"PRId64"\n", paramName, (*pData).calib.c2);
    #else
    printf("%s::calib::c2 %d\n", paramName, (*pData).calib.c2);
    #endif
    #if WORD_SIZE==8
    printf("%s::calib::c3 %"PRId64"\n", paramName, (*pData).calib.c3);
    #else
    printf("%s::calib::c3 %d\n", paramName, (*pData).calib.c3);
    #endif
    #if WORD_SIZE==8
    printf("%s::calib::c4 %"PRId64"\n", paramName, (*pData).calib.c4);
    #else
    printf("%s::calib::c4 %d\n", paramName, (*pData).calib.c4);
    #endif
    #if WORD_SIZE==8
    printf("%s::calib::c5 %"PRId64"\n", paramName, (*pData).calib.c5);
    #else
    printf("%s::calib::c5 %d\n", paramName, (*pData).calib.c5);
    #endif
    #if WORD_SIZE==8
    printf("%s::calib::c6 %"PRId64"\n", paramName, (*pData).calib.c6);
    #else
    printf("%s::calib::c6 %d\n", paramName, (*pData).calib.c6);
    #endif
    printf("%s::calib::sens_t1 %f\n", paramName, (*pData).calib.sens_t1);
    printf("%s::calib::off_t1 %f\n", paramName, (*pData).calib.off_t1);
    printf("%s::calib::tcs %f\n", paramName, (*pData).calib.tcs);
    printf("%s::calib::tco %f\n", paramName, (*pData).calib.tco);
    printf("%s::calib::tref %f\n", paramName, (*pData).calib.tref);
    printf("%s::calib::temp_sens %f\n", paramName, (*pData).calib.temp_sens);
    #if WORD_SIZE==8
    printf("%s::raw::d1 %"PRId64"\n", paramName, (*pData).raw.d1);
    #else
    printf("%s::raw::d1 %d\n", paramName, (*pData).raw.d1);
    #endif
    #if WORD_SIZE==8
    printf("%s::raw::d2 %"PRId64"\n", paramName, (*pData).raw.d2);
    #else
    printf("%s::raw::d2 %d\n", paramName, (*pData).raw.d2);
    #endif
    #if WORD_SIZE==8
    printf("%s::processed::pressure %"PRId64"\n", paramName, (*pData).processed.pressure);
    #else
    printf("%s::processed::pressure %d\n", paramName, (*pData).processed.pressure);
    #endif
    #if WORD_SIZE==8
    printf("%s::processed::temp %"PRId64"\n", paramName, (*pData).processed.temp);
    #else
    printf("%s::processed::temp %d\n", paramName, (*pData).processed.temp);
    #endif
    printf("%s::validity %d\n", paramName, (int)(*pData).validity);
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintHeater_Data(const char *paramName, const asn1SccHeater_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s::power_watts %f\n", paramName, (*pData).power_watts);
    printf("%s::validity %d\n", paramName, (int)(*pData).validity);
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintHeater_On_Off(const char *paramName, const asn1SccHeater_On_Off *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s %d\n", paramName, (int)(*pData));
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintHTL_State(const char *paramName, const asn1SccHTL_State *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s %d\n", paramName, (int)(*pData));
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintHTL_Config(const char *paramName, const asn1SccHTL_Config *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s::press_5km %f\n", paramName, (*pData).press_5km);
    printf("%s::press_10km %f\n", paramName, (*pData).press_10km);
    printf("%s::press_18km %f\n", paramName, (*pData).press_18km);
    printf("%s::a1_duration_emergency_secs %f\n", paramName, (*pData).a1_duration_emergency_secs);
    printf("%s::a1_duration_max_secs %f\n", paramName, (*pData).a1_duration_max_secs);
    printf("%s::a2_duration_max_secs %f\n", paramName, (*pData).a2_duration_max_secs);
    #if WORD_SIZE==8
    printf("%s::f1_duration_secs %"PRId64"\n", paramName, (*pData).f1_duration_secs);
    #else
    printf("%s::f1_duration_secs %d\n", paramName, (*pData).f1_duration_secs);
    #endif
    #if WORD_SIZE==8
    printf("%s::f2_duration_secs %"PRId64"\n", paramName, (*pData).f2_duration_secs);
    #else
    printf("%s::f2_duration_secs %d\n", paramName, (*pData).f2_duration_secs);
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintOBSW_DP_Data(const char *paramName, const asn1SccOBSW_DP_Data *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s::gps::data::mode %d\n", paramName, (int)(*pData).gps.data.mode);
    printf("%s::gps::data::date_and_time %f\n", paramName, (*pData).gps.data.date_and_time);
    printf("%s::gps::data::ept %f\n", paramName, (*pData).gps.data.ept);
    printf("%s::gps::data::latitude %f\n", paramName, (*pData).gps.data.latitude);
    printf("%s::gps::data::epy %f\n", paramName, (*pData).gps.data.epy);
    printf("%s::gps::data::longitude %f\n", paramName, (*pData).gps.data.longitude);
    printf("%s::gps::data::epx %f\n", paramName, (*pData).gps.data.epx);
    printf("%s::gps::data::altitude %f\n", paramName, (*pData).gps.data.altitude);
    printf("%s::gps::data::epv %f\n", paramName, (*pData).gps.data.epv);
    printf("%s::gps::data::course %f\n", paramName, (*pData).gps.data.course);
    printf("%s::gps::data::epd %f\n", paramName, (*pData).gps.data.epd);
    printf("%s::gps::data::speed %f\n", paramName, (*pData).gps.data.speed);
    printf("%s::gps::data::eps %f\n", paramName, (*pData).gps.data.eps);
    printf("%s::gps::data::climb %f\n", paramName, (*pData).gps.data.climb);
    printf("%s::gps::data::epc %f\n", paramName, (*pData).gps.data.epc);
    printf("%s::gps::gps_time %f\n", paramName, (*pData).gps.gps_time);
    printf("%s::gps::mission_time %f\n", paramName, (*pData).gps.mission_time);
    #if WORD_SIZE==8
    printf("%s::imu::data::mgt_raw::x_axis %"PRId64"\n", paramName, (*pData).imu.data.mgt_raw.x_axis);
    #else
    printf("%s::imu::data::mgt_raw::x_axis %d\n", paramName, (*pData).imu.data.mgt_raw.x_axis);
    #endif
    #if WORD_SIZE==8
    printf("%s::imu::data::mgt_raw::y_axis %"PRId64"\n", paramName, (*pData).imu.data.mgt_raw.y_axis);
    #else
    printf("%s::imu::data::mgt_raw::y_axis %d\n", paramName, (*pData).imu.data.mgt_raw.y_axis);
    #endif
    #if WORD_SIZE==8
    printf("%s::imu::data::mgt_raw::z_axis %"PRId64"\n", paramName, (*pData).imu.data.mgt_raw.z_axis);
    #else
    printf("%s::imu::data::mgt_raw::z_axis %d\n", paramName, (*pData).imu.data.mgt_raw.z_axis);
    #endif
    printf("%s::imu::data::mgt_mgauss::x_axis %f\n", paramName, (*pData).imu.data.mgt_mgauss.x_axis);
    printf("%s::imu::data::mgt_mgauss::y_axis %f\n", paramName, (*pData).imu.data.mgt_mgauss.y_axis);
    printf("%s::imu::data::mgt_mgauss::z_axis %f\n", paramName, (*pData).imu.data.mgt_mgauss.z_axis);
    #if WORD_SIZE==8
    printf("%s::imu::data::accel_raw::x_axis %"PRId64"\n", paramName, (*pData).imu.data.accel_raw.x_axis);
    #else
    printf("%s::imu::data::accel_raw::x_axis %d\n", paramName, (*pData).imu.data.accel_raw.x_axis);
    #endif
    #if WORD_SIZE==8
    printf("%s::imu::data::accel_raw::y_axis %"PRId64"\n", paramName, (*pData).imu.data.accel_raw.y_axis);
    #else
    printf("%s::imu::data::accel_raw::y_axis %d\n", paramName, (*pData).imu.data.accel_raw.y_axis);
    #endif
    #if WORD_SIZE==8
    printf("%s::imu::data::accel_raw::z_axis %"PRId64"\n", paramName, (*pData).imu.data.accel_raw.z_axis);
    #else
    printf("%s::imu::data::accel_raw::z_axis %d\n", paramName, (*pData).imu.data.accel_raw.z_axis);
    #endif
    printf("%s::imu::data::accel_mg::x_axis %f\n", paramName, (*pData).imu.data.accel_mg.x_axis);
    printf("%s::imu::data::accel_mg::y_axis %f\n", paramName, (*pData).imu.data.accel_mg.y_axis);
    printf("%s::imu::data::accel_mg::z_axis %f\n", paramName, (*pData).imu.data.accel_mg.z_axis);
    #if WORD_SIZE==8
    printf("%s::imu::data::gyro_raw::x_axis %"PRId64"\n", paramName, (*pData).imu.data.gyro_raw.x_axis);
    #else
    printf("%s::imu::data::gyro_raw::x_axis %d\n", paramName, (*pData).imu.data.gyro_raw.x_axis);
    #endif
    #if WORD_SIZE==8
    printf("%s::imu::data::gyro_raw::y_axis %"PRId64"\n", paramName, (*pData).imu.data.gyro_raw.y_axis);
    #else
    printf("%s::imu::data::gyro_raw::y_axis %d\n", paramName, (*pData).imu.data.gyro_raw.y_axis);
    #endif
    #if WORD_SIZE==8
    printf("%s::imu::data::gyro_raw::z_axis %"PRId64"\n", paramName, (*pData).imu.data.gyro_raw.z_axis);
    #else
    printf("%s::imu::data::gyro_raw::z_axis %d\n", paramName, (*pData).imu.data.gyro_raw.z_axis);
    #endif
    printf("%s::imu::data::gyro_mdps::x_axis %f\n", paramName, (*pData).imu.data.gyro_mdps.x_axis);
    printf("%s::imu::data::gyro_mdps::y_axis %f\n", paramName, (*pData).imu.data.gyro_mdps.y_axis);
    printf("%s::imu::data::gyro_mdps::z_axis %f\n", paramName, (*pData).imu.data.gyro_mdps.z_axis);
    #if WORD_SIZE==8
    printf("%s::imu::data::temp_raw %"PRId64"\n", paramName, (*pData).imu.data.temp_raw);
    #else
    printf("%s::imu::data::temp_raw %d\n", paramName, (*pData).imu.data.temp_raw);
    #endif
    printf("%s::imu::data::temp_celsius %f\n", paramName, (*pData).imu.data.temp_celsius);
    printf("%s::imu::data::mgt_valid %d\n", paramName, (int)(*pData).imu.data.mgt_valid);
    printf("%s::imu::data::acc_valid %d\n", paramName, (int)(*pData).imu.data.acc_valid);
    printf("%s::imu::data::gyro_valid %d\n", paramName, (int)(*pData).imu.data.gyro_valid);
    printf("%s::imu::data::temp_valid %d\n", paramName, (int)(*pData).imu.data.temp_valid);
    printf("%s::imu::gps_time %f\n", paramName, (*pData).imu.gps_time);
    printf("%s::imu::mission_time %f\n", paramName, (*pData).imu.mission_time);
    {
        int i9;
        for(i9=0; i9<5; i9++) {
            printf("%s::tc74s::data::Elem::temperature %f\n", paramName, (*pData).tc74s.data.arr[i9].temperature);
            printf("%s::tc74s::data::Elem::validity %d\n", paramName, (int)(*pData).tc74s.data.arr[i9].validity);
        }
    }
    printf("%s::tc74s::gps_time %f\n", paramName, (*pData).tc74s.gps_time);
    printf("%s::tc74s::mission_time %f\n", paramName, (*pData).tc74s.mission_time);
    {
        int i10;
        for(i10=0; i10<7; i10++) {
            printf("%s::pt1000s::data::raw::Elem::vcc_volts %f\n", paramName, (*pData).pt1000s.data.raw.arr[i10].vcc_volts);
            printf("%s::pt1000s::data::raw::Elem::pt1000 %f\n", paramName, (*pData).pt1000s.data.raw.arr[i10].pt1000);
        }
    }
    {
        int i11;
        for(i11=0; i11<7; i11++) {
            printf("%s::pt1000s::data::celsius::Elem %f\n", paramName, (*pData).pt1000s.data.celsius.arr[i11]);
        }
    }
    {
        int i12;
        for(i12=0; i12<7; i12++) {
            printf("%s::pt1000s::data::validity::Elem %d\n", paramName, (int)(*pData).pt1000s.data.validity.arr[i12]);
        }
    }
    printf("%s::pt1000s::gps_time %f\n", paramName, (*pData).pt1000s.gps_time);
    printf("%s::pt1000s::mission_time %f\n", paramName, (*pData).pt1000s.mission_time);
    #if WORD_SIZE==8
    printf("%s::ps1::data::calib::c1 %"PRId64"\n", paramName, (*pData).ps1.data.calib.c1);
    #else
    printf("%s::ps1::data::calib::c1 %d\n", paramName, (*pData).ps1.data.calib.c1);
    #endif
    #if WORD_SIZE==8
    printf("%s::ps1::data::calib::c2 %"PRId64"\n", paramName, (*pData).ps1.data.calib.c2);
    #else
    printf("%s::ps1::data::calib::c2 %d\n", paramName, (*pData).ps1.data.calib.c2);
    #endif
    #if WORD_SIZE==8
    printf("%s::ps1::data::calib::c3 %"PRId64"\n", paramName, (*pData).ps1.data.calib.c3);
    #else
    printf("%s::ps1::data::calib::c3 %d\n", paramName, (*pData).ps1.data.calib.c3);
    #endif
    #if WORD_SIZE==8
    printf("%s::ps1::data::calib::c4 %"PRId64"\n", paramName, (*pData).ps1.data.calib.c4);
    #else
    printf("%s::ps1::data::calib::c4 %d\n", paramName, (*pData).ps1.data.calib.c4);
    #endif
    #if WORD_SIZE==8
    printf("%s::ps1::data::calib::c5 %"PRId64"\n", paramName, (*pData).ps1.data.calib.c5);
    #else
    printf("%s::ps1::data::calib::c5 %d\n", paramName, (*pData).ps1.data.calib.c5);
    #endif
    #if WORD_SIZE==8
    printf("%s::ps1::data::calib::c6 %"PRId64"\n", paramName, (*pData).ps1.data.calib.c6);
    #else
    printf("%s::ps1::data::calib::c6 %d\n", paramName, (*pData).ps1.data.calib.c6);
    #endif
    printf("%s::ps1::data::calib::sens_t1 %f\n", paramName, (*pData).ps1.data.calib.sens_t1);
    printf("%s::ps1::data::calib::off_t1 %f\n", paramName, (*pData).ps1.data.calib.off_t1);
    printf("%s::ps1::data::calib::tcs %f\n", paramName, (*pData).ps1.data.calib.tcs);
    printf("%s::ps1::data::calib::tco %f\n", paramName, (*pData).ps1.data.calib.tco);
    printf("%s::ps1::data::calib::tref %f\n", paramName, (*pData).ps1.data.calib.tref);
    printf("%s::ps1::data::calib::temp_sens %f\n", paramName, (*pData).ps1.data.calib.temp_sens);
    #if WORD_SIZE==8
    printf("%s::ps1::data::raw::d1 %"PRId64"\n", paramName, (*pData).ps1.data.raw.d1);
    #else
    printf("%s::ps1::data::raw::d1 %d\n", paramName, (*pData).ps1.data.raw.d1);
    #endif
    #if WORD_SIZE==8
    printf("%s::ps1::data::raw::d2 %"PRId64"\n", paramName, (*pData).ps1.data.raw.d2);
    #else
    printf("%s::ps1::data::raw::d2 %d\n", paramName, (*pData).ps1.data.raw.d2);
    #endif
    #if WORD_SIZE==8
    printf("%s::ps1::data::processed::pressure %"PRId64"\n", paramName, (*pData).ps1.data.processed.pressure);
    #else
    printf("%s::ps1::data::processed::pressure %d\n", paramName, (*pData).ps1.data.processed.pressure);
    #endif
    #if WORD_SIZE==8
    printf("%s::ps1::data::processed::temp %"PRId64"\n", paramName, (*pData).ps1.data.processed.temp);
    #else
    printf("%s::ps1::data::processed::temp %d\n", paramName, (*pData).ps1.data.processed.temp);
    #endif
    printf("%s::ps1::data::validity %d\n", paramName, (int)(*pData).ps1.data.validity);
    printf("%s::ps1::gps_time %f\n", paramName, (*pData).ps1.gps_time);
    printf("%s::ps1::mission_time %f\n", paramName, (*pData).ps1.mission_time);
    #if WORD_SIZE==8
    printf("%s::ps2::data::calib::c1 %"PRId64"\n", paramName, (*pData).ps2.data.calib.c1);
    #else
    printf("%s::ps2::data::calib::c1 %d\n", paramName, (*pData).ps2.data.calib.c1);
    #endif
    #if WORD_SIZE==8
    printf("%s::ps2::data::calib::c2 %"PRId64"\n", paramName, (*pData).ps2.data.calib.c2);
    #else
    printf("%s::ps2::data::calib::c2 %d\n", paramName, (*pData).ps2.data.calib.c2);
    #endif
    #if WORD_SIZE==8
    printf("%s::ps2::data::calib::c3 %"PRId64"\n", paramName, (*pData).ps2.data.calib.c3);
    #else
    printf("%s::ps2::data::calib::c3 %d\n", paramName, (*pData).ps2.data.calib.c3);
    #endif
    #if WORD_SIZE==8
    printf("%s::ps2::data::calib::c4 %"PRId64"\n", paramName, (*pData).ps2.data.calib.c4);
    #else
    printf("%s::ps2::data::calib::c4 %d\n", paramName, (*pData).ps2.data.calib.c4);
    #endif
    #if WORD_SIZE==8
    printf("%s::ps2::data::calib::c5 %"PRId64"\n", paramName, (*pData).ps2.data.calib.c5);
    #else
    printf("%s::ps2::data::calib::c5 %d\n", paramName, (*pData).ps2.data.calib.c5);
    #endif
    #if WORD_SIZE==8
    printf("%s::ps2::data::calib::c6 %"PRId64"\n", paramName, (*pData).ps2.data.calib.c6);
    #else
    printf("%s::ps2::data::calib::c6 %d\n", paramName, (*pData).ps2.data.calib.c6);
    #endif
    printf("%s::ps2::data::calib::sens_t1 %f\n", paramName, (*pData).ps2.data.calib.sens_t1);
    printf("%s::ps2::data::calib::off_t1 %f\n", paramName, (*pData).ps2.data.calib.off_t1);
    printf("%s::ps2::data::calib::tcs %f\n", paramName, (*pData).ps2.data.calib.tcs);
    printf("%s::ps2::data::calib::tco %f\n", paramName, (*pData).ps2.data.calib.tco);
    printf("%s::ps2::data::calib::tref %f\n", paramName, (*pData).ps2.data.calib.tref);
    printf("%s::ps2::data::calib::temp_sens %f\n", paramName, (*pData).ps2.data.calib.temp_sens);
    #if WORD_SIZE==8
    printf("%s::ps2::data::raw::d1 %"PRId64"\n", paramName, (*pData).ps2.data.raw.d1);
    #else
    printf("%s::ps2::data::raw::d1 %d\n", paramName, (*pData).ps2.data.raw.d1);
    #endif
    #if WORD_SIZE==8
    printf("%s::ps2::data::raw::d2 %"PRId64"\n", paramName, (*pData).ps2.data.raw.d2);
    #else
    printf("%s::ps2::data::raw::d2 %d\n", paramName, (*pData).ps2.data.raw.d2);
    #endif
    #if WORD_SIZE==8
    printf("%s::ps2::data::processed::pressure %"PRId64"\n", paramName, (*pData).ps2.data.processed.pressure);
    #else
    printf("%s::ps2::data::processed::pressure %d\n", paramName, (*pData).ps2.data.processed.pressure);
    #endif
    #if WORD_SIZE==8
    printf("%s::ps2::data::processed::temp %"PRId64"\n", paramName, (*pData).ps2.data.processed.temp);
    #else
    printf("%s::ps2::data::processed::temp %d\n", paramName, (*pData).ps2.data.processed.temp);
    #endif
    printf("%s::ps2::data::validity %d\n", paramName, (int)(*pData).ps2.data.validity);
    printf("%s::ps2::gps_time %f\n", paramName, (*pData).ps2.gps_time);
    printf("%s::ps2::mission_time %f\n", paramName, (*pData).ps2.mission_time);
    printf("%s::heater1::data::power_watts %f\n", paramName, (*pData).heater1.data.power_watts);
    printf("%s::heater1::data::validity %d\n", paramName, (int)(*pData).heater1.data.validity);
    printf("%s::heater1::gps_time %f\n", paramName, (*pData).heater1.gps_time);
    printf("%s::heater1::mission_time %f\n", paramName, (*pData).heater1.mission_time);
    printf("%s::heater2::data::power_watts %f\n", paramName, (*pData).heater2.data.power_watts);
    printf("%s::heater2::data::validity %d\n", paramName, (int)(*pData).heater2.data.validity);
    printf("%s::heater2::gps_time %f\n", paramName, (*pData).heater2.gps_time);
    printf("%s::heater2::mission_time %f\n", paramName, (*pData).heater2.mission_time);
    #if WORD_SIZE==8
    printf("%s::anemometer::data %"PRId64"\n", paramName, (*pData).anemometer.data);
    #else
    printf("%s::anemometer::data %d\n", paramName, (*pData).anemometer.data);
    #endif
    printf("%s::anemometer::gps_time %f\n", paramName, (*pData).anemometer.gps_time);
    printf("%s::anemometer::mission_time %f\n", paramName, (*pData).anemometer.mission_time);
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintOBSW_DP_Filter(const char *paramName, const asn1SccOBSW_DP_Filter *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s %d\n", paramName, (int)(*pData));
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintOBSW_DP_SingleData(const char *paramName, const asn1SccOBSW_DP_SingleData *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    if ((*pData).kind == gps_PRESENT) {
        printf("%s::gps::data::mode %d\n", paramName, (int)(*pData).u.gps.data.mode);
        printf("%s::gps::data::date_and_time %f\n", paramName, (*pData).u.gps.data.date_and_time);
        printf("%s::gps::data::ept %f\n", paramName, (*pData).u.gps.data.ept);
        printf("%s::gps::data::latitude %f\n", paramName, (*pData).u.gps.data.latitude);
        printf("%s::gps::data::epy %f\n", paramName, (*pData).u.gps.data.epy);
        printf("%s::gps::data::longitude %f\n", paramName, (*pData).u.gps.data.longitude);
        printf("%s::gps::data::epx %f\n", paramName, (*pData).u.gps.data.epx);
        printf("%s::gps::data::altitude %f\n", paramName, (*pData).u.gps.data.altitude);
        printf("%s::gps::data::epv %f\n", paramName, (*pData).u.gps.data.epv);
        printf("%s::gps::data::course %f\n", paramName, (*pData).u.gps.data.course);
        printf("%s::gps::data::epd %f\n", paramName, (*pData).u.gps.data.epd);
        printf("%s::gps::data::speed %f\n", paramName, (*pData).u.gps.data.speed);
        printf("%s::gps::data::eps %f\n", paramName, (*pData).u.gps.data.eps);
        printf("%s::gps::data::climb %f\n", paramName, (*pData).u.gps.data.climb);
        printf("%s::gps::data::epc %f\n", paramName, (*pData).u.gps.data.epc);
        printf("%s::gps::gps_time %f\n", paramName, (*pData).u.gps.gps_time);
        printf("%s::gps::mission_time %f\n", paramName, (*pData).u.gps.mission_time);
    }
    else if ((*pData).kind == imu_PRESENT) {
        #if WORD_SIZE==8
        printf("%s::imu::data::mgt_raw::x_axis %"PRId64"\n", paramName, (*pData).u.imu.data.mgt_raw.x_axis);
        #else
        printf("%s::imu::data::mgt_raw::x_axis %d\n", paramName, (*pData).u.imu.data.mgt_raw.x_axis);
        #endif
        #if WORD_SIZE==8
        printf("%s::imu::data::mgt_raw::y_axis %"PRId64"\n", paramName, (*pData).u.imu.data.mgt_raw.y_axis);
        #else
        printf("%s::imu::data::mgt_raw::y_axis %d\n", paramName, (*pData).u.imu.data.mgt_raw.y_axis);
        #endif
        #if WORD_SIZE==8
        printf("%s::imu::data::mgt_raw::z_axis %"PRId64"\n", paramName, (*pData).u.imu.data.mgt_raw.z_axis);
        #else
        printf("%s::imu::data::mgt_raw::z_axis %d\n", paramName, (*pData).u.imu.data.mgt_raw.z_axis);
        #endif
        printf("%s::imu::data::mgt_mgauss::x_axis %f\n", paramName, (*pData).u.imu.data.mgt_mgauss.x_axis);
        printf("%s::imu::data::mgt_mgauss::y_axis %f\n", paramName, (*pData).u.imu.data.mgt_mgauss.y_axis);
        printf("%s::imu::data::mgt_mgauss::z_axis %f\n", paramName, (*pData).u.imu.data.mgt_mgauss.z_axis);
        #if WORD_SIZE==8
        printf("%s::imu::data::accel_raw::x_axis %"PRId64"\n", paramName, (*pData).u.imu.data.accel_raw.x_axis);
        #else
        printf("%s::imu::data::accel_raw::x_axis %d\n", paramName, (*pData).u.imu.data.accel_raw.x_axis);
        #endif
        #if WORD_SIZE==8
        printf("%s::imu::data::accel_raw::y_axis %"PRId64"\n", paramName, (*pData).u.imu.data.accel_raw.y_axis);
        #else
        printf("%s::imu::data::accel_raw::y_axis %d\n", paramName, (*pData).u.imu.data.accel_raw.y_axis);
        #endif
        #if WORD_SIZE==8
        printf("%s::imu::data::accel_raw::z_axis %"PRId64"\n", paramName, (*pData).u.imu.data.accel_raw.z_axis);
        #else
        printf("%s::imu::data::accel_raw::z_axis %d\n", paramName, (*pData).u.imu.data.accel_raw.z_axis);
        #endif
        printf("%s::imu::data::accel_mg::x_axis %f\n", paramName, (*pData).u.imu.data.accel_mg.x_axis);
        printf("%s::imu::data::accel_mg::y_axis %f\n", paramName, (*pData).u.imu.data.accel_mg.y_axis);
        printf("%s::imu::data::accel_mg::z_axis %f\n", paramName, (*pData).u.imu.data.accel_mg.z_axis);
        #if WORD_SIZE==8
        printf("%s::imu::data::gyro_raw::x_axis %"PRId64"\n", paramName, (*pData).u.imu.data.gyro_raw.x_axis);
        #else
        printf("%s::imu::data::gyro_raw::x_axis %d\n", paramName, (*pData).u.imu.data.gyro_raw.x_axis);
        #endif
        #if WORD_SIZE==8
        printf("%s::imu::data::gyro_raw::y_axis %"PRId64"\n", paramName, (*pData).u.imu.data.gyro_raw.y_axis);
        #else
        printf("%s::imu::data::gyro_raw::y_axis %d\n", paramName, (*pData).u.imu.data.gyro_raw.y_axis);
        #endif
        #if WORD_SIZE==8
        printf("%s::imu::data::gyro_raw::z_axis %"PRId64"\n", paramName, (*pData).u.imu.data.gyro_raw.z_axis);
        #else
        printf("%s::imu::data::gyro_raw::z_axis %d\n", paramName, (*pData).u.imu.data.gyro_raw.z_axis);
        #endif
        printf("%s::imu::data::gyro_mdps::x_axis %f\n", paramName, (*pData).u.imu.data.gyro_mdps.x_axis);
        printf("%s::imu::data::gyro_mdps::y_axis %f\n", paramName, (*pData).u.imu.data.gyro_mdps.y_axis);
        printf("%s::imu::data::gyro_mdps::z_axis %f\n", paramName, (*pData).u.imu.data.gyro_mdps.z_axis);
        #if WORD_SIZE==8
        printf("%s::imu::data::temp_raw %"PRId64"\n", paramName, (*pData).u.imu.data.temp_raw);
        #else
        printf("%s::imu::data::temp_raw %d\n", paramName, (*pData).u.imu.data.temp_raw);
        #endif
        printf("%s::imu::data::temp_celsius %f\n", paramName, (*pData).u.imu.data.temp_celsius);
        printf("%s::imu::data::mgt_valid %d\n", paramName, (int)(*pData).u.imu.data.mgt_valid);
        printf("%s::imu::data::acc_valid %d\n", paramName, (int)(*pData).u.imu.data.acc_valid);
        printf("%s::imu::data::gyro_valid %d\n", paramName, (int)(*pData).u.imu.data.gyro_valid);
        printf("%s::imu::data::temp_valid %d\n", paramName, (int)(*pData).u.imu.data.temp_valid);
        printf("%s::imu::gps_time %f\n", paramName, (*pData).u.imu.gps_time);
        printf("%s::imu::mission_time %f\n", paramName, (*pData).u.imu.mission_time);
    }
    else if ((*pData).kind == tc74s_PRESENT) {
        {
            int i13;
            for(i13=0; i13<5; i13++) {
                printf("%s::tc74s::data::Elem::temperature %f\n", paramName, (*pData).u.tc74s.data.arr[i13].temperature);
                printf("%s::tc74s::data::Elem::validity %d\n", paramName, (int)(*pData).u.tc74s.data.arr[i13].validity);
            }
        }
        printf("%s::tc74s::gps_time %f\n", paramName, (*pData).u.tc74s.gps_time);
        printf("%s::tc74s::mission_time %f\n", paramName, (*pData).u.tc74s.mission_time);
    }
    else if ((*pData).kind == pt1000s_PRESENT) {
        {
            int i14;
            for(i14=0; i14<7; i14++) {
                printf("%s::pt1000s::data::raw::Elem::vcc_volts %f\n", paramName, (*pData).u.pt1000s.data.raw.arr[i14].vcc_volts);
                printf("%s::pt1000s::data::raw::Elem::pt1000 %f\n", paramName, (*pData).u.pt1000s.data.raw.arr[i14].pt1000);
            }
        }
        {
            int i15;
            for(i15=0; i15<7; i15++) {
                printf("%s::pt1000s::data::celsius::Elem %f\n", paramName, (*pData).u.pt1000s.data.celsius.arr[i15]);
            }
        }
        {
            int i16;
            for(i16=0; i16<7; i16++) {
                printf("%s::pt1000s::data::validity::Elem %d\n", paramName, (int)(*pData).u.pt1000s.data.validity.arr[i16]);
            }
        }
        printf("%s::pt1000s::gps_time %f\n", paramName, (*pData).u.pt1000s.gps_time);
        printf("%s::pt1000s::mission_time %f\n", paramName, (*pData).u.pt1000s.mission_time);
    }
    else if ((*pData).kind == ps1_PRESENT) {
        #if WORD_SIZE==8
        printf("%s::ps1::data::calib::c1 %"PRId64"\n", paramName, (*pData).u.ps1.data.calib.c1);
        #else
        printf("%s::ps1::data::calib::c1 %d\n", paramName, (*pData).u.ps1.data.calib.c1);
        #endif
        #if WORD_SIZE==8
        printf("%s::ps1::data::calib::c2 %"PRId64"\n", paramName, (*pData).u.ps1.data.calib.c2);
        #else
        printf("%s::ps1::data::calib::c2 %d\n", paramName, (*pData).u.ps1.data.calib.c2);
        #endif
        #if WORD_SIZE==8
        printf("%s::ps1::data::calib::c3 %"PRId64"\n", paramName, (*pData).u.ps1.data.calib.c3);
        #else
        printf("%s::ps1::data::calib::c3 %d\n", paramName, (*pData).u.ps1.data.calib.c3);
        #endif
        #if WORD_SIZE==8
        printf("%s::ps1::data::calib::c4 %"PRId64"\n", paramName, (*pData).u.ps1.data.calib.c4);
        #else
        printf("%s::ps1::data::calib::c4 %d\n", paramName, (*pData).u.ps1.data.calib.c4);
        #endif
        #if WORD_SIZE==8
        printf("%s::ps1::data::calib::c5 %"PRId64"\n", paramName, (*pData).u.ps1.data.calib.c5);
        #else
        printf("%s::ps1::data::calib::c5 %d\n", paramName, (*pData).u.ps1.data.calib.c5);
        #endif
        #if WORD_SIZE==8
        printf("%s::ps1::data::calib::c6 %"PRId64"\n", paramName, (*pData).u.ps1.data.calib.c6);
        #else
        printf("%s::ps1::data::calib::c6 %d\n", paramName, (*pData).u.ps1.data.calib.c6);
        #endif
        printf("%s::ps1::data::calib::sens_t1 %f\n", paramName, (*pData).u.ps1.data.calib.sens_t1);
        printf("%s::ps1::data::calib::off_t1 %f\n", paramName, (*pData).u.ps1.data.calib.off_t1);
        printf("%s::ps1::data::calib::tcs %f\n", paramName, (*pData).u.ps1.data.calib.tcs);
        printf("%s::ps1::data::calib::tco %f\n", paramName, (*pData).u.ps1.data.calib.tco);
        printf("%s::ps1::data::calib::tref %f\n", paramName, (*pData).u.ps1.data.calib.tref);
        printf("%s::ps1::data::calib::temp_sens %f\n", paramName, (*pData).u.ps1.data.calib.temp_sens);
        #if WORD_SIZE==8
        printf("%s::ps1::data::raw::d1 %"PRId64"\n", paramName, (*pData).u.ps1.data.raw.d1);
        #else
        printf("%s::ps1::data::raw::d1 %d\n", paramName, (*pData).u.ps1.data.raw.d1);
        #endif
        #if WORD_SIZE==8
        printf("%s::ps1::data::raw::d2 %"PRId64"\n", paramName, (*pData).u.ps1.data.raw.d2);
        #else
        printf("%s::ps1::data::raw::d2 %d\n", paramName, (*pData).u.ps1.data.raw.d2);
        #endif
        #if WORD_SIZE==8
        printf("%s::ps1::data::processed::pressure %"PRId64"\n", paramName, (*pData).u.ps1.data.processed.pressure);
        #else
        printf("%s::ps1::data::processed::pressure %d\n", paramName, (*pData).u.ps1.data.processed.pressure);
        #endif
        #if WORD_SIZE==8
        printf("%s::ps1::data::processed::temp %"PRId64"\n", paramName, (*pData).u.ps1.data.processed.temp);
        #else
        printf("%s::ps1::data::processed::temp %d\n", paramName, (*pData).u.ps1.data.processed.temp);
        #endif
        printf("%s::ps1::data::validity %d\n", paramName, (int)(*pData).u.ps1.data.validity);
        printf("%s::ps1::gps_time %f\n", paramName, (*pData).u.ps1.gps_time);
        printf("%s::ps1::mission_time %f\n", paramName, (*pData).u.ps1.mission_time);
    }
    else if ((*pData).kind == ps2_PRESENT) {
        #if WORD_SIZE==8
        printf("%s::ps2::data::calib::c1 %"PRId64"\n", paramName, (*pData).u.ps2.data.calib.c1);
        #else
        printf("%s::ps2::data::calib::c1 %d\n", paramName, (*pData).u.ps2.data.calib.c1);
        #endif
        #if WORD_SIZE==8
        printf("%s::ps2::data::calib::c2 %"PRId64"\n", paramName, (*pData).u.ps2.data.calib.c2);
        #else
        printf("%s::ps2::data::calib::c2 %d\n", paramName, (*pData).u.ps2.data.calib.c2);
        #endif
        #if WORD_SIZE==8
        printf("%s::ps2::data::calib::c3 %"PRId64"\n", paramName, (*pData).u.ps2.data.calib.c3);
        #else
        printf("%s::ps2::data::calib::c3 %d\n", paramName, (*pData).u.ps2.data.calib.c3);
        #endif
        #if WORD_SIZE==8
        printf("%s::ps2::data::calib::c4 %"PRId64"\n", paramName, (*pData).u.ps2.data.calib.c4);
        #else
        printf("%s::ps2::data::calib::c4 %d\n", paramName, (*pData).u.ps2.data.calib.c4);
        #endif
        #if WORD_SIZE==8
        printf("%s::ps2::data::calib::c5 %"PRId64"\n", paramName, (*pData).u.ps2.data.calib.c5);
        #else
        printf("%s::ps2::data::calib::c5 %d\n", paramName, (*pData).u.ps2.data.calib.c5);
        #endif
        #if WORD_SIZE==8
        printf("%s::ps2::data::calib::c6 %"PRId64"\n", paramName, (*pData).u.ps2.data.calib.c6);
        #else
        printf("%s::ps2::data::calib::c6 %d\n", paramName, (*pData).u.ps2.data.calib.c6);
        #endif
        printf("%s::ps2::data::calib::sens_t1 %f\n", paramName, (*pData).u.ps2.data.calib.sens_t1);
        printf("%s::ps2::data::calib::off_t1 %f\n", paramName, (*pData).u.ps2.data.calib.off_t1);
        printf("%s::ps2::data::calib::tcs %f\n", paramName, (*pData).u.ps2.data.calib.tcs);
        printf("%s::ps2::data::calib::tco %f\n", paramName, (*pData).u.ps2.data.calib.tco);
        printf("%s::ps2::data::calib::tref %f\n", paramName, (*pData).u.ps2.data.calib.tref);
        printf("%s::ps2::data::calib::temp_sens %f\n", paramName, (*pData).u.ps2.data.calib.temp_sens);
        #if WORD_SIZE==8
        printf("%s::ps2::data::raw::d1 %"PRId64"\n", paramName, (*pData).u.ps2.data.raw.d1);
        #else
        printf("%s::ps2::data::raw::d1 %d\n", paramName, (*pData).u.ps2.data.raw.d1);
        #endif
        #if WORD_SIZE==8
        printf("%s::ps2::data::raw::d2 %"PRId64"\n", paramName, (*pData).u.ps2.data.raw.d2);
        #else
        printf("%s::ps2::data::raw::d2 %d\n", paramName, (*pData).u.ps2.data.raw.d2);
        #endif
        #if WORD_SIZE==8
        printf("%s::ps2::data::processed::pressure %"PRId64"\n", paramName, (*pData).u.ps2.data.processed.pressure);
        #else
        printf("%s::ps2::data::processed::pressure %d\n", paramName, (*pData).u.ps2.data.processed.pressure);
        #endif
        #if WORD_SIZE==8
        printf("%s::ps2::data::processed::temp %"PRId64"\n", paramName, (*pData).u.ps2.data.processed.temp);
        #else
        printf("%s::ps2::data::processed::temp %d\n", paramName, (*pData).u.ps2.data.processed.temp);
        #endif
        printf("%s::ps2::data::validity %d\n", paramName, (int)(*pData).u.ps2.data.validity);
        printf("%s::ps2::gps_time %f\n", paramName, (*pData).u.ps2.gps_time);
        printf("%s::ps2::mission_time %f\n", paramName, (*pData).u.ps2.mission_time);
    }
    else if ((*pData).kind == heater1_PRESENT) {
        printf("%s::heater1::data::power_watts %f\n", paramName, (*pData).u.heater1.data.power_watts);
        printf("%s::heater1::data::validity %d\n", paramName, (int)(*pData).u.heater1.data.validity);
        printf("%s::heater1::gps_time %f\n", paramName, (*pData).u.heater1.gps_time);
        printf("%s::heater1::mission_time %f\n", paramName, (*pData).u.heater1.mission_time);
    }
    else if ((*pData).kind == heater2_PRESENT) {
        printf("%s::heater2::data::power_watts %f\n", paramName, (*pData).u.heater2.data.power_watts);
        printf("%s::heater2::data::validity %d\n", paramName, (int)(*pData).u.heater2.data.validity);
        printf("%s::heater2::gps_time %f\n", paramName, (*pData).u.heater2.gps_time);
        printf("%s::heater2::mission_time %f\n", paramName, (*pData).u.heater2.mission_time);
    }
    else if ((*pData).kind == anemometer_PRESENT) {
        #if WORD_SIZE==8
        printf("%s::anemometer::data %"PRId64"\n", paramName, (*pData).u.anemometer.data);
        #else
        printf("%s::anemometer::data %d\n", paramName, (*pData).u.anemometer.data);
        #endif
        printf("%s::anemometer::gps_time %f\n", paramName, (*pData).u.anemometer.gps_time);
        printf("%s::anemometer::mission_time %f\n", paramName, (*pData).u.anemometer.mission_time);
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintTM(const char *paramName, const asn1SccTM *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s::state_htl %d\n", paramName, (int)(*pData).state_htl);
    printf("%s::heater1::power_watts %f\n", paramName, (*pData).heater1.power_watts);
    printf("%s::heater1::validity %d\n", paramName, (int)(*pData).heater1.validity);
    printf("%s::heater2::power_watts %f\n", paramName, (*pData).heater2.power_watts);
    printf("%s::heater2::validity %d\n", paramName, (int)(*pData).heater2.validity);
    {
        int i17;
        for(i17=0; i17<5; i17++) {
            printf("%s::tc74s::Elem::temperature %f\n", paramName, (*pData).tc74s.arr[i17].temperature);
            printf("%s::tc74s::Elem::validity %d\n", paramName, (int)(*pData).tc74s.arr[i17].validity);
        }
    }
    {
        int i18;
        for(i18=0; i18<7; i18++) {
            printf("%s::pt1000s::raw::Elem::vcc_volts %f\n", paramName, (*pData).pt1000s.raw.arr[i18].vcc_volts);
            printf("%s::pt1000s::raw::Elem::pt1000 %f\n", paramName, (*pData).pt1000s.raw.arr[i18].pt1000);
        }
    }
    {
        int i19;
        for(i19=0; i19<7; i19++) {
            printf("%s::pt1000s::celsius::Elem %f\n", paramName, (*pData).pt1000s.celsius.arr[i19]);
        }
    }
    {
        int i20;
        for(i20=0; i20<7; i20++) {
            printf("%s::pt1000s::validity::Elem %d\n", paramName, (int)(*pData).pt1000s.validity.arr[i20]);
        }
    }
    printf("%s::gps::mode %d\n", paramName, (int)(*pData).gps.mode);
    printf("%s::gps::date_and_time %f\n", paramName, (*pData).gps.date_and_time);
    printf("%s::gps::ept %f\n", paramName, (*pData).gps.ept);
    printf("%s::gps::latitude %f\n", paramName, (*pData).gps.latitude);
    printf("%s::gps::epy %f\n", paramName, (*pData).gps.epy);
    printf("%s::gps::longitude %f\n", paramName, (*pData).gps.longitude);
    printf("%s::gps::epx %f\n", paramName, (*pData).gps.epx);
    printf("%s::gps::altitude %f\n", paramName, (*pData).gps.altitude);
    printf("%s::gps::epv %f\n", paramName, (*pData).gps.epv);
    printf("%s::gps::course %f\n", paramName, (*pData).gps.course);
    printf("%s::gps::epd %f\n", paramName, (*pData).gps.epd);
    printf("%s::gps::speed %f\n", paramName, (*pData).gps.speed);
    printf("%s::gps::eps %f\n", paramName, (*pData).gps.eps);
    printf("%s::gps::climb %f\n", paramName, (*pData).gps.climb);
    printf("%s::gps::epc %f\n", paramName, (*pData).gps.epc);
    printf("%s::imu::mgt_mgauss::x_axis %f\n", paramName, (*pData).imu.mgt_mgauss.x_axis);
    printf("%s::imu::mgt_mgauss::y_axis %f\n", paramName, (*pData).imu.mgt_mgauss.y_axis);
    printf("%s::imu::mgt_mgauss::z_axis %f\n", paramName, (*pData).imu.mgt_mgauss.z_axis);
    printf("%s::imu::accel_mg::x_axis %f\n", paramName, (*pData).imu.accel_mg.x_axis);
    printf("%s::imu::accel_mg::y_axis %f\n", paramName, (*pData).imu.accel_mg.y_axis);
    printf("%s::imu::accel_mg::z_axis %f\n", paramName, (*pData).imu.accel_mg.z_axis);
    printf("%s::imu::gyro_mdps::x_axis %f\n", paramName, (*pData).imu.gyro_mdps.x_axis);
    printf("%s::imu::gyro_mdps::y_axis %f\n", paramName, (*pData).imu.gyro_mdps.y_axis);
    printf("%s::imu::gyro_mdps::z_axis %f\n", paramName, (*pData).imu.gyro_mdps.z_axis);
    printf("%s::imu::temp_celsius %f\n", paramName, (*pData).imu.temp_celsius);
    printf("%s::imu::mgt_valid %d\n", paramName, (int)(*pData).imu.mgt_valid);
    printf("%s::imu::acc_valid %d\n", paramName, (int)(*pData).imu.acc_valid);
    printf("%s::imu::gyro_valid %d\n", paramName, (int)(*pData).imu.gyro_valid);
    printf("%s::imu::temp_valid %d\n", paramName, (int)(*pData).imu.temp_valid);
    #if WORD_SIZE==8
    printf("%s::ps1::pressure %"PRId64"\n", paramName, (*pData).ps1.pressure);
    #else
    printf("%s::ps1::pressure %d\n", paramName, (*pData).ps1.pressure);
    #endif
    #if WORD_SIZE==8
    printf("%s::ps1::temp %"PRId64"\n", paramName, (*pData).ps1.temp);
    #else
    printf("%s::ps1::temp %d\n", paramName, (*pData).ps1.temp);
    #endif
    #if WORD_SIZE==8
    printf("%s::ps2::pressure %"PRId64"\n", paramName, (*pData).ps2.pressure);
    #else
    printf("%s::ps2::pressure %d\n", paramName, (*pData).ps2.pressure);
    #endif
    #if WORD_SIZE==8
    printf("%s::ps2::temp %"PRId64"\n", paramName, (*pData).ps2.temp);
    #else
    printf("%s::ps2::temp %d\n", paramName, (*pData).ps2.temp);
    #endif
    printf("%s::ps1_validity %d\n", paramName, (int)(*pData).ps1_validity);
    printf("%s::ps2_validity %d\n", paramName, (int)(*pData).ps2_validity);
    #if WORD_SIZE==8
    printf("%s::anemometer %"PRId64"\n", paramName, (*pData).anemometer);
    #else
    printf("%s::anemometer %d\n", paramName, (*pData).anemometer);
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintTC_Heater(const char *paramName, const asn1SccTC_Heater *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s::heater %d\n", paramName, (int)(*pData).heater);
    if ((*pData).command.kind == power_manual_PRESENT) {
        printf("%s::command::power_manual %f\n", paramName, (*pData).command.u.power_manual);
    }
    else if ((*pData).command.kind == max_min_PRESENT) {
        printf("%s::command::max_min %d\n", paramName, (int)(*pData).command.u.max_min);
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintTC(const char *paramName, const asn1SccTC *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    if ((*pData).kind == heater_commands_PRESENT) {
        printf("%s::heater_commands::heater_of_HTL::heater %d\n", paramName, (int)(*pData).u.heater_commands.heater_of_HTL.heater);
        if ((*pData).u.heater_commands.heater_of_HTL.command.kind == power_manual_PRESENT) {
            printf("%s::heater_commands::heater_of_HTL::command::power_manual %f\n", paramName, (*pData).u.heater_commands.heater_of_HTL.command.u.power_manual);
        }
        else if ((*pData).u.heater_commands.heater_of_HTL.command.kind == max_min_PRESENT) {
            printf("%s::heater_commands::heater_of_HTL::command::max_min %d\n", paramName, (int)(*pData).u.heater_commands.heater_of_HTL.command.u.max_min);
        }
        printf("%s::heater_commands::config_of_HTL::press_5km %f\n", paramName, (*pData).u.heater_commands.config_of_HTL.press_5km);
        printf("%s::heater_commands::config_of_HTL::press_10km %f\n", paramName, (*pData).u.heater_commands.config_of_HTL.press_10km);
        printf("%s::heater_commands::config_of_HTL::press_18km %f\n", paramName, (*pData).u.heater_commands.config_of_HTL.press_18km);
        printf("%s::heater_commands::config_of_HTL::a1_duration_emergency_secs %f\n", paramName, (*pData).u.heater_commands.config_of_HTL.a1_duration_emergency_secs);
        printf("%s::heater_commands::config_of_HTL::a1_duration_max_secs %f\n", paramName, (*pData).u.heater_commands.config_of_HTL.a1_duration_max_secs);
        printf("%s::heater_commands::config_of_HTL::a2_duration_max_secs %f\n", paramName, (*pData).u.heater_commands.config_of_HTL.a2_duration_max_secs);
        #if WORD_SIZE==8
        printf("%s::heater_commands::config_of_HTL::f1_duration_secs %"PRId64"\n", paramName, (*pData).u.heater_commands.config_of_HTL.f1_duration_secs);
        #else
        printf("%s::heater_commands::config_of_HTL::f1_duration_secs %d\n", paramName, (*pData).u.heater_commands.config_of_HTL.f1_duration_secs);
        #endif
        #if WORD_SIZE==8
        printf("%s::heater_commands::config_of_HTL::f2_duration_secs %"PRId64"\n", paramName, (*pData).u.heater_commands.config_of_HTL.f2_duration_secs);
        #else
        printf("%s::heater_commands::config_of_HTL::f2_duration_secs %d\n", paramName, (*pData).u.heater_commands.config_of_HTL.f2_duration_secs);
        #endif
    }
    else if ((*pData).kind == system_commands_PRESENT) {
        printf("%s::system_commands %d\n", paramName, (int)(*pData).u.system_commands);
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintHTL_GUI(const char *paramName, const asn1SccHTL_GUI *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s::state %d\n", paramName, (int)(*pData).state);
    printf("%s::heater::power_watts %f\n", paramName, (*pData).heater.power_watts);
    printf("%s::heater::validity %d\n", paramName, (int)(*pData).heater.validity);
    printf("%s::delta_T %f\n", paramName, (*pData).delta_T);
    printf("%s::pt1000s::aire_abajo %f\n", paramName, (*pData).pt1000s.aire_abajo);
    printf("%s::pt1000s::aire_arriba %f\n", paramName, (*pData).pt1000s.aire_arriba);
    printf("%s::pt1000s::placa_abajo %f\n", paramName, (*pData).pt1000s.placa_abajo);
    printf("%s::pt1000s::placa_arriba %f\n", paramName, (*pData).pt1000s.placa_arriba);
    printf("%s::pt1000s::infinito %f\n", paramName, (*pData).pt1000s.infinito);
    printf("%s::pt1000s::exterior %f\n", paramName, (*pData).pt1000s.exterior);
    {
        int i21;
        for(i21=0; i21<6; i21++) {
            printf("%s::pt1000s::validity::Elem %d\n", paramName, (int)(*pData).pt1000s.validity.arr[i21]);
        }
    }
    printf("%s::tc74s::x_positive %f\n", paramName, (*pData).tc74s.x_positive);
    printf("%s::tc74s::x_negative %f\n", paramName, (*pData).tc74s.x_negative);
    printf("%s::tc74s::y_positive %f\n", paramName, (*pData).tc74s.y_positive);
    printf("%s::tc74s::y_negative %f\n", paramName, (*pData).tc74s.y_negative);
    printf("%s::tc74s::z_techo %f\n", paramName, (*pData).tc74s.z_techo);
    {
        int i22;
        for(i22=0; i22<5; i22++) {
            printf("%s::tc74s::validity::Elem %d\n", paramName, (int)(*pData).tc74s.validity.arr[i22]);
        }
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintDate_Time(const char *paramName, const asn1SccDate_Time *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s::day %"PRId64"\n", paramName, (*pData).day);
    #else
    printf("%s::day %d\n", paramName, (*pData).day);
    #endif
    #if WORD_SIZE==8
    printf("%s::month %"PRId64"\n", paramName, (*pData).month);
    #else
    printf("%s::month %d\n", paramName, (*pData).month);
    #endif
    #if WORD_SIZE==8
    printf("%s::year %"PRId64"\n", paramName, (*pData).year);
    #else
    printf("%s::year %d\n", paramName, (*pData).year);
    #endif
    #if WORD_SIZE==8
    printf("%s::hour %"PRId64"\n", paramName, (*pData).hour);
    #else
    printf("%s::hour %d\n", paramName, (*pData).hour);
    #endif
    #if WORD_SIZE==8
    printf("%s::minute %"PRId64"\n", paramName, (*pData).minute);
    #else
    printf("%s::minute %d\n", paramName, (*pData).minute);
    #endif
    #if WORD_SIZE==8
    printf("%s::second %"PRId64"\n", paramName, (*pData).second);
    #else
    printf("%s::second %d\n", paramName, (*pData).second);
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintATT_GUI(const char *paramName, const asn1SccATT_GUI *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s::gps::mode %d\n", paramName, (int)(*pData).gps.mode);
    printf("%s::gps::date_and_time %f\n", paramName, (*pData).gps.date_and_time);
    printf("%s::gps::ept %f\n", paramName, (*pData).gps.ept);
    printf("%s::gps::latitude %f\n", paramName, (*pData).gps.latitude);
    printf("%s::gps::epy %f\n", paramName, (*pData).gps.epy);
    printf("%s::gps::longitude %f\n", paramName, (*pData).gps.longitude);
    printf("%s::gps::epx %f\n", paramName, (*pData).gps.epx);
    printf("%s::gps::altitude %f\n", paramName, (*pData).gps.altitude);
    printf("%s::gps::epv %f\n", paramName, (*pData).gps.epv);
    printf("%s::gps::course %f\n", paramName, (*pData).gps.course);
    printf("%s::gps::epd %f\n", paramName, (*pData).gps.epd);
    printf("%s::gps::speed %f\n", paramName, (*pData).gps.speed);
    printf("%s::gps::eps %f\n", paramName, (*pData).gps.eps);
    printf("%s::gps::climb %f\n", paramName, (*pData).gps.climb);
    printf("%s::gps::epc %f\n", paramName, (*pData).gps.epc);
    #if WORD_SIZE==8
    printf("%s::gps_date_time::day %"PRId64"\n", paramName, (*pData).gps_date_time.day);
    #else
    printf("%s::gps_date_time::day %d\n", paramName, (*pData).gps_date_time.day);
    #endif
    #if WORD_SIZE==8
    printf("%s::gps_date_time::month %"PRId64"\n", paramName, (*pData).gps_date_time.month);
    #else
    printf("%s::gps_date_time::month %d\n", paramName, (*pData).gps_date_time.month);
    #endif
    #if WORD_SIZE==8
    printf("%s::gps_date_time::year %"PRId64"\n", paramName, (*pData).gps_date_time.year);
    #else
    printf("%s::gps_date_time::year %d\n", paramName, (*pData).gps_date_time.year);
    #endif
    #if WORD_SIZE==8
    printf("%s::gps_date_time::hour %"PRId64"\n", paramName, (*pData).gps_date_time.hour);
    #else
    printf("%s::gps_date_time::hour %d\n", paramName, (*pData).gps_date_time.hour);
    #endif
    #if WORD_SIZE==8
    printf("%s::gps_date_time::minute %"PRId64"\n", paramName, (*pData).gps_date_time.minute);
    #else
    printf("%s::gps_date_time::minute %d\n", paramName, (*pData).gps_date_time.minute);
    #endif
    #if WORD_SIZE==8
    printf("%s::gps_date_time::second %"PRId64"\n", paramName, (*pData).gps_date_time.second);
    #else
    printf("%s::gps_date_time::second %d\n", paramName, (*pData).gps_date_time.second);
    #endif
    printf("%s::imu::mgt_mgauss::x_axis %f\n", paramName, (*pData).imu.mgt_mgauss.x_axis);
    printf("%s::imu::mgt_mgauss::y_axis %f\n", paramName, (*pData).imu.mgt_mgauss.y_axis);
    printf("%s::imu::mgt_mgauss::z_axis %f\n", paramName, (*pData).imu.mgt_mgauss.z_axis);
    printf("%s::imu::accel_mg::x_axis %f\n", paramName, (*pData).imu.accel_mg.x_axis);
    printf("%s::imu::accel_mg::y_axis %f\n", paramName, (*pData).imu.accel_mg.y_axis);
    printf("%s::imu::accel_mg::z_axis %f\n", paramName, (*pData).imu.accel_mg.z_axis);
    printf("%s::imu::gyro_mdps::x_axis %f\n", paramName, (*pData).imu.gyro_mdps.x_axis);
    printf("%s::imu::gyro_mdps::y_axis %f\n", paramName, (*pData).imu.gyro_mdps.y_axis);
    printf("%s::imu::gyro_mdps::z_axis %f\n", paramName, (*pData).imu.gyro_mdps.z_axis);
    printf("%s::imu::temp_celsius %f\n", paramName, (*pData).imu.temp_celsius);
    printf("%s::imu::mgt_valid %d\n", paramName, (int)(*pData).imu.mgt_valid);
    printf("%s::imu::acc_valid %d\n", paramName, (int)(*pData).imu.acc_valid);
    printf("%s::imu::gyro_valid %d\n", paramName, (int)(*pData).imu.gyro_valid);
    printf("%s::imu::temp_valid %d\n", paramName, (int)(*pData).imu.temp_valid);
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintPS_GUI(const char *paramName, const asn1SccPS_GUI *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s::pressure_mbar %f\n", paramName, (*pData).pressure_mbar);
    printf("%s::temperature_celsius %f\n", paramName, (*pData).temperature_celsius);
    printf("%s::validity %d\n", paramName, (int)(*pData).validity);
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintENV_GUI(const char *paramName, const asn1SccENV_GUI *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s::pressure_sensor_1::pressure_mbar %f\n", paramName, (*pData).pressure_sensor_1.pressure_mbar);
    printf("%s::pressure_sensor_1::temperature_celsius %f\n", paramName, (*pData).pressure_sensor_1.temperature_celsius);
    printf("%s::pressure_sensor_1::validity %d\n", paramName, (int)(*pData).pressure_sensor_1.validity);
    printf("%s::pressure_sensor_2::pressure_mbar %f\n", paramName, (*pData).pressure_sensor_2.pressure_mbar);
    printf("%s::pressure_sensor_2::temperature_celsius %f\n", paramName, (*pData).pressure_sensor_2.temperature_celsius);
    printf("%s::pressure_sensor_2::validity %d\n", paramName, (int)(*pData).pressure_sensor_2.validity);
    #if WORD_SIZE==8
    printf("%s::anemometer::global_counter %"PRId64"\n", paramName, (*pData).anemometer.global_counter);
    #else
    printf("%s::anemometer::global_counter %d\n", paramName, (*pData).anemometer.global_counter);
    #endif
    printf("%s::anemometer::temperature_celsius %f\n", paramName, (*pData).anemometer.temperature_celsius);
    printf("%s::anemometer::temperature_validity %d\n", paramName, (int)(*pData).anemometer.temperature_validity);
    printf("%s::heater::power_watts %f\n", paramName, (*pData).heater.power_watts);
    printf("%s::heater::validity %d\n", paramName, (int)(*pData).heater.validity);
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintT_Int32(const char *paramName, const asn1SccT_Int32 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s %"PRId64"\n", paramName, (*pData));
    #else
    printf("%s %d\n", paramName, (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintT_UInt32(const char *paramName, const asn1SccT_UInt32 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s %"PRId64"\n", paramName, (*pData));
    #else
    printf("%s %d\n", paramName, (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintT_Int8(const char *paramName, const asn1SccT_Int8 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s %"PRId64"\n", paramName, (*pData));
    #else
    printf("%s %d\n", paramName, (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintT_UInt8(const char *paramName, const asn1SccT_UInt8 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s %"PRId64"\n", paramName, (*pData));
    #else
    printf("%s %d\n", paramName, (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintT_Boolean(const char *paramName, const asn1SccT_Boolean *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s %d\n", paramName, (int)(*pData));
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintT_Null_Record(const char *paramName, const asn1SccT_Null_Record *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__

#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

