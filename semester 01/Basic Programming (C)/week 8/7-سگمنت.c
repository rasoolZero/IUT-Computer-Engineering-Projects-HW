#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{

    int segments[]={6,2,5,5,4,5,6,3,7,6};

    char input[12]={0};
    scanf("%s",input);
    int indexofe=strchr(input , 'e' ) - input;

    char part1[12]={0};
    char part2[12]={0};
    int index=0;
    int afterpoint=0;
    int checkingafterpoint=0;
    long long int output=0;

    for(int i = 0 ; i < indexofe ; i++){

        if(input[i]!='.'){
            output= output +segments[input[i]-48];
            index++;
            if(checkingafterpoint)
                afterpoint++;
        }
        else
            checkingafterpoint=1;

    }

    index=0;

    for(int i = indexofe+1 ; input[i]!=0 ; i++){
        part2[index]=input[i];
        index++;
    }


//    printf("part1 : %s , part2 : %s\nafter point : %d\n\n",part1,part2,afterpoint);

    long long int part2digit = atoll(part2);

    //for(int i = 0 ; i < part2-digitsafterpoint ; i++){
    output+= segments[0]*(part2digit-afterpoint);
    //}
    printf("%lld",output);
//

    return 0;;;
}
