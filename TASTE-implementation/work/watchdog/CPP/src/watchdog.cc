// Body file for function Watchdog
// Generated by TASTE on 2021-07-07 13:00:32
// You can edit this file, it will not be overwritten
// Provided interfaces : KickTheDog
// Required interfaces : 
// User-defined properties for this function:
//   |_ Taste::Active_Interfaces = any
//   |_ Taste::coordinates = 193252 62033 216912 69679
// Timers              : 

#include "watchdog.h"
#include "watchdog_state.h"
#include <iostream>

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// Define and use function state inside this context structure
// avoid defining global/static variable elsewhere
watchdog_state ctxt_watchdog;


void watchdog_startup(void)
{
   // Write your initialisation code, but DO NOT CALL REQUIRED INTERFACES
   std::cout << "[Watchdog] Startup" << std::endl;
}

void watchdog_PI_KickTheDog(void)
{
   // Write your code here
}


