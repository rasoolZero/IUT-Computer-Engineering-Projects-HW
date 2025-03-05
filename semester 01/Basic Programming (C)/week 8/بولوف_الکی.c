#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    size_t n;
    scanf("%d",&n);

    int counter=0;
    getc(stdin);
    for(size_t i = 0 ; i < n ; i++){
        char firstLine[1000001]={0};
        char secLine[1000001]={0};
        size_t index=0;
        while(1){
            scanf("%c",&firstLine[index]);
            if(firstLine[index]=='\n'){
               firstLine[index]=0;
               break;
            }
            if(firstLine[index]!=' '){
                index++;
            }
        }
        index=0;
        while(1){
            scanf("%c",&secLine[index]);
            if(secLine[index]=='\n'){
               secLine[index]=0;
               break;
            }
            if(secLine[index]!=' '){
                index++;
            }
        }
        if(strcmp(firstLine,secLine)!=0){
            counter++;
//            printf("FLine : %s\n",firstLine);
//            printf("SLine : %s\n",secLine);
        }
    }

    printf("%d",counter);

    return 0;
}
