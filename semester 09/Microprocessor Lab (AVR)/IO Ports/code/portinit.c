#include <mega16.h>
#include <delay.h>

void initialPorts(void){
DDRA=0x00;
PORTA=0xff;

DDRB=0xff;
PORTB=0x00;

DDRC=0xff;
PORTC=0x00;

DDRD=0x0f;
PORTD=0xf0;
}

char isPD7Pressed(void){
    static char PD7state = 1;
    if (!(PIND & 0b10000000) && (PD7state)){
        PD7state = 0;
        return 1;
    }
    if (PIND & 0b10000000 && !PD7state) PD7state = 1;
    return 0;
}

char isPD6Down(void){
    return !(PIND & 0b01000000);
}       
                     
void updatePortB(void){
    PORTB = PINA;
}
void updatePortD(unsigned char digit1,unsigned char digit2,unsigned char digit3,unsigned char digit4){
    PORTD = (0b11110000 & PORTD) | 0b00000001; 
    PORTC = digit3 | 0b10000000;  
    delay_ms(2);  
                             
    PORTD = (0b11110000 & PORTD) | 0b00000010; 
    PORTC = digit2;   
    delay_ms(2);  
        
    PORTD = (0b11110000 & PORTD) | 0b00000100; 
    PORTC = digit1; 
    delay_ms(2);  
        
    PORTD = (0b11110000 & PORTD) | 0b00001000; 
    PORTC = digit4; 
    delay_ms(2);  
}