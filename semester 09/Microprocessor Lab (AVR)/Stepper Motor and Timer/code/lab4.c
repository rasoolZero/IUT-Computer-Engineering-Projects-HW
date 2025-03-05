/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 10/31/2023
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
            
#include <init.h>
#include <motor.h>
#include <chronometer.h>

#include <mega16.h>
#include <stdio.h>
// Alphanumeric LCD functions
#include <alcd.h>

// Declare your global variables here

// External Interrupt 1 service routine
interrupt [EXT_INT1] void ext_int1_isr(void)
{
// Place your code here
motor_push_routine();
}

// External Interrupt 2 service routine
interrupt [EXT_INT2] void ext_int2_isr(void)
{
// Place your code here
chronometer_push_routine();

}

// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
// Reinitialize Timer 0 value
TCNT0=0x9C;
chronometer_timer_routine();
}



// Timer2 overflow interrupt service routine
interrupt [TIM2_OVF] void timer2_ovf_isr(void)
{

// Reinitialize Timer2 value
TCNT2=0x83;
motor_timer_routine();
}

void main(void)
{
// Declare your local variables here
init();
// Global enable interrupts
#asm("sei")

while (1)
      {
      // Place your code here

      }
}
