/*
 * File:   init_adc.c
 * Author: Nagaraj Moger
 *
 * Created on 5 March, 2025, 2:21 PM
 */


#include "main.h"
unsigned short read_adc() // Function to read the ADC value and return it
{
    GO=1; // Start the ADC conversion by setting the GO bit
    while(GO);     // Wait for the conversion to complete
    return ((ADRESH<<8)|ADRESL);  // Combine the 8-bit high (ADRESH) and low (ADRESL) registers into a 16-bit value
}

void init_adc(void) 
{
    CHS3=0;
    CHS2=1;
    CHS1=0;
    CHS0=0;
    
    ADON=1;
    
    VCFG1=0;
    VCFG0=0;
    
    PCFG3=1;
    PCFG2=0;
    PCFG1=1;
    PCFG0=0;
    
    ADFM=1;
    
    ADCS2=0;
    ADCS1=1;
    ADCS0=0;
    
    ACQT2=1;
    ACQT1=0;
    ACQT1=0;
    
    return;
}
