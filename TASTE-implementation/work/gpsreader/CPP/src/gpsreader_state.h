// Fill in this class with your context data (internal state):
// list all the variables you want global (per function instance)
#include "dataview-uniq.h"
#include <gps.h> // C library to be wrapped.
#include "Utils/FileLoggerFactory.h"
#include "Utils/FileLogger.h"

using namespace utils;

class gpsreader_state {
    
    public:      
      struct gps_data_t gpsData;  // Struct where the read data is stored.
      FileLogger *fileLogger;     // To log errors or infos, but not GPS data.
      asn1SccOBSW_DP_Data obsw_dp_data;
      
      gpsreader_state () {
         obsw_dp_data.exist = {
            .gps = 1,
            .imu = 0,
            .tc74s = 0,
            .pt1000s = 0,
            .ps1 = 0,
            .ps2 = 0,
            .heater1 = 0,
            .heater2 = 0,
            .anemometer = 0
        };
        
        fileLogger = 
            FileLoggerFactory::getInstance().createFileLogger("/home/pi/blackbox.log");

        // Connecto to daemon:
        const int ret = gps_open("localhost", DEFAULT_GPSD_PORT, &gpsData);
        const bool err = (ret != 0);
        if (!err) {
            gps_stream(&gpsData, WATCH_ENABLE | WATCH_JSON, NULL);
        }
      }
    
      ~gpsreader_state() {
        // Disconnect from daemon:
        gps_stream(&gpsData, WATCH_DISABLE, NULL);
        gps_close(&gpsData);
      }
        
};
