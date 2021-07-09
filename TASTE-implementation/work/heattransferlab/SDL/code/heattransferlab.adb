-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !

with System.IO;
use System.IO;

with Ada.Unchecked_Conversion;
with Ada.Numerics.Generic_Elementary_Functions;

package body Heattransferlab is
   CS_Only : constant := 19;
   procedure Execute_Transition (Id : Integer);
   procedure p_0_initA2;
   procedure p_0_initA1;
   procedure p_0_initF1;
   procedure p_0_initF2;
   function p_0_updateData return asn1SccT_Boolean;
   procedure p_0_doF1;
   procedure p_0_doA1;
   procedure p_0_doA2;
   procedure p_0_doF2;
   procedure p_0_doF3;
   procedure p_0_initA2 is
      tmp180 : asn1SccT_Double;
      tmp181 : asn1SccT_Double;
      --  !! stack: _call_external_function line 1604
      begin
         --  DECISION a2_started (-1,-1)
         --  ANSWER true (56,17)
         if (ctxt.a2_started) = true then
            null;
            --  ANSWER false (58,17)
         elsif (ctxt.a2_started) = false then
            --  a2_started := true (60,25)
            ctxt.a2_started := true;
            --  actual_state := a2 (61,0)
            ctxt.actual_state := asn1Scca2;
            --  RecordHTLParams(actual_state, -1.0, -1.0) (63,25)
            tmp180 := (-1.0);
            tmp181 := (-1.0);
            RI_0_RecordHTLParams(ctxt.actual_state, tmp180, tmp181);
         end if;
         --  RETURN  (None,None) at 507, 325
         return;
      end p_0_initA2;
      

   procedure p_0_initA1 is
      tmp197 : asn1SccT_Double;
      --  !! stack: _call_external_function line 1604
      tmp196 : asn1SccT_Double;
      begin
         --  DECISION a1_started (-1,-1)
         --  ANSWER true (75,17)
         if (ctxt.a1_started) = true then
            null;
            --  ANSWER false (77,17)
         elsif (ctxt.a1_started) = false then
            --  a1_started := true (79,25)
            ctxt.a1_started := true;
            --  actual_state := a1 (80,0)
            ctxt.actual_state := asn1Scca1;
            --  RecordHTLParams(actual_state, -1.0, -1.0) (82,25)
            tmp196 := (-1.0);
            tmp197 := (-1.0);
            RI_0_RecordHTLParams(ctxt.actual_state, tmp196, tmp197);
         end if;
         --  RETURN  (None,None) at 409, 316
         return;
      end p_0_initA1;
      

   procedure p_0_initF1 is
      begin
         --  DECISION f1_started (-1,-1)
         --  ANSWER true (94,17)
         if (ctxt.f1_started) = true then
            null;
            --  ANSWER false (96,17)
         elsif (ctxt.f1_started) = false then
            --  f1_started := true (98,25)
            ctxt.f1_started := true;
            --  actual_state := f1 (99,0)
            ctxt.actual_state := asn1Sccf1;
            --  DECISION f1_duration_max = -1.0 (101,45)
            --  ANSWER true (103,25)
            if (asn1SccT_Double_Equal (ctxt.f1_duration_max, (-1.0))) = true then
               --  f1_duration_max := htl_time + f1_relative_duration_max (105,33)
               ctxt.f1_duration_max := (ctxt.htl_time + ctxt.f1_relative_duration_max);
               --  ANSWER false (107,25)
            elsif (asn1SccT_Double_Equal (ctxt.f1_duration_max, (-1.0))) = false then
               null;
            end if;
            --  RecordHTLParams(actual_state, f1_duration_max, f2_duration_max) (110,25)
            RI_0_RecordHTLParams(ctxt.actual_state, ctxt.f1_duration_max, ctxt.f2_duration_max);
            --  writeln('[init f1] Recorded: ', actual_state) (112,25)
            Put ("[init f1] Recorded: ");
            Put (ctxt.actual_state'Img);
            New_Line;
         end if;
         --  RETURN  (None,None) at 455, 598
         return;
      end p_0_initF1;
      

   procedure p_0_initF2 is
      begin
         --  DECISION f2_started (-1,-1)
         --  ANSWER true (124,17)
         if (ctxt.f2_started) = true then
            null;
            --  ANSWER false (126,17)
         elsif (ctxt.f2_started) = false then
            --  f2_started := true (128,25)
            ctxt.f2_started := true;
            --  actual_state := f2 (129,0)
            ctxt.actual_state := asn1Sccf2;
            --  DECISION f2_duration_max = -1.0 (131,45)
            --  ANSWER true (133,25)
            if (asn1SccT_Double_Equal (ctxt.f2_duration_max, (-1.0))) = true then
               --  f2_duration_max := htl_time + f2_relative_duration_max (135,33)
               ctxt.f2_duration_max := (ctxt.htl_time + ctxt.f2_relative_duration_max);
               --  ANSWER false (137,25)
            elsif (asn1SccT_Double_Equal (ctxt.f2_duration_max, (-1.0))) = false then
               null;
            end if;
            --  RecordHTLParams(actual_state, f1_duration_max, f2_duration_max) (140,25)
            RI_0_RecordHTLParams(ctxt.actual_state, ctxt.f1_duration_max, ctxt.f2_duration_max);
            --  writeln('[initF2] Recorded: ', actual_state) (142,25)
            Put ("[initF2] Recorded: ");
            Put (ctxt.actual_state'Img);
            New_Line;
         end if;
         --  RETURN  (None,None) at 256, 579
         return;
      end p_0_initF2;
      

   procedure getCurrentMode(Current_State: in out asn1SccHTL_State) is
      begin
         --  Current_State := actual_state (157,17)
         Current_State := ctxt.actual_state;
         --  getCurrentMode_Transition (None,None)
         getCurrentMode_Transition;
         --  RETURN  (None,None) at 603, 257
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
      tmp346 : asn1SccT_Float;
      tmp368 : asn1SccT_Float;
      tmp268 : asn1SccOBSW_DP_Filter;
      tmp389 : asn1SccT_Float;
      tmp264 : asn1SccOBSW_DP_Filter;
      tmp272 : asn1SccOBSW_DP_Filter;
      tmp403 : asn1SccT_Float;
      tmp276 : asn1SccOBSW_DP_Filter;
      tmp377 : asn1SccT_Float;
      tmp356 : asn1SccT_Float;
      --  !! stack: _call_external_function line 1604
      begin
         --  getTime(gps_time, htl_time) (183,17)
         RI_0_getTime(gps_time, ctxt.htl_time);
         --  retreiveSingleData(pt1000s,pt1000s_data) (185,17)
         tmp264 := asn1Sccpt1000s;
         RI_0_RetreiveSingleData(tmp264, pt1000s_data);
         --  retreiveSingleData(ps1, press1_data) (187,17)
         tmp268 := asn1Sccps1;
         RI_0_RetreiveSingleData(tmp268, press1_data);
         --  retreiveSingleData(ps2, press2_data) (189,17)
         tmp272 := asn1Sccps2;
         RI_0_RetreiveSingleData(tmp272, press2_data);
         --  retreiveSingleData(heater2, power_data) (191,17)
         tmp276 := asn1Sccheater2;
         RI_0_RetreiveSingleData(tmp276, power_data);
         --  temp_air := 0.0 (193,17)
         ctxt.temp_air := 0.0;
         --  temp_plate := 0.0 (194,0)
         ctxt.temp_plate := 0.0;
         --  press := 0.0 (195,0)
         ctxt.press := 0.0;
         --  placa_abajo_ok := pt1000s_data.pt1000s.data.validity(6) = valid (197,0)
         placa_abajo_ok := (pt1000s_data.pt1000s.data.validity.Data(7) = asn1Sccvalid);
         --  placa_arriba_ok := pt1000s_data.pt1000s.data.validity(5) = valid (198,0)
         placa_arriba_ok := (pt1000s_data.pt1000s.data.validity.Data(6) = asn1Sccvalid);
         --  aire_infinito_ok := pt1000s_data.pt1000s.data.validity(2) = valid (199,0)
         aire_infinito_ok := (pt1000s_data.pt1000s.data.validity.Data(3) = asn1Sccvalid);
         --  press1_ok := press1_data.ps1.data.validity = valid (200,0)
         press1_ok := (press1_data.ps1.data.validity = asn1Sccvalid);
         --  press2_ok := press2_data.ps2.data.validity = valid (201,0)
         press2_ok := (press2_data.ps2.data.validity = asn1Sccvalid);
         --  power_ok := power_data.heater2.data.validity = valid (202,0)
         power_ok := (power_data.heater2.data.validity = asn1Sccvalid);
         --  DECISION power_ok and
         --  (placa_abajo_ok or placa_arriba_ok)
         --  and aire_infinito_ok
         --  and (press1_ok or press2_ok) (207,0)
         --  ANSWER true (209,17)
         if ((((power_ok and (placa_abajo_ok or placa_arriba_ok)) and aire_infinito_ok) and (press1_ok or press2_ok))) = true then
            --  temp_plate := if placa_arriba_ok then (pt1000s_data.pt1000s.data.celsius(5)) else 0.0 fi (211,25)
            if placa_arriba_ok then
               tmp346 := pt1000s_data.pt1000s.data.celsius.Data(6);
            else
               tmp346 := 0.0;
            end if;
            ctxt.temp_plate := tmp346;
            --  temp_plate := if placa_abajo_ok then (pt1000s_data.pt1000s.data.celsius(6) + temp_plate) else temp_plate fi (212,0)
            if placa_abajo_ok then
               tmp356 := (pt1000s_data.pt1000s.data.celsius.Data(7) + ctxt.temp_plate);
            else
               tmp356 := ctxt.temp_plate;
            end if;
            ctxt.temp_plate := tmp356;
            --  temp_plate := if placa_abajo_ok and placa_arriba_ok then temp_plate / 2.0 else temp_plate fi (213,0)
            if (placa_abajo_ok and placa_arriba_ok) then
               tmp368 := (ctxt.temp_plate / 2.0);
            else
               tmp368 := ctxt.temp_plate;
            end if;
            ctxt.temp_plate := tmp368;
            --  press := if press1_ok then float(press1_data.ps1.data.processed.pressure) /100.0 else 0.0 fi (215,0)
            if press1_ok then
               tmp377 := (Asn1Real(press1_data.ps1.data.processed.pressure) / 100.0);
            else
               tmp377 := 0.0;
            end if;
            ctxt.press := tmp377;
            --  press := if press2_ok then (float(press2_data.ps2.data.processed.pressure)/100.0 + press) else press fi (216,0)
            if press2_ok then
               tmp389 := ((Asn1Real(press2_data.ps2.data.processed.pressure) / 100.0) + ctxt.press);
            else
               tmp389 := ctxt.press;
            end if;
            ctxt.press := tmp389;
            --  press := if press1_ok and press2_ok then press / 2.0 else press fi (217,0)
            if (press1_ok and press2_ok) then
               tmp403 := (ctxt.press / 2.0);
            else
               tmp403 := ctxt.press;
            end if;
            ctxt.press := tmp403;
            --  temp_air := pt1000s_data.pt1000s.data.celsius(2) (219,0)
            ctxt.temp_air := pt1000s_data.pt1000s.data.celsius.Data(3);
            --  power := power_data.heater2.data.power_watts (221,0)
            ctxt.power := power_data.heater2.data.power_watts;
            --  writeln('temp_plate: ', temp_plate) (223,25)
            Put ("temp_plate: ");
            Put (asn1SccT_Float'Image (ctxt.temp_plate));
            New_Line;
            --  writeln('power: ', power) (225,25)
            Put ("power: ");
            Put (asn1SccT_Float'Image (ctxt.power));
            New_Line;
            --  writeln('press: ', press) (227,25)
            Put ("press: ");
            Put (asn1SccT_Float'Image (ctxt.press));
            New_Line;
            --  writeln('press 2 ok ', press2_ok) (229,25)
            Put ("press 2 ok ");
            Put (asn1SccT_Boolean'Image (press2_ok));
            New_Line;
            --  writeln('temp_air: ', temp_air) (231,25)
            Put ("temp_air: ");
            Put (asn1SccT_Float'Image (ctxt.temp_air));
            New_Line;
            --  RETURN True (None,None) at 407, 1318
            return true;
            --  ANSWER false (235,17)
         elsif ((((power_ok and (placa_abajo_ok or placa_arriba_ok)) and aire_infinito_ok) and (press1_ok or press2_ok))) = false then
            --  writeln('invalid data :-(') (237,25)
            Put ("invalid data :-(");
            New_Line;
            --  RETURN False (None,None) at 1223, 888
            return false;
         end if;
      end p_0_updateData;
      

   procedure configureParameters(Configuration: in out asn1SccHTL_Config) is
      tmp473 : asn1SccT_Double;
      tmp482 : asn1SccT_Double;
      tmp499 : asn1SccT_Double;
      tmp449 : asn1SccT_Float;
      tmp491 : asn1SccT_Double;
      tmp465 : asn1SccT_Float;
      tmp457 : asn1SccT_Float;
      tmp507 : asn1SccT_Double;
      begin
         --  press_5km  := if exist (Configuration.press_5km) then Configuration.press_5km else press_5km fi (253,17)
         if (Configuration.exist.press_5km = 1) then
            tmp449 := Configuration.press_5km;
         else
            tmp449 := ctxt.press_5km;
         end if;
         ctxt.press_5km := tmp449;
         --  press_10km := if exist(Configuration.press_10km) then Configuration.press_10km else press_10km fi (254,0)
         if (Configuration.exist.press_10km = 1) then
            tmp457 := Configuration.press_10km;
         else
            tmp457 := ctxt.press_10km;
         end if;
         ctxt.press_10km := tmp457;
         --  press_18km := if exist(Configuration.press_18km) then Configuration.press_18km else press_18km fi (255,0)
         if (Configuration.exist.press_18km = 1) then
            tmp465 := Configuration.press_18km;
         else
            tmp465 := ctxt.press_18km;
         end if;
         ctxt.press_18km := tmp465;
         --  f1_relative_duration_max :=
         --   if exist(Configuration.f1_duration_secs) then
            --     float (Configuration.f1_duration_secs)
            --  else
            --    f1_relative_duration_max
            --  fi (257,0)
            if (Configuration.exist.f1_duration_secs = 1) then
               tmp473 := Asn1Real(Configuration.f1_duration_secs);
            else
               tmp473 := ctxt.f1_relative_duration_max;
            end if;
            ctxt.f1_relative_duration_max := tmp473;
            --  f2_relative_duration_max :=
            --  if exist(Configuration.f2_duration_secs) then
               --    float(Configuration.f2_duration_secs)
               --  else
               --    f2_relative_duration_max
               --  fi (264,0)
               if (Configuration.exist.f2_duration_secs = 1) then
                  tmp482 := Asn1Real(Configuration.f2_duration_secs);
               else
                  tmp482 := ctxt.f2_relative_duration_max;
               end if;
               ctxt.f2_relative_duration_max := tmp482;
               --  a1_duration_emergency :=
               --  if exist(Configuration.a1_duration_emergency_secs) then
                  --    Configuration.a1_duration_emergency_secs
                  --  else
                  --    a1_duration_emergency
                  --  fi (271,0)
                  if (Configuration.exist.a1_duration_emergency_secs = 1) then
                     tmp491 := Configuration.a1_duration_emergency_secs;
                  else
                     tmp491 := ctxt.a1_duration_emergency;
                  end if;
                  ctxt.a1_duration_emergency := tmp491;
                  --  a1_duration_max :=
                  --  if exist(Configuration.a1_duration_max_secs) then
                     --    Configuration.a1_duration_max_secs
                     --  else
                     --    a1_duration_max
                     --  fi (278,0)
                     if (Configuration.exist.a1_duration_max_secs = 1) then
                        tmp499 := Configuration.a1_duration_max_secs;
                     else
                        tmp499 := ctxt.a1_duration_max;
                     end if;
                     ctxt.a1_duration_max := tmp499;
                     --  a2_duration_max :=
                     --  if exist(Configuration.a2_duration_max_secs) then
                        --    Configuration.a2_duration_max_secs
                        --  else
                        --    a2_duration_max
                        --  fi (285,0)
                        if (Configuration.exist.a2_duration_max_secs = 1) then
                           tmp507 := Configuration.a2_duration_max_secs;
                        else
                           tmp507 := ctxt.a2_duration_max;
                        end if;
                        ctxt.a2_duration_max := tmp507;
                        --  configureParameters_Transition (None,None)
                        configureParameters_Transition;
                        --  RETURN  (None,None) at 931, 777
                        return;
                     end configureParameters;
                     

                  procedure p_0_doF1 is
                     begin
                        --  DECISION power = 0.0 (299,27)
                        --  ANSWER true (301,17)
                        if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
                           --  DECISION temp_plate <= 55.0 and
                           --  abs(temp_plate - temp_air) <= 50.0 (303,48)
                           --  ANSWER true (306,25)
                           if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
                              --  n := n+1.0 (308,33)
                              ctxt.n := (ctxt.n + 1.0);
                              --  JOIN normalF1 (310,33) at 599, 454
                              goto normalF1;
                              --  ANSWER false (312,25)
                           elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
                              --  RETURN  (None,None) at 706, 404
                              return;
                           end if;
                           --  ANSWER false (317,17)
                        elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
                           --  JOIN normalF1 (None,None) at None, None
                           goto normalF1;
                        end if;
                        --  CONNECTION normalF1 (319,20)
                        <<normalF1>>
                        --  DECISION temp_plate >= 65.0 or
                        --  abs(temp_plate - temp_air) >= 60.0 (321,48)
                        --  COMMENT ¿>= 60? (324,20)
                        --  ANSWER true (326,25)
                        if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
                           --  power := 0.0 (328,33)
                           ctxt.power := 0.0;
                           --  ANSWER false (330,25)
                        elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
                           --  power := power_a2-n*0.1 (332,33)
                           ctxt.power := (ctxt.power_a2 - (ctxt.n * 0.1));
                           --  DECISION power <= 0.1 (334,43)
                           --  ANSWER true (336,33)
                           if ((ctxt.power <= 0.1)) = true then
                              --  power := 0.1 (338,41)
                              ctxt.power := 0.1;
                              --  ANSWER false (340,33)
                           elsif ((ctxt.power <= 0.1)) = false then
                              null;
                           end if;
                           --  power_f1 := power (343,33)
                           ctxt.power_f1 := ctxt.power;
                        end if;
                        --  setPowerH2(power) (346,25)
                        RI_0_setPowerH2(ctxt.power);
                        --  RETURN  (None,None) at 306, 742
                        return;
                     end p_0_doF1;
                     

                  procedure p_0_doA1 is
                     begin
                        --  DECISION power = 0.0 (356,27)
                        --  ANSWER false (358,17)
                        if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
                           null;
                           --  ANSWER true (360,17)
                        elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
                           --  DECISION temp_plate <= 55.0 and abs(temp_plate -temp_air) <= 50.0 (362,48)
                           --  ANSWER true (364,25)
                           if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
                              null;
                              --  ANSWER false (366,25)
                           elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
                              --  RETURN  (None,None) at 983, 318
                              return;
                           end if;
                        end if;
                        --  DECISION temp_plate >= 65.0 or abs(temp_plate - temp_air) >= 60.0 (372,40)
                        --  ANSWER true (374,17)
                        if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
                           --  power := 0.0 (376,25)
                           ctxt.power := 0.0;
                           --  ANSWER false (378,17)
                        elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
                           --  power := 0.8 (380,25)
                           ctxt.power := 0.8;
                        end if;
                        --  setPowerH2(power) (383,17)
                        RI_0_setPowerH2(ctxt.power);
                        --  RETURN  (None,None) at 518, 657
                        return;
                     end p_0_doA1;
                     

                  procedure p_0_doA2 is
                     begin
                        --  DECISION power = 0.0 (392,27)
                        --  ANSWER false (394,17)
                        if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
                           --  JOIN normalA2 (None,None) at None, None
                           goto normalA2;
                           --  ANSWER true (416,17)
                        elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
                           --  DECISION temp_plate <= 55.0 and
                           --  abs(temp_plate - temp_air) <= 50.0 (418,48)
                           --  COMMENT Pdiss = 0.0 W (421,20)
                           --  ANSWER true (423,25)
                           if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
                              --  JOIN normalA2 (425,33) at 757, 344
                              goto normalA2;
                              --  ANSWER false (427,25)
                           elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
                              --  RETURN  (None,None) at 861, 346
                              return;
                           end if;
                        end if;
                        --  setPowerH2(power) (433,17)
                        RI_0_setPowerH2(ctxt.power);
                        --  RETURN  (None,None) at 435, 612
                        return;
                        --  CONNECTION normalA2 (396,20)
                        <<normalA2>>
                        --  DECISION temp_plate >= 65.0 or
                        --  abs(temp_plate - temp_air) >= 60.0 (398,48)
                        --  COMMENT Pdiss = 1.0 (401,20)
                        --  ANSWER false (403,25)
                        if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
                           --  power := 0.6 (405,33)
                           ctxt.power := 0.6;
                           --  power_a2 := power (407,33)
                           ctxt.power_a2 := ctxt.power;
                           --  ANSWER true (409,25)
                        elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
                           --  power := 0.0 (411,33)
                           ctxt.power := 0.0;
                        end if;
                        --  writeln('normalA2') (414,25)
                        Put ("normalA2");
                        New_Line;
                        --  setPowerH2(power) (433,17)
                        RI_0_setPowerH2(ctxt.power);
                        --  RETURN  (None,None) at 435, 612
                        return;
                     end p_0_doA2;
                     

                  procedure p_0_doF2 is
                     begin
                        --  DECISION power = 0.0 (442,27)
                        --  ANSWER false (444,17)
                        if (asn1SccT_Float_Equal (ctxt.power, 0.0)) = false then
                           null;
                           --  ANSWER true (446,17)
                        elsif (asn1SccT_Float_Equal (ctxt.power, 0.0)) = true then
                           --  DECISION temp_plate <= 55.0 and
                           --  abs(temp_plate - temp_air) <= 50.0 (448,48)
                           --  ANSWER true (451,25)
                           if (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = true then
                              --  m := m+0.1 (453,33)
                              ctxt.m := (ctxt.m + 0.1);
                              --  ANSWER false (455,25)
                           elsif (((ctxt.temp_plate <= 55.0) and (abs((ctxt.temp_plate - ctxt.temp_air)) <= 50.0))) = false then
                              --  RETURN  (None,None) at 601, 362
                              return;
                           end if;
                        end if;
                        --  DECISION temp_plate >= 65.0 or 
                        --  abs (temp_plate - temp_air) >= 60.0 (461,40)
                        --  COMMENT >= 60? (464,12)
                        --  ANSWER true (466,17)
                        if (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = true then
                           --  power := 0.0 (468,25)
                           ctxt.power := 0.0;
                           --  ANSWER false (470,17)
                        elsif (((ctxt.temp_plate >= 65.0) or (abs((ctxt.temp_plate - ctxt.temp_air)) >= 60.0))) = false then
                           --  power := power_f1/2.0 - m*0.1 (472,25)
                           ctxt.power := ((ctxt.power_f1 / 2.0) - (ctxt.m * 0.1));
                           --  DECISION power <= 0.1 (474,35)
                           --  ANSWER true (476,25)
                           if ((ctxt.power <= 0.1)) = true then
                              --  power := 0.1 (478,33)
                              ctxt.power := 0.1;
                              --  ANSWER false (480,25)
                           elsif ((ctxt.power <= 0.1)) = false then
                              null;
                           end if;
                        end if;
                        --  setPowerH2(power) (484,17)
                        RI_0_setPowerH2(ctxt.power);
                        --  RETURN  (None,None) at 439, 851
                        return;
                     end p_0_doF2;
                     

                  procedure p_0_doF3 is
                     --  !! stack: _call_external_function line 1604
                     tmp723 : asn1SccT_Float;
                     begin
                        --  DECISION system_stopped (-1,-1)
                        --  ANSWER true (495,17)
                        if (ctxt.system_stopped) = true then
                           --  RETURN  (None,None) at 669, 238
                           return;
                           --  ANSWER false (499,17)
                        elsif (ctxt.system_stopped) = false then
                           null;
                        end if;
                        --  ok := call updateData (502,17)
                        ctxt.ok := p_0_updatedata;
                        --  DECISION ok and power = 0.0 (504,24)
                        --  ANSWER true (506,17)
                        if ((ctxt.ok and asn1SccT_Float_Equal (ctxt.power, 0.0))) = true then
                           --  system_stopped := true (508,25)
                           ctxt.system_stopped := true;
                           --  stopSystem (510,25)
                           RI_0_StopSystem;
                           --  ANSWER false (512,17)
                        elsif ((ctxt.ok and asn1SccT_Float_Equal (ctxt.power, 0.0))) = false then
                           --  setPowerH2(0.0) (514,25)
                           tmp723 := 0.0;
                           RI_0_setPowerH2(tmp723);
                        end if;
                        --  RETURN  (None,None) at 354, 601
                        return;
                     end p_0_doF3;
                     

                  procedure setCurrentMode(current_state: in out asn1SccHTL_State) is
                     begin
                        case ctxt.state is
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (6);
                           when asn1Sccf2 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (8);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Scca2 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (2);
                           when asn1Sccinit =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf3 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (10);
                           when asn1Scca1 =>
                              ctxt.actual_state := current_state;
                              Execute_Transition (4);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end setCurrentMode;
                     

                  procedure tick is
                     begin
                        case ctxt.state is
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
                              Execute_Transition (5);
                           when asn1Sccf2 =>
                              Execute_Transition (7);
                           when asn1Sccerror =>
                              Execute_Transition (11);
                           when asn1Scca2 =>
                              Execute_Transition (1);
                           when asn1Sccinit =>
                              Execute_Transition (18);
                           when asn1Sccf3 =>
                              Execute_Transition (9);
                           when asn1Scca1 =>
                              Execute_Transition (3);
                           when others =>
                              Execute_Transition (CS_Only);
                        end case;
                     end tick;
                     

                  procedure configureParameters_Transition is
                     begin
                        case ctxt.state is
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf2 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Scca2 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccinit =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf3 =>
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
                           when asn1Sccselectstate =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf1 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf2 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccerror =>
                              Execute_Transition (CS_Only);
                           when asn1Scca2 =>
                              Execute_Transition (CS_Only);
                           when asn1Sccinit =>
                              Execute_Transition (CS_Only);
                           when asn1Sccf3 =>
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
                                 --  NEXT_STATE Init (522,18) at 524, 116
                                 trId := -1;
                                 ctxt.State := asn1SccInit;
                                 goto Next_Transition;
                              when 1 =>
                                 --  InitA2 (528,17)
                                 p_0_initA2;
                                 --  kickTheDog (530,17)
                                 RI_0_KickTheDog;
                                 --  ok := call updateData (532,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (536,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (538,35)
                                    --  COMMENT no estamos cayendo? (540,20)
                                    --  ANSWER True (542,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  writeln('Nos estamos cayendo') (544,33)
                                       Put ("Nos estamos cayendo");
                                       New_Line;
                                       --  NEXT_STATE F3 (546,38) at 1798, 631
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (548,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       null;
                                    end if;
                                    --  ANSWER false (551,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (553,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (555,30) at 2027, 501
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                                 --  DECISION htl_time >= a2_duration_max
                                 --  or press <= press_18km (559,0)
                                 --  ANSWER false (561,17)
                                 if (((ctxt.htl_time >= ctxt.a2_duration_max) or (ctxt.press <= ctxt.press_18km))) = false then
                                    --  doA2 (563,25)
                                    p_0_doA2;
                                    --  NEXT_STATE A2 (565,30) at 1542, 896
                                    trId := -1;
                                    ctxt.State := asn1SccA2;
                                    goto Next_Transition;
                                    --  ANSWER true (567,17)
                                 elsif (((ctxt.htl_time >= ctxt.a2_duration_max) or (ctxt.press <= ctxt.press_18km))) = true then
                                    --  writeln('A2 max duration: ', a2_duration_max) (569,25)
                                    Put ("A2 max duration: ");
                                    Put (asn1SccT_Double'Image (ctxt.a2_duration_max));
                                    New_Line;
                                    --  NEXT_STATE F1 (571,30) at 1734, 901
                                    trId := -1;
                                    ctxt.State := asn1SccF1;
                                    goto Next_Transition;
                                 end if;
                              when 2 =>
                                 --  NEXT_STATE Selectstate (576,22) at 2235, 182
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 3 =>
                                 --  initA1 (583,17)
                                 p_0_initA1;
                                 --  KickTheDog (585,17)
                                 RI_0_KickTheDog;
                                 --  ok := call updateData (587,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (591,17)
                                 if (ctxt.ok) = true then
                                    null;
                                    --  ANSWER false (593,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (595,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (597,30) at 938, 510
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                                 --  DECISION (press <= press_10km and
                                 --  htl_time >= a1_duration_emergency) or
                                 --  htl_time >= a1_duration_max (601,35)
                                 --  ANSWER false (604,17)
                                 if ((((ctxt.press <= ctxt.press_10km) and (ctxt.htl_time >= ctxt.a1_duration_emergency)) or (ctxt.htl_time >= ctxt.a1_duration_max))) = false then
                                    --  doA1 (606,25)
                                    p_0_doA1;
                                    --  NEXT_STATE A1 (608,30) at 1014, 787
                                    trId := -1;
                                    ctxt.State := asn1SccA1;
                                    goto Next_Transition;
                                    --  ANSWER true (610,17)
                                 elsif ((((ctxt.press <= ctxt.press_10km) and (ctxt.htl_time >= ctxt.a1_duration_emergency)) or (ctxt.htl_time >= ctxt.a1_duration_max))) = true then
                                    --  NEXT_STATE A2 (612,30) at 1104, 737
                                    trId := -1;
                                    ctxt.State := asn1SccA2;
                                    goto Next_Transition;
                                 end if;
                              when 4 =>
                                 --  NEXT_STATE Selectstate (617,22) at 1373, 186
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 5 =>
                                 --  initf1 (624,17)
                                 p_0_initF1;
                                 --  kickTheDog (626,17)
                                 RI_0_KickTheDog;
                                 --  ok := call updateData (628,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (632,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (634,35)
                                    --  ANSWER True (636,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  NEXT_STATE F3 (638,38) at 2935, 588
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (640,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       --  DECISION htl_time >= f1_duration_max (642,46)
                                       --  ANSWER true (644,33)
                                       if ((ctxt.htl_time >= ctxt.f1_duration_max)) = true then
                                          --  NEXT_STATE F2 (646,46) at 2640, 735
                                          trId := -1;
                                          ctxt.State := asn1SccF2;
                                          goto Next_Transition;
                                          --  ANSWER false (648,33)
                                       elsif ((ctxt.htl_time >= ctxt.f1_duration_max)) = false then
                                          --  doF1 (650,41)
                                          p_0_doF1;
                                          --  NEXT_STATE F1 (652,46) at 2730, 790
                                          trId := -1;
                                          ctxt.State := asn1SccF1;
                                          goto Next_Transition;
                                       end if;
                                    end if;
                                    --  ANSWER false (656,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state := actual_state (658,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (660,30) at 2460, 512
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 6 =>
                                 --  NEXT_STATE Selectstate (665,22) at 3072, 192
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 7 =>
                                 --  initf2 (672,17)
                                 p_0_initF2;
                                 --  kickTheDog (674,17)
                                 RI_0_KickTheDog;
                                 --  ok := call updateData (676,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (680,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION press >= press_5km (682,35)
                                    --  ANSWER True (684,25)
                                    if ((ctxt.press >= ctxt.press_5km)) = true then
                                       --  NEXT_STATE F3 (686,38) at 1797, 1434
                                       trId := -1;
                                       ctxt.State := asn1SccF3;
                                       goto Next_Transition;
                                       --  ANSWER False (688,25)
                                    elsif ((ctxt.press >= ctxt.press_5km)) = false then
                                       --  DECISION htl_time >= f2_duration_max (690,46)
                                       --  ANSWER true (692,33)
                                       if ((ctxt.htl_time >= ctxt.f2_duration_max)) = true then
                                          --  NEXT_STATE F3 (694,46) at 1513, 1570
                                          --  COMMENT time in F3 is bigger
                                          --  than the allowed. (696,36)
                                          trId := -1;
                                          ctxt.State := asn1SccF3;
                                          goto Next_Transition;
                                          --  ANSWER false (699,33)
                                       elsif ((ctxt.htl_time >= ctxt.f2_duration_max)) = false then
                                          --  doF2 (701,41)
                                          p_0_doF2;
                                          --  NEXT_STATE F2 (703,46) at 1623, 1622
                                          trId := -1;
                                          ctxt.State := asn1SccF2;
                                          goto Next_Transition;
                                       end if;
                                    end if;
                                    --  ANSWER false (707,17)
                                 elsif (ctxt.ok) = false then
                                    --  last_good_state:=actual_state (709,25)
                                    ctxt.last_good_state := ctxt.actual_state;
                                    --  NEXT_STATE Error (711,30) at 1259, 1375
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 8 =>
                                 --  NEXT_STATE Selectstate (716,22) at 1944, 1057
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 9 =>
                                 --  actual_state := f3 (723,17)
                                 ctxt.actual_state := asn1Sccf3;
                                 --  doF3 (725,17)
                                 p_0_doF3;
                                 --  kickTheDog (727,17)
                                 RI_0_KickTheDog;
                                 --  NEXT_STATE F3 (729,22) at 2194, 1228
                                 trId := -1;
                                 ctxt.State := asn1SccF3;
                                 goto Next_Transition;
                              when 10 =>
                                 --  NEXT_STATE Selectstate (733,22) at 2364, 1063
                                 trId := -1;
                                 ctxt.State := asn1SccSelectstate;
                                 goto Next_Transition;
                              when 11 =>
                                 --  ok := call updateData (740,17)
                                 ctxt.ok := p_0_updatedata;
                                 --  actual_state := error (741,0)
                                 ctxt.actual_state := asn1Sccerror;
                                 --  DECISION ok (-1,-1)
                                 --  ANSWER true (745,17)
                                 if (ctxt.ok) = true then
                                    --  DECISION last_good_state (-1,-1)
                                    --  ANSWER a1 (749,25)
                                    if (ctxt.last_good_state) = asn1Scca1 then
                                       --  NEXT_STATE A1 (751,38) at 2332, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccA1;
                                       goto Next_Transition;
                                       --  ANSWER a2 (753,25)
                                    elsif (ctxt.last_good_state) = asn1Scca2 then
                                       --  NEXT_STATE A2 (755,38) at 2422, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccA2;
                                       goto Next_Transition;
                                       --  ANSWER f1 (757,25)
                                    elsif (ctxt.last_good_state) = asn1Sccf1 then
                                       --  NEXT_STATE F1 (759,38) at 2512, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccF1;
                                       goto Next_Transition;
                                       --  ANSWER f2 (761,25)
                                    elsif (ctxt.last_good_state) = asn1Sccf2 then
                                       --  NEXT_STATE F2 (763,38) at 2602, 1357
                                       trId := -1;
                                       ctxt.State := asn1SccF2;
                                       goto Next_Transition;
                                       --  ANSWER else (None,None)
                                    else
                                       --  NEXT_STATE Error (767,38) at 2692, 1362
                                       trId := -1;
                                       ctxt.State := asn1SccError;
                                       goto Next_Transition;
                                    end if;
                                    --  ANSWER false (770,17)
                                 elsif (ctxt.ok) = false then
                                    --  NEXT_STATE Error (772,30) at 2773, 1243
                                    trId := -1;
                                    ctxt.State := asn1SccError;
                                    goto Next_Transition;
                                 end if;
                              when 12 =>
                                 --  NEXT_STATE F2 (780,22) at 1081, 1065
                                 trId := -1;
                                 ctxt.State := asn1SccF2;
                                 goto Next_Transition;
                              when 13 =>
                                 --  NEXT_STATE A1 (784,22) at 820, 1060
                                 trId := -1;
                                 ctxt.State := asn1SccA1;
                                 goto Next_Transition;
                              when 14 =>
                                 --  NEXT_STATE A2 (788,22) at 542, 1060
                                 trId := -1;
                                 ctxt.State := asn1SccA2;
                                 goto Next_Transition;
                              when 15 =>
                                 --  NEXT_STATE F1 (792,22) at 686, 1065
                                 trId := -1;
                                 ctxt.State := asn1SccF1;
                                 goto Next_Transition;
                              when 16 =>
                                 --  NEXT_STATE F3 (796,22) at 950, 1063
                                 trId := -1;
                                 ctxt.State := asn1SccF3;
                                 goto Next_Transition;
                              when 17 =>
                                 --  NEXT_STATE Error (800,22) at 1222, 1065
                                 trId := -1;
                                 ctxt.State := asn1SccError;
                                 goto Next_Transition;
                              when 18 =>
                                 --  RecoverHTLParams(actual_state, f1_duration_max, f2_duration_max) (807,17)
                                 RI_0_RecoverHTLParams(ctxt.actual_state, ctxt.f1_duration_max, ctxt.f2_duration_max);
                                 --  writeln('Actual State: ', actual_state) (809,17)
                                 Put ("Actual State: ");
                                 Put (ctxt.actual_state'Img);
                                 New_Line;
                                 --  writeln('F1 max time', f1_duration_max) (811,17)
                                 Put ("F1 max time");
                                 Put (asn1SccT_Double'Image (ctxt.f1_duration_max));
                                 New_Line;
                                 --  writeln('F2 max time', f2_duration_max) (813,17)
                                 Put ("F2 max time");
                                 Put (asn1SccT_Double'Image (ctxt.f2_duration_max));
                                 New_Line;
                                 --  NEXT_STATE selectstate (815,22) at 798, 392
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
                              --  DECISION actual_state = f2 (778,30)
                              --  ANSWER true (None,None)
                              if ((ctxt.actual_state = asn1Sccf2)) = true then
                                 trId := 12;
                                 --  Priority 1
                                 --  DECISION actual_state = a1 (782,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Scca1)) = true then
                                 trId := 13;
                                 --  Priority 1
                                 --  DECISION actual_state = a2 (786,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Scca2)) = true then
                                 trId := 14;
                                 --  Priority 1
                                 --  DECISION actual_state = f1 (790,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccf1)) = true then
                                 trId := 15;
                                 --  Priority 1
                                 --  DECISION actual_state = f3 (794,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccf3)) = true then
                                 trId := 16;
                                 --  Priority 1
                                 --  DECISION actual_state = error (798,30)
                                 --  ANSWER true (None,None)
                              elsif ((ctxt.actual_state = asn1Sccerror)) = true then
                                 trId := 17;
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