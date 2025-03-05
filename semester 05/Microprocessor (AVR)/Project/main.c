#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdlib.h>


// last state of PORTC
char C0LastState=1;
char C1LastState=1;
char C2LastState=1;
char C3LastState=1;
char C4LastState=1;

typedef struct Point{
	char x;
	char y;
}Point;
Point snake[65];
Point fruit;
char length;
enum Dir{UP,DOWN,LEFT,RIGHT};
typedef enum Dir Dir;
enum Scene{MENU,GAME,DEAD};
typedef enum Scene Scene;
enum Difficulty{EASY,HARD};
typedef enum Difficulty Difficulty;
const char PORT[8] = {1, 2, 4, 8, 16, 32, 64, 128};
char characterIndex=0;
Scene scene;
Difficulty diff;
Dir moving,inputDir;
char updateCounter=0;
void updateMovingDirection(){
	if(moving==UP && inputDir==DOWN)
	return;
	if(moving==DOWN && inputDir==UP)
	return;
	if(moving==LEFT && inputDir==RIGHT)
	return;
	if(moving==RIGHT && inputDir==LEFT)
	return;
	moving=inputDir;
}
void updateHead(){
	if(moving==UP)
	snake[0].y--;
	if(moving==DOWN)
	snake[0].y++;
	if(moving==LEFT)
	snake[0].x--;
	if(moving==RIGHT)
	snake[0].x++;
}
void updateSnake(){
	for(int i=length-1;i>0;i--)
	snake[i]=snake[i-1];
	updateHead();
}

void pickRandomFruit(){
	static Point possiblePoints[64];
	int index=0;
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++){
		char found=0;
		for(int k=0;k<length;k++)
		if(snake[k].x==i && snake[k].y==j){
			found=1;
			break;
		}
		if(!found){
			possiblePoints[index].x=i;
			possiblePoints[index].y=j;
			index++;
		}
	}
	fruit = possiblePoints[rand()%index];
}

char checkIfHeadOutOfBoundries(){
	if(snake[0].x<0 || snake[0].x>=8 || snake[0].y<0 || snake[0].y>=8)
		return 1;
	return 0;
}
char checkHeadCollidedWithBody(){
	for(int i=1;i<length;i++)
		if(snake[0].x==snake[i].x && snake[0].y==snake[i].y)
			return 1;
	return 0;
}
void checkForDeath(){
	if(length>=64 || checkHeadCollidedWithBody() || checkIfHeadOutOfBoundries())
		scene=DEAD;
}
void checkCollectedFruit(){
	if(snake[0].x == fruit.x && snake[0].y == fruit.y){
		snake[length].x = snake[length-1].x;
		snake[length].y = snake[length-1].y;
		length++;
		pickRandomFruit();
	}
}
void updateDifficulty(){
	if(inputDir == LEFT)
		diff=EASY;
	else if(inputDir == RIGHT)
		diff=HARD;
}

void setup(){
	snake[0].x = 1;
	snake[0].y = 4;
	snake[1].x = 0;
	snake[1].y = 4;
	length = 2;
	moving=inputDir=RIGHT;
	diff=HARD;
	scene=MENU;
	updateCounter=0;
	characterIndex=0;
	pickRandomFruit();
}

enum Characters{G,A,M,E,O,V,R,H};
typedef enum Characters Characters;
static const unsigned char ALPHA[8][8]={
	{0b00011100,0b01011110,0b11001011,0b11000011,0b11000011,0b11000011,0b01111110,0b00111100},
	{0,0b01111111,0b11111111,0b11001100,0b11001100,0b11001100,0b11111111,0b01111111},
	{0b11111111,0b11111111,0b01100000,0b01110000,0b01110000,0b01100000,0b11111111,0b11111111},
	{0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111},
	{0b01111110,0b11111111,0b11000011,0b11000011,0b11000011,0b11000011,0b11111111,0b01111110},
	{0b11100000,0b11111100,0b00011110,0b00000011,0b00000011,0b00011110,0b11111100,0b11100000},
	{0b01111001,0b11111011,0b11011111,0b11011110,0b11011100,0b11011000,0b11111111,0b11111111},
	{0,0b11111111,0b11111111,0b00011000,0b00011000,0b00011000,0b11111111,0b11111111}
};

void drawDead() {
	static Characters gameover[8] = {G, A, M, E, O, V, E, R};
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 8; j++) {
			PORTA = PORT[j]; // ROW
			PORTB = ~ALPHA[gameover[characterIndex]][j]; // COLOMN
			_delay_us(500);
		}
	}
	characterIndex++;
	if(characterIndex==8)
		characterIndex=0;
}
void drawGame(){
	char matrix[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	for (int i = 0; i < length; i++) {
		matrix[7-snake[i].x] |= (1<<(7-snake[i].y));
	}
	matrix[7-fruit.x] |= (1 << (7-fruit.y));
	for (int j = 0; j < 8; j++) {
		PORTA = PORT[j];
		PORTB = ~matrix[j];
		_delay_us(500);
	}
}
void drawMenu(){
	if (diff == HARD) {
		for (int j = 0; j < 8; j++) {
			PORTA = PORT[j]; // ROW
			PORTB = ~ALPHA[H][j]; // COLOMN
			_delay_us(500);
		}
	}
	else if (diff == EASY) {
		for (int j = 0; j < 8; j++) {
			PORTA = PORT[j];
			PORTB = ~ALPHA[E][j]; // maybe add a ~ to ALPHA
			_delay_us(500);
		}
	}
}
void draw(){
	if(scene==DEAD)
		drawDead();
	if(scene==GAME)
		drawGame();
	if(scene==MENU)
		drawMenu();
}



ISR(TIMER1_OVF_vect)
{
	// Reinitialize Timer 1 value
	TCNT1H=0xBDC >> 8;
	TCNT1L=0xBDC & 0xff;
	// Place your code here
	if(scene==GAME){
		updateCounter++;
		if( (updateCounter==1 && diff==HARD) || (updateCounter==2 && diff==EASY) ){
			updateCounter=0;
			updateMovingDirection();
			updateSnake();
			checkCollectedFruit();
			checkForDeath();
		}
	}
}

void inputKey(void){

	if(!(PINC & (1 << 4)) && C4LastState != 0){
		if(scene == MENU)
			scene = GAME;
		else if(scene == DEAD)
			setup();
		
	}
	if(!(PINC & (1)) && C0LastState != 0){
		// UP
		inputDir = UP;
	}

	if(!(PINC & (1 << 1)) && C1LastState != 0){
		// RIGHT
		inputDir = RIGHT;
	}

	if(!(PINC & (1 << 2)) && C2LastState != 0){
		// LEFT
		inputDir = LEFT;
	}

	if(!(PINC & (1 << 3)) && C3LastState != 0){
		// DOWN
		inputDir = DOWN;
	}

	C0LastState = PINC & 1;
	C1LastState = PINC & (1 << 1);
	C2LastState = PINC & (1 << 2);
	C3LastState = PINC & (1 << 3);
	C4LastState = PINC & (1 << 4);
	
}

int main(void)
{
	// Declare your local variables here

	// Input/Output Ports initialization
	// Port A initialization
	// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out
	DDRA=(1<<DDA7) | (1<<DDA6) | (1<<DDA5) | (1<<DDA4) | (1<<DDA3) | (1<<DDA2) | (1<<DDA1) | (1<<DDA0);
	// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0
	PORTA=(0<<7) | (0<<6) | (0<<5) | (0<<4) | (0<<3) | (0<<2) | (0<<1) | (0<<0);

	// Port B initialization
	// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out
	DDRB=(1<<DDB7) | (1<<DDB6) | (1<<DDB5) | (1<<DDB4) | (1<<DDB3) | (1<<DDB2) | (1<<DDB1) | (1<<DDB0);
	// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0
	PORTB=(0<<7) | (0<<6) | (0<<5) | (0<<4) | (0<<3) | (0<<2) | (0<<1) | (0<<0);

	// Port C initialization
	// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In
	DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
	// State: Bit7=T Bit6=T Bit5=T Bit4=P Bit3=P Bit2=P Bit1=P Bit0=P
	PORTC=(0<<7) | (0<<6) | (0<<5) | (1<<4) | (1<<3) | (1<<2) | (1<<1) | (1<<0);

	// Timer/Counter 1 initialization
	// Clock source: System Clock
	// Clock value: 125.000 kHz
	// Mode: Normal top=0xFFFF
	// OC1A output: Disconnected
	// OC1B output: Disconnected
	// Noise Canceler: Off
	// Input Capture on Falling Edge
	// Timer Period: 0.5 s
	// Timer1 Overflow Interrupt: On
	// Input Capture Interrupt: Off
	// Compare A Match Interrupt: Off
	// Compare B Match Interrupt: Off
	TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
	TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (1<<CS11) | (1<<CS10);
	TCNT1H=0x0B;
	TCNT1L=0xDC;
	ICR1H=0x00;
	ICR1L=0x00;
	OCR1AH=0x00;
	OCR1AL=0x00;
	OCR1BH=0x00;
	OCR1BL=0x00;
	
	// Timer(s)/Counter(s) Interrupt(s) initialization
	TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (1<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);

	// Global enable interrupts
	sei();
	setup();
	while (1)
	{
		inputKey();
		if(scene == MENU)
			updateDifficulty();
		draw();
	}
	return 0;
}