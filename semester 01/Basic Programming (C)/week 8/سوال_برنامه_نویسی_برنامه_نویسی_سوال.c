#include <stdio.h>
#include <stdlib.h>

void operation(int i){

    char input[1000];

    if(i!=0){

        scanf("%s",input);
        operation(i-1);
        printf("%s ",input);

    }
    return ;
}

int main()
{
    int n;
    scanf("%d",&n);
    operation(n);


    return 0;
}
