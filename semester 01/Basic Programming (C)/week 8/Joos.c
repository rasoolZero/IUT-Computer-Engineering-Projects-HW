#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LL long long int

int main()
{
    char a[1001]={0};
    char b[1001]={0};
//    char c[2000001]={0};
    scanf("%s %s",b,a);

//    puts("Test");

    LL aleng = strlen(a);
    LL bleng = strlen(b);
//    while(strlen(c) < aleng*2 )
//        strcat(c,b);
//
//    if(strstr(b,a) != NULL)
//        printf("Yes");
//    else
//        printf("No");



    LL possible=0;
    for(LL i = 0 ; b[i]!=0 ;i++){
        possible=0;
        if(b[i]==a[0]){
            LL flag=1;
            for(LL j = 0 ; a[j]!=0 ; j++){
                if(a[j]!=b[(j+i)%bleng]){
                    flag=0;
                    break;
                }
            }
            if(flag)
                possible=1;
        }
        if(possible)
            break;
    }
    if(possible)
        puts("Yes");
    else
        puts("No");


    return 0;
}
