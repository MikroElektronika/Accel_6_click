#line 1 "D:/Clicks_git/Accel_6_Click/SW/example/c/PIC/Click_Accel6_PIC.c"
#line 1 "d:/clicks_git/accel_6_click/sw/example/c/pic/click_accel6_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdint.h"




typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;



typedef signed char int_fast8_t;
typedef signed int int_fast16_t;
typedef signed long int int_fast32_t;


typedef unsigned char uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned long int uint_fast32_t;


typedef signed int intptr_t;
typedef unsigned int uintptr_t;


typedef signed long int intmax_t;
typedef unsigned long int uintmax_t;
#line 1 "d:/clicks_git/accel_6_click/sw/example/c/pic/click_accel6_config.h"
#line 1 "d:/clicks_git/accel_6_click/sw/example/c/pic/click_accel6_types.h"
#line 3 "d:/clicks_git/accel_6_click/sw/example/c/pic/click_accel6_config.h"
const uint32_t _ACCEL6_I2C_CFG[ 1 ] =
{
 100000
};
#line 32 "D:/Clicks_git/Accel_6_Click/SW/example/c/PIC/Click_Accel6_PIC.c"
uint8_t tap_detect;
uint8_t orient;
uint8_t z_orient[1] = {0};
uint8_t xy_orient[1] ={0};
float fAxis = 0.0;
float Temp = 0.0;
char demoText[50] = {0};

void systemInit()
{
 mikrobus_i2cInit( _MIKROBUS1, &_ACCEL6_I2C_CFG[0] );
 mikrobus_logInit( _LOG_USBUART, 9600 );
 mikrobus_logWrite(" --- System init --- ", _LOG_LINE);
 Delay_ms( 100 );
}

void applicationInit()
{
 accel6_i2cDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_I2C, 0x18 );

 accel6_softReset();
 accel6_init(_ACCEL6_PMU_RANGE_4g, _ACCEL6_PMU_BW_125Hz, _ACCEL6_PMU_LPW_NORMAL_MODE | _ACCEL6_PMU_LPW_SLEEP_10ms);
 Delay_100ms();
}

void applicationTask()
{
 mikrobus_logWrite(" X axis :  ", _LOG_TEXT);
 fAxis = accel6_getAxis(_ACCEL6_AXIS_X);
 FloatToStr(fAxis, demoText);
 mikrobus_logWrite(demoText, _LOG_TEXT);
 mikrobus_logWrite(" mg ", _LOG_LINE);

 mikrobus_logWrite(" Y axis :  ", _LOG_TEXT);
 fAxis = accel6_getAxis(_ACCEL6_AXIS_Y);
 FloatToStr(fAxis, demoText);
 mikrobus_logWrite(demoText, _LOG_TEXT);
 mikrobus_logWrite(" mg ", _LOG_LINE);

 mikrobus_logWrite(" Z axis :  ", _LOG_TEXT);
 fAxis = accel6_getAxis(_ACCEL6_AXIS_Y);
 FloatToStr(fAxis, demoText);
 mikrobus_logWrite(demoText, _LOG_TEXT);
 mikrobus_logWrite(" mg ", _LOG_LINE);

 mikrobus_logWrite(" Temperature :  ", _LOG_TEXT);
 Temp = accel6_getTemperature();
 FloatToStr(Temp, demoText);
 mikrobus_logWrite(demoText, _LOG_TEXT);
 mikrobus_logWrite(" C ", _LOG_LINE);

 accel6_getOrient(&z_orient[0], &xy_orient[0]);

 switch(z_orient[0])
 {
 case 1:
 {
 mikrobus_logWrite(" Z orient : UPWARD looking ", _LOG_LINE);
 break;
 }
 case 2:
 {
 mikrobus_logWrite(" Z orient : DOWNWARD looking ", _LOG_LINE);
 break;
 }
 default:
 {
 break;
 }
 }

 switch(xy_orient[0])
 {
 case 1:
 {
 mikrobus_logWrite(" XY orient : UPSIDE DOWN ", _LOG_LINE);
 break;
 }
 case 2:
 {
 mikrobus_logWrite(" XY orient : LANDSCAPE LEFT ", _LOG_LINE);
 break;
 }
 case 3:
 {
 mikrobus_logWrite(" XY orient : LANDSCAPE RIGHT ", _LOG_LINE);
 break;
 }
 case 4:
 {
 mikrobus_logWrite(" XY orient : UPRIGHT ", _LOG_LINE);
 break;
 }
 default:
 {
 break;
 }
 }

 tap_detect = accel6_getTapStatus();
 switch( tap_detect )
 {
 case 1:
 {
 mikrobus_logWrite(" Tap status : X negative ", _LOG_LINE);
 break;
 }
 case 2:
 {
 mikrobus_logWrite(" Tap status : Y negative ", _LOG_LINE);
 break;
 }
 case 3:
 {
 mikrobus_logWrite(" Tap status : Z negative ", _LOG_LINE);
 break;
 }
 case 4:
 {
 mikrobus_logWrite(" Tap status : X positive ", _LOG_LINE);
 break;
 }
 case 5:
 {
 mikrobus_logWrite(" Tap status : Y positive ", _LOG_LINE);
 break;
 }
 case 6:
 {
 mikrobus_logWrite(" Tap status : Z positive ", _LOG_LINE);
 break;
 }
 default:
 {
 break;
 }
 }

 mikrobus_logWrite("  ", _LOG_LINE);
 Delay_ms( 500 );
}


void main()
{
 systemInit();
 applicationInit();

 while (1)
 {
 applicationTask();
 }
}
