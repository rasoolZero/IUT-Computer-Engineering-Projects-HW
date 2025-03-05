#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

//    int T=o,X=1,A=2,M=3,N=4;

    char TTop[6]="*****";
    char TMiddle[6]="oo*oo";
    char XTop[6]="*ooo*";
    char XMiddle[6]="oo*oo";
    char ATop[6]="oo*oo";
    char AMiddle[6]="o***o";
    char NTop[6]="*ooo*";
    char NMiddle[6]="*o*o*";
    char MTop[6]="**o**";
    char MMiddle[6]="*o*o*";

    char firstLine[101]={0};
    char secLine[101]={0};
    scanf("%s\n%s",firstLine,secLine);

    char top[6]={0};
    char middle[6]={0};
    for(int i = 0 ; firstLine[i*5]!=0 ; i++){
        int index = i*5;
        top[0]=firstLine[index];
        top[1]=firstLine[index+1];
        top[2]=firstLine[index+2];
        top[3]=firstLine[index+3];
        top[4]=firstLine[index+4];
        middle[0]=secLine[index];
        middle[1]=secLine[index+1];
        middle[2]=secLine[index+2];
        middle[3]=secLine[index+3];
        middle[4]=secLine[index+4];


        if(strcmp(TTop , top) == 0 && strcmp(TMiddle,middle) == 0)
            printf("T");

        if(strcmp(XTop , top) == 0 && strcmp(XMiddle,middle) == 0)
            printf("X");

        if(strcmp(ATop , top) == 0 && strcmp(AMiddle,middle) == 0)
            printf("A");

        if(strcmp(NTop , top) == 0 && strcmp(NMiddle,middle) == 0)
            printf("N");

        if(strcmp(MTop , top) == 0 && strcmp(MMiddle,middle) == 0)
            printf("M");

    }




    return 0;
}
