#include "EquipementHandlers/Anemometer.h"
#include <math.h>   // modf
#include <unistd.h> // Getopt
#include <stdlib.h> // strtof
#include <signal.h> // signal
#include <iostream>
#include <sys/time.h>
#include <string>
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

};

/* Global variabels:
 ******************************************************************************/
static volatile sig_atomic_t keepRunning = true;
static float frecuencyHz = 1500.0;
static int pin = 0;

/* Function declarations:
 ******************************************************************************/
void signal_handler(int signum);

static bool parseArgs(int argc, char **argv);

static void start(void);

/* Function definitions:
 ******************************************************************************/
int main(int argc, char **argv) {

  signal(SIGINT, signal_handler);

  keepRunning = parseArgs(argc, argv);
  
  std::cout << "START" << std::endl;
  start();
  std::cout << "END" << std::endl;
  return EXIT_SUCCESS;
}

static bool parseArgs(int argc, char **argv) {
  int c;
  while ( (c = getopt(argc, argv, "f:p:")) != -1 ) {
    switch (c) {
      case 'f':
        float f_aux;
        f_aux = atof(optarg);
        if (f_aux < 0) {
          std::cerr << "The pulse frequency of the counter can't be negative." << std::endl;
          std::cout << "Set pulse frecuency to default value: "
                    << std::to_string(frecuencyHz) << "Hz" << std::endl;
        } else {
          frecuencyHz = f_aux;
          std::cout << "Set pulse frecuency to: " << std::to_string(f_aux) << "Hz" << std::endl;
        }

        break;

      case 'p':
        int pin_aux;
        pin_aux = atoi(optarg);
        if (pin_aux < 0) {
          std::cerr << "The pin number of the counter can't be negative." << std::endl;
          std::cout << "Set to default value: "
                    << std::to_string(pin) << std::endl;
        } else {
          pin = pin_aux;
        }

        break;

      case '?':
        if(optopt == 'f') {
          std::cout << "Set pulse frecuency to default value: "
                    << std::to_string(frecuencyHz) << "Hz" << std::endl;
        }
        if(optopt == 'p') {
          std::cout << "Set pin number to default value: "
                    << std::to_string(pin) << "Hz" << std::endl;
        }
        break;

      default:
        std::cerr << "¿?" << std::endl;
        return false;
    }
  }

  return true;
}

void signal_handler(int signum) {
  if (signum == SIGINT) {
    keepRunning = false;
  }
}

static void start(void) {

  AnemometerHW a_hw (frecuencyHz, pin);
  a_hw.startPulseGeneration();

  while(keepRunning) {
    sleep(1);
  }

  a_hw.stopPulseGeneration();

}
