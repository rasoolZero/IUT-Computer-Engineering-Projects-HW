#include <avr/io.h>

void setLights(char counter){
	if(counter==1){
		PORTC=0b00100001;
		PORTD=0b00001001;
		return;
	}
	if(counter==2){
		PORTC=0b00100010;
		PORTD=0b00001001;
		return;
	}
	if(counter==3){
		PORTC=0b00001100;
		PORTD=0b00001001;
		return;
	}
	if(counter==4){
		PORTC=0b00010100;
		PORTD=0b00001001;
		return;
	}
	if(counter==5){
		PORTC=0b01100100;
		PORTD=0b00001000;
		return;
	}
	if(counter==6){
		PORTC=0b10100100;
		PORTD=0b00001000;
		return;
	}
	if(counter==7){
		PORTC=0b00100100;
		PORTD=0b00000011;
		return;
	}
	if(counter==8){
		PORTC=0b00100100;
		PORTD=0b00000101;
		return;
	}
}
int main(void)
{
	DDRC=0xFF;
	DDRD=0x0F;
	DDRB &= ~(1<<0);
	char counter=1;
    /* Replace with your application code */
    while (1) 
    {
		setLights(counter);
		TCCR0 = 0x07;
		if(counter%2==1){
			TCNT0 = (char) -200;
		}
		else{
			TCNT0 = -40;
		}
		while((TIFR&0x01) == 0);
		TCCR0 = 0;
		TIFR = 1<<TOV0;
		counter++;
		if(counter==9)
			counter=1;
    }
}

