/*
 * File:   main.c
 * Author: Nagaraj Moger
 *
 * Created on 5 March, 2025, 1:46 PM
 */


#include <xc.h>
#include "main.h"
#include "matrix_keypad.h"
#include "eeprom.h"
#include "uart.h"
#include "i2c.h"
#include "ds1307.h"

void init_config(void)
{
    init_clcd();
    TRISB=0x1E;
    RBPU=0;
    RB5=RB6=RB7=1;
}

void main(void)
{
    flag=dashboard;
    
    init_config();
     init_adc();
     init_matrix_keypad();
     init_uart();
    init_i2c();
	init_ds1307();
    while (1)
    {
         
         if(flag==dashboard)
         {
             dash_board(); 
         }
         else if(flag==menu)
         {
             MENU();
         }
         else if(flag==view_log)
         {
             VIEW_LOG();
         } 
         else if(flag==download_log)
         {
             DOWNLOAD_LOG();
         }
          else if(flag==clear_log)
          {
              CLEAR_LOG();
          }
         else if(flag==set_time)
         {
             SET_TIME();
         }
    }
}






