#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define LL long long

int n;

LL max(LL a ,LL b){
    if(a>b)
        return a;
    return b;
}

LL runAndMax(int i,int j,LL matrix[],LL caculated[]){

    if(i==0 && j==0){
//        printf("for i:0 j:0  :  %lld\n",matrix[0]);
        return  matrix[0];
    }



    if(i==0){
        int index=(j-1)*n+i;
        if(caculated[index]){
//            printf("for i:%d j:%d  :  caculated : %lld\n",i,j,caculated[index]+matrix[j*n+i]);
            return caculated[index]+matrix[j*n+i];
        }
        LL x = runAndMax(i,j-1,matrix,caculated);
        caculated[index]=x;
//        printf("for i:%d j:%d  :  %lld\n",i,j,x+matrix[j*n+i]);
        return x+matrix[j*n+i];
    }



    if(j==0){
        int index =j*n+i-1;
        if(caculated[index]){
//            printf("for i:%d j:%d  :  caculated : %lld\n",i,j,caculated[index]+matrix[j*n+i]);
            return caculated[index]+matrix[j*n+i];
        }
        LL x = runAndMax(i-1,j,matrix,caculated);
        caculated[index]=x;
//        printf("for i:%d j:%d  :  %lld\n",i,j,x+matrix[j*n+i]);
        return x+matrix[j*n+i];
    }




    LL xj,xi;
    int index1=(j-1)*n+i,index2=j*n+i-1;
    if(caculated[index1])
        xj=caculated[index1];
    else{
        xj = runAndMax(i,j-1,matrix,caculated);
        caculated[index1]=xj;
    }
    if(caculated[index2])
        xi=caculated[index2];
    else{
        xi=runAndMax(i-1,j,matrix,caculated);
        caculated[index2]=xi;
    }
//    printf("for i:%d j:%d  :  %lld\n",i,j,matrix[j*n+i]+max(xi,xj));
    return matrix[j*n+i] + max(xi,xj);

}


int main()
{
    int testcases;
    scanf("%d",&testcases);
    while(testcases){
        scanf("%d",&n);
        if(n==0){
            printf("0");
            testcases--;
            continue;
        }
        LL matrix[n*n];
        LL caculated[101*101]={0};
        for(int i = 0; i < n * n ; i++){
            scanf("%lld" ,&matrix[i]);
        }
        printf("%lld\n",runAndMax(n-1,n-1,matrix,caculated));
        testcases--;
    }


//    char str1[] = "abc\0";
//    char str2[] = "abe\0";
//    printf("%d",strcmp(str1,str2));
    return 0;;;
}
