#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n=1;
    int x,k;
    scanf("%d%d%d",&n,&x,&k);
    x--;

    char channels[101][101]={{0}};

    for(int i= 0 ; i < n ; i++){
        scanf("%s",&channels[i]);
    }

    int result=(x+k)%n;
    printf("%s",channels[result]);

    return 0;
}
