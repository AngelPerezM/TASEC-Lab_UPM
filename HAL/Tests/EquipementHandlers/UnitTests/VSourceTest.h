#include "EquipementHandlers/GroveAdcHat.h"
#include "Utils/CSVWriter.h"
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

    VSourceTest () : csv(",") {
      ;
    }

    void mySetUP () {
      nSamples = std::get<0>(GetParam());
      samplingFrec = (std::get<1>(GetParam()));
    }

    std::string getNameOfLog(void) {
      return "Vcc_" + getTimeStr() + "_" + std::to_string(nSamples) + "-" + 
             std::to_string(1/samplingFrec) + ".csv";
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
    int nSamples;
    float samplingFrec;

    float normalVcc = 2600; // mv
    float vccMaxError = 19; // mv
};

TEST_F (VSourceTest, MAXHzSampling) {
  nSamples = 1000;
  uint16_t samples [nSamples];

  for (int i = 0; i < nSamples; ++i) {
    (void) adc.get_nchan_vol_milli_data(5, samples[i]);
  }

  csv.newRow() << "VCC";
  for (int i = 0; i < nSamples; ++i) {  
    float vcc = samples[i];
    csv.newRow() << vcc;
    EXPECT_NEAR(vcc, normalVcc, vccMaxError);
  }

  csv.writeToFile("Logs/Vcc_" + getTimeStr()+"_"+std::to_string(nSamples)+"MAXHz.csv",
                  true);
}


/* Test with parameters.
 ******************************************************************************/
TEST_P (VSourceTest, LogVccSamples) {
  mySetUP();
  uint16_t samples [nSamples];
  int i = 0;
  periodicTask_frec
    (samplingFrec, nSamples, 
      [this, &samples, &i]() {
       (void) adc.get_nchan_vol_milli_data(5, samples[i]);
        i++;
      }
    );
  
  csv.newRow() << "VCC";
  for (int i = 0; i < nSamples; ++i) {  
    float vcc = samples[i];
    csv.newRow() << vcc;
    EXPECT_NEAR(vcc, normalVcc, vccMaxError);
  }

  csv.writeToFile("Logs/"+getNameOfLog(), true);
}
