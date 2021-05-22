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

      printf("-------------------------------------------------------------\n");
      printf("- Time: %s\n", buf);
      printf("- Satellites used: %d\n", gpsData.satellites_used);
      printf("- Online: %.7f\n", gpsData.online);
      printf("- Latitude: %f.\n- Longitude: %f\n", 
          gpsData.fix.latitude, gpsData.fix.longitude);
      printf("- Speed over gnd: %f.\n- Vertical speed [m/s] %f\n",
          gpsData.fix.speed, gpsData.fix.climb);
    }

    void readGPSPeriodically (struct timespec period) {
      gpsw.setMaxRetries(5);
      gpsw.setMaxWaitingTime_us(500000);
      int n_samples = 15;
      periodicTask
        ( period, n_samples,
           [this, period] () {
             gps_data_t gpsData;
             gpsw.readGpsData(gpsData);
             print_gps_data(gpsData);

	     static double prevTime = 0;
             double currTime = gpsData.fix.time;
	     if (isfinite(currTime)) {
		EXPECT_NEAR(currTime, prevTime + period.tv_sec, 1);
		prevTime = currTime;
	     }
             if (isfinite(gpsData.fix.longitude)) {
	       EXPECT_NEAR(gpsData.fix.longitude, normalLongitude, 0.0003);
             }
             if (isfinite(gpsData.fix.latitude)) {
               EXPECT_NEAR(gpsData.fix.latitude, normalLatitude, 0.0003); 
             }
           }
       );
    }

    GpsWrapper gpsw;

    // Coordinates in my house:
    float normalLatitude = 40.43757736771615;
    float normalLongitude = -3.6724481490453966;
};

TEST_F (GPSTest, CheckTimeConsistency_5secs) {
  readGPSPeriodically({.tv_sec = 5, .tv_nsec = 0});
}

TEST_F (GPSTest, CheckTimeConsistency_1secs) {
  readGPSPeriodically({.tv_sec = 1, .tv_nsec = 0});
}

TEST_F (GPSTest, CheckCoordinates) {
  gpsw.setMaxRetries(5);
  gpsw.setMaxWaitingTime_us(1000000);
  int n_samples = 15;
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
}
