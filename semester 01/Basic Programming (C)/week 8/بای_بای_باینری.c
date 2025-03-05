#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char firstPart[1000000*2]={0};
    char tempPart[1000000*2]={0};
    firstPart[0]='1';

    int L,R;
    scanf("%d%d",&L,&R);
    while(firstPart[R+1]==0){
        strcpy(tempPart,firstPart);
        for(int i = 0 ; i < 100000*2 ; i++){
            if(tempPart[i]==0)
                break;

            if(tempPart[i]=='1')
                tempPart[i]='0';
            else if(tempPart[i]=='0')
                tempPart[i]='1';
        }
        strcat(firstPart,tempPart);
    }
//    printf("%s",firstPart);
    for(int i = L ; i <= R ; i++)
        printf("%c",firstPart[i-1]);


    return 0;
}
