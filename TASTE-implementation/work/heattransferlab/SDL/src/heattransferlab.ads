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
       press_5km => 1000.0,
       press_10km => 265.0,
       press_18km => 84.0,
       power => 0.0,
       a1_started => false,
       a1_duration_emergency => 1800.0,
       a1_duration_max => 2400.0,
       a2_started => false,
       power_a2 => 0.6,
       a2_duration_max => 4800.0,
       n => 0.0,
       power_f1 => 0.0,
       f1_started => false,
       f1_first_it => true,
       f1_relative_duration_max => 7200.0,
       f1_duration_max => (-1.0),
       m => 0.0,
       f2_started => false,
       f2_first_it => true,
       f2_relative_duration_max => 7200.0,
       f2_duration_max => (-1.0),
       system_stopped => false,
      others => <>);
   function To_OBSW_DP_SingleData_selection (Src : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccOBSW_DP_SingleData_selection) return Heattransferlab_Datamodel.asn1SccOBSW_DP_SingleData_selection is (Heattransferlab_Datamodel.asn1SccOBSW_DP_SingleData_selection'Enum_Val (Src'Enum_Rep));
   function To_TC_Heater_command_selection (Src : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccTC_Heater_command_selection) return Heattransferlab_Datamodel.asn1SccTC_Heater_command_selection is (Heattransferlab_Datamodel.asn1SccTC_Heater_command_selection'Enum_Val (Src'Enum_Rep));
   function To_TC_selection (Src : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccTC_selection) return Heattransferlab_Datamodel.asn1SccTC_selection is (Heattransferlab_Datamodel.asn1SccTC_selection'Enum_Val (Src'Enum_Rep));
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
   --  Sync required interface "KickTheDog"
   procedure RI_0_KickTheDog renames Heattransferlab_RI.KickTheDog;
   --  Sync required interface "RecordHTLParams"
   procedure RI_0_RecordHTLParams (Htl_State : in out asn1SccHTL_State; F1_Max_Time : in out asn1SccT_Double; F2_Max_Time : in out asn1SccT_Double; M : in out asn1SccT_Float; N : in out asn1SccT_Float; Power_F1 : in out asn1SccT_Float) renames Heattransferlab_RI.RecordHTLParams;
   --  Sync required interface "RecoverHTLParams"
   procedure RI_0_RecoverHTLParams (Htl_State : out asn1SccHTL_State; F1_Max_Time : out asn1SccT_Double; F2_Max_Time : out asn1SccT_Double; M : out asn1SccT_Float; N : out asn1SccT_Float; Power_F1 : out asn1SccT_Float) renames Heattransferlab_RI.RecoverHTLParams;
   --  Sync required interface "RetreiveSingleData"
   procedure RI_0_RetreiveSingleData (Filter : in out asn1SccOBSW_DP_Filter; Single_Data : out asn1SccOBSW_DP_SingleData) renames Heattransferlab_RI.RetreiveSingleData;
   --  Sync required interface "StopSystem"
   procedure RI_0_StopSystem renames Heattransferlab_RI.StopSystem;
   --  Sync required interface "getTime"
   procedure RI_0_getTime (Gps_Time : out asn1SccT_Double; Mission_Time : out asn1SccT_Double) renames Heattransferlab_RI.getTime;
   --  Sync required interface "setPowerH2"
   procedure RI_0_setPowerH2 (Power : in out asn1SccT_Float) renames Heattransferlab_RI.setPowerH2;
   procedure Check_Queue (Res : out Asn1Boolean);
   pragma Import(C, Check_Queue, "heattransferlab_check_queue");
end Heattransferlab;