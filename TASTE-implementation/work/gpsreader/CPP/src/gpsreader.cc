// Body file for function GPSReader
// Generated by TASTE on 2021-05-17 12:48:29
// You can edit this file, it will not be overwritten
// Provided interfaces : readGPSData
// Required interfaces : 
// User-defined properties for this function:
//   |_ Taste::Active_Interfaces = any
//   |_ Taste::coordinates = 77690 118458 103344 127427
// Timers              : 

#include "gpsreader.h"
#include "gpsreader_state.h"
#include "Context-gpsreader.h"

#include <iostream>
#include <string.h> // memset
#include <stdio.h>
#include <errno.h>
#include <math.h>   // isfinite

#include "Utils/Debug.h"
#include "Utils/FileLoggerFactory.h"

// Auxiliary functions (file scope):
///////////////////////////////////////////////////////////////////////////////
static void print_gps_data (const gps_data_t gpsData);
static bool hasFixData (void);
static void sendDataToDP (void);

// Define and use function state inside this context structure
// avoid defining global/static variable elsewhere
gpsreader_state ctxt_gps;

void gpsreader_startup(void)
{
   // Write your initialisation code, but DO NOT CALL REQUIRED INTERFACES
   std::cout << "[GPSReader] Startup" << std::endl;
}

void gpsreader_PI_readGPSData (void)

{
    struct timespec start, stop;
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    uint32_t retries = 0;
    bool hasFix = false;

    while (!hasFix && (retries <= gpsreader_ctxt.max_retries)) {
      if (!gps_waiting(&ctxt_gps.gpsData, gpsreader_ctxt.waiting_time_per_retry_us)) {
        if (errno < 0) {
          ctxt_gps.fileLogger->LOG(Error, std::string("[GPSReader] Could not wait for data: ") +
                                          std::string(gps_errstr(errno)));
        } else {
          PRINT_DEBUG("[GPSReader] gps_waiting: TIMEOUT.\n");
        }
      } else {  // there is data, probably.
        int readBytes = gps_read(&ctxt_gps.gpsData);
        
        if (-1 == readBytes) {
          ctxt_gps.fileLogger->LOG(Error, std::string("[GPSReader] gps_read error: ") +
                                          std::string(gps_errstr(errno)));
        } else if (0 == readBytes) {
          ctxt_gps.fileLogger->LOG(Error, std::string("[GPSReader] There is not GPS data: ") +
                                          std::string(gps_errstr(errno)));
        } else {
          hasFix = hasFixData();
          if (hasFix) {
            PRINT_DEBUG("[GPSReader] FIX\n");
          } else {
            PRINT_DEBUG("[GPSReader] NO FIX\n");
          }
        }
      }

      retries++;
    }
    
    sendDataToDP();
    gps_clear_fix(&(ctxt_gps.gpsData.fix));  // data is clear for next read.
    
    clock_gettime(CLOCK_MONOTONIC, &stop);
    ctxt_gps.et += ((stop.tv_sec - start.tv_sec)*1e3 + (stop.tv_nsec - start.tv_nsec)/1e6);
    ctxt_gps.nIters++;
}

static bool hasFixData(void) {
  return ( (ctxt_gps.gpsData.status != STATUS_NO_FIX) &&
           (ctxt_gps.gpsData.fix.mode == MODE_2D || ctxt_gps.gpsData.fix.mode == MODE_3D) &&
           isfinite(ctxt_gps.gpsData.fix.time) && isfinite(ctxt_gps.gpsData.fix.latitude) &&
           isfinite(ctxt_gps.gpsData.fix.longitude) && (ctxt_gps.gpsData.set & TIME_SET)
         );
}

static void print_gps_data (const gps_data_t gpsData) {
      struct tm ts;
      time_t time = gpsData.fix.time;
      char buf[80];
      ts = *localtime(&time);
      strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", &ts);

      printf("- Time: %s\n", buf);
      printf("- Satellites used: %d\n", gpsData.satellites_used);
      printf("- Online: %.7f\n", gpsData.online);
      printf("- Latitude: %f.\n- Longitude: %f\n", 
      gpsData.fix.latitude, gpsData.fix.longitude);
      printf("- Speed over gnd: %f.\n- Vertical speed [m/s] %f\n",
      gpsData.fix.speed, gpsData.fix.climb);
}

static void sendDataToDP (void) {
    // data to be send to datapool
    asn1SccT_Double aux;
    gpsreader_RI_getTime(&aux, &ctxt_gps.obsw_dp_data.gps.mission_time);
    ctxt_gps.obsw_dp_data.gps.data = {
            .mode = (asn1SccGPS_PVT_mode) ctxt_gps.gpsData.fix.mode,
            .date_and_time = ctxt_gps.gpsData.fix.time,
            .ept = ctxt_gps.gpsData.fix.ept,
            .latitude = ctxt_gps.gpsData.fix.latitude,
            .epy = ctxt_gps.gpsData.fix.epy,
            .longitude = ctxt_gps.gpsData.fix.longitude,
            .epx = ctxt_gps.gpsData.fix.epx,
            .altitude = ctxt_gps.gpsData.fix.altitude,
            .epv = ctxt_gps.gpsData.fix.epv,
            .course = ctxt_gps.gpsData.fix.track,
            .epd = ctxt_gps.gpsData.fix.epd,
            .speed = ctxt_gps.gpsData.fix.speed,
            .eps = ctxt_gps.gpsData.fix.eps,
            .climb = ctxt_gps.gpsData.fix.climb,
            .epc = ctxt_gps.gpsData.fix.epc
        };
    ctxt_gps.obsw_dp_data.gps.gps_time = ctxt_gps.gpsData.fix.time;
    ctxt_gps.obsw_dp_data.exist.gps = 1;
    
    
    gpsreader_RI_InsertCompleteGroup(&ctxt_gps.obsw_dp_data);
}
