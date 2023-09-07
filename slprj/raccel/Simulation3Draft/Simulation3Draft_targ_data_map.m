    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 10;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 66;
            section.data(66)  = dumData; %prealloc

                    ;% rtP.InputPWM
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.WheelSpeed
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 173;

                    ;% rtP.axleLength
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 346;

                    ;% rtP.lineLength
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 347;

                    ;% rtP.ticksPerRot
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 348;

                    ;% rtP.wheelR
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 349;

                    ;% rtP.PIDController_I
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 350;

                    ;% rtP.PIDController_I_i45pwgvuma
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 351;

                    ;% rtP.PIDController_InitialConditionForIntegrator
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 352;

                    ;% rtP.PIDController_InitialConditionForIntegrator_epasr05elh
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 353;

                    ;% rtP.PIDController_LowerSaturationLimit
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 354;

                    ;% rtP.PIDController_LowerSaturationLimit_np30azhqa2
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 355;

                    ;% rtP.PIDController_P
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 356;

                    ;% rtP.PIDController_P_kws2tbogph
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 357;

                    ;% rtP.PIDController_UpperSaturationLimit
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 358;

                    ;% rtP.PIDController_UpperSaturationLimit_lonuxufgp5
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 359;

                    ;% rtP.LineSensor_envVal
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 360;

                    ;% rtP.LineSensor_lineVal
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 361;

                    ;% rtP.LeftMotor_sensorType
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 362;

                    ;% rtP.RightMotor_sensorType
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 363;

                    ;% rtP.RobotSimulator_startTheta
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 364;

                    ;% rtP.RobotSimulator_startX
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 365;

                    ;% rtP.RobotSimulator_startY
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 366;

                    ;% rtP.Towlwr_wheelR
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 367;

                    ;% rtP.Gain_Gain
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 368;

                    ;% rtP.Gain_Gain_o4hmcpr5ca
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 369;

                    ;% rtP.Constant1_Value
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 370;

                    ;% rtP.Constant1_Value_puhyejpghs
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 371;

                    ;% rtP.DiscreteTimeIntegrator_gainval
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 372;

                    ;% rtP.DiscreteTimeIntegrator1_gainval
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 373;

                    ;% rtP.DiscreteTimeIntegrator2_gainval
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 374;

                    ;% rtP.DiscreteTimeIntegrator_gainval_afikqgzpe0
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 375;

                    ;% rtP.DiscreteTimeIntegrator_IC
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 376;

                    ;% rtP.Internal_A
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 377;

                    ;% rtP.Internal_B
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 386;

                    ;% rtP.Internal_C
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 389;

                    ;% rtP.Switch_Threshold
                    section.data(37).logicalSrcIdx = 38;
                    section.data(37).dtTransOffset = 392;

                    ;% rtP.DiscreteTimeIntegrator_gainval_ptlrlhszmg
                    section.data(38).logicalSrcIdx = 39;
                    section.data(38).dtTransOffset = 393;

                    ;% rtP.DiscreteTimeIntegrator_IC_e3x2ks5ohu
                    section.data(39).logicalSrcIdx = 40;
                    section.data(39).dtTransOffset = 394;

                    ;% rtP.Internal_A_avp5ztxxzl
                    section.data(40).logicalSrcIdx = 41;
                    section.data(40).dtTransOffset = 395;

                    ;% rtP.Internal_B_ebkdikdi50
                    section.data(41).logicalSrcIdx = 42;
                    section.data(41).dtTransOffset = 404;

                    ;% rtP.Internal_C_hiyczu5j42
                    section.data(42).logicalSrcIdx = 43;
                    section.data(42).dtTransOffset = 407;

                    ;% rtP.Switch_Threshold_bmwdvzwwf2
                    section.data(43).logicalSrcIdx = 46;
                    section.data(43).dtTransOffset = 410;

                    ;% rtP.SoftRealTime_P1_Size
                    section.data(44).logicalSrcIdx = 47;
                    section.data(44).dtTransOffset = 411;

                    ;% rtP.SoftRealTime_P1
                    section.data(45).logicalSrcIdx = 48;
                    section.data(45).dtTransOffset = 413;

                    ;% rtP.changeparameters_Gain
                    section.data(46).logicalSrcIdx = 49;
                    section.data(46).dtTransOffset = 414;

                    ;% rtP.DiscreteTimeIntegrator_gainval_lzyl4k4zxv
                    section.data(47).logicalSrcIdx = 50;
                    section.data(47).dtTransOffset = 418;

                    ;% rtP.DiscreteTimeIntegrator_IC_f5z3vyriqm
                    section.data(48).logicalSrcIdx = 51;
                    section.data(48).dtTransOffset = 419;

                    ;% rtP.DiscreteTimeIntegrator1_gainval_fz4ugw3les
                    section.data(49).logicalSrcIdx = 52;
                    section.data(49).dtTransOffset = 420;

                    ;% rtP.DiscreteTimeIntegrator1_IC
                    section.data(50).logicalSrcIdx = 53;
                    section.data(50).dtTransOffset = 421;

                    ;% rtP.Gain2_Gain
                    section.data(51).logicalSrcIdx = 54;
                    section.data(51).dtTransOffset = 422;

                    ;% rtP.Integrator_gainval
                    section.data(52).logicalSrcIdx = 55;
                    section.data(52).dtTransOffset = 423;

                    ;% rtP.Gain2_Gain_cq42p4ubq2
                    section.data(53).logicalSrcIdx = 56;
                    section.data(53).dtTransOffset = 424;

                    ;% rtP.Gain3_Gain
                    section.data(54).logicalSrcIdx = 57;
                    section.data(54).dtTransOffset = 425;

                    ;% rtP.Gain3_Gain_moxmp2rie1
                    section.data(55).logicalSrcIdx = 58;
                    section.data(55).dtTransOffset = 426;

                    ;% rtP.Integrator_gainval_di3rudnbjq
                    section.data(56).logicalSrcIdx = 59;
                    section.data(56).dtTransOffset = 427;

                    ;% rtP.Circle_Value
                    section.data(57).logicalSrcIdx = 60;
                    section.data(57).dtTransOffset = 428;

                    ;% rtP.Gain1_Gain
                    section.data(58).logicalSrcIdx = 61;
                    section.data(58).dtTransOffset = 429;

                    ;% rtP.Constant_Value
                    section.data(59).logicalSrcIdx = 62;
                    section.data(59).dtTransOffset = 430;

                    ;% rtP.Constant1_Value_l3t40ea4hs
                    section.data(60).logicalSrcIdx = 63;
                    section.data(60).dtTransOffset = 434;

                    ;% rtP.Constant_Value_djcmpvlzjp
                    section.data(61).logicalSrcIdx = 64;
                    section.data(61).dtTransOffset = 438;

                    ;% rtP.Constant1_Value_k2rcs4rpgg
                    section.data(62).logicalSrcIdx = 65;
                    section.data(62).dtTransOffset = 439;

                    ;% rtP.Clamping_zero_Value
                    section.data(63).logicalSrcIdx = 66;
                    section.data(63).dtTransOffset = 440;

                    ;% rtP.DriveDist_Value
                    section.data(64).logicalSrcIdx = 67;
                    section.data(64).dtTransOffset = 441;

                    ;% rtP.DriveRot_Value
                    section.data(65).logicalSrcIdx = 68;
                    section.data(65).dtTransOffset = 442;

                    ;% rtP.Clamping_zero_Value_ojxi3o54um
                    section.data(66).logicalSrcIdx = 69;
                    section.data(66).dtTransOffset = 443;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.Switch_Threshold_j3y0cmi1bi
                    section.data(1).logicalSrcIdx = 70;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% rtP.Constant_Value_aizakqrn1k
                    section.data(1).logicalSrcIdx = 71;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Constant2_Value
                    section.data(2).logicalSrcIdx = 72;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.Constant3_Value
                    section.data(3).logicalSrcIdx = 73;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.Constant4_Value
                    section.data(4).logicalSrcIdx = 74;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.Constant_Value_bkskdfhvuo
                    section.data(5).logicalSrcIdx = 75;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.Constant2_Value_ntd5a3hqim
                    section.data(6).logicalSrcIdx = 76;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.Constant3_Value_ekyrhetqpn
                    section.data(7).logicalSrcIdx = 77;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.Constant4_Value_o1rmvqswsf
                    section.data(8).logicalSrcIdx = 78;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.hsodnwhfav.Constant_Value
                    section.data(1).logicalSrcIdx = 79;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% rtP.hsodnwhfav.hsodnwhfav.Gain1_Gain
                    section.data(1).logicalSrcIdx = 80;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.hsodnwhfav.hsodnwhfav.Bias_Bias
                    section.data(2).logicalSrcIdx = 81;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.hsodnwhfav.hsodnwhfav.Saturation_UpperSat
                    section.data(3).logicalSrcIdx = 82;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.hsodnwhfav.hsodnwhfav.Saturation_LowerSat
                    section.data(4).logicalSrcIdx = 83;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.hsodnwhfav.hsodnwhfav.Gain_Gain
                    section.data(5).logicalSrcIdx = 84;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.hsodnwhfav.hsodnwhfav.Bias1_Bias
                    section.data(6).logicalSrcIdx = 85;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.hsodnwhfav.hsodnwhfav.Saturation1_UpperSat
                    section.data(7).logicalSrcIdx = 86;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.hsodnwhfav.hsodnwhfav.Saturation1_LowerSat
                    section.data(8).logicalSrcIdx = 87;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.hsodnwhfav.hsodnwhfav.Constant_Value
                    section.data(9).logicalSrcIdx = 88;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.hsodnwhfav.hsodnwhfav.Constant1_Value
                    section.data(10).logicalSrcIdx = 89;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.hsodnwhfav.hsodnwhfav.DirectLookupTablenD_table
                    section.data(1).logicalSrcIdx = 90;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.hsodnwhfav.hsodnwhfav.DirectLookupTablenD_DiagnosticForOutOfRangeInput
                    section.data(1).logicalSrcIdx = 91;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% rtP.plige5liff.Gain1_Gain
                    section.data(1).logicalSrcIdx = 92;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.plige5liff.Bias_Bias
                    section.data(2).logicalSrcIdx = 93;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.plige5liff.Gain_Gain
                    section.data(3).logicalSrcIdx = 94;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.plige5liff.Bias1_Bias
                    section.data(4).logicalSrcIdx = 95;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.plige5liff.Saturation2_UpperSat
                    section.data(5).logicalSrcIdx = 96;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.plige5liff.Saturation2_LowerSat
                    section.data(6).logicalSrcIdx = 97;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.plige5liff.Saturation3_UpperSat
                    section.data(7).logicalSrcIdx = 98;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.plige5liff.Saturation3_LowerSat
                    section.data(8).logicalSrcIdx = 99;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.plige5liff.Constant_Value
                    section.data(9).logicalSrcIdx = 100;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.plige5liff.DirectLookupTablenD_table
                    section.data(1).logicalSrcIdx = 101;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.plige5liff.DirectLookupTablenD_DiagnosticForOutOfRangeInput
                    section.data(1).logicalSrcIdx = 102;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(10) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 4;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 25;
            section.data(25)  = dumData; %prealloc

                    ;% rtB.ktg4baxiij
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.cbrh4plvr3
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.athhvkdmdz
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.pcgdgayggx
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.g0jjedl3h4
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtB.fiztfjj1x3
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtB.d0xjp4ie5e
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtB.j23fnzwcfw
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtB.kg0pryf3mc
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtB.b3jbm402ar
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 12;

                    ;% rtB.ojoimenkbs
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 13;

                    ;% rtB.hohqowutc2
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 14;

                    ;% rtB.plm3guhvpt
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 15;

                    ;% rtB.i3sd1i01sd
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 16;

                    ;% rtB.om1zkmalu1
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 17;

                    ;% rtB.cu0343r3i2
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 18;

                    ;% rtB.lg1haipmqu
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 19;

                    ;% rtB.evsbnfyjxg
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 20;

                    ;% rtB.ooajfnplre
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 21;

                    ;% rtB.kqcugdbf5g
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 22;

                    ;% rtB.hnkwggkzou
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 23;

                    ;% rtB.lupfetmmtb
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 24;

                    ;% rtB.acattgqayi
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 25;

                    ;% rtB.n4nupykk20
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 34;

                    ;% rtB.jnpqvfwuw0
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 35;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.iitlyzvbjb
                    section.data(1).logicalSrcIdx = 26;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.hsodnwhfav[0].bm4eudfrr4
                    section.data(1).logicalSrcIdx = 27;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.hsodnwhfav[0].jz240yzam0
                    section.data(1).logicalSrcIdx = 29;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 14;
        sectIdxOffset = 4;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (rtDW)
        ;%
            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% rtDW.i2qyvx2esr
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.efs3a3hh2e
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.ludo5r20l3
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.m4gnknfopa
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.b2hfiqnrei
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.ghbxb2zrik
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 7;

                    ;% rtDW.i3g2v5ygab
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 8;

                    ;% rtDW.gwgdijo4lu
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 11;

                    ;% rtDW.dpj2cs1yxt
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 12;

                    ;% rtDW.mcaxcsndtw
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 13;

                    ;% rtDW.lgzytb1guk
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 14;

                    ;% rtDW.glmlggcvnu
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 15;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtDW.gx0eezp4oh.LoggedData
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.ly1uzbh4ws.LoggedData
                    section.data(2).logicalSrcIdx = 13;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.pocqi4rzhx.LoggedData
                    section.data(3).logicalSrcIdx = 14;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% rtDW.dtffab24fv
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.g4mgdk51u1
                    section.data(2).logicalSrcIdx = 16;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.cziarvqn3t
                    section.data(3).logicalSrcIdx = 17;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.bs4xv2f2dq
                    section.data(4).logicalSrcIdx = 18;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.cv32usfudo
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% rtDW.oc2vv2qobo
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.p2ujolujvr
                    section.data(2).logicalSrcIdx = 21;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.fredjixzlu
                    section.data(3).logicalSrcIdx = 22;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.p3xvndme1v
                    section.data(4).logicalSrcIdx = 23;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtDW.o3vvrfpxkk
                    section.data(1).logicalSrcIdx = 24;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.mbgesywozm
                    section.data(2).logicalSrcIdx = 25;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.hsodnwhfav[0].e3evixvwmi
                    section.data(1).logicalSrcIdx = 26;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.hsodnwhfav[0].klt5acnwos
                    section.data(1).logicalSrcIdx = 27;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.hsodnwhfav[0].pohhf0zdrr
                    section.data(1).logicalSrcIdx = 28;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.hsodnwhfav[0].hsodnwhfav[200].hz3a5pczoy
                    section.data(1).logicalSrcIdx = 29;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.plige5liff[3].ok2jbhyf1e
                    section.data(1).logicalSrcIdx = 30;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.plige5liff[3].h11ovhfoxn
                    section.data(1).logicalSrcIdx = 31;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.plige5liff[3].c2dlt0ce3l
                    section.data(1).logicalSrcIdx = 32;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(13) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.plige5liff[3].hecpg1s5r3
                    section.data(1).logicalSrcIdx = 33;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(14) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 3909823708;
    targMap.checksum1 = 1113749105;
    targMap.checksum2 = 912998277;
    targMap.checksum3 = 2265357886;

