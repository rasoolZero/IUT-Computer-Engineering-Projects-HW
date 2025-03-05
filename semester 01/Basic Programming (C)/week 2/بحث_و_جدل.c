#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int output = 1;
    long long int n;
    scanf("%lld" , &n);

//    if( n ==0 ){
//        puts("1");
//        return 0;
//    }

    while(output <= n){
        output*=2;
    }
    printf("%lld" , output);

    return 0;


}
