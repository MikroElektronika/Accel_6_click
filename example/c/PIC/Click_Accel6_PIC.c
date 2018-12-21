/*
Example for Accel6 Click

    Date          : maj 2018.
    Author        : Katarina Perendic

Test configuration PIC :
    
    MCU             : P18F87K22
    Dev. Board      : EasyPIC PRO v7
    PIC Compiler ver : v7.2.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes I2C module
- Application Initialization - Initializes Driver init and settings accelerometer data range,
                               bandwidth, mode and sleep timer which are necessary for the init chip.
- Application Task - (code snippet) - Reads the accel X / Y / Z axis data in mg,
                                      Temperature data in C, detects the orientation of the X,Y and Z axis
                                      and checking on which axis the tap is detected.
                                      All data logs on usb uart for every 500 ms.

*/

#include "Click_Accel6_types.h"
#include "Click_Accel6_config.h"

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
    accel6_i2cDriverInit( (T_ACCEL6_P)&_MIKROBUS1_GPIO, (T_ACCEL6_P)&_MIKROBUS1_I2C, 0x18 );

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