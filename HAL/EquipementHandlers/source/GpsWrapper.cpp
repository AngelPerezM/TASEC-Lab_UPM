#include "GpsWrapper.h"
#include <stdio.h>
#include <errno.h>
#include <math.h>   // isfinite

#include "Utils/Debug.h"
#include "Utils/FileLoggerFactory.h"

namespace equipementHandlers {

  GpsWrapper::GpsWrapper(const char *logFileName, const char *host, 
                         const char *port, const unsigned int maxRetries, 
                         const int maxWaitingTime_us)
    : m_host(host), m_port(port), m_maxRetries(maxRetries),
      m_maxWaitingTime_us(maxWaitingTime_us)
  {
    fileLogger = FileLoggerFactory::getInstance().createFileLogger(logFileName);
    if (!connectToDaemon()) {
        fileLogger->LOG(Error, std::string("Could not connect to gpsd: ") +
                               std::string(gps_errstr(errno)));
        return;
    }
  }

  GpsWrapper::~GpsWrapper() {
    disconnectFromDaemon();
  }

  void GpsWrapper::setMaxRetries(const unsigned int maxRetries) {
    m_maxRetries = maxRetries;
  }

  void GpsWrapper::setMaxWaitingTime_us(const int maxWaitingTime_us) {
    m_maxWaitingTime_us = maxWaitingTime_us;
  }

  void GpsWrapper::readGpsData(struct gps_data_t &gpsData_out)
  {
    // gps_stream(&gpsData, WATCH_ENABLE | WATCH_JSON, NULL);

    bool hasFix = false;
    unsigned int retries = 0;

    while (!hasFix && (retries <= m_maxRetries)) {
      if (!gps_waiting(&gpsData, m_maxWaitingTime_us)) {
        if (errno < 0) {
          fileLogger->LOG(Error, std::string("Could not wait for data: ") +
                                 std::string(gps_errstr(errno)));
        } else {
          PRINT_DEBUG("gps_waiting: TIMEOUT.\n");
        }
      } else {

        int readBytes = gps_read(&gpsData);
        if (-1 == readBytes) {
          fileLogger->LOG(Error, std::string("gps_read error: ") +
                                 std::string(gps_errstr(errno)));
        } else if (0 == readBytes) {
          fileLogger->LOG(Error, std::string("There is not GPS data: ") +
                                 std::string(gps_errstr(errno)));
        } else {
          hasFix = this->hasFix();
  	  if (hasFix) {
            PRINT_DEBUG("FIX\n");
          } else {
            PRINT_DEBUG("NO FIX\n");
          }
        }
      }

      retries++;
      // gps_stream(&gpsData, WATCH_ENABLE | WATCH_JSON, NULL);
    } // end loop

    gpsData_out = gpsData;
    gps_clear_fix(&(gpsData.fix));  // data is clear for next read.
    // gps_stream(&gpsData, WATCH_DISABLE, NULL);

    return;
  }

  bool GpsWrapper::connectToDaemon (void) {
    const int ret = gps_open(m_host, m_port, &gpsData);
    const bool err = (ret != 0);
    if (!err) {
      gps_stream(&gpsData, WATCH_ENABLE | WATCH_JSON, NULL);
    }

    return !err;
  }

  void GpsWrapper::disconnectFromDaemon (void) {
    gps_stream(&gpsData, WATCH_DISABLE, NULL);
    gps_close(&gpsData);
  }

  bool GpsWrapper::hasFix(void) {
    return ( (gpsData.status != STATUS_NO_FIX) &&
             (gpsData.fix.mode == MODE_2D || gpsData.fix.mode == MODE_3D) &&
             isfinite(gpsData.fix.time) && isfinite(gpsData.fix.latitude) &&
             isfinite(gpsData.fix.longitude) && (gpsData.set & TIME_SET)
           );
  }

}
