![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Accel6 Click

- **CIC Prefix**  : ACCEL6
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : maj 2018.

---

### Software Support

We provide a library for the Accel6 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2421/accel-6-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library initializes and defines the I2C bus driver and drivers that offer a choice for writing data in register.
The library includes function for read X/Y/Z axis data , orient chip, detect tap and slope on the chip and function for read temperature data .
The user also has the function for initializes chip, set offset and software reset.

Key functions :

- ``` float accel6_getAxis(uint8_t axis) ``` - Functions for read axis data
- ``` void accel6_getOrient(uint8_t *z_orient, uint8_t *xy_orient) ``` - Functions for read orient
- ``` uint8_t accel6_getTapStatus() ``` - Functions for detect tap on the x/y/z axis

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes I2C module
- Application Initialization - Initializes Driver init and settings accelerometer data range, 
                               bandwidth, mode and sleep timer which are necessary for the init chip.
- Application Task - (code snippet) - Reads the accel X / Y / Z axis data in mg, 
                                      Temperature data in C, detects the orientation of the X,Y and Z axis
                                      and checking on which axis the tap is detected.
                                      All data logs on usb uart for every 500 ms.


```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2421/accel-6-click) page.

Other mikroE Libraries used in the example:

- I2C
- UART
- Conversions

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
