-- DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
-- Generated by Kazoo (templates/glue/language_wrappers/ri_adb/function.tmplt)
-- Date : 2021-07-05 14:24:57

package body Thermostat_RI is

   procedure Setonoffh1
      (Command : in out asn1SccHeater_On_Off) is
      procedure C_Setonoffh1
         (Command : in out asn1SccHeater_On_Off)
         with Import,
              Convention => C,
              Link_Name  => "thermostat_RI_setOnOffH1";
   begin
         C_Setonoffh1 (command);
   end Setonoffh1;

end Thermostat_RI;
