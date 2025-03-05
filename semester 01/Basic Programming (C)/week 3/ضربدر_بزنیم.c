#include <stdio.h>
#include <stdlib.h>

int main()
{

    long long int n;
    scanf("%lld" , &n);

    if(n==1){
        printf("#");
        return 0;
    }

    for(long long int i = 0 ;i < n ; i++){
        printf("#");
    }





    printf("\n");
    for(long long int i = 1 ;i < n-1 ; i++){
        printf("#");

        long long int index1 = i;
        long long int index2 = (n-2)-i+1;
        if(index1 > index2){
            long long int tmp = index1;
            index1 = index2;
            index2 = tmp;
        }
        for(long long int j = 1 ;j < n-1 ; j++){

            if(j>=index2){
                printf("#");
            }
            else{
                if(j != index1){
                    if(j==i){
                        printf("#");
                    }
                    else{
                        printf(" ");
                    }
                }
                else{
                    printf("#");
                }
            }

        }
        printf("#\n");


    }




    for(long long int i = 0 ;i < n ; i++){
        printf("#");
    }



    return 0;;;
}
