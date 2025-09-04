/*
 * File:   get_time.c
 * Author: Nagaraj Moger
 *
 * Created on 15 March, 2025, 12:54 PM
 */


#include <xc.h>
#include "main.h"
#include "matrix_keypad.h"
#include "eeprom.h"
#include "uart.h"
#include "i2c.h"
#include "ds1307.h"

void get_time(void)
{
	clock_reg[0] = read_ds1307(HOUR_ADDR);
	clock_reg[1] = read_ds1307(MIN_ADDR);
	clock_reg[2] = read_ds1307(SEC_ADDR);

	if (clock_reg[0] & 0x40)
	{
		time[0] = '0' + ((clock_reg[0] >> 4) & 0x01);
		time[1] = '0' + (clock_reg[0] & 0x0F);
	}
	else
	{
		time[0] = '0' + ((clock_reg[0] >> 4) & 0x03);
		time[1] = '0' + (clock_reg[0] & 0x0F);
	}
	time[2] = ':';
	time[3] = '0' + ((clock_reg[1] >> 4) & 0x0F);
	time[4] = '0' + (clock_reg[1] & 0x0F);
	time[5] = ':';
	time[6] = '0' + ((clock_reg[2] >> 4) & 0x0F);
	time[7] = '0' + (clock_reg[2] & 0x0F);
	time[8] = '\0';
}

 void SET_TIME()
 {
     get_time();
     key=read_switches(STATE_CHANGE);
      if (extract == 0) 
    {
        hr = ((time[0] -  '0') * 10) + (time[1] - '0');
        min = ((time[3] - '0') * 10) + (time[4] - '0');
        sec = ((time[6] - '0') * 10) + (time[7] - '0');
        extract = 1;
        field = 0;  
        set();
    }
     if (++delay2 == 100) 
    {
        t[0] = (hr / 10)  + '0'; 
        t[1] = (hr % 10)  + '0';
        t[3] = (min / 10) + '0';
        t[4] = (min % 10) + '0';
        t[6] = (sec / 10) + '0';
        t[7] = (sec % 10) + '0';
        delay2 = 0;
        if (field == 0)
        {
            if (toggle == 0) 
            {
                toggle = 1;
               
            } 
            else 
            {
                toggle = 0;
                t[0] = 0xFF;
                t[1] = 0xFF;
            }
        } 
        else if (field == 1) 
        {
            if (toggle == 0) 
            {
                toggle = 1;
              
            } 
            else 
            {
                toggle = 0;
                t[3] = 0xFF;
                t[4] = 0xFF;
            }
        } 
        else if (field == 2)
        {
            if (toggle == 0) 
            {
                toggle = 1;
        
            } 
            else 
            {
                toggle = 0;
                t[6] = 0xFF;
                t[7] = 0xFF;
            }
        }
    }

      
    if (key == 3) 
    {
        field++;
        delay2 = 0;
        toggle = 0;
        if (field > 2)
            field= 0;
    } 
    else if (key == 2) 
    {
        if (field == 0) 
        {
            hr = (hr + 1) % 24;
        } 
        else if (field== 1) 
        {
            min = (min + 1) % 60;
        } 
        else if (field== 2) 
        {
            sec = (sec + 1) % 60;
        }
    }
      else if (key == 4) 
    {
        extract = 0;
        toggle = 0;
        save_in_rtc(hr, min, sec);
        CLEAR_DISP_SCREEN;
        flag= dashboard;
        star_flag=0;
        menu_index=0;
          CLEAR_DISP_SCREEN;
    }
      else if(key==5)
      {
         extract = 0;
        toggle = 0;
        CLEAR_DISP_SCREEN;
        flag = dashboard;
        star_flag=0;
         menu_index=0;
          CLEAR_DISP_SCREEN;
      }
     clcd_print("   HH:MM:SS  ", LINE1(0));
    clcd_print(t, LINE2(3));
    CLEAR_DISP_SCREEN;
 }
 
 void set() 
{
    t[0] = (hr / 10) + '0';
    t[1] = (hr % 10) + '0';
    t[3] = (min / 10) + '0';
    t[4] = (min % 10) + '0';
    t[6] = (sec / 10) + '0';
    t[7] = (sec % 10) + '0';
}

void save_in_rtc(int hr, int min, int sec) 
{
    unsigned char ss, mm, hh;
    hh = convert_to_bcd(hr);
    write_ds1307(HOUR_ADDR, hh);
    mm = convert_to_bcd(min);
    write_ds1307(MIN_ADDR, mm);
    ss = convert_to_bcd(sec);
    write_ds1307(SEC_ADDR, ss);
}

unsigned char convert_to_bcd(unsigned char num) 
{
    unsigned char result = 0;
    unsigned char shift = 0;

    while (num > 0) 
    {
        result = result|((num % 10) << shift);
        num = num/10;
        shift =shift + 4;
    }
    return result;
}
