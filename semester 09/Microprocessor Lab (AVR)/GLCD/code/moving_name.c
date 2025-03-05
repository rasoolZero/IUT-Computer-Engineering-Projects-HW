#include <mega16.h>
#include <font.h>
#include <delay.h>
void show_name(void){
        static  char offset = 0;
        char n,j;
        
            for ( n = 0; n < 50; n++) 
            {
              for ( j = 0; j < 8; j++) {
                PORTA = R_data[j];      // ROW
                PORTB = ~RK[(j+offset)%16]; // COLUMN
                delay_us(500);
              }
              
              PORTD.7 = !PORTD.7;
              for ( j = 0; j < 8; j++) {
                PORTA = R_data[j];      // ROW
                PORTB = ~RK[(j+offset+8)%16]; // COLUMN
                delay_us(500);
              } 
              PORTD.7 = !PORTD.7;
            }
            offset++;
}