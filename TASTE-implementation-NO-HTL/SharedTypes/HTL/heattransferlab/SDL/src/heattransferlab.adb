-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !

with System.IO;
use System.IO;

with Ada.Unchecked_Conversion;
with Ada.Numerics.Generic_Elementary_Functions;

package body Heattransferlab is
   CS_Only : constant := 20;
   procedure Execute_Transition (Id : Integer);
   function p_0_updateData return asn1SccT_Boolean;
   procedure p_0_doA1;
   procedure p_0_doA2;
   procedure p_0_doF1;
   procedure p_0_doF2;
   procedure p_0_doF3;
   function p_0_updateData return asn1SccT_Boolean is
      pt1000s_data : asn1SccOBSW_DP_SingleData;
      press1_data : asn1SccOBSW_DP_SingleData;
      press2_data : asn1SccOBSW_DP_SingleData;
      gps_time : asn1SccT_Double;
      placa_arriba_ok : asn1SccT_Boolean;
      placa_abajo_ok : asn1SccT_Boolean;
      aire_infinito_ok : asn1SccT_Boolean;
      press1_ok : asn1SccT_Boolean;
      press2_ok : asn1SccT_Boolean;
      tmp4980 : asn1SccOBSW_DP_Filter;
      tmp5071 : asn1SccT_Float;
      tmp4988 : asn1SccOBSW_DP_Filter;
      tmp5106 : asn1SccT_Float;
      --  !! stack: _call_external_function line 1604
      tmp4984 : asn1SccOBSW_DP_Filter;
      tmp5080 : asn1SccT_Float;
      tmp5092 : asn1SccT_Float;
      tmp5049 : asn1SccT_Float;
      tmp5059 : asn1SccT_Float;
      begin
         --  getTime(gps_time, htl_time) (62,17)
         RI_0_getTime(gps_time, ctxt.htl_time);
         --  retreiveSingleData(pt1000s,pt1000s_data) (64,17)
         tmp4980 := asn1Sccpt1000s;
         RI_0_RetreiveSingleData(tmp4980, pt1000s_data);
         --  retreiveSingleData(ps1, press1_data) (66,17)
         tmp4984 := asn1Sccps1;
         RI_0_RetreiveSingleData(tmp4984, press1_data);
         --  retreiveSingleData(ps2, press2_data) (68,17)
         tmp4988 := asn1Sccps2;
         RI_0_RetreiveSingleData(tmp4988, press2_data);
         --  temp_air := 0.0 (70,17)
         ctxt.temp_air := 0.0;
         --  temp_plate := 0.0 (71,0)
         ctxt.temp_plate := 0.0;
         --  press := 0.0 (72,0)
         ctxt.press := 0.0;
         --  placa_abajo_ok := pt1000s_data.pt1000s.data.validity(6) = valid (74,0)
         placa_abajo_ok := (pt1000s_data.pt1000s.data.validity.Data(7) = asn1Sccvalid);
         --  placa_arriba_ok := pt1000s_data.pt1000s.data.validity(5) = valid (75,0)
         placa_arriba_ok := (pt1000s_data.pt1000s.data.validity.Data(6) = asn1Sccvalid);
         --  aire_infinito_ok := pt1000s_data.pt1000s.data.validity(2) = valid (76,0)
         aire_infinito_ok := (pt1000s_data.pt1000s.data.validity.Data(3) = asn1Sccvalid);
         --  press1_ok := press1_data.ps1.data.validity = valid (77,0)
         press1_ok := (press1_data.ps1.data.validity = asn1Sccvalid);
         --  press2_ok := press2_data.ps2.data.validity = valid (78,0)
         press2_ok := (press2_data.ps2.data.validity = asn1Sccvalid);
         --  DECISION (placa_abajo_ok or placa_arriba_ok)
         --  and aire_infinito_ok
         --  and (press1_ok or press2_ok) (82,0)
         --  ANSWER true (84,17)
         if ((((placa_abajo_ok or placa_arriba_ok) and aire_infinito_ok) and (press1_ok or press2_ok))) = true then
            --  temp_plate := if placa_arriba_ok then (pt1000s_data.pt1000s.data.celsius(5)) else 0.0 fi (86,25)
            if placa_arriba_ok then
               tmp5049 := pt1000s_data.pt1000s.data.celsius.Data(6);
            else
               tmp5049 := 0.0;
            end if;
            ctxt.temp_plate := tmp5049;
            --  temp_plate := if placa_abajo_ok then (pt1000s_data.pt1000s.data.celsius(6) + temp_plate) else temp_plate fi (87,0)
            if placa_abajo_ok then
               tmp5059 := (pt1000s_data.pt1000s.data.celsius.Data(7) + ctxt.temp_plate);
            else
               tmp5059 := ctxt.temp_plate;
            end if;
            ctxt.temp_plate := tmp5059;
            --  temp_plate := if placa_abajo_ok and placa_arriba_ok then temp_plate / 2.0 else temp_plate fi (88,0)
            if (placa_abajo_ok and placa_arriba_ok) then
               tmp5071 := (ctxt.temp_plate / 2.0);
            else
               tmp5071 := ctxt.temp_plate;
            end if;
            ctxt.temp_plate := tmp5071;
            --  press := if press1_ok then float(press1_data.ps1.data.processed.pressure) /100.0 else 0.0 fi (90,0)
            if press1_ok then
               tmp5080 := (Asn1Real(press1_data.ps1.data.processed.pressure) / 100.0);
            else
               tmp5080 := 0.0;
            end if;
            ctxt.press := tmp5080;
            --  press := if press2_ok then (float(press2_data.ps2.data.processed.pressure)/100.0 + press) else press fi (91,0)
            if press2_ok then
               tmp5092 := ((Asn1Real(press2_data.ps2.data.processed.pressure) / 100.0) + ctxt.press);
            else
               tmp5092 := ctxt.press;
            end if;
            ctxt.press := tmp5092;
            --  press := if press1_ok and press2_ok then press / 2.0 else press fi (92,0)
            if (press1_ok and press2_ok) then
               tmp5106 := (ctxt.press / 2.0);
            else
               tmp5106 := ctxt.press;
            end if;
            ctxt.press := tmp5106;
            --  temp_air := pt1000s_data.pt1000s.data.celsius(2) (94,0)
            ctxt.temp_air := pt1000s_data.pt1000s.data.celsius.Data(3);
            --  writeln('temp_plate: ', temp_plate) (96,25)
            Put ("temp_plate: ");
            Put (asn1SccT_Float'Image (ctxt.temp_plate));
            New_Line;
            --  writeln('press: ', press) (98,25)
            Put ("press: ");
            Put (asn1SccT_Float'Image (ctxt.press));
            New_Line;
            --  writeln('press 2 ok ', press2_ok) (100,25)
            Put ("press 2 ok ");
            Put (asn1SccT_Boolean'Image (press2_ok));
            New_Line;
            --  writeln('temp_air: ', temp_air) (102,25)
            Put ("temp_air: ");
            Put (asn1SccT_Float'Image (ctxt.temp_air));
            New_Line;
            --  RETURN True (None,None) at 407, 1165
            return true;
            --  ANSWER false (106,17)
         elsif ((((placa_abajo_ok or placa_arriba_ok) and aire_infinito_ok) and (press1_ok or press2_ok))) = false then
            --  writeln('invalid data :-(') (108,25)
            Put ("invalid data :-(");
            New_Line;
            --  RETURN False (None,None) at 1223, 828
            return false;
         end if;
      end p_0_updateData;
      

   procedure getCurrentMode(Current_State: in out asn1SccHTL_State) is
      begin
         --  writeln('actual status is', actual_state) (123,17)
         Put ("actual status is");
         Put (ctxt.actual_state'Img);
         New_Line;
         --  Current_State := actual_state (125,17)
         Current_State := ctxt.actual_state;
         --  getCurrentMode_Transition (None,None)
         getCurrentMode_Transition;
         --  RETURN  (None,None) at 603, 307
         return;
      end getCurrentMode;
      

   procedure p_0_doA1 is
      begin
         --  DECISION power = 0.0 (134,27)
         --  ANSWER false (136,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            null;
            --  ANSWER true (138,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  DECISION temp_plate <= 55.0 and abs(temp_plate -temp_air) <= 50.0 (140,48)
            --  ANSWER true (142,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               null;
               --  ANSWER false (144,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 983, 318
               return;
            end if;
         end if;
         --  DECISION temp_plate >= 65.0 or abs(temp_plate - temp_air) >= 60.0 (150,40)
         --  ANSWER true (152,17)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (154,25)
            ctxt.power := 0.0;
            --  ANSWER false (156,17)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := 1.2 (158,25)
            ctxt.power := 1.2;
         end if;
         --  setPowerH2(power) (161,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 518, 657
         return;
      end p_0_doA1;
      

   procedure p_0_doA2 is
      begin
         --  DECISION power = 0.0 (170,27)
         --  ANSWER false (172,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            --  JOIN normalA2 (None,None) at None, None
            goto normalA2;
            --  ANSWER true (192,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  DECISION temp_plate <= 55.0 and
            --  abs(temp_plate - temp_air) <= 50.0 (194,48)
            --  COMMENT Pdiss = 0.0 W (197,20)
            --  ANSWER true (199,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               --  JOIN normalA2 (201,33) at 757, 344
               goto normalA2;
               --  ANSWER false (203,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 861, 346
               return;
            end if;
         end if;
         --  setPowerH2(power) (209,17)
         RI_0_setPowerH2(ctxt.power);
         --  power_a2 := power (211,17)
         ctxt.power_a2 := ctxt.power;
         --  RETURN  (None,None) at 435, 607
         return;
         --  CONNECTION normalA2 (174,20)
         <<normalA2>>
         --  DECISION temp_plate >= 65.0 or
         --  abs(temp_plate - temp_air) >= 60.0 (176,48)
         --  COMMENT Pdiss = 1.0 (179,20)
         --  ANSWER false (181,25)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := 1.0 (183,33)
            ctxt.power := 1.0;
            --  ANSWER true (185,25)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (187,33)
            ctxt.power := 0.0;
         end if;
         --  writeln('normalA2') (190,25)
         Put ("normalA2");
         New_Line;
         --  setPowerH2(power) (209,17)
         RI_0_setPowerH2(ctxt.power);
         --  power_a2 := power (211,17)
         ctxt.power_a2 := ctxt.power;
         --  RETURN  (None,None) at 435, 607
         return;
      end p_0_doA2;
      

   procedure p_0_doF1 is
      begin
         --  DECISION power = 0.0 (220,27)
         --  ANSWER true (222,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  DECISION temp_plate <= 55.0 and
            --  abs(temp_plate - temp_air) <= 50.0 (224,48)
            --  ANSWER true (227,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               --  n := n+1.0 (229,33)
               ctxt.n := (ctxt.n + 1.0);
               --  JOIN normalF1 (231,33) at 599, 454
               goto normalF1;
               --  ANSWER false (233,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 706, 404
               return;
            end if;
            --  ANSWER false (238,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            --  JOIN normalF1 (None,None) at None, None
            goto normalF1;
         end if;
         --  CONNECTION normalF1 (240,20)
         <<normalF1>>
         --  DECISION temp_plate >= 65.0 or
         --  abs(temp_plate - temp_air) >= 60.0 (242,48)
         --  COMMENT ¿>= 60? (245,20)
         --  ANSWER true (247,25)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (249,33)
            ctxt.power := 0.0;
            --  ANSWER false (251,25)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := power_a2-n*0.1 (253,33)
            ctxt.power := (ctxt.power_a2 - (ctxt.n * 0.1));
            --  DECISION power <= 0.1 (255,43)
            --  ANSWER true (257,33)
            if ((ctxt.power <= 0.1)) = true then
               --  power := 0.1 (259,41)
               ctxt.power := 0.1;
               --  ANSWER false (261,33)
            elsif ((ctxt.power <= 0.1)) = false then
               null;
            end if;
         end if;
         --  setPowerH2(power) (265,25)
         RI_0_setPowerH2(ctxt.power);
         --  power_f1 := power (267,25)
         ctxt.power_f1 := ctxt.power;
         --  RETURN  (None,None) at 306, 756
         return;
      end p_0_doF1;
      

   procedure p_0_doF2 is
      begin
         --  DECISION power = 0.0 (277,27)
         --  ANSWER false (279,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            null;
            --  ANSWER true (281,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  DECISION temp_plate <= 55.0 and
            --  abs(temp_plate - temp_air) <= 50.0 (283,48)
            --  ANSWER true (286,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               --  m := m+0.1 (288,33)
               ctxt.m := (ctxt.m + 0.1);
               --  ANSWER false (290,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 601, 362
               return;
            end if;
         end if;
         --  DECISION temp_plate >= 65.0 or 
         --  abs (temp_plate - temp_air) >= 60.0 (296,40)
         --  COMMENT >= 60? (299,12)
         --  ANSWER true (301,17)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (303,25)
            ctxt.power := 0.0;
            --  ANSWER false (305,17)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := power_f1/2.0 - m*0.1 (307,25)
            ctxt.power := ((ctxt.power_f1 / 2.0) - (ctxt.m * 0.1));
            --  DECISION power <= 0.1 (309,35)
            --  ANSWER true (311,25)
            if ((ctxt.power <= 0.1)) = true then
               --  power := 0.1 (313,33)
               ctxt.power := 0.1;
               --  ANSWER false (315,25)
            elsif ((ctxt.power <= 0.1)) = false then
               null;
            end if;
         end if;
         --  setPowerH2(power) (319,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 439, 851
         return;
      end p_0_doF2;
      

   procedure p_0_doF3 is
      tmp5351 : asn1SccT_Float;
      --  !! stack: _call_external_function line 1604
      begin
         --  ok := call updateData (328,17)
         ctxt.ok := p_0_updatedata;
         --  DECISION ok and power = 0.0 (330,24)
         --  ANSWER true (332,17)
         if ((ctxt.ok and asn1SccT_Float_Equal (ctxt.power, 0.0))) = true then
            null;
            --  ANSWER false (334,17)
         elsif ((ctxt.ok and asn1SccT_Float_Equal (ctxt.power, 0.0))) = false then
            --  setPowerH2(0.0) (336,25)
            tmp5351 := 0.0;
            RI_0_setPowerH2(tmp5351);
         end if;
         --  RETURN  (None,None) at 354, 381
         return;
      end p_0_doF3;
      

   procedure configureParameters(Configuration: in out asn1SccHTL_Config) is
      tmp5413 : asn1SccT_Double;
      tmp5353 : asn1SccT_Float;
      tmp5377 : asn1SccT_UInt32;
      tmp5397 : asn1SccT_Double;
      tmp5387 : asn1SccT_UInt32;
      tmp5369 : asn1SccT_Float;
      tmp5361 : asn1SccT_Float;
      tmp5405 : asn1SccT_Double;
      begin
         --  press_5km  := if exist (Configuration.press_5km) then Configuration.press_5km else press_5km fi (352,17)
         if (Configuration.exist.press_5km = 1) then
            tmp5353 := Configuration.press_5km;
         else
            tmp5353 := ctxt.press_5km;
         end if;
         ctxt.press_5km := tmp5353;
         --  press_10km := if exist(Configuration.press_10km) then Configuration.press_10km else press_10km fi (353,0)
         if (Configuration.exist.press_10km = 1) then
            tmp5361 := Configuration.press_10km;
         else
            tmp5361 := ctxt.press_10km;
         end if;
         ctxt.press_10km := tmp5361;
         --  press_18km := if exist(Configuration.press_18km) then Configuration.press_18km else press_18km fi (354,0)
         if (Configuration.exist.press_18km = 1) then
            tmp5369 := Configuration.press_18km;
         else
            tmp5369 := ctxt.press_18km;
         end if;
         ctxt.press_18km := tmp5369;
         --  f1_duration :=
         --   if exist(Configuration.f1_duration_secs) then
            --     Configuration.f1_duration_secs * 1000
            --  else
            --    f1_duration
            --  fi (356,0)
            if (Configuration.exist.f1_duration_secs = 1) then
               tmp5377 := (Configuration.f1_duration_secs * 1000);
            else
               tmp5377 := ctxt.f1_duration;
            end if;
            ctxt.f1_duration := tmp5377;
            --  f2_duration :=
            --  if exist(Configuration.f2_duration_secs) then
               --    Configuration.f2_duration_secs * 1000
               --  else
               --    f2_duration
               --  fi (363,0)
               if (Configuration.exist.f2_duration_secs = 1) then
                  tmp5387 := (Configuration.f2_duration_secs * 1000);
               else
                  tmp5387 := ctxt.f2_duration;
               end if;
               ctxt.f2_duration := tmp5387;
               --  a1_duration_emergency :=
               --  if exist(Configuration.a1_duration_emergency_secs) then
                  --    Configuration.a1_duration_emergency_secs
                  --  else
                  --    a1_duration_emergency
                  --  fi (370,0)
                  if (Configuration.exist.a1_duration_emergency_secs = 1) then
                     tmp5397 := Configuration.a1_duration_emergency_secs;
                  else
                     tmp5397 := ctxt.a1_duration_emergency;
                  end if;
                  ctxt.a1_duration_emergency := tmp5397;
                  --  a1_duration_max :=
                  --  if exist(Configuration.a1_duration_max_secs) then
                     --    Configuration.a1_duration_max_secs
                     --  else
                     --    a1_duration_max
                     --  fi (377,0)
                     if (Configuration.exist.a1_duration_max_secs = 1) then
                        tmp5405 := Configuration.a1_duration_max_secs;
                     else
                        tmp5405 := ctxt.a1_duration_max;
                     end if;
                     ctxt.a1_duration_max := tmp5405;
                     --  a2_duration_max :=
                     --  if exist(Configuration.a2_duration_max_secs) then
                        --    Configuration.a2_duration_max_secs
                        --  else
                        --    a2_duration_max
                        --  fi (384,0)
                        if (Configuration.exist.a2_duration_max_secs = 1) then
                           tmp5413 := Configuration.a2_duration_max_secs;
                        else
                           tmp5413 := ctxt.a2_duration_max;
                        end if;
                        ctxt.a2_duration_max := tmp5413;
                        --  configureParameters_Transition (None,None)
                        configureParameters_Transition;
                        --  RETURN  (None,None) at 931, 777
                        return;
                     end configureParameters;
                     

                  procedure setCurrentMode(current_state: in out asn1SccHTL_State) is
                     begin
                        case ctxt.state is
                           when asn1Sccf2 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (13);
                           when asn1Sccf3 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (11);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (2);
                           when asn1Sccf1 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (17);
                           when asn1Scca2 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (19);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end setCurrentMode;
                     

                  procedure tick is
                     begin
                        case ctxt.state is
                           when asn1Sccf2 =>
                              Execute_Transition (12);
                           when asn1Sccf3 =>
                              Execute_Transition (10);
                           when asn1Sccerror =>
                              Execute_Transition (9);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
                              Execute_Transition (1);
                           when asn1Sccf1 =>
                              Execute_Transition (15);
                           when asn1Scca2 =>
                              Execute_Transition (18);
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
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
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
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
                              Execute_Transition (CS_Only);
                           when asn1Scca2 =>
                              Execute_Transition (CS_Only);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end getCurrentMode_Transition;
                     

                  procedure f1_timeout is
                     begin
                        case ctxt.state is
                           when asn1Sccf2 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf3 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
                              Execute_Transition (16);
                           when asn1Scca2 =>
                              Execute_Transition (CS_Only);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end f1_timeout;
                     

                  procedure f2_timeout is
                     begin
                        case ctxt.state is
                           when asn1Sccf2 =>
                              Execute_Transition (14);
                           when asn1Sccf3 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
                              Execute_Transition (CS_Only);
                           when asn1Scca2 =>
                              Execute_Transition (CS_Only);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end f2_timeout;
                     

                  procedure Execute_Transition (Id : Integer) is
                     trId : Integer := Id;
                     msgPending : Asn1Boolean := True;
                     tmp4936 : asn1SccT_UInt32;
                     tmp4861 : asn1SccT_UInt32;
                     tmp4972 : asn1SccT_UInt32;
                     tmp4874 : asn1SccT_UInt32;
                     begin
                        while (trId /= -1) loop
                           case trId is
                              when 0 =>
                                 --  NEXT_STATE A1 (396,18) at 515, 65
                                 trId := -1;
                                 ctxt.State := asn1SccA1;
                                 goto Next_Transition;
                              when 1 =>
                                 --  actual_state := a1 (402,17)
                                 ctxt.actual_state := asn1Scca1;
                                 --  ok := call updateData (403,0)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (407,17)
                                 if (ctxt.ok) = true then
                                    null;
                                    --  ANSWER false (409,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (411,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (413,30) at 1391, 340
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                                 --  DECISION (press <= press_10km and
                                 --  htl_time >= a1_duration_emergency) or
                                 --  htl_time >= a1_duration_max (417,35)
                                 --  ANSWER false (420,17)
                                 if ((((ctxt.press <= ctxt.press_10km) and (ctxt.htl_time >= ctxt.a1_duration_emergency)) or (ctxt.htl_time >= ctxt.a1_duration_max))) = false then
                                    --  doA1 (422,25)
                                    p_0_doA1;
                                    --  NEXT_STATE A1 (424,30) at 1104, 617
                                    trId := -1;
                                    ctxt.State := asn1SccA1;
                                    goto Next_Transition;
                                    --  ANSWER true (426,17)
                                 elsif ((((ctxt.press <= ctxt.press_10km) and (ctxt.htl_time >= ctxt.a1_duration_emergency)) or (ctxt.htl_time >= ctxt.a1_duration_max))) = true then
                                    --  NEXT_STATE A2 (428,30) at 1194, 567
                                    trId := -1;
                                    ctxt.State := asn1SccA2;
                                    goto Next_Transition;
                                 end if;
                              when 2 =>
                                 --  NEXT_STATE Selectstate (433,22) at 1706, 116
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 3 =>
                                 --  set_timer(f2_duration, f2_timeout) (440,17)
                                 tmp4861 := ctxt.f2_duration;
                                 SET_f2_timeout (tmp4861);
                                 --  NEXT_STATE F2 (442,22) at 685, 530
                                 trId := -1;
                                 ctxt.State := asn1SccF2;
                                 goto Next_Transition;
                              when 4 =>
                                 --  NEXT_STATE A1 (446,22) at 419, 393
                                 trId := -1;
                                 ctxt.State := asn1SccA1;
                                 goto Next_Transition;
                              when 5 =>
                                 --  NEXT_STATE A2 (450,22) at 479, 516
                                 trId := -1;
                                 ctxt.State := asn1SccA2;
                                 goto Next_Transition;
                              when 6 =>
                                 --  set_timer(f1_duration,f1_timeout) (454,17)
                                 tmp4874 := ctxt.f1_duration;
                                 SET_f1_timeout (tmp4874);
                                 --  NEXT_STATE F1 (456,22) at 572, 683
                                 trId := -1;
                                 ctxt.State := asn1SccF1;
                                 goto Next_Transition;
                              when 7 =>
                                 --  NEXT_STATE F3 (460,22) at 789, 335
                                 trId := -1;
                                 ctxt.State := asn1SccF3;
                                 goto Next_Transition;
                              when 8 =>
                                 --  NEXT_STATE Error (464,22) at 881, 475
                                 trId := -1;
                                 ctxt.State := asn1SccError;
                                 goto Next_Transition;
                              when 9 =>
                                 --  ok := call updateData (471,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  actual_state := error (472,0)
                                 ctxt.actual_state := asn1Sccerror;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (476,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION last_good_state (-1,-1)
                                    --  ANSWER a1 (480,25)
                                    if (ctxt.last_good_state) = asn1Scca1 then
                                       --  NEXT_STATE A1 (482,38) at 2062, 1169
                                       trId := -1;
                                       ctxt.State := asn1SccA1;
                                       goto Next_Transition;
                                       --  ANSWER a2 (484,25)
                                    elsif (ctxt.last_good_state) = asn1Scca2 then
                                       --  NEXT_STATE A2 (486,38) at 2152, 1169
                                       trId := -1;
                                       ctxt.State := asn1SccA2;
                                       goto Next_Transition;
                                       --  ANSWER f1 (488,25)
                                    elsif (ctxt.last_good_state) = asn1Sccf1 then
                                       --  NEXT_STATE F1 (490,38) at 2242, 1169
                                       trId := -1;
                                       ctxt.State := asn1SccF1;
                                       goto Next_Transition;
                                       --  ANSWER f2 (492,25)
                                    elsif (ctxt.last_good_state) = asn1Sccf2 then
                                       --  NEXT_STATE F2 (494,38) at 2332, 1169
                                       trId := -1;
                                       ctxt.State := asn1SccF2;
                                       goto Next_Transition;
                                       --  ANSWER else (None,None)
                                    else
                                       --  NEXT_STATE Error (498,38) at 2422, 1174
                                       trId := -1;
                                       ctxt.State := asn1SccError;
                                       goto Next_Transition;
                                    end if;
                                    --  ANSWER false (501,17)
                                 elsif (ctxt.ok) = false then
                                    --  NEXT_STATE Error (503,30) at 2503, 1055
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 10 =>
                                 --  actual_state := f3 (511,17)
                                 ctxt.actual_state := asn1Sccf3;
                                 --  doF3 (513,17)
                                 p_0_doF3;
                                 --  NEXT_STATE F3 (515,22) at 1550, 974
                                 trId := -1;
                                 ctxt.State := asn1SccF3;
                                 goto Next_Transition;
                              when 11 =>
                                 --  NEXT_STATE Selectstate (519,22) at 1716, 864
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 12 =>
                                 --  actual_state := f2 (526,17)
                                 ctxt.actual_state := asn1Sccf2;
                                 --  ok := call updateData (527,0)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (531,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (533,35)
                                    --  ANSWER True (535,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  NEXT_STATE F3 (537,38) at 1030, 1148
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (539,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       --  doF2 (541,33)
                                       p_0_doF2;
                                       --  NEXT_STATE F2 (543,38) at 908, 1193
                                       trId := -1;
                                       ctxt.State := asn1SccF2;
                                       goto Next_Transition;
                                    end if;
                                    --  ANSWER false (546,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state:=actual_state (548,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (550,30) at 761, 1089
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 13 =>
                                 --  NEXT_STATE Selectstate (555,22) at 1177, 865
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 14 =>
                                 --  writeln('F2 timeout!!!') (559,17)
                                 Put ("F2 timeout!!!");
                                 New_Line;
                                 --  NEXT_STATE F3 (561,22) at 1387, 915
                                 trId := -1;
                                 ctxt.State := asn1SccF3;
                                 goto Next_Transition;
                              when 15 =>
                                 --  actual_state := f1 (568,17)
                                 ctxt.actual_state := asn1Sccf1;
                                 --  ok := call updateData (569,0)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (573,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (575,35)
                                    --  ANSWER True (577,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  NEXT_STATE F3 (579,38) at 2835, 416
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (581,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       --  doF1 (583,33)
                                       p_0_doF1;
                                       --  NEXT_STATE F1 (585,38) at 2696, 466
                                       trId := -1;
                                       ctxt.State := asn1SccF1;
                                       goto Next_Transition;
                                    end if;
                                    --  ANSWER false (588,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (590,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (592,30) at 2547, 340
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 16 =>
                                 --  writeln('F1 timeout!!!') (597,17)
                                 Put ("F1 timeout!!!");
                                 New_Line;
                                 --  set_timer(f2_duration, f2_timeout) (599,17)
                                 tmp4936 := ctxt.f2_duration;
                                 SET_f2_timeout (tmp4936);
                                 --  NEXT_STATE F2 (601,22) at 3210, 221
                                 trId := -1;
                                 ctxt.State := asn1SccF2;
                                 goto Next_Transition;
                              when 17 =>
                                 --  NEXT_STATE Selectstate (605,22) at 2972, 114
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 18 =>
                                 --  actual_state := a2 (612,17)
                                 ctxt.actual_state := asn1Scca2;
                                 --  ok := call updateData (613,0)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (617,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (619,35)
                                    --  COMMENT no estamos cayendo? (621,20)
                                    --  ANSWER True (623,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  writeln('Nos estamos cayendo') (625,33)
                                       Put ("Nos estamos cayendo");
                                       New_Line;
                                       --  NEXT_STATE F3 (627,38) at 2103, 467
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (629,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       null;
                                    end if;
                                    --  ANSWER false (632,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (634,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (636,30) at 2321, 337
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                                 --  DECISION htl_time >= a2_duration_max
                                 --  or press <= press_18km (640,0)
                                 --  ANSWER false (642,17)
                                 if (((ctxt.htl_time >= ctxt.a2_duration_max) or (ctxt.press <= ctxt.press_18km))) = false then
                                    --  doA2 (644,25)
                                    p_0_doA2;
                                    --  NEXT_STATE A2 (646,30) at 1892, 726
                                    trId := -1;
                                    ctxt.State := asn1SccA2;
                                    goto Next_Transition;
                                    --  ANSWER true (648,17)
                                 elsif (((ctxt.htl_time >= ctxt.a2_duration_max) or (ctxt.press <= ctxt.press_18km))) = true then
                                    --  writeln('A2 max duration: ', a2_duration_max) (650,25)
                                    Put ("A2 max duration: ");
                                    Put (asn1SccT_Double'Image (ctxt.a2_duration_max));
                                    New_Line;
                                    --  set_timer(f1_duration, f1_timeout) (652,25)
                                    tmp4972 := ctxt.f1_duration;
                                    SET_f1_timeout (tmp4972);
                                    --  NEXT_STATE F1 (654,30) at 2084, 781
                                    trId := -1;
                                    ctxt.State := asn1SccF1;
                                    goto Next_Transition;
                                 end if;
                              when 19 =>
                                 --  NEXT_STATE Selectstate (659,22) at 2524, 118
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
                              --  DECISION actual_state = f2 (438,30)
                              --  ANSWER true (None,None)
                              if ((ctxt.actual_state = asn1Sccf2)) = true then
                                 trId := 3;
                                 --  Priority 1
                                 --  DECISION actual_state = a1 (444,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Scca1)) = true then
                                 trId := 4;
                                 --  Priority 1
                                 --  DECISION actual_state = a2 (448,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Scca2)) = true then
                                 trId := 5;
                                 --  Priority 1
                                 --  DECISION actual_state = f1 (452,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccf1)) = true then
                                 trId := 6;
                                 --  Priority 1
                                 --  DECISION actual_state = f3 (458,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccf3)) = true then
                                 trId := 7;
                                 --  Priority 1
                                 --  DECISION actual_state = error (462,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccerror)) = true then
                                 trId := 8;
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