/*
 * File:   view_log.c
 * Author: Nagaraj Moger
 *
 * Created on 15 March, 2025, 12:50 PM
 */


#include <xc.h>
#include "main.h"
#include "matrix_keypad.h"
#include "eeprom.h"
#include "uart.h"
#include "i2c.h"
#include "ds1307.h"

void VIEW_LOG()
{
 //CLEAR_DISP_SCREEN;
 clcd_print("view log :-", LINE1(0));
 if(lap==0)
 {
         clcd_print(" No logs", LINE1(0));
         clcd_print("  To view", LINE2(0));
 }
 
 else
 {
      key=read_switches(STATE_CHANGE);
  int x=sl_no*10;
  
   if(key==3)
   {
     sl_no++; 
     if(sl_no==lap)
         sl_no=lap-1;
   }
   else if(key==2)
   {
       sl_no--;
       if(sl_no<0)
           sl_no=0;
   }
   else if(key==5)
   {
       flag=menu;
       star_flag=0;
   }
       
   
    clcd_putch(sl_no+48,LINE2(0));
    clcd_putch(' ',LINE2(1));
    clcd_putch(read_internal_eeprom(x),LINE2(2));
    clcd_putch(read_internal_eeprom(x+1),LINE2(3));
    clcd_putch(':',LINE2(4));
    clcd_putch(read_internal_eeprom(x+2),LINE2(5));
    clcd_putch(read_internal_eeprom(x+3),LINE2(6));
    clcd_putch(':',LINE2(7));
    clcd_putch(read_internal_eeprom(x+4),LINE2(8));
    clcd_putch(read_internal_eeprom(x+5),LINE2(9));
    clcd_putch(' ',LINE2(10));
    clcd_putch(read_internal_eeprom(x+6),LINE2(11));
    clcd_putch(read_internal_eeprom(x+7),LINE2(12));
    clcd_putch(' ',LINE2(13));
    clcd_putch(read_internal_eeprom(x+8),LINE2(14));
    clcd_putch(read_internal_eeprom(x+9),LINE2(15));

 }
  
}
