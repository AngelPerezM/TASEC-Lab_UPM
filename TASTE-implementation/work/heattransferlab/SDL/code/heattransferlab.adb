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
      tmp183 : asn1SccT_Float;
      --  !! stack: _call_external_function line 1604
      begin
         --  DECISION system_stopped (-1,-1)
         --  ANSWER true (56,17)
         if (ctxt.system_stopped) = true then
            --  RETURN  (None,None) at 669, 238
            return;
            --  ANSWER false (60,17)
         elsif (ctxt.system_stopped) = false then
            null;
         end if;
         --  ok := call updateData (63,17)
         ctxt.ok := p_0_updatedata;
         --  DECISION ok and power = 0.0 (65,24)
         --  ANSWER true (67,17)
         if ((ctxt.ok and asn1SccT_Float_Equal (ctxt.power, 0.0))) = true then
            --  system_stopped := true (69,25)
            ctxt.system_stopped := true;
            --  stopSystem (71,25)
            RI_0_StopSystem;
            --  ANSWER false (73,17)
         elsif ((ctxt.ok and asn1SccT_Float_Equal (ctxt.power, 0.0))) = false then
            --  setPowerH2(0.0) (75,25)
            tmp183 := 0.0;
            RI_0_setPowerH2(tmp183);
         end if;
         --  RETURN  (None,None) at 354, 601
         return;
      end p_0_doF3;
      

   procedure p_0_doF2 is
      begin
         --  DECISION power = 0.0 (85,27)
         --  ANSWER false (87,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            null;
            --  ANSWER true (89,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  DECISION temp_plate <= 55.0 and
            --  abs(temp_plate - temp_air) <= 50.0 (91,48)
            --  ANSWER true (94,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               --  m := m+0.1 (96,33)
               ctxt.m := (ctxt.m + 0.1);
               --  ANSWER false (98,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 601, 362
               return;
            end if;
         end if;
         --  DECISION temp_plate >= 65.0 or 
         --  abs (temp_plate - temp_air) >= 60.0 (104,40)
         --  COMMENT >= 60? (107,12)
         --  ANSWER true (109,17)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (111,25)
            ctxt.power := 0.0;
            --  ANSWER false (113,17)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := power_f1/2.0 - m*0.1 (115,25)
            ctxt.power := ((ctxt.power_f1 / 2.0) - (ctxt.m * 0.1));
            --  DECISION power <= 0.1 (117,35)
            --  ANSWER true (119,25)
            if ((ctxt.power <= 0.1)) = true then
               --  power := 0.1 (121,33)
               ctxt.power := 0.1;
               --  ANSWER false (123,25)
            elsif ((ctxt.power <= 0.1)) = false then
               null;
            end if;
         end if;
         --  setPowerH2(power) (127,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 439, 851
         return;
      end p_0_doF2;
      

   procedure p_0_doA2 is
      begin
         --  DECISION power = 0.0 (136,27)
         --  ANSWER false (138,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            --  JOIN normalA2 (None,None) at None, None
            goto normalA2;
            --  ANSWER true (160,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  DECISION temp_plate <= 55.0 and
            --  abs(temp_plate - temp_air) <= 50.0 (162,48)
            --  COMMENT Pdiss = 0.0 W (165,20)
            --  ANSWER true (167,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               --  JOIN normalA2 (169,33) at 757, 344
               goto normalA2;
               --  ANSWER false (171,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 861, 346
               return;
            end if;
         end if;
         --  setPowerH2(power) (177,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 435, 612
         return;
         --  CONNECTION normalA2 (140,20)
         <<normalA2>>
         --  DECISION temp_plate >= 65.0 or
         --  abs(temp_plate - temp_air) >= 60.0 (142,48)
         --  COMMENT Pdiss = 1.0 (145,20)
         --  ANSWER false (147,25)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := 0.6 (149,33)
            ctxt.power := 0.6;
            --  power_a2 := power (151,33)
            ctxt.power_a2 := ctxt.power;
            --  ANSWER true (153,25)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (155,33)
            ctxt.power := 0.0;
         end if;
         --  writeln('normalA2') (158,25)
         Put ("normalA2");
         New_Line;
         --  setPowerH2(power) (177,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 435, 612
         return;
      end p_0_doA2;
      

   procedure p_0_doA1 is
      begin
         --  DECISION power = 0.0 (186,27)
         --  ANSWER false (188,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            null;
            --  ANSWER true (190,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  DECISION temp_plate <= 55.0 and abs(temp_plate -temp_air) <= 50.0 (192,48)
            --  ANSWER true (194,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               null;
               --  ANSWER false (196,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 983, 318
               return;
            end if;
         end if;
         --  DECISION temp_plate >= 65.0 or abs(temp_plate - temp_air) >= 60.0 (202,40)
         --  ANSWER true (204,17)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (206,25)
            ctxt.power := 0.0;
            --  ANSWER false (208,17)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := 0.8 (210,25)
            ctxt.power := 0.8;
         end if;
         --  setPowerH2(power) (213,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 518, 657
         return;
      end p_0_doA1;
      

   procedure p_0_doF1 is
      begin
         --  DECISION power = 0.0 (222,27)
         --  ANSWER true (224,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  DECISION temp_plate <= 55.0 and
            --  abs(temp_plate - temp_air) <= 50.0 (226,48)
            --  ANSWER true (229,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               --  n := n+1.0 (231,33)
               ctxt.n := (ctxt.n + 1.0);
               --  JOIN normalF1 (233,33) at 599, 454
               goto normalF1;
               --  ANSWER false (235,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 706, 404
               return;
            end if;
            --  ANSWER false (240,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            --  JOIN normalF1 (None,None) at None, None
            goto normalF1;
         end if;
         --  CONNECTION normalF1 (242,20)
         <<normalF1>>
         --  DECISION temp_plate >= 65.0 or
         --  abs(temp_plate - temp_air) >= 60.0 (244,48)
         --  COMMENT ¿>= 60? (247,20)
         --  ANSWER true (249,25)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (251,33)
            ctxt.power := 0.0;
            --  ANSWER false (253,25)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := power_a2-n*0.1 (255,33)
            ctxt.power := (ctxt.power_a2 - (ctxt.n * 0.1));
            --  DECISION power <= 0.1 (257,43)
            --  ANSWER true (259,33)
            if ((ctxt.power <= 0.1)) = true then
               --  power := 0.1 (261,41)
               ctxt.power := 0.1;
               --  ANSWER false (263,33)
            elsif ((ctxt.power <= 0.1)) = false then
               null;
            end if;
            --  power_f1 := power (266,33)
            ctxt.power_f1 := ctxt.power;
         end if;
         --  setPowerH2(power) (269,25)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 306, 742
         return;
      end p_0_doF1;
      

   procedure configureParameters(Configuration: in out asn1SccHTL_Config) is
      tmp401 : asn1SccT_Double;
      tmp377 : asn1SccT_Float;
      tmp385 : asn1SccT_Float;
      tmp393 : asn1SccT_Float;
      tmp419 : asn1SccT_Double;
      tmp435 : asn1SccT_Double;
      tmp410 : asn1SccT_Double;
      tmp427 : asn1SccT_Double;
      begin
         --  press_5km  := if exist (Configuration.press_5km) then Configuration.press_5km else press_5km fi (285,17)
         if (Configuration.exist.press_5km = 1) then
            tmp377 := Configuration.press_5km;
         else
            tmp377 := ctxt.press_5km;
         end if;
         ctxt.press_5km := tmp377;
         --  press_10km := if exist(Configuration.press_10km) then Configuration.press_10km else press_10km fi (286,0)
         if (Configuration.exist.press_10km = 1) then
            tmp385 := Configuration.press_10km;
         else
            tmp385 := ctxt.press_10km;
         end if;
         ctxt.press_10km := tmp385;
         --  press_18km := if exist(Configuration.press_18km) then Configuration.press_18km else press_18km fi (287,0)
         if (Configuration.exist.press_18km = 1) then
            tmp393 := Configuration.press_18km;
         else
            tmp393 := ctxt.press_18km;
         end if;
         ctxt.press_18km := tmp393;
         --  f1_relative_duration_max :=
         --   if exist(Configuration.f1_duration_secs) then
            --     float (Configuration.f1_duration_secs)
            --  else
            --    f1_relative_duration_max
            --  fi (289,0)
            if (Configuration.exist.f1_duration_secs = 1) then
               tmp401 := Asn1Real(Configuration.f1_duration_secs);
            else
               tmp401 := ctxt.f1_relative_duration_max;
            end if;
            ctxt.f1_relative_duration_max := tmp401;
            --  f2_relative_duration_max :=
            --  if exist(Configuration.f2_duration_secs) then
               --    float(Configuration.f2_duration_secs)
               --  else
               --    f2_relative_duration_max
               --  fi (296,0)
               if (Configuration.exist.f2_duration_secs = 1) then
                  tmp410 := Asn1Real(Configuration.f2_duration_secs);
               else
                  tmp410 := ctxt.f2_relative_duration_max;
               end if;
               ctxt.f2_relative_duration_max := tmp410;
               --  a1_duration_emergency :=
               --  if exist(Configuration.a1_duration_emergency_secs) then
                  --    Configuration.a1_duration_emergency_secs
                  --  else
                  --    a1_duration_emergency
                  --  fi (303,0)
                  if (Configuration.exist.a1_duration_emergency_secs = 1) then
                     tmp419 := Configuration.a1_duration_emergency_secs;
                  else
                     tmp419 := ctxt.a1_duration_emergency;
                  end if;
                  ctxt.a1_duration_emergency := tmp419;
                  --  a1_duration_max :=
                  --  if exist(Configuration.a1_duration_max_secs) then
                     --    Configuration.a1_duration_max_secs
                     --  else
                     --    a1_duration_max
                     --  fi (310,0)
                     if (Configuration.exist.a1_duration_max_secs = 1) then
                        tmp427 := Configuration.a1_duration_max_secs;
                     else
                        tmp427 := ctxt.a1_duration_max;
                     end if;
                     ctxt.a1_duration_max := tmp427;
                     --  a2_duration_max :=
                     --  if exist(Configuration.a2_duration_max_secs) then
                        --    Configuration.a2_duration_max_secs
                        --  else
                        --    a2_duration_max
                        --  fi (317,0)
                        if (Configuration.exist.a2_duration_max_secs = 1) then
                           tmp435 := Configuration.a2_duration_max_secs;
                        else
                           tmp435 := ctxt.a2_duration_max;
                        end if;
                        ctxt.a2_duration_max := tmp435;
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
                     --  !! stack: _call_external_function line 1604
                     tmp448 : asn1SccOBSW_DP_Filter;
                     tmp460 : asn1SccOBSW_DP_Filter;
                     tmp587 : asn1SccT_Float;
                     tmp552 : asn1SccT_Float;
                     tmp456 : asn1SccOBSW_DP_Filter;
                     tmp530 : asn1SccT_Float;
                     tmp561 : asn1SccT_Float;
                     tmp540 : asn1SccT_Float;
                     tmp452 : asn1SccOBSW_DP_Filter;
                     tmp573 : asn1SccT_Float;
                     begin
                        --  getTime(gps_time, htl_time) (348,17)
                        RI_0_getTime(gps_time, ctxt.htl_time);
                        --  retreiveSingleData(pt1000s,pt1000s_data) (350,17)
                        tmp448 := asn1Sccpt1000s;
                        RI_0_RetreiveSingleData(tmp448, pt1000s_data);
                        --  retreiveSingleData(ps1, press1_data) (352,17)
                        tmp452 := asn1Sccps1;
                        RI_0_RetreiveSingleData(tmp452, press1_data);
                        --  retreiveSingleData(ps2, press2_data) (354,17)
                        tmp456 := asn1Sccps2;
                        RI_0_RetreiveSingleData(tmp456, press2_data);
                        --  retreiveSingleData(heater2, power_data) (356,17)
                        tmp460 := asn1Sccheater2;
                        RI_0_RetreiveSingleData(tmp460, power_data);
                        --  temp_air := 0.0 (358,17)
                        ctxt.temp_air := 0.0;
                        --  temp_plate := 0.0 (359,0)
                        ctxt.temp_plate := 0.0;
                        --  press := 0.0 (360,0)
                        ctxt.press := 0.0;
                        --  placa_abajo_ok := pt1000s_data.pt1000s.data.validity(6) = valid (362,0)
                        placa_abajo_ok := (pt1000s_data.pt1000s.data.validity.Data(7) = asn1Sccvalid);
                        --  placa_arriba_ok := pt1000s_data.pt1000s.data.validity(5) = valid (363,0)
                        placa_arriba_ok := (pt1000s_data.pt1000s.data.validity.Data(6) = asn1Sccvalid);
                        --  aire_infinito_ok := pt1000s_data.pt1000s.data.validity(2) = valid (364,0)
                        aire_infinito_ok := (pt1000s_data.pt1000s.data.validity.Data(3) = asn1Sccvalid);
                        --  press1_ok := press1_data.ps1.data.validity = valid (365,0)
                        press1_ok := (press1_data.ps1.data.validity = asn1Sccvalid);
                        --  press2_ok := press2_data.ps2.data.validity = valid (366,0)
                        press2_ok := (press2_data.ps2.data.validity = asn1Sccvalid);
                        --  power_ok := power_data.heater2.data.validity = valid (367,0)
                        power_ok := (power_data.heater2.data.validity = asn1Sccvalid);
                        --  DECISION power_ok and
                        --  (placa_abajo_ok or placa_arriba_ok)
                        --  and aire_infinito_ok
                        --  and (press1_ok or press2_ok) (372,0)
                        --  ANSWER true (374,17)
                        if ((((power_ok and (placa_abajo_ok or placa_arriba_ok)) and aire_infinito_ok) and (press1_ok or press2_ok))) = true then
                           --  temp_plate := if placa_arriba_ok then (pt1000s_data.pt1000s.data.celsius(5)) else 0.0 fi (376,25)
                           if placa_arriba_ok then
                              tmp530 := pt1000s_data.pt1000s.data.celsius.Data(6);
                           else
                              tmp530 := 0.0;
                           end if;
                           ctxt.temp_plate := tmp530;
                           --  temp_plate := if placa_abajo_ok then (pt1000s_data.pt1000s.data.celsius(6) + temp_plate) else temp_plate fi (377,0)
                           if placa_abajo_ok then
                              tmp540 := (pt1000s_data.pt1000s.data.celsius.Data(7) + ctxt.temp_plate);
                           else
                              tmp540 := ctxt.temp_plate;
                           end if;
                           ctxt.temp_plate := tmp540;
                           --  temp_plate := if placa_abajo_ok and placa_arriba_ok then temp_plate / 2.0 else temp_plate fi (378,0)
                           if (placa_abajo_ok and placa_arriba_ok) then
                              tmp552 := (ctxt.temp_plate / 2.0);
                           else
                              tmp552 := ctxt.temp_plate;
                           end if;
                           ctxt.temp_plate := tmp552;
                           --  press := if press1_ok then float(press1_data.ps1.data.processed.pressure) /100.0 else 0.0 fi (380,0)
                           if press1_ok then
                              tmp561 := (Asn1Real(press1_data.ps1.data.processed.pressure) / 100.0);
                           else
                              tmp561 := 0.0;
                           end if;
                           ctxt.press := tmp561;
                           --  press := if press2_ok then (float(press2_data.ps2.data.processed.pressure)/100.0 + press) else press fi (381,0)
                           if press2_ok then
                              tmp573 := ((Asn1Real(press2_data.ps2.data.processed.pressure) / 100.0) + ctxt.press);
                           else
                              tmp573 := ctxt.press;
                           end if;
                           ctxt.press := tmp573;
                           --  press := if press1_ok and press2_ok then press / 2.0 else press fi (382,0)
                           if (press1_ok and press2_ok) then
                              tmp587 := (ctxt.press / 2.0);
                           else
                              tmp587 := ctxt.press;
                           end if;
                           ctxt.press := tmp587;
                           --  temp_air := pt1000s_data.pt1000s.data.celsius(2) (384,0)
                           ctxt.temp_air := pt1000s_data.pt1000s.data.celsius.Data(3);
                           --  power := power_data.heater2.data.power_watts (386,0)
                           ctxt.power := power_data.heater2.data.power_watts;
                           --  writeln('temp_plate: ', temp_plate) (388,25)
                           Put ("temp_plate: ");
                           Put (asn1SccT_Float'Image (ctxt.temp_plate));
                           New_Line;
                           --  writeln('power: ', power) (390,25)
                           Put ("power: ");
                           Put (asn1SccT_Float'Image (ctxt.power));
                           New_Line;
                           --  writeln('press: ', press) (392,25)
                           Put ("press: ");
                           Put (asn1SccT_Float'Image (ctxt.press));
                           New_Line;
                           --  writeln('press 2 ok ', press2_ok) (394,25)
                           Put ("press 2 ok ");
                           Put (asn1SccT_Boolean'Image (press2_ok));
                           New_Line;
                           --  writeln('temp_air: ', temp_air) (396,25)
                           Put ("temp_air: ");
                           Put (asn1SccT_Float'Image (ctxt.temp_air));
                           New_Line;
                           --  RETURN True (None,None) at 407, 1318
                           return true;
                           --  ANSWER false (400,17)
                        elsif ((((power_ok and (placa_abajo_ok or placa_arriba_ok)) and aire_infinito_ok) and (press1_ok or press2_ok))) = false then
                           --  writeln('invalid data :-(') (402,25)
                           Put ("invalid data :-(");
                           New_Line;
                           --  RETURN False (None,None) at 1223, 888
                           return false;
                        end if;
                     end p_0_updateData;
                     

                  procedure getCurrentMode(Current_State: in out asn1SccHTL_State) is
                     begin
                        --  Current_State := actual_state (417,17)
                        Current_State := ctxt.actual_state;
                        --  getCurrentMode_Transition (None,None)
                        getCurrentMode_Transition;
                        --  RETURN  (None,None) at 603, 257
                        return;
                     end getCurrentMode;
                     

                  procedure p_0_initF2 is
                     begin
                        --  DECISION f2_started (-1,-1)
                        --  ANSWER true (428,17)
                        if (ctxt.f2_started) = true then
                           null;
                           --  ANSWER false (430,17)
                        elsif (ctxt.f2_started) = false then
                           --  f2_started := true (432,25)
                           ctxt.f2_started := true;
                           --  actual_state := f2 (433,0)
                           ctxt.actual_state := asn1Sccf2;
                           --  DECISION f2_duration_max = -1.0 (435,45)
                           --  ANSWER true (437,25)
                           if (asn1SccT_Double_Equal (ctxt.f2_duration_max, (-1.0))) = true then
                              --  f2_duration_max := htl_time + f2_relative_duration_max (439,33)
                              ctxt.f2_duration_max := (ctxt.htl_time + ctxt.f2_relative_duration_max);
                              --  ANSWER false (441,25)
                           elsif (asn1SccT_Double_Equal (ctxt.f2_duration_max, (-1.0))) = false then
                              null;
                           end if;
                           --  RecordHTLParams(actual_state, f1_duration_max, f2_duration_max) (444,25)
                           RI_0_RecordHTLParams(ctxt.actual_state, ctxt.f1_duration_max, ctxt.f2_duration_max);
                           --  writeln('[initF2] Recorded: ', actual_state) (446,25)
                           Put ("[initF2] Recorded: ");
                           Put (ctxt.actual_state'Img);
                           New_Line;
                        end if;
                        --  RETURN  (None,None) at 256, 579
                        return;
                     end p_0_initF2;
                     

                  procedure p_0_initF1 is
                     begin
                        --  DECISION f1_started (-1,-1)
                        --  ANSWER true (458,17)
                        if (ctxt.f1_started) = true then
                           null;
                           --  ANSWER false (460,17)
                        elsif (ctxt.f1_started) = false then
                           --  f1_started := true (462,25)
                           ctxt.f1_started := true;
                           --  actual_state := f1 (463,0)
                           ctxt.actual_state := asn1Sccf1;
                           --  DECISION f1_duration_max = -1.0 (465,45)
                           --  ANSWER true (467,25)
                           if (asn1SccT_Double_Equal (ctxt.f1_duration_max, (-1.0))) = true then
                              --  f1_duration_max := htl_time + f1_relative_duration_max (469,33)
                              ctxt.f1_duration_max := (ctxt.htl_time + ctxt.f1_relative_duration_max);
                              --  ANSWER false (471,25)
                           elsif (asn1SccT_Double_Equal (ctxt.f1_duration_max, (-1.0))) = false then
                              null;
                           end if;
                           --  RecordHTLParams(actual_state, f1_duration_max, f2_duration_max) (474,25)
                           RI_0_RecordHTLParams(ctxt.actual_state, ctxt.f1_duration_max, ctxt.f2_duration_max);
                           --  writeln('[init f1] Recorded: ', actual_state) (476,25)
                           Put ("[init f1] Recorded: ");
                           Put (ctxt.actual_state'Img);
                           New_Line;
                        end if;
                        --  RETURN  (None,None) at 455, 598
                        return;
                     end p_0_initF1;
                     

                  procedure p_0_initA1 is
                     tmp707 : asn1SccT_Double;
                     --  !! stack: _call_external_function line 1604
                     tmp706 : asn1SccT_Double;
                     begin
                        --  DECISION a1_started (-1,-1)
                        --  ANSWER true (488,17)
                        if (ctxt.a1_started) = true then
                           null;
                           --  ANSWER false (490,17)
                        elsif (ctxt.a1_started) = false then
                           --  a1_started := true (492,25)
                           ctxt.a1_started := true;
                           --  actual_state := a1 (493,0)
                           ctxt.actual_state := asn1Scca1;
                           --  RecordHTLParams(actual_state, -1.0, -1.0) (495,25)
                           tmp706 := (-1.0);
                           tmp707 := (-1.0);
                           RI_0_RecordHTLParams(ctxt.actual_state, tmp706, tmp707);
                        end if;
                        --  RETURN  (None,None) at 409, 316
                        return;
                     end p_0_initA1;
                     

                  procedure p_0_initA2 is
                     --  !! stack: _call_external_function line 1604
                     tmp722 : asn1SccT_Double;
                     tmp723 : asn1SccT_Double;
                     begin
                        --  DECISION a2_started (-1,-1)
                        --  ANSWER true (507,17)
                        if (ctxt.a2_started) = true then
                           null;
                           --  ANSWER false (509,17)
                        elsif (ctxt.a2_started) = false then
                           --  a2_started := true (511,25)
                           ctxt.a2_started := true;
                           --  actual_state := a2 (512,0)
                           ctxt.actual_state := asn1Scca2;
                           --  RecordHTLParams(actual_state, -1.0, -1.0) (514,25)
                           tmp722 := (-1.0);
                           tmp723 := (-1.0);
                           RI_0_RecordHTLParams(ctxt.actual_state, tmp722, tmp723);
                        end if;
                        --  RETURN  (None,None) at 507, 325
                        return;
                     end p_0_initA2;
                     

                  procedure setCurrentMode(current_state: in out asn1SccHTL_State) is
                     begin
                        case ctxt.state is
                           when asn1Sccf2 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (12);
                           when asn1Sccf3 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (10);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (14);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccinit =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (16);
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
                           when asn1Sccf2 =>
                              Execute_Transition (11);
                           when asn1Sccf3 =>
                              Execute_Transition (9);
                           when asn1Sccerror =>
                              Execute_Transition (8);
                           when asn1Sccf1 =>
                              Execute_Transition (13);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccinit =>
                              Execute_Transition (1);
                           when asn1Scca1 =>
                              Execute_Transition (15);
                           when asn1Scca2 =>
                              Execute_Transition (17);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end tick;
                     

                  procedure configureParameters_Transition is
                     begin
                        case ctxt.state is
                           when asn1Sccf2 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf3 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccinit =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
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
                           when asn1Sccf2 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf3 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccinit =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
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
                                 --  NEXT_STATE Init (522,18) at 524, 116
                                 trId := -1;
                                 ctxt.State := asn1SccInit;
                                 goto Next_Transition;
                              when 1 =>
                                 --  RecoverHTLParams(actual_state, f1_duration_max, f2_duration_max) (528,17)
                                 RI_0_RecoverHTLParams(ctxt.actual_state, ctxt.f1_duration_max, ctxt.f2_duration_max);
                                 --  writeln('Actual State: ', actual_state) (530,17)
                                 Put ("Actual State: ");
                                 Put (ctxt.actual_state'Img);
                                 New_Line;
                                 --  writeln('F1 max time', f1_duration_max) (532,17)
                                 Put ("F1 max time");
                                 Put (asn1SccT_Double'Image (ctxt.f1_duration_max));
                                 New_Line;
                                 --  writeln('F2 max time', f2_duration_max) (534,17)
                                 Put ("F2 max time");
                                 Put (asn1SccT_Double'Image (ctxt.f2_duration_max));
                                 New_Line;
                                 --  NEXT_STATE selectstate (536,22) at 799, 392
                                 trId := -1;
                                 ctxt.State := asn1Sccselectstate;
                                 goto Next_Transition;
                              when 2 =>
                                 --  NEXT_STATE F2 (543,22) at 1081, 1065
                                 trId := -1;
                                 ctxt.State := asn1SccF2;
                                 goto Next_Transition;
                              when 3 =>
                                 --  NEXT_STATE A1 (547,22) at 820, 1060
                                 trId := -1;
                                 ctxt.State := asn1SccA1;
                                 goto Next_Transition;
                              when 4 =>
                                 --  NEXT_STATE A2 (551,22) at 543, 1060
                                 trId := -1;
                                 ctxt.State := asn1SccA2;
                                 goto Next_Transition;
                              when 5 =>
                                 --  NEXT_STATE F1 (555,22) at 686, 1065
                                 trId := -1;
                                 ctxt.State := asn1SccF1;
                                 goto Next_Transition;
                              when 6 =>
                                 --  NEXT_STATE F3 (559,22) at 950, 1063
                                 trId := -1;
                                 ctxt.State := asn1SccF3;
                                 goto Next_Transition;
                              when 7 =>
                                 --  NEXT_STATE Error (563,22) at 1223, 1065
                                 trId := -1;
                                 ctxt.State := asn1SccError;
                                 goto Next_Transition;
                              when 8 =>
                                 --  ok := call updateData (570,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  actual_state := error (571,0)
                                 ctxt.actual_state := asn1Sccerror;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (575,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION last_good_state (-1,-1)
                                    --  ANSWER a1 (579,25)
                                    if (ctxt.last_good_state) = asn1Scca1 then
                                       --  NEXT_STATE A1 (581,38) at 2332, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccA1;
                                       goto Next_Transition;
                                       --  ANSWER a2 (583,25)
                                    elsif (ctxt.last_good_state) = asn1Scca2 then
                                       --  NEXT_STATE A2 (585,38) at 2422, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccA2;
                                       goto Next_Transition;
                                       --  ANSWER f1 (587,25)
                                    elsif (ctxt.last_good_state) = asn1Sccf1 then
                                       --  NEXT_STATE F1 (589,38) at 2512, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccF1;
                                       goto Next_Transition;
                                       --  ANSWER f2 (591,25)
                                    elsif (ctxt.last_good_state) = asn1Sccf2 then
                                       --  NEXT_STATE F2 (593,38) at 2602, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccF2;
                                       goto Next_Transition;
                                       --  ANSWER else (None,None)
                                    else
                                       --  NEXT_STATE Error (597,38) at 2692, 1362
                                       trId := -1;
                                       ctxt.State := asn1SccError;
                                       goto Next_Transition;
                                    end if;
                                    --  ANSWER false (600,17)
                                 elsif (ctxt.ok) = false then
                                    --  NEXT_STATE Error (602,30) at 2773, 1243
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 9 =>
                                 --  actual_state := f3 (610,17)
                                 ctxt.actual_state := asn1Sccf3;
                                 --  doF3 (612,17)
                                 p_0_doF3;
                                 --  kickTheDog (614,17)
                                 RI_0_KickTheDog;
                                 --  NEXT_STATE F3 (616,22) at 2194, 1228
                                 trId := -1;
                                 ctxt.State := asn1SccF3;
                                 goto Next_Transition;
                              when 10 =>
                                 --  NEXT_STATE Selectstate (620,22) at 2364, 1063
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 11 =>
                                 --  initf2 (627,17)
                                 p_0_initF2;
                                 --  kickTheDog (629,17)
                                 RI_0_KickTheDog;
                                 --  ok := call updateData (631,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (635,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (637,35)
                                    --  ANSWER True (639,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  NEXT_STATE F3 (641,38) at 1797, 1434
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (643,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       --  DECISION htl_time >= f2_duration_max (645,46)
                                       --  ANSWER true (647,33)
                                       if ((ctxt.htl_time >= ctxt.f2_duration_max)) = true then
                                          --  NEXT_STATE F3 (649,46) at 1513, 1570
                                          --  COMMENT time in F3 is bigger
                                          --  than the allowed. (651,36)
                                          trId := -1;
                                          ctxt.State := asn1SccF3;
                                          goto Next_Transition;
                                          --  ANSWER false (654,33)
                                       elsif ((ctxt.htl_time >= ctxt.f2_duration_max)) = false then
                                          --  doF2 (656,41)
                                          p_0_doF2;
                                          --  NEXT_STATE F2 (658,46) at 1623, 1622
                                          trId := -1;
                                          ctxt.State := asn1SccF2;
                                          goto Next_Transition;
                                       end if;
                                    end if;
                                    --  ANSWER false (662,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state:=actual_state (664,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (666,30) at 1259, 1375
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 12 =>
                                 --  NEXT_STATE Selectstate (671,22) at 1944, 1057
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 13 =>
                                 --  initf1 (678,17)
                                 p_0_initF1;
                                 --  kickTheDog (680,17)
                                 RI_0_KickTheDog;
                                 --  ok := call updateData (682,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (686,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (688,35)
                                    --  ANSWER True (690,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  NEXT_STATE F3 (692,38) at 2935, 588
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (694,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       --  DECISION htl_time >= f1_duration_max (696,46)
                                       --  ANSWER true (698,33)
                                       if ((ctxt.htl_time >= ctxt.f1_duration_max)) = true then
                                          --  NEXT_STATE F2 (700,46) at 2640, 735
                                          trId := -1;
                                          ctxt.State := asn1SccF2;
                                          goto Next_Transition;
                                          --  ANSWER false (702,33)
                                       elsif ((ctxt.htl_time >= ctxt.f1_duration_max)) = false then
                                          --  doF1 (704,41)
                                          p_0_doF1;
                                          --  NEXT_STATE F1 (706,46) at 2730, 790
                                          trId := -1;
                                          ctxt.State := asn1SccF1;
                                          goto Next_Transition;
                                       end if;
                                    end if;
                                    --  ANSWER false (710,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (712,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (714,30) at 2460, 512
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 14 =>
                                 --  NEXT_STATE Selectstate (719,22) at 3073, 192
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 15 =>
                                 --  initA1 (726,17)
                                 p_0_initA1;
                                 --  KickTheDog (728,17)
                                 RI_0_KickTheDog;
                                 --  ok := call updateData (730,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (734,17)
                                 if (ctxt.ok) = true then
                                    null;
                                    --  ANSWER false (736,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (738,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (740,30) at 938, 510
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                                 --  DECISION (press <= press_10km and
                                 --  htl_time >= a1_duration_emergency) or
                                 --  htl_time >= a1_duration_max (744,35)
                                 --  ANSWER false (747,17)
                                 if ((((ctxt.press <= ctxt.press_10km) and (ctxt.htl_time >= ctxt.a1_duration_emergency)) or (ctxt.htl_time >= ctxt.a1_duration_max))) = false then
                                    --  doA1 (749,25)
                                    p_0_doA1;
                                    --  NEXT_STATE A1 (751,30) at 1014, 787
                                    trId := -1;
                                    ctxt.State := asn1SccA1;
                                    goto Next_Transition;
                                    --  ANSWER true (753,17)
                                 elsif ((((ctxt.press <= ctxt.press_10km) and (ctxt.htl_time >= ctxt.a1_duration_emergency)) or (ctxt.htl_time >= ctxt.a1_duration_max))) = true then
                                    --  NEXT_STATE A2 (755,30) at 1104, 737
                                    trId := -1;
                                    ctxt.State := asn1SccA2;
                                    goto Next_Transition;
                                 end if;
                              when 16 =>
                                 --  NEXT_STATE Selectstate (760,22) at 1374, 186
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 17 =>
                                 --  InitA2 (767,17)
                                 p_0_initA2;
                                 --  kickTheDog (769,17)
                                 RI_0_KickTheDog;
                                 --  ok := call updateData (771,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (775,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (777,35)
                                    --  COMMENT no estamos cayendo? (779,20)
                                    --  ANSWER True (781,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  writeln('Nos estamos cayendo') (783,33)
                                       Put ("Nos estamos cayendo");
                                       New_Line;
                                       --  NEXT_STATE F3 (785,38) at 1798, 631
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (787,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       null;
                                    end if;
                                    --  ANSWER false (790,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (792,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (794,30) at 2027, 501
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                                 --  DECISION htl_time >= a2_duration_max
                                 --  or press <= press_18km (798,0)
                                 --  ANSWER false (800,17)
                                 if (((ctxt.htl_time >= ctxt.a2_duration_max) or (ctxt.press <= ctxt.press_18km))) = false then
                                    --  doA2 (802,25)
                                    p_0_doA2;
                                    --  NEXT_STATE A2 (804,30) at 1542, 896
                                    trId := -1;
                                    ctxt.State := asn1SccA2;
                                    goto Next_Transition;
                                    --  ANSWER true (806,17)
                                 elsif (((ctxt.htl_time >= ctxt.a2_duration_max) or (ctxt.press <= ctxt.press_18km))) = true then
                                    --  writeln('A2 max duration: ', a2_duration_max) (808,25)
                                    Put ("A2 max duration: ");
                                    Put (asn1SccT_Double'Image (ctxt.a2_duration_max));
                                    New_Line;
                                    --  NEXT_STATE F1 (810,30) at 1734, 901
                                    trId := -1;
                                    ctxt.State := asn1SccF1;
                                    goto Next_Transition;
                                 end if;
                              when 18 =>
                                 --  NEXT_STATE Selectstate (815,22) at 2236, 182
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
                              --  DECISION actual_state = f2 (541,30)
                              --  ANSWER true (None,None)
                              if ((ctxt.actual_state = asn1Sccf2)) = true then
                                 trId := 2;
                                 --  Priority 1
                                 --  DECISION actual_state = a1 (545,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Scca1)) = true then
                                 trId := 3;
                                 --  Priority 1
                                 --  DECISION actual_state = a2 (549,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Scca2)) = true then
                                 trId := 4;
                                 --  Priority 1
                                 --  DECISION actual_state = f1 (553,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccf1)) = true then
                                 trId := 5;
                                 --  Priority 1
                                 --  DECISION actual_state = f3 (557,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccf3)) = true then
                                 trId := 6;
                                 --  Priority 1
                                 --  DECISION actual_state = error (561,30)
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