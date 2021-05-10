#include "EquipementHandlers/PT1000.h"
#include "EquipementHandlers/GroveAdcHat.h"
#include "Utils/CSVWriter.h"

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

    PT1000Test() : csv(","), pt1000(1)
    {
      pt1000.activateVccCorrection(5);  // Vcc connected to channel 5
      pt1000.setFIRNSamples(10);
    }

    void mySetUP () {
      nSamples = std::get<0>(GetParam());
      samplingFrec = std::get<1>(GetParam());
    }

    std::string getNameOfLog(void) {
      time_t now = time(0);
      struct tm tstruct = *localtime(&now);
      char timeStr[81];
      strftime(timeStr, sizeof(timeStr), "%Y-%m-%d_%X", &tstruct);

      return "PT1000Test_" + std::string(timeStr) + "_" + std::to_string(nSamples) + "-" + 
             std::to_string(samplingFrec) + ".csv";
    }

    std::string getTimeStr(void) {
      time_t now = time(0);
      struct tm tstruct = *localtime(&now);
      char timeStr[81];
      strftime(timeStr, sizeof(timeStr), "%Y-%m-%d_%X", &tstruct);
      return std::string(timeStr);
    }

    CSVWriter csv;
    GroveAdcHat &adc = GroveAdcHat::getInstance();
    PT1000 <GroveAdcHat> pt1000;  // channel 0
    int nSamples = 0;
    float samplingFrec = 0;


    // Typical values from Vcc and temperature:
    float tempMaxerror = 2;
    float normalTemp = 22;

    float normalVcc = 2600; // mv
    float vccMaxError = 19; // mv
};

/*
TEST_F (PT1000Test, MAXHzSampling) {
  nSamples = 200;
  float samples [nSamples];
  
  for (int i = 0; i < nSamples; ++i) {
    samples[i] = pt1000.getTempCelsius();
  }

  csv.newRow() << "PT1000";
  for (int i = 0; i < nSamples; ++i) {  
    csv.newRow() << samples[i];
    EXPECT_NEAR(samples[i], normalTemp, tempMaxerror);
  }
  csv.writeToFile("Logs/PT1000Test_"+getTimeStr()+"_"+std::to_string(nSamples)+"_MAXHz.csv");
  std::cout << "Fin pt1000\n";
}
*/

/*
TEST_F (PT1000Test, VccAndPT1000) {
  nSamples = 1000.0;
  samplingFrec = 10.0;  // 10 HZ

  float samples_vcc [nSamples];
  float samples_pt1000 [nSamples];

  int i = 0;
  periodicTask_frec
    (samplingFrec, nSamples, 
      [this, &samples_vcc, &samples_pt1000, &i]() {
        samples_vcc[i] = adc.get_nchan_vol_milli_data(5);
        samples_pt1000[i] = adc.get_nchan_vol_milli_data(0);
        i++;
      }      
    );

  csv.newRow() << "VCC channel" << "PT1000 channel";
  for (int i = 0; i < nSamples; ++i) {
    float vcc = samples_vcc[i];
    float pt1000 = samples_pt1000[i];
    csv.newRow() << vcc << pt1000;
    EXPECT_NEAR(vcc, normalVcc, vccMaxError);
  }

  csv.writeToFile("Logs/VccAndPT1000_"+getNameOfLog());
}
*/

/* Test with parameters.
 ******************************************************************************/

TEST_P (PT1000Test, LogPT1000Samples) {
  mySetUP();
  float samples [nSamples];

  int i = 0;
  periodicTask_frec
    (samplingFrec, nSamples, 
      [this, &samples, &i]() {
        samples[i] = pt1000.getTempCelsius();
        i++;
      }      
    );
  
  std::ofstream ofs;
  std::cout << getNameOfLog() << std::endl;
  ofs.open("Logs/"+getNameOfLog(), std::ios::out);
  ofs << "PT1000" << std::endl;
  for (int i = 0; i < nSamples; ++i) {  
    ofs << samples[i] << std::endl;
    EXPECT_NEAR(samples[i], normalTemp, tempMaxerror);
  }
}
