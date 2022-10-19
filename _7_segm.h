#ifndef _7_SEGM_H
#define _7_SEGM_H

#define SEVEN_SEG_PORT_INIT() TRISd &= 0xC0;
#define SEVEN_SEG_PORT(x) PORTD = PORTD & 0xf0;  PORTD |= ((x) & 0x0f);
#define EN1(x) if(x == 1) portd.B4=0; else portd.B4=1;
#define EN2(x) if(x == 1) portd.B5=0; else portd.B5=1;

void _7_segm_init(void);  //prorotype
void _7_segm_write_num(unsigned char);

#endif