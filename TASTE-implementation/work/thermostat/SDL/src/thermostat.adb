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
      tmp230 : asn1SccHeater_On_Off;
      --  !! stack: _call_external_function line 1601
      tmp223 : asn1SccHeater_On_Off;
      begin
         while (trId /= -1) loop
            case trId is
               when 0 =>
                  --  tempcelsius := 0.0 (12,13)
                  ctxt.tempcelsius := 0.0;
                  --  heaterison := False (13,0)
                  ctxt.heaterison := false;
                  --  NEXT_STATE Wait (15,18) at 124, 123
                  trId := -1;
                  ctxt.State := asn1SccWait;
                  goto Next_Transition;
               when 1 =>
                  --  DECISION tempcelsius (-1,-1)
                  --  ANSWER < 29.0 (23,17)
                  if (ctxt.tempcelsius) < 29.0 then
                     --  DECISION heaterison (-1,-1)
                     --  ANSWER true (27,25)
                     if (ctxt.heaterison) = true then
                        null;
                        --  ANSWER false (29,25)
                     elsif (ctxt.heaterison) = false then
                        --  setOnOffH2(on) (31,33)
                        tmp223 := asn1Sccon;
                        RI_0_setOnOffH2(tmp223);
                        --  heaterison := True (33,33)
                        ctxt.heaterison := true;
                     end if;
                     --  ANSWER else (None,None)
                  else
                     --  DECISION heaterison (-1,-1)
                     --  ANSWER true (40,25)
                     if (ctxt.heaterison) = true then
                        --  setOnOffH2(off) (42,33)
                        tmp230 := asn1Sccoff;
                        RI_0_setOnOffH2(tmp230);
                        --  heaterison := False (44,33)
                        ctxt.heaterison := false;
                        --  ANSWER false (46,25)
                     elsif (ctxt.heaterison) = false then
                        null;
                     end if;
                  end if;
                  --  NEXT_STATE Wait (50,22) at 662, 464
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