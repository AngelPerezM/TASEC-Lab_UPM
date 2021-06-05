/* C++ Function Instance
 * Header file for function FunctionInstance2 in CPP language
 * Generated by TASTE on 2021-05-18 19:10:51
 * Context Parameters present : YES
 * Provided interfaces : getPower, setPower
 * Required interfaces : 
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 81498 155101 101581 165025
  *  |_ Taste::is_Instance_Of = Heater::IV::Heater::Heater.others
  *  |_ Taste::is_Instance_Of2 = Heater.others
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include "dataview-uniq.h"

// External declaration of required interfaces


void functioninstance2_startup();

void functioninstance2_PI_getPower( asn1SccT_Float *power );
void functioninstance2_PI_setPower( const asn1SccT_Float *power );
#ifdef __cplusplus
}
#endif
