#include "EquipementHandlers/Anemometer.h"
#include "PeriodicTask.h"
#include <unistd.h>
#include <iostream>
#include <sys/time.h>
#include <gtest/gtest.h>
#include <algorithm>
#include <functional>
#include <pigpiod_if2.h>
using namespace equipementHandlers;

/*
 * mocks the hardware.
 **/
class AnemometerHW {
  private:
    int m_pigpioHdlr;
    // int m_range;
    // int m_realRange;
    float m_freq;
    unsigned m_outputPin;

    int m_waveid;
  
  public:
    AnemometerHW (float freq, unsigned outputPin) :
      m_freq(freq), m_outputPin(outputPin)
    {
      m_pigpioHdlr = pigpio_start(NULL, NULL);
      set_mode(m_pigpioHdlr, m_outputPin, PI_OUTPUT);
      gpio_write(m_pigpioHdlr, m_outputPin, 0);
    }

    ~AnemometerHW() {
      std::cout << "~Anemometer" << std::endl;
      gpio_write(m_pigpioHdlr, m_outputPin, PI_INPUT);
      pigpio_stop(m_pigpioHdlr);
    }

    void setFreq(float freq) {
      m_freq = freq;
      gpio_write(m_pigpioHdlr, m_outputPin, 0);
    }

    void startPulseGeneration() {
      uint32_t period_us = 1000000/m_freq;

      wave_clear(m_pigpioHdlr);

      gpioPulse_t pulse [2];
      pulse[0].gpioOn = (uint32_t) (1 << m_outputPin);
      pulse[0].gpioOff = 0;
      pulse[0].usDelay = period_us/2;

      pulse[1].gpioOn = 0;
      pulse[1].gpioOff = (uint32_t) (1 << m_outputPin);
      pulse[1].usDelay = period_us/2;

      wave_add_generic(m_pigpioHdlr, 2, pulse);
      m_waveid = wave_create(m_pigpioHdlr);

      wave_send_repeat(m_pigpioHdlr, m_waveid);
    }

    void stopPulseGeneration() {
      wave_tx_stop(m_pigpioHdlr);
      if (wave_delete(m_pigpioHdlr, m_waveid) != 0)
        std::cerr << "wave_delete" << std::endl;
      if(wave_clear(m_pigpioHdlr) != 0) {
        std::cerr << "wave_clear" << std::endl;
      }
    }

    void generateNPulses_LOFI(int nPulses) {
      int counter = 1;
      float period = 1.0/m_freq;
      float dcTime_usec = period*0.4*1000000.0;
      periodicTask_period
        (period, nPulses,
          [this, &nPulses, &dcTime_usec, &counter] () {
            // std::cout << ">>> Pulse "<< counter << std::endl;
            gpio_write(this->m_pigpioHdlr, this->m_outputPin, 1);
            usleep(dcTime_usec);  
            // 333 usecs HIGH with 1,5 KHz of period, 
            // which is the maximum for the anemo).
            gpio_write(this->m_pigpioHdlr, this->m_outputPin, 0);
            
            counter++;
          }
        );
    }

};

class AnemometerTest : public testing::TestWithParam<float /*freq*/> {
  protected:

    AnemometerTest() : 
      hw(50, 26)
    {
    }

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
