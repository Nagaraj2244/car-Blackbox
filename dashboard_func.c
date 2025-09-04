/*
 * File:   dashboard_func.c
 * Author: Nagaraj Moger
 *
 * Created on 10 March, 2025, 8:12 AM
 */

#include <xc.h>
#include "main.h"
#include "matrix_keypad.h"
#include "eeprom.h"
#include "uart.h"
#include "i2c.h"
#include "ds1307.h"
void dash_board()
{
   
    get_time();
     
        clcd_print("Time", LINE1(0)); 
        clcd_putch(time[0], LINE2(0));
         clcd_putch(time[1], LINE2(1));
         clcd_putch(time[2], LINE2(2));
           clcd_putch(time[3], LINE2(3));
            clcd_putch(time[4], LINE2(4));
           clcd_putch(time[5], LINE2(5));
             clcd_putch(time[6], LINE2(6));
             clcd_putch(time[7], LINE2(7));
       
         clcd_print("Ev", LINE1(10));
          
         key=read_switches(STATE_CHANGE);
         if(key==2)
         {
             if(event_index==8)
                 event_index=2;
             else
             {
             event_index++;
             if(event_index>7)
             event_index=7;  
             }
             save_flag=1;
         }
         else if(key==3)
         {
             if(event_index==8)
                 event_index=2;
             
             else if(event_index==0||event_index==1)
             {
                 event_index=1;
             }
             else
                 event_index--; 
             save_flag=1;
         }
         else if(key==1)
         {
             event_index=8;
             save_flag=1;
         }  
          clcd_print(event[event_index], LINE2(10));
      
         clcd_print("SP", LINE1(14));
         short duty_cycle=(read_adc()/10.33);
          clcd_putch((duty_cycle/10)+48, LINE2(14));
           clcd_putch((duty_cycle%10)+48, LINE2(15)); 
           
           arr[0]=time[0];
           arr[1]=time[1];
           arr[2]=time[3];
           arr[3]=time[4];
           arr[4]=time[6];
           arr[5]=time[7];
           
           arr[6]=event[event_index][0];
           arr[7]=event[event_index][1];
            
           arr[8]=(duty_cycle/10)+48;
           arr[9]=(duty_cycle%10)+48;
   
           if(save_flag==1)
           {
            if(lap==10)
           {
             lap=9;
             int x=lap+1;
             while(x<100)
             {
             write_internal_eeprom(x-10,read_internal_eeprom(x)); 
             x++;
             }  
           }
             for(int i=0;i<10;i++)
           {
              write_internal_eeprom(i+(10*lap),arr[i]);  
           }
           lap++; 
           save_flag=0;
           }
  
           
           if(key==4)
           {
             flag=menu;
              star_flag=0;
                CLEAR_DISP_SCREEN;
           }
      
}
