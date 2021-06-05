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
       others => <>);
   function To_TC_Heater_command_selection (Src : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccTC_Heater_command_selection) return Heattransferlab_Datamodel.asn1SccTC_Heater_command_selection is (Heattransferlab_Datamodel.asn1SccTC_Heater_command_selection'Enum_Val (Src'Enum_Rep));
   function Get_State return chars_ptr is (New_String (asn1SccHeattransferlab_States'Image (ctxt.State))) with Export, Convention => C, Link_Name => "heattransferlab_state";
   procedure Startup with Export, Convention => C, Link_Name => "Heattransferlab_startup";
   --  Provided interface "tick"
   procedure tick;
   pragma Export(C, tick, "heattransferlab_PI_tick");
   --  Provided interface "f1_max_time"
   procedure f1_max_time;
   pragma Export(C, f1_max_time, "heattransferlab_PI_f1_max_time");
   --  Provided interface "f2_max_time"
   procedure f2_max_time;
   pragma Export(C, f2_max_time, "heattransferlab_PI_f2_max_time");
   --  Sync required interface "RetreiveAllData"
   procedure RI_0_RetreiveAllData (Alldata : out asn1SccOBSW_DP_Data) renames Heattransferlab_RI.RetreiveAllData;
   --  Sync required interface "setOnOffH1"
   procedure RI_0_setOnOffH1 (Command : in out asn1SccHeater_On_Off) renames Heattransferlab_RI.setOnOffH1;
   --  Sync required interface "setPowerH1"
   procedure RI_0_setPowerH1 (Power : in out asn1SccT_Float) renames Heattransferlab_RI.setPowerH1;
   --  Timer f1_max_time SET and RESET functions
   procedure SET_f1_max_time (Val : in out asn1SccT_UInt32) renames Heattransferlab_RI.Set_f1_max_time;
   procedure RESET_f1_max_time renames Heattransferlab_RI.Reset_f1_max_time;
   --  Timer f2_max_time SET and RESET functions
   procedure SET_f2_max_time (Val : in out asn1SccT_UInt32) renames Heattransferlab_RI.Set_f2_max_time;
   procedure RESET_f2_max_time renames Heattransferlab_RI.Reset_f2_max_time;
end Heattransferlab;