pragma Style_Checks (Off);
--  Code automatically generated by asn1scc tool
pragma Warnings (Off, "redundant with clause in body");

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
use type TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float;
use type TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Double;
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
    val := asn1Scca2;
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
    ret.Success := (((((((((val = asn1Scca2)) OR ((val = asn1Sccf2)))) OR ((val = asn1Sccf1)))) OR ((val = asn1Scca1)))) OR ((val = asn1Sccf3)));
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
            ret := (adaasn1rtl.Asn1Real_Equal(val1.press, val2.press));

            if ret then
                ret := (adaasn1rtl.Asn1Real_Equal(val1.press_10km, val2.press_10km));

                if ret then
                    ret := (adaasn1rtl.Asn1Real_Equal(val1.press_18km, val2.press_18km));

                    if ret then
                        ret := (adaasn1rtl.Asn1Real_Equal(val1.mission_time, val2.mission_time));

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
    --set press 
    val.press := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_Init;
    --set press_10km 
    val.press_10km := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_Init;
    --set press_18km 
    val.press_18km := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_Init;
    --set mission_time 
    val.mission_time := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Double_Init;
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
        ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_IsConstraintValid(val.press);
        if ret.Success then
            ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_IsConstraintValid(val.press_10km);
            if ret.Success then
                ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Float_IsConstraintValid(val.press_18km);
                if ret.Success then
                    ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Double_IsConstraintValid(val.mission_time);
                end if;
            end if;
        end if;
    end if;
    return ret;
end asn1SccHeattransferlab_Context_IsConstraintValid;



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


pragma Warnings (On, "condition can only be False if invalid values present");
pragma Warnings (On, "condition can only be True if invalid values present");

 
end Heattransferlab_Datamodel;