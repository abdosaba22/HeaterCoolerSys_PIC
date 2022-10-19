#include "CONTROL.h"

void main(void)
{   unsigned char temperature;
    unsigned char speed ;
    trisb=0;
    portb.b7=0;

    LCD_Init();
    Lcd_Cmd(_LCD_CURSOR_OFF);        // cursor off
    Lcd_Cmd(_LCD_CLEAR);             // clear LCD
    ADC_Init();
    PWM_CCP1_init();
    _7_segm_init();

    while (1)
    {
        temperature = getTemp();                                // Get current temperature
        speed = checkTempGetSpeed(temperature);                 // Get speed corresponding to the current temperature
        applySpeedOnMotor(speed);                               // Increase/decrease motor speed according to measured temperature
        displayTempAndSpeed(temperature, speed);                // Display both on screen
    }

}
