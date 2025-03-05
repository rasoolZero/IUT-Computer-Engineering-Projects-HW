#include <mega16.h>
#include <stdio.h>
#include <alcd.h>
int timer0counter = 0;
char ms,s,m,h;
char clock[16];

bit start = 0;

void chronometer_timer_routine(void){
if(!start)
    return;
timer0counter++;
if(timer0counter!=10)
    return;
timer0counter=0;
    ms++;
     if(ms==100){
        ms=0;
        s++;
        if(s==60){
            s=0;
            m++;
            if(m==60){
                m=0;
                h++;
                if(h==24)
                    h=0;
                
            }
        }
     }
    sprintf(clock,"%02d:%02d:%02d:%02d",h,m,s,ms);
    lcd_clear();
    lcd_puts(clock);    


}


void chronometer_push_routine(void){
if (!PINB.1){
start=1;
}
if (!PINB.0){
if(start==0)
    timer0counter = ms = s = m = h = 0;
start = 0;
    sprintf(clock,"%02d:%02d:%02d:%02d",h,m,s,ms);
    lcd_clear();
    lcd_puts(clock);    

}    

}