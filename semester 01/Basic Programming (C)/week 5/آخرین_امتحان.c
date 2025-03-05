#include <stdio.h>
#define MAX 1000
//#define LL unsigned long long

int facAndCount(int bd , int input){

    //initializing
    int fac[MAX] = {1};
    fac[0]=1;
    int size = 1;


    //lets multiply
    while(bd!=1){


        int rem = 0;
        for(int i = 0 ; i < size; i++){
            int prod = fac[i] * bd + rem;
            fac[i]=prod%10;
            rem=prod/10;
        }
        while(rem){
            fac[size]=rem%10;
            rem/=10;
            size++;
        }


        bd--;

    }

    int counter = 0;
    for(int i = 0 ; i<size ; i++){
        int d = fac[i];
        if(d==input)
            counter++;
    }
    printf("%d",counter);
}


int main() {
    int birthdate,input;

    scanf("%d%d",&birthdate , &input);
    facAndCount(birthdate,input);




    return 0;;;
}
