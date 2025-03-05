/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 11/11/2023
Author  : 
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <stdlib.h>
#include <string.h>

#include <init.h>

// Alphanumeric LCD functions
#include <alcd.h>

// Declare your global variables here
char string[33] = "";
int index=0;

// Standard Input/Output functions
#include <stdio.h>

void main(void)
{
// Declare your local variables here

init_ports();
init_uart();
init_lcd();
             
puts("please enter your name, input must be under 28 characters\r\n");
while (1)
      {
        char ch = getchar();     
        if(ch == '\n' || ch == '\r'){
            string[index] = 0;
            lcd_clear();
            lcd_gotoxy(0,0);
            lcd_puts("<<");
            lcd_puts(string); 
            lcd_puts(">>");
            index = 0;
        }
        string[index++] = ch;
        if(index == 28){
            string[index] = 0;
            lcd_clear();
            lcd_gotoxy(0,0);
            lcd_puts("<<");
            lcd_puts(string); 
            lcd_puts(">>");
            index = 0;   
        }
      }
}
