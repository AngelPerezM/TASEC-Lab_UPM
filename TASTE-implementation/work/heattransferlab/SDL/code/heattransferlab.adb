-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !

with System.IO;
use System.IO;

with Ada.Unchecked_Conversion;
with Ada.Numerics.Generic_Elementary_Functions;

package body Heattransferlab is
   CS_Only : constant := 19;
   procedure Execute_Transition (Id : Integer);
   procedure p_0_doF3;
   procedure p_0_doF2;
   procedure p_0_doA2;
   procedure p_0_doA1;
   procedure p_0_doF1;
   function p_0_updateData return asn1SccT_Boolean;
   procedure p_0_initF2;
   procedure p_0_initF1;
   procedure p_0_initA1;
   procedure p_0_initA2;
   procedure p_0_doF3 is
      tmp192 : asn1SccT_Float;
      --  !! stack: _call_external_function line 1604
      begin
         --  DECISION system_stopped (-1,-1)
         --  ANSWER true (58,17)
         if (ctxt.system_stopped) = true then
            --  RETURN  (None,None) at 669, 238
            return;
            --  ANSWER false (62,17)
         elsif (ctxt.system_stopped) = false then
            null;
         end if;
         --  ok := call updateData (65,17)
         ctxt.ok := p_0_updatedata;
         --  DECISION ok and power = 0.0 (67,24)
         --  ANSWER true (69,17)
         if ((ctxt.ok and asn1SccT_Float_Equal (ctxt.power, 0.0))) = true then
            --  system_stopped := true (71,25)
            ctxt.system_stopped := true;
            --  stopSystem (73,25)
            RI_0_StopSystem;
            --  ANSWER false (75,17)
         elsif ((ctxt.ok and asn1SccT_Float_Equal (ctxt.power, 0.0))) = false then
            --  setPowerH2(0.0) (77,25)
            tmp192 := 0.0;
            RI_0_setPowerH2(tmp192);
         end if;
         --  RETURN  (None,None) at 354, 601
         return;
      end p_0_doF3;
      

   procedure p_0_doF2 is
      begin
         --  DECISION (not f2_first_it) and power = 0.0 (87,39)
         --  ANSWER false (89,17)
         if (((not ctxt.f2_first_it) and asn1SccT_Float_Equal (ctxt.power, 0.0))) = false then
            null;
            --  ANSWER true (91,17)
         elsif (((not ctxt.f2_first_it) and asn1SccT_Float_Equal (ctxt.power, 0.0))) = true then
            --  DECISION temp_plate <= 55.0 and
            --  abs(temp_plate - temp_air) <= 50.0 (93,48)
            --  ANSWER true (96,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               --  m := m+0.1 (98,33)
               ctxt.m := (ctxt.m + 0.1);
               --  RecordHTLParams(actual_state, f1_duration_max, f2_duration_max, m, n, power_f1) (100,33)
               --  COMMENT m was modified, so it needs to
               --  be recorded (102,28)
               RI_0_RecordHTLParams(ctxt.actual_state, ctxt.f1_duration_max, ctxt.f2_duration_max, ctxt.m, ctxt.n, ctxt.power_f1);
               --  ANSWER false (105,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 726, 355
               return;
            end if;
         end if;
         --  DECISION temp_plate >= 65.0 or 
         --  abs (temp_plate - temp_air) >= 60.0 (111,40)
         --  COMMENT >= 60? (114,12)
         --  ANSWER true (116,17)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (118,25)
            ctxt.power := 0.0;
            --  ANSWER false (120,17)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := power_f1/2.0 - m*0.1 (122,25)
            ctxt.power := ((ctxt.power_f1 / 2.0) - (ctxt.m * 0.1));
            --  DECISION power <= 0.1 (124,35)
            --  ANSWER true (126,25)
            if ((ctxt.power <= 0.1)) = true then
               --  power := 0.1 (128,33)
               ctxt.power := 0.1;
               --  ANSWER false (130,25)
            elsif ((ctxt.power <= 0.1)) = false then
               null;
            end if;
         end if;
         --  setPowerH2(power) (134,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 439, 904
         return;
      end p_0_doF2;
      

   procedure p_0_doA2 is
      begin
         --  DECISION power = 0.0 (143,27)
         --  ANSWER false (145,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            --  JOIN normalA2 (None,None) at None, None
            goto normalA2;
            --  ANSWER true (165,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  DECISION temp_plate <= 55.0 and
            --  abs(temp_plate - temp_air) <= 50.0 (167,48)
            --  COMMENT Pdiss = 0.0 W (170,20)
            --  ANSWER true (172,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               --  JOIN normalA2 (174,33) at 757, 344
               goto normalA2;
               --  ANSWER false (176,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 861, 346
               return;
            end if;
         end if;
         --  setPowerH2(power) (182,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 435, 557
         return;
         --  CONNECTION normalA2 (147,20)
         <<normalA2>>
         --  DECISION temp_plate >= 65.0 or
         --  abs(temp_plate - temp_air) >= 60.0 (149,48)
         --  COMMENT Pdiss = 1.0 (152,20)
         --  ANSWER false (154,25)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := power_a2 (156,33)
            ctxt.power := ctxt.power_a2;
            --  ANSWER true (158,25)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (160,33)
            ctxt.power := 0.0;
         end if;
         --  writeln('normalA2') (163,25)
         Put ("normalA2");
         New_Line;
         --  setPowerH2(power) (182,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 435, 557
         return;
      end p_0_doA2;
      

   procedure p_0_doA1 is
      begin
         --  DECISION power = 0.0 (191,27)
         --  ANSWER false (193,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            null;
            --  ANSWER true (195,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  DECISION temp_plate <= 55.0 and abs(temp_plate -temp_air) <= 50.0 (197,48)
            --  ANSWER true (199,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               null;
               --  ANSWER false (201,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 983, 318
               return;
            end if;
         end if;
         --  DECISION temp_plate >= 65.0 or abs(temp_plate - temp_air) >= 60.0 (207,40)
         --  ANSWER true (209,17)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (211,25)
            ctxt.power := 0.0;
            --  ANSWER false (213,17)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := 0.8 (215,25)
            ctxt.power := 0.8;
         end if;
         --  setPowerH2(power) (218,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 518, 657
         return;
      end p_0_doA1;
      

   procedure p_0_doF1 is
      begin
         --  DECISION (not f1_first_it) and power = 0.0 (227,39)
         --  ANSWER true (229,17)
         if (((not ctxt.f1_first_it) and asn1SccT_Float_Equal (ctxt.power, 0.0))) = true then
            --  DECISION temp_plate <= 55.0 and
            --  abs(temp_plate - temp_air) <= 50.0 (231,48)
            --  ANSWER true (234,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               --  COMMENT n will be recorded at the end
               --  of the procedure execution (238,28)
               --  n := n+1.0 (236,33)
               ctxt.n := (ctxt.n + 1.0);
               --  JOIN normalF1 (241,33) at 820, 465
               goto normalF1;
               --  ANSWER false (243,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 1164, 415
               return;
            end if;
            --  ANSWER false (248,17)
         elsif (((not ctxt.f1_first_it) and asn1SccT_Float_Equal (ctxt.power, 0.0))) = false then
            --  JOIN normalF1 (None,None) at None, None
            goto normalF1;
         end if;
         --  CONNECTION normalF1 (250,20)
         <<normalF1>>
         --  DECISION temp_plate >= 65.0 or
         --  abs(temp_plate - temp_air) >= 60.0 (252,48)
         --  ANSWER true (255,25)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (257,33)
            ctxt.power := 0.0;
            --  ANSWER false (259,25)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := power_a2-n*0.1 (261,33)
            ctxt.power := (ctxt.power_a2 - (ctxt.n * 0.1));
            --  DECISION power <= 0.1 (263,43)
            --  ANSWER true (265,33)
            if ((ctxt.power <= 0.1)) = true then
               --  power := 0.1 (267,41)
               ctxt.power := 0.1;
               --  ANSWER false (269,33)
            elsif ((ctxt.power <= 0.1)) = false then
               null;
            end if;
            --  power_f1 := power (272,33)
            ctxt.power_f1 := ctxt.power;
         end if;
         --  setPowerH2(power) (275,25)
         RI_0_setPowerH2(ctxt.power);
         --  RecordHTLParams(actual_state, f1_duration_max, f2_duration_max, m, n, power_f1) (277,25)
         --  COMMENT power was modified,
         --   so it needs to be recorded (279,20)
         RI_0_RecordHTLParams(ctxt.actual_state, ctxt.f1_duration_max, ctxt.f2_duration_max, ctxt.m, ctxt.n, ctxt.power_f1);
         --  RETURN  (None,None) at 388, 808
         return;
      end p_0_doF1;
      

   procedure configureParameters(Configuration: in out asn1SccHTL_Config) is
      tmp447 : asn1SccT_Double;
      tmp430 : asn1SccT_Float;
      tmp422 : asn1SccT_Float;
      tmp464 : asn1SccT_Double;
      tmp472 : asn1SccT_Double;
      tmp438 : asn1SccT_Double;
      tmp414 : asn1SccT_Float;
      tmp456 : asn1SccT_Double;
      begin
         --  press_5km  := if exist (Configuration.press_5km) then Configuration.press_5km else press_5km fi (296,17)
         if (Configuration.exist.press_5km = 1) then
            tmp414 := Configuration.press_5km;
         else
            tmp414 := ctxt.press_5km;
         end if;
         ctxt.press_5km := tmp414;
         --  press_10km := if exist(Configuration.press_10km) then Configuration.press_10km else press_10km fi (297,0)
         if (Configuration.exist.press_10km = 1) then
            tmp422 := Configuration.press_10km;
         else
            tmp422 := ctxt.press_10km;
         end if;
         ctxt.press_10km := tmp422;
         --  press_18km := if exist(Configuration.press_18km) then Configuration.press_18km else press_18km fi (298,0)
         if (Configuration.exist.press_18km = 1) then
            tmp430 := Configuration.press_18km;
         else
            tmp430 := ctxt.press_18km;
         end if;
         ctxt.press_18km := tmp430;
         --  f1_relative_duration_max :=
         --   if exist(Configuration.f1_duration_secs) then
            --     float (Configuration.f1_duration_secs)
            --  else
            --    f1_relative_duration_max
            --  fi (300,0)
            if (Configuration.exist.f1_duration_secs = 1) then
               tmp438 := Asn1Real(Configuration.f1_duration_secs);
            else
               tmp438 := ctxt.f1_relative_duration_max;
            end if;
            ctxt.f1_relative_duration_max := tmp438;
            --  f2_relative_duration_max :=
            --  if exist(Configuration.f2_duration_secs) then
               --    float(Configuration.f2_duration_secs)
               --  else
               --    f2_relative_duration_max
               --  fi (307,0)
               if (Configuration.exist.f2_duration_secs = 1) then
                  tmp447 := Asn1Real(Configuration.f2_duration_secs);
               else
                  tmp447 := ctxt.f2_relative_duration_max;
               end if;
               ctxt.f2_relative_duration_max := tmp447;
               --  a1_duration_emergency :=
               --  if exist(Configuration.a1_duration_emergency_secs) then
                  --    Configuration.a1_duration_emergency_secs
                  --  else
                  --    a1_duration_emergency
                  --  fi (314,0)
                  if (Configuration.exist.a1_duration_emergency_secs = 1) then
                     tmp456 := Configuration.a1_duration_emergency_secs;
                  else
                     tmp456 := ctxt.a1_duration_emergency;
                  end if;
                  ctxt.a1_duration_emergency := tmp456;
                  --  a1_duration_max :=
                  --  if exist(Configuration.a1_duration_max_secs) then
                     --    Configuration.a1_duration_max_secs
                     --  else
                     --    a1_duration_max
                     --  fi (321,0)
                     if (Configuration.exist.a1_duration_max_secs = 1) then
                        tmp464 := Configuration.a1_duration_max_secs;
                     else
                        tmp464 := ctxt.a1_duration_max;
                     end if;
                     ctxt.a1_duration_max := tmp464;
                     --  a2_duration_max :=
                     --  if exist(Configuration.a2_duration_max_secs) then
                        --    Configuration.a2_duration_max_secs
                        --  else
                        --    a2_duration_max
                        --  fi (328,0)
                        if (Configuration.exist.a2_duration_max_secs = 1) then
                           tmp472 := Configuration.a2_duration_max_secs;
                        else
                           tmp472 := ctxt.a2_duration_max;
                        end if;
                        ctxt.a2_duration_max := tmp472;
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
                     tmp489 : asn1SccOBSW_DP_Filter;
                     tmp610 : asn1SccT_Float;
                     tmp598 : asn1SccT_Float;
                     tmp589 : asn1SccT_Float;
                     --  !! stack: _call_external_function line 1604
                     tmp485 : asn1SccOBSW_DP_Filter;
                     tmp577 : asn1SccT_Float;
                     tmp624 : asn1SccT_Float;
                     tmp493 : asn1SccOBSW_DP_Filter;
                     tmp497 : asn1SccOBSW_DP_Filter;
                     tmp567 : asn1SccT_Float;
                     begin
                        --  getTime(gps_time, htl_time) (359,17)
                        RI_0_getTime(gps_time, ctxt.htl_time);
                        --  retreiveSingleData(pt1000s,pt1000s_data) (361,17)
                        tmp485 := asn1Sccpt1000s;
                        RI_0_RetreiveSingleData(tmp485, pt1000s_data);
                        --  retreiveSingleData(ps1, press1_data) (363,17)
                        tmp489 := asn1Sccps1;
                        RI_0_RetreiveSingleData(tmp489, press1_data);
                        --  retreiveSingleData(ps2, press2_data) (365,17)
                        tmp493 := asn1Sccps2;
                        RI_0_RetreiveSingleData(tmp493, press2_data);
                        --  retreiveSingleData(heater2, power_data) (367,17)
                        tmp497 := asn1Sccheater2;
                        RI_0_RetreiveSingleData(tmp497, power_data);
                        --  temp_air := 0.0 (369,17)
                        ctxt.temp_air := 0.0;
                        --  temp_plate := 0.0 (370,0)
                        ctxt.temp_plate := 0.0;
                        --  press := 0.0 (371,0)
                        ctxt.press := 0.0;
                        --  placa_abajo_ok := pt1000s_data.pt1000s.data.validity(6) = valid (373,0)
                        placa_abajo_ok := (pt1000s_data.pt1000s.data.validity.Data(7) = asn1Sccvalid);
                        --  placa_arriba_ok := pt1000s_data.pt1000s.data.validity(5) = valid (374,0)
                        placa_arriba_ok := (pt1000s_data.pt1000s.data.validity.Data(6) = asn1Sccvalid);
                        --  aire_infinito_ok := pt1000s_data.pt1000s.data.validity(2) = valid (375,0)
                        aire_infinito_ok := (pt1000s_data.pt1000s.data.validity.Data(3) = asn1Sccvalid);
                        --  press1_ok := press1_data.ps1.data.validity = valid (376,0)
                        press1_ok := (press1_data.ps1.data.validity = asn1Sccvalid);
                        --  press2_ok := press2_data.ps2.data.validity = valid (377,0)
                        press2_ok := (press2_data.ps2.data.validity = asn1Sccvalid);
                        --  power_ok := power_data.heater2.data.validity = valid (378,0)
                        power_ok := (power_data.heater2.data.validity = asn1Sccvalid);
                        --  DECISION power_ok and
                        --  (placa_abajo_ok or placa_arriba_ok)
                        --  and aire_infinito_ok
                        --  and (press1_ok or press2_ok) (383,0)
                        --  ANSWER true (385,17)
                        if ((((power_ok and (placa_abajo_ok or placa_arriba_ok)) and aire_infinito_ok) and (press1_ok or press2_ok))) = true then
                           --  temp_plate := if placa_arriba_ok then (pt1000s_data.pt1000s.data.celsius(5)) else 0.0 fi (387,25)
                           if placa_arriba_ok then
                              tmp567 := pt1000s_data.pt1000s.data.celsius.Data(6);
                           else
                              tmp567 := 0.0;
                           end if;
                           ctxt.temp_plate := tmp567;
                           --  temp_plate := if placa_abajo_ok then (pt1000s_data.pt1000s.data.celsius(6) + temp_plate) else temp_plate fi (388,0)
                           if placa_abajo_ok then
                              tmp577 := (pt1000s_data.pt1000s.data.celsius.Data(7) + ctxt.temp_plate);
                           else
                              tmp577 := ctxt.temp_plate;
                           end if;
                           ctxt.temp_plate := tmp577;
                           --  temp_plate := if placa_abajo_ok and placa_arriba_ok then temp_plate / 2.0 else temp_plate fi (389,0)
                           if (placa_abajo_ok and placa_arriba_ok) then
                              tmp589 := (ctxt.temp_plate / 2.0);
                           else
                              tmp589 := ctxt.temp_plate;
                           end if;
                           ctxt.temp_plate := tmp589;
                           --  press := if press1_ok then float(press1_data.ps1.data.processed.pressure) /100.0 else 0.0 fi (391,0)
                           if press1_ok then
                              tmp598 := (Asn1Real(press1_data.ps1.data.processed.pressure) / 100.0);
                           else
                              tmp598 := 0.0;
                           end if;
                           ctxt.press := tmp598;
                           --  press := if press2_ok then (float(press2_data.ps2.data.processed.pressure)/100.0 + press) else press fi (392,0)
                           if press2_ok then
                              tmp610 := ((Asn1Real(press2_data.ps2.data.processed.pressure) / 100.0) + ctxt.press);
                           else
                              tmp610 := ctxt.press;
                           end if;
                           ctxt.press := tmp610;
                           --  press := if press1_ok and press2_ok then press / 2.0 else press fi (393,0)
                           if (press1_ok and press2_ok) then
                              tmp624 := (ctxt.press / 2.0);
                           else
                              tmp624 := ctxt.press;
                           end if;
                           ctxt.press := tmp624;
                           --  temp_air := pt1000s_data.pt1000s.data.celsius(2) (395,0)
                           ctxt.temp_air := pt1000s_data.pt1000s.data.celsius.Data(3);
                           --  power := power_data.heater2.data.power_watts (397,0)
                           ctxt.power := power_data.heater2.data.power_watts;
                           --  writeln('temp_plate: ', temp_plate) (399,25)
                           Put ("temp_plate: ");
                           Put (asn1SccT_Float'Image (ctxt.temp_plate));
                           New_Line;
                           --  writeln('power: ', power) (401,25)
                           Put ("power: ");
                           Put (asn1SccT_Float'Image (ctxt.power));
                           New_Line;
                           --  writeln('press: ', press) (403,25)
                           Put ("press: ");
                           Put (asn1SccT_Float'Image (ctxt.press));
                           New_Line;
                           --  writeln('press 2 ok ', press2_ok) (405,25)
                           Put ("press 2 ok ");
                           Put (asn1SccT_Boolean'Image (press2_ok));
                           New_Line;
                           --  writeln('temp_air: ', temp_air) (407,25)
                           Put ("temp_air: ");
                           Put (asn1SccT_Float'Image (ctxt.temp_air));
                           New_Line;
                           --  RETURN True (None,None) at 407, 1318
                           return true;
                           --  ANSWER false (411,17)
                        elsif ((((power_ok and (placa_abajo_ok or placa_arriba_ok)) and aire_infinito_ok) and (press1_ok or press2_ok))) = false then
                           --  writeln('invalid data :-(') (413,25)
                           Put ("invalid data :-(");
                           New_Line;
                           --  RETURN False (None,None) at 1223, 888
                           return false;
                        end if;
                     end p_0_updateData;
                     

                  procedure getCurrentMode(Current_State: in out asn1SccHTL_State) is
                     begin
                        --  Current_State := actual_state (428,17)
                        Current_State := ctxt.actual_state;
                        --  getCurrentMode_Transition (None,None)
                        getCurrentMode_Transition;
                        --  RETURN  (None,None) at 603, 257
                        return;
                     end getCurrentMode;
                     

                  procedure p_0_initF2 is
                     begin
                        --  DECISION f2_started (-1,-1)
                        --  ANSWER true (439,17)
                        if (ctxt.f2_started) = true then
                           --  f2_first_it := false (441,25)
                           ctxt.f2_first_it := false;
                           --  ANSWER false (443,17)
                        elsif (ctxt.f2_started) = false then
                           --  f2_started := true (445,25)
                           ctxt.f2_started := true;
                           --  actual_state := f2 (446,0)
                           ctxt.actual_state := asn1Sccf2;
                           --  DECISION f2_duration_max = -1.0 (448,45)
                           --  ANSWER true (450,25)
                           if (asn1SccT_Double_Equal (ctxt.f2_duration_max, (-1.0))) = true then
                              --  f2_duration_max := htl_time + f2_relative_duration_max (452,33)
                              ctxt.f2_duration_max := (ctxt.htl_time + ctxt.f2_relative_duration_max);
                              --  ANSWER false (454,25)
                           elsif (asn1SccT_Double_Equal (ctxt.f2_duration_max, (-1.0))) = false then
                              null;
                           end if;
                           --  RecordHTLParams(actual_state, f1_duration_max, f2_duration_max, m, n, power_f1) (457,25)
                           RI_0_RecordHTLParams(ctxt.actual_state, ctxt.f1_duration_max, ctxt.f2_duration_max, ctxt.m, ctxt.n, ctxt.power_f1);
                           --  writeln('[initF2] Recorded: ', actual_state) (459,25)
                           Put ("[initF2] Recorded: ");
                           Put (ctxt.actual_state'Img);
                           New_Line;
                        end if;
                        --  RETURN  (None,None) at 285, 574
                        return;
                     end p_0_initF2;
                     

                  procedure p_0_initF1 is
                     begin
                        --  DECISION f1_started (-1,-1)
                        --  ANSWER true (471,17)
                        if (ctxt.f1_started) = true then
                           --  f1_first_it := False (473,25)
                           ctxt.f1_first_it := false;
                           --  ANSWER false (475,17)
                        elsif (ctxt.f1_started) = false then
                           --  f1_started := true (477,25)
                           ctxt.f1_started := true;
                           --  actual_state := f1 (478,0)
                           ctxt.actual_state := asn1Sccf1;
                           --  DECISION f1_duration_max = -1.0 (480,45)
                           --  ANSWER true (482,25)
                           if (asn1SccT_Double_Equal (ctxt.f1_duration_max, (-1.0))) = true then
                              --  f1_duration_max := htl_time + f1_relative_duration_max (484,33)
                              ctxt.f1_duration_max := (ctxt.htl_time + ctxt.f1_relative_duration_max);
                              --  ANSWER false (486,25)
                           elsif (asn1SccT_Double_Equal (ctxt.f1_duration_max, (-1.0))) = false then
                              null;
                           end if;
                           --  RecordHTLParams(actual_state, f1_duration_max, f2_duration_max, m, n, power_f1) (489,25)
                           RI_0_RecordHTLParams(ctxt.actual_state, ctxt.f1_duration_max, ctxt.f2_duration_max, ctxt.m, ctxt.n, ctxt.power_f1);
                           --  writeln('[init f1] Recorded: ', actual_state) (491,25)
                           Put ("[init f1] Recorded: ");
                           Put (ctxt.actual_state'Img);
                           New_Line;
                        end if;
                        --  RETURN  (None,None) at 455, 593
                        return;
                     end p_0_initF1;
                     

                  procedure p_0_initA1 is
                     --  !! stack: _call_external_function line 1604
                     tmp763 : asn1SccT_Double;
                     tmp762 : asn1SccT_Double;
                     begin
                        --  DECISION a1_started (-1,-1)
                        --  ANSWER true (503,17)
                        if (ctxt.a1_started) = true then
                           null;
                           --  ANSWER false (505,17)
                        elsif (ctxt.a1_started) = false then
                           --  a1_started := true (507,25)
                           ctxt.a1_started := true;
                           --  actual_state := a1 (508,0)
                           ctxt.actual_state := asn1Scca1;
                           --  RecordHTLParams(actual_state, -1.0, -1.0, m, n, power_f1) (510,25)
                           tmp762 := (-1.0);
                           tmp763 := (-1.0);
                           RI_0_RecordHTLParams(ctxt.actual_state, tmp762, tmp763, ctxt.m, ctxt.n, ctxt.power_f1);
                        end if;
                        --  RETURN  (None,None) at 409, 316
                        return;
                     end p_0_initA1;
                     

                  procedure p_0_initA2 is
                     --  !! stack: _call_external_function line 1604
                     tmp785 : asn1SccT_Double;
                     tmp784 : asn1SccT_Double;
                     begin
                        --  DECISION a2_started (-1,-1)
                        --  ANSWER true (522,17)
                        if (ctxt.a2_started) = true then
                           null;
                           --  ANSWER false (524,17)
                        elsif (ctxt.a2_started) = false then
                           --  a2_started := true (526,25)
                           ctxt.a2_started := true;
                           --  actual_state := a2 (527,0)
                           ctxt.actual_state := asn1Scca2;
                           --  RecordHTLParams(actual_state, -1.0, -1.0, m, n, power_f1) (529,25)
                           tmp784 := (-1.0);
                           tmp785 := (-1.0);
                           RI_0_RecordHTLParams(ctxt.actual_state, tmp784, tmp785, ctxt.m, ctxt.n, ctxt.power_f1);
                        end if;
                        --  RETURN  (None,None) at 507, 325
                        return;
                     end p_0_initA2;
                     

                  procedure setCurrentMode(current_state: in out asn1SccHTL_State) is
                     begin
                        case ctxt.state is
                           when asn1Sccf3 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (10);
                           when asn1Sccinit =>
                              Execute_Transition (CS_Only);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (16);
                           when asn1Sccf1 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (14);
                           when asn1Sccf2 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (12);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Scca2 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (18);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end setCurrentMode;
                     

                  procedure tick is
                     begin
                        case ctxt.state is
                           when asn1Sccf3 =>
                              Execute_Transition (9);
                           when asn1Sccinit =>
                              Execute_Transition (1);
                           when asn1Sccerror =>
                              Execute_Transition (8);
                           when asn1Scca1 =>
                              Execute_Transition (15);
                           when asn1Sccf1 =>
                              Execute_Transition (13);
                           when asn1Sccf2 =>
                              Execute_Transition (11);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Scca2 =>
                              Execute_Transition (17);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end tick;
                     

                  procedure configureParameters_Transition is
                     begin
                        case ctxt.state is
                           when asn1Sccf3 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccinit =>
                              Execute_Transition (CS_Only);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf2 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Scca2 =>
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
                           when asn1Sccinit =>
                              Execute_Transition (CS_Only);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf2 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Scca2 =>
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
                                 --  NEXT_STATE Init (537,18) at 663, 127
                                 trId := -1;
                                 ctxt.State := asn1SccInit;
                                 goto Next_Transition;
                              when 1 =>
                                 --  RecoverHTLParams(actual_state, f1_duration_max, f2_duration_max, m, n, power_f1) (543,17)
                                 RI_0_RecoverHTLParams(ctxt.actual_state, ctxt.f1_duration_max, ctxt.f2_duration_max, ctxt.m, ctxt.n, ctxt.power_f1);
                                 --  writeln('Actual State: ', actual_state) (545,17)
                                 Put ("Actual State: ");
                                 Put (ctxt.actual_state'Img);
                                 New_Line;
                                 --  writeln('F1 max time', f1_duration_max) (547,17)
                                 Put ("F1 max time");
                                 Put (asn1SccT_Double'Image (ctxt.f1_duration_max));
                                 New_Line;
                                 --  writeln('F2 max time', f2_duration_max) (549,17)
                                 Put ("F2 max time");
                                 Put (asn1SccT_Double'Image (ctxt.f2_duration_max));
                                 New_Line;
                                 --  NEXT_STATE selectstate (551,22) at 655, 508
                                 trId := -1;
                                 ctxt.State := asn1Sccselectstate;
                                 goto Next_Transition;
                              when 2 =>
                                 --  NEXT_STATE F2 (558,22) at 1076, 1065
                                 trId := -1;
                                 ctxt.State := asn1SccF2;
                                 goto Next_Transition;
                              when 3 =>
                                 --  NEXT_STATE A1 (562,22) at 820, 1060
                                 trId := -1;
                                 ctxt.State := asn1SccA1;
                                 goto Next_Transition;
                              when 4 =>
                                 --  NEXT_STATE A2 (566,22) at 537, 1060
                                 trId := -1;
                                 ctxt.State := asn1SccA2;
                                 goto Next_Transition;
                              when 5 =>
                                 --  NEXT_STATE F1 (570,22) at 686, 1065
                                 trId := -1;
                                 ctxt.State := asn1SccF1;
                                 goto Next_Transition;
                              when 6 =>
                                 --  NEXT_STATE F3 (574,22) at 945, 1063
                                 trId := -1;
                                 ctxt.State := asn1SccF3;
                                 goto Next_Transition;
                              when 7 =>
                                 --  NEXT_STATE Error (578,22) at 1217, 1065
                                 trId := -1;
                                 ctxt.State := asn1SccError;
                                 goto Next_Transition;
                              when 8 =>
                                 --  ok := call updateData (585,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  actual_state := error (586,0)
                                 ctxt.actual_state := asn1Sccerror;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (590,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION last_good_state (-1,-1)
                                    --  ANSWER a1 (594,25)
                                    if (ctxt.last_good_state) = asn1Scca1 then
                                       --  NEXT_STATE A1 (596,38) at 2332, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccA1;
                                       goto Next_Transition;
                                       --  ANSWER a2 (598,25)
                                    elsif (ctxt.last_good_state) = asn1Scca2 then
                                       --  NEXT_STATE A2 (600,38) at 2422, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccA2;
                                       goto Next_Transition;
                                       --  ANSWER f1 (602,25)
                                    elsif (ctxt.last_good_state) = asn1Sccf1 then
                                       --  NEXT_STATE F1 (604,38) at 2512, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccF1;
                                       goto Next_Transition;
                                       --  ANSWER f2 (606,25)
                                    elsif (ctxt.last_good_state) = asn1Sccf2 then
                                       --  NEXT_STATE F2 (608,38) at 2602, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccF2;
                                       goto Next_Transition;
                                       --  ANSWER else (None,None)
                                    else
                                       --  NEXT_STATE Error (612,38) at 2692, 1362
                                       trId := -1;
                                       ctxt.State := asn1SccError;
                                       goto Next_Transition;
                                    end if;
                                    --  ANSWER false (615,17)
                                 elsif (ctxt.ok) = false then
                                    --  NEXT_STATE Error (617,30) at 2773, 1243
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 9 =>
                                 --  actual_state := f3 (625,17)
                                 ctxt.actual_state := asn1Sccf3;
                                 --  doF3 (627,17)
                                 p_0_doF3;
                                 --  kickTheDog (629,17)
                                 RI_0_KickTheDog;
                                 --  NEXT_STATE F3 (631,22) at 2194, 1228
                                 trId := -1;
                                 ctxt.State := asn1SccF3;
                                 goto Next_Transition;
                              when 10 =>
                                 --  NEXT_STATE Selectstate (635,22) at 2359, 1063
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 11 =>
                                 --  initf2 (642,17)
                                 p_0_initF2;
                                 --  kickTheDog (644,17)
                                 RI_0_KickTheDog;
                                 --  ok := call updateData (646,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (650,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (652,35)
                                    --  ANSWER True (654,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  NEXT_STATE F3 (656,38) at 1797, 1434
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (658,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       --  DECISION htl_time >= f2_duration_max (660,46)
                                       --  ANSWER true (662,33)
                                       if ((ctxt.htl_time >= ctxt.f2_duration_max)) = true then
                                          --  NEXT_STATE F3 (664,46) at 1513, 1570
                                          --  COMMENT time in F3 is bigger
                                          --  than the allowed. (666,36)
                                          trId := -1;
                                          ctxt.State := asn1SccF3;
                                          goto Next_Transition;
                                          --  ANSWER false (669,33)
                                       elsif ((ctxt.htl_time >= ctxt.f2_duration_max)) = false then
                                          --  doF2 (671,41)
                                          p_0_doF2;
                                          --  NEXT_STATE F2 (673,46) at 1623, 1622
                                          trId := -1;
                                          ctxt.State := asn1SccF2;
                                          goto Next_Transition;
                                       end if;
                                    end if;
                                    --  ANSWER false (677,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state:=actual_state (679,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (681,30) at 1259, 1375
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 12 =>
                                 --  NEXT_STATE Selectstate (686,22) at 1944, 1057
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 13 =>
                                 --  initf1 (693,17)
                                 p_0_initF1;
                                 --  kickTheDog (695,17)
                                 RI_0_KickTheDog;
                                 --  ok := call updateData (697,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (701,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (703,35)
                                    --  ANSWER True (705,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  NEXT_STATE F3 (707,38) at 2935, 588
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (709,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       --  DECISION htl_time >= f1_duration_max (711,46)
                                       --  ANSWER true (713,33)
                                       if ((ctxt.htl_time >= ctxt.f1_duration_max)) = true then
                                          --  NEXT_STATE F2 (715,46) at 2640, 735
                                          trId := -1;
                                          ctxt.State := asn1SccF2;
                                          goto Next_Transition;
                                          --  ANSWER false (717,33)
                                       elsif ((ctxt.htl_time >= ctxt.f1_duration_max)) = false then
                                          --  doF1 (719,41)
                                          p_0_doF1;
                                          --  NEXT_STATE F1 (721,46) at 2730, 790
                                          trId := -1;
                                          ctxt.State := asn1SccF1;
                                          goto Next_Transition;
                                       end if;
                                    end if;
                                    --  ANSWER false (725,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (727,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (729,30) at 2460, 512
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 14 =>
                                 --  NEXT_STATE Selectstate (734,22) at 3072, 192
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 15 =>
                                 --  initA1 (741,17)
                                 p_0_initA1;
                                 --  KickTheDog (743,17)
                                 RI_0_KickTheDog;
                                 --  ok := call updateData (745,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (749,17)
                                 if (ctxt.ok) = true then
                                    null;
                                    --  ANSWER false (751,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (753,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (755,30) at 938, 510
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                                 --  DECISION (press <= press_10km and
                                 --  htl_time >= a1_duration_emergency) or
                                 --  htl_time >= a1_duration_max (759,35)
                                 --  ANSWER false (762,17)
                                 if ((((ctxt.press <= ctxt.press_10km) and (ctxt.htl_time >= ctxt.a1_duration_emergency)) or (ctxt.htl_time >= ctxt.a1_duration_max))) = false then
                                    --  doA1 (764,25)
                                    p_0_doA1;
                                    --  NEXT_STATE A1 (766,30) at 1014, 787
                                    trId := -1;
                                    ctxt.State := asn1SccA1;
                                    goto Next_Transition;
                                    --  ANSWER true (768,17)
                                 elsif ((((ctxt.press <= ctxt.press_10km) and (ctxt.htl_time >= ctxt.a1_duration_emergency)) or (ctxt.htl_time >= ctxt.a1_duration_max))) = true then
                                    --  NEXT_STATE A2 (770,30) at 1104, 737
                                    trId := -1;
                                    ctxt.State := asn1SccA2;
                                    goto Next_Transition;
                                 end if;
                              when 16 =>
                                 --  NEXT_STATE Selectstate (775,22) at 1373, 186
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 17 =>
                                 --  InitA2 (782,17)
                                 p_0_initA2;
                                 --  kickTheDog (784,17)
                                 RI_0_KickTheDog;
                                 --  ok := call updateData (786,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (790,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (792,35)
                                    --  COMMENT no estamos cayendo? (794,20)
                                    --  ANSWER True (796,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  writeln('Nos estamos cayendo') (798,33)
                                       Put ("Nos estamos cayendo");
                                       New_Line;
                                       --  NEXT_STATE F3 (800,38) at 1798, 631
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (802,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       null;
                                    end if;
                                    --  ANSWER false (805,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (807,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (809,30) at 2027, 501
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                                 --  DECISION htl_time >= a2_duration_max
                                 --  or press <= press_18km (813,0)
                                 --  ANSWER false (815,17)
                                 if (((ctxt.htl_time >= ctxt.a2_duration_max) or (ctxt.press <= ctxt.press_18km))) = false then
                                    --  doA2 (817,25)
                                    p_0_doA2;
                                    --  NEXT_STATE A2 (819,30) at 1542, 896
                                    trId := -1;
                                    ctxt.State := asn1SccA2;
                                    goto Next_Transition;
                                    --  ANSWER true (821,17)
                                 elsif (((ctxt.htl_time >= ctxt.a2_duration_max) or (ctxt.press <= ctxt.press_18km))) = true then
                                    --  writeln('A2 max duration: ', a2_duration_max) (823,25)
                                    Put ("A2 max duration: ");
                                    Put (asn1SccT_Double'Image (ctxt.a2_duration_max));
                                    New_Line;
                                    --  NEXT_STATE F1 (825,30) at 1734, 901
                                    trId := -1;
                                    ctxt.State := asn1SccF1;
                                    goto Next_Transition;
                                 end if;
                              when 18 =>
                                 --  NEXT_STATE Selectstate (830,22) at 2230, 182
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
                              --  DECISION actual_state = f2 (556,30)
                              --  ANSWER true (None,None)
                              if ((ctxt.actual_state = asn1Sccf2)) = true then
                                 trId := 2;
                                 --  Priority 1
                                 --  DECISION actual_state = a1 (560,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Scca1)) = true then
                                 trId := 3;
                                 --  Priority 1
                                 --  DECISION actual_state = a2 (564,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Scca2)) = true then
                                 trId := 4;
                                 --  Priority 1
                                 --  DECISION actual_state = f1 (568,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccf1)) = true then
                                 trId := 5;
                                 --  Priority 1
                                 --  DECISION actual_state = f3 (572,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccf3)) = true then
                                 trId := 6;
                                 --  Priority 1
                                 --  DECISION actual_state = error (576,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccerror)) = true then
                                 trId := 7;
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