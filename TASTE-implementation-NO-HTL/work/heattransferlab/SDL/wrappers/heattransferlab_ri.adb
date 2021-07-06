-- DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
-- Generated by Kazoo (templates/glue/language_wrappers/ri_adb/function.tmplt)
-- Date : 2021-06-29 11:21:06

package body Heattransferlab_RI is

   procedure Retreivesingledata
      (Filter : in   out asn1SccObsw_Dp_Filter;
       Single_Data : out asn1SccObsw_Dp_Singledata) is
      procedure C_Retreivesingledata
         (Filter : in   out asn1SccObsw_Dp_Filter;
          Single_Data : out asn1SccObsw_Dp_Singledata)
         with Import,
              Convention => C,
              Link_Name  => "heattransferlab_RI_RetreiveSingleData";
   begin
         C_Retreivesingledata (filter, single_data);
   end Retreivesingledata;
   
   procedure Stopsystem is
      procedure C_Stopsystem
         with Import,
              Convention => C,
              Link_Name  => "heattransferlab_RI_StopSystem";
   begin
         C_Stopsystem;
   end Stopsystem;
   
   procedure Gettime
      (Gps_Time :     out asn1SccT_Double;
       Mission_Time : out asn1SccT_Double) is
      procedure C_Gettime
         (Gps_Time :     out asn1SccT_Double;
          Mission_Time : out asn1SccT_Double)
         with Import,
              Convention => C,
              Link_Name  => "heattransferlab_RI_getTime";
   begin
         C_Gettime (gps_time, mission_time);
   end Gettime;
   
   procedure Setpowerh2
      (Power : in out asn1SccT_Float) is
      procedure C_Setpowerh2
         (Power : in out asn1SccT_Float)
         with Import,
              Convention => C,
              Link_Name  => "heattransferlab_RI_setPowerH2";
   begin
         C_Setpowerh2 (power);
   end Setpowerh2;

end Heattransferlab_RI;
