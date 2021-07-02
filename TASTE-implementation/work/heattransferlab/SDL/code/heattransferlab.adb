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
   procedure p_0_initF2;
   procedure p_0_initF1;
   procedure p_0_doF3 is
      --  !! stack: _call_external_function line 1604
      tmp163 : asn1SccT_Float;
      begin
         --  DECISION system_stopped (-1,-1)
         --  ANSWER true (54,17)
         if (ctxt.system_stopped) = true then
            --  RETURN  (None,None) at 309, 238
            return;
            --  ANSWER false (58,17)
         elsif (ctxt.system_stopped) = false then
            null;
         end if;
         --  ok := call updateData (61,17)
         ctxt.ok := p_0_updatedata;
         --  DECISION ok and power = 0.0 (63,24)
         --  ANSWER true (65,17)
         if ((ctxt.ok and asn1SccT_Float_Equal (ctxt.power, 0.0))) = true then
            --  system_stopped := true (67,25)
            ctxt.system_stopped := true;
            --  stopSystem (69,25)
            RI_0_StopSystem;
            --  ANSWER false (71,17)
         elsif ((ctxt.ok and asn1SccT_Float_Equal (ctxt.power, 0.0))) = false then
            --  setPowerH2(0.0) (73,25)
            tmp163 := 0.0;
            RI_0_setPowerH2(tmp163);
         end if;
         --  RETURN  (None,None) at 354, 596
         return;
      end p_0_doF3;
      

   procedure p_0_doF2 is
      begin
         --  DECISION power = 0.0 (83,27)
         --  ANSWER false (85,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            null;
            --  ANSWER true (87,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  DECISION temp_plate <= 55.0 and
            --  abs(temp_plate - temp_air) <= 50.0 (89,48)
            --  ANSWER true (92,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               --  m := m+0.1 (94,33)
               ctxt.m := (ctxt.m + 0.1);
               --  ANSWER false (96,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 601, 362
               return;
            end if;
         end if;
         --  DECISION temp_plate >= 65.0 or 
         --  abs (temp_plate - temp_air) >= 60.0 (102,40)
         --  COMMENT >= 60? (105,12)
         --  ANSWER true (107,17)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (109,25)
            ctxt.power := 0.0;
            --  ANSWER false (111,17)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := power_f1/2.0 - m*0.1 (113,25)
            ctxt.power := ((ctxt.power_f1 / 2.0) - (ctxt.m * 0.1));
            --  DECISION power <= 0.1 (115,35)
            --  ANSWER true (117,25)
            if ((ctxt.power <= 0.1)) = true then
               --  power := 0.1 (119,33)
               ctxt.power := 0.1;
               --  ANSWER false (121,25)
            elsif ((ctxt.power <= 0.1)) = false then
               null;
            end if;
         end if;
         --  setPowerH2(power) (125,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 439, 851
         return;
      end p_0_doF2;
      

   procedure p_0_doA2 is
      begin
         --  DECISION power = 0.0 (134,27)
         --  ANSWER false (136,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            --  JOIN normalA2 (None,None) at None, None
            goto normalA2;
            --  ANSWER true (158,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  DECISION temp_plate <= 55.0 and
            --  abs(temp_plate - temp_air) <= 50.0 (160,48)
            --  COMMENT Pdiss = 0.0 W (163,20)
            --  ANSWER true (165,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               --  JOIN normalA2 (167,33) at 757, 344
               goto normalA2;
               --  ANSWER false (169,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 861, 346
               return;
            end if;
         end if;
         --  setPowerH2(power) (175,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 435, 612
         return;
         --  CONNECTION normalA2 (138,20)
         <<normalA2>>
         --  DECISION temp_plate >= 65.0 or
         --  abs(temp_plate - temp_air) >= 60.0 (140,48)
         --  COMMENT Pdiss = 1.0 (143,20)
         --  ANSWER false (145,25)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := 0.6 (147,33)
            ctxt.power := 0.6;
            --  power_a2 := power (149,33)
            ctxt.power_a2 := ctxt.power;
            --  ANSWER true (151,25)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (153,33)
            ctxt.power := 0.0;
         end if;
         --  writeln('normalA2') (156,25)
         Put ("normalA2");
         New_Line;
         --  setPowerH2(power) (175,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 435, 612
         return;
      end p_0_doA2;
      

   procedure p_0_doA1 is
      begin
         --  DECISION power = 0.0 (184,27)
         --  ANSWER false (186,17)
         if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
            null;
            --  ANSWER true (188,17)
         elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
            --  DECISION temp_plate <= 55.0 and abs(temp_plate -temp_air) <= 50.0 (190,48)
            --  ANSWER true (192,25)
            if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
               null;
               --  ANSWER false (194,25)
            elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
               --  RETURN  (None,None) at 983, 318
               return;
            end if;
         end if;
         --  DECISION temp_plate >= 65.0 or abs(temp_plate - temp_air) >= 60.0 (200,40)
         --  ANSWER true (202,17)
         if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
            --  power := 0.0 (204,25)
            ctxt.power := 0.0;
            --  ANSWER false (206,17)
         elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
            --  power := 0.8 (208,25)
            ctxt.power := 0.8;
         end if;
         --  setPowerH2(power) (211,17)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 518, 657
         return;
      end p_0_doA1;
      

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
            --  power_f1 := power (264,33)
            ctxt.power_f1 := ctxt.power;
         end if;
         --  setPowerH2(power) (267,25)
         RI_0_setPowerH2(ctxt.power);
         --  RETURN  (None,None) at 306, 742
         return;
      end p_0_doF1;
      

   procedure configureParameters(Configuration: in out asn1SccHTL_Config) is
      tmp365 : asn1SccT_Float;
      tmp399 : asn1SccT_Double;
      tmp357 : asn1SccT_Float;
      tmp415 : asn1SccT_Double;
      tmp373 : asn1SccT_Float;
      tmp381 : asn1SccT_Double;
      tmp407 : asn1SccT_Double;
      tmp390 : asn1SccT_Double;
      begin
         --  press_5km  := if exist (Configuration.press_5km) then Configuration.press_5km else press_5km fi (283,17)
         if (Configuration.exist.press_5km = 1) then
            tmp357 := Configuration.press_5km;
         else
            tmp357 := ctxt.press_5km;
         end if;
         ctxt.press_5km := tmp357;
         --  press_10km := if exist(Configuration.press_10km) then Configuration.press_10km else press_10km fi (284,0)
         if (Configuration.exist.press_10km = 1) then
            tmp365 := Configuration.press_10km;
         else
            tmp365 := ctxt.press_10km;
         end if;
         ctxt.press_10km := tmp365;
         --  press_18km := if exist(Configuration.press_18km) then Configuration.press_18km else press_18km fi (285,0)
         if (Configuration.exist.press_18km = 1) then
            tmp373 := Configuration.press_18km;
         else
            tmp373 := ctxt.press_18km;
         end if;
         ctxt.press_18km := tmp373;
         --  f1_relative_duration_max :=
         --   if exist(Configuration.f1_duration_secs) then
            --     float (Configuration.f1_duration_secs)
            --  else
            --    f1_relative_duration_max
            --  fi (287,0)
            if (Configuration.exist.f1_duration_secs = 1) then
               tmp381 := Asn1Real(Configuration.f1_duration_secs);
            else
               tmp381 := ctxt.f1_relative_duration_max;
            end if;
            ctxt.f1_relative_duration_max := tmp381;
            --  f2_relative_duration_max :=
            --  if exist(Configuration.f2_duration_secs) then
               --    float(Configuration.f2_duration_secs)
               --  else
               --    f2_relative_duration_max
               --  fi (294,0)
               if (Configuration.exist.f2_duration_secs = 1) then
                  tmp390 := Asn1Real(Configuration.f2_duration_secs);
               else
                  tmp390 := ctxt.f2_relative_duration_max;
               end if;
               ctxt.f2_relative_duration_max := tmp390;
               --  a1_duration_emergency :=
               --  if exist(Configuration.a1_duration_emergency_secs) then
                  --    Configuration.a1_duration_emergency_secs
                  --  else
                  --    a1_duration_emergency
                  --  fi (301,0)
                  if (Configuration.exist.a1_duration_emergency_secs = 1) then
                     tmp399 := Configuration.a1_duration_emergency_secs;
                  else
                     tmp399 := ctxt.a1_duration_emergency;
                  end if;
                  ctxt.a1_duration_emergency := tmp399;
                  --  a1_duration_max :=
                  --  if exist(Configuration.a1_duration_max_secs) then
                     --    Configuration.a1_duration_max_secs
                     --  else
                     --    a1_duration_max
                     --  fi (308,0)
                     if (Configuration.exist.a1_duration_max_secs = 1) then
                        tmp407 := Configuration.a1_duration_max_secs;
                     else
                        tmp407 := ctxt.a1_duration_max;
                     end if;
                     ctxt.a1_duration_max := tmp407;
                     --  a2_duration_max :=
                     --  if exist(Configuration.a2_duration_max_secs) then
                        --    Configuration.a2_duration_max_secs
                        --  else
                        --    a2_duration_max
                        --  fi (315,0)
                        if (Configuration.exist.a2_duration_max_secs = 1) then
                           tmp415 := Configuration.a2_duration_max_secs;
                        else
                           tmp415 := ctxt.a2_duration_max;
                        end if;
                        ctxt.a2_duration_max := tmp415;
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
                     tmp553 : asn1SccT_Float;
                     tmp510 : asn1SccT_Float;
                     tmp432 : asn1SccOBSW_DP_Filter;
                     tmp436 : asn1SccOBSW_DP_Filter;
                     tmp541 : asn1SccT_Float;
                     --  !! stack: _call_external_function line 1604
                     tmp440 : asn1SccOBSW_DP_Filter;
                     tmp520 : asn1SccT_Float;
                     tmp567 : asn1SccT_Float;
                     tmp532 : asn1SccT_Float;
                     tmp428 : asn1SccOBSW_DP_Filter;
                     begin
                        --  getTime(gps_time, htl_time) (346,17)
                        RI_0_getTime(gps_time, ctxt.htl_time);
                        --  retreiveSingleData(pt1000s,pt1000s_data) (348,17)
                        tmp428 := asn1Sccpt1000s;
                        RI_0_RetreiveSingleData(tmp428, pt1000s_data);
                        --  retreiveSingleData(ps1, press1_data) (350,17)
                        tmp432 := asn1Sccps1;
                        RI_0_RetreiveSingleData(tmp432, press1_data);
                        --  retreiveSingleData(ps2, press2_data) (352,17)
                        tmp436 := asn1Sccps2;
                        RI_0_RetreiveSingleData(tmp436, press2_data);
                        --  retreiveSingleData(heater2, power_data) (354,17)
                        tmp440 := asn1Sccheater2;
                        RI_0_RetreiveSingleData(tmp440, power_data);
                        --  temp_air := 0.0 (356,17)
                        ctxt.temp_air := 0.0;
                        --  temp_plate := 0.0 (357,0)
                        ctxt.temp_plate := 0.0;
                        --  press := 0.0 (358,0)
                        ctxt.press := 0.0;
                        --  placa_abajo_ok := pt1000s_data.pt1000s.data.validity(6) = valid (360,0)
                        placa_abajo_ok := (pt1000s_data.pt1000s.data.validity.Data(7) = asn1Sccvalid);
                        --  placa_arriba_ok := pt1000s_data.pt1000s.data.validity(5) = valid (361,0)
                        placa_arriba_ok := (pt1000s_data.pt1000s.data.validity.Data(6) = asn1Sccvalid);
                        --  aire_infinito_ok := pt1000s_data.pt1000s.data.validity(2) = valid (362,0)
                        aire_infinito_ok := (pt1000s_data.pt1000s.data.validity.Data(3) = asn1Sccvalid);
                        --  press1_ok := press1_data.ps1.data.validity = valid (363,0)
                        press1_ok := (press1_data.ps1.data.validity = asn1Sccvalid);
                        --  press2_ok := press2_data.ps2.data.validity = valid (364,0)
                        press2_ok := (press2_data.ps2.data.validity = asn1Sccvalid);
                        --  power_ok := power_data.heater2.data.validity = valid (365,0)
                        power_ok := (power_data.heater2.data.validity = asn1Sccvalid);
                        --  DECISION power_ok and
                        --  (placa_abajo_ok or placa_arriba_ok)
                        --  and aire_infinito_ok
                        --  and (press1_ok or press2_ok) (370,0)
                        --  ANSWER true (372,17)
                        if ((((power_ok and (placa_abajo_ok or placa_arriba_ok)) and aire_infinito_ok) and (press1_ok or press2_ok))) = true then
                           --  temp_plate := if placa_arriba_ok then (pt1000s_data.pt1000s.data.celsius(5)) else 0.0 fi (374,25)
                           if placa_arriba_ok then
                              tmp510 := pt1000s_data.pt1000s.data.celsius.Data(6);
                           else
                              tmp510 := 0.0;
                           end if;
                           ctxt.temp_plate := tmp510;
                           --  temp_plate := if placa_abajo_ok then (pt1000s_data.pt1000s.data.celsius(6) + temp_plate) else temp_plate fi (375,0)
                           if placa_abajo_ok then
                              tmp520 := (pt1000s_data.pt1000s.data.celsius.Data(7) + ctxt.temp_plate);
                           else
                              tmp520 := ctxt.temp_plate;
                           end if;
                           ctxt.temp_plate := tmp520;
                           --  temp_plate := if placa_abajo_ok and placa_arriba_ok then temp_plate / 2.0 else temp_plate fi (376,0)
                           if (placa_abajo_ok and placa_arriba_ok) then
                              tmp532 := (ctxt.temp_plate / 2.0);
                           else
                              tmp532 := ctxt.temp_plate;
                           end if;
                           ctxt.temp_plate := tmp532;
                           --  press := if press1_ok then float(press1_data.ps1.data.processed.pressure) /100.0 else 0.0 fi (378,0)
                           if press1_ok then
                              tmp541 := (Asn1Real(press1_data.ps1.data.processed.pressure) / 100.0);
                           else
                              tmp541 := 0.0;
                           end if;
                           ctxt.press := tmp541;
                           --  press := if press2_ok then (float(press2_data.ps2.data.processed.pressure)/100.0 + press) else press fi (379,0)
                           if press2_ok then
                              tmp553 := ((Asn1Real(press2_data.ps2.data.processed.pressure) / 100.0) + ctxt.press);
                           else
                              tmp553 := ctxt.press;
                           end if;
                           ctxt.press := tmp553;
                           --  press := if press1_ok and press2_ok then press / 2.0 else press fi (380,0)
                           if (press1_ok and press2_ok) then
                              tmp567 := (ctxt.press / 2.0);
                           else
                              tmp567 := ctxt.press;
                           end if;
                           ctxt.press := tmp567;
                           --  temp_air := pt1000s_data.pt1000s.data.celsius(2) (382,0)
                           ctxt.temp_air := pt1000s_data.pt1000s.data.celsius.Data(3);
                           --  power := power_data.heater2.data.power_watts (384,0)
                           ctxt.power := power_data.heater2.data.power_watts;
                           --  writeln('temp_plate: ', temp_plate) (386,25)
                           Put ("temp_plate: ");
                           Put (asn1SccT_Float'Image (ctxt.temp_plate));
                           New_Line;
                           --  writeln('power: ', power) (388,25)
                           Put ("power: ");
                           Put (asn1SccT_Float'Image (ctxt.power));
                           New_Line;
                           --  writeln('press: ', press) (390,25)
                           Put ("press: ");
                           Put (asn1SccT_Float'Image (ctxt.press));
                           New_Line;
                           --  writeln('press 2 ok ', press2_ok) (392,25)
                           Put ("press 2 ok ");
                           Put (asn1SccT_Boolean'Image (press2_ok));
                           New_Line;
                           --  writeln('temp_air: ', temp_air) (394,25)
                           Put ("temp_air: ");
                           Put (asn1SccT_Float'Image (ctxt.temp_air));
                           New_Line;
                           --  RETURN True (None,None) at 407, 1318
                           return true;
                           --  ANSWER false (398,17)
                        elsif ((((power_ok and (placa_abajo_ok or placa_arriba_ok)) and aire_infinito_ok) and (press1_ok or press2_ok))) = false then
                           --  writeln('invalid data :-(') (400,25)
                           Put ("invalid data :-(");
                           New_Line;
                           --  RETURN False (None,None) at 1223, 888
                           return false;
                        end if;
                     end p_0_updateData;
                     

                  procedure getCurrentMode(Current_State: in out asn1SccHTL_State) is
                     begin
                        --  writeln('actual status is', actual_state) (415,17)
                        Put ("actual status is");
                        Put (ctxt.actual_state'Img);
                        New_Line;
                        --  Current_State := actual_state (417,17)
                        Current_State := ctxt.actual_state;
                        --  getCurrentMode_Transition (None,None)
                        getCurrentMode_Transition;
                        --  RETURN  (None,None) at 603, 307
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
                           --  f2_duration_max := htl_time + f2_relative_duration_max (433,0)
                           ctxt.f2_duration_max := (ctxt.htl_time + ctxt.f2_relative_duration_max);
                           --  actual_state := f2 (434,0)
                           ctxt.actual_state := asn1Sccf2;
                        end if;
                        --  RETURN  (None,None) at 183, 324
                        return;
                     end p_0_initF2;
                     

                  procedure p_0_initF1 is
                     begin
                        --  DECISION f1_started (-1,-1)
                        --  ANSWER true (446,17)
                        if (ctxt.f1_started) = true then
                           null;
                           --  ANSWER false (448,17)
                        elsif (ctxt.f1_started) = false then
                           --  f1_started := true (450,25)
                           ctxt.f1_started := true;
                           --  f1_duration_max := htl_time + f1_relative_duration_max (451,0)
                           ctxt.f1_duration_max := (ctxt.htl_time + ctxt.f1_relative_duration_max);
                           --  actual_state := f1 (452,0)
                           ctxt.actual_state := asn1Sccf1;
                        end if;
                        --  RETURN  (None,None) at 455, 353
                        return;
                     end p_0_initF1;
                     

                  procedure setCurrentMode(current_state: in out asn1SccHTL_State) is
                     begin
                        case ctxt.state is
                           when asn1Sccf1 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (17);
                           when asn1Sccf2 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (15);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
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
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end setCurrentMode;
                     

                  procedure tick is
                     begin
                        case ctxt.state is
                           when asn1Sccf1 =>
                              Execute_Transition (16);
                           when asn1Sccf2 =>
                              Execute_Transition (14);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf3 =>
                              Execute_Transition (11);
                           when asn1Sccerror =>
                              Execute_Transition (13);
                           when asn1Scca2 =>
                              Execute_Transition (3);
                           when asn1Scca1 =>
                              Execute_Transition (1);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end tick;
                     

                  procedure configureParameters_Transition is
                     begin
                        case ctxt.state is
                           when asn1Sccf1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf2 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf3 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Scca2 =>
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
                           when asn1Sccf1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf2 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf3 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Scca2 =>
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
                                 --  NEXT_STATE A1 (460,18) at 512, 127
                                 trId := -1;
                                 ctxt.State := asn1SccA1;
                                 goto Next_Transition;
                              when 1 =>
                                 --  actual_state := a1 (466,17)
                                 ctxt.actual_state := asn1Scca1;
                                 --  ok := call updateData (467,0)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (471,17)
                                 if (ctxt.ok) = true then
                                    null;
                                    --  ANSWER false (473,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (475,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (477,30) at 518, 410
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                                 --  DECISION (press <= press_10km and
                                 --  htl_time >= a1_duration_emergency) or
                                 --  htl_time >= a1_duration_max (481,35)
                                 --  ANSWER false (484,17)
                                 if ((((ctxt.press <= ctxt.press_10km) and (ctxt.htl_time >= ctxt.a1_duration_emergency)) or (ctxt.htl_time >= ctxt.a1_duration_max))) = false then
                                    --  doA1 (486,25)
                                    p_0_doA1;
                                    --  NEXT_STATE A1 (488,30) at 594, 687
                                    trId := -1;
                                    ctxt.State := asn1SccA1;
                                    goto Next_Transition;
                                    --  ANSWER true (490,17)
                                 elsif ((((ctxt.press <= ctxt.press_10km) and (ctxt.htl_time >= ctxt.a1_duration_emergency)) or (ctxt.htl_time >= ctxt.a1_duration_max))) = true then
                                    --  NEXT_STATE A2 (492,30) at 684, 637
                                    trId := -1;
                                    ctxt.State := asn1SccA2;
                                    goto Next_Transition;
                                 end if;
                              when 2 =>
                                 --  NEXT_STATE Selectstate (497,22) at 953, 186
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 3 =>
                                 --  actual_state := a2 (504,17)
                                 ctxt.actual_state := asn1Scca2;
                                 --  ok := call updateData (505,0)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (509,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (511,35)
                                    --  COMMENT no estamos cayendo? (513,20)
                                    --  ANSWER True (515,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  writeln('Nos estamos cayendo') (517,33)
                                       Put ("Nos estamos cayendo");
                                       New_Line;
                                       --  NEXT_STATE F3 (519,38) at 1331, 531
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (521,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       null;
                                    end if;
                                    --  ANSWER false (524,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (526,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (528,30) at 1560, 401
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                                 --  DECISION htl_time >= a2_duration_max
                                 --  or press <= press_18km (532,0)
                                 --  ANSWER false (534,17)
                                 if (((ctxt.htl_time >= ctxt.a2_duration_max) or (ctxt.press <= ctxt.press_18km))) = false then
                                    --  doA2 (536,25)
                                    p_0_doA2;
                                    --  NEXT_STATE A2 (538,30) at 1075, 796
                                    trId := -1;
                                    ctxt.State := asn1SccA2;
                                    goto Next_Transition;
                                    --  ANSWER true (540,17)
                                 elsif (((ctxt.htl_time >= ctxt.a2_duration_max) or (ctxt.press <= ctxt.press_18km))) = true then
                                    --  writeln('A2 max duration: ', a2_duration_max) (542,25)
                                    Put ("A2 max duration: ");
                                    Put (asn1SccT_Double'Image (ctxt.a2_duration_max));
                                    New_Line;
                                    --  NEXT_STATE F1 (544,30) at 1267, 801
                                    trId := -1;
                                    ctxt.State := asn1SccF1;
                                    goto Next_Transition;
                                 end if;
                              when 4 =>
                                 --  NEXT_STATE Selectstate (549,22) at 1776, 182
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 5 =>
                                 --  NEXT_STATE F2 (556,22) at 989, 1065
                                 trId := -1;
                                 ctxt.State := asn1SccF2;
                                 goto Next_Transition;
                              when 6 =>
                                 --  NEXT_STATE A1 (560,22) at 721, 1060
                                 trId := -1;
                                 ctxt.State := asn1SccA1;
                                 goto Next_Transition;
                              when 7 =>
                                 --  NEXT_STATE A2 (564,22) at 451, 1060
                                 trId := -1;
                                 ctxt.State := asn1SccA2;
                                 goto Next_Transition;
                              when 8 =>
                                 --  NEXT_STATE F1 (568,22) at 587, 1065
                                 trId := -1;
                                 ctxt.State := asn1SccF1;
                                 goto Next_Transition;
                              when 9 =>
                                 --  NEXT_STATE F3 (572,22) at 858, 1063
                                 trId := -1;
                                 ctxt.State := asn1SccF3;
                                 goto Next_Transition;
                              when 10 =>
                                 --  NEXT_STATE Error (576,22) at 1131, 1065
                                 trId := -1;
                                 ctxt.State := asn1SccError;
                                 goto Next_Transition;
                              when 11 =>
                                 --  actual_state := f3 (583,17)
                                 ctxt.actual_state := asn1Sccf3;
                                 --  doF3 (585,17)
                                 p_0_doF3;
                                 --  NEXT_STATE F3 (587,22) at 2127, 1173
                                 trId := -1;
                                 ctxt.State := asn1SccF3;
                                 goto Next_Transition;
                              when 12 =>
                                 --  NEXT_STATE Selectstate (591,22) at 2289, 1063
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 13 =>
                                 --  ok := call updateData (598,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  actual_state := error (599,0)
                                 ctxt.actual_state := asn1Sccerror;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (603,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION last_good_state (-1,-1)
                                    --  ANSWER a1 (607,25)
                                    if (ctxt.last_good_state) = asn1Scca1 then
                                       --  NEXT_STATE A1 (609,38) at 2265, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccA1;
                                       goto Next_Transition;
                                       --  ANSWER a2 (611,25)
                                    elsif (ctxt.last_good_state) = asn1Scca2 then
                                       --  NEXT_STATE A2 (613,38) at 2355, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccA2;
                                       goto Next_Transition;
                                       --  ANSWER f1 (615,25)
                                    elsif (ctxt.last_good_state) = asn1Sccf1 then
                                       --  NEXT_STATE F1 (617,38) at 2445, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccF1;
                                       goto Next_Transition;
                                       --  ANSWER f2 (619,25)
                                    elsif (ctxt.last_good_state) = asn1Sccf2 then
                                       --  NEXT_STATE F2 (621,38) at 2535, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccF2;
                                       goto Next_Transition;
                                       --  ANSWER else (None,None)
                                    else
                                       --  NEXT_STATE Error (625,38) at 2625, 1362
                                       trId := -1;
                                       ctxt.State := asn1SccError;
                                       goto Next_Transition;
                                    end if;
                                    --  ANSWER false (628,17)
                                 elsif (ctxt.ok) = false then
                                    --  NEXT_STATE Error (630,30) at 2706, 1243
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 14 =>
                                 --  initf2 (638,17)
                                 p_0_initF2;
                                 --  ok := call updateData (640,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (644,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (646,35)
                                    --  ANSWER True (648,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  NEXT_STATE F3 (650,38) at 1730, 1379
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (652,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       --  DECISION htl_time >= f2_duration_max (654,46)
                                       --  ANSWER true (656,33)
                                       if ((ctxt.htl_time >= ctxt.f2_duration_max)) = true then
                                          --  NEXT_STATE F3 (658,46) at 1446, 1515
                                          --  COMMENT time in F3 is bigger
                                          --  than the allowed. (660,36)
                                          trId := -1;
                                          ctxt.State := asn1SccF3;
                                          goto Next_Transition;
                                          --  ANSWER false (663,33)
                                       elsif ((ctxt.htl_time >= ctxt.f2_duration_max)) = false then
                                          --  doF2 (665,41)
                                          p_0_doF2;
                                          --  NEXT_STATE F2 (667,46) at 1556, 1567
                                          trId := -1;
                                          ctxt.State := asn1SccF2;
                                          goto Next_Transition;
                                       end if;
                                    end if;
                                    --  ANSWER false (671,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state:=actual_state (673,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (675,30) at 1192, 1320
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 15 =>
                                 --  NEXT_STATE Selectstate (680,22) at 1877, 1057
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 16 =>
                                 --  initf1 (687,17)
                                 p_0_initF1;
                                 --  ok := call updateData (689,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (693,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (695,35)
                                    --  ANSWER True (697,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  NEXT_STATE F3 (699,38) at 2625, 533
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (701,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       --  DECISION htl_time >= f1_duration_max (703,46)
                                       --  ANSWER true (705,33)
                                       if ((ctxt.htl_time >= ctxt.f1_duration_max)) = true then
                                          --  NEXT_STATE F2 (707,46) at 2330, 680
                                          trId := -1;
                                          ctxt.State := asn1SccF2;
                                          goto Next_Transition;
                                          --  ANSWER false (709,33)
                                       elsif ((ctxt.htl_time >= ctxt.f1_duration_max)) = false then
                                          --  doF1 (711,41)
                                          p_0_doF1;
                                          --  NEXT_STATE F1 (713,46) at 2420, 735
                                          trId := -1;
                                          ctxt.State := asn1SccF1;
                                          goto Next_Transition;
                                       end if;
                                    end if;
                                    --  ANSWER false (717,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (719,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (721,30) at 2150, 457
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 17 =>
                                 --  NEXT_STATE Selectstate (726,22) at 2762, 192
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
                              --  DECISION actual_state = f2 (554,30)
                              --  ANSWER true (None,None)
                              if ((ctxt.actual_state = asn1Sccf2)) = true then
                                 trId := 5;
                                 --  Priority 1
                                 --  DECISION actual_state = a1 (558,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Scca1)) = true then
                                 trId := 6;
                                 --  Priority 1
                                 --  DECISION actual_state = a2 (562,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Scca2)) = true then
                                 trId := 7;
                                 --  Priority 1
                                 --  DECISION actual_state = f1 (566,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccf1)) = true then
                                 trId := 8;
                                 --  Priority 1
                                 --  DECISION actual_state = f3 (570,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccf3)) = true then
                                 trId := 9;
                                 --  Priority 1
                                 --  DECISION actual_state = error (574,30)
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