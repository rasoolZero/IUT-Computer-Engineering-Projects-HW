
#include "init_functions.h"
#include "interrupt_functions.h"
#include "commons.h"

#include <mega16.h>

// Alphanumeric LCD functions
#include <alcd.h>
#include <delay.h>

// Declare your global variables here  
enum MODES global_mode;
enum CASE global_case;

// External Interrupt 1 service routine
interrupt [EXT_INT1] void ext_int1_isr(void)
{
    char key, ch;
    PORTC.0 = ~PORTC.0;
    key = keypad();
    ch = process_key(key);
    display_char(ch);
}

int counter = 0;


void main(void)
{

init_port();
init_interrupt();

// Declare your local variables here


lcd_init(16);

// Global enable interrupts
#asm("sei")

while (1)
      {
        delay_ms(100);
        counter+=1;

      }
}
