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
with Systemhandler_Datamodel; use Systemhandler_Datamodel;

with Systemhandler_RI;
package Systemhandler with Elaborate_Body is
   ctxt : aliased asn1SccSystemhandler_Context :=
      (Init_Done => False,
       others => <>);
   function To_OBSW_DP_SingleData_selection (Src : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccOBSW_DP_SingleData_selection) return Systemhandler_Datamodel.asn1SccOBSW_DP_SingleData_selection is (Systemhandler_Datamodel.asn1SccOBSW_DP_SingleData_selection'Enum_Val (Src'Enum_Rep));
   function To_TC_Heater_command_selection (Src : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccTC_Heater_command_selection) return Systemhandler_Datamodel.asn1SccTC_Heater_command_selection is (Systemhandler_Datamodel.asn1SccTC_Heater_command_selection'Enum_Val (Src'Enum_Rep));
   function To_TC_selection (Src : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccTC_selection) return Systemhandler_Datamodel.asn1SccTC_selection is (Systemhandler_Datamodel.asn1SccTC_selection'Enum_Val (Src'Enum_Rep));
   function Get_State return chars_ptr is (New_String (asn1SccSystemhandler_States'Image (ctxt.State))) with Export, Convention => C, Link_Name => "systemhandler_state";
   procedure Startup with Export, Convention => C, Link_Name => "Systemhandler_startup";
   procedure StopSystem;
   pragma Export (C, StopSystem, "systemhandler_PI_StopSystem");
   --  Provided interface "StopSystem"
   procedure StopSystem_Transition;
   --  Paramless required interface "stop_DL"
   procedure RI_0_stop_DL renames Systemhandler_RI.stop_DL;
   --  Paramless required interface "stop_DM"
   procedure RI_0_stop_DM renames Systemhandler_RI.stop_DM;
   --  Paramless required interface "stop_IIC"
   procedure RI_0_stop_IIC renames Systemhandler_RI.stop_IIC;
   --  Paramless required interface "stop_WD"
   procedure RI_0_stop_WD renames Systemhandler_RI.stop_WD;
end Systemhandler;