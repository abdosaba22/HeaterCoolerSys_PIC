#ifndef LCD_H_
#define LCD_H_


#define LCD_PORT_INIT() TRISC = 0b00000000;
#define READBIT(REG,BIT) ((REG >> BIT) & 1) ;
#define RS(x) if(x == 1) portc.b1=1; else portc.b1=0 ;
#define EN(x) if(x == 1) portc.b3=1; else portc.b3=0 ;
#define D4(x) if(x == 1) portc.b4=1; else portc.b4=0;
#define D5(x) if(x == 1) portc.b5=1; else portc.b5=0:
#define D6(x) if(x == 1) portc.b6=1; else portc.b6=0:
#define D7(x) if(x == 1) portc.b7=1; else portc.b7=0:

void LCD_init(void);
void LCD_write_command(unsigned char);
void LCD_write_char(unsigned char);
void LCD_write_num(unsigned int);
void LCD_write_string(unsigned char *);

#endif