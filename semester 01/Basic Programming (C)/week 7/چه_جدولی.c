#include <stdio.h>
#include <stdlib.h>
#define LL long long


int main()
{
    int m,n;
    scanf("%d%d",&n,&m);
    int width=m;
    int height=n;


    LL table[m*n];

    for(int i = 0 ; i < height; i++)
        for(int j = 0 ; j < width ; j++)
            scanf("%lld",&table[j*height+i]);

    LL counter = 0;

    for(int i = 1 ; i < height-1; i++)
        for(int j = 1 ; j < width-1 ; j++){
            LL index = j*height+i;
            LL ntc=table[index];
            if(ntc > table[j*height+i+1] && ntc > table[j*height+i-1] && ntc < table[(j-1)*height+i] && ntc < table[(j+1)*height+i] ||
               ntc < table[j*height+i+1] && ntc < table[j*height+i-1] && ntc > table[(j-1)*height+i] && ntc > table[(j+1)*height+i]
               )
                counter++;
        }
    printf("%lld",counter);


    return 0;;;
}
