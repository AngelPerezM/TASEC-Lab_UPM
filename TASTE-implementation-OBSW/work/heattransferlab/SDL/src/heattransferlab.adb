-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !

with System.IO;
use System.IO;

with Ada.Unchecked_Conversion;
with Ada.Numerics.Generic_Elementary_Functions;

package body Heattransferlab is
   CS_Only : constant := 18;
   procedure Execute_Transition (Id : Integer);
   procedure p_0_initF1;
   procedure p_0_initF2;
   function p_0_updateData return asn1SccT_Boolean;
   procedure p_0_doF1;
   procedure p_0_doA1;
   procedure p_0_doA2;
   procedure p_0_doF2;
   procedure p_0_doF3;
   procedure p_0_initF1 is
      begin
         --  DECISION f1_started (-1,-1)
         --  ANSWER true (54,17)
         if (ctxt.f1_started) = true then
            null;
            --  ANSWER false (56,17)
         elsif (ctxt.f1_started) = false then
            --  f1_started := true (58,25)
            ctxt.f1_started := true;
            --  f1_duration_max := htl_time + f1_relative_duration_max (59,0)
            ctxt.f1_duration_max := (ctxt.htl_time + ctxt.f1_relative_duration_max);
            --  actual_state := f1 (60,0)
            ctxt.actual_state := asn1Sccf1;
         end if;
         --  RETURN  (None,None) at 455, 353
         return;
      end p_0_initF1;
      

   procedure p_0_initF2 is
      begin
         --  DECISION f2_started (-1,-1)
         --  ANSWER true (72,17)
         if (ctxt.f2_started) = true then
            null;
            --  ANSWER false (74,17)
         elsif (ctxt.f2_started) = false then
            --  f2_started := true (76,25)
            ctxt.f2_started := true;
            --  f2_duration_max := htl_time + f2_relative_duration_max (77,0)
            ctxt.f2_duration_max := (ctxt.htl_time + ctxt.f2_relative_duration_max);
            --  actual_state := f2 (78,0)
            ctxt.actual_state := asn1Sccf2;
         end if;
         --  RETURN  (None,None) at 183, 324
         return;
      end p_0_initF2;
      

   procedure getCurrentMode(Current_State: in out asn1SccHTL_State) is
      begin
         --  writeln('actual status is', actual_state) (93,17)
         Put ("actual status is");
         Put (ctxt.actual_state'Img);
         New_Line;
         --  Current_State := actual_state (95,17)
         Current_State := ctxt.actual_state;
         --  getCurrentMode_Transition (None,None)
         getCurrentMode_Transition;
         --  RETURN  (None,None) at 603, 307
         return;
      end getCurrentMode;
      

   function p_0_updateData return asn1SccT_Boolean is
      pt1000s_data : asn1SccOBSW_DP_SingleData;
      press1_data : asn1SccOBSW_DP_SingleData;
      press2_data : asn1SccOBSW_DP_SingleData;
      power_data : asn1SccOBSW_DP_SingleData;
      gps_time : asn1SccT_Double;
      placa_arriba_ok : asn1SccT_Boolean;
      placa_abajo_ok : asn1SccT_Boolean;
      aire_infinito_ok : asn1SccT_Boolean;
      press1_ok : asn1SccT_Boolean;
      press2_ok : asn1SccT_Boolean;
      power_ok : asn1SccT_Boolean;
      tmp60627 : asn1SccT_Float;
      tmp60514 : asn1SccOBSW_DP_Filter;
      tmp60653 : asn1SccT_Float;
      tmp60522 : asn1SccOBSW_DP_Filter;
      tmp60596 : asn1SccT_Float;
      --  !! stack: _call_external_function line 1604
      tmp60606 : asn1SccT_Float;
      tmp60526 : asn1SccOBSW_DP_Filter;
      tmp60639 : asn1SccT_Float;
      tmp60518 : asn1SccOBSW_DP_Filter;
      tmp60618 : asn1SccT_Float;
      begin
         --  getTime(gps_time, htl_time) (121,17)
         RI_0_getTime(gps_time, ctxt.htl_time);
         --  retreiveSingleData(pt1000s,pt1000s_data) (123,17)
         tmp60514 := asn1Sccpt1000s;
         RI_0_RetreiveSingleData(tmp60514, pt1000s_data);
         --  retreiveSingleData(ps1, press1_data) (125,17)
         tmp60518 := asn1Sccps1;
         RI_0_RetreiveSingleData(tmp60518, press1_data);
         --  retreiveSingleData(ps2, press2_data) (127,17)
         tmp60522 := asn1Sccps2;
         RI_0_RetreiveSingleData(tmp60522, press2_data);
         --  retreiveSingleData(heater2, power_data) (129,17)
         tmp60526 := asn1Sccheater2;
         RI_0_RetreiveSingleData(tmp60526, power_data);
         --  temp_air := 0.0 (131,17)
         ctxt.temp_air := 0.0;
         --  temp_plate := 0.0 (132,0)
         ctxt.temp_plate := 0.0;
         --  press := 0.0 (133,0)
         ctxt.press := 0.0;
         --  placa_abajo_ok := pt1000s_data.pt1000s.data.validity(6) = valid (135,0)
         placa_abajo_ok := (pt1000s_data.pt1000s.data.validity.Data(7) = asn1Sccvalid);
         --  placa_arriba_ok := pt1000s_data.pt1000s.data.validity(5) = valid (136,0)
         placa_arriba_ok := (pt1000s_data.pt1000s.data.validity.Data(6) = asn1Sccvalid);
         --  aire_infinito_ok := pt1000s_data.pt1000s.data.validity(2) = valid (137,0)
         aire_infinito_ok := (pt1000s_data.pt1000s.data.validity.Data(3) = asn1Sccvalid);
         --  press1_ok := press1_data.ps1.data.validity = valid (138,0)
         press1_ok := (press1_data.ps1.data.validity = asn1Sccvalid);
         --  press2_ok := press2_data.ps2.data.validity = valid (139,0)
         press2_ok := (press2_data.ps2.data.validity = asn1Sccvalid);
         --  power_ok := power_data.heater2.data.validity = valid (140,0)
         power_ok := (power_data.heater2.data.validity = asn1Sccvalid);
         --  DECISION power_ok and
         --  (placa_abajo_ok or placa_arriba_ok)
         --  and aire_infinito_ok
         --  and (press1_ok or press2_ok) (145,0)
         --  ANSWER true (147,17)
         if ((((power_ok and (placa_abajo_ok or placa_arriba_ok)) and aire_infinito_ok) and (press1_ok or press2_ok))) = true then
            --  temp_plate := if placa_arriba_ok then (pt1000s_data.pt1000s.data.celsius(5)) else 0.0 fi (149,25)
            if placa_arriba_ok then
               tmp60596 := pt1000s_data.pt1000s.data.celsius.Data(6);
            else
               tmp60596 := 0.0;
            end if;
            ctxt.temp_plate := tmp60596;
            --  temp_plate := if placa_abajo_ok then (pt1000s_data.pt1000s.data.celsius(6) + temp_plate) else temp_plate fi (150,0)
            if placa_abajo_ok then
               tmp60606 := (pt1000s_data.pt1000s.data.celsius.Data(7) + ctxt.temp_plate);
            else
               tmp60606 := ctxt.temp_plate;
            end if;
            ctxt.temp_plate := tmp60606;
            --  temp_plate := if placa_abajo_ok and placa_arriba_ok then temp_plate / 2.0 else temp_plate fi (151,0)
            if (placa_abajo_ok and placa_arriba_ok) then
               tmp60618 := (ctxt.temp_plate / 2.0);
            else
               tmp60618 := ctxt.temp_plate;
            end if;
            ctxt.temp_plate := tmp60618;
            --  press := if press1_ok then float(press1_data.ps1.data.processed.pressure) /100.0 else 0.0 fi (153,0)
            if press1_ok then
               tmp60627 := (Asn1Real(press1_data.ps1.data.processed.pressure) / 100.0);
            else
               tmp60627 := 0.0;
            end if;
            ctxt.press := tmp60627;
            --  press := if press2_ok then (float(press2_data.ps2.data.processed.pressure)/100.0 + press) else press fi (154,0)
            if press2_ok then
               tmp60639 := ((Asn1Real(press2_data.ps2.data.processed.pressure) / 100.0) + ctxt.press);
            else
               tmp60639 := ctxt.press;
            end if;
            ctxt.press := tmp60639;
            --  press := if press1_ok and press2_ok then press / 2.0 else press fi (155,0)
            if (press1_ok and press2_ok) then
               tmp60653 := (ctxt.press / 2.0);
            else
               tmp60653 := ctxt.press;
            end if;
            ctxt.press := tmp60653;
            --  temp_air := pt1000s_data.pt1000s.data.celsius(2) (157,0)
            ctxt.temp_air := pt1000s_data.pt1000s.data.celsius.Data(3);
            --  power := power_data.heater2.data.power_watts (159,0)
            ctxt.power := power_data.heater2.data.power_watts;
            --  writeln('temp_plate: ', temp_plate) (161,25)
            Put ("temp_plate: ");
            Put (asn1SccT_Float'Image (ctxt.temp_plate));
            New_Line;
            --  writeln('power: ', power) (163,25)
            Put ("power: ");
            Put (asn1SccT_Float'Image (ctxt.power));
            New_Line;
            --  writeln('press: ', press) (165,25)
            Put ("press: ");
            Put (asn1SccT_Float'Image (ctxt.press));
            New_Line;
            --  writeln('press 2 ok ', press2_ok) (167,25)
            Put ("press 2 ok ");
            Put (asn1SccT_Boolean'Image (press2_ok));
            New_Line;
            --  writeln('temp_air: ', temp_air) (169,25)
            Put ("temp_air: ");
            Put (asn1SccT_Float'Image (ctxt.temp_air));
            New_Line;
            --  RETURN True (None,None) at 407, 1318
            return true;
            --  ANSWER false (173,17)
         elsif ((((power_ok and (placa_abajo_ok or placa_arriba_ok)) and aire_infinito_ok) and (press1_ok or press2_ok))) = false then
            --  writeln('invalid data :-(') (175,25)
            Put ("invalid data :-(");
            New_Line;
            --  RETURN False (None,None) at 1223, 888
            return false;
         end if;
      end p_0_updateData;
      

   procedure configureParameters(Configuration: in out asn1SccHTL_Config) is
      tmp60749 : asn1SccT_Double;
      tmp60715 : asn1SccT_Float;
      tmp60699 : asn1SccT_Float;
      tmp60732 : asn1SccT_Double;
      tmp60741 : asn1SccT_Double;
      tmp60757 : asn1SccT_Double;
      tmp60723 : asn1SccT_Double;
      tmp60707 : asn1SccT_Float;
      begin
         --  press_5km  := if exist (Configuration.press_5km) then Configuration.press_5km else press_5km fi (191,17)
         if (Configuration.exist.press_5km = 1) then
            tmp60699 := Configuration.press_5km;
         else
            tmp60699 := ctxt.press_5km;
         end if;
         ctxt.press_5km := tmp60699;
         --  press_10km := if exist(Configuration.press_10km) then Configuration.press_10km else press_10km fi (192,0)
         if (Configuration.exist.press_10km = 1) then
            tmp60707 := Configuration.press_10km;
         else
            tmp60707 := ctxt.press_10km;
         end if;
         ctxt.press_10km := tmp60707;
         --  press_18km := if exist(Configuration.press_18km) then Configuration.press_18km else press_18km fi (193,0)
         if (Configuration.exist.press_18km = 1) then
            tmp60715 := Configuration.press_18km;
         else
            tmp60715 := ctxt.press_18km;
         end if;
         ctxt.press_18km := tmp60715;
         --  f1_relative_duration_max :=
         --   if exist(Configuration.f1_duration_secs) then
            --     float (Configuration.f1_duration_secs)
            --  else
            --    f1_relative_duration_max
            --  fi (195,0)
            if (Configuration.exist.f1_duration_secs = 1) then
               tmp60723 := Asn1Real(Configuration.f1_duration_secs);
            else
               tmp60723 := ctxt.f1_relative_duration_max;
            end if;
            ctxt.f1_relative_duration_max := tmp60723;
            --  f2_relative_duration_max :=
            --  if exist(Configuration.f2_duration_secs) then
               --    float(Configuration.f2_duration_secs)
               --  else
               --    f2_relative_duration_max
               --  fi (202,0)
               if (Configuration.exist.f2_duration_secs = 1) then
                  tmp60732 := Asn1Real(Configuration.f2_duration_secs);
               else
                  tmp60732 := ctxt.f2_relative_duration_max;
               end if;
               ctxt.f2_relative_duration_max := tmp60732;
               --  a1_duration_emergency :=
               --  if exist(Configuration.a1_duration_emergency_secs) then
                  --    Configuration.a1_duration_emergency_secs
                  --  else
                  --    a1_duration_emergency
                  --  fi (209,0)
                  if (Configuration.exist.a1_duration_emergency_secs = 1) then
                     tmp60741 := Configuration.a1_duration_emergency_secs;
                  else
                     tmp60741 := ctxt.a1_duration_emergency;
                  end if;
                  ctxt.a1_duration_emergency := tmp60741;
                  --  a1_duration_max :=
                  --  if exist(Configuration.a1_duration_max_secs) then
                     --    Configuration.a1_duration_max_secs
                     --  else
                     --    a1_duration_max
                     --  fi (216,0)
                     if (Configuration.exist.a1_duration_max_secs = 1) then
                        tmp60749 := Configuration.a1_duration_max_secs;
                     else
                        tmp60749 := ctxt.a1_duration_max;
                     end if;
                     ctxt.a1_duration_max := tmp60749;
                     --  a2_duration_max :=
                     --  if exist(Configuration.a2_duration_max_secs) then
                        --    Configuration.a2_duration_max_secs
                        --  else
                        --    a2_duration_max
                        --  fi (223,0)
                        if (Configuration.exist.a2_duration_max_secs = 1) then
                           tmp60757 := Configuration.a2_duration_max_secs;
                        else
                           tmp60757 := ctxt.a2_duration_max;
                        end if;
                        ctxt.a2_duration_max := tmp60757;
                        --  configureParameters_Transition (None,None)
                        configureParameters_Transition;
                        --  RETURN  (None,None) at 931, 777
                        return;
                     end configureParameters;
                     

                  procedure p_0_doF1 is
                     begin
                        --  DECISION power = 0.0 (237,27)
                        --  ANSWER true (239,17)
                        if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
                           --  DECISION temp_plate <= 55.0 and
                           --  abs(temp_plate - temp_air) <= 50.0 (241,48)
                           --  ANSWER true (244,25)
                           if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
                              --  n := n+1.0 (246,33)
                              ctxt.n := (ctxt.n + 1.0);
                              --  JOIN normalF1 (248,33) at 599, 454
                              goto normalF1;
                              --  ANSWER false (250,25)
                           elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
                              --  RETURN  (None,None) at 706, 404
                              return;
                           end if;
                           --  ANSWER false (255,17)
                        elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
                           --  JOIN normalF1 (None,None) at None, None
                           goto normalF1;
                        end if;
                        --  CONNECTION normalF1 (257,20)
                        <<normalF1>>
                        --  DECISION temp_plate >= 65.0 or
                        --  abs(temp_plate - temp_air) >= 60.0 (259,48)
                        --  COMMENT ¿>= 60? (262,20)
                        --  ANSWER true (264,25)
                        if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
                           --  power := 0.0 (266,33)
                           ctxt.power := 0.0;
                           --  ANSWER false (268,25)
                        elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
                           --  power := power_a2-n*0.1 (270,33)
                           ctxt.power := (ctxt.power_a2 - (ctxt.n * 0.1));
                           --  DECISION power <= 0.1 (272,43)
                           --  ANSWER true (274,33)
                           if ((ctxt.power <= 0.1)) = true then
                              --  power := 0.1 (276,41)
                              ctxt.power := 0.1;
                              --  ANSWER false (278,33)
                           elsif ((ctxt.power <= 0.1)) = false then
                              null;
                           end if;
                           --  power_f1 := power (281,33)
                           ctxt.power_f1 := ctxt.power;
                        end if;
                        --  setPowerH2(power) (284,25)
                        RI_0_setPowerH2(ctxt.power);
                        --  RETURN  (None,None) at 306, 742
                        return;
                     end p_0_doF1;
                     

                  procedure p_0_doA1 is
                     begin
                        --  DECISION power = 0.0 (294,27)
                        --  ANSWER false (296,17)
                        if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
                           null;
                           --  ANSWER true (298,17)
                        elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
                           --  DECISION temp_plate <= 55.0 and abs(temp_plate -temp_air) <= 50.0 (300,48)
                           --  ANSWER true (302,25)
                           if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
                              null;
                              --  ANSWER false (304,25)
                           elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
                              --  RETURN  (None,None) at 983, 318
                              return;
                           end if;
                        end if;
                        --  DECISION temp_plate >= 65.0 or abs(temp_plate - temp_air) >= 60.0 (310,40)
                        --  ANSWER true (312,17)
                        if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
                           --  power := 0.0 (314,25)
                           ctxt.power := 0.0;
                           --  ANSWER false (316,17)
                        elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
                           --  power := 0.8 (318,25)
                           ctxt.power := 0.8;
                        end if;
                        --  setPowerH2(power) (321,17)
                        RI_0_setPowerH2(ctxt.power);
                        --  RETURN  (None,None) at 518, 657
                        return;
                     end p_0_doA1;
                     

                  procedure p_0_doA2 is
                     begin
                        --  DECISION power = 0.0 (330,27)
                        --  ANSWER false (332,17)
                        if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
                           --  JOIN normalA2 (None,None) at None, None
                           goto normalA2;
                           --  ANSWER true (354,17)
                        elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
                           --  DECISION temp_plate <= 55.0 and
                           --  abs(temp_plate - temp_air) <= 50.0 (356,48)
                           --  COMMENT Pdiss = 0.0 W (359,20)
                           --  ANSWER true (361,25)
                           if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
                              --  JOIN normalA2 (363,33) at 757, 344
                              goto normalA2;
                              --  ANSWER false (365,25)
                           elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
                              --  RETURN  (None,None) at 861, 346
                              return;
                           end if;
                        end if;
                        --  setPowerH2(power) (371,17)
                        RI_0_setPowerH2(ctxt.power);
                        --  RETURN  (None,None) at 435, 612
                        return;
                        --  CONNECTION normalA2 (334,20)
                        <<normalA2>>
                        --  DECISION temp_plate >= 65.0 or
                        --  abs(temp_plate - temp_air) >= 60.0 (336,48)
                        --  COMMENT Pdiss = 1.0 (339,20)
                        --  ANSWER false (341,25)
                        if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
                           --  power := 0.6 (343,33)
                           ctxt.power := 0.6;
                           --  power_a2 := power (345,33)
                           ctxt.power_a2 := ctxt.power;
                           --  ANSWER true (347,25)
                        elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
                           --  power := 0.0 (349,33)
                           ctxt.power := 0.0;
                        end if;
                        --  writeln('normalA2') (352,25)
                        Put ("normalA2");
                        New_Line;
                        --  setPowerH2(power) (371,17)
                        RI_0_setPowerH2(ctxt.power);
                        --  RETURN  (None,None) at 435, 612
                        return;
                     end p_0_doA2;
                     

                  procedure p_0_doF2 is
                     begin
                        --  DECISION power = 0.0 (380,27)
                        --  ANSWER false (382,17)
                        if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
                           null;
                           --  ANSWER true (384,17)
                        elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
                           --  DECISION temp_plate <= 55.0 and
                           --  abs(temp_plate - temp_air) <= 50.0 (386,48)
                           --  ANSWER true (389,25)
                           if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
                              --  m := m+0.1 (391,33)
                              ctxt.m := (ctxt.m + 0.1);
                              --  ANSWER false (393,25)
                           elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
                              --  RETURN  (None,None) at 601, 362
                              return;
                           end if;
                        end if;
                        --  DECISION temp_plate >= 65.0 or 
                        --  abs (temp_plate - temp_air) >= 60.0 (399,40)
                        --  COMMENT >= 60? (402,12)
                        --  ANSWER true (404,17)
                        if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
                           --  power := 0.0 (406,25)
                           ctxt.power := 0.0;
                           --  ANSWER false (408,17)
                        elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
                           --  power := power_f1/2.0 - m*0.1 (410,25)
                           ctxt.power := ((ctxt.power_f1 / 2.0) - (ctxt.m * 0.1));
                           --  DECISION power <= 0.1 (412,35)
                           --  ANSWER true (414,25)
                           if ((ctxt.power <= 0.1)) = true then
                              --  power := 0.1 (416,33)
                              ctxt.power := 0.1;
                              --  ANSWER false (418,25)
                           elsif ((ctxt.power <= 0.1)) = false then
                              null;
                           end if;
                        end if;
                        --  setPowerH2(power) (422,17)
                        RI_0_setPowerH2(ctxt.power);
                        --  RETURN  (None,None) at 439, 851
                        return;
                     end p_0_doF2;
                     

                  procedure p_0_doF3 is
                     tmp60973 : asn1SccT_Float;
                     --  !! stack: _call_external_function line 1604
                     begin
                        --  DECISION system_stopped (-1,-1)
                        --  ANSWER true (433,17)
                        if (ctxt.system_stopped) = true then
                           --  RETURN  (None,None) at 309, 238
                           return;
                           --  ANSWER false (437,17)
                        elsif (ctxt.system_stopped) = false then
                           null;
                        end if;
                        --  ok := call updateData (440,17)
                        ctxt.ok := p_0_updatedata;
                        --  DECISION ok and power = 0.0 (442,24)
                        --  ANSWER true (444,17)
                        if ((ctxt.ok and asn1SccT_Float_Equal (ctxt.power, 0.0))) = true then
                           --  system_stopped := true (446,25)
                           ctxt.system_stopped := true;
                           --  stopSystem (448,25)
                           RI_0_StopSystem;
                           --  ANSWER false (450,17)
                        elsif ((ctxt.ok and asn1SccT_Float_Equal (ctxt.power, 0.0))) = false then
                           --  setPowerH2(0.0) (452,25)
                           tmp60973 := 0.0;
                           RI_0_setPowerH2(tmp60973);
                        end if;
                        --  RETURN  (None,None) at 354, 596
                        return;
                     end p_0_doF3;
                     

                  procedure setCurrentMode(current_state: in out asn1SccHTL_State) is
                     begin
                        case ctxt.state is
                           when asn1Sccf2 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (4);
                           when asn1Scca1 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (17);
                           when asn1Sccf3 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (7);
                           when asn1Sccf1 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (2);
                           when asn1Scca2 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (15);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end setCurrentMode;
                     

                  procedure tick is
                     begin
                        case ctxt.state is
                           when asn1Sccf2 =>
                              Execute_Transition (3);
                           when asn1Scca1 =>
                              Execute_Transition (16);
                           when asn1Sccf3 =>
                              Execute_Transition (6);
                           when asn1Sccf1 =>
                              Execute_Transition (1);
                           when asn1Scca2 =>
                              Execute_Transition (14);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccerror =>
                              Execute_Transition (5);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end tick;
                     

                  procedure configureParameters_Transition is
                     begin
                        case ctxt.state is
                           when asn1Sccf2 =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf3 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
                              Execute_Transition (CS_Only);
                           when asn1Scca2 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end configureParameters_Transition;
                     

                  procedure getCurrentMode_Transition is
                     begin
                        case ctxt.state is
                           when asn1Sccf2 =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf3 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
                              Execute_Transition (CS_Only);
                           when asn1Scca2 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end getCurrentMode_Transition;
                     

                  procedure Execute_Transition (Id : Integer) is
                     trId : Integer := Id;
                     msgPending : Asn1Boolean := True;
                     begin
                        while (trId /= -1) loop
                           case trId is
                              when 0 =>
                                 --  NEXT_STATE A1 (460,18) at 512, 127
                                 trId := -1;
                                 ctxt.State := asn1SccA1;
                                 goto Next_Transition;
                              when 1 =>
                                 --  initf1 (466,17)
                                 p_0_initF1;
                                 --  ok := call updateData (468,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (472,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (474,35)
                                    --  ANSWER True (476,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  NEXT_STATE F3 (478,38) at 2625, 533
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (480,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       --  DECISION htl_time >= f1_duration_max (482,46)
                                       --  ANSWER true (484,33)
                                       if ((ctxt.htl_time >= ctxt.f1_duration_max)) = true then
                                          --  NEXT_STATE F2 (486,46) at 2330, 680
                                          trId := -1;
                                          ctxt.State := asn1SccF2;
                                          goto Next_Transition;
                                          --  ANSWER false (488,33)
                                       elsif ((ctxt.htl_time >= ctxt.f1_duration_max)) = false then
                                          --  doF1 (490,41)
                                          p_0_doF1;
                                          --  NEXT_STATE F1 (492,46) at 2420, 735
                                          trId := -1;
                                          ctxt.State := asn1SccF1;
                                          goto Next_Transition;
                                       end if;
                                    end if;
                                    --  ANSWER false (496,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (498,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (500,30) at 2150, 457
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 2 =>
                                 --  NEXT_STATE Selectstate (505,22) at 2762, 192
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 3 =>
                                 --  initf2 (512,17)
                                 p_0_initF2;
                                 --  ok := call updateData (514,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (518,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (520,35)
                                    --  ANSWER True (522,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  NEXT_STATE F3 (524,38) at 1730, 1379
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (526,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       --  DECISION htl_time >= f2_duration_max (528,46)
                                       --  ANSWER true (530,33)
                                       if ((ctxt.htl_time >= ctxt.f2_duration_max)) = true then
                                          --  NEXT_STATE F3 (532,46) at 1446, 1515
                                          --  COMMENT time in F3 is bigger
                                          --  than the allowed. (534,36)
                                          trId := -1;
                                          ctxt.State := asn1SccF3;
                                          goto Next_Transition;
                                          --  ANSWER false (537,33)
                                       elsif ((ctxt.htl_time >= ctxt.f2_duration_max)) = false then
                                          --  doF2 (539,41)
                                          p_0_doF2;
                                          --  NEXT_STATE F2 (541,46) at 1556, 1567
                                          trId := -1;
                                          ctxt.State := asn1SccF2;
                                          goto Next_Transition;
                                       end if;
                                    end if;
                                    --  ANSWER false (545,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state:=actual_state (547,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (549,30) at 1192, 1320
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 4 =>
                                 --  NEXT_STATE Selectstate (554,22) at 1877, 1057
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 5 =>
                                 --  ok := call updateData (561,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  actual_state := error (562,0)
                                 ctxt.actual_state := asn1Sccerror;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (566,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION last_good_state (-1,-1)
                                    --  ANSWER a1 (570,25)
                                    if (ctxt.last_good_state) = asn1Scca1 then
                                       --  NEXT_STATE A1 (572,38) at 2265, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccA1;
                                       goto Next_Transition;
                                       --  ANSWER a2 (574,25)
                                    elsif (ctxt.last_good_state) = asn1Scca2 then
                                       --  NEXT_STATE A2 (576,38) at 2355, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccA2;
                                       goto Next_Transition;
                                       --  ANSWER f1 (578,25)
                                    elsif (ctxt.last_good_state) = asn1Sccf1 then
                                       --  NEXT_STATE F1 (580,38) at 2445, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccF1;
                                       goto Next_Transition;
                                       --  ANSWER f2 (582,25)
                                    elsif (ctxt.last_good_state) = asn1Sccf2 then
                                       --  NEXT_STATE F2 (584,38) at 2535, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccF2;
                                       goto Next_Transition;
                                       --  ANSWER else (None,None)
                                    else
                                       --  NEXT_STATE Error (588,38) at 2625, 1362
                                       trId := -1;
                                       ctxt.State := asn1SccError;
                                       goto Next_Transition;
                                    end if;
                                    --  ANSWER false (591,17)
                                 elsif (ctxt.ok) = false then
                                    --  NEXT_STATE Error (593,30) at 2706, 1243
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 6 =>
                                 --  actual_state := f3 (601,17)
                                 ctxt.actual_state := asn1Sccf3;
                                 --  doF3 (603,17)
                                 p_0_doF3;
                                 --  NEXT_STATE F3 (605,22) at 2127, 1173
                                 trId := -1;
                                 ctxt.State := asn1SccF3;
                                 goto Next_Transition;
                              when 7 =>
                                 --  NEXT_STATE Selectstate (609,22) at 2290, 1063
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 8 =>
                                 --  NEXT_STATE F2 (616,22) at 990, 1065
                                 trId := -1;
                                 ctxt.State := asn1SccF2;
                                 goto Next_Transition;
                              when 9 =>
                                 --  NEXT_STATE A1 (620,22) at 721, 1060
                                 trId := -1;
                                 ctxt.State := asn1SccA1;
                                 goto Next_Transition;
                              when 10 =>
                                 --  NEXT_STATE A2 (624,22) at 452, 1060
                                 trId := -1;
                                 ctxt.State := asn1SccA2;
                                 goto Next_Transition;
                              when 11 =>
                                 --  NEXT_STATE F1 (628,22) at 587, 1065
                                 trId := -1;
                                 ctxt.State := asn1SccF1;
                                 goto Next_Transition;
                              when 12 =>
                                 --  NEXT_STATE F3 (632,22) at 859, 1063
                                 trId := -1;
                                 ctxt.State := asn1SccF3;
                                 goto Next_Transition;
                              when 13 =>
                                 --  NEXT_STATE Error (636,22) at 1131, 1065
                                 trId := -1;
                                 ctxt.State := asn1SccError;
                                 goto Next_Transition;
                              when 14 =>
                                 --  actual_state := a2 (643,17)
                                 ctxt.actual_state := asn1Scca2;
                                 --  ok := call updateData (644,0)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (648,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (650,35)
                                    --  COMMENT no estamos cayendo? (652,20)
                                    --  ANSWER True (654,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  writeln('Nos estamos cayendo') (656,33)
                                       Put ("Nos estamos cayendo");
                                       New_Line;
                                       --  NEXT_STATE F3 (658,38) at 1331, 531
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (660,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       null;
                                    end if;
                                    --  ANSWER false (663,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (665,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (667,30) at 1560, 401
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                                 --  DECISION htl_time >= a2_duration_max
                                 --  or press <= press_18km (671,0)
                                 --  ANSWER false (673,17)
                                 if (((ctxt.htl_time >= ctxt.a2_duration_max) or (ctxt.press <= ctxt.press_18km))) = false then
                                    --  doA2 (675,25)
                                    p_0_doA2;
                                    --  NEXT_STATE A2 (677,30) at 1075, 790
                                    trId := -1;
                                    ctxt.State := asn1SccA2;
                                    goto Next_Transition;
                                    --  ANSWER true (679,17)
                                 elsif (((ctxt.htl_time >= ctxt.a2_duration_max) or (ctxt.press <= ctxt.press_18km))) = true then
                                    --  writeln('A2 max duration: ', a2_duration_max) (681,25)
                                    Put ("A2 max duration: ");
                                    Put (asn1SccT_Double'Image (ctxt.a2_duration_max));
                                    New_Line;
                                    --  NEXT_STATE F1 (683,30) at 1267, 795
                                    trId := -1;
                                    ctxt.State := asn1SccF1;
                                    goto Next_Transition;
                                 end if;
                              when 15 =>
                                 --  NEXT_STATE Selectstate (688,22) at 1777, 182
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 16 =>
                                 --  actual_state := a1 (695,17)
                                 ctxt.actual_state := asn1Scca1;
                                 --  ok := call updateData (696,0)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (700,17)
                                 if (ctxt.ok) = true then
                                    null;
                                    --  ANSWER false (702,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (704,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (706,30) at 518, 410
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                                 --  DECISION (press <= press_10km and
                                 --  htl_time >= a1_duration_emergency) or
                                 --  htl_time >= a1_duration_max (710,35)
                                 --  ANSWER false (713,17)
                                 if ((((ctxt.press <= ctxt.press_10km) and (ctxt.htl_time >= ctxt.a1_duration_emergency)) or (ctxt.htl_time >= ctxt.a1_duration_max))) = false then
                                    --  doA1 (715,25)
                                    p_0_doA1;
                                    --  NEXT_STATE A1 (717,30) at 594, 687
                                    trId := -1;
                                    ctxt.State := asn1SccA1;
                                    goto Next_Transition;
                                    --  ANSWER true (719,17)
                                 elsif ((((ctxt.press <= ctxt.press_10km) and (ctxt.htl_time >= ctxt.a1_duration_emergency)) or (ctxt.htl_time >= ctxt.a1_duration_max))) = true then
                                    --  NEXT_STATE A2 (721,30) at 684, 637
                                    trId := -1;
                                    ctxt.State := asn1SccA2;
                                    goto Next_Transition;
                                 end if;
                              when 17 =>
                                 --  NEXT_STATE Selectstate (726,22) at 953, 186
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when CS_Only =>
                                 trId := -1;
                                 goto Next_Transition;
                              when others =>
                                 null;
                           end case;
                           <<Next_Transition>>
                           --  Process continuous signals
                           if ctxt.Init_Done then
                              Check_Queue (msgPending);
                           end if;
                           if not msgPending and trId = -1 and ctxt.State = asn1Sccselectstate then
                              --  Priority 1
                              --  DECISION actual_state = f2 (614,30)
                              --  ANSWER true (None,None)
                              if ((ctxt.actual_state = asn1Sccf2)) = true then
                                 trId := 8;
                                 --  Priority 1
                                 --  DECISION actual_state = a1 (618,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Scca1)) = true then
                                 trId := 9;
                                 --  Priority 1
                                 --  DECISION actual_state = a2 (622,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Scca2)) = true then
                                 trId := 10;
                                 --  Priority 1
                                 --  DECISION actual_state = f1 (626,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccf1)) = true then
                                 trId := 11;
                                 --  Priority 1
                                 --  DECISION actual_state = f3 (630,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccf3)) = true then
                                 trId := 12;
                                 --  Priority 1
                                 --  DECISION actual_state = error (634,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccerror)) = true then
                                 trId := 13;
                              end if;
                           end if;
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