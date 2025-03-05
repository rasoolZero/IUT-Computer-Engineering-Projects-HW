#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void shift(char text[]){
    for(int i = 0 ; i < 100*30 ; i++){
        if(text[i] != ' ' && text[i]!= '\0'){
            text[i] = (char)(((((int)text[i]+1)-97)%26 )+97);
        }
    }
}
int check (char text[]){
    char substring[] = "zozagtoor";
    return strstr(text,substring)!=NULL;
}


int main()
{
    char inputtext[100*31]={0};
    int i = 0;
    while(scanf("%c",&inputtext[i])!=EOF){
        i++;
    }


    for( int i = 0 ; i < 100*31 ; i++)
        if( !( (inputtext[i] <= 122 && inputtext[i] >= 97 ) || inputtext[i] == ' ' ) )
            inputtext[i]=0;
//    inputtext[i-1]='\0';
//    scanf("%s",inputtext);
    while(1){

        shift(inputtext);
        if(check(inputtext))
            break;
    }

    for( int i = 0 ; i < 100*31 ; i++)
        if(inputtext[i] == '`')
            inputtext[i]=0;

    printf("%s\n",inputtext);


    return 0;;;
}
