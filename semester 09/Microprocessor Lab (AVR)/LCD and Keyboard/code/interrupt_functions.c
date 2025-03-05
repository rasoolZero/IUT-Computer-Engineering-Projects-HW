#include <mega16.h>
#include <delay.h>
#include <alcd.h>
#include <string.h> 
#include <ctype.h>
#include "commons.h"


extern enum MODES global_mode;
extern enum CASE global_case;

char string[33]="";
char stringIndex = 0;

char keypad(void)
{               
     char row[4]={0x10,0x20,0x40,0x80};
     char key=100,r,c;
     for (r=0;r<4;r++)
     {
         PORTB=row[r]; //row= 0x10,0x20,0x40,0x80
         c=20;
         delay_ms(10);
         if (PINB.0==1) c=0;
         if (PINB.1==1) c=1;
         if (PINB.2==1) c=2;
         if (PINB.3==1) c=3;
         if (!(c==20)){
             key=(r*4)+c;
             PORTB=0xf0;
             while (PINB.0==1) {}
             while (PINB.1==1) {}
             while (PINB.2==1) {}
             while (PINB.3==1) {}
         }
         PORTB=0xf0;
     }
     return key;

}


void display_char(char ch){
    if (ch == 0)
        return;
    lcd_clear();     
    lcd_gotoxy(0,0);
    if(stringIndex==33){
        memset(string,0,33);
        stringIndex=1;
    }
    
    string[stringIndex-1] = ch;
    lcd_puts(string);
}

extern int counter;


// this function will return the coressponding character based on pressed key
// if the key is a controll key (number, letter, up case, down case) it will return 0
char process_key(char key){
    static char last_key_pressed = -1;
    static char index = 0;
    const static char numbers[]=  {'1','2','3',0,
                            '4','5','6',0,
                            '7','8','9',0,
                            '#','0','*',0};
    const static char * alphbets[]= {"abc","def","ghi","",
                                    "jkl","mno","pqr","",
                                    "stu","vwx","yz","",
                                    "#"," ","*",""}; 
    if (key%4 == 3){
        if (key==3)
            global_mode = NUMBER;
        if (key==7)
            global_mode = LETTER;
        if (key==11)
            global_case = UP;
        if (key==15)
            global_case = DOWN;
        return 0;
    }
    
    if (global_mode == NUMBER){
        stringIndex++;  
        return numbers[key];
    }
    if (global_mode == LETTER){
        if(counter <= 3 && last_key_pressed==key){
            index++;
            index%=strlen(alphbets[key]);
        }
        else{
            index = 0;
            stringIndex++;
        }
        last_key_pressed = key;
        counter = 0;
        if(global_case==UP){
            return toupper(alphbets[key][index]);
        }   
        return alphbets[key][index];
        
    }
    
    
}