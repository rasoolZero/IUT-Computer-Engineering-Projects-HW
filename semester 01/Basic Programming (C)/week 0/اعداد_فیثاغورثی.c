#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    scanf("%d%d%d" , &a ,&b ,&c );

    if( a*a==b*b+c*c || b*b==a*a+c*c || c*c==a*a+b*b ){
        printf("YES");
    }
    else{
        printf("NO");
    }

    return 0;
}
