/*
 * GccApplication2.c
 *
 * Created: 12/26/2021 10:05:39 PM
 * Author : sepis
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

double stateTime[13];
int defaultStateTime[13] = {30, 30, 30, 70, 5, 30, 32, 9, 89, 55, 55, 55, 367};

double statwRiseVolts[13];
int defaultStatwRiseVolts[13] = {1, 0, -1, 0, -3, 6, -6, 3, 0, 1, 0, -1, 0};


char state = 0;
char volt = 50;
int count = 0;
ISR(TIMER0_OVF_vect)
{
	volt += statwRiseVolts[state];
	count++;
	if (count >= (int)stateTime[state])
	{
		state++;
		count = 0;
		if(state >= 13){
			state = 0;
		}
	}
	PORTB = volt;
}


/*
* T0 = 1ms --> T = 1/256 ms --> f = 256khz
* if f_micro = 2Mhz --> N = 2*1024/256 = 8
*/
int main(void)
{
	
	DDRB = 0xFF;	// portB as output
	TCNT0 = 0;		// initial timer0 by zero
	TIMSK = (1 << TOIE0);	// timer0 interrupt enable
	sei();					// enable interrupts
	TCCR0 = 0x02;	// N = 8 --> f = f_micro/8, mode = normal

	
	while(1);
	return 1;
}