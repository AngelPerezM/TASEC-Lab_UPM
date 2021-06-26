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



package Context_gpsreader with SPARK_Mode
is


-- asn1SccContext_gpsreader --------------------------------------------

type asn1SccContext_gpsreader is record 
    max_retries : TASTE_BasicTypes.asn1SccT_UInt32;
    waiting_time_per_retry_us : TASTE_BasicTypes.asn1SccT_UInt32;
end record;


function asn1SccContext_gpsreader_Equal(val1, val2 : asn1SccContext_gpsreader) return Boolean;

function asn1SccContext_gpsreader_Init return asn1SccContext_gpsreader;

ERR_CONTEXT_GPSREADER:constant Integer := 99; 
ERR_CONTEXT_GPSREADER_MAX_RETRIES_2:constant Integer := 78; 
ERR_CONTEXT_GPSREADER_WAITING_TIME_PER_RETRY_US_2:constant Integer := 92; 
function asn1SccContext_gpsreader_IsConstraintValid(val : asn1SccContext_gpsreader) return adaasn1rtl.ASN1_RESULT;
pragma Warnings (Off, "there are no others");
gpsreader_ctxt : constant Context_gpsreader.asn1SccContext_gpsreader:= asn1SccContext_gpsreader'(
    max_retries => 2,
    waiting_time_per_retry_us => 300000
    ); 
pragma Warnings (On, "there are no others");
private
   --# hide Context_gpsreader;


end Context_gpsreader;