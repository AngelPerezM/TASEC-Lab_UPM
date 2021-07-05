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



package Context_datapool with SPARK_Mode
is


-- asn1SccContext_datapool --------------------------------------------

type asn1SccContext_datapool is record 
    maxoutdatedsecs : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Double;
end record;


function asn1SccContext_datapool_Equal(val1, val2 : asn1SccContext_datapool) return Boolean;

function asn1SccContext_datapool_Init return asn1SccContext_datapool;

ERR_CONTEXT_DATAPOOL:constant Integer := 8618; 
ERR_CONTEXT_DATAPOOL_MAXOUTDATEDSECS_2:constant Integer := 8611; 
function asn1SccContext_datapool_IsConstraintValid(val : asn1SccContext_datapool) return adaasn1rtl.ASN1_RESULT;
pragma Warnings (Off, "there are no others");
datapool_ctxt : constant Context_datapool.asn1SccContext_datapool:= asn1SccContext_datapool'(
    maxoutdatedsecs => 5.00000000000000000000E+000
    ); 
pragma Warnings (On, "there are no others");
private
   --# hide Context_datapool;


end Context_datapool;