-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !

with System.IO;
use System.IO;

with Ada.Unchecked_Conversion;
with Ada.Numerics.Generic_Elementary_Functions;

package body Heattransferlab is
   CS_Only : constant := 20;
   procedure Execute_Transition (Id : Integer);
   procedure p_0_doF3;
   procedure p_0_doF2;
   procedure p_0_doA2;
   procedure p_0_doA1;
   procedure p_0_doF1;
   function p_0_updateData return asn1SccT_Boolean;
   procedure p_0_doF3 is
      tmp13960 : asn1SccT_Float;
      --  !! stack: _call_external_function line 1604
      begin
         --  ok := call updateData (47,17)
         ctxt.ok := p_0_updatedata;
         --  DECISION ok and power = 0.0 (49,24)
         --  ANSWER true (51,17)
         if ((ctxt.ok and asn1SccT_Float_Equal (ctxt.power, 0.0))) = true then
            null;
            --  ANSWER false (53,17)
         elsif ((ctxt.ok and asn1SccT_Float_Equal (ctxt.power, 0.0))) = false then
            --  setPowerH2(0.0) (55,25)
            tmp13960 := 0.0;
            RI_0_setPowerH2(tmp13960);
         end if;
         --  RETURN  (None,None) at 354, 381
         return;
      end p_0_doF3;
      

   procedure p_0_doF2 is
      begin
         --  DECISION power = 0.0 (65,27)
         --  ANSWER false (67,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            null;
            --  ANSWER true (69,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  DECISION temp_plate <= 55.0 and
            --  abs(temp_plate - temp_air) <= 50.0 (71,48)
            --  ANSWER true (74,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               --  m := m+0.1 (76,33)
               ctxt.m := (ctxt.m + 0.1);
               --  ANSWER false (78,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 601, 362
               return;
            end if;
         end if;
         --  DECISION temp_plate >= 65.0 or 
         --  abs (temp_plate - temp_air) >= 60.0 (84,40)
         --  COMMENT >= 60? (87,12)
         --  ANSWER true (89,17)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (91,25)
            ctxt.power := 0.0;
            --  ANSWER false (93,17)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := power_f1/2.0 - m*0.1 (95,25)
            ctxt.power := ((ctxt.power_f1 / 2.0) - (ctxt.m * 0.1));
            --  DECISION power <= 0.1 (97,35)
            --  ANSWER true (99,25)
            if ((ctxt.power <= 0.1)) = true then
               --  power := 0.1 (101,33)
               ctxt.power := 0.1;
               --  ANSWER false (103,25)
            elsif ((ctxt.power <= 0.1)) = false then
               null;
            end if;
         end if;
         --  setPowerH2(power) (107,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 439, 851
         return;
      end p_0_doF2;
      

   procedure p_0_doA2 is
      begin
         --  DECISION power = 0.0 (116,27)
         --  ANSWER false (118,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            --  JOIN normalA2 (None,None) at None, None
            goto normalA2;
            --  ANSWER true (140,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  DECISION temp_plate <= 55.0 and
            --  abs(temp_plate - temp_air) <= 50.0 (142,48)
            --  COMMENT Pdiss = 0.0 W (145,20)
            --  ANSWER true (147,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               --  JOIN normalA2 (149,33) at 757, 344
               goto normalA2;
               --  ANSWER false (151,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 861, 346
               return;
            end if;
         end if;
         --  setPowerH2(power) (157,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 435, 612
         return;
         --  CONNECTION normalA2 (120,20)
         <<normalA2>>
         --  DECISION temp_plate >= 65.0 or
         --  abs(temp_plate - temp_air) >= 60.0 (122,48)
         --  COMMENT Pdiss = 1.0 (125,20)
         --  ANSWER false (127,25)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := 0.6 (129,33)
            ctxt.power := 0.6;
            --  power_a2 := power (131,33)
            ctxt.power_a2 := ctxt.power;
            --  ANSWER true (133,25)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (135,33)
            ctxt.power := 0.0;
         end if;
         --  writeln('normalA2') (138,25)
         Put ("normalA2");
         New_Line;
         --  setPowerH2(power) (157,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 435, 612
         return;
      end p_0_doA2;
      

   procedure p_0_doA1 is
      begin
         --  DECISION power = 0.0 (166,27)
         --  ANSWER false (168,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            null;
            --  ANSWER true (170,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  DECISION temp_plate <= 55.0 and abs(temp_plate -temp_air) <= 50.0 (172,48)
            --  ANSWER true (174,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               null;
               --  ANSWER false (176,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 983, 318
               return;
            end if;
         end if;
         --  DECISION temp_plate >= 65.0 or abs(temp_plate - temp_air) >= 60.0 (182,40)
         --  ANSWER true (184,17)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (186,25)
            ctxt.power := 0.0;
            --  ANSWER false (188,17)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := 0.8 (190,25)
            ctxt.power := 0.8;
         end if;
         --  setPowerH2(power) (193,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 518, 657
         return;
      end p_0_doA1;
      

   procedure p_0_doF1 is
      begin
         --  DECISION power = 0.0 (202,27)
         --  ANSWER true (204,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  DECISION temp_plate <= 55.0 and
            --  abs(temp_plate - temp_air) <= 50.0 (206,48)
            --  ANSWER true (209,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               --  n := n+1.0 (211,33)
               ctxt.n := (ctxt.n + 1.0);
               --  JOIN normalF1 (213,33) at 599, 454
               goto normalF1;
               --  ANSWER false (215,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 706, 404
               return;
            end if;
            --  ANSWER false (220,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            --  JOIN normalF1 (None,None) at None, None
            goto normalF1;
         end if;
         --  CONNECTION normalF1 (222,20)
         <<normalF1>>
         --  DECISION temp_plate >= 65.0 or
         --  abs(temp_plate - temp_air) >= 60.0 (224,48)
         --  COMMENT ¿>= 60? (227,20)
         --  ANSWER true (229,25)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (231,33)
            ctxt.power := 0.0;
            --  ANSWER false (233,25)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := power_a2-n*0.1 (235,33)
            ctxt.power := (ctxt.power_a2 - (ctxt.n * 0.1));
            --  DECISION power <= 0.1 (237,43)
            --  ANSWER true (239,33)
            if ((ctxt.power <= 0.1)) = true then
               --  power := 0.1 (241,41)
               ctxt.power := 0.1;
               --  ANSWER false (243,33)
            elsif ((ctxt.power <= 0.1)) = false then
               null;
            end if;
            --  power_f1 := power (246,33)
            ctxt.power_f1 := ctxt.power;
         end if;
         --  setPowerH2(power) (249,25)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 306, 742
         return;
      end p_0_doF1;
      

   procedure configureParameters(Configuration: in out asn1SccHTL_Config) is
      tmp14188 : asn1SccT_UInt32;
      tmp14178 : asn1SccT_UInt32;
      tmp14162 : asn1SccT_Float;
      tmp14170 : asn1SccT_Float;
      tmp14206 : asn1SccT_Double;
      tmp14214 : asn1SccT_Double;
      tmp14198 : asn1SccT_Double;
      tmp14154 : asn1SccT_Float;
      begin
         --  press_5km  := if exist (Configuration.press_5km) then Configuration.press_5km else press_5km fi (265,17)
         if (Configuration.exist.press_5km = 1) then
            tmp14154 := Configuration.press_5km;
         else
            tmp14154 := ctxt.press_5km;
         end if;
         ctxt.press_5km := tmp14154;
         --  press_10km := if exist(Configuration.press_10km) then Configuration.press_10km else press_10km fi (266,0)
         if (Configuration.exist.press_10km = 1) then
            tmp14162 := Configuration.press_10km;
         else
            tmp14162 := ctxt.press_10km;
         end if;
         ctxt.press_10km := tmp14162;
         --  press_18km := if exist(Configuration.press_18km) then Configuration.press_18km else press_18km fi (267,0)
         if (Configuration.exist.press_18km = 1) then
            tmp14170 := Configuration.press_18km;
         else
            tmp14170 := ctxt.press_18km;
         end if;
         ctxt.press_18km := tmp14170;
         --  f1_duration :=
         --   if exist(Configuration.f1_duration_secs) then
            --     Configuration.f1_duration_secs * 1000
            --  else
            --    f1_duration
            --  fi (269,0)
            if (Configuration.exist.f1_duration_secs = 1) then
               tmp14178 := (Configuration.f1_duration_secs * 1000);
            else
               tmp14178 := ctxt.f1_duration;
            end if;
            ctxt.f1_duration := tmp14178;
            --  f2_duration :=
            --  if exist(Configuration.f2_duration_secs) then
               --    Configuration.f2_duration_secs * 1000
               --  else
               --    f2_duration
               --  fi (276,0)
               if (Configuration.exist.f2_duration_secs = 1) then
                  tmp14188 := (Configuration.f2_duration_secs * 1000);
               else
                  tmp14188 := ctxt.f2_duration;
               end if;
               ctxt.f2_duration := tmp14188;
               --  a1_duration_emergency :=
               --  if exist(Configuration.a1_duration_emergency_secs) then
                  --    Configuration.a1_duration_emergency_secs
                  --  else
                  --    a1_duration_emergency
                  --  fi (283,0)
                  if (Configuration.exist.a1_duration_emergency_secs = 1) then
                     tmp14198 := Configuration.a1_duration_emergency_secs;
                  else
                     tmp14198 := ctxt.a1_duration_emergency;
                  end if;
                  ctxt.a1_duration_emergency := tmp14198;
                  --  a1_duration_max :=
                  --  if exist(Configuration.a1_duration_max_secs) then
                     --    Configuration.a1_duration_max_secs
                     --  else
                     --    a1_duration_max
                     --  fi (290,0)
                     if (Configuration.exist.a1_duration_max_secs = 1) then
                        tmp14206 := Configuration.a1_duration_max_secs;
                     else
                        tmp14206 := ctxt.a1_duration_max;
                     end if;
                     ctxt.a1_duration_max := tmp14206;
                     --  a2_duration_max :=
                     --  if exist(Configuration.a2_duration_max_secs) then
                        --    Configuration.a2_duration_max_secs
                        --  else
                        --    a2_duration_max
                        --  fi (297,0)
                        if (Configuration.exist.a2_duration_max_secs = 1) then
                           tmp14214 := Configuration.a2_duration_max_secs;
                        else
                           tmp14214 := ctxt.a2_duration_max;
                        end if;
                        ctxt.a2_duration_max := tmp14214;
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
                     tmp14340 : asn1SccT_Float;
                     tmp14319 : asn1SccT_Float;
                     tmp14227 : asn1SccOBSW_DP_Filter;
                     tmp14239 : asn1SccOBSW_DP_Filter;
                     tmp14331 : asn1SccT_Float;
                     tmp14352 : asn1SccT_Float;
                     tmp14309 : asn1SccT_Float;
                     tmp14231 : asn1SccOBSW_DP_Filter;
                     --  !! stack: _call_external_function line 1604
                     tmp14366 : asn1SccT_Float;
                     tmp14235 : asn1SccOBSW_DP_Filter;
                     begin
                        --  getTime(gps_time, htl_time) (328,17)
                        RI_0_getTime(gps_time, ctxt.htl_time);
                        --  retreiveSingleData(pt1000s,pt1000s_data) (330,17)
                        tmp14227 := asn1Sccpt1000s;
                        RI_0_RetreiveSingleData(tmp14227, pt1000s_data);
                        --  retreiveSingleData(ps1, press1_data) (332,17)
                        tmp14231 := asn1Sccps1;
                        RI_0_RetreiveSingleData(tmp14231, press1_data);
                        --  retreiveSingleData(ps2, press2_data) (334,17)
                        tmp14235 := asn1Sccps2;
                        RI_0_RetreiveSingleData(tmp14235, press2_data);
                        --  retreiveSingleData(heater2, power_data) (336,17)
                        tmp14239 := asn1Sccheater2;
                        RI_0_RetreiveSingleData(tmp14239, power_data);
                        --  temp_air := 0.0 (338,17)
                        ctxt.temp_air := 0.0;
                        --  temp_plate := 0.0 (339,0)
                        ctxt.temp_plate := 0.0;
                        --  press := 0.0 (340,0)
                        ctxt.press := 0.0;
                        --  placa_abajo_ok := pt1000s_data.pt1000s.data.validity(6) = valid (342,0)
                        placa_abajo_ok := (pt1000s_data.pt1000s.data.validity.Data(7) = asn1Sccvalid);
                        --  placa_arriba_ok := pt1000s_data.pt1000s.data.validity(5) = valid (343,0)
                        placa_arriba_ok := (pt1000s_data.pt1000s.data.validity.Data(6) = asn1Sccvalid);
                        --  aire_infinito_ok := pt1000s_data.pt1000s.data.validity(2) = valid (344,0)
                        aire_infinito_ok := (pt1000s_data.pt1000s.data.validity.Data(3) = asn1Sccvalid);
                        --  press1_ok := press1_data.ps1.data.validity = valid (345,0)
                        press1_ok := (press1_data.ps1.data.validity = asn1Sccvalid);
                        --  press2_ok := press2_data.ps2.data.validity = valid (346,0)
                        press2_ok := (press2_data.ps2.data.validity = asn1Sccvalid);
                        --  power_ok := power_data.heater2.data.validity = valid (347,0)
                        power_ok := (power_data.heater2.data.validity = asn1Sccvalid);
                        --  DECISION power_ok and
                        --  (placa_abajo_ok or placa_arriba_ok)
                        --  and aire_infinito_ok
                        --  and (press1_ok or press2_ok) (352,0)
                        --  ANSWER true (354,17)
                        if ((((power_ok and (placa_abajo_ok or placa_arriba_ok)) and aire_infinito_ok) and (press1_ok or press2_ok))) = true then
                           --  temp_plate := if placa_arriba_ok then (pt1000s_data.pt1000s.data.celsius(5)) else 0.0 fi (356,25)
                           if placa_arriba_ok then
                              tmp14309 := pt1000s_data.pt1000s.data.celsius.Data(6);
                           else
                              tmp14309 := 0.0;
                           end if;
                           ctxt.temp_plate := tmp14309;
                           --  temp_plate := if placa_abajo_ok then (pt1000s_data.pt1000s.data.celsius(6) + temp_plate) else temp_plate fi (357,0)
                           if placa_abajo_ok then
                              tmp14319 := (pt1000s_data.pt1000s.data.celsius.Data(7) + ctxt.temp_plate);
                           else
                              tmp14319 := ctxt.temp_plate;
                           end if;
                           ctxt.temp_plate := tmp14319;
                           --  temp_plate := if placa_abajo_ok and placa_arriba_ok then temp_plate / 2.0 else temp_plate fi (358,0)
                           if (placa_abajo_ok and placa_arriba_ok) then
                              tmp14331 := (ctxt.temp_plate / 2.0);
                           else
                              tmp14331 := ctxt.temp_plate;
                           end if;
                           ctxt.temp_plate := tmp14331;
                           --  press := if press1_ok then float(press1_data.ps1.data.processed.pressure) /100.0 else 0.0 fi (360,0)
                           if press1_ok then
                              tmp14340 := (Asn1Real(press1_data.ps1.data.processed.pressure) / 100.0);
                           else
                              tmp14340 := 0.0;
                           end if;
                           ctxt.press := tmp14340;
                           --  press := if press2_ok then (float(press2_data.ps2.data.processed.pressure)/100.0 + press) else press fi (361,0)
                           if press2_ok then
                              tmp14352 := ((Asn1Real(press2_data.ps2.data.processed.pressure) / 100.0) + ctxt.press);
                           else
                              tmp14352 := ctxt.press;
                           end if;
                           ctxt.press := tmp14352;
                           --  press := if press1_ok and press2_ok then press / 2.0 else press fi (362,0)
                           if (press1_ok and press2_ok) then
                              tmp14366 := (ctxt.press / 2.0);
                           else
                              tmp14366 := ctxt.press;
                           end if;
                           ctxt.press := tmp14366;
                           --  temp_air := pt1000s_data.pt1000s.data.celsius(2) (364,0)
                           ctxt.temp_air := pt1000s_data.pt1000s.data.celsius.Data(3);
                           --  power := power_data.heater2.data.power_watts (366,0)
                           ctxt.power := power_data.heater2.data.power_watts;
                           --  writeln('temp_plate: ', temp_plate) (368,25)
                           Put ("temp_plate: ");
                           Put (asn1SccT_Float'Image (ctxt.temp_plate));
                           New_Line;
                           --  writeln('power: ', power) (370,25)
                           Put ("power: ");
                           Put (asn1SccT_Float'Image (ctxt.power));
                           New_Line;
                           --  writeln('press: ', press) (372,25)
                           Put ("press: ");
                           Put (asn1SccT_Float'Image (ctxt.press));
                           New_Line;
                           --  writeln('press 2 ok ', press2_ok) (374,25)
                           Put ("press 2 ok ");
                           Put (asn1SccT_Boolean'Image (press2_ok));
                           New_Line;
                           --  writeln('temp_air: ', temp_air) (376,25)
                           Put ("temp_air: ");
                           Put (asn1SccT_Float'Image (ctxt.temp_air));
                           New_Line;
                           --  RETURN True (None,None) at 407, 1318
                           return true;
                           --  ANSWER false (380,17)
                        elsif ((((power_ok and (placa_abajo_ok or placa_arriba_ok)) and aire_infinito_ok) and (press1_ok or press2_ok))) = false then
                           --  writeln('invalid data :-(') (382,25)
                           Put ("invalid data :-(");
                           New_Line;
                           --  RETURN False (None,None) at 1223, 888
                           return false;
                        end if;
                     end p_0_updateData;
                     

                  procedure getCurrentMode(Current_State: in out asn1SccHTL_State) is
                     begin
                        --  writeln('actual status is', actual_state) (397,17)
                        Put ("actual status is");
                        Put (ctxt.actual_state'Img);
                        New_Line;
                        --  Current_State := actual_state (399,17)
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
                              Execute_Transition (18);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Scca2 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (4);
                           when asn1Sccf1 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (7);
                           when asn1Scca1 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (2);
                           when asn1Sccf2 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (15);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end setCurrentMode;
                     

                  procedure tick is
                     begin
                        case ctxt.state is
                           when asn1Sccf3 =>
                              Execute_Transition (17);
                           when asn1Sccerror =>
                              Execute_Transition (19);
                           when asn1Scca2 =>
                              Execute_Transition (3);
                           when asn1Sccf1 =>
                              Execute_Transition (5);
                           when asn1Scca1 =>
                              Execute_Transition (1);
                           when asn1Sccf2 =>
                              Execute_Transition (14);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
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
                           when asn1Sccf1 =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf2 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccselectstate =>
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
                           when asn1Sccf1 =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf2 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccselectstate =>
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
                           when asn1Sccf1 =>
                              Execute_Transition (6);
                           when asn1Scca1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf2 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccselectstate =>
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
                           when asn1Sccf1 =>
                              Execute_Transition (CS_Only);
                           when asn1Scca1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf2 =>
                              Execute_Transition (16);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end f2_timeout;
                     

                  procedure Execute_Transition (Id : Integer) is
                     trId : Integer := Id;
                     msgPending : Asn1Boolean := True;
                     tmp13887 : asn1SccT_UInt32;
                     tmp13894 : asn1SccT_UInt32;
                     tmp13907 : asn1SccT_UInt32;
                     tmp13865 : asn1SccT_UInt32;
                     begin
                        while (trId /= -1) loop
                           case trId is
                              when 0 =>
                                 --  NEXT_STATE A1 (406,18) at 430, 122
                                 trId := -1;
                                 ctxt.State := asn1SccA1;
                                 goto Next_Transition;
                              when 1 =>
                                 --  actual_state := a1 (412,17)
                                 ctxt.actual_state := asn1Scca1;
                                 --  ok := call updateData (413,0)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (417,17)
                                 if (ctxt.ok) = true then
                                    null;
                                    --  ANSWER false (419,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (421,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (423,30) at 477, 410
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                                 --  DECISION (press <= press_10km and
                                 --  htl_time >= a1_duration_emergency) or
                                 --  htl_time >= a1_duration_max (427,35)
                                 --  ANSWER false (430,17)
                                 if ((((ctxt.press <= ctxt.press_10km) and (ctxt.htl_time >= ctxt.a1_duration_emergency)) or (ctxt.htl_time >= ctxt.a1_duration_max))) = false then
                                    --  doA1 (432,25)
                                    p_0_doA1;
                                    --  NEXT_STATE A1 (434,30) at 553, 687
                                    trId := -1;
                                    ctxt.State := asn1SccA1;
                                    goto Next_Transition;
                                    --  ANSWER true (436,17)
                                 elsif ((((ctxt.press <= ctxt.press_10km) and (ctxt.htl_time >= ctxt.a1_duration_emergency)) or (ctxt.htl_time >= ctxt.a1_duration_max))) = true then
                                    --  NEXT_STATE A2 (438,30) at 643, 637
                                    trId := -1;
                                    ctxt.State := asn1SccA2;
                                    goto Next_Transition;
                                 end if;
                              when 2 =>
                                 --  NEXT_STATE Selectstate (443,22) at 913, 186
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 3 =>
                                 --  actual_state := a2 (450,17)
                                 ctxt.actual_state := asn1Scca2;
                                 --  ok := call updateData (451,0)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (455,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (457,35)
                                    --  COMMENT no estamos cayendo? (459,20)
                                    --  ANSWER True (461,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  writeln('Nos estamos cayendo') (463,33)
                                       Put ("Nos estamos cayendo");
                                       New_Line;
                                       --  NEXT_STATE F3 (465,38) at 1201, 531
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (467,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       null;
                                    end if;
                                    --  ANSWER false (470,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (472,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (474,30) at 1430, 401
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                                 --  DECISION htl_time >= a2_duration_max
                                 --  or press <= press_18km (478,0)
                                 --  ANSWER false (480,17)
                                 if (((ctxt.htl_time >= ctxt.a2_duration_max) or (ctxt.press <= ctxt.press_18km))) = false then
                                    --  doA2 (482,25)
                                    p_0_doA2;
                                    --  NEXT_STATE A2 (484,30) at 945, 790
                                    trId := -1;
                                    ctxt.State := asn1SccA2;
                                    goto Next_Transition;
                                    --  ANSWER true (486,17)
                                 elsif (((ctxt.htl_time >= ctxt.a2_duration_max) or (ctxt.press <= ctxt.press_18km))) = true then
                                    --  writeln('A2 max duration: ', a2_duration_max) (488,25)
                                    Put ("A2 max duration: ");
                                    Put (asn1SccT_Double'Image (ctxt.a2_duration_max));
                                    New_Line;
                                    --  set_timer(f1_duration, f1_timeout) (490,25)
                                    tmp13865 := ctxt.f1_duration;
                                    SET_f1_timeout (tmp13865);
                                    --  NEXT_STATE F1 (492,30) at 1137, 845
                                    trId := -1;
                                    ctxt.State := asn1SccF1;
                                    goto Next_Transition;
                                 end if;
                              when 4 =>
                                 --  NEXT_STATE Selectstate (497,22) at 1649, 182
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 5 =>
                                 --  actual_state := f1 (504,17)
                                 ctxt.actual_state := asn1Sccf1;
                                 --  ok := call updateData (505,0)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (509,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (511,35)
                                    --  ANSWER True (513,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  NEXT_STATE F3 (515,38) at 2068, 494
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (517,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       --  doF1 (519,33)
                                       p_0_doF1;
                                       --  NEXT_STATE F1 (521,38) at 1929, 544
                                       trId := -1;
                                       ctxt.State := asn1SccF1;
                                       goto Next_Transition;
                                    end if;
                                    --  ANSWER false (524,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (526,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (528,30) at 1790, 418
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 6 =>
                                 --  writeln('F1 timeout!!!') (533,17)
                                 Put ("F1 timeout!!!");
                                 New_Line;
                                 --  set_timer(f2_duration, f2_timeout) (535,17)
                                 tmp13887 := ctxt.f2_duration;
                                 SET_f2_timeout (tmp13887);
                                 --  NEXT_STATE F2 (537,22) at 2470, 299
                                 trId := -1;
                                 ctxt.State := asn1SccF2;
                                 goto Next_Transition;
                              when 7 =>
                                 --  NEXT_STATE Selectstate (541,22) at 2232, 192
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 8 =>
                                 --  set_timer(f2_duration, f2_timeout) (548,17)
                                 tmp13894 := ctxt.f2_duration;
                                 SET_f2_timeout (tmp13894);
                                 --  NEXT_STATE F2 (550,22) at 528, 1235
                                 trId := -1;
                                 ctxt.State := asn1SccF2;
                                 goto Next_Transition;
                              when 9 =>
                                 --  NEXT_STATE A1 (554,22) at 205, 1118
                                 trId := -1;
                                 ctxt.State := asn1SccA1;
                                 goto Next_Transition;
                              when 10 =>
                                 --  NEXT_STATE A2 (558,22) at 26, 1115
                                 trId := -1;
                                 ctxt.State := asn1SccA2;
                                 goto Next_Transition;
                              when 11 =>
                                 --  set_timer(f1_duration,f1_timeout) (562,17)
                                 tmp13907 := ctxt.f1_duration;
                                 SET_f1_timeout (tmp13907);
                                 --  NEXT_STATE F1 (564,22) at 129, 1413
                                 trId := -1;
                                 ctxt.State := asn1SccF1;
                                 goto Next_Transition;
                              when 12 =>
                                 --  NEXT_STATE F3 (568,22) at 340, 1117
                                 trId := -1;
                                 ctxt.State := asn1SccF3;
                                 goto Next_Transition;
                              when 13 =>
                                 --  NEXT_STATE Error (572,22) at 671, 1065
                                 trId := -1;
                                 ctxt.State := asn1SccError;
                                 goto Next_Transition;
                              when 14 =>
                                 --  actual_state := f2 (579,17)
                                 ctxt.actual_state := asn1Sccf2;
                                 --  ok := call updateData (580,0)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (584,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (586,35)
                                    --  ANSWER True (588,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  NEXT_STATE F3 (590,38) at 1097, 1340
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (592,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       --  doF2 (594,33)
                                       p_0_doF2;
                                       --  NEXT_STATE F2 (596,38) at 975, 1385
                                       trId := -1;
                                       ctxt.State := asn1SccF2;
                                       goto Next_Transition;
                                    end if;
                                    --  ANSWER false (599,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state:=actual_state (601,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (603,30) at 843, 1281
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 15 =>
                                 --  NEXT_STATE Selectstate (608,22) at 1276, 1057
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 16 =>
                                 --  writeln('F2 timeout!!!') (612,17)
                                 Put ("F2 timeout!!!");
                                 New_Line;
                                 --  NEXT_STATE F3 (614,22) at 1486, 1107
                                 trId := -1;
                                 ctxt.State := asn1SccF3;
                                 goto Next_Transition;
                              when 17 =>
                                 --  actual_state := f3 (621,17)
                                 ctxt.actual_state := asn1Sccf3;
                                 --  doF3 (623,17)
                                 p_0_doF3;
                                 --  NEXT_STATE F3 (625,22) at 1721, 1173
                                 trId := -1;
                                 ctxt.State := asn1SccF3;
                                 goto Next_Transition;
                              when 18 =>
                                 --  NEXT_STATE Selectstate (629,22) at 1886, 1063
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 19 =>
                                 --  ok := call updateData (636,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  actual_state := error (637,0)
                                 ctxt.actual_state := asn1Sccerror;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (641,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION last_good_state (-1,-1)
                                    --  ANSWER a1 (645,25)
                                    if (ctxt.last_good_state) = asn1Scca1 then
                                       --  NEXT_STATE A1 (647,38) at 1872, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccA1;
                                       goto Next_Transition;
                                       --  ANSWER a2 (649,25)
                                    elsif (ctxt.last_good_state) = asn1Scca2 then
                                       --  NEXT_STATE A2 (651,38) at 1962, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccA2;
                                       goto Next_Transition;
                                       --  ANSWER f1 (653,25)
                                    elsif (ctxt.last_good_state) = asn1Sccf1 then
                                       --  NEXT_STATE F1 (655,38) at 2052, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccF1;
                                       goto Next_Transition;
                                       --  ANSWER f2 (657,25)
                                    elsif (ctxt.last_good_state) = asn1Sccf2 then
                                       --  NEXT_STATE F2 (659,38) at 2142, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccF2;
                                       goto Next_Transition;
                                       --  ANSWER else (None,None)
                                    else
                                       --  NEXT_STATE Error (663,38) at 2232, 1362
                                       trId := -1;
                                       ctxt.State := asn1SccError;
                                       goto Next_Transition;
                                    end if;
                                    --  ANSWER false (666,17)
                                 elsif (ctxt.ok) = false then
                                    --  NEXT_STATE Error (668,30) at 2313, 1243
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
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
                              --  DECISION actual_state = f2 (546,30)
                              --  ANSWER true (None,None)
                              if ((ctxt.actual_state = asn1Sccf2)) = true then
                                 trId := 8;
                                 --  Priority 1
                                 --  DECISION actual_state = a1 (552,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Scca1)) = true then
                                 trId := 9;
                                 --  Priority 1
                                 --  DECISION actual_state = a2 (556,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Scca2)) = true then
                                 trId := 10;
                                 --  Priority 1
                                 --  DECISION actual_state = f1 (560,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccf1)) = true then
                                 trId := 11;
                                 --  Priority 1
                                 --  DECISION actual_state = f3 (566,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccf3)) = true then
                                 trId := 12;
                                 --  Priority 1
                                 --  DECISION actual_state = error (570,30)
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