#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int x;
    scanf("%d" , &x);

    int y = x/100;
    int m = x%100;

    if(y<10){
        printf("YEAR:0%d\n" , y);
    }
    else{
        printf("YEAR:%d\n" , y);
    }
    if(m<10){
        printf("MONTH:0%d" , m);
    }
    else{
        printf("MONTH:%d" , m);
    }






}
