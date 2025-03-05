#include <mega16.h>
#include <stdio.h>
// Alphanumeric LCD functions
#include <alcd.h>

int current_angle = 0; 
int desired_angle; 
char counter = 0;

void motor_timer_routine(void){
static char port_value;
// Place your code here
if(desired_angle>current_angle){  
    switch(counter){
        case 0:
            port_value = 0b00110000; 
            break;
        case 1:
            port_value = 0b01100000;
            break; 
        case 2:
            port_value = 0b11000000;
            break;
        case 3:
            port_value = 0b10010000; 
            break;
    }
    current_angle++;  
    PORTB = (port_value)|(PORTB&0b00001111); 
    counter++;    
    if(counter == 4)
        counter = 0;    
}
else if(desired_angle<current_angle){    
    switch(counter){
        case 3:
            port_value = 0b00110000; 
            break;
        case 2:
            port_value = 0b01100000;
            break; 
        case 1:
            port_value = 0b11000000;
            break;
        case 0:
            port_value = 0b10010000; 
            break;
    }
    current_angle--;
    PORTB = (port_value)|(PORTB&0b00001111); 
    counter++;    
    if(counter == 4)
        counter = 0; 
}
else{
     PORTB =  (PORTB&0b00001111);
    }

}


void motor_push_routine(void){
desired_angle = PINA-128;
counter = 0;

}