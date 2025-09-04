#include<xc.h>
enum f{dashboard,menu,view_log,download_log,clear_log,set_time};
char t[9]="00:00:00";
unsigned char clock_reg[3];
char key;
unsigned char time[9];
int event_index,lap=0,menu_index,star_flag,sl_no=0,save_flag=0,delay1=0,delay2=0,field=0,extract = 0,toggle = 0;
int hr, min, sec;
char arr[10];
char event[][3]={"ON","GR","GN","G1","G2","G3","G4","G5"," C"};
char menu_arr[][13]={"view log    ","Download log","Clear log   ","Set time    "};
enum f flag;

#ifndef LCD_H
#define LCD_H



#define CLCD_PORT			PORTD
#define CLCD_EN				RC2
#define CLCD_RS				RC1
#define CLCD_RW				RC0
#define CLCD_BUSY			RD7
#define PORT_DIR			TRISD7


#define HI												1
#define LO												0

#define INPUT											0xFF
#define OUTPUT											0x00

#define DATA_COMMAND									1
#define INSTRUCTION_COMMAND								0
#define _XTAL_FREQ                  20000000
#define LINE1(x)									(0x80 + (x))
#define LINE2(x)										(0xC0 + (x))

#define TWO_LINE_5x8_MATRIX_8_BIT					clcd_write(0x38, INSTRUCTION_COMMAND)
#define CLEAR_DISP_SCREEN				                clcd_write(0x01, INSTRUCTION_COMMAND)
#define CURSOR_HOME							clcd_write(0x02, INSTRUCTION_COMMAND)
#define DISP_ON_AND_CURSOR_OFF						clcd_write(0x0C, INSTRUCTION_COMMAND)
#define EIGHT_BIT_MODE   0x30
void init_clcd(void);
void clcd_print(const unsigned char *data, unsigned char addr);
void clcd_putch(const unsigned char data, unsigned char addr);
void clcd_write(unsigned char bit_values, unsigned char control_bit);
void init_adc(void);
unsigned short read_adc();
void dash_board();
void MENU();
void VIEW_LOG();
void DOWNLOAD_LOG();
void CLEAR_LOG();
void SET_TIME();
 void set();
 void save_in_rtc(int hr, int min, int sec);
 unsigned char convert_to_bcd(unsigned char num);
 void get_time(void);
#endif

