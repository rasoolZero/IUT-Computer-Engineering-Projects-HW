/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 11/14/2023
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
#include <string.h>
#include <delay.h>
#include <ctype.h>

#include <init.h>
// Alphanumeric LCD functions
#include <alcd.h>


#define DATA_REGISTER_EMPTY (1<<UDRE)
#define RX_COMPLETE (1<<RXC)
#define FRAMING_ERROR (1<<FE)
#define PARITY_ERROR (1<<UPE)
#define DATA_OVERRUN (1<<DOR)

// USART Receiver buffer
#define RX_BUFFER_SIZE 128
char rx_buffer[RX_BUFFER_SIZE];

#if RX_BUFFER_SIZE <= 256
unsigned char rx_wr_index=0,rx_rd_index=0;
#else
unsigned int rx_wr_index=0,rx_rd_index=0;
#endif

#if RX_BUFFER_SIZE < 256
unsigned char rx_counter=0;
#else
unsigned int rx_counter=0;
#endif

// This flag is set on USART Receiver buffer overflow
bit rx_buffer_overflow;

// USART Receiver interrupt service routine
interrupt [USART_RXC] void usart_rx_isr(void)
{
char status,data;
status=UCSRA;
data=UDR;
if ((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN))==0)
   {
   rx_buffer[rx_wr_index++]=data;
#if RX_BUFFER_SIZE == 256
   // special case for receiver buffer size=256
   if (++rx_counter == 0) rx_buffer_overflow=1;
#else
   if (rx_wr_index == RX_BUFFER_SIZE) rx_wr_index=0;
   if (++rx_counter == RX_BUFFER_SIZE)
      {
      rx_counter=0;
      rx_buffer_overflow=1;
      }
#endif
   }
}

#ifndef _DEBUG_TERMINAL_IO_
// Get a character from the USART Receiver buffer
#define _ALTERNATE_GETCHAR_
#pragma used+
char getchar(void)
{
char data;
while (rx_counter==0);
data=rx_buffer[rx_rd_index++];
#if RX_BUFFER_SIZE != 256
if (rx_rd_index == RX_BUFFER_SIZE) rx_rd_index=0;
#endif
#asm("cli")
--rx_counter;
#asm("sei")
return data;
}
#pragma used-
#endif

// USART Transmitter buffer
#define TX_BUFFER_SIZE 128
char tx_buffer[TX_BUFFER_SIZE];

#if TX_BUFFER_SIZE <= 256
unsigned char tx_wr_index=0,tx_rd_index=0;
#else
unsigned int tx_wr_index=0,tx_rd_index=0;
#endif

#if TX_BUFFER_SIZE < 256
unsigned char tx_counter=0;
#else
unsigned int tx_counter=0;
#endif

// USART Transmitter interrupt service routine
interrupt [USART_TXC] void usart_tx_isr(void)
{
if (tx_counter)
   {
   --tx_counter;
   UDR=tx_buffer[tx_rd_index++];
#if TX_BUFFER_SIZE != 256
   if (tx_rd_index == TX_BUFFER_SIZE) tx_rd_index=0;
#endif
   }
}

#ifndef _DEBUG_TERMINAL_IO_
// Write a character to the USART Transmitter buffer
#define _ALTERNATE_PUTCHAR_
#pragma used+
void putchar(char c)
{
while (tx_counter == TX_BUFFER_SIZE);
#asm("cli")
if (tx_counter || ((UCSRA & DATA_REGISTER_EMPTY)==0))
   {
   tx_buffer[tx_wr_index++]=c;
#if TX_BUFFER_SIZE != 256
   if (tx_wr_index == TX_BUFFER_SIZE) tx_wr_index=0;
#endif
   ++tx_counter;
   }
else
   UDR=c;
#asm("sei")
}
#pragma used-
#endif

// Standard Input/Output functions
#include <stdio.h>

// Declare your global variables here
enum Stage {Q2,Q3};
enum Stage stage = Q2;

void parse_Q2(char ch){
    char buffer[32];
    lcd_clear();
    lcd_gotoxy(0,0);
    puts("\n\r"); 
    if(isdigit(ch)){
        sprintf(buffer,"data=%c and 10*data=%c%c",ch,ch,ch=='0'?0:'0');
        lcd_puts(buffer);
        puts(buffer);
    }
    else if(ch == 'H'){
        puts("Description is on LCD");
        lcd_puts("Hello From Micro Processor Lab");
    }  
    else if(ch == 'D'){
        puts("Deleted LCD!");
    }                        
    else if(ch == 'E'){
        stage = Q3;
        puts("Q2 is Over, starting Q3");
    }                
    else{
        sprintf(buffer,"input letter is %c%c%c",'"',ch,'"');
        lcd_puts(buffer);
        puts(buffer);
    }    
    
    
    
    
    
    puts("\n\r");
}

void parse_Q3(){
    char buffer[100];
    char length;
    char i;
    puts("Please Enter your data frame (must start with '(' and end with ')'\n\r");
    scanf("%s",buffer);
    length = strlen(buffer);   
    if(buffer[0] != '(' && buffer[length-1] != ')'){
        puts("Incorrect frame format, it's not between ( and )\n\r");
        return;
    }
    if(length != 7){
        puts("Incorrect frame size, it's not 5 characters\n\r");
        return;
    }        
    for(i=1;i<length-1;i++){
        if(!isdigit(buffer[i])){
            puts("Incorrect frame input, it's not 5 digits\n\r");
            return;
        }
    }
    lcd_clear();
    lcd_gotoxy(0,0);
    buffer[length-1] = 0;
    lcd_puts(buffer+1);
    puts("Correct frame, displayed on LCD\n\r");
        
}






void main(void)
{
// Declare your local variables here
char ch;

init_ports();
init_uart();
init_lcd();


// Global enable interrupts
#asm("sei")

puts("Starting Q2\n\r");

while (1)
{
      delay_ms(10);
      
      if(rx_counter == 0 && stage == Q2)
        continue;
      
      if(stage == Q2){
        ch = getchar(); 
        parse_Q2(ch);
      }
      
      
      
      if(stage == Q3)
        parse_Q3();
      
      }
}
