/*
 * File:   menu_func.c
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
void MENU()
{
    // CLEAR_DISP_SCREEN;
     key=read_switches(STATE_CHANGE);
 
       if(star_flag==0)
       {
           CLEAR_DISP_SCREEN;
        clcd_print(menu_arr[menu_index], LINE1(1));  
       clcd_print(menu_arr[menu_index+1], LINE2(1));
       clcd_putch('*',LINE1(0));
       clcd_putch(' ',LINE2(0)); 
        star_flag=1;
       
       }
       else
       {
           if(key==3)
           {
               CLEAR_DISP_SCREEN;
             menu_index++;
             if(menu_index==4)
             menu_index=3;
         clcd_print(menu_arr[menu_index-1], LINE1(1));  
       clcd_print(menu_arr[menu_index], LINE2(1));
       
        clcd_putch(' ',LINE1(0));
        clcd_putch('*',LINE2(0)); 
     
           }
           
           else if(key==2)
           {
              CLEAR_DISP_SCREEN;
                    menu_index--;
                    if(menu_index<0)
                    menu_index=0;
                    clcd_print(menu_arr[menu_index], LINE1(1));  
                   clcd_print(menu_arr[menu_index+1], LINE2(1));
                   clcd_putch('*',LINE1(0));
                   clcd_putch(' ',LINE2(0)); 
                  
           }
                   
       }
        if(key==5)
        {
        CLEAR_DISP_SCREEN;
        flag=dashboard;
        } 
       else if(key==4)
       {
           if(menu_index==0)
           {
              flag= view_log;
              CLEAR_DISP_SCREEN;
           }
           else if(menu_index==1)
           {
              flag= download_log;
              CLEAR_DISP_SCREEN;
           }
           else if(menu_index==2)
           {
              flag= clear_log;
              CLEAR_DISP_SCREEN;
           }
           else if(menu_index==3)
           {
              flag=set_time;
              CLEAR_DISP_SCREEN;
           }
       }
}