#include <stdio.h>
#include <stdlib.h>

int main()
{

    float sum;
    float mult;
    float a,b,c,d,e;


    scanf("%f%f%f%f%f",&a,&b,&c,&d,&e);

    sum=a+b+c+d+e;
    mult=a*b*c*d*e;

//    float numbers[5];
//    for(int i =0 ; i <5 ; i++){
//        scanf("%f",numbers+i);
//    }
//
//
//    for(int i =0 ; i <5 ; i++){
//        sum+=numbers[i];
//        mult*=numbers[i];
//    }

    printf("SUM: %.2f\n" , sum );
    printf("PRD: %.2f\n" , mult);
    printf("AVG: %.2f" , sum/(5));

}
