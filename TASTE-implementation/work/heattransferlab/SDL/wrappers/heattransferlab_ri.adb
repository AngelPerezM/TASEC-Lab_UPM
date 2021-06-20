-- DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
-- Generated by Kazoo (templates/glue/language_wrappers/ri_adb/function.tmplt)
-- Date : 2021-06-18 14:58:12

package body Heattransferlab_RI is

   procedure Reset_F1_Timeout is
      procedure C_Reset_F1_Timeout
         with Import,
              Convention => C,
              Link_Name  => "heattransferlab_RI_RESET_f1_timeout";
   begin
         C_Reset_F1_Timeout;
   end Reset_F1_Timeout;
   
   procedure Reset_F2_Timeout is
      procedure C_Reset_F2_Timeout
         with Import,
              Convention => C,
              Link_Name  => "heattransferlab_RI_RESET_f2_timeout";
   begin
         C_Reset_F2_Timeout;
   end Reset_F2_Timeout;
   
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
   
   procedure Set_F1_Timeout
      (Val : in out asn1SccT_Uint32) is
      procedure C_Set_F1_Timeout
         (Val : in out asn1SccT_Uint32)
         with Import,
              Convention => C,
              Link_Name  => "heattransferlab_RI_SET_f1_timeout";
   begin
         C_Set_F1_Timeout (Val);
   end Set_F1_Timeout;
   
   procedure Set_F2_Timeout
      (Val : in out asn1SccT_Uint32) is
      procedure C_Set_F2_Timeout
         (Val : in out asn1SccT_Uint32)
         with Import,
              Convention => C,
              Link_Name  => "heattransferlab_RI_SET_f2_timeout";
   begin
         C_Set_F2_Timeout (Val);
   end Set_F2_Timeout;
   
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
