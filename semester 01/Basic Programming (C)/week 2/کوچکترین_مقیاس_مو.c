#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int n ,m ;
    long long int GCF=1;
    long long int output;
    scanf("%lld%lld",&n,&m);

    long long int i;
    for(i=1; i <= n && i <= m; ++i)
    {
//        int isPrime = 1;
//        for(long int j = 2 ; j < i/2 ; j++){
//            if(i%j == 0 ){
//                isPrime = 0;
//                break;
//            }
//
//        }
        if(n%i==0 && m%i==0)
            GCF = i;
    }
    output = (n*m)/GCF;

    printf("%lld" , output);

    return 0;

}
