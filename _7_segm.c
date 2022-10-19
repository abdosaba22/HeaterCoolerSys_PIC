#include "_7_segm.h"

void _7_segm_init(void){
SEVEN_SEG_PORT_INIT();
EN1(0); EN2(0); // close the 7-seg
}

void _7_segm_write_num(unsigned char t)
{
 SEVEN_SEG_PORT(t% 10) ;
 EN2(1);
 delay_ms(5); EN2(0);

 SEVEN_SEG_PORT(t/ 10) ;
 EN1(1) ;
 delay_ms(5);EN1(0) ;
}