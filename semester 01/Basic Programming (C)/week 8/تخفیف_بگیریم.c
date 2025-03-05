#include <stdio.h>
#include <stdlib.h>


int contain(char sub[],int c){

    int flag=0;

    for(int j = 0 ; sub[j]!=0; j++){
        if(sub[j]==c){
            flag=1;
            break;
        }
    }

    return flag;

}

int main()
{

    int n = 0;
    char sample[101] = {0};
    scanf("%d %s",&n,sample);

    char sub[101]={0};
    int lastindex=0;
    for(int i = 0 ; sample[i]!=0 ; i++){
        int flag=0;

        for(int j = 0 ; sub[j]!=0; j++){
            if(sub[j]==sample[i] )
                flag=1;
        }

        if(!flag){
            sub[lastindex] = sample[i];
            lastindex++;
        }


    }
    //printf("%s",sub);


    for(int k = 0 ; k < n ; k++){

        char input[101]={0};

        scanf("%s",input);



        int flag=0;
        for(int i = 0 ; input[i]!=0 ;i++){

            flag =contain(sub,input[i]);

            if(!flag)
                break;

        }
        int flag2=0;
        for(int i = 0 ; sub[i]!=0 ;i++){

            flag2 =contain(input,sub[i]);

            if(!flag2)
                break;

        }



        if(flag&&flag2)
            puts("Yes");
        else
            puts("No");

    }



    return 0;
}
