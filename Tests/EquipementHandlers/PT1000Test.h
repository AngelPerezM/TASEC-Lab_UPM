#include "EquipementHandlers/PT1000.h"
#include "EquipementHandlers/GroveAdcHat.h"

#include <unistd.h>
#include <iostream>
#include <sys/time.h>
#include "gtest/gtest.h"
#include <fstream>
#include <tuple>  // for multi params in TEST SUIT
#include <math.h>
#include <chrono> // To get curr time for log file name.


using namespace equipementHandlers;

class PT1000Test : public testing::TestWithParam<std::tuple<int, float>> {
  protected:

    PT1000Test() :
      pt1000(1)
    {
      pt1000.activateVccCorrection(5);  // Vcc connected to channel 5
      // pt1000.setVoltageSource(5.2);
    }

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
      time_t now = time(0);
      struct tm tstruct = *localtime(&now);
      char timeStr[81];
      strftime(timeStr, sizeof(timeStr), "%Y-%m-%d_%X", &tstruct);

      return "PT1000_" + std::string(timeStr) + "_" + std::to_string(n_samples) + "-" + 
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
    PT1000 pt1000;  // channel 0
    int n_samples = 0;
    float samplingPeriod = 0;
    struct timespec period;
};

TEST_P (PT1000Test, MAXHzSampling) {
  mySetUP();
  float samples [n_samples];
  
  for (int i = 0; i < n_samples; ++i) {
    samples[i] = pt1000.getTempCelsius();
  }

  std::ofstream ofs;
  ofs.open("Logs/PT1000_"+getTimeStr()+"_"+std::to_string(n_samples)+"MAXHz.csv", 
           std::ios::out);
  ofs << "PT1000" << std::endl;
  for (int i = 0; i < n_samples; ++i) {  
    ofs << samples[i] << std::endl;
  }
}

/*
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

TEST_F (PT1000Test, Vcc_vs_PT1000) {

  int n_samples = 1000.0;
  float samples_vcc [n_samples];
  float samples_pt1000 [n_samples];
  for (int i = 0; i < n_samples; ++i) {  
    samples_vcc[i] = adc.get_nchan_vol_milli_data(5)/500.0;
    samples_pt1000[i] = adc.get_nchan_vol_milli_data(0)/500.0;
  } 


  std::ofstream ofs;
  ofs.open("Logs/pt1000_vs_vcc.csv", std::ios::out);
  ofs << "Vcc, ADC Vin" << std::endl;
  for (int i = 0; i < n_samples; ++i) {  
    ofs << samples_vcc[i] << ", " << samples_pt1000[i] <<std::endl;
  }

}
*/
