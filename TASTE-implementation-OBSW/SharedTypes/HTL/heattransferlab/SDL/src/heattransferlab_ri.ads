--  This file is a stub for the implementation of the required interfaces
--  It is normally overwritten by TASTE with the actual connection to the
--  middleware. If you use Opengeode independently from TASTE you must
--  edit the .adb (body) with your own implementation of these functions.
--  The body stub will be generated only once.

with TASEC_LAB_B2SPACE_DATAVIEW;
use TASEC_LAB_B2SPACE_DATAVIEW;
with TASTE_BasicTypes;
use TASTE_BasicTypes;
with adaasn1rtl;
use adaasn1rtl;

package Heattransferlab_RI is
   procedure RetreiveSingleData (Filter : in out asn1SccOBSW_DP_Filter; Single_Data : out asn1SccOBSW_DP_SingleData);
   procedure getTime (Gps_Time : out asn1SccT_Double; Mission_Time : out asn1SccT_Double);
   procedure setOnOffH2 (Cmd : in out asn1SccHeater_On_Off);
   procedure setPowerH2 (Power : in out asn1SccT_Float);
   procedure SET_f1_timeout (Val : in out asn1SccT_UInt32);
   procedure RESET_f1_timeout;
   procedure SET_f2_timeout (Val : in out asn1SccT_UInt32);
   procedure RESET_f2_timeout;
end Heattransferlab_RI;