#include <stdio.h>
#include <stdlib.h>
long long int fact(long long int in){
    if(in == 1)
        return 1;
    return in * fact(in-1);
}


int main()
{
    long long int input;
    scanf("%lld" , &input);
    printf("%lld", fact(input));
    return 0;
}
