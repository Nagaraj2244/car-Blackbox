/*
 * File:   clear_log.c
 * Author: Nagaraj Moger
 *
 * Created on 15 March, 2025, 12:53 PM
 */


#include <xc.h>
#include "main.h"
#include "matrix_keypad.h"
#include "eeprom.h"
#include "uart.h"
#include "i2c.h"
#include "ds1307.h"

void CLEAR_LOG()
{
  lap=0;
  clcd_print(" clear logs ",LINE1(0));
   clcd_print(" Successful ",LINE2(0));
   for (unsigned long wait = 800000; wait--;);
   for (unsigned long wait = 800000; wait--;);
    CLEAR_DISP_SCREEN;
    lap=0;
   flag=dashboard;
}