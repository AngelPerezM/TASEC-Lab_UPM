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


pragma Warnings (Off, "no entities of ""TASTE_BasicTypes"" are referenced");
pragma Warnings (Off, "use clause for package ""TASTE_BasicTypes"" has no effect");
with TASTE_BasicTypes; use TASTE_BasicTypes;
pragma Warnings (On, "no entities of ""TASTE_BasicTypes"" are referenced");
pragma Warnings (On, "use clause for package ""TASTE_BasicTypes"" has no effect");


pragma Warnings (Off, "no entities of ""TASEC_LAB_B2SPACE_DATAVIEW"" are referenced");
pragma Warnings (Off, "use clause for package ""TASEC_LAB_B2SPACE_DATAVIEW"" has no effect");
with TASEC_LAB_B2SPACE_DATAVIEW; use TASEC_LAB_B2SPACE_DATAVIEW;
pragma Warnings (On, "no entities of ""TASEC_LAB_B2SPACE_DATAVIEW"" are referenced");
pragma Warnings (On, "use clause for package ""TASEC_LAB_B2SPACE_DATAVIEW"" has no effect");



package Heattransferlab_Datamodel with SPARK_Mode
is


subtype asn1SccHeattransferlab_States_index_range is Integer range 0..6;
type asn1SccHeattransferlab_States is (asn1Sccf2, asn1Sccf1, asn1Sccselectstate, asn1Sccerror, asn1Scca1, asn1Sccf3, asn1Scca2) with Size => adaasn1rtl.Enumerated_Size;
for asn1SccHeattransferlab_States use
    (asn1Sccf2 => 0, asn1Sccf1 => 1, asn1Sccselectstate => 2, asn1Sccerror => 3, asn1Scca1 => 4, asn1Sccf3 => 5, asn1Scca2 => 6);

function asn1SccHeattransferlab_States_Equal(val1, val2 : asn1SccHeattransferlab_States) return Boolean;

function asn1SccHeattransferlab_States_Init return asn1SccHeattransferlab_States;

ERR_HEATTRANSFERLAB_STATES:constant Integer := 1; 
function asn1SccHeattransferlab_States_IsConstraintValid(val : asn1SccHeattransferlab_States) return adaasn1rtl.ASN1_RESULT;
-- asn1SccHeattransferlab_Context --------------------------------------------

type asn1SccHeattransferlab_Context is record 
    state : asn1SccHeattransferlab_States;
    init_done : adaasn1rtl.Asn1Boolean;
    ok : TASTE_BasicTypes.asn1SccT_Boolean;
    actual_state : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccHTL_State;
    last_good_state : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccHTL_State;
    temp_air : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float;
    temp_plate : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float;
    press : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float;
    press_5km : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float;
    press_10km : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float;
    press_18km : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float;
    power : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float;
    htl_time : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Double;
    a1_duration_emergency : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Double;
    a1_duration_max : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Double;
    power_a2 : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float;
    a2_duration_max : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Double;
    n : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float;
    power_f1 : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float;
    f1_duration : TASTE_BasicTypes.asn1SccT_UInt32;
    m : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float;
    f2_duration : TASTE_BasicTypes.asn1SccT_UInt32;
end record;


function asn1SccHeattransferlab_Context_Equal(val1, val2 : asn1SccHeattransferlab_Context) return Boolean;

function asn1SccHeattransferlab_Context_Init return asn1SccHeattransferlab_Context;

ERR_HEATTRANSFERLAB_CONTEXT:constant Integer := 309; 
ERR_HEATTRANSFERLAB_CONTEXT_STATE_2:constant Integer := 15; 
ERR_HEATTRANSFERLAB_CONTEXT_INIT_DONE:constant Integer := 22; 
ERR_HEATTRANSFERLAB_CONTEXT_OK_2:constant Integer := 36; 
ERR_HEATTRANSFERLAB_CONTEXT_ACTUAL_STATE_2:constant Integer := 50; 
ERR_HEATTRANSFERLAB_CONTEXT_LAST_GOOD_STATE_2:constant Integer := 64; 
ERR_HEATTRANSFERLAB_CONTEXT_TEMP_AIR_2:constant Integer := 78; 
ERR_HEATTRANSFERLAB_CONTEXT_TEMP_PLATE_2:constant Integer := 92; 
ERR_HEATTRANSFERLAB_CONTEXT_PRESS_2:constant Integer := 106; 
ERR_HEATTRANSFERLAB_CONTEXT_PRESS_5KM_2:constant Integer := 120; 
ERR_HEATTRANSFERLAB_CONTEXT_PRESS_10KM_2:constant Integer := 134; 
ERR_HEATTRANSFERLAB_CONTEXT_PRESS_18KM_2:constant Integer := 148; 
ERR_HEATTRANSFERLAB_CONTEXT_POWER_2:constant Integer := 162; 
ERR_HEATTRANSFERLAB_CONTEXT_HTL_TIME_2:constant Integer := 176; 
ERR_HEATTRANSFERLAB_CONTEXT_A1_DURATION_EMERGENCY_2:constant Integer := 190; 
ERR_HEATTRANSFERLAB_CONTEXT_A1_DURATION_MAX_2:constant Integer := 204; 
ERR_HEATTRANSFERLAB_CONTEXT_POWER_A2_2:constant Integer := 218; 
ERR_HEATTRANSFERLAB_CONTEXT_A2_DURATION_MAX_2:constant Integer := 232; 
ERR_HEATTRANSFERLAB_CONTEXT_N_2:constant Integer := 246; 
ERR_HEATTRANSFERLAB_CONTEXT_POWER_F1_2:constant Integer := 260; 
ERR_HEATTRANSFERLAB_CONTEXT_F1_DURATION_2:constant Integer := 274; 
ERR_HEATTRANSFERLAB_CONTEXT_M_2:constant Integer := 288; 
ERR_HEATTRANSFERLAB_CONTEXT_F2_DURATION_2:constant Integer := 302; 
function asn1SccHeattransferlab_Context_IsConstraintValid(val : asn1SccHeattransferlab_Context) return adaasn1rtl.ASN1_RESULT;
subtype asn1SccOBSW_DP_SingleData_selection_index_range is Integer range 0..8;
type asn1SccOBSW_DP_SingleData_selection is (asn1Sccgps_present, asn1Sccimu_present, asn1Scctc74s_present, asn1Sccpt1000s_present, asn1Sccps1_present, asn1Sccps2_present, asn1Sccheater1_present, asn1Sccheater2_present, asn1Sccanemometer_present) with Size => adaasn1rtl.Enumerated_Size;
for asn1SccOBSW_DP_SingleData_selection use
    (asn1Sccgps_present => 1, asn1Sccimu_present => 2, asn1Scctc74s_present => 3, asn1Sccpt1000s_present => 4, asn1Sccps1_present => 5, asn1Sccps2_present => 6, asn1Sccheater1_present => 7, asn1Sccheater2_present => 8, asn1Sccanemometer_present => 9);

function asn1SccOBSW_DP_SingleData_selection_Equal(val1, val2 : asn1SccOBSW_DP_SingleData_selection) return Boolean;

function asn1SccOBSW_DP_SingleData_selection_Init return asn1SccOBSW_DP_SingleData_selection;

ERR_OBSW_DP_SINGLEDATA_SELECTION:constant Integer := 316; 
function asn1SccOBSW_DP_SingleData_selection_IsConstraintValid(val : asn1SccOBSW_DP_SingleData_selection) return adaasn1rtl.ASN1_RESULT;
subtype asn1SccTC_Heater_command_selection_index_range is Integer range 0..1;
type asn1SccTC_Heater_command_selection is (asn1Sccpower_manual_present, asn1Sccmax_min_present) with Size => adaasn1rtl.Enumerated_Size;
for asn1SccTC_Heater_command_selection use
    (asn1Sccpower_manual_present => 1, asn1Sccmax_min_present => 2);

function asn1SccTC_Heater_command_selection_Equal(val1, val2 : asn1SccTC_Heater_command_selection) return Boolean;

function asn1SccTC_Heater_command_selection_Init return asn1SccTC_Heater_command_selection;

ERR_TC_HEATER_COMMAND_SELECTION:constant Integer := 323; 
function asn1SccTC_Heater_command_selection_IsConstraintValid(val : asn1SccTC_Heater_command_selection) return adaasn1rtl.ASN1_RESULT;
pragma Warnings (Off, "there are no others");
 
pragma Warnings (On, "there are no others");
private
   --# hide Heattransferlab_Datamodel;


end Heattransferlab_Datamodel;