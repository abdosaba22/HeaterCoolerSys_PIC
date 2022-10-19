#ifndef CONTROL_H_

#define CONTROL_H_

#include "PWM.h"
#include "_7_segm.h"
#include "ADC.h"

// LCD module connections
sbit LCD_RS at RC1_bit;
sbit LCD_EN at RC3_bit;
sbit LCD_D4 at RC4_bit;
sbit LCD_D5 at RC5_bit;
sbit LCD_D6 at RC6_bit;
sbit LCD_D7 at RC7_bit;
sbit LCD_RS_Direction at TRISC1_bit;
sbit LCD_EN_Direction at TRISC3_bit;
sbit LCD_D4_Direction at TRISC4_bit;
sbit LCD_D5_Direction at TRISC5_bit;
sbit LCD_D6_Direction at TRISC6_bit;
sbit LCD_D7_Direction at TRISC7_bit;
// End LCD module connections

sbit COOLING_EN at portb.b1 ; // for Cooling
sbit HEATING_EN at portb.b0 ; // for heating
sbit LEDC at portb.b2;        // for light LED as alarm in case of COOLING
sbit LEDH at portb.b3;        // for light LED as alarm in case of HEATING
sbit AC_LIGHT at portb.b4;
// Prototype of functions we need
unsigned char getTemp();
void applySpeedOnMotor(unsigned char speed);
void displayTempAndSpeed(unsigned char temp,unsigned char speed);
unsigned char checkTempGetSpeed(unsigned char temp);
void NUMBER_TO_STRING(unsigned char num);


#endif