-- DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
-- Generated by Kazoo (templates/glue/language_wrappers/ri_adb/function.tmplt)
-- Date : 2021-07-08 21:13:24

package body Systemhandler_RI is

   procedure Stop_Dl is
      procedure C_Stop_Dl
         with Import,
              Convention => C,
              Link_Name  => "systemhandler_RI_stop_DL";
   begin
         C_Stop_Dl;
   end Stop_Dl;
   
   procedure Stop_Dm is
      procedure C_Stop_Dm
         with Import,
              Convention => C,
              Link_Name  => "systemhandler_RI_stop_DM";
   begin
         C_Stop_Dm;
   end Stop_Dm;
   
   procedure Stop_Iic is
      procedure C_Stop_Iic
         with Import,
              Convention => C,
              Link_Name  => "systemhandler_RI_stop_IIC";
   begin
         C_Stop_Iic;
   end Stop_Iic;
   
   procedure Stop_Wd is
      procedure C_Stop_Wd
         with Import,
              Convention => C,
              Link_Name  => "systemhandler_RI_stop_WD";
   begin
         C_Stop_Wd;
   end Stop_Wd;

end Systemhandler_RI;
