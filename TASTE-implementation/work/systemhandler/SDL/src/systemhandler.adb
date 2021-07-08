-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !

with System.IO;
use System.IO;

with Ada.Unchecked_Conversion;
with Ada.Numerics.Generic_Elementary_Functions;

package body Systemhandler is
   CS_Only : constant := 1;
   procedure Execute_Transition (Id : Integer);
   procedure StopSystem is
      begin
         --  stop_DM (8,17)
         RI_0_stop_DM;
         --  stop_IIC (10,17)
         RI_0_stop_IIC;
         --  stop_DL (12,17)
         RI_0_stop_DL;
         --  stop_WD (14,17)
         RI_0_stop_WD;
         --  StopSystem_Transition (None,None)
         StopSystem_Transition;
         --  RETURN  (None,None) at 250, 378
         return;
      end StopSystem;
      

   procedure StopSystem_Transition is
      begin
         case ctxt.state is
            when asn1Sccwait =>
               Execute_Transition (CS_Only);
            when others =>
               Execute_Transition (CS_Only);
         end case;
      end StopSystem_Transition;
      

   procedure Execute_Transition (Id : Integer) is
      trId : Integer := Id;
      begin
         while (trId /= -1) loop
            case trId is
               when 0 =>
                  --  NEXT_STATE Wait (21,18) at 320, 60
                  trId := -1;
                  ctxt.State := asn1SccWait;
                  goto Next_Transition;
               when CS_Only =>
                  trId := -1;
                  goto Next_Transition;
               when others =>
                  null;
            end case;
            <<Next_Transition>>
            null;
         end loop;
      end Execute_Transition;
      

   procedure Startup is
      begin
         Execute_Transition (0);
         ctxt.Init_Done := True;
      end Startup;
   begin
      Startup;
end Systemhandler;