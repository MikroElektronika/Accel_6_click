
_systemInit:

;Click_Accel6_PIC.c,42 :: 		void systemInit()
;Click_Accel6_PIC.c,44 :: 		mikrobus_i2cInit( _MIKROBUS1, &_ACCEL6_I2C_CFG[0] );
	CLRF        FARG_mikrobus_i2cInit_bus+0 
	MOVLW       __ACCEL6_I2C_CFG+0
	MOVWF       FARG_mikrobus_i2cInit_cfg+0 
	MOVLW       hi_addr(__ACCEL6_I2C_CFG+0)
	MOVWF       FARG_mikrobus_i2cInit_cfg+1 
	MOVLW       higher_addr(__ACCEL6_I2C_CFG+0)
	MOVWF       FARG_mikrobus_i2cInit_cfg+2 
	CALL        _mikrobus_i2cInit+0, 0
;Click_Accel6_PIC.c,45 :: 		mikrobus_logInit( _LOG_USBUART, 9600 );
	MOVLW       16
	MOVWF       FARG_mikrobus_logInit_port+0 
	MOVLW       128
	MOVWF       FARG_mikrobus_logInit_baud+0 
	MOVLW       37
	MOVWF       FARG_mikrobus_logInit_baud+1 
	MOVLW       0
	MOVWF       FARG_mikrobus_logInit_baud+2 
	MOVWF       FARG_mikrobus_logInit_baud+3 
	CALL        _mikrobus_logInit+0, 0
;Click_Accel6_PIC.c,46 :: 		mikrobus_logWrite(" --- System init --- ", _LOG_LINE);
	MOVLW       ?lstr1_Click_Accel6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr1_Click_Accel6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,47 :: 		Delay_ms( 100 );
	MOVLW       9
	MOVWF       R11, 0
	MOVLW       30
	MOVWF       R12, 0
	MOVLW       228
	MOVWF       R13, 0
L_systemInit0:
	DECFSZ      R13, 1, 1
	BRA         L_systemInit0
	DECFSZ      R12, 1, 1
	BRA         L_systemInit0
	DECFSZ      R11, 1, 1
	BRA         L_systemInit0
	NOP
;Click_Accel6_PIC.c,48 :: 		}
L_end_systemInit:
	RETURN      0
; end of _systemInit

_applicationInit:

;Click_Accel6_PIC.c,50 :: 		void applicationInit()
;Click_Accel6_PIC.c,52 :: 		accel6_i2cDriverInit( (T_ACCEL6_P)&_MIKROBUS1_GPIO, (T_ACCEL6_P)&_MIKROBUS1_I2C, 0x18 );
	MOVLW       __MIKROBUS1_GPIO+0
	MOVWF       FARG_accel6_i2cDriverInit_gpioObj+0 
	MOVLW       hi_addr(__MIKROBUS1_GPIO+0)
	MOVWF       FARG_accel6_i2cDriverInit_gpioObj+1 
	MOVLW       higher_addr(__MIKROBUS1_GPIO+0)
	MOVWF       FARG_accel6_i2cDriverInit_gpioObj+2 
	MOVLW       __MIKROBUS1_I2C+0
	MOVWF       FARG_accel6_i2cDriverInit_i2cObj+0 
	MOVLW       hi_addr(__MIKROBUS1_I2C+0)
	MOVWF       FARG_accel6_i2cDriverInit_i2cObj+1 
	MOVLW       higher_addr(__MIKROBUS1_I2C+0)
	MOVWF       FARG_accel6_i2cDriverInit_i2cObj+2 
	MOVLW       24
	MOVWF       FARG_accel6_i2cDriverInit_slave+0 
	CALL        _accel6_i2cDriverInit+0, 0
;Click_Accel6_PIC.c,54 :: 		accel6_softReset();
	CALL        _accel6_softReset+0, 0
;Click_Accel6_PIC.c,55 :: 		accel6_init(_ACCEL6_PMU_RANGE_4g, _ACCEL6_PMU_BW_125Hz, _ACCEL6_PMU_LPW_NORMAL_MODE | _ACCEL6_PMU_LPW_SLEEP_10ms);
	MOVLW       __ACCEL6_PMU_RANGE_4g
	MOVWF       FARG_accel6_init_range_data+0 
	MOVLW       __ACCEL6_PMU_BW_125Hz
	MOVWF       FARG_accel6_init_bw_data+0 
	MOVLW       __ACCEL6_PMU_LPW_NORMAL_MODE
	MOVWF       R0 
	MOVLW       __ACCEL6_PMU_LPW_SLEEP_10ms
	IORWF       R0, 0 
	MOVWF       FARG_accel6_init_lpw_data+0 
	CALL        _accel6_init+0, 0
;Click_Accel6_PIC.c,56 :: 		Delay_100ms();
	CALL        _Delay_100ms+0, 0
;Click_Accel6_PIC.c,57 :: 		}
L_end_applicationInit:
	RETURN      0
; end of _applicationInit

_applicationTask:

;Click_Accel6_PIC.c,59 :: 		void applicationTask()
;Click_Accel6_PIC.c,61 :: 		mikrobus_logWrite(" X axis :  ", _LOG_TEXT);
	MOVLW       ?lstr2_Click_Accel6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr2_Click_Accel6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,62 :: 		fAxis = accel6_getAxis(_ACCEL6_AXIS_X);
	MOVLW       __ACCEL6_AXIS_X
	MOVWF       FARG_accel6_getAxis_axis+0 
	CALL        _accel6_getAxis+0, 0
	MOVF        R0, 0 
	MOVWF       _fAxis+0 
	MOVF        R1, 0 
	MOVWF       _fAxis+1 
	MOVF        R2, 0 
	MOVWF       _fAxis+2 
	MOVF        R3, 0 
	MOVWF       _fAxis+3 
;Click_Accel6_PIC.c,63 :: 		FloatToStr(fAxis, demoText);
	MOVF        R0, 0 
	MOVWF       FARG_FloatToStr_fnum+0 
	MOVF        R1, 0 
	MOVWF       FARG_FloatToStr_fnum+1 
	MOVF        R2, 0 
	MOVWF       FARG_FloatToStr_fnum+2 
	MOVF        R3, 0 
	MOVWF       FARG_FloatToStr_fnum+3 
	MOVLW       _demoText+0
	MOVWF       FARG_FloatToStr_str+0 
	MOVLW       hi_addr(_demoText+0)
	MOVWF       FARG_FloatToStr_str+1 
	CALL        _FloatToStr+0, 0
;Click_Accel6_PIC.c,64 :: 		mikrobus_logWrite(demoText, _LOG_TEXT);
	MOVLW       _demoText+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(_demoText+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,65 :: 		mikrobus_logWrite(" mg ", _LOG_LINE);
	MOVLW       ?lstr3_Click_Accel6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr3_Click_Accel6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,67 :: 		mikrobus_logWrite(" Y axis :  ", _LOG_TEXT);
	MOVLW       ?lstr4_Click_Accel6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr4_Click_Accel6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,68 :: 		fAxis = accel6_getAxis(_ACCEL6_AXIS_Y);
	MOVLW       __ACCEL6_AXIS_Y
	MOVWF       FARG_accel6_getAxis_axis+0 
	CALL        _accel6_getAxis+0, 0
	MOVF        R0, 0 
	MOVWF       _fAxis+0 
	MOVF        R1, 0 
	MOVWF       _fAxis+1 
	MOVF        R2, 0 
	MOVWF       _fAxis+2 
	MOVF        R3, 0 
	MOVWF       _fAxis+3 
;Click_Accel6_PIC.c,69 :: 		FloatToStr(fAxis, demoText);
	MOVF        R0, 0 
	MOVWF       FARG_FloatToStr_fnum+0 
	MOVF        R1, 0 
	MOVWF       FARG_FloatToStr_fnum+1 
	MOVF        R2, 0 
	MOVWF       FARG_FloatToStr_fnum+2 
	MOVF        R3, 0 
	MOVWF       FARG_FloatToStr_fnum+3 
	MOVLW       _demoText+0
	MOVWF       FARG_FloatToStr_str+0 
	MOVLW       hi_addr(_demoText+0)
	MOVWF       FARG_FloatToStr_str+1 
	CALL        _FloatToStr+0, 0
;Click_Accel6_PIC.c,70 :: 		mikrobus_logWrite(demoText, _LOG_TEXT);
	MOVLW       _demoText+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(_demoText+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,71 :: 		mikrobus_logWrite(" mg ", _LOG_LINE);
	MOVLW       ?lstr5_Click_Accel6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr5_Click_Accel6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,73 :: 		mikrobus_logWrite(" Z axis :  ", _LOG_TEXT);
	MOVLW       ?lstr6_Click_Accel6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr6_Click_Accel6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,74 :: 		fAxis = accel6_getAxis(_ACCEL6_AXIS_Y);
	MOVLW       __ACCEL6_AXIS_Y
	MOVWF       FARG_accel6_getAxis_axis+0 
	CALL        _accel6_getAxis+0, 0
	MOVF        R0, 0 
	MOVWF       _fAxis+0 
	MOVF        R1, 0 
	MOVWF       _fAxis+1 
	MOVF        R2, 0 
	MOVWF       _fAxis+2 
	MOVF        R3, 0 
	MOVWF       _fAxis+3 
;Click_Accel6_PIC.c,75 :: 		FloatToStr(fAxis, demoText);
	MOVF        R0, 0 
	MOVWF       FARG_FloatToStr_fnum+0 
	MOVF        R1, 0 
	MOVWF       FARG_FloatToStr_fnum+1 
	MOVF        R2, 0 
	MOVWF       FARG_FloatToStr_fnum+2 
	MOVF        R3, 0 
	MOVWF       FARG_FloatToStr_fnum+3 
	MOVLW       _demoText+0
	MOVWF       FARG_FloatToStr_str+0 
	MOVLW       hi_addr(_demoText+0)
	MOVWF       FARG_FloatToStr_str+1 
	CALL        _FloatToStr+0, 0
;Click_Accel6_PIC.c,76 :: 		mikrobus_logWrite(demoText, _LOG_TEXT);
	MOVLW       _demoText+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(_demoText+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,77 :: 		mikrobus_logWrite(" mg ", _LOG_LINE);
	MOVLW       ?lstr7_Click_Accel6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr7_Click_Accel6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,79 :: 		mikrobus_logWrite(" Temperature :  ", _LOG_TEXT);
	MOVLW       ?lstr8_Click_Accel6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr8_Click_Accel6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,80 :: 		Temp = accel6_getTemperature();
	CALL        _accel6_getTemperature+0, 0
	MOVF        R0, 0 
	MOVWF       _Temp+0 
	MOVF        R1, 0 
	MOVWF       _Temp+1 
	MOVF        R2, 0 
	MOVWF       _Temp+2 
	MOVF        R3, 0 
	MOVWF       _Temp+3 
;Click_Accel6_PIC.c,81 :: 		FloatToStr(Temp, demoText);
	MOVF        R0, 0 
	MOVWF       FARG_FloatToStr_fnum+0 
	MOVF        R1, 0 
	MOVWF       FARG_FloatToStr_fnum+1 
	MOVF        R2, 0 
	MOVWF       FARG_FloatToStr_fnum+2 
	MOVF        R3, 0 
	MOVWF       FARG_FloatToStr_fnum+3 
	MOVLW       _demoText+0
	MOVWF       FARG_FloatToStr_str+0 
	MOVLW       hi_addr(_demoText+0)
	MOVWF       FARG_FloatToStr_str+1 
	CALL        _FloatToStr+0, 0
;Click_Accel6_PIC.c,82 :: 		mikrobus_logWrite(demoText, _LOG_TEXT);
	MOVLW       _demoText+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(_demoText+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,83 :: 		mikrobus_logWrite(" C ", _LOG_LINE);
	MOVLW       ?lstr9_Click_Accel6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr9_Click_Accel6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,85 :: 		accel6_getOrient(&z_orient[0], &xy_orient[0]);
	MOVLW       _z_orient+0
	MOVWF       FARG_accel6_getOrient_z_orient+0 
	MOVLW       hi_addr(_z_orient+0)
	MOVWF       FARG_accel6_getOrient_z_orient+1 
	MOVLW       _xy_orient+0
	MOVWF       FARG_accel6_getOrient_xy_orient+0 
	MOVLW       hi_addr(_xy_orient+0)
	MOVWF       FARG_accel6_getOrient_xy_orient+1 
	CALL        _accel6_getOrient+0, 0
;Click_Accel6_PIC.c,87 :: 		switch(z_orient[0])
	GOTO        L_applicationTask1
;Click_Accel6_PIC.c,89 :: 		case 1:
L_applicationTask3:
;Click_Accel6_PIC.c,91 :: 		mikrobus_logWrite(" Z orient : UPWARD looking ", _LOG_LINE);
	MOVLW       ?lstr10_Click_Accel6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr10_Click_Accel6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,92 :: 		break;
	GOTO        L_applicationTask2
;Click_Accel6_PIC.c,94 :: 		case 2:
L_applicationTask4:
;Click_Accel6_PIC.c,96 :: 		mikrobus_logWrite(" Z orient : DOWNWARD looking ", _LOG_LINE);
	MOVLW       ?lstr11_Click_Accel6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr11_Click_Accel6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,97 :: 		break;
	GOTO        L_applicationTask2
;Click_Accel6_PIC.c,99 :: 		default:
L_applicationTask5:
;Click_Accel6_PIC.c,101 :: 		break;
	GOTO        L_applicationTask2
;Click_Accel6_PIC.c,103 :: 		}
L_applicationTask1:
	MOVF        _z_orient+0, 0 
	XORLW       1
	BTFSC       STATUS+0, 2 
	GOTO        L_applicationTask3
	MOVF        _z_orient+0, 0 
	XORLW       2
	BTFSC       STATUS+0, 2 
	GOTO        L_applicationTask4
	GOTO        L_applicationTask5
L_applicationTask2:
;Click_Accel6_PIC.c,105 :: 		switch(xy_orient[0])
	GOTO        L_applicationTask6
;Click_Accel6_PIC.c,107 :: 		case 1:
L_applicationTask8:
;Click_Accel6_PIC.c,109 :: 		mikrobus_logWrite(" XY orient : UPSIDE DOWN ", _LOG_LINE);
	MOVLW       ?lstr12_Click_Accel6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr12_Click_Accel6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,110 :: 		break;
	GOTO        L_applicationTask7
;Click_Accel6_PIC.c,112 :: 		case 2:
L_applicationTask9:
;Click_Accel6_PIC.c,114 :: 		mikrobus_logWrite(" XY orient : LANDSCAPE LEFT ", _LOG_LINE);
	MOVLW       ?lstr13_Click_Accel6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr13_Click_Accel6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,115 :: 		break;
	GOTO        L_applicationTask7
;Click_Accel6_PIC.c,117 :: 		case 3:
L_applicationTask10:
;Click_Accel6_PIC.c,119 :: 		mikrobus_logWrite(" XY orient : LANDSCAPE RIGHT ", _LOG_LINE);
	MOVLW       ?lstr14_Click_Accel6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr14_Click_Accel6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,120 :: 		break;
	GOTO        L_applicationTask7
;Click_Accel6_PIC.c,122 :: 		case 4:
L_applicationTask11:
;Click_Accel6_PIC.c,124 :: 		mikrobus_logWrite(" XY orient : UPRIGHT ", _LOG_LINE);
	MOVLW       ?lstr15_Click_Accel6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr15_Click_Accel6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,125 :: 		break;
	GOTO        L_applicationTask7
;Click_Accel6_PIC.c,127 :: 		default:
L_applicationTask12:
;Click_Accel6_PIC.c,129 :: 		break;
	GOTO        L_applicationTask7
;Click_Accel6_PIC.c,131 :: 		}
L_applicationTask6:
	MOVF        _xy_orient+0, 0 
	XORLW       1
	BTFSC       STATUS+0, 2 
	GOTO        L_applicationTask8
	MOVF        _xy_orient+0, 0 
	XORLW       2
	BTFSC       STATUS+0, 2 
	GOTO        L_applicationTask9
	MOVF        _xy_orient+0, 0 
	XORLW       3
	BTFSC       STATUS+0, 2 
	GOTO        L_applicationTask10
	MOVF        _xy_orient+0, 0 
	XORLW       4
	BTFSC       STATUS+0, 2 
	GOTO        L_applicationTask11
	GOTO        L_applicationTask12
L_applicationTask7:
;Click_Accel6_PIC.c,133 :: 		tap_detect = accel6_getTapStatus();
	CALL        _accel6_getTapStatus+0, 0
	MOVF        R0, 0 
	MOVWF       _tap_detect+0 
;Click_Accel6_PIC.c,134 :: 		switch( tap_detect )
	GOTO        L_applicationTask13
;Click_Accel6_PIC.c,136 :: 		case 1:
L_applicationTask15:
;Click_Accel6_PIC.c,138 :: 		mikrobus_logWrite(" Tap status : X negative ", _LOG_LINE);
	MOVLW       ?lstr16_Click_Accel6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr16_Click_Accel6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,139 :: 		break;
	GOTO        L_applicationTask14
;Click_Accel6_PIC.c,141 :: 		case 2:
L_applicationTask16:
;Click_Accel6_PIC.c,143 :: 		mikrobus_logWrite(" Tap status : Y negative ", _LOG_LINE);
	MOVLW       ?lstr17_Click_Accel6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr17_Click_Accel6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,144 :: 		break;
	GOTO        L_applicationTask14
;Click_Accel6_PIC.c,146 :: 		case 3:
L_applicationTask17:
;Click_Accel6_PIC.c,148 :: 		mikrobus_logWrite(" Tap status : Z negative ", _LOG_LINE);
	MOVLW       ?lstr18_Click_Accel6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr18_Click_Accel6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,149 :: 		break;
	GOTO        L_applicationTask14
;Click_Accel6_PIC.c,151 :: 		case 4:
L_applicationTask18:
;Click_Accel6_PIC.c,153 :: 		mikrobus_logWrite(" Tap status : X positive ", _LOG_LINE);
	MOVLW       ?lstr19_Click_Accel6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr19_Click_Accel6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,154 :: 		break;
	GOTO        L_applicationTask14
;Click_Accel6_PIC.c,156 :: 		case 5:
L_applicationTask19:
;Click_Accel6_PIC.c,158 :: 		mikrobus_logWrite(" Tap status : Y positive ", _LOG_LINE);
	MOVLW       ?lstr20_Click_Accel6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr20_Click_Accel6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,159 :: 		break;
	GOTO        L_applicationTask14
;Click_Accel6_PIC.c,161 :: 		case 6:
L_applicationTask20:
;Click_Accel6_PIC.c,163 :: 		mikrobus_logWrite(" Tap status : Z positive ", _LOG_LINE);
	MOVLW       ?lstr21_Click_Accel6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr21_Click_Accel6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,164 :: 		break;
	GOTO        L_applicationTask14
;Click_Accel6_PIC.c,166 :: 		default:
L_applicationTask21:
;Click_Accel6_PIC.c,168 :: 		break;
	GOTO        L_applicationTask14
;Click_Accel6_PIC.c,170 :: 		}
L_applicationTask13:
	MOVF        _tap_detect+0, 0 
	XORLW       1
	BTFSC       STATUS+0, 2 
	GOTO        L_applicationTask15
	MOVF        _tap_detect+0, 0 
	XORLW       2
	BTFSC       STATUS+0, 2 
	GOTO        L_applicationTask16
	MOVF        _tap_detect+0, 0 
	XORLW       3
	BTFSC       STATUS+0, 2 
	GOTO        L_applicationTask17
	MOVF        _tap_detect+0, 0 
	XORLW       4
	BTFSC       STATUS+0, 2 
	GOTO        L_applicationTask18
	MOVF        _tap_detect+0, 0 
	XORLW       5
	BTFSC       STATUS+0, 2 
	GOTO        L_applicationTask19
	MOVF        _tap_detect+0, 0 
	XORLW       6
	BTFSC       STATUS+0, 2 
	GOTO        L_applicationTask20
	GOTO        L_applicationTask21
L_applicationTask14:
;Click_Accel6_PIC.c,172 :: 		mikrobus_logWrite("  ", _LOG_LINE);
	MOVLW       ?lstr22_Click_Accel6_PIC+0
	MOVWF       FARG_mikrobus_logWrite_data_+0 
	MOVLW       hi_addr(?lstr22_Click_Accel6_PIC+0)
	MOVWF       FARG_mikrobus_logWrite_data_+1 
	MOVLW       2
	MOVWF       FARG_mikrobus_logWrite_format+0 
	CALL        _mikrobus_logWrite+0, 0
;Click_Accel6_PIC.c,173 :: 		Delay_ms( 500 );
	MOVLW       41
	MOVWF       R11, 0
	MOVLW       150
	MOVWF       R12, 0
	MOVLW       127
	MOVWF       R13, 0
L_applicationTask22:
	DECFSZ      R13, 1, 1
	BRA         L_applicationTask22
	DECFSZ      R12, 1, 1
	BRA         L_applicationTask22
	DECFSZ      R11, 1, 1
	BRA         L_applicationTask22
;Click_Accel6_PIC.c,174 :: 		}
L_end_applicationTask:
	RETURN      0
; end of _applicationTask

_main:

;Click_Accel6_PIC.c,176 :: 		void main()
;Click_Accel6_PIC.c,178 :: 		systemInit();
	CALL        _systemInit+0, 0
;Click_Accel6_PIC.c,179 :: 		applicationInit();
	CALL        _applicationInit+0, 0
;Click_Accel6_PIC.c,181 :: 		while (1)
L_main23:
;Click_Accel6_PIC.c,183 :: 		applicationTask();
	CALL        _applicationTask+0, 0
;Click_Accel6_PIC.c,184 :: 		}
	GOTO        L_main23
;Click_Accel6_PIC.c,185 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
