#include <avr/io.h>
#include <avr/interrupt.h>
char i=0;
ISR(TIMER0_OVF_vect)
{
	OCR0 = sinewave[i];
	if(i>21){i=0;}
	else {i++;}
}
int main(void)
{
	DDRB = 0xFF;
	TCCR0 = 0x6C;
	TIMSK = (1 << TOIE0);
	TCNT0 = 0;
	OCR0 = 256;
	sei();
	while(1);
	return 1;
}