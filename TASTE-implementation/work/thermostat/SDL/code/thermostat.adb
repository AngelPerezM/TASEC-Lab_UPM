-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !

with System.IO;
use System.IO;

with Ada.Unchecked_Conversion;
with Ada.Numerics.Generic_Elementary_Functions;

package body Thermostat is
   CS_Only : constant := 2;
   procedure Execute_Transition (Id : Integer);
   procedure notifyTempChanged(tempCelsius: in out asn1SccT_Float) is
      begin
         case ctxt.state is
            when asn1Sccwait =>
               ctxt.tempcelsius := tempCelsius;
               Execute_Transition (1);
            when others =>
               Execute_Transition (CS_Only);
         end case;
      end notifyTempChanged;
      

   procedure Execute_Transition (Id : Integer) is
      trId : Integer := Id;
      tmp16 : asn1SccHeater_On_Off;
      tmp25 : asn1SccHeater_On_Off;
      --  !! stack: _call_external_function line 1604
      begin
         while (trId /= -1) loop
            case trId is
               when 0 =>
                  --  writeln('[Thermostat] Startup') (12,14)
                  Put ("[Thermostat] Startup");
                  New_Line;
                  --  tempcelsius := 0.0 (14,13)
                  ctxt.tempcelsius := 0.0;
                  --  heaterison := False (15,0)
                  ctxt.heaterison := false;
                  --  NEXT_STATE Wait (17,18) at 125, 178
                  trId := -1;
                  ctxt.State := asn1SccWait;
                  goto Next_Transition;
               when 1 =>
                  --  DECISION tempcelsius (-1,-1)
                  --  ANSWER < 29.0 (25,17)
                  if (ctxt.tempcelsius) < 29.0 then
                     --  DECISION heaterison (-1,-1)
                     --  ANSWER true (29,25)
                     if (ctxt.heaterison) = true then
                        null;
                        --  ANSWER false (31,25)
                     elsif (ctxt.heaterison) = false then
                        --  writeln('[Thermostat] Engaging anemo heater') (33,33)
                        Put ("[Thermostat] Engaging anemo heater");
                        New_Line;
                        --  setOnOffH1(on) (35,33)
                        tmp16 := asn1Sccon;
                        RI_0_setOnOffH1(tmp16);
                        --  heaterison := True (37,33)
                        ctxt.heaterison := true;
                     end if;
                     --  ANSWER else (None,None)
                  else
                     --  DECISION heaterison (-1,-1)
                     --  ANSWER true (44,25)
                     if (ctxt.heaterison) = true then
                        --  writeln('[Thermostat] Disengaging anemo heater') (46,33)
                        Put ("[Thermostat] Disengaging anemo heater");
                        New_Line;
                        --  setOnOffH1(off) (48,33)
                        tmp25 := asn1Sccoff;
                        RI_0_setOnOffH1(tmp25);
                        --  heaterison := False (50,33)
                        ctxt.heaterison := false;
                        --  ANSWER false (52,25)
                     elsif (ctxt.heaterison) = false then
                        null;
                     end if;
                  end if;
                  --  NEXT_STATE Wait (56,22) at 661, 519
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
end Thermostat;