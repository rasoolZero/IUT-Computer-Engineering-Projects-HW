#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long int numberOfInput;
    scanf("%lld" , &numberOfInput);

    for (int i = 0 ; i < numberOfInput ; i++){
        long long int remDays , remMin;
        scanf("%lld" , &remDays);
        remMin = remDays *24*60;

        remMin = sqrt((double)remMin);

        remDays = remMin/24/60;

        remDays = remDays%7;

        switch(remDays){
        case 0:
            puts("Sunday");
            break;
        case 1:
            puts("Monday");
            break;
        case 2:
            puts("Tuesday");
            break;
        case 3:
            puts("Wednesday");
            break;
        case 4:
            puts("Thursday");
            break;
        case 5:
            puts("Friday");
            break;
        case 6:
            puts("Saturday");
            break;

        }




    }

    return 0;;;
}
