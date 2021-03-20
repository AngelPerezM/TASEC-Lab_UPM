/* IMPORTANT:
 *
 * This program works only if the GPS dev was registered with the comand: 
 * sudo gpsd /dev/<path_to_gps> -F /var/run/gpsd.sock
 ******************************************************************************/

#include "GPS.t.h"
#include <stdio.h>
#include <unistd.h> // usleep
#include <errno.h>  // errno

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

void test_gps (void) {
  GpsWrapper gpsw;
  gpsw.setMaxRetries(5);
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
}
