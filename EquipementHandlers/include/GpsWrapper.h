#ifndef GPS_WRAPPER_H
#define GPS_WRAPPER_H

#include <gps.h> // C library to be wrapped.

namespace equipementHandlers {

  /**
   * TODO:
   * The real purpose of this class is to wrap the read operation from the GPS,
   * so maybe GpsReader is a better name.
   */ 
  class GpsWrapper {
    public:
      GpsWrapper(const char *host = "localhost",
                 const char *port = DEFAULT_GPSD_PORT,
                 const unsigned int maxRetries = 0);

      ~GpsWrapper();

      void setMaxRetries(const unsigned int maxRetries);

      void setReadConstraints(gps_mask_t constraints);

      bool readGpsData(struct gps_data_t &gpsData_out);

    private:
      const char *m_host;
      const char *m_port;
      struct gps_data_t gpsData;  // Struct where the read data is stored.
      unsigned int m_maxRetries;

      bool connectToDaemon();
      void disconnectFromDaemon();
      bool isDataCorrect();
  };
}

#endif // GPS_WRAPPER_H
