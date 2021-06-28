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


pragma Warnings (Off, "no entities of ""TASTE_BasicTypes"" are referenced");
pragma Warnings (Off, "use clause for package ""TASTE_BasicTypes"" has no effect");
with TASTE_BasicTypes; use TASTE_BasicTypes;
pragma Warnings (On, "no entities of ""TASTE_BasicTypes"" are referenced");
pragma Warnings (On, "use clause for package ""TASTE_BasicTypes"" has no effect");



package Context_pressuresensors with SPARK_Mode
is


-- asn1SccContext_pressuresensors --------------------------------------------

type asn1SccContext_pressuresensors is record 
    ps1_id : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccSPI_ID;
    ps2_id : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccSPI_ID;
end record;


function asn1SccContext_pressuresensors_Equal(val1, val2 : asn1SccContext_pressuresensors) return Boolean;

function asn1SccContext_pressuresensors_Init return asn1SccContext_pressuresensors;

ERR_CONTEXT_PRESSURESENSORS:constant Integer := 8205; 
ERR_CONTEXT_PRESSURESENSORS_PS1_ID_2:constant Integer := 8156; 
ERR_CONTEXT_PRESSURESENSORS_PS2_ID_2:constant Integer := 8198; 
function asn1SccContext_pressuresensors_IsConstraintValid(val : asn1SccContext_pressuresensors) return adaasn1rtl.ASN1_RESULT;
pragma Warnings (Off, "there are no others");
pressuresensors_ctxt : constant Context_pressuresensors.asn1SccContext_pressuresensors:= asn1SccContext_pressuresensors'(
    ps1_id => TASEC_LAB_B2SPACE_DATAVIEW.asn1SccSPI_ID'(
        bus => 1,
        cs => 1
        ),
    ps2_id => TASEC_LAB_B2SPACE_DATAVIEW.asn1SccSPI_ID'(
        bus => 1,
        cs => 2
        )
    ); 
pragma Warnings (On, "there are no others");
private
   --# hide Context_pressuresensors;


end Context_pressuresensors;