#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    long long int x;

    long long int curoot;

    scanf("%lld" , &x);


    curoot=round(pow(x, 1.0/3.0));

    if(curoot*curoot*curoot==x){
        printf("Yes");
    }
    else{
        printf("No");
    }

}

