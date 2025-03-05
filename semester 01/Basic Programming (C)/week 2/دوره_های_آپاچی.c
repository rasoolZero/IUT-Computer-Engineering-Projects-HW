#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long int input ;
    scanf("%lld" , &input);




    if(input == 1){
        puts("NO");
        return 0;
    }
    int isPrime = 1;
//    for(long long int i = 2 ; i < input/2 ; i++){
    for(long long int i = 2 ; i < (long long int)sqrt(input/2) ; i++){
        if(input%i == 0 ){
            isPrime = 0;
            break;
        }
    }






    if(isPrime)
        puts("Yes");
    else
        puts("No");


    return 0;
}
