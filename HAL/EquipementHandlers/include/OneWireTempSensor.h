#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include <vector>
#include <string>

namespace equipementHandlers {
  class OneWireTempSensor {
    private:
      const char *w1DevsPath= "/sys/bus/w1/devices";
      const char *slaveFile = "w1_slave";
      std::vector <std::string> sensorsName;
      std::vector <std::string> sensorsReadChannel;

    public:

      // CONSTRUCTORS

      OneWireTempSensor();

      // DESTRUCTORS

      // ACCESORS

      std::vector<float> getAllTempsCelsius();

      bool getTempCelsius(float /*out*/ &celsiusTemp, int i);

      // MANIPULATORS

    private:

      void setUpSensorsInfo();
  };
}

#endif
