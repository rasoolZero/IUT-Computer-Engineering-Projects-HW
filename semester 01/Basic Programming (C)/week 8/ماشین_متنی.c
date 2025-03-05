#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void strcpyn(char* s1,const char* s2,size_t n){
    size_t index=0;
    for(size_t i = n ; s2[i]!=0 ; i++){
        s1[index] = s2[i];
        index++;
    }
}

int main()
{

    char mainstring[1025]={0};
    char operetion[1025]={0};
    int index=0;

    while(1){
        scanf("%c",&mainstring[index]);
        if(mainstring[index]=='\n'){
            mainstring[index]=0;
            break;
        }
        index++;
    }

    while( 1 ){
        index=0;
        while(1){
            scanf("%c",&operetion[index]);
            if(operetion[index]=='\n'){
                operetion[index]=0;
                break;
            }
            index++;
        }

        if(operetion[0]=='x'){
//            printf("%s",mainstring);
            return 0;
        }
        else if(operetion[0]=='>'){
            int leng = strlen(mainstring);
            if(leng!=0){
                char subOp[1025]={0};
                strcpyn(subOp,operetion,1);
                int numToShift = atoi(subOp);
                char result[1025]={0};
                for(int i = 0 ; mainstring[i]!=0; i++){
                    result[(i+numToShift)%leng]=mainstring[i];
                }
                strcpy(mainstring,result);
            }
            printf("%s\n",mainstring);

        }
        else if(operetion[0]=='<'){
            int leng = strlen(mainstring);
            if(leng!=0){
                char subOp[1025]={0};
                strcpyn(subOp,operetion,1);
                int numToShift = atoi(subOp);
                int trueNumToShift=numToShift%leng;
                char leftPart[1025]={0};
                char rightPart[1025]={0};

                strncpy(leftPart,mainstring,trueNumToShift);
                strcpyn(rightPart,mainstring,trueNumToShift);

                strcpy(mainstring,rightPart);
                strcat(mainstring,leftPart);

            }
            printf("%s\n",mainstring);

        }
        else if(operetion[0]=='+'){
            int leng = strlen(mainstring);
            for(int i = 1 ; operetion[i]!=0; i++){
                mainstring[leng+i-1]=operetion[i];
            }
            printf("%s\n",mainstring);
        }
        else if(operetion[0]=='*'){
            char subOp[1025]={0};
            strcpyn(subOp,operetion,1);
            int numToCat = atoi(subOp);
            char result[1025]={0};
            if(numToCat==0){
                 memset(mainstring,'\0',1025);
            }
            else{
                for(int i = 0 ; i < numToCat; i++){
                    strcat(result,mainstring);
                }
            }
            strcpy(mainstring,result);
//            int leng=strlen(mainstring);
//            printf("%d",leng);
            printf("%s\n",mainstring);
        }

        else if(operetion[0]=='-'){
//            int leng = strlen(mainstring);
            char subOp[1025]={0};
            strcpyn(subOp,operetion,1);

            char* CP = strstr(mainstring,subOp);
            if(CP!=NULL){
                int subLeng=strlen(subOp);

                for(int i = CP-mainstring ; mainstring[i]!=0; i++){
                    mainstring[i]=mainstring[i+subLeng];
                }
            }

            printf("%s\n",mainstring);
        }
//        memset(operetion,'\0',1025);



    }


    return 0;
}
