#include "EquipementHandlers/HeaterHandler.h"
#include <unistd.h>
#include <iostream>
#include <sys/time.h>

using namespace equipementHandlers;

void test_heater() {
  HeaterHandler hh;
  hh.setPower(0.25);
  sleep(3);
  hh.setPower(0.23884/2);
  sleep(3);
  hh.setPower(0.23884/4);
  sleep(3);

  hh.setPWMFreq(1000000);
  hh.setPower(0.25);
  sleep(3);
  hh.setPower(0.23884/2);
  sleep(3);
  hh.setPower(0.23884/4);
  sleep(3);
}

int main () 
{
  test_heater();

  return 0;
}
