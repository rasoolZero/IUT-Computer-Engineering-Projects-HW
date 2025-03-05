#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k,state=1;
    scanf("%d%d",&n,&k);
    long long counter=0;

    while(1){
        counter++;
        state=(state+k)%n;
        if(state==0)
            state=n;

        if(state==1)
            break;
    }


    printf("%lld",counter);
    return 0;
}
