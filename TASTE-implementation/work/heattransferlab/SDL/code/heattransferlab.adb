-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !

with System.IO;
use System.IO;

with Ada.Unchecked_Conversion;
with Ada.Numerics.Generic_Elementary_Functions;

package body Heattransferlab is
   CS_Only : constant := 18;
   procedure Execute_Transition (Id : Integer);
   procedure p_0_doF3;
   procedure p_0_doF2;
   procedure p_0_doA2;
   procedure p_0_doA1;
   procedure p_0_doF1;
   function p_0_updateData return asn1SccT_Boolean;
   procedure p_0_doF3 is
      --  !! stack: _call_external_function line 1604
      tmp163 : asn1SccT_Float;
      begin
         --  ok := call updateData (56,17)
         ctxt.ok := p_0_updatedata;
         --  DECISION ok and power = 0.0 (58,24)
         --  ANSWER true (60,17)
         if ((ctxt.ok and asn1SccT_Float_Equal (ctxt.power, 0.0))) = true then
            null;
            --  ANSWER false (62,17)
         elsif ((ctxt.ok and asn1SccT_Float_Equal (ctxt.power, 0.0))) = false then
            --  setPowerH2(0.0) (64,25)
            tmp163 := 0.0;
            RI_0_setPowerH2(tmp163);
         end if;
         --  DECISION system_stopped (-1,-1)
         --  ANSWER true (69,17)
         if (ctxt.system_stopped) = true then
            null;
            --  ANSWER false (71,17)
         elsif (ctxt.system_stopped) = false then
            --  stopSystem (73,25)
            RI_0_StopSystem;
            --  system_stopped := true (75,25)
            ctxt.system_stopped := true;
         end if;
         --  RETURN  (None,None) at 354, 612
         return;
      end p_0_doF3;
      

   procedure p_0_doF2 is
      begin
         --  DECISION f2_started (-1,-1)
         --  ANSWER true (87,17)
         if (ctxt.f2_started) = true then
            null;
            --  ANSWER false (89,17)
         elsif (ctxt.f2_started) = false then
            --  f2_duration_max := htl_time + f2_relative_duration_max (91,25)
            ctxt.f2_duration_max := (ctxt.htl_time + ctxt.f2_relative_duration_max);
            --  f2_started := true (92,0)
            ctxt.f2_started := true;
         end if;
         --  DECISION power = 0.0 (95,27)
         --  ANSWER false (97,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            null;
            --  ANSWER true (99,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  DECISION temp_plate <= 55.0 and
            --  abs(temp_plate - temp_air) <= 50.0 (101,48)
            --  ANSWER true (104,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               --  m := m+0.1 (106,33)
               ctxt.m := (ctxt.m + 0.1);
               --  ANSWER false (108,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 601, 543
               return;
            end if;
         end if;
         --  DECISION temp_plate >= 65.0 or 
         --  abs (temp_plate - temp_air) >= 60.0 (114,40)
         --  COMMENT >= 60? (117,12)
         --  ANSWER true (119,17)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (121,25)
            ctxt.power := 0.0;
            --  ANSWER false (123,17)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := power_f1/2.0 - m*0.1 (125,25)
            ctxt.power := ((ctxt.power_f1 / 2.0) - (ctxt.m * 0.1));
            --  DECISION power <= 0.1 (127,35)
            --  ANSWER true (129,25)
            if ((ctxt.power <= 0.1)) = true then
               --  power := 0.1 (131,33)
               ctxt.power := 0.1;
               --  ANSWER false (133,25)
            elsif ((ctxt.power <= 0.1)) = false then
               null;
            end if;
         end if;
         --  setPowerH2(power) (137,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 439, 1032
         return;
      end p_0_doF2;
      

   procedure p_0_doA2 is
      begin
         --  DECISION power = 0.0 (146,27)
         --  ANSWER false (148,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            --  JOIN normalA2 (None,None) at None, None
            goto normalA2;
            --  ANSWER true (170,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  DECISION temp_plate <= 55.0 and
            --  abs(temp_plate - temp_air) <= 50.0 (172,48)
            --  COMMENT Pdiss = 0.0 W (175,20)
            --  ANSWER true (177,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               --  JOIN normalA2 (179,33) at 757, 344
               goto normalA2;
               --  ANSWER false (181,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 861, 346
               return;
            end if;
         end if;
         --  setPowerH2(power) (187,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 435, 612
         return;
         --  CONNECTION normalA2 (150,20)
         <<normalA2>>
         --  DECISION temp_plate >= 65.0 or
         --  abs(temp_plate - temp_air) >= 60.0 (152,48)
         --  COMMENT Pdiss = 1.0 (155,20)
         --  ANSWER false (157,25)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := 0.6 (159,33)
            ctxt.power := 0.6;
            --  power_a2 := power (161,33)
            ctxt.power_a2 := ctxt.power;
            --  ANSWER true (163,25)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (165,33)
            ctxt.power := 0.0;
         end if;
         --  writeln('normalA2') (168,25)
         Put ("normalA2");
         New_Line;
         --  setPowerH2(power) (187,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 435, 612
         return;
      end p_0_doA2;
      

   procedure p_0_doA1 is
      begin
         --  DECISION power = 0.0 (196,27)
         --  ANSWER false (198,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            null;
            --  ANSWER true (200,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  DECISION temp_plate <= 55.0 and abs(temp_plate -temp_air) <= 50.0 (202,48)
            --  ANSWER true (204,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               null;
               --  ANSWER false (206,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 983, 318
               return;
            end if;
         end if;
         --  DECISION temp_plate >= 65.0 or abs(temp_plate - temp_air) >= 60.0 (212,40)
         --  ANSWER true (214,17)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (216,25)
            ctxt.power := 0.0;
            --  ANSWER false (218,17)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := 0.8 (220,25)
            ctxt.power := 0.8;
         end if;
         --  setPowerH2(power) (223,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 518, 657
         return;
      end p_0_doA1;
      

   procedure p_0_doF1 is
      begin
         --  DECISION f1_started (-1,-1)
         --  ANSWER true (234,17)
         if (ctxt.f1_started) = true then
            null;
            --  ANSWER false (236,17)
         elsif (ctxt.f1_started) = false then
            --  f1_duration_max := htl_time + f1_relative_duration_max (238,25)
            ctxt.f1_duration_max := (ctxt.htl_time + ctxt.f1_relative_duration_max);
            --  f1_started := true (239,0)
            ctxt.f1_started := true;
         end if;
         --  DECISION power = 0.0 (242,27)
         --  ANSWER true (244,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  DECISION temp_plate <= 55.0 and
            --  abs(temp_plate - temp_air) <= 50.0 (246,48)
            --  ANSWER true (249,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               --  n := n+1.0 (251,33)
               ctxt.n := (ctxt.n + 1.0);
               --  JOIN normalF1 (253,33) at 599, 624
               goto normalF1;
               --  ANSWER false (255,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 706, 574
               return;
            end if;
            --  ANSWER false (260,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            --  JOIN normalF1 (None,None) at None, None
            goto normalF1;
         end if;
         --  CONNECTION normalF1 (262,20)
         <<normalF1>>
         --  DECISION temp_plate >= 65.0 or
         --  abs(temp_plate - temp_air) >= 60.0 (264,48)
         --  COMMENT ¿>= 60? (267,20)
         --  ANSWER true (269,25)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (271,33)
            ctxt.power := 0.0;
            --  ANSWER false (273,25)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := power_a2-n*0.1 (275,33)
            ctxt.power := (ctxt.power_a2 - (ctxt.n * 0.1));
            --  DECISION power <= 0.1 (277,43)
            --  ANSWER true (279,33)
            if ((ctxt.power <= 0.1)) = true then
               --  power := 0.1 (281,41)
               ctxt.power := 0.1;
               --  ANSWER false (283,33)
            elsif ((ctxt.power <= 0.1)) = false then
               null;
            end if;
            --  power_f1 := power (286,33)
            ctxt.power_f1 := ctxt.power;
         end if;
         --  setPowerH2(power) (289,25)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 306, 912
         return;
      end p_0_doF1;
      

   procedure configureParameters(Configuration: in out asn1SccHTL_Config) is
      tmp435 : asn1SccT_Double;
      tmp399 : asn1SccT_Float;
      tmp417 : asn1SccT_UInt32;
      tmp391 : asn1SccT_Float;
      tmp407 : asn1SccT_UInt32;
      tmp443 : asn1SccT_Double;
      tmp383 : asn1SccT_Float;
      tmp427 : asn1SccT_Double;
      begin
         --  press_5km  := if exist (Configuration.press_5km) then Configuration.press_5km else press_5km fi (305,17)
         if (Configuration.exist.press_5km = 1) then
            tmp383 := Configuration.press_5km;
         else
            tmp383 := ctxt.press_5km;
         end if;
         ctxt.press_5km := tmp383;
         --  press_10km := if exist(Configuration.press_10km) then Configuration.press_10km else press_10km fi (306,0)
         if (Configuration.exist.press_10km = 1) then
            tmp391 := Configuration.press_10km;
         else
            tmp391 := ctxt.press_10km;
         end if;
         ctxt.press_10km := tmp391;
         --  press_18km := if exist(Configuration.press_18km) then Configuration.press_18km else press_18km fi (307,0)
         if (Configuration.exist.press_18km = 1) then
            tmp399 := Configuration.press_18km;
         else
            tmp399 := ctxt.press_18km;
         end if;
         ctxt.press_18km := tmp399;
         --  f1_duration :=
         --   if exist(Configuration.f1_duration_secs) then
            --     Configuration.f1_duration_secs * 1000
            --  else
            --    f1_duration
            --  fi (309,0)
            if (Configuration.exist.f1_duration_secs = 1) then
               tmp407 := (Configuration.f1_duration_secs * 1000);
            else
               tmp407 := ctxt.f1_duration;
            end if;
            ctxt.f1_duration := tmp407;
            --  f2_duration :=
            --  if exist(Configuration.f2_duration_secs) then
               --    Configuration.f2_duration_secs * 1000
               --  else
               --    f2_duration
               --  fi (316,0)
               if (Configuration.exist.f2_duration_secs = 1) then
                  tmp417 := (Configuration.f2_duration_secs * 1000);
               else
                  tmp417 := ctxt.f2_duration;
               end if;
               ctxt.f2_duration := tmp417;
               --  a1_duration_emergency :=
               --  if exist(Configuration.a1_duration_emergency_secs) then
                  --    Configuration.a1_duration_emergency_secs
                  --  else
                  --    a1_duration_emergency
                  --  fi (323,0)
                  if (Configuration.exist.a1_duration_emergency_secs = 1) then
                     tmp427 := Configuration.a1_duration_emergency_secs;
                  else
                     tmp427 := ctxt.a1_duration_emergency;
                  end if;
                  ctxt.a1_duration_emergency := tmp427;
                  --  a1_duration_max :=
                  --  if exist(Configuration.a1_duration_max_secs) then
                     --    Configuration.a1_duration_max_secs
                     --  else
                     --    a1_duration_max
                     --  fi (330,0)
                     if (Configuration.exist.a1_duration_max_secs = 1) then
                        tmp435 := Configuration.a1_duration_max_secs;
                     else
                        tmp435 := ctxt.a1_duration_max;
                     end if;
                     ctxt.a1_duration_max := tmp435;
                     --  a2_duration_max :=
                     --  if exist(Configuration.a2_duration_max_secs) then
                        --    Configuration.a2_duration_max_secs
                        --  else
                        --    a2_duration_max
                        --  fi (337,0)
                        if (Configuration.exist.a2_duration_max_secs = 1) then
                           tmp443 := Configuration.a2_duration_max_secs;
                        else
                           tmp443 := ctxt.a2_duration_max;
                        end if;
                        ctxt.a2_duration_max := tmp443;
                        --  configureParameters_Transition (None,None)
                        configureParameters_Transition;
                        --  RETURN  (None,None) at 931, 777
                        return;
                     end configureParameters;
                     

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
                     tmp560 : asn1SccT_Float;
                     tmp468 : asn1SccOBSW_DP_Filter;
                     tmp460 : asn1SccOBSW_DP_Filter;
                     tmp595 : asn1SccT_Float;
                     tmp581 : asn1SccT_Float;
                     tmp464 : asn1SccOBSW_DP_Filter;
                     tmp548 : asn1SccT_Float;
                     --  !! stack: _call_external_function line 1604
                     tmp569 : asn1SccT_Float;
                     tmp538 : asn1SccT_Float;
                     tmp456 : asn1SccOBSW_DP_Filter;
                     begin
                        --  getTime(gps_time, htl_time) (368,17)
                        RI_0_getTime(gps_time, ctxt.htl_time);
                        --  retreiveSingleData(pt1000s,pt1000s_data) (370,17)
                        tmp456 := asn1Sccpt1000s;
                        RI_0_RetreiveSingleData(tmp456, pt1000s_data);
                        --  retreiveSingleData(ps1, press1_data) (372,17)
                        tmp460 := asn1Sccps1;
                        RI_0_RetreiveSingleData(tmp460, press1_data);
                        --  retreiveSingleData(ps2, press2_data) (374,17)
                        tmp464 := asn1Sccps2;
                        RI_0_RetreiveSingleData(tmp464, press2_data);
                        --  retreiveSingleData(heater2, power_data) (376,17)
                        tmp468 := asn1Sccheater2;
                        RI_0_RetreiveSingleData(tmp468, power_data);
                        --  temp_air := 0.0 (378,17)
                        ctxt.temp_air := 0.0;
                        --  temp_plate := 0.0 (379,0)
                        ctxt.temp_plate := 0.0;
                        --  press := 0.0 (380,0)
                        ctxt.press := 0.0;
                        --  placa_abajo_ok := pt1000s_data.pt1000s.data.validity(6) = valid (382,0)
                        placa_abajo_ok := (pt1000s_data.pt1000s.data.validity.Data(7) = asn1Sccvalid);
                        --  placa_arriba_ok := pt1000s_data.pt1000s.data.validity(5) = valid (383,0)
                        placa_arriba_ok := (pt1000s_data.pt1000s.data.validity.Data(6) = asn1Sccvalid);
                        --  aire_infinito_ok := pt1000s_data.pt1000s.data.validity(2) = valid (384,0)
                        aire_infinito_ok := (pt1000s_data.pt1000s.data.validity.Data(3) = asn1Sccvalid);
                        --  press1_ok := press1_data.ps1.data.validity = valid (385,0)
                        press1_ok := (press1_data.ps1.data.validity = asn1Sccvalid);
                        --  press2_ok := press2_data.ps2.data.validity = valid (386,0)
                        press2_ok := (press2_data.ps2.data.validity = asn1Sccvalid);
                        --  power_ok := power_data.heater2.data.validity = valid (387,0)
                        power_ok := (power_data.heater2.data.validity = asn1Sccvalid);
                        --  DECISION power_ok and
                        --  (placa_abajo_ok or placa_arriba_ok)
                        --  and aire_infinito_ok
                        --  and (press1_ok or press2_ok) (392,0)
                        --  ANSWER true (394,17)
                        if ((((power_ok and (placa_abajo_ok or placa_arriba_ok)) and aire_infinito_ok) and (press1_ok or press2_ok))) = true then
                           --  temp_plate := if placa_arriba_ok then (pt1000s_data.pt1000s.data.celsius(5)) else 0.0 fi (396,25)
                           if placa_arriba_ok then
                              tmp538 := pt1000s_data.pt1000s.data.celsius.Data(6);
                           else
                              tmp538 := 0.0;
                           end if;
                           ctxt.temp_plate := tmp538;
                           --  temp_plate := if placa_abajo_ok then (pt1000s_data.pt1000s.data.celsius(6) + temp_plate) else temp_plate fi (397,0)
                           if placa_abajo_ok then
                              tmp548 := (pt1000s_data.pt1000s.data.celsius.Data(7) + ctxt.temp_plate);
                           else
                              tmp548 := ctxt.temp_plate;
                           end if;
                           ctxt.temp_plate := tmp548;
                           --  temp_plate := if placa_abajo_ok and placa_arriba_ok then temp_plate / 2.0 else temp_plate fi (398,0)
                           if (placa_abajo_ok and placa_arriba_ok) then
                              tmp560 := (ctxt.temp_plate / 2.0);
                           else
                              tmp560 := ctxt.temp_plate;
                           end if;
                           ctxt.temp_plate := tmp560;
                           --  press := if press1_ok then float(press1_data.ps1.data.processed.pressure) /100.0 else 0.0 fi (400,0)
                           if press1_ok then
                              tmp569 := (Asn1Real(press1_data.ps1.data.processed.pressure) / 100.0);
                           else
                              tmp569 := 0.0;
                           end if;
                           ctxt.press := tmp569;
                           --  press := if press2_ok then (float(press2_data.ps2.data.processed.pressure)/100.0 + press) else press fi (401,0)
                           if press2_ok then
                              tmp581 := ((Asn1Real(press2_data.ps2.data.processed.pressure) / 100.0) + ctxt.press);
                           else
                              tmp581 := ctxt.press;
                           end if;
                           ctxt.press := tmp581;
                           --  press := if press1_ok and press2_ok then press / 2.0 else press fi (402,0)
                           if (press1_ok and press2_ok) then
                              tmp595 := (ctxt.press / 2.0);
                           else
                              tmp595 := ctxt.press;
                           end if;
                           ctxt.press := tmp595;
                           --  temp_air := pt1000s_data.pt1000s.data.celsius(2) (404,0)
                           ctxt.temp_air := pt1000s_data.pt1000s.data.celsius.Data(3);
                           --  power := power_data.heater2.data.power_watts (406,0)
                           ctxt.power := power_data.heater2.data.power_watts;
                           --  writeln('temp_plate: ', temp_plate) (408,25)
                           Put ("temp_plate: ");
                           Put (asn1SccT_Float'Image (ctxt.temp_plate));
                           New_Line;
                           --  writeln('power: ', power) (410,25)
                           Put ("power: ");
                           Put (asn1SccT_Float'Image (ctxt.power));
                           New_Line;
                           --  writeln('press: ', press) (412,25)
                           Put ("press: ");
                           Put (asn1SccT_Float'Image (ctxt.press));
                           New_Line;
                           --  writeln('press 2 ok ', press2_ok) (414,25)
                           Put ("press 2 ok ");
                           Put (asn1SccT_Boolean'Image (press2_ok));
                           New_Line;
                           --  writeln('temp_air: ', temp_air) (416,25)
                           Put ("temp_air: ");
                           Put (asn1SccT_Float'Image (ctxt.temp_air));
                           New_Line;
                           --  RETURN True (None,None) at 407, 1318
                           return true;
                           --  ANSWER false (420,17)
                        elsif ((((power_ok and (placa_abajo_ok or placa_arriba_ok)) and aire_infinito_ok) and (press1_ok or press2_ok))) = false then
                           --  writeln('invalid data :-(') (422,25)
                           Put ("invalid data :-(");
                           New_Line;
                           --  RETURN False (None,None) at 1223, 888
                           return false;
                        end if;
                     end p_0_updateData;
                     

                  procedure getCurrentMode(Current_State: in out asn1SccHTL_State) is
                     begin
                        --  writeln('actual status is', actual_state) (437,17)
                        Put ("actual status is");
                        Put (ctxt.actual_state'Img);
                        New_Line;
                        --  Current_State := actual_state (439,17)
                        Current_State := ctxt.actual_state;
                        --  getCurrentMode_Transition (None,None)
                        getCurrentMode_Transition;
                        --  RETURN  (None,None) at 603, 307
                        return;
                     end getCurrentMode;
                     

                  procedure setCurrentMode(current_state: in out asn1SccHTL_State) is
                     begin
                        case ctxt.state is
                           when asn1Sccf3 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (12);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Scca2 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (4);
                           when asn1Scca1 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (2);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf2 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (15);
                           when asn1Sccf1 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (17);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end setCurrentMode;
                     

                  procedure tick is
                     begin
                        case ctxt.state is
                           when asn1Sccf3 =>
                              Execute_Transition (11);
                           when asn1Sccerror =>
                              Execute_Transition (13);
                           when asn1Scca2 =>
                              Execute_Transition (3);
                           when asn1Scca1 =>
                              Execute_Transition (1);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf2 =>
                              Execute_Transition (14);
                           when asn1Sccf1 =>
                              Execute_Transition (16);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end tick;
                     

                  procedure configureParameters_Transition is
                     begin
                        case ctxt.state is
                           when asn1Sccf3 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Scca2 =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf2 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
                              Execute_Transition (CS_Only);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end configureParameters_Transition;
                     

                  procedure getCurrentMode_Transition is
                     begin
                        case ctxt.state is
                           when asn1Sccf3 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Scca2 =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf2 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
                              Execute_Transition (CS_Only);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end getCurrentMode_Transition;
                     

                  procedure f1_timeout is
                     begin
                        case ctxt.state is
                           when asn1Sccf3 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Scca2 =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf2 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
                              Execute_Transition (CS_Only);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end f1_timeout;
                     

                  procedure f2_timeout is
                     begin
                        case ctxt.state is
                           when asn1Sccf3 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Scca2 =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf2 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
                              Execute_Transition (CS_Only);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end f2_timeout;
                     

                  procedure Execute_Transition (Id : Integer) is
                     trId : Integer := Id;
                     msgPending : Asn1Boolean := True;
                     begin
                        while (trId /= -1) loop
                           case trId is
                              when 0 =>
                                 --  NEXT_STATE A1 (446,18) at 322, 122
                                 trId := -1;
                                 ctxt.State := asn1SccA1;
                                 goto Next_Transition;
                              when 1 =>
                                 --  actual_state := a1 (452,17)
                                 ctxt.actual_state := asn1Scca1;
                                 --  ok := call updateData (453,0)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (457,17)
                                 if (ctxt.ok) = true then
                                    null;
                                    --  ANSWER false (459,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (461,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (463,30) at 518, 410
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                                 --  DECISION (press <= press_10km and
                                 --  htl_time >= a1_duration_emergency) or
                                 --  htl_time >= a1_duration_max (467,35)
                                 --  ANSWER false (470,17)
                                 if ((((ctxt.press <= ctxt.press_10km) and (ctxt.htl_time >= ctxt.a1_duration_emergency)) or (ctxt.htl_time >= ctxt.a1_duration_max))) = false then
                                    --  doA1 (472,25)
                                    p_0_doA1;
                                    --  NEXT_STATE A1 (474,30) at 594, 687
                                    trId := -1;
                                    ctxt.State := asn1SccA1;
                                    goto Next_Transition;
                                    --  ANSWER true (476,17)
                                 elsif ((((ctxt.press <= ctxt.press_10km) and (ctxt.htl_time >= ctxt.a1_duration_emergency)) or (ctxt.htl_time >= ctxt.a1_duration_max))) = true then
                                    --  NEXT_STATE A2 (478,30) at 684, 637
                                    trId := -1;
                                    ctxt.State := asn1SccA2;
                                    goto Next_Transition;
                                 end if;
                              when 2 =>
                                 --  NEXT_STATE Selectstate (483,22) at 953, 186
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 3 =>
                                 --  actual_state := a2 (490,17)
                                 ctxt.actual_state := asn1Scca2;
                                 --  ok := call updateData (491,0)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (495,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (497,35)
                                    --  COMMENT no estamos cayendo? (499,20)
                                    --  ANSWER True (501,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  writeln('Nos estamos cayendo') (503,33)
                                       Put ("Nos estamos cayendo");
                                       New_Line;
                                       --  NEXT_STATE F3 (505,38) at 1331, 531
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (507,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       null;
                                    end if;
                                    --  ANSWER false (510,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (512,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (514,30) at 1560, 401
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                                 --  DECISION htl_time >= a2_duration_max
                                 --  or press <= press_18km (518,0)
                                 --  ANSWER false (520,17)
                                 if (((ctxt.htl_time >= ctxt.a2_duration_max) or (ctxt.press <= ctxt.press_18km))) = false then
                                    --  doA2 (522,25)
                                    p_0_doA2;
                                    --  NEXT_STATE A2 (524,30) at 1075, 790
                                    trId := -1;
                                    ctxt.State := asn1SccA2;
                                    goto Next_Transition;
                                    --  ANSWER true (526,17)
                                 elsif (((ctxt.htl_time >= ctxt.a2_duration_max) or (ctxt.press <= ctxt.press_18km))) = true then
                                    --  writeln('A2 max duration: ', a2_duration_max) (528,25)
                                    Put ("A2 max duration: ");
                                    Put (asn1SccT_Double'Image (ctxt.a2_duration_max));
                                    New_Line;
                                    --  NEXT_STATE F1 (530,30) at 1267, 795
                                    trId := -1;
                                    ctxt.State := asn1SccF1;
                                    goto Next_Transition;
                                 end if;
                              when 4 =>
                                 --  NEXT_STATE Selectstate (535,22) at 1778, 182
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 5 =>
                                 --  NEXT_STATE F2 (542,22) at 740, 1185
                                 trId := -1;
                                 ctxt.State := asn1SccF2;
                                 goto Next_Transition;
                              when 6 =>
                                 --  NEXT_STATE A1 (546,22) at 417, 1118
                                 trId := -1;
                                 ctxt.State := asn1SccA1;
                                 goto Next_Transition;
                              when 7 =>
                                 --  NEXT_STATE A2 (550,22) at 237, 1115
                                 trId := -1;
                                 ctxt.State := asn1SccA2;
                                 goto Next_Transition;
                              when 8 =>
                                 --  NEXT_STATE F1 (554,22) at 341, 1363
                                 trId := -1;
                                 ctxt.State := asn1SccF1;
                                 goto Next_Transition;
                              when 9 =>
                                 --  NEXT_STATE F3 (558,22) at 552, 1117
                                 trId := -1;
                                 ctxt.State := asn1SccF3;
                                 goto Next_Transition;
                              when 10 =>
                                 --  NEXT_STATE Error (562,22) at 882, 1065
                                 trId := -1;
                                 ctxt.State := asn1SccError;
                                 goto Next_Transition;
                              when 11 =>
                                 --  actual_state := f3 (569,17)
                                 ctxt.actual_state := asn1Sccf3;
                                 --  doF3 (571,17)
                                 p_0_doF3;
                                 --  NEXT_STATE F3 (573,22) at 2127, 1173
                                 trId := -1;
                                 ctxt.State := asn1SccF3;
                                 goto Next_Transition;
                              when 12 =>
                                 --  NEXT_STATE Selectstate (577,22) at 2291, 1063
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 13 =>
                                 --  ok := call updateData (584,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  actual_state := error (585,0)
                                 ctxt.actual_state := asn1Sccerror;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (589,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION last_good_state (-1,-1)
                                    --  ANSWER a1 (593,25)
                                    if (ctxt.last_good_state) = asn1Scca1 then
                                       --  NEXT_STATE A1 (595,38) at 2265, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccA1;
                                       goto Next_Transition;
                                       --  ANSWER a2 (597,25)
                                    elsif (ctxt.last_good_state) = asn1Scca2 then
                                       --  NEXT_STATE A2 (599,38) at 2355, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccA2;
                                       goto Next_Transition;
                                       --  ANSWER f1 (601,25)
                                    elsif (ctxt.last_good_state) = asn1Sccf1 then
                                       --  NEXT_STATE F1 (603,38) at 2445, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccF1;
                                       goto Next_Transition;
                                       --  ANSWER f2 (605,25)
                                    elsif (ctxt.last_good_state) = asn1Sccf2 then
                                       --  NEXT_STATE F2 (607,38) at 2535, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccF2;
                                       goto Next_Transition;
                                       --  ANSWER else (None,None)
                                    else
                                       --  NEXT_STATE Error (611,38) at 2625, 1362
                                       trId := -1;
                                       ctxt.State := asn1SccError;
                                       goto Next_Transition;
                                    end if;
                                    --  ANSWER false (614,17)
                                 elsif (ctxt.ok) = false then
                                    --  NEXT_STATE Error (616,30) at 2706, 1243
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 14 =>
                                 --  actual_state := f2 (624,17)
                                 ctxt.actual_state := asn1Sccf2;
                                 --  ok := call updateData (625,0)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (629,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (631,35)
                                    --  ANSWER True (633,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  NEXT_STATE F3 (635,38) at 1607, 1340
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (637,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       --  DECISION htl_time >= f2_duration_max (639,46)
                                       --  ANSWER true (641,33)
                                       if ((ctxt.htl_time >= ctxt.f2_duration_max)) = true then
                                          --  NEXT_STATE F3 (643,46) at 1323, 1476
                                          --  COMMENT time in F3 is bigger
                                          --  than the allowed. (645,36)
                                          trId := -1;
                                          ctxt.State := asn1SccF3;
                                          goto Next_Transition;
                                          --  ANSWER false (648,33)
                                       elsif ((ctxt.htl_time >= ctxt.f2_duration_max)) = false then
                                          --  doF2 (650,41)
                                          p_0_doF2;
                                          --  NEXT_STATE F2 (652,46) at 1433, 1528
                                          trId := -1;
                                          ctxt.State := asn1SccF2;
                                          goto Next_Transition;
                                       end if;
                                    end if;
                                    --  ANSWER false (656,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state:=actual_state (658,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (660,30) at 1063, 1281
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 15 =>
                                 --  NEXT_STATE Selectstate (665,22) at 1754, 1057
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 16 =>
                                 --  actual_state := f1 (672,17)
                                 ctxt.actual_state := asn1Sccf1;
                                 --  ok := call updateData (673,0)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (677,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (679,35)
                                    --  ANSWER True (681,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  NEXT_STATE F3 (683,38) at 2572, 494
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (685,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       --  DECISION htl_time >= f1_duration_max (687,46)
                                       --  ANSWER true (689,33)
                                       if ((ctxt.htl_time >= ctxt.f1_duration_max)) = true then
                                          --  NEXT_STATE F2 (691,46) at 2277, 641
                                          trId := -1;
                                          ctxt.State := asn1SccF2;
                                          goto Next_Transition;
                                          --  ANSWER false (693,33)
                                       elsif ((ctxt.htl_time >= ctxt.f1_duration_max)) = false then
                                          --  doF1 (695,41)
                                          p_0_doF1;
                                          --  NEXT_STATE F1 (697,46) at 2367, 696
                                          trId := -1;
                                          ctxt.State := asn1SccF1;
                                          goto Next_Transition;
                                       end if;
                                    end if;
                                    --  ANSWER false (701,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (703,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (705,30) at 2003, 418
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 17 =>
                                 --  NEXT_STATE Selectstate (710,22) at 2709, 192
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
                              --  DECISION actual_state = f2 (540,30)
                              --  ANSWER true (None,None)
                              if ((ctxt.actual_state = asn1Sccf2)) = true then
                                 trId := 5;
                                 --  Priority 1
                                 --  DECISION actual_state = a1 (544,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Scca1)) = true then
                                 trId := 6;
                                 --  Priority 1
                                 --  DECISION actual_state = a2 (548,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Scca2)) = true then
                                 trId := 7;
                                 --  Priority 1
                                 --  DECISION actual_state = f1 (552,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccf1)) = true then
                                 trId := 8;
                                 --  Priority 1
                                 --  DECISION actual_state = f3 (556,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccf3)) = true then
                                 trId := 9;
                                 --  Priority 1
                                 --  DECISION actual_state = error (560,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccerror)) = true then
                                 trId := 10;
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