pragma Style_Checks (Off);
--  Code automatically generated by asn1scc tool
with adaasn1rtl;


pragma Warnings (Off, "unit ""System"" is not referenced");
with System;
pragma Warnings (On, "unit ""System"" is not referenced");

pragma Warnings (Off, "use clause for package ""adaasn1rtl"" has no effect");
use adaasn1rtl;
pragma Warnings (On, "use clause for package ""adaasn1rtl"" has no effect");

pragma Warnings (Off, "use clause for type");
pragma Warnings (Off, "is already use-visible through package use clause at line");
use type adaasn1rtl.OctetBuffer;
use type adaasn1rtl.BitArray;
use type adaasn1rtl.Asn1UInt;
use type adaasn1rtl.Asn1Int;
use type adaasn1rtl.BIT;
pragma Warnings (On, "use clause for type");
pragma Warnings (On, "is already use-visible through package use clause at line");


pragma Warnings (Off, "no entities of ""TASEC_LAB_B2SPACE_DATAVIEW"" are referenced");
pragma Warnings (Off, "use clause for package ""TASEC_LAB_B2SPACE_DATAVIEW"" has no effect");
with TASEC_LAB_B2SPACE_DATAVIEW; use TASEC_LAB_B2SPACE_DATAVIEW;
pragma Warnings (On, "no entities of ""TASEC_LAB_B2SPACE_DATAVIEW"" are referenced");
pragma Warnings (On, "use clause for package ""TASEC_LAB_B2SPACE_DATAVIEW"" has no effect");


pragma Warnings (Off, "no entities of ""TASTE_BasicTypes"" are referenced");
pragma Warnings (Off, "use clause for package ""TASTE_BasicTypes"" has no effect");
with TASTE_BasicTypes; use TASTE_BasicTypes;
pragma Warnings (On, "no entities of ""TASTE_BasicTypes"" are referenced");
pragma Warnings (On, "use clause for package ""TASTE_BasicTypes"" has no effect");



package Thermostat_Datamodel with SPARK_Mode
is


subtype asn1SccThermostat_States_index_range is Integer range 0..0;
type asn1SccThermostat_States is (asn1Sccwait) with Size => adaasn1rtl.Enumerated_Size;
for asn1SccThermostat_States use
    (asn1Sccwait => 0);

function asn1SccThermostat_States_Equal(val1, val2 : asn1SccThermostat_States) return Boolean;

function asn1SccThermostat_States_Init return asn1SccThermostat_States;

ERR_THERMOSTAT_STATES:constant Integer := 491; 
function asn1SccThermostat_States_IsConstraintValid(val : asn1SccThermostat_States) return adaasn1rtl.ASN1_RESULT;
-- asn1SccThermostat_Context --------------------------------------------

type asn1SccThermostat_Context is record 
    state : asn1SccThermostat_States;
    init_done : adaasn1rtl.Asn1Boolean;
    tempcelsius : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float;
    heaterison : TASTE_BasicTypes.asn1SccT_Boolean;
end record;


function asn1SccThermostat_Context_Equal(val1, val2 : asn1SccThermostat_Context) return Boolean;

function asn1SccThermostat_Context_Init return asn1SccThermostat_Context;

ERR_THERMOSTAT_CONTEXT:constant Integer := 547; 
ERR_THERMOSTAT_CONTEXT_STATE_2:constant Integer := 505; 
ERR_THERMOSTAT_CONTEXT_INIT_DONE:constant Integer := 512; 
ERR_THERMOSTAT_CONTEXT_TEMPCELSIUS_2:constant Integer := 526; 
ERR_THERMOSTAT_CONTEXT_HEATERISON_2:constant Integer := 540; 
function asn1SccThermostat_Context_IsConstraintValid(val : asn1SccThermostat_Context) return adaasn1rtl.ASN1_RESULT;
subtype asn1SccOBSW_DP_SingleData_selection_index_range is Integer range 0..8;
type asn1SccOBSW_DP_SingleData_selection is (asn1Sccgps_present, asn1Sccimu_present, asn1Scctc74s_present, asn1Sccpt1000s_present, asn1Sccps1_present, asn1Sccps2_present, asn1Sccheater1_present, asn1Sccheater2_present, asn1Sccanemometer_present) with Size => adaasn1rtl.Enumerated_Size;
for asn1SccOBSW_DP_SingleData_selection use
    (asn1Sccgps_present => 1, asn1Sccimu_present => 2, asn1Scctc74s_present => 3, asn1Sccpt1000s_present => 4, asn1Sccps1_present => 5, asn1Sccps2_present => 6, asn1Sccheater1_present => 7, asn1Sccheater2_present => 8, asn1Sccanemometer_present => 9);

function asn1SccOBSW_DP_SingleData_selection_Equal(val1, val2 : asn1SccOBSW_DP_SingleData_selection) return Boolean;

function asn1SccOBSW_DP_SingleData_selection_Init return asn1SccOBSW_DP_SingleData_selection;

ERR_OBSW_DP_SINGLEDATA_SELECTION_2_2:constant Integer := 554; 
function asn1SccOBSW_DP_SingleData_selection_IsConstraintValid(val : asn1SccOBSW_DP_SingleData_selection) return adaasn1rtl.ASN1_RESULT;
subtype asn1SccTC_Heater_command_selection_index_range is Integer range 0..1;
type asn1SccTC_Heater_command_selection is (asn1Sccpower_manual_present, asn1Sccmax_min_present) with Size => adaasn1rtl.Enumerated_Size;
for asn1SccTC_Heater_command_selection use
    (asn1Sccpower_manual_present => 1, asn1Sccmax_min_present => 2);

function asn1SccTC_Heater_command_selection_Equal(val1, val2 : asn1SccTC_Heater_command_selection) return Boolean;

function asn1SccTC_Heater_command_selection_Init return asn1SccTC_Heater_command_selection;

ERR_TC_HEATER_COMMAND_SELECTION_2_2:constant Integer := 561; 
function asn1SccTC_Heater_command_selection_IsConstraintValid(val : asn1SccTC_Heater_command_selection) return adaasn1rtl.ASN1_RESULT;
subtype asn1SccTC_selection_index_range is Integer range 0..1;
type asn1SccTC_selection is (asn1Sccheater_commands_present, asn1Sccsystem_commands_present) with Size => adaasn1rtl.Enumerated_Size;
for asn1SccTC_selection use
    (asn1Sccheater_commands_present => 1, asn1Sccsystem_commands_present => 2);

function asn1SccTC_selection_Equal(val1, val2 : asn1SccTC_selection) return Boolean;

function asn1SccTC_selection_Init return asn1SccTC_selection;

ERR_TC_SELECTION_2_2:constant Integer := 568; 
function asn1SccTC_selection_IsConstraintValid(val : asn1SccTC_selection) return adaasn1rtl.ASN1_RESULT;
pragma Warnings (Off, "there are no others");
 
pragma Warnings (On, "there are no others");
private
   --# hide Thermostat_Datamodel;


end Thermostat_Datamodel;