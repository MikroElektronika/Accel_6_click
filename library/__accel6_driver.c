/*
    __accel6_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__accel6_driver.h"
#include "__accel6_hal.c"

/* ------------------------------------------------------------------- MACROS */

/* Mask */
const uint8_t _ACCEL6_CHIP_ID = 0xFB;
const uint8_t _ACCEL6_SOFT_RESET = 0xB6;

/* Axis */
const uint8_t _ACCEL6_AXIS_X = 0x02;
const uint8_t _ACCEL6_AXIS_Y = 0x04;
const uint8_t _ACCEL6_AXIS_Z = 0x06;

/* Register */
const uint8_t _ACCEL6_REG_CHIP_ID       = 0x00;
const uint8_t _ACCEL6_REG_AXIS_X_LSB    = 0x02;
const uint8_t _ACCEL6_REG_AXIS_X_MSB    = 0x03;
const uint8_t _ACCEL6_REG_AXIS_Y_LSB    = 0x04;
const uint8_t _ACCEL6_REG_AXIS_Y_MSB    = 0x05;
const uint8_t _ACCEL6_REG_AXIS_Z_LSB    = 0x06;
const uint8_t _ACCEL6_REG_AXIS_Z_MSB    = 0x07;
const uint8_t _ACCEL6_REG_TEMPERATURE   = 0x08;
const uint8_t _ACCEL6_REG_INT_STATUS_0  = 0x09;
const uint8_t _ACCEL6_REG_INT_STATUS_1  = 0x0A;
const uint8_t _ACCEL6_REG_INT_STATUS_2  = 0x0B;
const uint8_t _ACCEL6_REG_INT_STATUS_3  = 0x0C;
const uint8_t _ACCEL6_REG_FIFO_STATUS   = 0x0E;
const uint8_t _ACCEL6_REG_PMU_RANGE     = 0x0F;
const uint8_t _ACCEL6_REG_PMU_BW        = 0x10;
const uint8_t _ACCEL6_REG_PMU_LPW       = 0x11;
const uint8_t _ACCEL6_REG_PMU_LOW_POWER = 0x12;
const uint8_t _ACCEL6_REG_ACCD_HBW      = 0x13;
const uint8_t _ACCEL6_REG_BGW_SOFTRESET = 0x14;
const uint8_t _ACCEL6_REG_INT_EN_0      = 0x16;
const uint8_t _ACCEL6_REG_INT_EN_1      = 0x17;
const uint8_t _ACCEL6_REG_INT_EN_2      = 0x18;
const uint8_t _ACCEL6_REG_INT_MAP_0     = 0x19;
const uint8_t _ACCEL6_REG_INT_MAP_1     = 0x1A;
const uint8_t _ACCEL6_REG_INT_MAP_2     = 0x1B;
const uint8_t _ACCEL6_REG_INT_SRC       = 0x1E;
const uint8_t _ACCEL6_REG_INT_OUT_CTRL  = 0x20;
const uint8_t _ACCEL6_REG_INT_RST_LATCH = 0x21;
const uint8_t _ACCEL6_REG_INT1          = 0x23;
const uint8_t _ACCEL6_REG_INT2          = 0x24;
const uint8_t _ACCEL6_REG_INT3          = 0x25;
const uint8_t _ACCEL6_REG_INT4          = 0x26;
const uint8_t _ACCEL6_REG_INT5          = 0x27;
const uint8_t _ACCEL6_REG_INT6          = 0x28;
const uint8_t _ACCEL6_REG_INT7          = 0x29;
const uint8_t _ACCEL6_REG_INT8          = 0x2A;
const uint8_t _ACCEL6_REG_INT9          = 0x2B;
const uint8_t _ACCEL6_REG_INT_A         = 0x2C;
const uint8_t _ACCEL6_REG_INT_B         = 0x2D;
const uint8_t _ACCEL6_REG_INT_C         = 0x2E;
const uint8_t _ACCEL6_REG_INT_D         = 0x2F;
const uint8_t _ACCEL6_REG_FIFO_CONFIG_0 = 0x30;
const uint8_t _ACCEL6_REG_PMU_SELF_TEST = 0x32;
const uint8_t _ACCEL6_REG_TRIM_NVM_CTRL = 0x33;
const uint8_t _ACCEL6_REG_BGW_SPI3_WDT  = 0x34;
const uint8_t _ACCEL6_REG_OFC_CTRL      = 0x36;
const uint8_t _ACCEL6_REG_OFC_SETTINGS  = 0x37;
const uint8_t _ACCEL6_REG_OFC_OFFSET_X  = 0x38;
const uint8_t _ACCEL6_REG_OFC_OFFSET_Y  = 0x39;
const uint8_t _ACCEL6_REG_OFC_OFFSET_Z  = 0x3A;
const uint8_t _ACCEL6_REG_TRIM_GP_0     = 0x3B;
const uint8_t _ACCEL6_REG_TRIM_GP_1     = 0x3C;
const uint8_t _ACCEL6_REG_FIFO_CONFIG_1 = 0x3E;
const uint8_t _ACCEL6_REG_FIFO_DATA     = 0x3F;

/* Interrupt status register 0 */
const uint8_t _ACCEL6_STATUS_0_FLAT_INT       = 0x80;
const uint8_t _ACCEL6_STATUS_0_ORIENT_INT     = 0x40;
const uint8_t _ACCEL6_STATUS_0_SINGLE_TAP_INT = 0x20;
const uint8_t _ACCEL6_STATUS_0_DOUBLE_TAP_INT = 0x10;
const uint8_t _ACCEL6_STATUS_0_MOTION_INT     = 0x08;
const uint8_t _ACCEL6_STATUS_0_SLOPE_INT      = 0x04;
const uint8_t _ACCEL6_STATUS_0_HIGH_INT       = 0x02;
const uint8_t _ACCEL6_STATUS_0_LOW_INT        = 0x01;

/* Interrupt status register 1 */
const uint8_t _ACCEL6_STATUS_1_DATA_INT      = 0x80;
const uint8_t _ACCEL6_STATUS_1_FIFO_WM_INT   = 0x40;
const uint8_t _ACCEL6_STATUS_1_FIFO_FULL_INT = 0x20;

/* Interrupt status register 2 */
const uint8_t _ACCEL6_STATUS_2_TAP_SING       = 0x80;
const uint8_t _ACCEL6_STATUS_2_TAP_FIRST_Z    = 0x40;
const uint8_t _ACCEL6_STATUS_2_TAP_FIRST_Y    = 0x20;
const uint8_t _ACCEL6_STATUS_2_TAP_FIRST_X    = 0x10;
const uint8_t _ACCEL6_STATUS_2_SLOPE_SING     = 0x08;
const uint8_t _ACCEL6_STATUS_2_SLOPE_FIRST_Z  = 0x04;
const uint8_t _ACCEL6_STATUS_2_SLOPE_FIRST_Y  = 0x02;
const uint8_t _ACCEL6_STATUS_2_SLOPE_FIRST_X  = 0x01;

/* Interrupt status register 3 */
const uint8_t _ACCEL6_STATUS_3_FLAT_POSITION             = 0x80;
const uint8_t _ACCEL6_STATUS_3_ORIENT_Z_UPWARD           = 0x00;
const uint8_t _ACCEL6_STATUS_3_ORIENT_Z_DOWNWARD         = 0x40;
const uint8_t _ACCEL6_STATUS_3_ORIENT_XY_UPRIGHT         = 0x00;
const uint8_t _ACCEL6_STATUS_3_ORIENT_XY_UPSIDE          = 0x10;
const uint8_t _ACCEL6_STATUS_3_ORIENT_XY_LANDSCAPE_LEFT  = 0x20;
const uint8_t _ACCEL6_STATUS_3_ORIENT_XY_LANDSCAPE_RIGHT = 0x30;
const uint8_t _ACCEL6_STATUS_3_HIGH_SING_POSITIVE        = 0x00;
const uint8_t _ACCEL6_STATUS_3_HIGH_SING_NEGATIVE        = 0x08;
const uint8_t _ACCEL6_STATUS_3_HIGH_FIRST_Z              = 0x04;
const uint8_t _ACCEL6_STATUS_3_HIGH_FIRST_Y              = 0x02;
const uint8_t _ACCEL6_STATUS_3_HIGH_FIRST_X              = 0x01;

/* Accelerometer g-range */
const uint8_t _ACCEL6_PMU_RANGE_2g  = 0x03;
const uint8_t _ACCEL6_PMU_RANGE_4g  = 0x05;
const uint8_t _ACCEL6_PMU_RANGE_8g  = 0x08;
const uint8_t _ACCEL6_PMU_RANGE_16g = 0x0C;

/* Acceleration data filter bandwidth */
const uint8_t _ACCEL6_PMU_BW_7_81Hz  = 0x08;
const uint8_t _ACCEL6_PMU_BW_15_63Hz = 0x09;
const uint8_t _ACCEL6_PMU_BW_31_25Hz = 0x0A;
const uint8_t _ACCEL6_PMU_BW_62_5Hz  = 0x0B;
const uint8_t _ACCEL6_PMU_BW_125Hz   = 0x0C;
const uint8_t _ACCEL6_PMU_BW_250Hz   = 0x0D;
const uint8_t _ACCEL6_PMU_BW_500Hz   = 0x0E;

/* Power modes and the low power sleep period */
const uint8_t _ACCEL6_PMU_LPW_NORMAL_MODE       = 0x00;
const uint8_t _ACCEL6_PMU_LPW_DEEP_SUSPEND_MODE = 0x20;
const uint8_t _ACCEL6_PMU_LPW_LOW_POWER_MODE    = 0x40;
const uint8_t _ACCEL6_PMU_LPW_SUSPEND_MODE      = 0x80;
const uint8_t _ACCEL6_PMU_LPW_SLEEP_0_5ms       = 0x05;
const uint8_t _ACCEL6_PMU_LPW_SLEEP_1ms         = 0x06;
const uint8_t _ACCEL6_PMU_LPW_SLEEP_2ms         = 0x07;
const uint8_t _ACCEL6_PMU_LPW_SLEEP_4ms         = 0x08;
const uint8_t _ACCEL6_PMU_LPW_SLEEP_6ms         = 0x09;
const uint8_t _ACCEL6_PMU_LPW_SLEEP_10ms        = 0x0A;
const uint8_t _ACCEL6_PMU_LPW_SLEEP_25ms        = 0x0B;
const uint8_t _ACCEL6_PMU_LPW_SLEEP_50ms        = 0x0C;
const uint8_t _ACCEL6_PMU_LPW_SLEEP_100ms       = 0x0D;
const uint8_t _ACCEL6_PMU_LPW_SLEEP_500ms       = 0x0E;

/* Interrupt enable group 0 */
const uint8_t _ACCEL6_INT_EN_0_FLAT_ENABLE        = 0x80;
const uint8_t _ACCEL6_INT_EN_0_ORIENT_ENABLE      = 0x40;
const uint8_t _ACCEL6_INT_EN_0_SINGLE_TAP_ENABLE  = 0x20;
const uint8_t _ACCEL6_INT_EN_0_DOUBLE_TAP_ENABLE  = 0x10;
const uint8_t _ACCEL6_INT_EN_0_SLOPE_Z_ENABLE     = 0x04;
const uint8_t _ACCEL6_INT_EN_0_SLOPE_Y_ENABLE     = 0x02;
const uint8_t _ACCEL6_INT_EN_0_SLOPE_X_ENABLE     = 0x01;

/* Interrupt enable group 1 */
const uint8_t _ACCEL6_INT_EN_1_FIFO_WM_ENABLE    = 0x40;
const uint8_t _ACCEL6_INT_EN_1_FIFO_FULL_ENABLE  = 0x20;
const uint8_t _ACCEL6_INT_EN_1_DATA_ENABLE       = 0x10;
const uint8_t _ACCEL6_INT_EN_1_LOW_ENABLE        = 0x08;
const uint8_t _ACCEL6_INT_EN_1_HIGH_Z_ENABLE     = 0x04;
const uint8_t _ACCEL6_INT_EN_1_HIGH_Y_ENABLE     = 0x02;
const uint8_t _ACCEL6_INT_EN_1_HIGH_X_ENABLE     = 0x01;

/* Interrupt enable group 2 */
const uint8_t _ACCEL6_INT_EN_2_MOTION_ENABLE   = 0x08;
const uint8_t _ACCEL6_INT_EN_2_MOTION_Z_ENABLE = 0x04;
const uint8_t _ACCEL6_INT_EN_2_MOTION_Y_ENABLE = 0x02;
const uint8_t _ACCEL6_INT_EN_2_MOTION_X_ENABLE = 0x01;

/* Interrupt map group 0 */
const uint8_t _ACCEL6_INT1_MAP_FLAT_ENABLE        = 0x80;
const uint8_t _ACCEL6_INT1_MAP_ORIENT_ENABLE      = 0x40;
const uint8_t _ACCEL6_INT1_MAP_SINGLE_TAP_ENABLE  = 0x20;
const uint8_t _ACCEL6_INT1_MAP_DOUBLE_TAP_ENABLE  = 0x10;
const uint8_t _ACCEL6_INT1_MAP_MOTION_ENABLE      = 0x08;
const uint8_t _ACCEL6_INT1_MAP_SLOPE_ENABLE       = 0x04;
const uint8_t _ACCEL6_INT1_MAP_HIGH_ENABLE        = 0x02;
const uint8_t _ACCEL6_INT1_MAP_LOW_ENABLE         = 0x01;

/* Interrupt map group 1 */
const uint8_t _ACCEL6_INT2_MAP_DATA_ENABLE        = 0x80;
const uint8_t _ACCEL6_INT2_MAP_FIFO_WM_ENABLE     = 0x40;
const uint8_t _ACCEL6_INT2_MAP_FIFO_FULL_ENABLE   = 0x20;
const uint8_t _ACCEL6_INT1_MAP_DATA_ENABLE        = 0x01;
const uint8_t _ACCEL6_INT1_MAP_FIFO_WM_ENABLE     = 0x02;
const uint8_t _ACCEL6_INT1_MAP_FIFO_FULL_ENABLE   = 0x04;

/* Interrupt map group 2 */
const uint8_t _ACCEL6_INT2_MAP_FLAT_ENABLE        = 0x80;
const uint8_t _ACCEL6_INT2_MAP_ORIENT_ENABLE      = 0x40;
const uint8_t _ACCEL6_INT2_MAP_SINGLE_TAP_ENABLE  = 0x20;
const uint8_t _ACCEL6_INT2_MAP_DOUBLE_TAP_ENABLE  = 0x10;
const uint8_t _ACCEL6_INT2_MAP_MOTION_ENABLE      = 0x08;
const uint8_t _ACCEL6_INT2_MAP_SLOPE_ENABLE       = 0x04;
const uint8_t _ACCEL6_INT2_MAP_HIGH_ENABLE        = 0x02;
const uint8_t _ACCEL6_INT2_MAP_LOW_ENABLE         = 0x01;

/* Interrupt with selectable data source */
const uint8_t _ACCEL6_INT_SRC_DATA   = 0x20;
const uint8_t _ACCEL6_INT_SRC_TAP    = 0x10;
const uint8_t _ACCEL6_INT_SRC_MOTION = 0x08;
const uint8_t _ACCEL6_INT_SRC_SLOPE  = 0x04;
const uint8_t _ACCEL6_INT_SRC_HIGH   = 0x02;
const uint8_t _ACCEL6_INT_SRC_LOW    = 0x01;

/* Configuration (electrical behaviour) of the interrupt pin */
const uint8_t _ACCEL6_INT2_CTRL_OPEN_DRAIN = 0x08;
const uint8_t _ACCEL6_INT1_CTRL_OPEN_DRAIN = 0x02;
const uint8_t _ACCEL6_INT2_CTRL_ACTIVE_HIGH_LEVEL = 0x04;
const uint8_t _ACCEL6_INT1_CTRL_ACTIVE_HIGH_LEVEL = 0x01;

/* Interrupt reset and interrupt selection mode*/
const uint8_t _ACCEL6_LATCH_RESET_INT  = 0x80;
const uint8_t _ACCEL6_LATCH_INT_250ms  = 0x01;
const uint8_t _ACCEL6_LATCH_INT_500ms  = 0x02;
const uint8_t _ACCEL6_LATCH_INT_1sec   = 0x03;
const uint8_t _ACCEL6_LATCH_INT_2sec   = 0x04;
const uint8_t _ACCEL6_LATCH_INT_4sec   = 0x05;
const uint8_t _ACCEL6_LATCH_INT_8sec   = 0x06;
const uint8_t _ACCEL6_LATCH_INT_250us  = 0x09;
const uint8_t _ACCEL6_LATCH_INT_500us  = 0x0A;
const uint8_t _ACCEL6_LATCH_INT_1ms    = 0x0B;
const uint8_t _ACCEL6_LATCH_INT_12_5ms = 0x0C;
const uint8_t _ACCEL6_LATCH_INT_25ms   = 0x0D;
const uint8_t _ACCEL6_LATCH_INT_50ms   = 0x0E;

/* Single tap and double tap interrupts */
const uint8_t _ACCEL6_TAP_QUIET_30ms = 0x00;
const uint8_t _ACCEL6_TAP_QUIET_20ms = 0x80;
const uint8_t _ACCEL6_TAP_SHOCK_50ms = 0x00;
const uint8_t _ACCEL6_TAP_SHOCK_75ms = 0x40;
const uint8_t _ACCEL6_TAP_DUR_50ms   = 0x00;
const uint8_t _ACCEL6_TAP_DUR_100ms  = 0x01;
const uint8_t _ACCEL6_TAP_DUR_150ms  = 0x02;
const uint8_t _ACCEL6_TAP_DUR_200ms  = 0x03;
const uint8_t _ACCEL6_TAP_DUR_250ms  = 0x04;
const uint8_t _ACCEL6_TAP_DUR_375ms  = 0x05;
const uint8_t _ACCEL6_TAP_DUR_500ms  = 0x06;
const uint8_t _ACCEL6_TAP_DUR_700ms  = 0x07;

/* Tap samples */
const uint8_t _ACCEL6_TAP_2_SAMPLES  = 0x00;
const uint8_t _ACCEL6_TAP_4_SAMPLES  = 0x40;
const uint8_t _ACCEL6_TAP_8_SAMPLES  = 0x80;
const uint8_t _ACCEL6_TAP_16_SAMPLES = 0xC0;

/* Self test */
const uint8_t _ACCEL6_SELF_TEST_SING_POSITIVE = 0x40;
const uint8_t _ACCEL6_SELF_TEST_SING_NEGATIVE = 0x00;
const uint8_t _ACCEL6_SELF_TEST_DISABLE       = 0x00;
const uint8_t _ACCEL6_SELF_TEST_X_AXIS        = 0x01;
const uint8_t _ACCEL6_SELF_TEST_Y_AXIS        = 0x02;
const uint8_t _ACCEL6_SELF_TEST_Z_AXIS        = 0x03;

/* Settings for the digital interfaces */
const uint8_t _ACCEL6_I2C_ENABLE   = 0x04;
const uint8_t _ACCEL6_I2C_DISABLE  = 0x00;
const uint8_t _ACCEL6_I2C_WTD_1ms  = 0x00;
const uint8_t _ACCEL6_I2C_WTD_50ms = 0x02;
const uint8_t _ACCEL6_SPI_4_WIRE   = 0x00;
const uint8_t _ACCEL6_SPI_3_WIRE   = 0x01;

/* Offset control register */
const uint8_t _ACCEL6_OFFSET_RESET          = 0x80;
const uint8_t _ACCEL6_OFFSET_TRIGGER_X_AXIS = 0x20;
const uint8_t _ACCEL6_OFFSET_TRIGGER_Y_AXIS = 0x40;
const uint8_t _ACCEL6_OFFSET_TRIGGER_Z_AXIS = 0x60;
const uint8_t _ACCEL6_OFFSET_NOT_TRIGGER    = 0x00;
const uint8_t _ACCEL6_OFC_HP_X_ENABLE       = 0x04;
const uint8_t _ACCEL6_OFC_HP_Y_ENABLE       = 0x02;
const uint8_t _ACCEL6_OFC_HP_Z_ENABLE       = 0x01;

/* Offset settings */
const uint8_t _ACCEL6_OFFSET_TARGET_Z_0g = 0x00;
const uint8_t _ACCEL6_OFFSET_TARGET_Z_PLUS_1g  = 0x20;
const uint8_t _ACCEL6_OFFSET_TARGET_Z_MINUS_1g = 0x40;
const uint8_t _ACCEL6_OFFSET_TARGET_Y_PLUS_1g  = 0x08;
const uint8_t _ACCEL6_OFFSET_TARGET_Y_MINUS_1g = 0x10;
const uint8_t _ACCEL6_OFFSET_TARGET_X_PLUS_1g  = 0x02;
const uint8_t _ACCEL6_OFFSET_TARGET_X_MINUS_1g = 0x04;
const uint8_t _ACCEL6_OFFSET_CUT_OFF_1Hz       = 0x00;
const uint8_t _ACCEL6_OFFSET_CUT_OFF_10Hz      = 0x01;

/* FIFO mode and FIFO data selsect */
const uint8_t _ACCEL6_FIFO_MODE_BYPASS     = 0x00;
const uint8_t _ACCEL6_FIFO_MODE_FIFO       = 0x40;
const uint8_t _ACCEL6_FIFO_MODE_STREAM     = 0x80;
const uint8_t _ACCEL6_FIFO_SELECT_XYZ_AXIS = 0x00;
const uint8_t _ACCEL6_FIFO_SELECT_X_AXIS   = 0x01;
const uint8_t _ACCEL6_FIFO_SELECT_Y_AXIS   = 0x02;
const uint8_t _ACCEL6_FIFO_SELECT_Z_AXIS   = 0x03;

/* Error */
static const uint8_t DEVICE_ERROR = 0x04;
static const uint8_t DEVICE_OK  = 0x00;

/* Tap detect*/
static const uint8_t _TAP_X_NEGATIVE   = 0x01;
static const uint8_t _TAP_Y_NEGATIVE   = 0x02;
static const uint8_t _TAP_Z_NEGATIVE   = 0x03;
static const uint8_t _TAP_X_POSITIVE   = 0x04;
static const uint8_t _TAP_Y_POSITIVE   = 0x05;
static const uint8_t _TAP_Z_POSITIVE   = 0x06;
static const uint8_t _NON_TAP = 0x00;

/* Slope detect */
static const uint8_t _SLOPE_X_NEGATIVE   = 0x01;
static const uint8_t _SLOPE_Y_NEGATIVE   = 0x02;
static const uint8_t _SLOPE_Z_NEGATIVE   = 0x03;
static const uint8_t _SLOPE_X_POSITIVE   = 0x04;
static const uint8_t _SLOPE_Y_POSITIVE   = 0x05;
static const uint8_t _SLOPE_Z_POSITIVE   = 0x06;
static const uint8_t _NON_SLOPE = 0x00;

/* Orient detect */
static const uint8_t _Z_ORIENT_UPWARD_LOOKING   = 0x01;
static const uint8_t _Z_ORIENT_DOWNWARD_LOOKING = 0x02;
static const uint8_t _XY_ORIENT_UPSIDE_DOWN     = 0x01;
static const uint8_t _XY_ORIENT_LANDSCAPE_LEFT  = 0x02;
static const uint8_t _XY_ORIENT_LANDSCAPE_RIGHT = 0x03;
static const uint8_t _XY_ORIENT_UPRIGHT         = 0x04;
/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __ACCEL6_DRV_I2C__
static uint8_t _slaveAddress;
#endif

static float _gaus = 2.0;
static float _freq = 7.81;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */

static void _waitOffset();

/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */

static void _waitOffset()
{
   uint8_t readData = 0;
   
   readData = accel6_readByte(_ACCEL6_REG_OFC_CTRL);
   while (!(readData & 0x10))
   {
       readData = accel6_readByte(_ACCEL6_REG_OFC_CTRL);
   }
}

/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __ACCEL6_DRV_SPI__

void accel6_spiDriverInit(T_ACCEL6_P gpioObj, T_ACCEL6_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __ACCEL6_DRV_I2C__

void accel6_i2cDriverInit(T_ACCEL6_P gpioObj, T_ACCEL6_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __ACCEL6_DRV_UART__

void accel6_uartDriverInit(T_ACCEL6_P gpioObj, T_ACCEL6_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

void accel6_writeByte(uint8_t reg, uint8_t _data)
{
    uint8_t writeReg[ 2 ];
    
    writeReg[ 0 ] = reg;
    writeReg[ 1 ] = _data;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 2, END_MODE_STOP);
}

uint8_t accel6_readByte(uint8_t reg)
{
    uint8_t writeReg[ 1 ];
    uint8_t readReg[ 1 ];
    
    writeReg[ 0 ] = reg;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 1, END_MODE_RESTART);
    hal_i2cRead(_slaveAddress, readReg, 1, END_MODE_STOP);
    
    return readReg[ 0 ];
}

int16_t accel6_readData(uint8_t reg)
{
    uint8_t writeReg[ 1 ];
    uint8_t readReg[ 2 ];
    int16_t readData;
    
    writeReg[ 0 ] = reg;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 1, END_MODE_RESTART);
    hal_i2cRead(_slaveAddress, readReg, 2, END_MODE_STOP);
    
    readData = readReg[ 1 ];
    readData = readData << 8;
    readData = readData | readReg[ 0 ];
    
    return readData;
}

void accel6_softReset()
{
    accel6_writeByte(_ACCEL6_REG_BGW_SOFTRESET, _ACCEL6_SOFT_RESET);
}

uint8_t accel6_init(uint8_t range_data, uint8_t bw_data, uint8_t lpw_data)
{
    volatile uint8_t deviceID;
    
    deviceID = accel6_readByte(_ACCEL6_REG_CHIP_ID);
    
    if (deviceID != _ACCEL6_CHIP_ID)
    {
        return DEVICE_ERROR;
    }
    
    accel6_writeByte(_ACCEL6_REG_PMU_RANGE, range_data);
    accel6_writeByte(_ACCEL6_REG_PMU_BW, bw_data);
    accel6_writeByte(_ACCEL6_REG_PMU_LPW, lpw_data);
    
    accel6_writeByte(_ACCEL6_REG_BGW_SPI3_WDT, _ACCEL6_I2C_ENABLE | _ACCEL6_I2C_WTD_50ms);
    
    accel6_writeByte(_ACCEL6_REG_INT_EN_1,_ACCEL6_INT_EN_1_DATA_ENABLE );
    accel6_writeByte(_ACCEL6_REG_INT_MAP_1,_ACCEL6_INT1_MAP_DATA_ENABLE );
    
    accel6_writeByte(_ACCEL6_REG_INT_EN_0, _ACCEL6_INT_EN_0_SINGLE_TAP_ENABLE |
                                           _ACCEL6_INT_EN_0_DOUBLE_TAP_ENABLE |
                                           _ACCEL6_INT_EN_0_ORIENT_ENABLE |
                                           _ACCEL6_INT_EN_0_SLOPE_X_ENABLE |
                                           _ACCEL6_INT_EN_0_SLOPE_Y_ENABLE |
                                           _ACCEL6_INT_EN_0_SLOPE_Z_ENABLE |
                                           _ACCEL6_INT_EN_0_FLAT_ENABLE);
                                           
    accel6_writeByte(_ACCEL6_REG_INT_MAP_0, _ACCEL6_INT1_MAP_ORIENT_ENABLE |
                                            _ACCEL6_INT1_MAP_SINGLE_TAP_ENABLE | 
                                            _ACCEL6_INT1_MAP_DOUBLE_TAP_ENABLE |
                                            _ACCEL6_INT1_MAP_SLOPE_ENABLE );
    
    accel6_writeByte(_ACCEL6_REG_INT9, 0x0A);
    accel6_writeByte(_ACCEL6_REG_INT_OUT_CTRL, _ACCEL6_INT2_CTRL_ACTIVE_HIGH_LEVEL |
                                               _ACCEL6_INT1_CTRL_ACTIVE_HIGH_LEVEL );
    
    // storage accel range
    if (range_data == _ACCEL6_PMU_RANGE_2g)
    {
        _gaus = 2.0;
    }
    else if (range_data == _ACCEL6_PMU_RANGE_4g)
    {
        _gaus = 4.0;
    }
    else if (range_data == _ACCEL6_PMU_RANGE_8g)
    {
        _gaus = 8.0;
    }
    else if (range_data == _ACCEL6_PMU_RANGE_16g)
    {
        _gaus = 16.0;
    }
    
    // storage bandwidth data
    if (bw_data == _ACCEL6_PMU_BW_7_81Hz)
    {
        _freq = 7.81;
    }
    else if (bw_data == _ACCEL6_PMU_BW_15_63Hz)
    {
        _freq = 15.63;
    }
    else if (bw_data == _ACCEL6_PMU_BW_31_25Hz)
    {
        _freq = 31.25;
    }
    else if (bw_data == _ACCEL6_PMU_BW_62_5Hz)
    {
        _freq = 62.50;
    }
    else if (bw_data == _ACCEL6_PMU_BW_125Hz)
    {
        _freq = 125.0;
    }
    else if (bw_data == _ACCEL6_PMU_BW_250Hz)
    {
        _freq = 250.0;
    }
    else if (bw_data == _ACCEL6_PMU_BW_500Hz)
    {
        _freq = 500.0;
    }
    
    return DEVICE_OK;
}

void accel6_dataOffset(uint8_t setOffset, float *offsetData)
{
    int16_t offsetX = 0;
    int16_t offsetY = 0;
    int16_t offsetZ = 0;
    
    accel6_writeByte(_ACCEL6_REG_OFC_SETTINGS, setOffset);
                                               
    accel6_writeByte(_ACCEL6_REG_OFC_CTRL, _ACCEL6_OFFSET_TRIGGER_X_AXIS );
    _waitOffset();
    accel6_writeByte(_ACCEL6_REG_OFC_CTRL, _ACCEL6_OFFSET_TRIGGER_Y_AXIS );
    _waitOffset();
    accel6_writeByte(_ACCEL6_REG_OFC_CTRL, _ACCEL6_OFFSET_TRIGGER_Z_AXIS );
    _waitOffset();
    
    offsetX = accel6_readData(_ACCEL6_REG_OFC_OFFSET_X);
    offsetX = offsetX << 8;
    offsetData[ 0 ] = offsetX * (_freq / 256.0);
    
    offsetY = accel6_readData(_ACCEL6_REG_OFC_OFFSET_Y);
    offsetY = offsetY << 8;
    
    offsetData[ 1 ] = offsetY * (_freq / 256.0);
    
    offsetZ = accel6_readData(_ACCEL6_REG_OFC_OFFSET_Z);
    offsetZ = offsetZ << 8;
    
    offsetData[ 2 ] = offsetY * (_freq / 256.0);
}

uint8_t accel6_getTapStatus()
{
    uint8_t tap;
    uint8_t tapAxis;
    
    tap = accel6_readByte(_ACCEL6_REG_INT_STATUS_2);
    
     if((tap & 0x80) != 0)
     {
         if((tap & 0x40) != 0)
         {
             return _TAP_X_NEGATIVE;
         }
         if((tap & 0x20) != 0)
         {
             return _TAP_Y_NEGATIVE;
         }
         if((tap & 0x10) != 0)
         {
             return _TAP_Z_NEGATIVE;
         }
     }
     else 
     {
         if((tap & 0x40) != 0)
         {
              return _TAP_X_POSITIVE;
         }
         if((tap & 0x20) != 0)
         {
              return _TAP_Y_POSITIVE;
         }
         if((tap & 0x10) != 0)
         {
              return _TAP_Z_POSITIVE;
         }
     }
     return _NON_TAP;
}

uint8_t accel6_getSlopeStatus()
{
    uint8_t slope;
    uint8_t slopeAxis;

    slope = accel6_readByte(_ACCEL6_REG_INT_STATUS_2);

    if((slope & 0x08) != 0)
    {
        if((slope & 0x04) != 0)
        {
            return _SLOPE_X_NEGATIVE;
        }
        if((slope & 0x02) != 0)
        {
           return _SLOPE_Y_NEGATIVE;
        }
        if((slope & 0x01) != 0)
        {
            return _SLOPE_Z_NEGATIVE;
        }
    }
    else
    {
        if((slope & 0x04) != 0)
        {
             return _SLOPE_X_POSITIVE;
        }
        if((slope & 0x02) != 0)
        {
             return _SLOPE_Y_POSITIVE;
        }
        if((slope & 0x01) != 0)
        {
             return _SLOPE_Z_POSITIVE;
        }
    }
    return _NON_SLOPE;
}

void accel6_getOrient(uint8_t *z_orient, uint8_t *xy_orient)
{
    uint8_t orient;
    
    orient = accel6_readByte(_ACCEL6_REG_INT_STATUS_3);
    
    if ((orient & 0x40) != 0)
    {
        z_orient[ 0 ] = _Z_ORIENT_UPWARD_LOOKING;
    }
    else
    {
        z_orient[ 0 ] = _Z_ORIENT_DOWNWARD_LOOKING;
    }
    
    if ((orient & 0x30) == 0x30)
    {
        xy_orient[ 0 ] = _XY_ORIENT_LANDSCAPE_RIGHT;
    }
    else if ((orient & 0x20) != 0)
    {
        xy_orient[ 0 ] = _XY_ORIENT_LANDSCAPE_LEFT;
    }
    else if ((orient & 0x10) != 0)
    {
        xy_orient[ 0 ] = _XY_ORIENT_UPSIDE_DOWN;
    }
    else
    {
        xy_orient[ 0 ] = _XY_ORIENT_UPRIGHT;
    }
}

float accel6_getAxis(uint8_t axis)
{
    int16_t axisData;
    float fAxis;
    
    axisData = accel6_readData( axis );
    axisData = axisData >> 2;
    fAxis = axisData * ( _gaus / 8192.0 ) / 4.0;
    fAxis = fAxis * 1000;
    
    return fAxis;
}

float accel6_getTemperature()
{
    int16_t dataTemp;
    float fTemp;
    
    dataTemp = accel6_readByte( _ACCEL6_REG_TEMPERATURE );
    fTemp = 0.5 * (float)dataTemp + 23.0;

    return fTemp;
}

/* -------------------------------------------------------------------------- */
/*
  __accel6_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */