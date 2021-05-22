/* IMPORTANT:
 *
 * This program works only if the GPS dev was registered with the comand: 
 * sudo gpsd /dev/<path_to_gps> -F /var/run/gpsd.sock
 ******************************************************************************/

#include <math.h>   // isfinite
#include <stdio.h>
#include <unistd.h> // usleep
#include <errno.h>  // errno
#include <gtest/gtest.h>
#include "PeriodicTask.h"
#include "EquipementHandlers/GpsWrapper.h"

using namespace equipementHandlers;

class GPSTest : public testing::Test {
  protected:

    void print_gps_data (const gps_data_t gpsData) {
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

    GpsWrapper gpsw;

    // Coordinates in my house:
    float normalLatitude = 40.43757736771615;
    float normalLongitude = -3.6724481490453966;
};

TEST_F (GPSTest, CheckCoordinates) {
  gpsw.setMaxRetries(5);
  int n_samples = 7;
  struct timespec period = {.tv_sec = 1, .tv_nsec = 0};
  periodicTask
    ( period, n_samples,
      [this, &n_samples] () {
        gps_data_t gpsData;
        gpsw.readGpsData(gpsData);
        print_gps_data(gpsData);
        if (isfinite(gpsData.fix.longitude)) {
            EXPECT_NEAR(gpsData.fix.longitude, normalLongitude, 0.0003);
        }
        if (isfinite(gpsData.fix.latitude)) {
            EXPECT_NEAR(gpsData.fix.latitude, normalLatitude, 0.0003); 
        }
      }
    );

  /*
  for(int i = 0; i < 10; ++i) {
    gps_data_t gpsData;
    bool hasData = gpsw.readGpsData(gpsData);
    if (hasData) {
      print_gps_data(gpsData);
      puts("- Has data");
    } else {
      puts("- Does not have data");
    }
    puts("----------");
    usleep(1000000);
  }
  */
}
