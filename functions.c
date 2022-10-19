#include "functions.h"
#include "LCD.h"
sbit COOLING_EN at portb.b0 ;
sbit HEATING_EN at portb.b1 ;
sbit LEDA at porta.b0;
unsigned char getTemp()
{
        /* 4.88 m.v for level --> 5 V / 1023
           ADC_read return number of the level multiply it by 4.88 = V_out m.v from sens
           T c = V_out m.v / 10.00 m.v --> 10 mv/c */
        unsigned char temp = ( ( ADC_Read(0) *4.88)/10.00) ;        //temp in C
        return temp;
}
void applySpeedOnMotor(unsigned char speed)
{
        PWM_CCP1_set_duty(speed);
}

void displayTempAndSpeed(unsigned char temp, unsigned char speed)
{
                                       // Display temp on seven segment
        LCD_write_command(0x01);
        LCD_write_string("Temp:");
        LCD_write_command(0x87);
        LCD_write_num(temp);                                // Display temp in first row of LCD
        LCD_write_command(0xC0);
        LCD_write_string("Motor_speed:");
        LCD_write_command(0xCD);
        LCD_write_num(speed);                                // Display motor speed in percentage in second row of LCD
        delay_ms(100);
}

unsigned int checkTempGetSpeed(unsigned char temp)
{       unsigned int dc1=0;
        trisb=0;

        if (temp <= 35 && temp >= 20)
        {
                LEDA=0; // alarm off light
                dc1 = 0;                        // Motor speed = zero
        }
        else if (temp <20 ){
                HEATING_EN=1; // heating on
                LEDA=1;
                if        ((temp <  20 ) && (temp > 18 ))                dc1 = 50;
                else if((temp <=18  ) && (temp < 15 ))        dc1 = 60;
                else if((temp <= 15 ) && (temp < 10 ))        dc1 = 70;
                else if((temp <= 10 ) && (temp < 7 ))        dc1 = 80;
                else if((temp <= 7 ) && (temp < 4 ))        dc1 = 90;
                else        dc1 = 100;
        }
        else
        {       COOLING_EN=1;
                LEDA=1; // alarm on Light
                if        ((temp >  35 ) && (temp < 38 ))                dc1 = 50;
                else if((temp >= 38 ) && (temp < 40 ))        dc1 = 60;
                else if((temp >= 40 ) && (temp < 42 ))        dc1 = 70;
                else if((temp >= 42 ) && (temp < 45 ))        dc1 = 80;
                else if((temp >= 45 ) && (temp < 48 ))        dc1 = 90;
                else        dc1 = 100;
        }
        return dc1;
}