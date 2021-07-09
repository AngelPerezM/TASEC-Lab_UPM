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



package Context_watchdog with SPARK_Mode
is


-- asn1SccContext_watchdog --------------------------------------------

type asn1SccContext_watchdog is record 
    timeout : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccWD_TIMEOUT;
end record;


function asn1SccContext_watchdog_Equal(val1, val2 : asn1SccContext_watchdog) return Boolean;

function asn1SccContext_watchdog_Init return asn1SccContext_watchdog;

ERR_CONTEXT_WATCHDOG:constant Integer := 8737; 
ERR_CONTEXT_WATCHDOG_TIMEOUT_2:constant Integer := 8730; 
function asn1SccContext_watchdog_IsConstraintValid(val : asn1SccContext_watchdog) return adaasn1rtl.ASN1_RESULT;
pragma Warnings (Off, "there are no others");
watchdog_ctxt : constant Context_watchdog.asn1SccContext_watchdog:= asn1SccContext_watchdog'(
    timeout => 15
    ); 
pragma Warnings (On, "there are no others");
private
   --# hide Context_watchdog;


end Context_watchdog;