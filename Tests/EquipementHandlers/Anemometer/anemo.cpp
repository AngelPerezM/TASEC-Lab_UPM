#include "EquipementHandlers/Anemometer.h"
#include "PeriodicTask.h"
#include <unistd.h> // Getopt
#include <iostream>
#include <sys/time.h>
#include <algorithm>
#include <functional>
using namespace equipementHandlers;

int main(int argc, char **argv) {

  float report
    void testWithWaveforms(float freq, int nPulses) {
      hw.setFreq(freq);
      this->hw.startPulseGeneration();

      // COUNT -->
      struct timespec begin;
      struct timespec timeInterval = secondsToTimespec( (float (nPulses))/freq );
      if(clock_gettime(CLOCK_MONOTONIC, &begin) < 0) {
        perror("clock_gettime");
      } else {
        begin.tv_sec += timeInterval.tv_sec;
        begin.tv_nsec += timeInterval.tv_nsec;
      }
      this->a.setCounter(0);
      this->a.startCounting();
      if(clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &begin, 0) < 0) {
        perror("clock_nanosleep");
      }
      this->a.stopCounting();
      // COUNT <--

      this->hw.stopPulseGeneration();

      EXPECT_NEAR(this->a.getCounter(), nPulses, 2);
    }

    Anemometer a;
    AnemometerHW hw;
};

TEST_F (AnemometerTest, ZeroPulses) {
  a.startCounting();
  usleep(1000000);
  a.stopCounting();
  int counter = a.getCounter();
  EXPECT_EQ(counter, 0);
}

TEST_F (AnemometerTest, FewPulsesLowFreq) {
  hw.setFreq(50); // HZ
  for(int nPulses = 1; nPulses <= 20; ++nPulses) {
    this->a.startCounting();
    this->a.setCounter(0);
    this->hw.generateNPulses_LOFI(nPulses);
    usleep(1000);
    this->a.stopCounting();
    EXPECT_EQ(this->a.getCounter(), nPulses);
  }
}

TEST_P (AnemometerTest, FewPulsesHighFreqLOFI) {
  hw.setFreq(GetParam());
  int nPulses = 100;
  this->a.startCounting();
  this->a.setCounter(0);
  this->hw.generateNPulses_LOFI(nPulses);
  usleep(1000);
  this->a.stopCounting();
  EXPECT_EQ(this->a.getCounter(), nPulses);
}

TEST_P (AnemometerTest, LotOfPulsesHighFreqLOFI) {
  hw.setFreq(GetParam());
  int nPulses = 1500;
  this->a.startCounting();
  this->a.setCounter(0);
  this->hw.generateNPulses_LOFI(nPulses);
  usleep(1000);
  this->a.stopCounting();
  EXPECT_EQ(this->a.getCounter(), nPulses);
}

TEST_P (AnemometerTest, checkFewPulsesHighFreq) {
  float freq = GetParam();
  int nPulses = 500;
  testWithWaveforms(freq, nPulses);
}

TEST_P (AnemometerTest, checkLotOfPulsesHighFreq) {
  float freq = GetParam();
  int nPulses = 5000;
  testWithWaveforms(freq, nPulses);
}

INSTANTIATE_TEST_CASE_P(HighFreqTests, AnemometerTest,
                        ::testing::Values(500, 700, 1000, 1200, 1500)); // HZ
