-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !

with Interfaces,
     Interfaces.C.Strings,
     Ada.Characters.Handling;

use Interfaces,
    Interfaces.C.Strings,
    Ada.Characters.Handling;

with TASEC_LAB_B2SPACE_DATAVIEW;
use TASEC_LAB_B2SPACE_DATAVIEW;
with TASTE_BasicTypes;
use TASTE_BasicTypes;
with adaasn1rtl;
use adaasn1rtl;
with Heattransferlab_Datamodel; use Heattransferlab_Datamodel;

with Heattransferlab_RI;
package Heattransferlab with Elaborate_Body is
   ctxt : aliased asn1SccHeattransferlab_Context :=
      (Init_Done => False,
       ok => false,
       press_5km => 541.0,
       press_10km => 265.0,
       press_18km => 84.0,
       a1_duration_emergency => 1800.0,
       a1_duration_max => 2400.0,
       power_a2 => 0.0,
       a2_duration_max => 4800.0,
       n => 0.0,
       power_f1 => 0.0,
       f1_duration => 900000,
       m => 0.0,
       f2_duration => 900000,
      others => <>);
   function To_OBSW_DP_SingleData_selection (Src : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccOBSW_DP_SingleData_selection) return Heattransferlab_Datamodel.asn1SccOBSW_DP_SingleData_selection is (Heattransferlab_Datamodel.asn1SccOBSW_DP_SingleData_selection'Enum_Val (Src'Enum_Rep));
   function To_TC_Heater_command_selection (Src : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccTC_Heater_command_selection) return Heattransferlab_Datamodel.asn1SccTC_Heater_command_selection is (Heattransferlab_Datamodel.asn1SccTC_Heater_command_selection'Enum_Val (Src'Enum_Rep));
   function Get_State return chars_ptr is (New_String (asn1SccHeattransferlab_States'Image (ctxt.State))) with Export, Convention => C, Link_Name => "heattransferlab_state";
   procedure Startup with Export, Convention => C, Link_Name => "Heattransferlab_startup";
   procedure configureParameters(Configuration: in out asn1SccHTL_Config);
   pragma Export (C, configureParameters, "heattransferlab_PI_configureParameters");
   procedure getCurrentMode(Current_State: in out asn1SccHTL_State);
   pragma Export (C, getCurrentMode, "heattransferlab_PI_getCurrentMode");
   --  Provided interface "setCurrentMode"
   procedure setCurrentMode(current_state: in out asn1SccHTL_State);
   pragma Export(C, setCurrentMode, "heattransferlab_PI_setCurrentMode");
   --  Provided interface "tick"
   procedure tick;
   pragma Export(C, tick, "heattransferlab_PI_tick");
   --  Provided interface "configureParameters"
   procedure configureParameters_Transition;
   --  Provided interface "getCurrentMode"
   procedure getCurrentMode_Transition;
   --  Provided interface "f1_timeout"
   procedure f1_timeout;
   pragma Export(C, f1_timeout, "heattransferlab_PI_f1_timeout");
   --  Provided interface "f2_timeout"
   procedure f2_timeout;
   pragma Export(C, f2_timeout, "heattransferlab_PI_f2_timeout");
   --  Sync required interface "RetreiveSingleData"
   procedure RI_0_RetreiveSingleData (Filter : in out asn1SccOBSW_DP_Filter; Single_Data : out asn1SccOBSW_DP_SingleData) renames Heattransferlab_RI.RetreiveSingleData;
   --  Sync required interface "getTime"
   procedure RI_0_getTime (Gps_Time : out asn1SccT_Double; Mission_Time : out asn1SccT_Double) renames Heattransferlab_RI.getTime;
   --  Sync required interface "setPowerH2"
   procedure RI_0_setPowerH2 (Power : in out asn1SccT_Float) renames Heattransferlab_RI.setPowerH2;
   --  Timer f1_timeout SET and RESET functions
   procedure SET_f1_timeout (Val : in out asn1SccT_UInt32) renames Heattransferlab_RI.Set_f1_timeout;
   procedure RESET_f1_timeout renames Heattransferlab_RI.Reset_f1_timeout;
   --  Timer f2_timeout SET and RESET functions
   procedure SET_f2_timeout (Val : in out asn1SccT_UInt32) renames Heattransferlab_RI.Set_f2_timeout;
   procedure RESET_f2_timeout renames Heattransferlab_RI.Reset_f2_timeout;
   procedure Check_Queue (Res : out Asn1Boolean);
   pragma Import(C, Check_Queue, "heattransferlab_check_queue");
end Heattransferlab;