#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    long long int input;
    long long int sum=0;



    scanf("%lld", &input);

    for(long long int i = 1 ; i < input ; i++){

//        int isPrime = 1;
//        for(long long int j = 2 ; j < (int)sqrt(i) ; j++){
//            if(i%j == 0 ){
//                isPrime = 0;
//                break;
//            }
//        }
        if( input%i == 0)
            sum+=i;
    }
    if(sum == input)
        puts("Yea babe");
    else
        puts("No my dear");


    return 0;
}
