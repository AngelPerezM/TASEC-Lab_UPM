pragma Style_Checks (Off);
--  Code automatically generated by asn1scc tool
pragma Warnings (Off, "redundant with clause in body");

pragma Warnings (Off, "no entities of ""TASTE_BasicTypes"" are referenced");
pragma Warnings (Off, "use clause for package ""TASTE_BasicTypes"" has no effect");
pragma Warnings (Off, "unit ""TASTE_BasicTypes"" is not referenced");
with TASTE_BasicTypes;
pragma Warnings (On, "no entities of ""TASTE_BasicTypes"" are referenced");
pragma Warnings (On, "use clause for package ""TASTE_BasicTypes"" has no effect");
pragma Warnings (On, "unit ""TASTE_BasicTypes"" is not referenced");


pragma Warnings (Off, "no entities of ""TASEC_LAB_B2SPACE_DATAVIEW"" are referenced");
pragma Warnings (Off, "use clause for package ""TASEC_LAB_B2SPACE_DATAVIEW"" has no effect");
pragma Warnings (Off, "unit ""TASEC_LAB_B2SPACE_DATAVIEW"" is not referenced");
with TASEC_LAB_B2SPACE_DATAVIEW;
pragma Warnings (On, "no entities of ""TASEC_LAB_B2SPACE_DATAVIEW"" are referenced");
pragma Warnings (On, "use clause for package ""TASEC_LAB_B2SPACE_DATAVIEW"" has no effect");
pragma Warnings (On, "unit ""TASEC_LAB_B2SPACE_DATAVIEW"" is not referenced");

pragma Warnings (On, "redundant with clause in body");

pragma Warnings (Off, "use clause for type");
pragma Warnings (Off, "is already use-visible through previous use_type_clause at");
use type TASTE_BasicTypes.asn1SccT_Boolean;
use type TASEC_LAB_B2SPACE_DATAVIEW.asn1SccHTL_State;
use type TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float;
use type TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Double;
use type TASTE_BasicTypes.asn1SccT_UInt32;
pragma Warnings (On, "use clause for type");
pragma Warnings (On, "is already use-visible through previous use_type_clause at");
package body Heattransferlab_Datamodel with SPARK_Mode is



pragma Warnings (Off, "condition can only be False if invalid values present");
pragma Warnings (Off, "condition can only be True if invalid values present");


function asn1SccHeattransferlab_States_Equal (val1, val2 :  asn1SccHeattransferlab_States) return Boolean
is

begin
	return val1 = val2;

end asn1SccHeattransferlab_States_Equal;

function asn1SccHeattransferlab_States_Init return asn1SccHeattransferlab_States
is
    val: asn1SccHeattransferlab_States;
begin
    val := asn1Sccf1;
	pragma Warnings (Off, "object ""val"" is always");
    return val;
	pragma Warnings (On, "object ""val"" is always");
end asn1SccHeattransferlab_States_Init;

function asn1SccHeattransferlab_States_IsConstraintValid(val : asn1SccHeattransferlab_States) return adaasn1rtl.ASN1_RESULT
is
    pragma Warnings (Off, "initialization of ret has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ret has no effect");        
begin
    ret.Success := (((((((((((((val = asn1Sccf1)) OR ((val = asn1Sccerror)))) OR ((val = asn1Sccf2)))) OR ((val = asn1Scca1)))) OR ((val = asn1Sccf3)))) OR ((val = asn1Scca2)))) OR ((val = asn1Sccselectstate)));
    ret.ErrorCode := (if ret.Success then 0 else ERR_HEATTRANSFERLAB_STATES);
    return ret;
end asn1SccHeattransferlab_States_IsConstraintValid;



function asn1SccHeattransferlab_Context_Equal (val1, val2 :  asn1SccHeattransferlab_Context) return Boolean
is
    pragma Warnings (Off, "initialization of ret has no effect");
    ret : Boolean := True;
    pragma Warnings (On, "initialization of ret has no effect");

begin
    ret := (val1.state = val2.state);

    if ret then
        ret := (val1.init_done = val2.init_done);

        if ret then
            ret := (val1.ok = val2.ok);

            if ret then
                ret := (val1.actual_state = val2.actual_state);

                if ret then
                    ret := (val1.last_good_state = val2.last_good_state);

                    if ret then
                        ret := (adaasn1rtl.Asn1Real_Equal(val1.temp_air, val2.temp_air));

                        if ret then
                            ret := (adaasn1rtl.Asn1Real_Equal(val1.temp_plate, val2.temp_plate));

                            if ret then
                                ret := (adaasn1rtl.Asn1Real_Equal(val1.press, val2.press));

                                if ret then
                                    ret := (adaasn1rtl.Asn1Real_Equal(val1.press_5km, val2.press_5km));

                                    if ret then
                                        ret := (adaasn1rtl.Asn1Real_Equal(val1.press_10km, val2.press_10km));

                                        if ret then
                                            ret := (adaasn1rtl.Asn1Real_Equal(val1.press_18km, val2.press_18km));

                                            if ret then
                                                ret := (adaasn1rtl.Asn1Real_Equal(val1.power, val2.power));

                                                if ret then
                                                    ret := (adaasn1rtl.Asn1Real_Equal(val1.htl_time, val2.htl_time));

                                                    if ret then
                                                        ret := (adaasn1rtl.Asn1Real_Equal(val1.a1_duration_emergency, val2.a1_duration_emergency));

                                                        if ret then
                                                            ret := (adaasn1rtl.Asn1Real_Equal(val1.a1_duration_max, val2.a1_duration_max));

                                                            if ret then
                                                                ret := (adaasn1rtl.Asn1Real_Equal(val1.power_a2, val2.power_a2));

                                                                if ret then
                                                                    ret := (adaasn1rtl.Asn1Real_Equal(val1.a2_duration_max, val2.a2_duration_max));

                                                                    if ret then
                                                                        ret := (adaasn1rtl.Asn1Real_Equal(val1.n, val2.n));

                                                                        if ret then
                                                                            ret := (adaasn1rtl.Asn1Real_Equal(val1.power_f1, val2.power_f1));

                                                                            if ret then
                                                                                ret := (val1.f1_duration = val2.f1_duration);

                                                                                if ret then
                                                                                    ret := (adaasn1rtl.Asn1Real_Equal(val1.m, val2.m));

                                                                                    if ret then
                                                                                        ret := (val1.f2_duration = val2.f2_duration);

                                                                                    end if;
                                                                                end if;
                                                                            end if;
                                                                        end if;
                                                                    end if;
                                                                end if;
                                                            end if;
                                                        end if;
                                                    end if;
                                                end if;
                                            end if;
                                        end if;
                                    end if;
                                end if;
                            end if;
                        end if;
                    end if;
                end if;
            end if;
        end if;
    end if;
	return ret;

end asn1SccHeattransferlab_Context_Equal;

function asn1SccHeattransferlab_Context_Init return asn1SccHeattransferlab_Context
is
    val: asn1SccHeattransferlab_Context;
begin

    --set state 
    val.state := asn1SccHeattransferlab_States_Init;
    --set init_done 
    val.init_done := FALSE;
    --set ok 
    val.ok := TASTE_BasicTypes.asn1SccT_Boolean_Init;
    --set actual_state 
    val.actual_state := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccHTL_State_Init;
    --set last_good_state 
    val.last_good_state := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccHTL_State_Init;
    --set temp_air 
    val.temp_air := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_Init;
    --set temp_plate 
    val.temp_plate := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_Init;
    --set press 
    val.press := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_Init;
    --set press_5km 
    val.press_5km := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_Init;
    --set press_10km 
    val.press_10km := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_Init;
    --set press_18km 
    val.press_18km := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_Init;
    --set power 
    val.power := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_Init;
    --set htl_time 
    val.htl_time := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Double_Init;
    --set a1_duration_emergency 
    val.a1_duration_emergency := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Double_Init;
    --set a1_duration_max 
    val.a1_duration_max := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Double_Init;
    --set power_a2 
    val.power_a2 := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_Init;
    --set a2_duration_max 
    val.a2_duration_max := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Double_Init;
    --set n 
    val.n := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_Init;
    --set power_f1 
    val.power_f1 := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_Init;
    --set f1_duration 
    val.f1_duration := TASTE_BasicTypes.asn1SccT_UInt32_Init;
    --set m 
    val.m := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_Init;
    --set f2_duration 
    val.f2_duration := TASTE_BasicTypes.asn1SccT_UInt32_Init;
	pragma Warnings (Off, "object ""val"" is always");
    return val;
	pragma Warnings (On, "object ""val"" is always");
end asn1SccHeattransferlab_Context_Init;

function asn1SccHeattransferlab_Context_IsConstraintValid(val : asn1SccHeattransferlab_Context) return adaasn1rtl.ASN1_RESULT
is
    pragma Warnings (Off, "initialization of ret has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ret has no effect");        
begin
    ret := asn1SccHeattransferlab_States_IsConstraintValid(val.state);
    if ret.Success then
        ret := TASTE_BasicTypes.asn1SccT_Boolean_IsConstraintValid(val.ok);
        if ret.Success then
            ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccHTL_State_IsConstraintValid(val.actual_state);
            if ret.Success then
                ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccHTL_State_IsConstraintValid(val.last_good_state);
                if ret.Success then
                    ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_IsConstraintValid(val.temp_air);
                    if ret.Success then
                        ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_IsConstraintValid(val.temp_plate);
                        if ret.Success then
                            ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_IsConstraintValid(val.press);
                            if ret.Success then
                                ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_IsConstraintValid(val.press_5km);
                                if ret.Success then
                                    ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_IsConstraintValid(val.press_10km);
                                    if ret.Success then
                                        ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_IsConstraintValid(val.press_18km);
                                        if ret.Success then
                                            ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_IsConstraintValid(val.power);
                                            if ret.Success then
                                                ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Double_IsConstraintValid(val.htl_time);
                                                if ret.Success then
                                                    ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Double_IsConstraintValid(val.a1_duration_emergency);
                                                    if ret.Success then
                                                        ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Double_IsConstraintValid(val.a1_duration_max);
                                                        if ret.Success then
                                                            ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_IsConstraintValid(val.power_a2);
                                                            if ret.Success then
                                                                ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Double_IsConstraintValid(val.a2_duration_max);
                                                                if ret.Success then
                                                                    ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_IsConstraintValid(val.n);
                                                                    if ret.Success then
                                                                        ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_IsConstraintValid(val.power_f1);
                                                                        if ret.Success then
                                                                            ret := TASTE_BasicTypes.asn1SccT_UInt32_IsConstraintValid(val.f1_duration);
                                                                            if ret.Success then
                                                                                ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_IsConstraintValid(val.m);
                                                                                if ret.Success then
                                                                                    ret := TASTE_BasicTypes.asn1SccT_UInt32_IsConstraintValid(val.f2_duration);
                                                                                end if;
                                                                            end if;
                                                                        end if;
                                                                    end if;
                                                                end if;
                                                            end if;
                                                        end if;
                                                    end if;
                                                end if;
                                            end if;
                                        end if;
                                    end if;
                                end if;
                            end if;
                        end if;
                    end if;
                end if;
            end if;
        end if;
    end if;
    return ret;
end asn1SccHeattransferlab_Context_IsConstraintValid;



function asn1SccOBSW_DP_SingleData_selection_Equal (val1, val2 :  asn1SccOBSW_DP_SingleData_selection) return Boolean
is

begin
	return val1 = val2;

end asn1SccOBSW_DP_SingleData_selection_Equal;

function asn1SccOBSW_DP_SingleData_selection_Init return asn1SccOBSW_DP_SingleData_selection
is
    val: asn1SccOBSW_DP_SingleData_selection;
begin
    val := asn1Sccgps_present;
	pragma Warnings (Off, "object ""val"" is always");
    return val;
	pragma Warnings (On, "object ""val"" is always");
end asn1SccOBSW_DP_SingleData_selection_Init;

function asn1SccOBSW_DP_SingleData_selection_IsConstraintValid(val : asn1SccOBSW_DP_SingleData_selection) return adaasn1rtl.ASN1_RESULT
is
    pragma Warnings (Off, "initialization of ret has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ret has no effect");        
begin
    ret.Success := (((((((((((((((((val = asn1Sccgps_present)) OR ((val = asn1Sccimu_present)))) OR ((val = asn1Scctc74s_present)))) OR ((val = asn1Sccpt1000s_present)))) OR ((val = asn1Sccps1_present)))) OR ((val = asn1Sccps2_present)))) OR ((val = asn1Sccheater1_present)))) OR ((val = asn1Sccheater2_present)))) OR ((val = asn1Sccanemometer_present)));
    ret.ErrorCode := (if ret.Success then 0 else ERR_OBSW_DP_SINGLEDATA_SELECTION);
    return ret;
end asn1SccOBSW_DP_SingleData_selection_IsConstraintValid;



function asn1SccTC_Heater_command_selection_Equal (val1, val2 :  asn1SccTC_Heater_command_selection) return Boolean
is

begin
	return val1 = val2;

end asn1SccTC_Heater_command_selection_Equal;

function asn1SccTC_Heater_command_selection_Init return asn1SccTC_Heater_command_selection
is
    val: asn1SccTC_Heater_command_selection;
begin
    val := asn1Sccpower_manual_present;
	pragma Warnings (Off, "object ""val"" is always");
    return val;
	pragma Warnings (On, "object ""val"" is always");
end asn1SccTC_Heater_command_selection_Init;

function asn1SccTC_Heater_command_selection_IsConstraintValid(val : asn1SccTC_Heater_command_selection) return adaasn1rtl.ASN1_RESULT
is
    pragma Warnings (Off, "initialization of ret has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ret has no effect");        
begin
    ret.Success := (((val = asn1Sccpower_manual_present)) OR ((val = asn1Sccmax_min_present)));
    ret.ErrorCode := (if ret.Success then 0 else ERR_TC_HEATER_COMMAND_SELECTION);
    return ret;
end asn1SccTC_Heater_command_selection_IsConstraintValid;



function asn1SccTC_selection_Equal (val1, val2 :  asn1SccTC_selection) return Boolean
is

begin
	return val1 = val2;

end asn1SccTC_selection_Equal;

function asn1SccTC_selection_Init return asn1SccTC_selection
is
    val: asn1SccTC_selection;
begin
    val := asn1Sccheater_commands_present;
	pragma Warnings (Off, "object ""val"" is always");
    return val;
	pragma Warnings (On, "object ""val"" is always");
end asn1SccTC_selection_Init;

function asn1SccTC_selection_IsConstraintValid(val : asn1SccTC_selection) return adaasn1rtl.ASN1_RESULT
is
    pragma Warnings (Off, "initialization of ret has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ret has no effect");        
begin
    ret.Success := (((val = asn1Sccheater_commands_present)) OR ((val = asn1Sccsystem_commands_present)));
    ret.ErrorCode := (if ret.Success then 0 else ERR_TC_SELECTION);
    return ret;
end asn1SccTC_selection_IsConstraintValid;


pragma Warnings (On, "condition can only be False if invalid values present");
pragma Warnings (On, "condition can only be True if invalid values present");

 
end Heattransferlab_Datamodel;