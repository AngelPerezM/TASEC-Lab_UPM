/* IMPORTANT:
 *
 * This program works only if the GPS dev was registered with the comand: 
 * sudo gpsd /dev/<path_to_gps> -F /var/run/gpsd.sock
 ******************************************************************************/

#include "GPS.t.h"
#include <gps.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <errno.h>  // errno
#include <stdbool.h>
#include <string.h> // memset

#include "EquipementHandlers/GpsWrapper.h"
using namespace equipementHandlers;

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

static bool my_get_gpsdata (const int maxRetries) {

  struct gps_data_t gpsData;
  bool thereWasData = false;
  int retries = 1;

  // OPEN:
  // Client apps communicate with gpsd via TCP/IP port 2947, by default.
  int ret = gps_open("localhost", "2947", &gpsData);
  if (ret < 0) {
    gps_errstr(errno);
    perror("gps_open.");
    return thereWasData;
  }

  gps_stream(&gpsData, WATCH_ENABLE | WATCH_JSON, NULL);

  // PROCESS DATA:
  while (!thereWasData && retries <= maxRetries) {
    // MAX 1 second waiting:
    if (!gps_waiting(&gpsData, 1000000)) { // usec.
      // Timeout, no waiting data:
      printf("gps_waiting. Error %d. %s\n", errno, gps_errstr(errno));
    } else {
      errno = 0;
      gps_clear_fix(&(gpsData.fix));

      int readBytes = gps_read(&gpsData);
      if (-1 == readBytes) {
        printf("gps_read. Error %d. %s\n", errno, gps_errstr(errno));
      } else if (0 == readBytes) {
        puts("There is not GPS availabe data. :(");
      } else {
        // Display data from GPS receiver:
        // Tiny race window between gps_waiting and gps_read.
        thereWasData = 
          ( (gpsData.status == STATUS_FIX) &&
            (gpsData.fix.mode == MODE_2D || gpsData.fix.mode == MODE_3D) &&
            isfinite(gpsData.fix.time) && isfinite(gpsData.fix.latitude) &&
            isfinite(gpsData.fix.longitude) && (gpsData.set & TIME_SET) );
        if (thereWasData) {
          print_gps_data(gpsData);
        } else {
          retries++;
        }

      }

    }
  } // end loop

  // CLOSE:
  gps_stream(&gpsData, WATCH_DISABLE, NULL);
  gps_close(&gpsData);

  printf("Number of retries: %d\n", retries);
  return thereWasData;
}

void test_gps (void) {
  GpsWrapper gpsw;
  gpsw.setMaxRetries(5);
  for(int i = 0; i < 100; ++i) {
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
}

void test_gps_old3 (void) {
  for(int i = 0; i < 100; ++i) {
    bool thereWasData = my_get_gpsdata(10);
    printf("%s\n--------------\n", thereWasData?"Hubo datos":"No hubo datos");
    usleep(1000000);
  }
}

void test_gps_old2 (void) {
  
  struct gps_data_t gpsData;

  // OPEN:
  // Client apps communicate with gpsd via TCP/IP port 2947, by default.
  int ret = gps_open("localhost", "2947", &gpsData);
  if (ret < 0) {
    gps_errstr(errno);
    perror("gps_open.");
    return;
  }

  gps_stream(&gpsData, WATCH_ENABLE | WATCH_JSON, NULL);

  // PROCESS DATA:
  for (int i = 0; i < 40; ++i) {

    int waitRetries = 0;
    // 0.5 seconds waiting:
    if (!gps_waiting(&gpsData, 500000)) { // usec.
      // Timeout, no waiting data:
      gps_errstr(errno);
      perror("gps_waiting: TIMEOUT.");
      // 120 retires <-> 60 seconds <-> 1 minute of MAX waiting.
      if (120 < waitRetries++) {
        printf("There was no data after %d retries.\n", waitRetries);
        goto getout;
      }

    } else {
      errno = 0;
      waitRetries = 0;
      gps_clear_fix(&(gpsData.fix));

      int nanRetries = 0;
      int readBytes = gps_read(&gpsData);
      if (-1 == readBytes) {
        gps_errstr(errno);
        perror("gps_read");

      } else if (0 == readBytes) {
        puts("There is not GPS availabe data. :(");

      } else {
        // Display data from GPS receiver:
        // Tiny race window between gps_waiting and gps_read.
        if (// (gpsData.status == STATUS_FIX) &&
             (gpsData.fix.mode == MODE_2D || gpsData.fix.mode == MODE_3D) &&
             isfinite(gpsData.fix.time) &&
            // isfinite(gpsData.fix.latitude) &&
            // isfinite(gpsData.fix.longitude) &&
             (gpsData.set & TIME_SET))
        {
          nanRetries = 0;
          print_gps_data(gpsData);
          sleep(3);
        } else {
          printf("Unknown variables (NaN).\n");
          if (4 < nanRetries++) {
            printf("There was NaN data after %d retries.\n", nanRetries);
            goto getout;
          }
          // print_gps_data(gpsData);
        }

      }

    }
  } // end loop

getout:
  // CLOSE:
  gps_stream(&gpsData, WATCH_DISABLE, NULL);
  gps_close(&gpsData);

}

void test_gps_old () {
  struct gps_data_t gps_data;

  if ((gps_open("localhost", "2947", &gps_data)) == -1) {
    printf("code: %d, reason: %s\n", errno, gps_errstr(errno));
    return;
  }
  gps_stream(&gps_data, WATCH_ENABLE | WATCH_JSON, NULL);

  while (1) {
    /* wait for 2 seconds to receive data */
    if (gps_waiting (&gps_data, 2000000)) {
      /* read data */
      if ((gps_read(&gps_data)) == -1) {
        printf("error occured reading gps data. code: %d, reason: %s\n", errno, gps_errstr(errno));
      } else {
        /* Display data from the GPS receiver. */
        if ((gps_data.set & TIME_SET)) {
          //gettimeofday(&tv, NULL); EDIT: tv.tv_sec isn't actually the timestamp!
          printf("latitude: %f, longitude: %f, speed: %f, timestamp: %lf\n", gps_data.fix.latitude, gps_data.fix.longitude, gps_data.fix.speed, gps_data.fix.time); //EDIT: Replaced tv.tv_sec with gps_data.fix.time
        } /* else {
          printf("no GPS data available\n");
        }*/
        gps_clear_fix(&(gps_data.fix));
      }
    }

    sleep(1);
  }

  /* When you are done... */
  gps_stream(&gps_data, WATCH_DISABLE, NULL);
  gps_close (&gps_data);

  return;
}
