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
with Thermostat_Datamodel; use Thermostat_Datamodel;

with Thermostat_RI;
package Thermostat with Elaborate_Body is
   ctxt : aliased asn1SccThermostat_Context :=
      (Init_Done => False,
       others => <>);
   function To_TC_Heater_command_selection (Src : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccTC_Heater_command_selection) return Thermostat_Datamodel.asn1SccTC_Heater_command_selection is (Thermostat_Datamodel.asn1SccTC_Heater_command_selection'Enum_Val (Src'Enum_Rep));
   function Get_State return chars_ptr is (New_String (asn1SccThermostat_States'Image (ctxt.State))) with Export, Convention => C, Link_Name => "thermostat_state";
   procedure Startup with Export, Convention => C, Link_Name => "Thermostat_startup";
   --  Provided interface "notifyTempChanged"
   procedure notifyTempChanged(tempCelsius: in out asn1SccT_Float);
   pragma Export(C, notifyTempChanged, "thermostat_PI_notifyTempChanged");
   --  Sync required interface "setOnOffH2"
   procedure RI_0_setOnOffH2 (Command : in out asn1SccHeater_On_Off) renames Thermostat_RI.setOnOffH2;
end Thermostat;