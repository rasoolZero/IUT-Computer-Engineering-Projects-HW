#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int input;
    long long int a1=1;
    long long int a2=1;
    long long int tmp;

    scanf("%lld" , &input);

    for(int i = 1 ; i < input - 1; i++){
        tmp = a1;
        a1 = a2;
        a2 = a1 + tmp;


    }
    printf("%lld" , a2);



    return 0;
}
