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
use type TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Double;
pragma Warnings (On, "use clause for type");
pragma Warnings (On, "is already use-visible through previous use_type_clause at");
package body Context_datapool with SPARK_Mode is



pragma Warnings (Off, "condition can only be False if invalid values present");
pragma Warnings (Off, "condition can only be True if invalid values present");


function asn1SccContext_datapool_Equal (val1, val2 :  asn1SccContext_datapool) return Boolean
is
    pragma Warnings (Off, "initialization of ret has no effect");
    ret : Boolean := True;
    pragma Warnings (On, "initialization of ret has no effect");

begin
    ret := (adaasn1rtl.Asn1Real_Equal(val1.maxoutdatedsecs, val2.maxoutdatedsecs));

	return ret;

end asn1SccContext_datapool_Equal;

function asn1SccContext_datapool_Init return asn1SccContext_datapool
is
    val: asn1SccContext_datapool;
begin

    --set maxoutdatedsecs 
    val.maxoutdatedsecs := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Double_Init;
	pragma Warnings (Off, "object ""val"" is always");
    return val;
	pragma Warnings (On, "object ""val"" is always");
end asn1SccContext_datapool_Init;

function asn1SccContext_datapool_IsConstraintValid(val : asn1SccContext_datapool) return adaasn1rtl.ASN1_RESULT
is
    pragma Warnings (Off, "initialization of ret has no effect");        
    ret : adaasn1rtl.ASN1_RESULT := adaasn1rtl.ASN1_RESULT'(Success => true, ErrorCode => 0);
    pragma Warnings (On, "initialization of ret has no effect");        
begin
    ret := TASEC_LAB_B2SPACE_DATAVIEW.asn1SccT_Double_IsConstraintValid(val.maxoutdatedsecs);
    return ret;
end asn1SccContext_datapool_IsConstraintValid;


pragma Warnings (On, "condition can only be False if invalid values present");
pragma Warnings (On, "condition can only be True if invalid values present");

 
end Context_datapool;