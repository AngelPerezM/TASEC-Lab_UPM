-- DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
-- Generated by Kazoo (templates/glue/language_wrappers/ri_adb/function.tmplt)
-- Date : 2021-07-13 16:37:57

package body Heattransferlab_RI is

   procedure Kickthedog is
      procedure C_Kickthedog
         with Import,
              Convention => C,
              Link_Name  => "heattransferlab_RI_KickTheDog";
   begin
         C_Kickthedog;
   end Kickthedog;
   
   procedure Recordhtlparams
      (Htl_State : in   out asn1SccHtl_State;
       F1_Max_Time : in out asn1SccT_Double;
       F2_Max_Time : in out asn1SccT_Double;
       M : in           out asn1SccT_Float;
       N : in           out asn1SccT_Float;
       Power_F1 : in    out asn1SccT_Float) is
      procedure C_Recordhtlparams
         (Htl_State : in   out asn1SccHtl_State;
          F1_Max_Time : in out asn1SccT_Double;
          F2_Max_Time : in out asn1SccT_Double;
          M : in           out asn1SccT_Float;
          N : in           out asn1SccT_Float;
          Power_F1 : in    out asn1SccT_Float)
         with Import,
              Convention => C,
              Link_Name  => "heattransferlab_RI_RecordHTLParams";
   begin
         C_Recordhtlparams (htl_state, f1_max_time, f2_max_time, m, n, power_f1);
   end Recordhtlparams;
   
   procedure Recoverhtlparams
      (Htl_State :   out asn1SccHtl_State;
       F1_Max_Time : out asn1SccT_Double;
       F2_Max_Time : out asn1SccT_Double;
       M :           out asn1SccT_Float;
       N :           out asn1SccT_Float;
       Power_F1 :    out asn1SccT_Float) is
      procedure C_Recoverhtlparams
         (Htl_State :   out asn1SccHtl_State;
          F1_Max_Time : out asn1SccT_Double;
          F2_Max_Time : out asn1SccT_Double;
          M :           out asn1SccT_Float;
          N :           out asn1SccT_Float;
          Power_F1 :    out asn1SccT_Float)
         with Import,
              Convention => C,
              Link_Name  => "heattransferlab_RI_RecoverHTLParams";
   begin
         C_Recoverhtlparams (htl_state, f1_max_time, f2_max_time, m, n, power_f1);
   end Recoverhtlparams;
   
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
