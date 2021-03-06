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



package Context_tc74sensors with SPARK_Mode
is


-- asn1SccContext_tc74sensors --------------------------------------------

type asn1SccContext_tc74sensors is record 
    i2c_channels : TASEC_LAB_B2SPACE_DATAVIEW.asn1SccTC74s_I2CBuses;
end record;


function asn1SccContext_tc74sensors_Equal(val1, val2 : asn1SccContext_tc74sensors) return Boolean;

function asn1SccContext_tc74sensors_Init return asn1SccContext_tc74sensors;

ERR_CONTEXT_TC74SENSORS:constant Integer := 8674; 
ERR_CONTEXT_TC74SENSORS_I2C_CHANNELS_2:constant Integer := 8667; 
function asn1SccContext_tc74sensors_IsConstraintValid(val : asn1SccContext_tc74sensors) return adaasn1rtl.ASN1_RESULT;
pragma Warnings (Off, "there are no others");
tc74sensors_ctxt : constant Context_tc74sensors.asn1SccContext_tc74sensors:= asn1SccContext_tc74sensors'(
    i2c_channels => TASEC_LAB_B2SPACE_DATAVIEW.asn1SccTC74s_I2CBuses'(Data => TASEC_LAB_B2SPACE_DATAVIEW.asn1SccTC74s_I2CBuses_array'(
                                                                                                                      1=>11, 
                                                                                                                      2=>12, 
                                                                                                                      3=>13, 
                                                                                                                      4=>14, 
                                                                                                                      5=>15, others => -2147483648))
    ); 
pragma Warnings (On, "there are no others");
private
   --# hide Context_tc74sensors;


end Context_tc74sensors;