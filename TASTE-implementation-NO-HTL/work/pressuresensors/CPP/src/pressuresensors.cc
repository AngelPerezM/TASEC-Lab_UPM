// Body file for function PressureSensors
// Generated by TASTE on 2021-05-17 12:48:29
// You can edit this file, it will not be overwritten
// Provided interfaces : getCalibData, readPressureAndTemp
// Required interfaces : 
// User-defined properties for this function:
//   |_ Taste::Active_Interfaces = any
//   |_ Taste::coordinates = 120915 126768 146475 137004
// Timers              : 

#include "pressuresensors.h"
#include "pressuresensors_state.h"
#include <iostream>

// Define and use function state inside this context structure
// avoid defining global/static variable elsewhere
pressuresensors_state ctxt_ps;
static bool stopped_ps = false;

// Auxiliary functions (file scope).
///////////////////////////////////////////////////////////////////////////////
static inline bool castCalibData_2_ASN1Struct (asn1SccPS_Calibration_Data &out, 
                                               PressureSensor &ps)
{
    PressureSensor::CalibrationData cd_ps;
    bool isValid = ps.getCalibData(cd_ps);
    if (isValid) {
        out = asn1SccPS_Calibration_Data {
                .c1 = cd_ps.c1, .c2 = cd_ps.c2, .c3 = cd_ps.c3,
                .c4 = cd_ps.c4, .c5 = cd_ps.c5, .c6 = cd_ps.c6,
                .sens_t1 = cd_ps.sensT1,
                .off_t1 = cd_ps.offT1,
                .tcs = cd_ps.tcs,
                .tco = cd_ps.tco,
                .tref = cd_ps.tRef,
                .temp_sens = cd_ps.tempSens
            };
    }
    
    return isValid;
}

// Components interfaces implementation:
////////////////////////////////////////////////////////////////////////////////
void pressuresensors_startup(void)
{
   // Write your initialisation code, but DO NOT CALL REQUIRED INTERFACES
    std::cout << "[PressureSensors] Startup" << std::endl;
    ctxt_ps.ps1_cv = castCalibData_2_ASN1Struct (ctxt_ps.ps1_cd, ctxt_ps.ps1) ? asn1Sccvalid : asn1Sccinvalid;
    ctxt_ps.ps2_cv = castCalibData_2_ASN1Struct (ctxt_ps.ps2_cd, ctxt_ps.ps2) ? asn1Sccvalid : asn1Sccinvalid;
}

void pressuresensors_PI_readPressureAndTemp( asn1SccPS_All_Data * OUT_ps1,
                                             asn1SccPS_All_Data * OUT_ps2)
{
    if (stopped_ps) {
        return;
    }
    
    struct timespec start, stop;
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    OUT_ps1->calib = ctxt_ps.ps1_cd;
    OUT_ps2->calib = ctxt_ps.ps2_cd;

    OUT_ps1->validity = ctxt_ps.ps1_cv;
    OUT_ps2->validity = ctxt_ps.ps2_cv;
        
    int32_t p, t;
    uint32_t d1, d2;
    
    // Pressures sensor 1:
    if( OUT_ps1->validity == asn1Sccvalid ) {
        OUT_ps1->validity = (ctxt_ps.ps1.getPressureAndTemp(p, t, d1, d2) < 0) ? asn1Sccinvalid : asn1Sccvalid;
        OUT_ps1->processed.pressure = p;
        OUT_ps1->processed.temp = t;
        OUT_ps1->raw.d1 = d1;
        OUT_ps1->raw.d2 = d2;
        std::cout << "Pressure sensor 2: " << p << " Temperature: " << t << std::endl;
    }    
    std::cout << "Pressure sensor 2: " << p << " Temperature: " << t << std::endl;
        
    // Pressure sensor 2:
    if( OUT_ps2->validity == asn1Sccvalid ) {
        OUT_ps2->validity = (ctxt_ps.ps2.getPressureAndTemp(p, t, d1, d2) < 0) ? asn1Sccinvalid : asn1Sccvalid;
        OUT_ps2->processed.pressure = p;
        OUT_ps2->processed.temp = t;
        OUT_ps2->raw.d1 = d1;
        OUT_ps2->raw.d2 = d2;
         std::cout << "Pressure sensor 1: " << p << " Temperature: " << t << std::endl;
    }
    std::cout << "Pressure sensor 1: " << p << " Temperature: " << t << std::endl;
    
    clock_gettime(CLOCK_MONOTONIC, &stop);
    ctxt_ps.et += ((stop.tv_sec - start.tv_sec)*1e3 + (stop.tv_nsec - start.tv_nsec)/1e6);
    ctxt_ps.nIters++;
}

void pressuresensors_PI_stop( ) {
    stopped_ps = true;
    ctxt_ps.~pressuresensors_state();
}