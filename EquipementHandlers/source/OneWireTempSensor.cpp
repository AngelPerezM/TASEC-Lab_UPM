#include "OneWireTempSensor.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <cstring>
#include <iostream>

namespace equipementHandlers {

  OneWireTempSensor::OneWireTempSensor() {
    setUpSensorsInfo();
  }

  std::vector<float> OneWireTempSensor::getAllTempsCelsius() {
    std::vector<float> temps;
    float temp;
    for (int i = 0; (size_t)i < sensorsName.size(); ++i) {	
      if(getTempCelsius(temp, i))
        temps.push_back(temp);
    }
    return temps;
  }    

  bool OneWireTempSensor::getTempCelsius(float /*out*/ &celsiusTemp, int i) {
    bool dataAvailable = false;

    const char *readChannel = sensorsReadChannel[i].c_str();
    int fd = open(readChannel, O_RDONLY);
    if (fd < 0) {
      perror("open");
    } else {
      char data [100];
      dataAvailable = (read(fd, data, sizeof(data)) > 0) && strstr(data, "YES");
      if(dataAvailable) {
        char *tempStr = strstr(data, "t=");
        sscanf(tempStr, "t=%f", &celsiusTemp);
        celsiusTemp /= 1000.0;
      }
      close(fd);
    }

    return dataAvailable;
  }

  void OneWireTempSensor::setUpSensorsInfo() {
    DIR *dirp = NULL;
    if ((dirp = opendir(w1DevsPath)) == NULL) {
      perror("opendir");
    } else {
      char sensorName [16];
      char sensorReadChannel[81];
      struct dirent *direntp;
      while(((direntp = readdir(dirp)) != NULL)) {
        if (strstr(direntp->d_name, "28-") != NULL) {
          strcpy(sensorName, direntp->d_name);
          sensorsName.push_back(std::string (sensorName));
          sprintf(sensorReadChannel, "%s/%s/%s", w1DevsPath, sensorName, slaveFile);
          sensorsReadChannel.push_back(std::string(sensorReadChannel));
          std::cout << "Sensor name: " << sensorName << std::endl;
          std::cout << "Sensor read channel: " << sensorReadChannel << std::endl;
        }
      }
    }

  }

};
