--  DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
--  Generated by TASTE (Kazoo template templates/skeletons/ada-ri-source/function.tmplt)
--  2021-06-29 11:21:06
--  Timers:

with Tasec_Lab_B2space_Dataview; use Tasec_Lab_B2space_Dataview;
with Taste_Basictypes;           use Taste_Basictypes;

package Heattransferlab_RI is

   procedure Retreivesingledata (Filter : in out asn1SccObsw_Dp_Filter; Single_Data : out asn1SccObsw_Dp_Singledata);
   procedure Stopsystem;
   procedure Gettime (Gps_Time : out asn1SccT_Double; Mission_Time : out asn1SccT_Double);
   procedure Setpowerh2 (Power : in out asn1SccT_Float);

end Heattransferlab_RI;
