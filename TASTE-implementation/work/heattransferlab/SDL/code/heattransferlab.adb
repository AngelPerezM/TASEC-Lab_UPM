-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !

with System.IO;
use System.IO;

with Ada.Unchecked_Conversion;
with Ada.Numerics.Generic_Elementary_Functions;

package body Heattransferlab is
   CS_Only : constant := 6;
   procedure Execute_Transition (Id : Integer);
   procedure tick is
      begin
         case ctxt.state is
            when asn1Scca2 =>
               Execute_Transition (5);
            when asn1Sccf2 =>
               Execute_Transition (3);
            when asn1Sccf1 =>
               Execute_Transition (2);
            when asn1Scca1 =>
               Execute_Transition (4);
            when asn1Sccf3 =>
               Execute_Transition (1);
            when others =>
               Execute_Transition (CS_Only);
         end case;
      end tick;
      

   procedure Execute_Transition (Id : Integer) is
      trId : Integer := Id;
      begin
         while (trId /= -1) loop
            case trId is
               when 0 =>
                  --  NEXT_STATE A1 (14,18) at 132, 120
                  trId := -1;
                  ctxt.State := asn1SccA1;
                  goto Next_Transition;
               when 1 =>
                  --  NEXT_STATE F3 (22,22) at 940, 576
                  trId := -1;
                  ctxt.State := asn1SccF3;
                  goto Next_Transition;
               when 2 =>
                  -- F1 job
                  --  NEXT_STATE F1 (31,22) at 83, 622
                  trId := -1;
                  ctxt.State := asn1SccF1;
                  goto Next_Transition;
               when 3 =>
                  -- F2 job
                  --  NEXT_STATE F2 (40,22) at 553, 631
                  trId := -1;
                  ctxt.State := asn1SccF2;
                  goto Next_Transition;
               when 4 =>
                  -- A1 Job
                  --  DECISION press <= press_10km and mission_time >= 1800.0 (49,41)
                  --  ANSWER false (51,17)
                  if (((ctxt.press <= ctxt.press_10km) and (ctxt.mission_time >= 1800.0))) = false then
                     --  NEXT_STATE A1 (53,30) at 364, 381
                     trId := -1;
                     ctxt.State := asn1SccA1;
                     goto Next_Transition;
                     --  ANSWER true (55,17)
                  elsif (((ctxt.press <= ctxt.press_10km) and (ctxt.mission_time >= 1800.0))) = true then
                     --  NEXT_STATE A2 (57,30) at 454, 381
                     trId := -1;
                     ctxt.State := asn1SccA2;
                     goto Next_Transition;
                  end if;
               when 5 =>
                  -- A2 job
                  --  DECISION mission_time >= 4800.0 or press <= press_18km (67,44)
                  --  ANSWER false (69,17)
                  if (((ctxt.mission_time >= 4800.0) or (ctxt.press <= ctxt.press_18km))) = false then
                     --  NEXT_STATE A2 (71,30) at 633, 366
                     trId := -1;
                     ctxt.State := asn1SccA2;
                     goto Next_Transition;
                     --  ANSWER true (73,17)
                  elsif (((ctxt.mission_time >= 4800.0) or (ctxt.press <= ctxt.press_18km))) = true then
                     --  NEXT_STATE F1 (75,30) at 802, 369
                     trId := -1;
                     ctxt.State := asn1SccF1;
                     goto Next_Transition;
                  end if;
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
end Heattransferlab;