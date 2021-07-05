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


pragma Warnings (Off, "no entities of ""TASEC_LAB_B2SPACE_DATAVIEW"" are referenced");
pragma Warnings (Off, "use clause for package ""TASEC_LAB_B2SPACE_DATAVIEW"" has no effect");
with TASEC_LAB_B2SPACE_DATAVIEW; use TASEC_LAB_B2SPACE_DATAVIEW;
pragma Warnings (On, "no entities of ""TASEC_LAB_B2SPACE_DATAVIEW"" are referenced");
pragma Warnings (On, "use clause for package ""TASEC_LAB_B2SPACE_DATAVIEW"" has no effect");



package Context_pt1000sensors with SPARK_Mode
is


-- asn1SccContext_pt1000sensors --------------------------------------------

type asn1SccContext_pt1000sensors is record 
    vcc_ch : TASTE_BasicTypes.asn1SccT_Int32;
    channels : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccPT1000s_Channels;
end record;


function asn1SccContext_pt1000sensors_Equal(val1, val2 : asn1SccContext_pt1000sensors) return Boolean;

function asn1SccContext_pt1000sensors_Init return asn1SccContext_pt1000sensors;

ERR_CONTEXT_PT1000SENSORS:constant Integer := 8597; 
ERR_CONTEXT_PT1000SENSORS_VCC_CH_2:constant Integer := 8562; 
ERR_CONTEXT_PT1000SENSORS_CHANNELS_2:constant Integer := 8590; 
function asn1SccContext_pt1000sensors_IsConstraintValid(val : asn1SccContext_pt1000sensors) return adaasn1rtl.ASN1_RESULT;
pragma Warnings (Off, "there are no others");
pt1000sensors_ctxt : constant Context_pt1000sensors.asn1SccContext_pt1000sensors:= asn1SccContext_pt1000sensors'(
    vcc_ch => 7,
    channels => TASEC_LAB_B2SPACE_DATAVIEW.asn1SccPT1000s_Channels'(Data => TASEC_LAB_B2SPACE_DATAVIEW.asn1SccPT1000s_Channels_array'(
                                                                                                                          1=>0, 
                                                                                                                          2=>1, 
                                                                                                                          3=>2, 
                                                                                                                          4=>3, 
                                                                                                                          5=>4, 
                                                                                                                          6=>5, 
                                                                                                                          7=>6, others => -2147483648))
    ); 
pragma Warnings (On, "there are no others");
private
   --# hide Context_pt1000sensors;


end Context_pt1000sensors;