/* Body file for function HeatTransferLab
 * Generated by TASTE on 2021-06-14 14:27:40
 * You can edit this file, it will not be overwritten
 * Provided interfaces : configureParameters, getCurrentMode, setCurrentMode, tick
 * Required interfaces : getTime, setPowerH2
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 222060 53729 262688 74201
 * Timers              : 
 */

#include "heattransferlab.h"
//#include <stdio.h>


void heattransferlab_startup(void)
{
   // Write your initialisation code, but DO NOT CALL REQUIRED INTERFACES
   // puts ("[HeatTransferLab] Startup");
}

void heattransferlab_PI_configureParameters
      (const asn1SccHTL_Config *IN_configuration)

{
   // Write your code here
}
void heattransferlab_PI_getCurrentMode
      (asn1SccHTL_State *OUT_current_state)

{
   // Write your code here
}
void heattransferlab_PI_setCurrentMode
      (const asn1SccHTL_State *IN_current_state)

{
   // Write your code here
}
void heattransferlab_PI_tick(void)
{
   // Write your code here
}


