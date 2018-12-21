/*
    __accel6_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __accel6_driver.h
@brief    Accel6 Driver
@mainpage Accel6 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   ACCEL6
@brief      Accel6 Click Driver
@{

| Global Library Prefix | **ACCEL6** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **maj 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _ACCEL6_H_
#define _ACCEL6_H_

/** 
 * @macro T_ACCEL6_P
 * @brief Driver Abstract type 
 */
#define T_ACCEL6_P    const uint8_t*

/** @defgroup ACCEL6_COMPILE Compilation Config */              /** @{ */

//  #define   __ACCEL6_DRV_SPI__                            /**<     @macro __ACCEL6_DRV_SPI__  @brief SPI driver selector */
   #define   __ACCEL6_DRV_I2C__                            /**<     @macro __ACCEL6_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __ACCEL6_DRV_UART__                           /**<     @macro __ACCEL6_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup ACCEL6_VAR Variables */                           /** @{ */

/* Mask */
extern const uint8_t _ACCEL6_CHIP_ID;
extern const uint8_t _ACCEL6_SOFT_RESET;

/* Axis */
extern const uint8_t _ACCEL6_AXIS_X;
extern const uint8_t _ACCEL6_AXIS_Y;
extern const uint8_t _ACCEL6_AXIS_Z;

/* Register */
extern const uint8_t _ACCEL6_REG_CHIP_ID       ;
extern const uint8_t _ACCEL6_REG_AXIS_X_LSB    ;
extern const uint8_t _ACCEL6_REG_AXIS_X_MSB    ;
extern const uint8_t _ACCEL6_REG_AXIS_Y_LSB    ;
extern const uint8_t _ACCEL6_REG_AXIS_Y_MSB    ;
extern const uint8_t _ACCEL6_REG_AXIS_Z_LSB    ;
extern const uint8_t _ACCEL6_REG_AXIS_Z_MSB    ;
extern const uint8_t _ACCEL6_REG_TEMPERATURE   ;
extern const uint8_t _ACCEL6_REG_INT_STATUS_0  ;
extern const uint8_t _ACCEL6_REG_INT_STATUS_1  ;
extern const uint8_t _ACCEL6_REG_INT_STATUS_2  ;
extern const uint8_t _ACCEL6_REG_INT_STATUS_3  ;
extern const uint8_t _ACCEL6_REG_FIFO_STATUS   ;
extern const uint8_t _ACCEL6_REG_PMU_RANGE     ;
extern const uint8_t _ACCEL6_REG_PMU_BW        ;
extern const uint8_t _ACCEL6_REG_PMU_LPW       ;
extern const uint8_t _ACCEL6_REG_PMU_LOW_POWER ;
extern const uint8_t _ACCEL6_REG_ACCD_HBW      ;
extern const uint8_t _ACCEL6_REG_BGW_SOFTRESET ;
extern const uint8_t _ACCEL6_REG_INT_EN_0      ;
extern const uint8_t _ACCEL6_REG_INT_EN_1      ;
extern const uint8_t _ACCEL6_REG_INT_EN_2      ;
extern const uint8_t _ACCEL6_REG_INT_MAP_0     ;
extern const uint8_t _ACCEL6_REG_INT_MAP_1     ;
extern const uint8_t _ACCEL6_REG_INT_MAP_2     ;
extern const uint8_t _ACCEL6_REG_INT_SRC       ;
extern const uint8_t _ACCEL6_REG_INT_OUT_CTRL  ;
extern const uint8_t _ACCEL6_REG_INT_RST_LATCH ;
extern const uint8_t _ACCEL6_REG_INT1          ;
extern const uint8_t _ACCEL6_REG_INT2          ;
extern const uint8_t _ACCEL6_REG_INT3          ;
extern const uint8_t _ACCEL6_REG_INT4          ;
extern const uint8_t _ACCEL6_REG_INT5          ;
extern const uint8_t _ACCEL6_REG_INT6          ;
extern const uint8_t _ACCEL6_REG_INT7          ;
extern const uint8_t _ACCEL6_REG_INT8          ;
extern const uint8_t _ACCEL6_REG_INT9          ;
extern const uint8_t _ACCEL6_REG_INT_A         ;
extern const uint8_t _ACCEL6_REG_INT_B         ;
extern const uint8_t _ACCEL6_REG_INT_C         ;
extern const uint8_t _ACCEL6_REG_INT_D         ;
extern const uint8_t _ACCEL6_REG_FIFO_CONFIG_0 ;
extern const uint8_t _ACCEL6_REG_PMU_SELF_TEST ;
extern const uint8_t _ACCEL6_REG_TRIM_NVM_CTRL ;
extern const uint8_t _ACCEL6_REG_BGW_SPI3_WDT  ;
extern const uint8_t _ACCEL6_REG_OFC_CTRL      ;
extern const uint8_t _ACCEL6_REG_OFC_SETTINGS  ;
extern const uint8_t _ACCEL6_REG_OFC_OFFSET_X  ;
extern const uint8_t _ACCEL6_REG_OFC_OFFSET_Y  ;
extern const uint8_t _ACCEL6_REG_OFC_OFFSET_Z  ;
extern const uint8_t _ACCEL6_REG_TRIM_GP_0     ;
extern const uint8_t _ACCEL6_REG_TRIM_GP_1     ;
extern const uint8_t _ACCEL6_REG_FIFO_CONFIG_1 ;
extern const uint8_t _ACCEL6_REG_FIFO_DATA     ;

/* Interrupt status register 0 */
extern const uint8_t _ACCEL6_STATUS_0_FLOAT_INT      ;
extern const uint8_t _ACCEL6_STATUS_0_ORIENT_INT     ;
extern const uint8_t _ACCEL6_STATUS_0_SINGLE_TAP_INT ;
extern const uint8_t _ACCEL6_STATUS_0_DOUBLE_TAP_INT ;
extern const uint8_t _ACCEL6_STATUS_0_MOTION_INT     ;
extern const uint8_t _ACCEL6_STATUS_0_SLOPE_INT      ;
extern const uint8_t _ACCEL6_STATUS_0_HIGH_INT       ;
extern const uint8_t _ACCEL6_STATUS_0_LOW_INT        ;

/* Interrupt status register 1 */
extern const uint8_t _ACCEL6_STATUS_1_DATA_INT      ;
extern const uint8_t _ACCEL6_STATUS_1_FIFO_WM_INT   ;
extern const uint8_t _ACCEL6_STATUS_1_FIFO_FULL_INT ;

/* Interrupt status register 2 */
extern const uint8_t _ACCEL6_STATUS_2_TAP_SING     ;
extern const uint8_t _ACCEL6_STATUS_2_TAP_FIRST_Z  ;
extern const uint8_t _ACCEL6_STATUS_2_TAP_FIRST_Y  ;
extern const uint8_t _ACCEL6_STATUS_2_TAP_FIRST_X  ;
extern const uint8_t _ACCEL6_STATUS_2_SLOPE_SING   ;
extern const uint8_t _ACCEL6_STATUS_2_SLOPE_FIRST_Z;
extern const uint8_t _ACCEL6_STATUS_2_SLOPE_FIRST_Y;
extern const uint8_t _ACCEL6_STATUS_2_SLOPE_FIRST_X;

/* Interrupt status register 3 */
extern const uint8_t _ACCEL6_STATUS_3_FLAT_POSITION            ;
extern const uint8_t _ACCEL6_STATUS_3_ORIENT_Z_UPWARD          ;
extern const uint8_t _ACCEL6_STATUS_3_ORIENT_Z_DOWNWARD        ;
extern const uint8_t _ACCEL6_STATUS_3_ORIENT_XY_UPRIGHT        ;
extern const uint8_t _ACCEL6_STATUS_3_ORIENT_XY_UPSIDE         ;
extern const uint8_t _ACCEL6_STATUS_3_ORIENT_XY_LANDSCAPE_LEFT ;
extern const uint8_t _ACCEL6_STATUS_3_ORIENT_XY_LANDSCAPE_RIGHT;
extern const uint8_t _ACCEL6_STATUS_3_HIGH_SING_POSITIVE       ;
extern const uint8_t _ACCEL6_STATUS_3_HIGH_SING_NEGATIVE       ;
extern const uint8_t _ACCEL6_STATUS_3_HIGH_FIRST_Z             ;
extern const uint8_t _ACCEL6_STATUS_3_HIGH_FIRST_Y             ;
extern const uint8_t _ACCEL6_STATUS_3_HIGH_FIRST_X             ;

/* Accelerometer g-range */
extern const uint8_t _ACCEL6_PMU_RANGE_2g ;
extern const uint8_t _ACCEL6_PMU_RANGE_4g ;
extern const uint8_t _ACCEL6_PMU_RANGE_8g ;
extern const uint8_t _ACCEL6_PMU_RANGE_16g;

/* Acceleration data filter bandwidth */
extern const uint8_t _ACCEL6_PMU_BW_7_81Hz ;
extern const uint8_t _ACCEL6_PMU_BW_15_63Hz;
extern const uint8_t _ACCEL6_PMU_BW_31_25Hz;
extern const uint8_t _ACCEL6_PMU_BW_62_5Hz ;
extern const uint8_t _ACCEL6_PMU_BW_125Hz  ;
extern const uint8_t _ACCEL6_PMU_BW_250Hz  ;
extern const uint8_t _ACCEL6_PMU_BW_500Hz  ;

/* Power modes and the low power sleep period */
extern const uint8_t _ACCEL6_PMU_LPW_NORMAL_MODE       ;
extern const uint8_t _ACCEL6_PMU_LPW_DEEP_SUSPEND_MODE ;
extern const uint8_t _ACCEL6_PMU_LPW_LOW_POWER_MODE    ;
extern const uint8_t _ACCEL6_PMU_LPW_SUSPEND_MODE      ;
extern const uint8_t _ACCEL6_PMU_LPW_SLEEP_0_5ms       ;
extern const uint8_t _ACCEL6_PMU_LPW_SLEEP_1ms         ;
extern const uint8_t _ACCEL6_PMU_LPW_SLEEP_2ms         ;
extern const uint8_t _ACCEL6_PMU_LPW_SLEEP_4ms         ;
extern const uint8_t _ACCEL6_PMU_LPW_SLEEP_6ms         ;
extern const uint8_t _ACCEL6_PMU_LPW_SLEEP_10ms        ;
extern const uint8_t _ACCEL6_PMU_LPW_SLEEP_25ms        ;
extern const uint8_t _ACCEL6_PMU_LPW_SLEEP_50ms        ;
extern const uint8_t _ACCEL6_PMU_LPW_SLEEP_100ms       ;
extern const uint8_t _ACCEL6_PMU_LPW_SLEEP_500ms       ;

/* Interrupt enable group 0 */
extern const uint8_t _ACCEL6_INT_EN_0_FLAT_ENABLE      ;
extern const uint8_t _ACCEL6_INT_EN_0_ORIENT_ENABLE    ;
extern const uint8_t _ACCEL6_INT_EN_0_SINGLE_TAP_ENABLE;
extern const uint8_t _ACCEL6_INT_EN_0_DOUBLE_TAP_ENABLE;
extern const uint8_t _ACCEL6_INT_EN_0_SLOPE_Z_ENABLE   ;
extern const uint8_t _ACCEL6_INT_EN_0_SLOPE_Y_ENABLE   ;
extern const uint8_t _ACCEL6_INT_EN_0_SLOPE_X_ENABLE   ;

/* Interrupt enable group 1 */
extern const uint8_t _ACCEL6_INT_EN_1_FIFO_WM_ENABLE  ;
extern const uint8_t _ACCEL6_INT_EN_1_FIFO_FULL_ENABLE;
extern const uint8_t _ACCEL6_INT_EN_1_DATA_ENABLE     ;
extern const uint8_t _ACCEL6_INT_EN_1_LOW_ENABLE      ;
extern const uint8_t _ACCEL6_INT_EN_1_HIGH_Z_ENABLE   ;
extern const uint8_t _ACCEL6_INT_EN_1_HIGH_Y_ENABLE   ;
extern const uint8_t _ACCEL6_INT_EN_1_HIGH_X_ENABLE   ;

/* Interrupt enable group 2 */
extern const uint8_t _ACCEL6_INT_EN_2_MOTION_ENABLE  ;
extern const uint8_t _ACCEL6_INT_EN_2_MOTION_Z_ENABLE;
extern const uint8_t _ACCEL6_INT_EN_2_MOTION_Y_ENABLE;
extern const uint8_t _ACCEL6_INT_EN_2_MOTION_X_ENABLE;

/* Interrupt map group 0 */
extern const uint8_t _ACCEL6_INT1_MAP_FLAT_ENABLE      ;
extern const uint8_t _ACCEL6_INT1_MAP_ORIENT_ENABLE    ;
extern const uint8_t _ACCEL6_INT1_MAP_SINGLE_TAP_ENABLE;
extern const uint8_t _ACCEL6_INT1_MAP_DOUBLE_TAP_ENABLE;
extern const uint8_t _ACCEL6_INT1_MAP_MOTION_ENABLE    ;
extern const uint8_t _ACCEL6_INT1_MAP_SLOPE_ENABLE     ;
extern const uint8_t _ACCEL6_INT1_MAP_HIGH_ENABLE      ;
extern const uint8_t _ACCEL6_INT1_MAP_LOW_ENABLE       ;

/* Interrupt map group 1 */
extern const uint8_t _ACCEL6_INT2_MAP_DATA_ENABLE     ;
extern const uint8_t _ACCEL6_INT2_MAP_FIFO_WM_ENABLE  ;
extern const uint8_t _ACCEL6_INT2_MAP_FIFO_FULL_ENABLE;
extern const uint8_t _ACCEL6_INT1_MAP_DATA_ENABLE     ;
extern const uint8_t _ACCEL6_INT1_MAP_FIFO_WM_ENABLE  ;
extern const uint8_t _ACCEL6_INT1_MAP_FIFO_FULL_ENABLE;

/* Interrupt map group 2 */
extern const uint8_t _ACCEL6_INT2_MAP_FLAT_ENABLE      ;
extern const uint8_t _ACCEL6_INT2_MAP_ORIENT_ENABLE    ;
extern const uint8_t _ACCEL6_INT2_MAP_SINGLE_TAP_ENABLE;
extern const uint8_t _ACCEL6_INT2_MAP_DOUBLE_TAP_ENABLE;
extern const uint8_t _ACCEL6_INT2_MAP_MOTION_ENABLE    ;
extern const uint8_t _ACCEL6_INT2_MAP_SLOPE_ENABLE     ;
extern const uint8_t _ACCEL6_INT2_MAP_HIGH_ENABLE      ;
extern const uint8_t _ACCEL6_INT2_MAP_LOW_ENABLE       ;

/* Interrupt with selectable data source */
extern const uint8_t _ACCEL6_INT_SRC_DATA  ;
extern const uint8_t _ACCEL6_INT_SRC_TAP   ;
extern const uint8_t _ACCEL6_INT_SRC_MOTION;
extern const uint8_t _ACCEL6_INT_SRC_SLOPE ;
extern const uint8_t _ACCEL6_INT_SRC_HIGH  ;
extern const uint8_t _ACCEL6_INT_SRC_LOW   ;

/* Configuration (electrical behaviour) of the interrupt pin */
extern const uint8_t _ACCEL6_INT2_CTRL_OPEN_DRAIN;
extern const uint8_t _ACCEL6_INT1_CTRL_OPEN_DRAIN;
extern const uint8_t _ACCEL6_INT2_CTRL_ACTIVE_HIGH_LEVEL;
extern const uint8_t _ACCEL6_INT1_CTRL_ACTIVE_HIGH_LEVEL;

/* Interrupt reset and interrupt selection mode*/
extern const uint8_t _ACCEL6_LATCH_RESET_INT ;
extern const uint8_t _ACCEL6_LATCH_INT_250ms ;
extern const uint8_t _ACCEL6_LATCH_INT_500ms ;
extern const uint8_t _ACCEL6_LATCH_INT_1sec  ;
extern const uint8_t _ACCEL6_LATCH_INT_2sec  ;
extern const uint8_t _ACCEL6_LATCH_INT_4sec  ;
extern const uint8_t _ACCEL6_LATCH_INT_8sec  ;
extern const uint8_t _ACCEL6_LATCH_INT_250us ;
extern const uint8_t _ACCEL6_LATCH_INT_500us ;
extern const uint8_t _ACCEL6_LATCH_INT_1ms   ;
extern const uint8_t _ACCEL6_LATCH_INT_12_5ms;
extern const uint8_t _ACCEL6_LATCH_INT_25ms  ;
extern const uint8_t _ACCEL6_LATCH_INT_50ms  ;

/* Single tap and double tap interrupts */
extern const uint8_t _ACCEL6_TAP_QUIET_30ms;
extern const uint8_t _ACCEL6_TAP_QUIET_20ms;
extern const uint8_t _ACCEL6_TAP_SHOCK_50ms;
extern const uint8_t _ACCEL6_TAP_SHOCK_75ms;
extern const uint8_t _ACCEL6_TAP_DUR_50ms  ;
extern const uint8_t _ACCEL6_TAP_DUR_100ms ;
extern const uint8_t _ACCEL6_TAP_DUR_150ms ;
extern const uint8_t _ACCEL6_TAP_DUR_200ms ;
extern const uint8_t _ACCEL6_TAP_DUR_250ms ;
extern const uint8_t _ACCEL6_TAP_DUR_375ms ;
extern const uint8_t _ACCEL6_TAP_DUR_500ms ;
extern const uint8_t _ACCEL6_TAP_DUR_700ms ;

/* Tap samples */
extern const uint8_t _ACCEL6_TAP_2_SAMPLES ;
extern const uint8_t _ACCEL6_TAP_4_SAMPLES ;
extern const uint8_t _ACCEL6_TAP_8_SAMPLES ;
extern const uint8_t _ACCEL6_TAP_16_SAMPLES;

/* Self test */
extern const uint8_t _ACCEL6_SELF_TEST_SING_POSITIVE;
extern const uint8_t _ACCEL6_SELF_TEST_SING_NEGATIVE;
extern const uint8_t _ACCEL6_SELF_TEST_DISABLE      ;
extern const uint8_t _ACCEL6_SELF_TEST_X_AXIS       ;
extern const uint8_t _ACCEL6_SELF_TEST_Y_AXIS       ;
extern const uint8_t _ACCEL6_SELF_TEST_Z_AXIS       ;

/* Settings for the digital interfaces */
extern const uint8_t _ACCEL6_I2C_ENABLE  ;
extern const uint8_t _ACCEL6_I2C_DISABLE ;
extern const uint8_t _ACCEL6_I2C_WTD_1ms ;
extern const uint8_t _ACCEL6_I2C_WTD_50ms;
extern const uint8_t _ACCEL6_SPI_4_WIRE  ;
extern const uint8_t _ACCEL6_SPI_3_WIRE  ;

/* Offset control register */
extern const uint8_t _ACCEL6_OFFSET_RESET         ;
extern const uint8_t _ACCEL6_OFFSET_TRIGGER_X_AXIS;
extern const uint8_t _ACCEL6_OFFSET_TRIGGER_Y_AXIS;
extern const uint8_t _ACCEL6_OFFSET_TRIGGER_Z_AXIS;
extern const uint8_t _ACCEL6_OFFSET_NOT_TRIGGER   ;
extern const uint8_t _ACCEL6_OFC_HP_X_ENABLE      ;
extern const uint8_t _ACCEL6_OFC_HP_y_ENABLE      ;
extern const uint8_t _ACCEL6_OFC_HP_z_ENABLE      ;


/* Offset settings */
extern const uint8_t _ACCEL6_OFFSET_TARGET_Z_0g;
extern const uint8_t _ACCEL6_OFFSET_TARGET_Z_PLUS_1g  ;
extern const uint8_t _ACCEL6_OFFSET_TARGET_Z_MINUS_1g ;
extern const uint8_t _ACCEL6_OFFSET_TARGET_Y_PLUS_1g  ;
extern const uint8_t _ACCEL6_OFFSET_TARGET_Y_MINUS_1g ;
extern const uint8_t _ACCEL6_OFFSET_TARGET_X_PLUS_1g  ;
extern const uint8_t _ACCEL6_OFFSET_TARGET_X_MINUS_1g ;
extern const uint8_t _ACCEL6_OFFSET_CUT_OFF_1Hz       ;
extern const uint8_t _ACCEL6_OFFSET_CUT_OFF_10Hz      ;

/* FIFO mode and FIFO data selsect */
extern const uint8_t _ACCEL6_FIFO_MODE_BYPASS    ;
extern const uint8_t _ACCEL6_FIFO_MODE_FIFO      ;
extern const uint8_t _ACCEL6_FIFO_MODE_STREAM    ;
extern const uint8_t _ACCEL6_FIFO_SELECT_XYZ_AXIS;
extern const uint8_t _ACCEL6_FIFO_SELECT_X_AXIS  ;
extern const uint8_t _ACCEL6_FIFO_SELECT_Y_AXIS  ;
extern const uint8_t _ACCEL6_FIFO_SELECT_Z_AXIS  ;
                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup ACCEL6_INIT Driver Initialization */              /** @{ */

#ifdef   __ACCEL6_DRV_SPI__
void accel6_spiDriverInit(T_ACCEL6_P gpioObj, T_ACCEL6_P spiObj);
#endif
#ifdef   __ACCEL6_DRV_I2C__
void accel6_i2cDriverInit(T_ACCEL6_P gpioObj, T_ACCEL6_P i2cObj, uint8_t slave);
#endif
#ifdef   __ACCEL6_DRV_UART__
void accel6_uartDriverInit(T_ACCEL6_P gpioObj, T_ACCEL6_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void accel6_gpioDriverInit(T_ACCEL6_P gpioObj);
                                                                       /** @} */
/** @defgroup ACCEL6_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Functions for write one byte in register
 *
 * @param[in] reg    Register in which the data will be written
 * @param[in] _data  Data which be written in the register
 */
void accel6_writeByte(uint8_t reg, uint8_t _data);

/**
 * @brief Functions for read byte from register
 *
 * @param[in] reg    Register which will be read
 * @retval one byte data which is read from the register
 */
uint8_t accel6_readByte(uint8_t reg);

/**
 * @brief Functions for read data from register
 *
 * @param[in] reg     Register which will be read
 * @retval two byte data which is read from the register
 */
int16_t accel6_readData(uint8_t reg);

/**
 * @brief Functions for initialize the chip
 *
 * @param[ in ] range_data      Accelerometer g-range
 * @param[ in ] bw_data         Acceleration data filter bandwidth
 * @param[ in ] lpw_data        Power mode and the low power sleep period.
 *
 * @retval Information whether the chip is successfully initialized or not.
 *
 * Functions initializes accelerometer g-range, filter bandwidth , 
   power mode and sleep period in low power mode.
   Initialization contains and enable data, single tap, double tap, orient, 
   flat and shope x / y / z axis.
 */
uint8_t accel6_init(uint8_t range_data, uint8_t bw_data, uint8_t lpw_data);

/**
 * @brief Functions for read axis data
 *
 * @param[ in ] axis    Axis data which will be read
 * @retval Axis data in mg
 */
float accel6_getAxis(uint8_t axis);

/**
 * @brief Functions for read orient
 *
 * @param[ out ] z_orient    Buffer in which the Z-axis chip orientation will be written.
 * @param[ out ] xy_orient   Buffer in which the XY-axis chip orientation will be written.
 *
 *  Z orientation :
       - UPWARD LOOKING
       - DOWNWARD LOOKING
    XY orientation :
       - UPRIGHT
       - UPSIDE DOWN
       - LANDSCAPE LEFT
       - LANDSCAPE RIGHT
 */
void accel6_getOrient(uint8_t *z_orient, uint8_t *xy_orient);

/**
 * @brief Functions for detect tap on the x/y/z axis
 *
 * @retval Information of the Tap
 *
 * Tap detection :
      - X negative  (0x01)
      - Y negative  (0x02)
      - Z negative  (0x03)
      - X positive  (0x04)
      - Y positive  (0x05)
      - Z positive  (0x06)
 */
uint8_t accel6_getTapStatus();

/**
 * @brief Functions for detect slope on the x/y/z axis
 *
 * @retval Information of the slope
 *
 * Tap detection :
      - X negative  (0x01)
      - Y negative  (0x02)
      - Z negative  (0x03)
      - X positive  (0x04)
      - Y positive  (0x05)
      - Z positive  (0x06)
 */
uint8_t accel6_getSlopeStatus();

/**
 * @brief Functions for set offset
 *
 * @param[ in ] setOffset      Data which will be written in offset settings register
 * @param[ out ] offsetData    Buffer in which the XYZ offset will be written.
                               - offsetData[ 0 ] = x_offset
                               - offsetData[ 1 ] = y_offset
                               - offsetData[ 2 ] = z_offset
 */
void accel6_dataOffset(uint8_t setOffset, float *offsetData);

/**
 * @brief Functions for read temperature
 *
 * @retval Temperature data in C
 *
 * Formula:
       Temperature = 0.5 * Temp_data + 23.0
       - Temp_data  data read from _ACCEL6_REG_TEMPERATURE register
   The formula for calculating the temperature is from dataheet.
 *
 */
float accel6_getTemperature();

/**
 * @brief Functions for software reset
 */
void accel6_softReset();

                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Accel6_STM.c
    @example Click_Accel6_TIVA.c
    @example Click_Accel6_CEC.c
    @example Click_Accel6_KINETIS.c
    @example Click_Accel6_MSP.c
    @example Click_Accel6_PIC.c
    @example Click_Accel6_PIC32.c
    @example Click_Accel6_DSPIC.c
    @example Click_Accel6_AVR.c
    @example Click_Accel6_FT90x.c
    @example Click_Accel6_STM.mbas
    @example Click_Accel6_TIVA.mbas
    @example Click_Accel6_CEC.mbas
    @example Click_Accel6_KINETIS.mbas
    @example Click_Accel6_MSP.mbas
    @example Click_Accel6_PIC.mbas
    @example Click_Accel6_PIC32.mbas
    @example Click_Accel6_DSPIC.mbas
    @example Click_Accel6_AVR.mbas
    @example Click_Accel6_FT90x.mbas
    @example Click_Accel6_STM.mpas
    @example Click_Accel6_TIVA.mpas
    @example Click_Accel6_CEC.mpas
    @example Click_Accel6_KINETIS.mpas
    @example Click_Accel6_MSP.mpas
    @example Click_Accel6_PIC.mpas
    @example Click_Accel6_PIC32.mpas
    @example Click_Accel6_DSPIC.mpas
    @example Click_Accel6_AVR.mpas
    @example Click_Accel6_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __accel6_driver.h

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