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



package Systemhandler_Datamodel with SPARK_Mode
is


subtype asn1SccSystemhandler_States_index_range is Integer range 0..0;
type asn1SccSystemhandler_States is (asn1Sccwait) with Size => adaasn1rtl.Enumerated_Size;
for asn1SccSystemhandler_States use
    (asn1Sccwait => 0);

function asn1SccSystemhandler_States_Equal(val1, val2 : asn1SccSystemhandler_States) return Boolean;

function asn1SccSystemhandler_States_Init return asn1SccSystemhandler_States;

ERR_SYSTEMHANDLER_STATES:constant Integer := 407; 
function asn1SccSystemhandler_States_IsConstraintValid(val : asn1SccSystemhandler_States) return adaasn1rtl.ASN1_RESULT;
-- asn1SccSystemhandler_Context --------------------------------------------

type asn1SccSystemhandler_Context is record 
    state : asn1SccSystemhandler_States;
    init_done : adaasn1rtl.Asn1Boolean;
end record;


function asn1SccSystemhandler_Context_Equal(val1, val2 : asn1SccSystemhandler_Context) return Boolean;

function asn1SccSystemhandler_Context_Init return asn1SccSystemhandler_Context;

ERR_SYSTEMHANDLER_CONTEXT:constant Integer := 435; 
ERR_SYSTEMHANDLER_CONTEXT_STATE_2:constant Integer := 421; 
ERR_SYSTEMHANDLER_CONTEXT_INIT_DONE:constant Integer := 428; 
function asn1SccSystemhandler_Context_IsConstraintValid(val : asn1SccSystemhandler_Context) return adaasn1rtl.ASN1_RESULT;
subtype asn1SccOBSW_DP_SingleData_selection_index_range is Integer range 0..8;
type asn1SccOBSW_DP_SingleData_selection is (asn1Sccgps_present, asn1Sccimu_present, asn1Scctc74s_present, asn1Sccpt1000s_present, asn1Sccps1_present, asn1Sccps2_present, asn1Sccheater1_present, asn1Sccheater2_present, asn1Sccanemometer_present) with Size => adaasn1rtl.Enumerated_Size;
for asn1SccOBSW_DP_SingleData_selection use
    (asn1Sccgps_present => 1, asn1Sccimu_present => 2, asn1Scctc74s_present => 3, asn1Sccpt1000s_present => 4, asn1Sccps1_present => 5, asn1Sccps2_present => 6, asn1Sccheater1_present => 7, asn1Sccheater2_present => 8, asn1Sccanemometer_present => 9);

function asn1SccOBSW_DP_SingleData_selection_Equal(val1, val2 : asn1SccOBSW_DP_SingleData_selection) return Boolean;

function asn1SccOBSW_DP_SingleData_selection_Init return asn1SccOBSW_DP_SingleData_selection;

ERR_OBSW_DP_SINGLEDATA_SELECTION_2:constant Integer := 442; 
function asn1SccOBSW_DP_SingleData_selection_IsConstraintValid(val : asn1SccOBSW_DP_SingleData_selection) return adaasn1rtl.ASN1_RESULT;
subtype asn1SccTC_Heater_command_selection_index_range is Integer range 0..1;
type asn1SccTC_Heater_command_selection is (asn1Sccpower_manual_present, asn1Sccmax_min_present) with Size => adaasn1rtl.Enumerated_Size;
for asn1SccTC_Heater_command_selection use
    (asn1Sccpower_manual_present => 1, asn1Sccmax_min_present => 2);

function asn1SccTC_Heater_command_selection_Equal(val1, val2 : asn1SccTC_Heater_command_selection) return Boolean;

function asn1SccTC_Heater_command_selection_Init return asn1SccTC_Heater_command_selection;

ERR_TC_HEATER_COMMAND_SELECTION_2:constant Integer := 449; 
function asn1SccTC_Heater_command_selection_IsConstraintValid(val : asn1SccTC_Heater_command_selection) return adaasn1rtl.ASN1_RESULT;
subtype asn1SccTC_selection_index_range is Integer range 0..1;
type asn1SccTC_selection is (asn1Sccheater_commands_present, asn1Sccsystem_commands_present) with Size => adaasn1rtl.Enumerated_Size;
for asn1SccTC_selection use
    (asn1Sccheater_commands_present => 1, asn1Sccsystem_commands_present => 2);

function asn1SccTC_selection_Equal(val1, val2 : asn1SccTC_selection) return Boolean;

function asn1SccTC_selection_Init return asn1SccTC_selection;

ERR_TC_SELECTION_2:constant Integer := 456; 
function asn1SccTC_selection_IsConstraintValid(val : asn1SccTC_selection) return adaasn1rtl.ASN1_RESULT;
pragma Warnings (Off, "there are no others");
 
pragma Warnings (On, "there are no others");
private
   --# hide Systemhandler_Datamodel;


end Systemhandler_Datamodel;