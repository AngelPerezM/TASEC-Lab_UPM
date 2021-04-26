#include "EquipementHandlers/GroveAdcHat.h"
#include "PeriodicTask.h"
#include <unistd.h>
#include <iostream>
#include <sys/time.h>
#include <fstream>
#include <tuple>  // for multi params in TEST SUIT
#include <math.h>
#include <chrono> // To get curr time for log file name.
#include "gtest/gtest.h"


using namespace equipementHandlers;

// Params: NSamples, Sample freq (Hz).
class VSourceTest : public testing::TestWithParam<std::tuple<int, float>> {
  protected:
    void mySetUP () {
      n_samples = std::get<0>(GetParam());
      samplingPeriod = 1.0/(std::get<1>(GetParam()));

      period.tv_sec = (int) samplingPeriod; // truncate

      float fracPart = 0.0;
      modff(samplingPeriod, &fracPart);
      period.tv_nsec = (int) (fracPart*1E9);

      std::cout << period.tv_sec << " secs, " << period.tv_nsec << "nsecs" << std::endl;
    }

    std::string getNameOfLog(void) {
      return "Vcc_" + getTimeStr() + "_" + std::to_string(n_samples) + "-" + 
             std::to_string(1/samplingPeriod) + ".csv";
    }

    std::string getTimeStr(void) {
      time_t now = time(0);
      struct tm tstruct = *localtime(&now);
      char timeStr[81];
      strftime(timeStr, sizeof(timeStr), "%Y-%m-%d_%X", &tstruct);
      return std::string(timeStr);
    }

    GroveAdcHat &adc = GroveAdcHat::getInstance();
    int n_samples;
    float samplingPeriod;
    struct timespec period;
};

/*
TEST_P (VSourceTest, VccStatistics) {
  mySetUP();

  float v = 0.0;
  float mean_v = 0.0;
  float v_min = 5.1;
  float v_max = 0.0;
 
  float drift = 0.0;
  float mean_drift = 0.0;
  float drift_min = 5.1;
  float drift_max = 0.0;

  // float n_samples = 1000.0;

  for (int i = 0; i < n_samples; ++i) {
    v = adc.get_nchan_vol_milli_data(5)/500.0;
    drift = (5.1-v);
    // std::cout << "Vread: " << v << std::endl;
    // std::cout << " diff: " << drift << std::endl;
    mean_v += v;
    mean_drift += drift;

    v_min = (v < v_min) ? (v) : (v_min);
    v_max = (v > v_max) ? (v) : (v_max);
    drift_min = (drift < drift_min) ? (drift) : (drift_min);
    drift_max = (drift > drift_max) ? (drift) : (drift_max);
  }

  std::cout << "Media de Variaciones: " << mean_drift/n_samples << std::endl;
  std::cout << "Media de Vcc: " << mean_v/n_samples << std::endl;
  std::cout << "Valores de Vcc: [" << v_min << ", " << v_max << "]" << std::endl;
  std::cout << "Valores de Drift: [" << drift_min << ", " << drift_max << "]" << std::endl;
  }
  */
TEST_P (VSourceTest, MAXHzSampling) {
  mySetUP();
  float samples [n_samples];
  
  for (int i = 0; i < n_samples; ++i) {
    samples[i] = adc.get_nchan_vol_milli_data(5)/500.0;
  }

  std::ofstream ofs;
  ofs.open("Logs/Vcc_" + getTimeStr()+"_"+std::to_string(n_samples)+"MAXHz.csv", 
           std::ios::out);
  ofs << "VCC" << std::endl;
  for (int i = 0; i < n_samples; ++i) {  
    ofs << samples[i] << std::endl;
  }
}

TEST_P (VSourceTest, LogVccSamples) {
  mySetUP();
  float samples [n_samples];
  int i = 0;
  periodicTask
    (period, n_samples, 
      [this, &samples, &i]() {
        samples[i] = adc.get_nchan_vol_milli_data(5)/500.0;
        i++;
      }      
    );
  
  std::ofstream ofs;
  std::cout << getNameOfLog() << std::endl;
  ofs.open("Logs/"+getNameOfLog(), std::ios::out);
  ofs << "VCC" << std::endl;
  for (int i = 0; i < n_samples; ++i) {  
    ofs << samples[i] << std::endl;
  }
}
