#line 1 "D:/Clicks_git/Accel_6_Click/SW/example/c/ARM/STM/Click_Accel6_STM.c"
#line 1 "d:/clicks_git/accel_6_click/sw/example/c/arm/stm/click_accel6_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "d:/clicks_git/accel_6_click/sw/example/c/arm/stm/click_accel6_config.h"
#line 1 "d:/clicks_git/accel_6_click/sw/example/c/arm/stm/click_accel6_types.h"
#line 19 "d:/clicks_git/accel_6_click/sw/example/c/arm/stm/click_accel6_config.h"
const uint32_t _ACCEL6_I2C_CFG[ 1 ] =
{
 100000
};
#line 1 "d:/clicks_git/accel_6_click/sw/library/__accel6_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 58 "d:/clicks_git/accel_6_click/sw/library/__accel6_driver.h"
extern const uint8_t _ACCEL6_CHIP_ID;
extern const uint8_t _ACCEL6_SOFT_RESET;


extern const uint8_t _ACCEL6_AXIS_X;
extern const uint8_t _ACCEL6_AXIS_Y;
extern const uint8_t _ACCEL6_AXIS_Z;


extern const uint8_t _ACCEL6_REG_CHIP_ID ;
extern const uint8_t _ACCEL6_REG_AXIS_X_LSB ;
extern const uint8_t _ACCEL6_REG_AXIS_X_MSB ;
extern const uint8_t _ACCEL6_REG_AXIS_Y_LSB ;
extern const uint8_t _ACCEL6_REG_AXIS_Y_MSB ;
extern const uint8_t _ACCEL6_REG_AXIS_Z_LSB ;
extern const uint8_t _ACCEL6_REG_AXIS_Z_MSB ;
extern const uint8_t _ACCEL6_REG_TEMPERATURE ;
extern const uint8_t _ACCEL6_REG_INT_STATUS_0 ;
extern const uint8_t _ACCEL6_REG_INT_STATUS_1 ;
extern const uint8_t _ACCEL6_REG_INT_STATUS_2 ;
extern const uint8_t _ACCEL6_REG_INT_STATUS_3 ;
extern const uint8_t _ACCEL6_REG_FIFO_STATUS ;
extern const uint8_t _ACCEL6_REG_PMU_RANGE ;
extern const uint8_t _ACCEL6_REG_PMU_BW ;
extern const uint8_t _ACCEL6_REG_PMU_LPW ;
extern const uint8_t _ACCEL6_REG_PMU_LOW_POWER ;
extern const uint8_t _ACCEL6_REG_ACCD_HBW ;
extern const uint8_t _ACCEL6_REG_BGW_SOFTRESET ;
extern const uint8_t _ACCEL6_REG_INT_EN_0 ;
extern const uint8_t _ACCEL6_REG_INT_EN_1 ;
extern const uint8_t _ACCEL6_REG_INT_EN_2 ;
extern const uint8_t _ACCEL6_REG_INT_MAP_0 ;
extern const uint8_t _ACCEL6_REG_INT_MAP_1 ;
extern const uint8_t _ACCEL6_REG_INT_MAP_2 ;
extern const uint8_t _ACCEL6_REG_INT_SRC ;
extern const uint8_t _ACCEL6_REG_INT_OUT_CTRL ;
extern const uint8_t _ACCEL6_REG_INT_RST_LATCH ;
extern const uint8_t _ACCEL6_REG_INT1 ;
extern const uint8_t _ACCEL6_REG_INT2 ;
extern const uint8_t _ACCEL6_REG_INT3 ;
extern const uint8_t _ACCEL6_REG_INT4 ;
extern const uint8_t _ACCEL6_REG_INT5 ;
extern const uint8_t _ACCEL6_REG_INT6 ;
extern const uint8_t _ACCEL6_REG_INT7 ;
extern const uint8_t _ACCEL6_REG_INT8 ;
extern const uint8_t _ACCEL6_REG_INT9 ;
extern const uint8_t _ACCEL6_REG_INT_A ;
extern const uint8_t _ACCEL6_REG_INT_B ;
extern const uint8_t _ACCEL6_REG_INT_C ;
extern const uint8_t _ACCEL6_REG_INT_D ;
extern const uint8_t _ACCEL6_REG_FIFO_CONFIG_0 ;
extern const uint8_t _ACCEL6_REG_PMU_SELF_TEST ;
extern const uint8_t _ACCEL6_REG_TRIM_NVM_CTRL ;
extern const uint8_t _ACCEL6_REG_BGW_SPI3_WDT ;
extern const uint8_t _ACCEL6_REG_OFC_CTRL ;
extern const uint8_t _ACCEL6_REG_OFC_SETTINGS ;
extern const uint8_t _ACCEL6_REG_OFC_OFFSET_X ;
extern const uint8_t _ACCEL6_REG_OFC_OFFSET_Y ;
extern const uint8_t _ACCEL6_REG_OFC_OFFSET_Z ;
extern const uint8_t _ACCEL6_REG_TRIM_GP_0 ;
extern const uint8_t _ACCEL6_REG_TRIM_GP_1 ;
extern const uint8_t _ACCEL6_REG_FIFO_CONFIG_1 ;
extern const uint8_t _ACCEL6_REG_FIFO_DATA ;


extern const uint8_t _ACCEL6_STATUS_0_FLOAT_INT ;
extern const uint8_t _ACCEL6_STATUS_0_ORIENT_INT ;
extern const uint8_t _ACCEL6_STATUS_0_SINGLE_TAP_INT ;
extern const uint8_t _ACCEL6_STATUS_0_DOUBLE_TAP_INT ;
extern const uint8_t _ACCEL6_STATUS_0_MOTION_INT ;
extern const uint8_t _ACCEL6_STATUS_0_SLOPE_INT ;
extern const uint8_t _ACCEL6_STATUS_0_HIGH_INT ;
extern const uint8_t _ACCEL6_STATUS_0_LOW_INT ;


extern const uint8_t _ACCEL6_STATUS_1_DATA_INT ;
extern const uint8_t _ACCEL6_STATUS_1_FIFO_WM_INT ;
extern const uint8_t _ACCEL6_STATUS_1_FIFO_FULL_INT ;


extern const uint8_t _ACCEL6_STATUS_2_TAP_SING ;
extern const uint8_t _ACCEL6_STATUS_2_TAP_FIRST_Z ;
extern const uint8_t _ACCEL6_STATUS_2_TAP_FIRST_Y ;
extern const uint8_t _ACCEL6_STATUS_2_TAP_FIRST_X ;
extern const uint8_t _ACCEL6_STATUS_2_SLOPE_SING ;
extern const uint8_t _ACCEL6_STATUS_2_SLOPE_FIRST_Z;
extern const uint8_t _ACCEL6_STATUS_2_SLOPE_FIRST_Y;
extern const uint8_t _ACCEL6_STATUS_2_SLOPE_FIRST_X;


extern const uint8_t _ACCEL6_STATUS_3_FLAT_POSITION ;
extern const uint8_t _ACCEL6_STATUS_3_ORIENT_Z_UPWARD ;
extern const uint8_t _ACCEL6_STATUS_3_ORIENT_Z_DOWNWARD ;
extern const uint8_t _ACCEL6_STATUS_3_ORIENT_XY_UPRIGHT ;
extern const uint8_t _ACCEL6_STATUS_3_ORIENT_XY_UPSIDE ;
extern const uint8_t _ACCEL6_STATUS_3_ORIENT_XY_LANDSCAPE_LEFT ;
extern const uint8_t _ACCEL6_STATUS_3_ORIENT_XY_LANDSCAPE_RIGHT;
extern const uint8_t _ACCEL6_STATUS_3_HIGH_SING_POSITIVE ;
extern const uint8_t _ACCEL6_STATUS_3_HIGH_SING_NEGATIVE ;
extern const uint8_t _ACCEL6_STATUS_3_HIGH_FIRST_Z ;
extern const uint8_t _ACCEL6_STATUS_3_HIGH_FIRST_Y ;
extern const uint8_t _ACCEL6_STATUS_3_HIGH_FIRST_X ;


extern const uint8_t _ACCEL6_PMU_RANGE_2g ;
extern const uint8_t _ACCEL6_PMU_RANGE_4g ;
extern const uint8_t _ACCEL6_PMU_RANGE_8g ;
extern const uint8_t _ACCEL6_PMU_RANGE_16g;


extern const uint8_t _ACCEL6_PMU_BW_7_81Hz ;
extern const uint8_t _ACCEL6_PMU_BW_15_63Hz;
extern const uint8_t _ACCEL6_PMU_BW_31_25Hz;
extern const uint8_t _ACCEL6_PMU_BW_62_5Hz ;
extern const uint8_t _ACCEL6_PMU_BW_125Hz ;
extern const uint8_t _ACCEL6_PMU_BW_250Hz ;
extern const uint8_t _ACCEL6_PMU_BW_500Hz ;


extern const uint8_t _ACCEL6_PMU_LPW_NORMAL_MODE ;
extern const uint8_t _ACCEL6_PMU_LPW_DEEP_SUSPEND_MODE ;
extern const uint8_t _ACCEL6_PMU_LPW_LOW_POWER_MODE ;
extern const uint8_t _ACCEL6_PMU_LPW_SUSPEND_MODE ;
extern const uint8_t _ACCEL6_PMU_LPW_SLEEP_0_5ms ;
extern const uint8_t _ACCEL6_PMU_LPW_SLEEP_1ms ;
extern const uint8_t _ACCEL6_PMU_LPW_SLEEP_2ms ;
extern const uint8_t _ACCEL6_PMU_LPW_SLEEP_4ms ;
extern const uint8_t _ACCEL6_PMU_LPW_SLEEP_6ms ;
extern const uint8_t _ACCEL6_PMU_LPW_SLEEP_10ms ;
extern const uint8_t _ACCEL6_PMU_LPW_SLEEP_25ms ;
extern const uint8_t _ACCEL6_PMU_LPW_SLEEP_50ms ;
extern const uint8_t _ACCEL6_PMU_LPW_SLEEP_100ms ;
extern const uint8_t _ACCEL6_PMU_LPW_SLEEP_500ms ;


extern const uint8_t _ACCEL6_INT_EN_0_FLAT_ENABLE ;
extern const uint8_t _ACCEL6_INT_EN_0_ORIENT_ENABLE ;
extern const uint8_t _ACCEL6_INT_EN_0_SINGLE_TAP_ENABLE;
extern const uint8_t _ACCEL6_INT_EN_0_DOUBLE_TAP_ENABLE;
extern const uint8_t _ACCEL6_INT_EN_0_SLOPE_Z_ENABLE ;
extern const uint8_t _ACCEL6_INT_EN_0_SLOPE_Y_ENABLE ;
extern const uint8_t _ACCEL6_INT_EN_0_SLOPE_X_ENABLE ;


extern const uint8_t _ACCEL6_INT_EN_1_FIFO_WM_ENABLE ;
extern const uint8_t _ACCEL6_INT_EN_1_FIFO_FULL_ENABLE;
extern const uint8_t _ACCEL6_INT_EN_1_DATA_ENABLE ;
extern const uint8_t _ACCEL6_INT_EN_1_LOW_ENABLE ;
extern const uint8_t _ACCEL6_INT_EN_1_HIGH_Z_ENABLE ;
extern const uint8_t _ACCEL6_INT_EN_1_HIGH_Y_ENABLE ;
extern const uint8_t _ACCEL6_INT_EN_1_HIGH_X_ENABLE ;


extern const uint8_t _ACCEL6_INT_EN_2_MOTION_ENABLE ;
extern const uint8_t _ACCEL6_INT_EN_2_MOTION_Z_ENABLE;
extern const uint8_t _ACCEL6_INT_EN_2_MOTION_Y_ENABLE;
extern const uint8_t _ACCEL6_INT_EN_2_MOTION_X_ENABLE;


extern const uint8_t _ACCEL6_INT1_MAP_FLAT_ENABLE ;
extern const uint8_t _ACCEL6_INT1_MAP_ORIENT_ENABLE ;
extern const uint8_t _ACCEL6_INT1_MAP_SINGLE_TAP_ENABLE;
extern const uint8_t _ACCEL6_INT1_MAP_DOUBLE_TAP_ENABLE;
extern const uint8_t _ACCEL6_INT1_MAP_MOTION_ENABLE ;
extern const uint8_t _ACCEL6_INT1_MAP_SLOPE_ENABLE ;
extern const uint8_t _ACCEL6_INT1_MAP_HIGH_ENABLE ;
extern const uint8_t _ACCEL6_INT1_MAP_LOW_ENABLE ;


extern const uint8_t _ACCEL6_INT2_MAP_DATA_ENABLE ;
extern const uint8_t _ACCEL6_INT2_MAP_FIFO_WM_ENABLE ;
extern const uint8_t _ACCEL6_INT2_MAP_FIFO_FULL_ENABLE;
extern const uint8_t _ACCEL6_INT1_MAP_DATA_ENABLE ;
extern const uint8_t _ACCEL6_INT1_MAP_FIFO_WM_ENABLE ;
extern const uint8_t _ACCEL6_INT1_MAP_FIFO_FULL_ENABLE;


extern const uint8_t _ACCEL6_INT2_MAP_FLAT_ENABLE ;
extern const uint8_t _ACCEL6_INT2_MAP_ORIENT_ENABLE ;
extern const uint8_t _ACCEL6_INT2_MAP_SINGLE_TAP_ENABLE;
extern const uint8_t _ACCEL6_INT2_MAP_DOUBLE_TAP_ENABLE;
extern const uint8_t _ACCEL6_INT2_MAP_MOTION_ENABLE ;
extern const uint8_t _ACCEL6_INT2_MAP_SLOPE_ENABLE ;
extern const uint8_t _ACCEL6_INT2_MAP_HIGH_ENABLE ;
extern const uint8_t _ACCEL6_INT2_MAP_LOW_ENABLE ;


extern const uint8_t _ACCEL6_INT_SRC_DATA ;
extern const uint8_t _ACCEL6_INT_SRC_TAP ;
extern const uint8_t _ACCEL6_INT_SRC_MOTION;
extern const uint8_t _ACCEL6_INT_SRC_SLOPE ;
extern const uint8_t _ACCEL6_INT_SRC_HIGH ;
extern const uint8_t _ACCEL6_INT_SRC_LOW ;


extern const uint8_t _ACCEL6_INT2_CTRL_OPEN_DRAIN;
extern const uint8_t _ACCEL6_INT1_CTRL_OPEN_DRAIN;
extern const uint8_t _ACCEL6_INT2_CTRL_ACTIVE_HIGH_LEVEL;
extern const uint8_t _ACCEL6_INT1_CTRL_ACTIVE_HIGH_LEVEL;


extern const uint8_t _ACCEL6_LATCH_RESET_INT ;
extern const uint8_t _ACCEL6_LATCH_INT_250ms ;
extern const uint8_t _ACCEL6_LATCH_INT_500ms ;
extern const uint8_t _ACCEL6_LATCH_INT_1sec ;
extern const uint8_t _ACCEL6_LATCH_INT_2sec ;
extern const uint8_t _ACCEL6_LATCH_INT_4sec ;
extern const uint8_t _ACCEL6_LATCH_INT_8sec ;
extern const uint8_t _ACCEL6_LATCH_INT_250us ;
extern const uint8_t _ACCEL6_LATCH_INT_500us ;
extern const uint8_t _ACCEL6_LATCH_INT_1ms ;
extern const uint8_t _ACCEL6_LATCH_INT_12_5ms;
extern const uint8_t _ACCEL6_LATCH_INT_25ms ;
extern const uint8_t _ACCEL6_LATCH_INT_50ms ;


extern const uint8_t _ACCEL6_TAP_QUIET_30ms;
extern const uint8_t _ACCEL6_TAP_QUIET_20ms;
extern const uint8_t _ACCEL6_TAP_SHOCK_50ms;
extern const uint8_t _ACCEL6_TAP_SHOCK_75ms;
extern const uint8_t _ACCEL6_TAP_DUR_50ms ;
extern const uint8_t _ACCEL6_TAP_DUR_100ms ;
extern const uint8_t _ACCEL6_TAP_DUR_150ms ;
extern const uint8_t _ACCEL6_TAP_DUR_200ms ;
extern const uint8_t _ACCEL6_TAP_DUR_250ms ;
extern const uint8_t _ACCEL6_TAP_DUR_375ms ;
extern const uint8_t _ACCEL6_TAP_DUR_500ms ;
extern const uint8_t _ACCEL6_TAP_DUR_700ms ;


extern const uint8_t _ACCEL6_TAP_2_SAMPLES ;
extern const uint8_t _ACCEL6_TAP_4_SAMPLES ;
extern const uint8_t _ACCEL6_TAP_8_SAMPLES ;
extern const uint8_t _ACCEL6_TAP_16_SAMPLES;


extern const uint8_t _ACCEL6_SELF_TEST_SING_POSITIVE;
extern const uint8_t _ACCEL6_SELF_TEST_SING_NEGATIVE;
extern const uint8_t _ACCEL6_SELF_TEST_DISABLE ;
extern const uint8_t _ACCEL6_SELF_TEST_X_AXIS ;
extern const uint8_t _ACCEL6_SELF_TEST_Y_AXIS ;
extern const uint8_t _ACCEL6_SELF_TEST_Z_AXIS ;


extern const uint8_t _ACCEL6_I2C_ENABLE ;
extern const uint8_t _ACCEL6_I2C_DISABLE ;
extern const uint8_t _ACCEL6_I2C_WTD_1ms ;
extern const uint8_t _ACCEL6_I2C_WTD_50ms;
extern const uint8_t _ACCEL6_SPI_4_WIRE ;
extern const uint8_t _ACCEL6_SPI_3_WIRE ;


extern const uint8_t _ACCEL6_OFFSET_RESET ;
extern const uint8_t _ACCEL6_OFFSET_TRIGGER_X_AXIS;
extern const uint8_t _ACCEL6_OFFSET_TRIGGER_Y_AXIS;
extern const uint8_t _ACCEL6_OFFSET_TRIGGER_Z_AXIS;
extern const uint8_t _ACCEL6_OFFSET_NOT_TRIGGER ;
extern const uint8_t _ACCEL6_OFC_HP_X_ENABLE ;
extern const uint8_t _ACCEL6_OFC_HP_y_ENABLE ;
extern const uint8_t _ACCEL6_OFC_HP_z_ENABLE ;



extern const uint8_t _ACCEL6_OFFSET_TARGET_Z_0g;
extern const uint8_t _ACCEL6_OFFSET_TARGET_Z_PLUS_1g ;
extern const uint8_t _ACCEL6_OFFSET_TARGET_Z_MINUS_1g ;
extern const uint8_t _ACCEL6_OFFSET_TARGET_Y_PLUS_1g ;
extern const uint8_t _ACCEL6_OFFSET_TARGET_Y_MINUS_1g ;
extern const uint8_t _ACCEL6_OFFSET_TARGET_X_PLUS_1g ;
extern const uint8_t _ACCEL6_OFFSET_TARGET_X_MINUS_1g ;
extern const uint8_t _ACCEL6_OFFSET_CUT_OFF_1Hz ;
extern const uint8_t _ACCEL6_OFFSET_CUT_OFF_10Hz ;


extern const uint8_t _ACCEL6_FIFO_MODE_BYPASS ;
extern const uint8_t _ACCEL6_FIFO_MODE_FIFO ;
extern const uint8_t _ACCEL6_FIFO_MODE_STREAM ;
extern const uint8_t _ACCEL6_FIFO_SELECT_XYZ_AXIS;
extern const uint8_t _ACCEL6_FIFO_SELECT_X_AXIS ;
extern const uint8_t _ACCEL6_FIFO_SELECT_Y_AXIS ;
extern const uint8_t _ACCEL6_FIFO_SELECT_Z_AXIS ;
#line 350 "d:/clicks_git/accel_6_click/sw/library/__accel6_driver.h"
void accel6_i2cDriverInit( const uint8_t*  gpioObj,  const uint8_t*  i2cObj, uint8_t slave);
#line 357 "d:/clicks_git/accel_6_click/sw/library/__accel6_driver.h"
void accel6_gpioDriverInit( const uint8_t*  gpioObj);
#line 367 "d:/clicks_git/accel_6_click/sw/library/__accel6_driver.h"
void accel6_writeByte(uint8_t reg, uint8_t _data);
#line 375 "d:/clicks_git/accel_6_click/sw/library/__accel6_driver.h"
uint8_t accel6_readByte(uint8_t reg);
#line 383 "d:/clicks_git/accel_6_click/sw/library/__accel6_driver.h"
int16_t accel6_readData(uint8_t reg);
#line 399 "d:/clicks_git/accel_6_click/sw/library/__accel6_driver.h"
uint8_t accel6_init(uint8_t range_data, uint8_t bw_data, uint8_t lpw_data);
#line 407 "d:/clicks_git/accel_6_click/sw/library/__accel6_driver.h"
float accel6_getAxis(uint8_t axis);
#line 424 "d:/clicks_git/accel_6_click/sw/library/__accel6_driver.h"
void accel6_getOrient(uint8_t *z_orient, uint8_t *xy_orient);
#line 439 "d:/clicks_git/accel_6_click/sw/library/__accel6_driver.h"
uint8_t accel6_getTapStatus();
#line 454 "d:/clicks_git/accel_6_click/sw/library/__accel6_driver.h"
uint8_t accel6_getSlopeStatus();
#line 465 "d:/clicks_git/accel_6_click/sw/library/__accel6_driver.h"
void accel6_dataOffset(uint8_t setOffset, float *offsetData);
#line 478 "d:/clicks_git/accel_6_click/sw/library/__accel6_driver.h"
float accel6_getTemperature();
#line 483 "d:/clicks_git/accel_6_click/sw/library/__accel6_driver.h"
void accel6_softReset();
#line 34 "D:/Clicks_git/Accel_6_Click/SW/example/c/ARM/STM/Click_Accel6_STM.c"
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
 mikrobus_logInit( _LOG_USBUART_A, 9600 );
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
