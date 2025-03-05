#include <avr/io.h>

int main(void)
{
	char sec=0,min=0,hour=0;
	DDRB &= ~(1<<0);
	DDRA=0xFF;
	DDRC=0xFF;
	DDRD=0xFF;
    while (1) 
    {
		TCNT0 = -60;
		TCCR0 = 0X06;
		while((TIFR&(1<<TOV0)) == 0);
		TIFR = (1<<TOV0);
		TCCR0=0;
		sec++;
		if(sec==60){
			sec=0;
			min++;
		}
		if(min==60){
			min=0;
			hour++;
		}
		if(hour==24)
			hour=0;
		PORTA=sec;
		PORTC=min;
		PORTD=hour;
    }
}