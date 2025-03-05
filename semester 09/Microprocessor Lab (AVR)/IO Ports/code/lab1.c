/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 10/10/2023
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
#include <delay.h>
#include "portinit.h"

// Declare your global variables here
int centisecond;
int seconds;
flash unsigned char digit[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

//char isPD7Pressed(){
//    stat
//}
 
void main(void)
{
// Declare your local variables here  
char running = 0;
int digit1;
int digit2;
int digit3;
int digit4; 
centisecond = 0;
seconds = 0; 
initialPorts();
while (1)
      {
        if (isPD7Pressed()){
            seconds = centisecond = 0;
            running = 1;
        }
        
        if (isPD6Down()) running = 0;
        
        if (running){
            centisecond++;
            if (centisecond == 100){
                centisecond = 0;
                seconds++;
            }
            if (seconds == 100){
                seconds = 0;
            }  
        }
                                    
        digit1 = centisecond%10;
        digit2 = centisecond>=10?centisecond/10:0;
        digit3 = seconds%10;  
        digit4 = seconds>=10?seconds/10:0;
        
        updatePortD(digit[digit1],digit[digit2],digit[digit3],digit[digit4]);      
        updatePortB();     
        delay_ms(2);  
      }
}
