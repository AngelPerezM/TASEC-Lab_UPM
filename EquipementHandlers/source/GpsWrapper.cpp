#include "GpsWrapper.h"
#include <stdio.h>
#include <errno.h>
#include <math.h>   // isfinite
#include "Utils/Debug.h"

namespace equipementHandlers {

  GpsWrapper::GpsWrapper(const char *host, const char *port, 
                         const unsigned int maxRetries)
    : m_host(host), m_port(port), m_maxRetries(maxRetries)
  {
    ;
  }

  GpsWrapper::~GpsWrapper() {
    ;
  }

  void GpsWrapper::setMaxRetries(const unsigned int maxRetries) {
    m_maxRetries = maxRetries;
  }

  bool GpsWrapper::readGpsData(struct gps_data_t &gpsData_out)
  {
    if (!connectToDaemon()) { return false; }

    bool hasData = false;
    unsigned int retries = 0;

    while (!hasData && retries <= m_maxRetries) {
      if (!gps_waiting(&gpsData, 500000)) { // 500 ms
        if (errno < 0) {
          printf("gps_waiting. Error %d. %s\n", errno, gps_errstr(errno));
        } else {
          PRINT_DEBUG("gps_waiting: TIMEOUT.\n");
        }
      } else {
        errno = 0;
        gps_clear_fix(&(gpsData.fix));

        int readBytes = gps_read(&gpsData);
        if (-1 == readBytes) {
          printf("gps_read. Error %d. %s\n", errno, gps_errstr(errno));
        } else if (0 == readBytes) {
          puts("There is not GPS available data.");
        } else {
          hasData = isDataCorrect();
          if (!hasData) {
            retries++;
          }
        }
      }
    } // end loop

    gpsData_out = gpsData;
    disconnectFromDaemon();

    return hasData;
  }

  bool GpsWrapper::connectToDaemon (void) {
    const int ret = gps_open(m_host, m_port, &gpsData);
    const bool err = (ret != 0);
    if (err) {
      printf("gps_open: Error %d. %s\n", errno, gps_errstr(errno));
    } else {
      gps_stream(&gpsData, WATCH_ENABLE | WATCH_JSON, NULL);
    }

    return !err;
  }

  void GpsWrapper::disconnectFromDaemon (void) {
    gps_stream(&gpsData, WATCH_DISABLE, NULL);
    gps_close(&gpsData);
  }

  bool GpsWrapper::isDataCorrect(void) {
    return ( (gpsData.status == STATUS_FIX) &&
             (gpsData.fix.mode == MODE_2D || gpsData.fix.mode == MODE_3D) &&
             isfinite(gpsData.fix.time) && isfinite(gpsData.fix.latitude) &&
             isfinite(gpsData.fix.longitude) && (gpsData.set & TIME_SET)
            );
  }

}
