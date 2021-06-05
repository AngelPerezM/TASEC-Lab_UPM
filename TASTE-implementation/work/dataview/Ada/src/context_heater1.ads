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



package Context_heater1 with SPARK_Mode
is


-- asn1SccContext_heater1 --------------------------------------------

type asn1SccContext_heater1 is record 
    gpio_pin : TASTE_BasicTypes.asn1SccT_Int32;
end record;


function asn1SccContext_heater1_Equal(val1, val2 : asn1SccContext_heater1) return Boolean;

function asn1SccContext_heater1_Init return asn1SccContext_heater1;

ERR_CONTEXT_HEATER1:constant Integer := 6049; 
ERR_CONTEXT_HEATER1_GPIO_PIN_2:constant Integer := 6042; 
function asn1SccContext_heater1_IsConstraintValid(val : asn1SccContext_heater1) return adaasn1rtl.ASN1_RESULT;
pragma Warnings (Off, "there are no others");
heater1_ctxt : constant Context_heater1.asn1SccContext_heater1:= asn1SccContext_heater1'(
    gpio_pin => 12
    ); 
pragma Warnings (On, "there are no others");
private
   --# hide Context_heater1;


end Context_heater1;