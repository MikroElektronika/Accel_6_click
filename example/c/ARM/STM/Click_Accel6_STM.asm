_systemInit:
;Click_Accel6_STM.c,42 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Accel6_STM.c,44 :: 		mikrobus_i2cInit( _MIKROBUS1, &_ACCEL6_I2C_CFG[0] );
MOVW	R0, #lo_addr(__ACCEL6_I2C_CFG+0)
MOVT	R0, #hi_addr(__ACCEL6_I2C_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_i2cInit+0
;Click_Accel6_STM.c,45 :: 		mikrobus_logInit( _LOG_USBUART_A, 9600 );
MOVW	R1, #9600
MOVS	R0, #32
BL	_mikrobus_logInit+0
;Click_Accel6_STM.c,46 :: 		mikrobus_logWrite(" --- System init --- ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr1_Click_Accel6_STM+0)
MOVT	R0, #hi_addr(?lstr1_Click_Accel6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,47 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_Accel6_STM.c,48 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_Accel6_STM.c,50 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Accel6_STM.c,52 :: 		accel6_i2cDriverInit( (T_ACCEL6_P)&_MIKROBUS1_GPIO, (T_ACCEL6_P)&_MIKROBUS1_I2C, 0x18 );
MOVS	R2, #24
MOVW	R1, #lo_addr(__MIKROBUS1_I2C+0)
MOVT	R1, #hi_addr(__MIKROBUS1_I2C+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_accel6_i2cDriverInit+0
;Click_Accel6_STM.c,54 :: 		accel6_softReset();
BL	_accel6_softReset+0
;Click_Accel6_STM.c,55 :: 		accel6_init(_ACCEL6_PMU_RANGE_4g, _ACCEL6_PMU_BW_125Hz, _ACCEL6_PMU_LPW_NORMAL_MODE | _ACCEL6_PMU_LPW_SLEEP_10ms);
MOVS	R0, __ACCEL6_PMU_LPW_NORMAL_MODE
ORR	R0, R0, __ACCEL6_PMU_LPW_SLEEP_10ms
UXTB	R2, R0
MOVS	R1, __ACCEL6_PMU_BW_125Hz
MOVS	R0, __ACCEL6_PMU_RANGE_4g
BL	_accel6_init+0
;Click_Accel6_STM.c,56 :: 		Delay_100ms();
BL	_Delay_100ms+0
;Click_Accel6_STM.c,57 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_Accel6_STM.c,59 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Accel6_STM.c,61 :: 		mikrobus_logWrite(" X axis :  ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr2_Click_Accel6_STM+0)
MOVT	R0, #hi_addr(?lstr2_Click_Accel6_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,62 :: 		fAxis = accel6_getAxis(_ACCEL6_AXIS_X);
MOVS	R0, __ACCEL6_AXIS_X
BL	_accel6_getAxis+0
MOVW	R1, #lo_addr(_fAxis+0)
MOVT	R1, #hi_addr(_fAxis+0)
STR	R0, [R1, #0]
;Click_Accel6_STM.c,63 :: 		FloatToStr(fAxis, demoText);
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_FloatToStr+0
;Click_Accel6_STM.c,64 :: 		mikrobus_logWrite(demoText, _LOG_TEXT);
MOVS	R1, #1
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,65 :: 		mikrobus_logWrite(" mg ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr3_Click_Accel6_STM+0)
MOVT	R0, #hi_addr(?lstr3_Click_Accel6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,67 :: 		mikrobus_logWrite(" Y axis :  ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr4_Click_Accel6_STM+0)
MOVT	R0, #hi_addr(?lstr4_Click_Accel6_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,68 :: 		fAxis = accel6_getAxis(_ACCEL6_AXIS_Y);
MOVS	R0, __ACCEL6_AXIS_Y
BL	_accel6_getAxis+0
MOVW	R1, #lo_addr(_fAxis+0)
MOVT	R1, #hi_addr(_fAxis+0)
STR	R0, [R1, #0]
;Click_Accel6_STM.c,69 :: 		FloatToStr(fAxis, demoText);
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_FloatToStr+0
;Click_Accel6_STM.c,70 :: 		mikrobus_logWrite(demoText, _LOG_TEXT);
MOVS	R1, #1
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,71 :: 		mikrobus_logWrite(" mg ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr5_Click_Accel6_STM+0)
MOVT	R0, #hi_addr(?lstr5_Click_Accel6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,73 :: 		mikrobus_logWrite(" Z axis :  ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr6_Click_Accel6_STM+0)
MOVT	R0, #hi_addr(?lstr6_Click_Accel6_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,74 :: 		fAxis = accel6_getAxis(_ACCEL6_AXIS_Y);
MOVS	R0, __ACCEL6_AXIS_Y
BL	_accel6_getAxis+0
MOVW	R1, #lo_addr(_fAxis+0)
MOVT	R1, #hi_addr(_fAxis+0)
STR	R0, [R1, #0]
;Click_Accel6_STM.c,75 :: 		FloatToStr(fAxis, demoText);
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_FloatToStr+0
;Click_Accel6_STM.c,76 :: 		mikrobus_logWrite(demoText, _LOG_TEXT);
MOVS	R1, #1
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,77 :: 		mikrobus_logWrite(" mg ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr7_Click_Accel6_STM+0)
MOVT	R0, #hi_addr(?lstr7_Click_Accel6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,79 :: 		mikrobus_logWrite(" Temperature :  ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr8_Click_Accel6_STM+0)
MOVT	R0, #hi_addr(?lstr8_Click_Accel6_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,80 :: 		Temp = accel6_getTemperature();
BL	_accel6_getTemperature+0
MOVW	R1, #lo_addr(_Temp+0)
MOVT	R1, #hi_addr(_Temp+0)
STR	R0, [R1, #0]
;Click_Accel6_STM.c,81 :: 		FloatToStr(Temp, demoText);
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_FloatToStr+0
;Click_Accel6_STM.c,82 :: 		mikrobus_logWrite(demoText, _LOG_TEXT);
MOVS	R1, #1
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,83 :: 		mikrobus_logWrite(" C ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr9_Click_Accel6_STM+0)
MOVT	R0, #hi_addr(?lstr9_Click_Accel6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,85 :: 		accel6_getOrient(&z_orient[0], &xy_orient[0]);
MOVW	R1, #lo_addr(_xy_orient+0)
MOVT	R1, #hi_addr(_xy_orient+0)
MOVW	R0, #lo_addr(_z_orient+0)
MOVT	R0, #hi_addr(_z_orient+0)
BL	_accel6_getOrient+0
;Click_Accel6_STM.c,87 :: 		switch(z_orient[0])
IT	AL
BAL	L_applicationTask2
;Click_Accel6_STM.c,89 :: 		case 1:
L_applicationTask4:
;Click_Accel6_STM.c,91 :: 		mikrobus_logWrite(" Z orient : UPWARD looking ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr10_Click_Accel6_STM+0)
MOVT	R0, #hi_addr(?lstr10_Click_Accel6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,92 :: 		break;
IT	AL
BAL	L_applicationTask3
;Click_Accel6_STM.c,94 :: 		case 2:
L_applicationTask5:
;Click_Accel6_STM.c,96 :: 		mikrobus_logWrite(" Z orient : DOWNWARD looking ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr11_Click_Accel6_STM+0)
MOVT	R0, #hi_addr(?lstr11_Click_Accel6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,97 :: 		break;
IT	AL
BAL	L_applicationTask3
;Click_Accel6_STM.c,99 :: 		default:
L_applicationTask6:
;Click_Accel6_STM.c,101 :: 		break;
IT	AL
BAL	L_applicationTask3
;Click_Accel6_STM.c,103 :: 		}
L_applicationTask2:
MOVW	R0, #lo_addr(_z_orient+0)
MOVT	R0, #hi_addr(_z_orient+0)
LDRB	R0, [R0, #0]
CMP	R0, #1
IT	EQ
BEQ	L_applicationTask4
MOVW	R0, #lo_addr(_z_orient+0)
MOVT	R0, #hi_addr(_z_orient+0)
LDRB	R0, [R0, #0]
CMP	R0, #2
IT	EQ
BEQ	L_applicationTask5
IT	AL
BAL	L_applicationTask6
L_applicationTask3:
;Click_Accel6_STM.c,105 :: 		switch(xy_orient[0])
IT	AL
BAL	L_applicationTask7
;Click_Accel6_STM.c,107 :: 		case 1:
L_applicationTask9:
;Click_Accel6_STM.c,109 :: 		mikrobus_logWrite(" XY orient : UPSIDE DOWN ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr12_Click_Accel6_STM+0)
MOVT	R0, #hi_addr(?lstr12_Click_Accel6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,110 :: 		break;
IT	AL
BAL	L_applicationTask8
;Click_Accel6_STM.c,112 :: 		case 2:
L_applicationTask10:
;Click_Accel6_STM.c,114 :: 		mikrobus_logWrite(" XY orient : LANDSCAPE LEFT ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr13_Click_Accel6_STM+0)
MOVT	R0, #hi_addr(?lstr13_Click_Accel6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,115 :: 		break;
IT	AL
BAL	L_applicationTask8
;Click_Accel6_STM.c,117 :: 		case 3:
L_applicationTask11:
;Click_Accel6_STM.c,119 :: 		mikrobus_logWrite(" XY orient : LANDSCAPE RIGHT ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr14_Click_Accel6_STM+0)
MOVT	R0, #hi_addr(?lstr14_Click_Accel6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,120 :: 		break;
IT	AL
BAL	L_applicationTask8
;Click_Accel6_STM.c,122 :: 		case 4:
L_applicationTask12:
;Click_Accel6_STM.c,124 :: 		mikrobus_logWrite(" XY orient : UPRIGHT ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr15_Click_Accel6_STM+0)
MOVT	R0, #hi_addr(?lstr15_Click_Accel6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,125 :: 		break;
IT	AL
BAL	L_applicationTask8
;Click_Accel6_STM.c,127 :: 		default:
L_applicationTask13:
;Click_Accel6_STM.c,129 :: 		break;
IT	AL
BAL	L_applicationTask8
;Click_Accel6_STM.c,131 :: 		}
L_applicationTask7:
MOVW	R0, #lo_addr(_xy_orient+0)
MOVT	R0, #hi_addr(_xy_orient+0)
LDRB	R0, [R0, #0]
CMP	R0, #1
IT	EQ
BEQ	L_applicationTask9
MOVW	R0, #lo_addr(_xy_orient+0)
MOVT	R0, #hi_addr(_xy_orient+0)
LDRB	R0, [R0, #0]
CMP	R0, #2
IT	EQ
BEQ	L_applicationTask10
MOVW	R0, #lo_addr(_xy_orient+0)
MOVT	R0, #hi_addr(_xy_orient+0)
LDRB	R0, [R0, #0]
CMP	R0, #3
IT	EQ
BEQ	L_applicationTask11
MOVW	R0, #lo_addr(_xy_orient+0)
MOVT	R0, #hi_addr(_xy_orient+0)
LDRB	R0, [R0, #0]
CMP	R0, #4
IT	EQ
BEQ	L_applicationTask12
IT	AL
BAL	L_applicationTask13
L_applicationTask8:
;Click_Accel6_STM.c,133 :: 		tap_detect = accel6_getTapStatus();
BL	_accel6_getTapStatus+0
MOVW	R1, #lo_addr(_tap_detect+0)
MOVT	R1, #hi_addr(_tap_detect+0)
STRB	R0, [R1, #0]
;Click_Accel6_STM.c,134 :: 		switch( tap_detect )
IT	AL
BAL	L_applicationTask14
;Click_Accel6_STM.c,136 :: 		case 1:
L_applicationTask16:
;Click_Accel6_STM.c,138 :: 		mikrobus_logWrite(" Tap status : X negative ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr16_Click_Accel6_STM+0)
MOVT	R0, #hi_addr(?lstr16_Click_Accel6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,139 :: 		break;
IT	AL
BAL	L_applicationTask15
;Click_Accel6_STM.c,141 :: 		case 2:
L_applicationTask17:
;Click_Accel6_STM.c,143 :: 		mikrobus_logWrite(" Tap status : Y negative ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr17_Click_Accel6_STM+0)
MOVT	R0, #hi_addr(?lstr17_Click_Accel6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,144 :: 		break;
IT	AL
BAL	L_applicationTask15
;Click_Accel6_STM.c,146 :: 		case 3:
L_applicationTask18:
;Click_Accel6_STM.c,148 :: 		mikrobus_logWrite(" Tap status : Z negative ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr18_Click_Accel6_STM+0)
MOVT	R0, #hi_addr(?lstr18_Click_Accel6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,149 :: 		break;
IT	AL
BAL	L_applicationTask15
;Click_Accel6_STM.c,151 :: 		case 4:
L_applicationTask19:
;Click_Accel6_STM.c,153 :: 		mikrobus_logWrite(" Tap status : X positive ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr19_Click_Accel6_STM+0)
MOVT	R0, #hi_addr(?lstr19_Click_Accel6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,154 :: 		break;
IT	AL
BAL	L_applicationTask15
;Click_Accel6_STM.c,156 :: 		case 5:
L_applicationTask20:
;Click_Accel6_STM.c,158 :: 		mikrobus_logWrite(" Tap status : Y positive ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr20_Click_Accel6_STM+0)
MOVT	R0, #hi_addr(?lstr20_Click_Accel6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,159 :: 		break;
IT	AL
BAL	L_applicationTask15
;Click_Accel6_STM.c,161 :: 		case 6:
L_applicationTask21:
;Click_Accel6_STM.c,163 :: 		mikrobus_logWrite(" Tap status : Z positive ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr21_Click_Accel6_STM+0)
MOVT	R0, #hi_addr(?lstr21_Click_Accel6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,164 :: 		break;
IT	AL
BAL	L_applicationTask15
;Click_Accel6_STM.c,166 :: 		default:
L_applicationTask22:
;Click_Accel6_STM.c,168 :: 		break;
IT	AL
BAL	L_applicationTask15
;Click_Accel6_STM.c,170 :: 		}
L_applicationTask14:
MOVW	R0, #lo_addr(_tap_detect+0)
MOVT	R0, #hi_addr(_tap_detect+0)
LDRB	R0, [R0, #0]
CMP	R0, #1
IT	EQ
BEQ	L_applicationTask16
MOVW	R0, #lo_addr(_tap_detect+0)
MOVT	R0, #hi_addr(_tap_detect+0)
LDRB	R0, [R0, #0]
CMP	R0, #2
IT	EQ
BEQ	L_applicationTask17
MOVW	R0, #lo_addr(_tap_detect+0)
MOVT	R0, #hi_addr(_tap_detect+0)
LDRB	R0, [R0, #0]
CMP	R0, #3
IT	EQ
BEQ	L_applicationTask18
MOVW	R0, #lo_addr(_tap_detect+0)
MOVT	R0, #hi_addr(_tap_detect+0)
LDRB	R0, [R0, #0]
CMP	R0, #4
IT	EQ
BEQ	L_applicationTask19
MOVW	R0, #lo_addr(_tap_detect+0)
MOVT	R0, #hi_addr(_tap_detect+0)
LDRB	R0, [R0, #0]
CMP	R0, #5
IT	EQ
BEQ	L_applicationTask20
MOVW	R0, #lo_addr(_tap_detect+0)
MOVT	R0, #hi_addr(_tap_detect+0)
LDRB	R0, [R0, #0]
CMP	R0, #6
IT	EQ
BEQ	L_applicationTask21
IT	AL
BAL	L_applicationTask22
L_applicationTask15:
;Click_Accel6_STM.c,172 :: 		mikrobus_logWrite("  ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr22_Click_Accel6_STM+0)
MOVT	R0, #hi_addr(?lstr22_Click_Accel6_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Accel6_STM.c,173 :: 		Delay_ms( 500 );
MOVW	R7, #36223
MOVT	R7, #91
NOP
NOP
L_applicationTask23:
SUBS	R7, R7, #1
BNE	L_applicationTask23
NOP
NOP
NOP
;Click_Accel6_STM.c,174 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_Accel6_STM.c,176 :: 		void main()
;Click_Accel6_STM.c,178 :: 		systemInit();
BL	_systemInit+0
;Click_Accel6_STM.c,179 :: 		applicationInit();
BL	_applicationInit+0
;Click_Accel6_STM.c,181 :: 		while (1)
L_main25:
;Click_Accel6_STM.c,183 :: 		applicationTask();
BL	_applicationTask+0
;Click_Accel6_STM.c,184 :: 		}
IT	AL
BAL	L_main25
;Click_Accel6_STM.c,185 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
