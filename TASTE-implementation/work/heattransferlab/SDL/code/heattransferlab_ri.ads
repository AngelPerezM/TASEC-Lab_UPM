--  DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
--  Generated by TASTE (Kazoo template templates/skeletons/ada-ri-source/function.tmplt)
--  2021-06-28 13:00:54
--  Timers:
--    |_ f1_timeout
--    |_ f2_timeout

with Tasec_Lab_B2space_Dataview; use Tasec_Lab_B2space_Dataview;
with Taste_Basictypes;           use Taste_Basictypes;

package Heattransferlab_RI is

   procedure Retreivesingledata (Filter : in out asn1SccObsw_Dp_Filter; Single_Data : out asn1SccObsw_Dp_Singledata);
   procedure Stopsystem;
   procedure Gettime (Gps_Time : out asn1SccT_Double; Mission_Time : out asn1SccT_Double);
   procedure Setpowerh2 (Power : in out asn1SccT_Float);

   --  Timer f1_timeout Set and Reset functions
   procedure Set_F1_Timeout (Val : in out asn1SccT_UInt32);

   procedure Reset_F1_Timeout;

   --  Timer f2_timeout Set and Reset functions
   procedure Set_F2_Timeout (Val : in out asn1SccT_UInt32);

   procedure Reset_F2_Timeout;

end Heattransferlab_RI;
