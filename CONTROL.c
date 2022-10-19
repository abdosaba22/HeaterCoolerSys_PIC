#include "CONTROL.h"
unsigned char txt[7];
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
        _7_segm_write_num(temp);          // Display temp on seven segment
        Lcd_Out(1, 1, "TEMP:");
        NUMBER_TO_STRING(temp);
        Lcd_Out_Cp(txt);                   // Display temp in first row of LCD
       // Lcd_Chr_Cp(223);                   // Put degree symbol ( ° )
        Lcd_Out(2,1,"Motor_speed:");
        NUMBER_TO_STRING(speed);
        Lcd_Out_Cp(txt);                  // Display motor speed in percentage in second row of LCD
        delay_ms(100);
}

unsigned char checkTempGetSpeed(unsigned char temp)
{       unsigned char duty_cycle1=0;

        if (temp <20 ){
                LEDC=0 ;
                AC_LIGHT=0;
                COOLING_EN=0;
                HEATING_EN=1; // heating on
                LEDH=1;  // led of HEATING is on
                Lcd_Out(1, 9, ",HEATER");
                if     ( temp > 17 )                      duty_cycle1 = 50;
                else if((temp <=17  ) && (temp > 14 ))    duty_cycle1 = 60;
                else if((temp <= 14 ) && (temp > 10 ))    duty_cycle1 = 70;
                else if((temp <= 10 ) && (temp > 7 ))     duty_cycle1 = 80;
                else if((temp <= 7 ) && (temp > 4 ))      duty_cycle1 = 90;
                else                                      duty_cycle1 = 100;
        }
        else if (temp <= 35 && temp >= 20)
        {       Lcd_Out(1, 9, ",NORMAL");
                LEDC=0; LEDH=0;// alarm off light
                HEATING_EN=0; COOLING_EN=0; // stable state
                AC_LIGHT=1;
                duty_cycle1 = 0;                        // Motor speed = zero
        }
        else
        {       LEDH=0;
                HEATING_EN=0;
                AC_LIGHT=0;
                COOLING_EN=1;   // COOLING on
                LEDC=1; // led of HEATING is on
                Lcd_Out(1, 9, ",COOLER");
                if     ( temp < 38 )                          duty_cycle1 = 50;
                else if((temp >= 38 ) && (temp < 40 ))        duty_cycle1 = 60;
                else if((temp >= 40 ) && (temp < 42 ))        duty_cycle1 = 70;
                else if((temp >= 42 ) && (temp < 45 ))        duty_cycle1 = 80;
                else if((temp >= 45 ) && (temp < 48 ))        duty_cycle1 = 90;
                else                                          duty_cycle1 = 100;
        }
        return duty_cycle1;
}
void NUMBER_TO_STRING(unsigned char num){
        char i=2;
        txt[0]='0'; txt[1]='0'; txt[2]='0';
        if (num ==0) return;
        else{

          //save every digit of num in our array separately
          for(;num!=0;i--)
          {
                  txt[i]=(num%10) +'0';
                  num/=10;
          }

        }
}