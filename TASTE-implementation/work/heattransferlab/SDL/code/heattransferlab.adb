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
      tmp210 : asn1SccT_Float;
      --  !! stack: _call_external_function line 1604
      begin
         --  writeln('[HTL] Actual mode: Secure F3') (56,17)
         Put ("[HTL] Actual mode: Secure F3");
         New_Line;
         --  DECISION system_stopped (-1,-1)
         --  ANSWER true (60,17)
         if (ctxt.system_stopped) = true then
            --  RETURN  (None,None) at 669, 288
            return;
            --  ANSWER false (64,17)
         elsif (ctxt.system_stopped) = false then
            null;
         end if;
         --  ok := call updateData (67,17)
         ctxt.ok := p_0_updatedata;
         --  DECISION ok and power = 0.0 (69,24)
         --  ANSWER true (71,17)
         if ((ctxt.ok and asn1SccT_Float_Equal (ctxt.power, 0.0))) = true then
            --  system_stopped := true (73,25)
            ctxt.system_stopped := true;
            --  stopSystem (75,25)
            RI_0_StopSystem;
            --  ANSWER false (77,17)
         elsif ((ctxt.ok and asn1SccT_Float_Equal (ctxt.power, 0.0))) = false then
            --  setPowerH2(0.0) (79,25)
            tmp210 := 0.0;
            RI_0_setPowerH2(tmp210);
         end if;
         --  RETURN  (None,None) at 354, 651
         return;
      end p_0_doF3;
      

   procedure p_0_doF2 is
      begin
         --  DECISION (not f2_first_it) and power = 0.0 (89,39)
         --  ANSWER false (91,17)
         if (((not ctxt.f2_first_it) and asn1SccT_Float_Equal (ctxt.power, 0.0))) = false then
            --  writeln('[HTL] Actual mode: Normal F2') (93,25)
            Put ("[HTL] Actual mode: Normal F2");
            New_Line;
            --  ANSWER true (95,17)
         elsif (((not ctxt.f2_first_it) and asn1SccT_Float_Equal (ctxt.power, 0.0))) = true then
            --  writeln('[HTL] Actual mode: Secure F2') (97,25)
            Put ("[HTL] Actual mode: Secure F2");
            New_Line;
            --  DECISION temp_plate <= 55.0 and
            --  abs(temp_plate - temp_air) <= 50.0 (99,48)
            --  ANSWER true (102,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               --  m := m+0.1 (104,33)
               ctxt.m := (ctxt.m + 0.1);
               --  RecordHTLParams(actual_state, f1_duration_max, f2_duration_max, m, n, power_f1) (106,33)
               --  COMMENT m was modified, so it needs to
               --  be recorded (108,28)
               RI_0_RecordHTLParams(ctxt.actual_state, ctxt.f1_duration_max, ctxt.f2_duration_max, ctxt.m, ctxt.n, ctxt.power_f1);
               --  ANSWER false (111,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 833, 405
               return;
            end if;
         end if;
         --  DECISION temp_plate >= 65.0 or 
         --  abs (temp_plate - temp_air) >= 60.0 (117,40)
         --  COMMENT >= 60? (120,12)
         --  ANSWER true (122,17)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (124,25)
            ctxt.power := 0.0;
            --  ANSWER false (126,17)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := power_f1/2.0 - m*0.1 (128,25)
            ctxt.power := ((ctxt.power_f1 / 2.0) - (ctxt.m * 0.1));
            --  DECISION power <= 0.1 (130,35)
            --  ANSWER true (132,25)
            if ((ctxt.power <= 0.1)) = true then
               --  power := 0.1 (134,33)
               ctxt.power := 0.1;
               --  ANSWER false (136,25)
            elsif ((ctxt.power <= 0.1)) = false then
               null;
            end if;
         end if;
         --  setPowerH2(power) (140,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 453, 954
         return;
      end p_0_doF2;
      

   procedure p_0_doA2 is
      begin
         --  DECISION power = 0.0 (149,27)
         --  ANSWER false (151,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            --  writeln('[HTL] Actual mode: Normal A2') (153,25)
            Put ("[HTL] Actual mode: Normal A2");
            New_Line;
            --  JOIN normalA2 (None,None) at None, None
            goto normalA2;
            --  ANSWER true (171,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  writeln('[HTL] Actual mode: Secure A2') (173,25)
            Put ("[HTL] Actual mode: Secure A2");
            New_Line;
            --  DECISION temp_plate <= 55.0 and
            --  abs(temp_plate - temp_air) <= 50.0 (175,48)
            --  COMMENT Pdiss = 0.0 W (178,20)
            --  ANSWER true (180,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               --  JOIN normalA2 (182,33) at 757, 409
               goto normalA2;
               --  ANSWER false (184,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 861, 411
               return;
            end if;
         end if;
         --  setPowerH2(power) (190,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 435, 576
         return;
         --  CONNECTION normalA2 (155,20)
         <<normalA2>>
         --  DECISION temp_plate >= 65.0 or
         --  abs(temp_plate - temp_air) >= 60.0 (157,48)
         --  COMMENT Pdiss = 1.0 (160,20)
         --  ANSWER false (162,25)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := power_a2 (164,33)
            ctxt.power := ctxt.power_a2;
            --  ANSWER true (166,25)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (168,33)
            ctxt.power := 0.0;
         end if;
         --  setPowerH2(power) (190,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 435, 576
         return;
      end p_0_doA2;
      

   procedure p_0_doA1 is
      begin
         --  DECISION power = 0.0 (199,27)
         --  ANSWER false (201,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            --  writeln('[HTL] Mode: Normal A1.') (203,25)
            Put ("[HTL] Mode: Normal A1.");
            New_Line;
            --  ANSWER true (205,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  writeln('[HTL] Mode: Secure A1.') (207,25)
            Put ("[HTL] Mode: Secure A1.");
            New_Line;
            --  DECISION temp_plate <= 55.0 and abs(temp_plate -temp_air) <= 50.0 (209,48)
            --  ANSWER true (211,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               null;
               --  ANSWER false (213,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 983, 368
               return;
            end if;
         end if;
         --  DECISION temp_plate >= 65.0 or abs(temp_plate - temp_air) >= 60.0 (219,40)
         --  ANSWER true (221,17)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (223,25)
            ctxt.power := 0.0;
            --  ANSWER false (225,17)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := 0.8 (227,25)
            ctxt.power := 0.8;
         end if;
         --  setPowerH2(power) (230,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 518, 707
         return;
      end p_0_doA1;
      

   procedure p_0_doF1 is
      begin
         --  DECISION (not f1_first_it) and power = 0.0 (239,39)
         --  ANSWER true (241,17)
         if (((not ctxt.f1_first_it) and asn1SccT_Float_Equal (ctxt.power, 0.0))) = true then
            --  writeln('[HTL] Actual mode: Secure F1') (243,25)
            Put ("[HTL] Actual mode: Secure F1");
            New_Line;
            --  DECISION temp_plate <= 55.0 and
            --  abs(temp_plate - temp_air) <= 50.0 (245,48)
            --  ANSWER true (248,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               --  COMMENT n will be recorded at the end
               --  of the procedure execution (252,28)
               --  n := n+1.0 (250,33)
               ctxt.n := (ctxt.n + 1.0);
               --  JOIN normalF1 (255,33) at 820, 515
               goto normalF1;
               --  ANSWER false (257,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 1164, 465
               return;
            end if;
            --  ANSWER false (262,17)
         elsif (((not ctxt.f1_first_it) and asn1SccT_Float_Equal (ctxt.power, 0.0))) = false then
            --  writeln('[HTL] Actual mode: Normal F1') (264,25)
            Put ("[HTL] Actual mode: Normal F1");
            New_Line;
            --  JOIN normalF1 (None,None) at None, None
            goto normalF1;
         end if;
         --  CONNECTION normalF1 (266,20)
         <<normalF1>>
         --  DECISION temp_plate >= 65.0 or
         --  abs(temp_plate - temp_air) >= 60.0 (268,48)
         --  ANSWER true (271,25)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (273,33)
            ctxt.power := 0.0;
            --  ANSWER false (275,25)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := power_a2-n*0.1 (277,33)
            ctxt.power := (ctxt.power_a2 - (ctxt.n * 0.1));
            --  DECISION power <= 0.1 (279,43)
            --  ANSWER true (281,33)
            if ((ctxt.power <= 0.1)) = true then
               --  power := 0.1 (283,41)
               ctxt.power := 0.1;
               --  ANSWER false (285,33)
            elsif ((ctxt.power <= 0.1)) = false then
               null;
            end if;
            --  power_f1 := power (288,33)
            ctxt.power_f1 := ctxt.power;
         end if;
         --  setPowerH2(power) (291,25)
         RI_0_setPowerH2(ctxt.power);
         --  RecordHTLParams(actual_state, f1_duration_max, f2_duration_max, m, n, power_f1) (293,25)
         --  COMMENT power was modified,
         --   so it needs to be recorded (295,20)
         RI_0_RecordHTLParams(ctxt.actual_state, ctxt.f1_duration_max, ctxt.f2_duration_max, ctxt.m, ctxt.n, ctxt.power_f1);
         --  RETURN  (None,None) at 388, 858
         return;
      end p_0_doF1;
      

   procedure configureParameters(Configuration: in out asn1SccHTL_Config) is
      tmp454 : asn1SccT_Float;
      tmp504 : asn1SccT_Double;
      tmp496 : asn1SccT_Double;
      tmp446 : asn1SccT_Float;
      tmp462 : asn1SccT_Float;
      tmp470 : asn1SccT_Double;
      tmp488 : asn1SccT_Double;
      tmp479 : asn1SccT_Double;
      begin
         --  press_5km  := if exist (Configuration.press_5km) then Configuration.press_5km else press_5km fi (312,17)
         if (Configuration.exist.press_5km = 1) then
            tmp446 := Configuration.press_5km;
         else
            tmp446 := ctxt.press_5km;
         end if;
         ctxt.press_5km := tmp446;
         --  press_10km := if exist(Configuration.press_10km) then Configuration.press_10km else press_10km fi (313,0)
         if (Configuration.exist.press_10km = 1) then
            tmp454 := Configuration.press_10km;
         else
            tmp454 := ctxt.press_10km;
         end if;
         ctxt.press_10km := tmp454;
         --  press_18km := if exist(Configuration.press_18km) then Configuration.press_18km else press_18km fi (314,0)
         if (Configuration.exist.press_18km = 1) then
            tmp462 := Configuration.press_18km;
         else
            tmp462 := ctxt.press_18km;
         end if;
         ctxt.press_18km := tmp462;
         --  f1_relative_duration_max :=
         --   if exist(Configuration.f1_duration_secs) then
            --     float (Configuration.f1_duration_secs)
            --  else
            --    f1_relative_duration_max
            --  fi (316,0)
            if (Configuration.exist.f1_duration_secs = 1) then
               tmp470 := Asn1Real(Configuration.f1_duration_secs);
            else
               tmp470 := ctxt.f1_relative_duration_max;
            end if;
            ctxt.f1_relative_duration_max := tmp470;
            --  f2_relative_duration_max :=
            --  if exist(Configuration.f2_duration_secs) then
               --    float(Configuration.f2_duration_secs)
               --  else
               --    f2_relative_duration_max
               --  fi (323,0)
               if (Configuration.exist.f2_duration_secs = 1) then
                  tmp479 := Asn1Real(Configuration.f2_duration_secs);
               else
                  tmp479 := ctxt.f2_relative_duration_max;
               end if;
               ctxt.f2_relative_duration_max := tmp479;
               --  a1_duration_emergency :=
               --  if exist(Configuration.a1_duration_emergency_secs) then
                  --    Configuration.a1_duration_emergency_secs
                  --  else
                  --    a1_duration_emergency
                  --  fi (330,0)
                  if (Configuration.exist.a1_duration_emergency_secs = 1) then
                     tmp488 := Configuration.a1_duration_emergency_secs;
                  else
                     tmp488 := ctxt.a1_duration_emergency;
                  end if;
                  ctxt.a1_duration_emergency := tmp488;
                  --  a1_duration_max :=
                  --  if exist(Configuration.a1_duration_max_secs) then
                     --    Configuration.a1_duration_max_secs
                     --  else
                     --    a1_duration_max
                     --  fi (337,0)
                     if (Configuration.exist.a1_duration_max_secs = 1) then
                        tmp496 := Configuration.a1_duration_max_secs;
                     else
                        tmp496 := ctxt.a1_duration_max;
                     end if;
                     ctxt.a1_duration_max := tmp496;
                     --  a2_duration_max :=
                     --  if exist(Configuration.a2_duration_max_secs) then
                        --    Configuration.a2_duration_max_secs
                        --  else
                        --    a2_duration_max
                        --  fi (344,0)
                        if (Configuration.exist.a2_duration_max_secs = 1) then
                           tmp504 := Configuration.a2_duration_max_secs;
                        else
                           tmp504 := ctxt.a2_duration_max;
                        end if;
                        ctxt.a2_duration_max := tmp504;
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
                     tmp656 : asn1SccT_Float;
                     tmp630 : asn1SccT_Float;
                     --  !! stack: _call_external_function line 1604
                     tmp642 : asn1SccT_Float;
                     tmp525 : asn1SccOBSW_DP_Filter;
                     tmp621 : asn1SccT_Float;
                     tmp517 : asn1SccOBSW_DP_Filter;
                     tmp521 : asn1SccOBSW_DP_Filter;
                     tmp529 : asn1SccOBSW_DP_Filter;
                     tmp599 : asn1SccT_Float;
                     tmp609 : asn1SccT_Float;
                     begin
                        --  getTime(gps_time, htl_time) (375,17)
                        RI_0_getTime(gps_time, ctxt.htl_time);
                        --  retreiveSingleData(pt1000s,pt1000s_data) (377,17)
                        tmp517 := asn1Sccpt1000s;
                        RI_0_RetreiveSingleData(tmp517, pt1000s_data);
                        --  retreiveSingleData(ps1, press1_data) (379,17)
                        tmp521 := asn1Sccps1;
                        RI_0_RetreiveSingleData(tmp521, press1_data);
                        --  retreiveSingleData(ps2, press2_data) (381,17)
                        tmp525 := asn1Sccps2;
                        RI_0_RetreiveSingleData(tmp525, press2_data);
                        --  retreiveSingleData(heater2, power_data) (383,17)
                        tmp529 := asn1Sccheater2;
                        RI_0_RetreiveSingleData(tmp529, power_data);
                        --  temp_air := 0.0 (385,17)
                        ctxt.temp_air := 0.0;
                        --  temp_plate := 0.0 (386,0)
                        ctxt.temp_plate := 0.0;
                        --  press := 0.0 (387,0)
                        ctxt.press := 0.0;
                        --  placa_abajo_ok := pt1000s_data.pt1000s.data.validity(6) = valid (389,0)
                        placa_abajo_ok := (pt1000s_data.pt1000s.data.validity.Data(7) = asn1Sccvalid);
                        --  placa_arriba_ok := pt1000s_data.pt1000s.data.validity(5) = valid (390,0)
                        placa_arriba_ok := (pt1000s_data.pt1000s.data.validity.Data(6) = asn1Sccvalid);
                        --  aire_infinito_ok := pt1000s_data.pt1000s.data.validity(2) = valid (391,0)
                        aire_infinito_ok := (pt1000s_data.pt1000s.data.validity.Data(3) = asn1Sccvalid);
                        --  press1_ok := press1_data.ps1.data.validity = valid (392,0)
                        press1_ok := (press1_data.ps1.data.validity = asn1Sccvalid);
                        --  press2_ok := press2_data.ps2.data.validity = valid (393,0)
                        press2_ok := (press2_data.ps2.data.validity = asn1Sccvalid);
                        --  power_ok := power_data.heater2.data.validity = valid (394,0)
                        power_ok := (power_data.heater2.data.validity = asn1Sccvalid);
                        --  DECISION power_ok and
                        --  (placa_abajo_ok or placa_arriba_ok)
                        --  and aire_infinito_ok
                        --  and (press1_ok or press2_ok) (399,0)
                        --  ANSWER true (401,17)
                        if ((((power_ok and (placa_abajo_ok or placa_arriba_ok)) and aire_infinito_ok) and (press1_ok or press2_ok))) = true then
                           --  temp_plate := if placa_arriba_ok then (pt1000s_data.pt1000s.data.celsius(5)) else 0.0 fi (403,25)
                           if placa_arriba_ok then
                              tmp599 := pt1000s_data.pt1000s.data.celsius.Data(6);
                           else
                              tmp599 := 0.0;
                           end if;
                           ctxt.temp_plate := tmp599;
                           --  temp_plate := if placa_abajo_ok then (pt1000s_data.pt1000s.data.celsius(6) + temp_plate) else temp_plate fi (404,0)
                           if placa_abajo_ok then
                              tmp609 := (pt1000s_data.pt1000s.data.celsius.Data(7) + ctxt.temp_plate);
                           else
                              tmp609 := ctxt.temp_plate;
                           end if;
                           ctxt.temp_plate := tmp609;
                           --  temp_plate := if placa_abajo_ok and placa_arriba_ok then temp_plate / 2.0 else temp_plate fi (405,0)
                           if (placa_abajo_ok and placa_arriba_ok) then
                              tmp621 := (ctxt.temp_plate / 2.0);
                           else
                              tmp621 := ctxt.temp_plate;
                           end if;
                           ctxt.temp_plate := tmp621;
                           --  press := if press1_ok then float(press1_data.ps1.data.processed.pressure) /100.0 else 0.0 fi (407,0)
                           if press1_ok then
                              tmp630 := (Asn1Real(press1_data.ps1.data.processed.pressure) / 100.0);
                           else
                              tmp630 := 0.0;
                           end if;
                           ctxt.press := tmp630;
                           --  press := if press2_ok then (float(press2_data.ps2.data.processed.pressure)/100.0 + press) else press fi (408,0)
                           if press2_ok then
                              tmp642 := ((Asn1Real(press2_data.ps2.data.processed.pressure) / 100.0) + ctxt.press);
                           else
                              tmp642 := ctxt.press;
                           end if;
                           ctxt.press := tmp642;
                           --  press := if press1_ok and press2_ok then press / 2.0 else press fi (409,0)
                           if (press1_ok and press2_ok) then
                              tmp656 := (ctxt.press / 2.0);
                           else
                              tmp656 := ctxt.press;
                           end if;
                           ctxt.press := tmp656;
                           --  temp_air := pt1000s_data.pt1000s.data.celsius(2) (411,0)
                           ctxt.temp_air := pt1000s_data.pt1000s.data.celsius.Data(3);
                           --  power := power_data.heater2.data.power_watts (413,0)
                           ctxt.power := power_data.heater2.data.power_watts;
                           --  writeln('[HTL] temp. of plate: ', temp_plate, ' Celsius deg.') (415,25)
                           Put ("[HTL] temp. of plate: ");
                           Put (asn1SccT_Float'Image (ctxt.temp_plate));
                           Put (" Celsius deg.");
                           New_Line;
                           --  writeln('[HTL] temp. of air: ', temp_air, ' Celsius deg.') (417,25)
                           Put ("[HTL] temp. of air: ");
                           Put (asn1SccT_Float'Image (ctxt.temp_air));
                           Put (" Celsius deg.");
                           New_Line;
                           --  writeln('[HTL] power in plate: ', power, ' watts') (419,25)
                           Put ("[HTL] power in plate: ");
                           Put (asn1SccT_Float'Image (ctxt.power));
                           Put (" watts");
                           New_Line;
                           --  writeln('[HTL] pressure: ', press, ' mbar') (421,25)
                           Put ("[HTL] pressure: ");
                           Put (asn1SccT_Float'Image (ctxt.press));
                           Put (" mbar");
                           New_Line;
                           --  RETURN True (None,None) at 407, 1263
                           return true;
                           --  ANSWER false (425,17)
                        elsif ((((power_ok and (placa_abajo_ok or placa_arriba_ok)) and aire_infinito_ok) and (press1_ok or press2_ok))) = false then
                           --  writeln('[HTL] INVALID DATA') (427,25)
                           Put ("[HTL] INVALID DATA");
                           New_Line;
                           --  RETURN False (None,None) at 1223, 888
                           return false;
                        end if;
                     end p_0_updateData;
                     

                  procedure getCurrentMode(Current_State: in out asn1SccHTL_State) is
                     begin
                        --  Current_State := actual_state (442,17)
                        Current_State := ctxt.actual_state;
                        --  getCurrentMode_Transition (None,None)
                        getCurrentMode_Transition;
                        --  RETURN  (None,None) at 603, 257
                        return;
                     end getCurrentMode;
                     

                  procedure p_0_initF2 is
                     begin
                        --  DECISION f2_started (-1,-1)
                        --  ANSWER true (453,17)
                        if (ctxt.f2_started) = true then
                           --  f2_first_it := false (455,25)
                           ctxt.f2_first_it := false;
                           --  ANSWER false (457,17)
                        elsif (ctxt.f2_started) = false then
                           --  f2_started := true (459,25)
                           ctxt.f2_started := true;
                           --  actual_state := f2 (460,0)
                           ctxt.actual_state := asn1Sccf2;
                           --  DECISION f2_duration_max = -1.0 (462,45)
                           --  ANSWER true (464,25)
                           if (asn1SccT_Double_Equal (ctxt.f2_duration_max, (-1.0))) = true then
                              --  f2_duration_max := htl_time + f2_relative_duration_max (466,33)
                              ctxt.f2_duration_max := (ctxt.htl_time + ctxt.f2_relative_duration_max);
                              --  ANSWER false (468,25)
                           elsif (asn1SccT_Double_Equal (ctxt.f2_duration_max, (-1.0))) = false then
                              null;
                           end if;
                           --  RecordHTLParams(actual_state, f1_duration_max, f2_duration_max, m, n, power_f1) (471,25)
                           RI_0_RecordHTLParams(ctxt.actual_state, ctxt.f1_duration_max, ctxt.f2_duration_max, ctxt.m, ctxt.n, ctxt.power_f1);
                           --  writeln('[initF2] Recorded: ', actual_state) (473,25)
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
                        --  ANSWER true (485,17)
                        if (ctxt.f1_started) = true then
                           --  f1_first_it := False (487,25)
                           ctxt.f1_first_it := false;
                           --  ANSWER false (489,17)
                        elsif (ctxt.f1_started) = false then
                           --  f1_started := true (491,25)
                           ctxt.f1_started := true;
                           --  actual_state := f1 (492,0)
                           ctxt.actual_state := asn1Sccf1;
                           --  DECISION f1_duration_max = -1.0 (494,45)
                           --  ANSWER true (496,25)
                           if (asn1SccT_Double_Equal (ctxt.f1_duration_max, (-1.0))) = true then
                              --  f1_duration_max := htl_time + f1_relative_duration_max (498,33)
                              ctxt.f1_duration_max := (ctxt.htl_time + ctxt.f1_relative_duration_max);
                              --  ANSWER false (500,25)
                           elsif (asn1SccT_Double_Equal (ctxt.f1_duration_max, (-1.0))) = false then
                              null;
                           end if;
                           --  RecordHTLParams(actual_state, f1_duration_max, f2_duration_max, m, n, power_f1) (503,25)
                           RI_0_RecordHTLParams(ctxt.actual_state, ctxt.f1_duration_max, ctxt.f2_duration_max, ctxt.m, ctxt.n, ctxt.power_f1);
                           --  writeln('[init f1] Recorded: ', actual_state) (505,25)
                           Put ("[init f1] Recorded: ");
                           Put (ctxt.actual_state'Img);
                           New_Line;
                        end if;
                        --  RETURN  (None,None) at 455, 593
                        return;
                     end p_0_initF1;
                     

                  procedure p_0_initA1 is
                     tmp799 : asn1SccT_Double;
                     tmp798 : asn1SccT_Double;
                     --  !! stack: _call_external_function line 1604
                     begin
                        --  DECISION a1_started (-1,-1)
                        --  ANSWER true (517,17)
                        if (ctxt.a1_started) = true then
                           null;
                           --  ANSWER false (519,17)
                        elsif (ctxt.a1_started) = false then
                           --  a1_started := true (521,25)
                           ctxt.a1_started := true;
                           --  actual_state := a1 (522,0)
                           ctxt.actual_state := asn1Scca1;
                           --  RecordHTLParams(actual_state, -1.0, -1.0, m, n, power_f1) (524,25)
                           tmp798 := (-1.0);
                           tmp799 := (-1.0);
                           RI_0_RecordHTLParams(ctxt.actual_state, tmp798, tmp799, ctxt.m, ctxt.n, ctxt.power_f1);
                        end if;
                        --  RETURN  (None,None) at 409, 316
                        return;
                     end p_0_initA1;
                     

                  procedure p_0_initA2 is
                     tmp820 : asn1SccT_Double;
                     tmp821 : asn1SccT_Double;
                     --  !! stack: _call_external_function line 1604
                     begin
                        --  DECISION a2_started (-1,-1)
                        --  ANSWER true (536,17)
                        if (ctxt.a2_started) = true then
                           null;
                           --  ANSWER false (538,17)
                        elsif (ctxt.a2_started) = false then
                           --  a2_started := true (540,25)
                           ctxt.a2_started := true;
                           --  actual_state := a2 (541,0)
                           ctxt.actual_state := asn1Scca2;
                           --  RecordHTLParams(actual_state, -1.0, -1.0, m, n, power_f1) (543,25)
                           tmp820 := (-1.0);
                           tmp821 := (-1.0);
                           RI_0_RecordHTLParams(ctxt.actual_state, tmp820, tmp821, ctxt.m, ctxt.n, ctxt.power_f1);
                        end if;
                        --  RETURN  (None,None) at 507, 325
                        return;
                     end p_0_initA2;
                     

                  procedure setCurrentMode(current_state: in out asn1SccHTL_State) is
                     begin
                        case ctxt.state is
                           when asn1Sccinit =>
                              Execute_Transition (CS_Only);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (12);
                           when asn1Scca2 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (16);
                           when asn1Sccf3 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (8);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf2 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (10);
                           when asn1Scca1 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (14);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end setCurrentMode;
                     

                  procedure tick is
                     begin
                        case ctxt.state is
                           when asn1Sccinit =>
                              Execute_Transition (18);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
                              Execute_Transition (11);
                           when asn1Scca2 =>
                              Execute_Transition (15);
                           when asn1Sccf3 =>
                              Execute_Transition (7);
                           when asn1Sccerror =>
                              Execute_Transition (17);
                           when asn1Sccf2 =>
                              Execute_Transition (9);
                           when asn1Scca1 =>
                              Execute_Transition (13);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end tick;
                     

                  procedure configureParameters_Transition is
                     begin
                        case ctxt.state is
                           when asn1Sccinit =>
                              Execute_Transition (CS_Only);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
                              Execute_Transition (CS_Only);
                           when asn1Scca2 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf3 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf2 =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
                              Execute_Transition (CS_Only);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end configureParameters_Transition;
                     

                  procedure getCurrentMode_Transition is
                     begin
                        case ctxt.state is
                           when asn1Sccinit =>
                              Execute_Transition (CS_Only);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
                              Execute_Transition (CS_Only);
                           when asn1Scca2 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf3 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf2 =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
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
                                 --  NEXT_STATE Init (551,18) at 632, 128
                                 trId := -1;
                                 ctxt.State := asn1SccInit;
                                 goto Next_Transition;
                              when 1 =>
                                 --  NEXT_STATE F2 (557,22) at 1074, 1065
                                 trId := -1;
                                 ctxt.State := asn1SccF2;
                                 goto Next_Transition;
                              when 2 =>
                                 --  NEXT_STATE A1 (561,22) at 820, 1060
                                 trId := -1;
                                 ctxt.State := asn1SccA1;
                                 goto Next_Transition;
                              when 3 =>
                                 --  NEXT_STATE A2 (565,22) at 535, 1060
                                 trId := -1;
                                 ctxt.State := asn1SccA2;
                                 goto Next_Transition;
                              when 4 =>
                                 --  NEXT_STATE F1 (569,22) at 686, 1065
                                 trId := -1;
                                 ctxt.State := asn1SccF1;
                                 goto Next_Transition;
                              when 5 =>
                                 --  NEXT_STATE F3 (573,22) at 943, 1063
                                 trId := -1;
                                 ctxt.State := asn1SccF3;
                                 goto Next_Transition;
                              when 6 =>
                                 --  NEXT_STATE Error (577,22) at 1215, 1065
                                 trId := -1;
                                 ctxt.State := asn1SccError;
                                 goto Next_Transition;
                              when 7 =>
                                 --  actual_state := f3 (584,17)
                                 ctxt.actual_state := asn1Sccf3;
                                 --  doF3 (586,17)
                                 p_0_doF3;
                                 --  kickTheDog (588,17)
                                 RI_0_KickTheDog;
                                 --  NEXT_STATE F3 (590,22) at 2194, 1228
                                 trId := -1;
                                 ctxt.State := asn1SccF3;
                                 goto Next_Transition;
                              when 8 =>
                                 --  NEXT_STATE Selectstate (594,22) at 2357, 1063
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 9 =>
                                 --  initf2 (601,17)
                                 p_0_initF2;
                                 --  kickTheDog (603,17)
                                 RI_0_KickTheDog;
                                 --  ok := call updateData (605,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (609,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (611,35)
                                    --  ANSWER True (613,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  NEXT_STATE F3 (615,38) at 1797, 1434
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (617,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       --  DECISION htl_time >= f2_duration_max (619,46)
                                       --  ANSWER true (621,33)
                                       if ((ctxt.htl_time >= ctxt.f2_duration_max)) = true then
                                          --  NEXT_STATE F3 (623,46) at 1513, 1570
                                          --  COMMENT time in F3 is bigger
                                          --  than the allowed. (625,36)
                                          trId := -1;
                                          ctxt.State := asn1SccF3;
                                          goto Next_Transition;
                                          --  ANSWER false (628,33)
                                       elsif ((ctxt.htl_time >= ctxt.f2_duration_max)) = false then
                                          --  doF2 (630,41)
                                          p_0_doF2;
                                          --  NEXT_STATE F2 (632,46) at 1623, 1622
                                          trId := -1;
                                          ctxt.State := asn1SccF2;
                                          goto Next_Transition;
                                       end if;
                                    end if;
                                    --  ANSWER false (636,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state:=actual_state (638,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (640,30) at 1259, 1375
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 10 =>
                                 --  NEXT_STATE Selectstate (645,22) at 1944, 1057
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 11 =>
                                 --  initf1 (652,17)
                                 p_0_initF1;
                                 --  kickTheDog (654,17)
                                 RI_0_KickTheDog;
                                 --  ok := call updateData (656,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (660,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (662,35)
                                    --  ANSWER True (664,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  NEXT_STATE F3 (666,38) at 2935, 588
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (668,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       --  DECISION htl_time >= f1_duration_max (670,46)
                                       --  ANSWER true (672,33)
                                       if ((ctxt.htl_time >= ctxt.f1_duration_max)) = true then
                                          --  NEXT_STATE F2 (674,46) at 2640, 735
                                          trId := -1;
                                          ctxt.State := asn1SccF2;
                                          goto Next_Transition;
                                          --  ANSWER false (676,33)
                                       elsif ((ctxt.htl_time >= ctxt.f1_duration_max)) = false then
                                          --  doF1 (678,41)
                                          p_0_doF1;
                                          --  NEXT_STATE F1 (680,46) at 2730, 790
                                          trId := -1;
                                          ctxt.State := asn1SccF1;
                                          goto Next_Transition;
                                       end if;
                                    end if;
                                    --  ANSWER false (684,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (686,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (688,30) at 2460, 512
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 12 =>
                                 --  NEXT_STATE Selectstate (693,22) at 3072, 192
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 13 =>
                                 --  initA1 (700,17)
                                 p_0_initA1;
                                 --  KickTheDog (702,17)
                                 RI_0_KickTheDog;
                                 --  ok := call updateData (704,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (708,17)
                                 if (ctxt.ok) = true then
                                    null;
                                    --  ANSWER false (710,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (712,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (714,30) at 1041, 510
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                                 --  DECISION (press <= press_10km and
                                 --  htl_time >= a1_duration_emergency) or
                                 --  htl_time >= a1_duration_max (718,35)
                                 --  ANSWER false (721,17)
                                 if ((((ctxt.press <= ctxt.press_10km) and (ctxt.htl_time >= ctxt.a1_duration_emergency)) or (ctxt.htl_time >= ctxt.a1_duration_max))) = false then
                                    --  doA1 (723,25)
                                    p_0_doA1;
                                    --  NEXT_STATE A1 (725,30) at 1117, 787
                                    trId := -1;
                                    ctxt.State := asn1SccA1;
                                    goto Next_Transition;
                                    --  ANSWER true (727,17)
                                 elsif ((((ctxt.press <= ctxt.press_10km) and (ctxt.htl_time >= ctxt.a1_duration_emergency)) or (ctxt.htl_time >= ctxt.a1_duration_max))) = true then
                                    --  NEXT_STATE A2 (729,30) at 1207, 737
                                    trId := -1;
                                    ctxt.State := asn1SccA2;
                                    goto Next_Transition;
                                 end if;
                              when 14 =>
                                 --  NEXT_STATE Selectstate (734,22) at 1476, 186
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 15 =>
                                 --  InitA2 (741,17)
                                 p_0_initA2;
                                 --  kickTheDog (743,17)
                                 RI_0_KickTheDog;
                                 --  ok := call updateData (745,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (749,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (751,35)
                                    --  COMMENT no estamos cayendo? (753,20)
                                    --  ANSWER True (755,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  writeln('Nos estamos cayendo') (757,33)
                                       Put ("Nos estamos cayendo");
                                       New_Line;
                                       --  NEXT_STATE F3 (759,38) at 1798, 620
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (761,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       null;
                                    end if;
                                    --  ANSWER false (764,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (766,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (768,30) at 2027, 490
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                                 --  DECISION htl_time >= a2_duration_max
                                 --  or press <= press_18km (772,0)
                                 --  ANSWER false (774,17)
                                 if (((ctxt.htl_time >= ctxt.a2_duration_max) or (ctxt.press <= ctxt.press_18km))) = false then
                                    --  doA2 (776,25)
                                    p_0_doA2;
                                    --  NEXT_STATE A2 (778,30) at 1542, 885
                                    trId := -1;
                                    ctxt.State := asn1SccA2;
                                    goto Next_Transition;
                                    --  ANSWER true (780,17)
                                 elsif (((ctxt.htl_time >= ctxt.a2_duration_max) or (ctxt.press <= ctxt.press_18km))) = true then
                                    --  writeln('A2 max duration: ', a2_duration_max) (782,25)
                                    Put ("A2 max duration: ");
                                    Put (asn1SccT_Double'Image (ctxt.a2_duration_max));
                                    New_Line;
                                    --  NEXT_STATE F1 (784,30) at 1734, 890
                                    trId := -1;
                                    ctxt.State := asn1SccF1;
                                    goto Next_Transition;
                                 end if;
                              when 16 =>
                                 --  NEXT_STATE Selectstate (789,22) at 2228, 182
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 17 =>
                                 --  ok := call updateData (796,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  actual_state := error (797,0)
                                 ctxt.actual_state := asn1Sccerror;
                                 --  writeln('[HTL] Actual mode: ERROR') (799,17)
                                 Put ("[HTL] Actual mode: ERROR");
                                 New_Line;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (803,17)
                                 if (ctxt.ok) = true then
                                    --  actual_state := last_good_state (805,25)
                                    ctxt.actual_state := ctxt.last_good_state;
                                    --  DECISION last_good_state (-1,-1)
                                    --  ANSWER a1 (809,25)
                                    if (ctxt.last_good_state) = asn1Scca1 then
                                       --  NEXT_STATE A1 (811,38) at 2332, 1462
                                       trId := -1;
                                       ctxt.State := asn1SccA1;
                                       goto Next_Transition;
                                       --  ANSWER a2 (813,25)
                                    elsif (ctxt.last_good_state) = asn1Scca2 then
                                       --  NEXT_STATE A2 (815,38) at 2422, 1462
                                       trId := -1;
                                       ctxt.State := asn1SccA2;
                                       goto Next_Transition;
                                       --  ANSWER f1 (817,25)
                                    elsif (ctxt.last_good_state) = asn1Sccf1 then
                                       --  NEXT_STATE F1 (819,38) at 2512, 1462
                                       trId := -1;
                                       ctxt.State := asn1SccF1;
                                       goto Next_Transition;
                                       --  ANSWER f2 (821,25)
                                    elsif (ctxt.last_good_state) = asn1Sccf2 then
                                       --  NEXT_STATE F2 (823,38) at 2602, 1462
                                       trId := -1;
                                       ctxt.State := asn1SccF2;
                                       goto Next_Transition;
                                       --  ANSWER else (None,None)
                                    else
                                       --  NEXT_STATE Error (827,38) at 2692, 1467
                                       trId := -1;
                                       ctxt.State := asn1SccError;
                                       goto Next_Transition;
                                    end if;
                                    --  ANSWER false (830,17)
                                 elsif (ctxt.ok) = false then
                                    --  NEXT_STATE Error (832,30) at 2773, 1298
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 18 =>
                                 --  RecoverHTLParams(actual_state, f1_duration_max, f2_duration_max, m, n, power_f1) (840,17)
                                 RI_0_RecoverHTLParams(ctxt.actual_state, ctxt.f1_duration_max, ctxt.f2_duration_max, ctxt.m, ctxt.n, ctxt.power_f1);
                                 --  writeln('[HTL] Actual mode recovered: ', actual_state) (842,17)
                                 Put ("[HTL] Actual mode recovered: ");
                                 Put (ctxt.actual_state'Img);
                                 New_Line;
                                 --  writeln('[HTL] F1 max time recovered: ', f1_duration_max, ' secs.') (844,17)
                                 Put ("[HTL] F1 max time recovered: ");
                                 Put (asn1SccT_Double'Image (ctxt.f1_duration_max));
                                 Put (" secs.");
                                 New_Line;
                                 --  writeln('[HTL] Value of n (used in F1)', n) (846,17)
                                 Put ("[HTL] Value of n (used in F1)");
                                 Put (asn1SccT_Float'Image (ctxt.n));
                                 New_Line;
                                 --  writeln('[HTL] F2 max time recovered: ', f2_duration_max, ' secs.') (848,17)
                                 Put ("[HTL] F2 max time recovered: ");
                                 Put (asn1SccT_Double'Image (ctxt.f2_duration_max));
                                 Put (" secs.");
                                 New_Line;
                                 --  writeln('[HTL] Value of m (used in F2)', m) (850,17)
                                 Put ("[HTL] Value of m (used in F2)");
                                 Put (asn1SccT_Float'Image (ctxt.m));
                                 New_Line;
                                 --  NEXT_STATE selectstate (852,22) at 626, 613
                                 trId := -1;
                                 ctxt.State := asn1Sccselectstate;
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
                              --  DECISION actual_state = f2 (555,30)
                              --  ANSWER true (None,None)
                              if ((ctxt.actual_state = asn1Sccf2)) = true then
                                 trId := 1;
                                 --  Priority 1
                                 --  DECISION actual_state = a1 (559,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Scca1)) = true then
                                 trId := 2;
                                 --  Priority 1
                                 --  DECISION actual_state = a2 (563,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Scca2)) = true then
                                 trId := 3;
                                 --  Priority 1
                                 --  DECISION actual_state = f1 (567,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccf1)) = true then
                                 trId := 4;
                                 --  Priority 1
                                 --  DECISION actual_state = f3 (571,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccf3)) = true then
                                 trId := 5;
                                 --  Priority 1
                                 --  DECISION actual_state = error (575,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccerror)) = true then
                                 trId := 6;
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