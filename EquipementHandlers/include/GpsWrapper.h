/* IMPORTANT:
 *
 * This class works only if the GPS dev was registered with the comand: 
 * sudo gpsd /dev/<path_to_gps> -F /var/run/gpsd.sock
 ******************************************************************************/
#ifndef GPS_WRAPPER_H
#define GPS_WRAPPER_H

#include <gps.h> // C library to be wrapped.
#include "Utils/FileLogger.h"

using namespace utils;

namespace equipementHandlers {

  /**
   * The real purpose of this class is to wrap the read operation from the GPS,
   * so maybe GpsReader is a better name.
   */ 
  class GpsWrapper {
    public:
      GpsWrapper(const char *logFileName = "/home/pi/blackbox.log",
                 const char *host = "localhost",
                 const char *port = DEFAULT_GPSD_PORT,
                 const unsigned int maxRetries = 0,
                 const int maxWaitingTime_usecs = 250000);

      ~GpsWrapper();

      void setMaxRetries(const unsigned int maxRetries);

      void setMaxWaitingTime_us (const int maxWaitingTime_us);

      void setReadConstraints(gps_mask_t constraints);

      // If time, lat, long, etc. are NOT availabe, they are set to infinite.
      void readGpsData(struct gps_data_t &gpsData_out);

    private:
      const char *m_host;
      const char *m_port;
      struct gps_data_t gpsData;  // Struct where the read data is stored.
      unsigned int m_maxRetries;
      int m_maxWaitingTime_us = 250000;
      FileLogger *fileLogger;     // To log errors or infos, but not GPS data.

      bool connectToDaemon();
      void disconnectFromDaemon();
      bool hasFix();
  };
}

#endif // GPS_WRAPPER_H
