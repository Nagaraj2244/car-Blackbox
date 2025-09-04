/*
 * File:   download_log.c
 * Author:Nagaraj Moger
 *
 * Created on 15 March, 2025, 12:51 PM
 */



#include <xc.h>
#include "main.h"
#include "matrix_keypad.h"
#include "eeprom.h"
#include "uart.h"
#include "i2c.h"
#include "ds1307.h"

void DOWNLOAD_LOG()
{
    if(lap==0)
    {
           clcd_print(" NO LOGS ",LINE1(0));
            clcd_print("TO DOWNLOAD ",LINE2(0));
            for (unsigned long wait = 800000; wait--;);
            for (unsigned long wait = 800000; wait--;);
          // lap=0;
            CLEAR_DISP_SCREEN;
            flag=dashboard;
    }
    else
    {
        
        clcd_print("Download Log ",LINE1(0));
        clcd_print(" Success ",LINE2(0));
         for (unsigned long wait = 800000; wait--;);
         for (unsigned long wait = 800000; wait--;);
         for (unsigned long wait = 800000; wait--;);
           
         puts("THE Download LOGS ARE:\n\r");
         puts("#   Time   Ev SP\n\r");
          
             int z=0;
             while(z!=lap)
             {
              putch(z+48);
           
            putch(' ');
            putch(read_internal_eeprom(z*10));
            putch(read_internal_eeprom(z*10+1));
            putch(':');
            putch(read_internal_eeprom(z*10+2));
            putch(read_internal_eeprom(z*10+3));
            putch(':');
            putch(read_internal_eeprom(z*10+4));
            putch(read_internal_eeprom(z*10+5));
            putch(' ');
            putch(read_internal_eeprom(z*10+6));
            putch(read_internal_eeprom(z*10+7));
            putch(' ');
            putch(read_internal_eeprom(z*10+8));
            putch(read_internal_eeprom(z*10+9));
            puts("\n\r");
            z++;
             }
             if(z==lap)
             {
                  for (unsigned long wait = 800000; wait--;);
                CLEAR_DISP_SCREEN;
                flag=dashboard; 
                
             }
   
    }
}