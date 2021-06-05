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
use type TASTE_BasicTypes.asn1SccT_Int32;
use type TASEC_LAB_B2SPACE_DATAVIEW.asn1SccPT1000s_Channels;
pragma Warnings (On, "use clause for type");
pragma Warnings (On, "is already use-visible through previous use_type_clause at");
package body Context_pt1000sensors with SPARK_Mode is



pragma Warnings (Off, "condition can only be False if invalid values present");
pragma Warnings (Off, "condition can only be True if invalid values present");


function asn1SccContext_pt1000sensors_Equal (val1, val2 :  asn1SccContext_pt1000sensors) return Boolean
is
    pragma Warnings (Off, "initialization of ret has no effect");
    ret : Boolean := True;
    pragma Warnings (On, "initialization of ret has no effect");

begin
    ret := (val1.vcc_ch = val2.vcc_ch);

    if ret then
        ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccPT1000s_Channels_Equal(val1.channels, val2.channels);

    end if;
	return ret;

end asn1SccContext_pt1000sensors_Equal;

function asn1SccContext_pt1000sensors_Init return asn1SccContext_pt1000sensors
is
    val: asn1SccContext_pt1000sensors;
begin

    --set vcc_ch 
    val.vcc_ch := TASTE_BasicTypes.asn1SccT_Int32_Init;
    --set channels 
    val.channels := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccPT1000s_Channels_Init;
	pragma Warnings (Off, "object ""val"" is always");
    return val;
	pragma Warnings (On, "object ""val"" is always");
end asn1SccContext_pt1000sensors_Init;

function asn1SccContext_pt1000sensors_IsConstraintValid(val : asn1SccContext_pt1000sensors) return adaasn1rtl.ASN1_RESULT
is
    pragma Warnings (Off, "initialization of ret has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ret has no effect");        
begin
    ret := TASTE_BasicTypes.asn1SccT_Int32_IsConstraintValid(val.vcc_ch);
    if ret.Success then
        ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccPT1000s_Channels_IsConstraintValid(val.channels);
    end if;
    return ret;
end asn1SccContext_pt1000sensors_IsConstraintValid;


pragma Warnings (On, "condition can only be False if invalid values present");
pragma Warnings (On, "condition can only be True if invalid values present");

 
end Context_pt1000sensors;