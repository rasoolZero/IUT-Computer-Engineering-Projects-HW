#include <stdio.h>
#include <stdlib.h>

int main()
{


    unsigned long long key , tmp;
    int numberOfTests;
    int nezamScore=0,shirScore=0,keyvoonScore=0;
    scanf("%d" ,&numberOfTests);
    int parts = numberOfTests/19;
    int indexOfAnswer=0;
    int keyvoon[]={3,3,1,1,2,2};
    int nezam[]={1,2,3};
    int shir[]={2,1,2,3};



    for(int i = 0 ; i < parts+1 ; i++){
    scanf("%19llu" , &key);
//    printf("key : %llu\n",key);
    tmp = key;
    key=0;
    int counter = 0;
    while(tmp!=0){
        int digit = tmp%10;
        tmp/=10;
        key=key*10+digit;
        counter++;
    }
//    printf("%lld" ,key
    int module;
    while(key!=0){
        int correctAnswer = key%10;
        key/=10;


        module = indexOfAnswer%6;
        if(keyvoon[module]==correctAnswer)
            keyvoonScore++;

        module = indexOfAnswer%4;
        if(shir[module]==correctAnswer)
            shirScore++;

        module = indexOfAnswer%3;
        if(nezam[module]==correctAnswer)
            nezamScore++;

    indexOfAnswer++;
//        printf(" correct Answer : %d\n" , correctAnswer);
    }
//    printf(" keyvoon Score : %d\n" , keyvoonScore);
//    printf(" nezam Score : %d\n" , nezamScore);
//    printf(" shirfarhad Score : %d\n" , shirScore);

    }

    int maxScore = 0;
    if(keyvoonScore>maxScore)
        maxScore = keyvoonScore;
    if(nezamScore>maxScore)
        maxScore = nezamScore;
    if(shirScore>maxScore)
        maxScore = shirScore;

    printf("%d\n" , maxScore);

    if(keyvoonScore == maxScore)
        puts("keyvoon");
    if(nezamScore == maxScore)
        puts("nezam");
    if(shirScore == maxScore)
        puts("shir farhad");
    return 0;;;
}
