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
   --  Sync required interface "RetreiveAllData"
   procedure RI_0_RetreiveAllData (Alldata : out asn1SccOBSW_DP_Data) renames Heattransferlab_RI.RetreiveAllData;
   --  Sync required interface "setOnOffH1"
   procedure RI_0_setOnOffH1 (Command : in out asn1SccHeater_On_Off) renames Heattransferlab_RI.setOnOffH1;
   --  Sync required interface "setPowerH1"
   procedure RI_0_setPowerH1 (Power : in out asn1SccT_Float) renames Heattransferlab_RI.setPowerH1;
end Heattransferlab;