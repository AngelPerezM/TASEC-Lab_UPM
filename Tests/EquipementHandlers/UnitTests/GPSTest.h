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

      printf("-------------------------------------------------------------\n");
    }

    void readGPSPeriodically (int nSamples, struct timespec period) {
      periodicTask
        ( period, nSamples,
           [this, period] () {
             gps_data_t gpsData;
             gpsw.readGpsData(gpsData);
             print_gps_data(gpsData);

	     static double prevTime = 0;
             double currTime = gpsData.fix.time;
	     if (isfinite(currTime)) {
	     	EXPECT_NE(currTime, 0);
		std::cout << "TIMESTAMP: " << currTime << std::endl;
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

TEST_F (GPSTest, CheckData_5secs) {
  gpsw.setMaxRetries(5);
  gpsw.setMaxWaitingTime_us(500000);
  readGPSPeriodically(10, {.tv_sec = 5, .tv_nsec = 0});
}

TEST_F (GPSTest, CheckData_1secs) {
  gpsw.setMaxRetries(5);
  gpsw.setMaxWaitingTime_us(500000);
  readGPSPeriodically(10, {.tv_sec = 1, .tv_nsec = 0});
}

TEST_F (GPSTest, CheckData_5secs_50msWait) {
  gpsw.setMaxRetries(5);
  gpsw.setMaxWaitingTime_us(50000);
  readGPSPeriodically(5, {.tv_sec = 5, .tv_nsec = 0});
}

TEST_F (GPSTest, CheckData_1secs_100msWait) {
  gpsw.setMaxRetries(5);
  gpsw.setMaxWaitingTime_us(100000); 
  readGPSPeriodically(5, {.tv_sec = 1, .tv_nsec = 0});
}

TEST_F (GPSTest, CheckData_1secs_150msWait) {
  gpsw.setMaxRetries(5);
  gpsw.setMaxWaitingTime_us(150000); 
  readGPSPeriodically(5, {.tv_sec = 1, .tv_nsec = 0});
}

TEST_F (GPSTest, CheckData_1secs_200msWait) {
  gpsw.setMaxRetries(5);
  gpsw.setMaxWaitingTime_us(200000); 
  readGPSPeriodically(5, {.tv_sec = 1, .tv_nsec = 0});
}

TEST_F (GPSTest, CheckData_1secs_500msWait) {
  gpsw.setMaxRetries(5);
  gpsw.setMaxWaitingTime_us(500000); 
  readGPSPeriodically(5, {.tv_sec = 1, .tv_nsec = 0});
}

TEST_F (GPSTest, CheckData_1secs_1000msWait) {
  gpsw.setMaxRetries(3);
  gpsw.setMaxWaitingTime_us(1000000); 
  readGPSPeriodically(5, {.tv_sec = 1, .tv_nsec = 0});
}
