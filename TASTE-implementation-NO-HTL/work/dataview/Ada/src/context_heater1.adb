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

pragma Warnings (On, "redundant with clause in body");

pragma Warnings (Off, "use clause for type");
pragma Warnings (Off, "is already use-visible through previous use_type_clause at");
use type TASTE_BasicTypes.asn1SccT_Int32;
pragma Warnings (On, "use clause for type");
pragma Warnings (On, "is already use-visible through previous use_type_clause at");
package body Context_heater1 with SPARK_Mode is



pragma Warnings (Off, "condition can only be False if invalid values present");
pragma Warnings (Off, "condition can only be True if invalid values present");


function asn1SccContext_heater1_Equal (val1, val2 :  asn1SccContext_heater1) return Boolean
is
    pragma Warnings (Off, "initialization of ret has no effect");
    ret : Boolean := True;
    pragma Warnings (On, "initialization of ret has no effect");

begin
    ret := (val1.gpio_pin = val2.gpio_pin);

	return ret;

end asn1SccContext_heater1_Equal;

function asn1SccContext_heater1_Init return asn1SccContext_heater1
is
    val: asn1SccContext_heater1;
begin

    --set gpio_pin 
    val.gpio_pin := TASTE_BasicTypes.asn1SccT_Int32_Init;
	pragma Warnings (Off, "object ""val"" is always");
    return val;
	pragma Warnings (On, "object ""val"" is always");
end asn1SccContext_heater1_Init;

function asn1SccContext_heater1_IsConstraintValid(val : asn1SccContext_heater1) return adaasn1rtl.ASN1_RESULT
is
    pragma Warnings (Off, "initialization of ret has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ret has no effect");        
begin
    ret := TASTE_BasicTypes.asn1SccT_Int32_IsConstraintValid(val.gpio_pin);
    return ret;
end asn1SccContext_heater1_IsConstraintValid;


pragma Warnings (On, "condition can only be False if invalid values present");
pragma Warnings (On, "condition can only be True if invalid values present");

 
end Context_heater1;