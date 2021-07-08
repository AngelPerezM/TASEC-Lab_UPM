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
   procedure KickTheDog;
   procedure RecordHTLParams (Htl_State : in out asn1SccHTL_State; F1_Max_Time : in out asn1SccT_Double; F2_Max_Time : in out asn1SccT_Double);
   procedure RecoverHTLParams (Htl_State : out asn1SccHTL_State; F1_Max_Time : out asn1SccT_Double; F2_Max_Time : out asn1SccT_Double);
   procedure RetreiveSingleData (Filter : in out asn1SccOBSW_DP_Filter; Single_Data : out asn1SccOBSW_DP_SingleData);
   procedure StopSystem;
   procedure getTime (Gps_Time : out asn1SccT_Double; Mission_Time : out asn1SccT_Double);
   procedure setPowerH2 (Power : in out asn1SccT_Float);
end Heattransferlab_RI;