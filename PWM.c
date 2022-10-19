#include "PWM.h"

void PWM_CCP1_init(void){
 //--[ Configure The CCP Module For PWM Mode ]--
          CCP1CON.CCP1M3 = 1;
          CCP1CON.CCP1M2 = 1;
          TRISC.b2 = 0; // The CCP1 Output Pin (PWM)
          // Set The PWM Frequency (9.77kHz)  /* (1/PWM Fre /4 ) - 1 */
          PR2 = 0xFF;
          // Set The PS For Timer2 (1:4 Ratio)    prescaler
          T2CON.T2CKPS0 = 1;
          T2CON.T2CKPS1 = 0;
          // Start CCP1 PWM !
          T2CON.TMR2ON = 1;
}
/*
Resolution = 8.96578 bits
the maximum duty cycle 100% is given by writing 2^Resolution = 2^8.96578 = 500
*/

void PWM_CCP1_set_duty(unsigned char duty){
         unsigned int DC_value = duty *10.23 ;
         CCP1CON.CCP1Y = DC_value & 1;
         CCP1CON.CCP1X = DC_value & 2;
         CCPR1L = DC_value >> 2;
}