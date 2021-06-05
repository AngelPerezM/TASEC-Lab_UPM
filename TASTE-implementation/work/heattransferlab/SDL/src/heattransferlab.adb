-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !

with System.IO;
use System.IO;

with Ada.Unchecked_Conversion;
with Ada.Numerics.Generic_Elementary_Functions;

package body Heattransferlab is
   CS_Only : constant := 8;
   procedure Execute_Transition (Id : Integer);
   procedure tick is
      begin
         case ctxt.state is
            when asn1Sccf1 =>
               Execute_Transition (5);
            when asn1Scca1 =>
               Execute_Transition (4);
            when asn1Scca2 =>
               Execute_Transition (7);
            when asn1Sccf3 =>
               Execute_Transition (1);
            when asn1Sccf2 =>
               Execute_Transition (2);
            when others =>
               Execute_Transition (CS_Only);
         end case;
      end tick;
      

   procedure f1_max_time is
      begin
         case ctxt.state is
            when asn1Sccf1 =>
               Execute_Transition (6);
            when asn1Scca1 =>
               Execute_Transition (CS_Only);
            when asn1Scca2 =>
               Execute_Transition (CS_Only);
            when asn1Sccf3 =>
               Execute_Transition (CS_Only);
            when asn1Sccf2 =>
               Execute_Transition (CS_Only);
            when others =>
               Execute_Transition (CS_Only);
         end case;
      end f1_max_time;
      

   procedure f2_max_time is
      begin
         case ctxt.state is
            when asn1Sccf1 =>
               Execute_Transition (CS_Only);
            when asn1Scca1 =>
               Execute_Transition (CS_Only);
            when asn1Scca2 =>
               Execute_Transition (CS_Only);
            when asn1Sccf3 =>
               Execute_Transition (CS_Only);
            when asn1Sccf2 =>
               Execute_Transition (3);
            when others =>
               Execute_Transition (CS_Only);
         end case;
      end f2_max_time;
      

   procedure Execute_Transition (Id : Integer) is
      trId : Integer := Id;
      begin
         while (trId /= -1) loop
            case trId is
               when 0 =>
                  --  NEXT_STATE A1 (16,18) at 132, 120
                  trId := -1;
                  ctxt.State := asn1SccA1;
                  goto Next_Transition;
               when 1 =>
                  --  NEXT_STATE F3 (24,22) at 940, 576
                  trId := -1;
                  ctxt.State := asn1SccF3;
                  goto Next_Transition;
               when 2 =>
                  -- F2 job
                  --  NEXT_STATE F2 (33,22) at 553, 631
                  trId := -1;
                  ctxt.State := asn1SccF2;
                  goto Next_Transition;
               when 3 =>
                  -- Power 0
                  --  NEXT_STATE F3 (39,22) at 682, 631
                  trId := -1;
                  ctxt.State := asn1SccF3;
                  goto Next_Transition;
               when 4 =>
                  -- A1 Job
                  --  DECISION press <= press_10km and mission_time >= 1800.0 (48,41)
                  --  ANSWER false (50,17)
                  if (((ctxt.press <= ctxt.press_10km) and (ctxt.mission_time >= 1800.0))) = false then
                     --  NEXT_STATE A1 (52,30) at 364, 381
                     trId := -1;
                     ctxt.State := asn1SccA1;
                     goto Next_Transition;
                     --  ANSWER true (54,17)
                  elsif (((ctxt.press <= ctxt.press_10km) and (ctxt.mission_time >= 1800.0))) = true then
                     --  NEXT_STATE A2 (56,30) at 454, 381
                     trId := -1;
                     ctxt.State := asn1SccA2;
                     goto Next_Transition;
                  end if;
               when 5 =>
                  -- F1 job
                  --  NEXT_STATE F1 (66,22) at 83, 622
                  trId := -1;
                  ctxt.State := asn1SccF1;
                  goto Next_Transition;
               when 6 =>
                  --  NEXT_STATE F2 (70,22) at 265, 572
                  trId := -1;
                  ctxt.State := asn1SccF2;
                  goto Next_Transition;
               when 7 =>
                  -- A2 job
                  --  DECISION mission_time >= 4800.0 or press <= press_18km (79,44)
                  --  ANSWER false (81,17)
                  if (((ctxt.mission_time >= 4800.0) or (ctxt.press <= ctxt.press_18km))) = false then
                     --  NEXT_STATE A2 (83,30) at 633, 366
                     trId := -1;
                     ctxt.State := asn1SccA2;
                     goto Next_Transition;
                     --  ANSWER true (85,17)
                  elsif (((ctxt.mission_time >= 4800.0) or (ctxt.press <= ctxt.press_18km))) = true then
                     --  NEXT_STATE F1 (87,30) at 802, 369
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