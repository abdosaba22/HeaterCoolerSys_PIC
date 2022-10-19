#ifndef FUNCIONS_H_
#define FUNCIONS_H_

#include "ADC.h"

#include "LCD.h"
#include "PWM.h"



unsigned char getTemp();
void applySpeedOnMotor(unsigned int speed);
void displayTempAndSpeed(unsigned char temp,unsigned char speed);
unsigned int checkTempGetSpeed(unsigned char temp);

#endif