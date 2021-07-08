/* Message identifiers for the GUI messages
 * Used by the code of the GUIs and by the ctypes Python interface
 * DO NOT EDIT THIS FILE MANUALLY - MODIFY THE KAZOO TEMPLATE IF NECESSARY
*/
#pragma once

// 4 attitude_data, environmental_data, htl_data, poll
typedef enum {
   i_Attitude_Data,
   i_Environmental_Data,
   i_HTL_Data
} T_gui_PI_list;

typedef enum {
   i_send_telecommand,
   i_setCurrentMode
} T_gui_RI_list;
