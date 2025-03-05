#include <stdio.h>
#include <stdlib.h>
#define ULL unsigned long long

int main()
{
    ULL input;
    scanf("%llu" , &input);
    int out = input%9;
    if(out==0)
        out=9;
    printf("%d",out);
    return 0;
}
