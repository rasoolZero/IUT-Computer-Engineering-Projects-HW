#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numberoforders ;
    int caps=0;
    char input[5];
    scanf("%d\n",&numberoforders);
    for(int i = 0 ; i < numberoforders ; i++){
        scanf("%s\n",&input);
        if(input[0]=='C'){
            caps=!caps;
            continue;
        }
        else{
            if(caps){
                printf("%c",input[0]-32);
            }
            else{
                printf("%c",input[0]);
            }
        }
    }
    return 0;
}
