 #include <stdio.h>
 #include <limits.h>
 #include <stdlib.h>
 #include <math.h>
 #define F long long
 #define LL long long

//arr1 : ratio , arr2 : weights , arr3 : values
void bubbleSort(float arr1[],F arr2[],F arr3[], LL n)
{
    LL i, j;
    for (i = 0; i < n-1; i++)
    for (j = 0; j < n-i-1; j++)
        if (arr1[j] < arr1[j+1]){
            float tmp;

            tmp = arr1[j];
            arr1[j]=arr1[j+1];
            arr1[j+1]=tmp;
            tmp = arr2[j];
            arr2[j]=arr2[j+1];
            arr2[j+1]=tmp;
            tmp = arr3[j];
            arr3[j]=arr3[j+1];
            arr3[j+1]=tmp;

        }
        else if(arr1[j] == arr1[j+1]){
            if (arr3[j] < arr3[j+1]){
                F tmp;

                tmp = arr1[j];
                arr1[j]=arr1[j+1];
                arr1[j+1]=tmp;
                tmp = arr2[j];
                arr2[j]=arr2[j+1];
                arr2[j+1]=tmp;
                tmp = arr3[j];
                arr3[j]=arr3[j+1];
                arr3[j+1]=tmp;

            }
            else if(arr3[j]== arr3[j+1]){
                if (arr2[j] > arr2[j+1]){
                    F tmp;

                    tmp = arr1[j];
                    arr1[j]=arr1[j+1];
                    arr1[j+1]=tmp;
                    tmp = arr2[j];
                    arr2[j]=arr2[j+1];
                    arr2[j+1]=tmp;
                    tmp = arr3[j];
                    arr3[j]=arr3[j+1];
                    arr3[j+1]=tmp;

                }
            }

        }
}


 int main()
 {

    LL capacity;
    LL numberOfStuff;

     while(scanf("%lld %lld",&numberOfStuff,&capacity) != EOF ){
//         for(unsigned long long i= 0 ; i<capacity*capacity ; i++){
////             printf("%lld\n\n",caculated[i]);
//         }
         LL sum=0;
         F weights[numberOfStuff];
         F values[numberOfStuff];
         float Ratio[numberOfStuff];
         for(LL i = 0 ; i < numberOfStuff ; i++){
             scanf("%lld",&weights[i]);
         }
         for(LL i = 0 ; i < numberOfStuff ; i++){
             scanf("%lld",&values[i]);
             if(weights[i]==0){
                Ratio[i]=LONG_MAX;
                continue;
             }
             Ratio[i]=values[i]/(float)weights[i];
         }

         bubbleSort(Ratio,weights,values,numberOfStuff);
//
//         for(LL i = 0 ; i < numberOfStuff ; i++){
//             printf("%lld\n\n",weights[i]);
//         }
//         for(LL i = 0 ; i < numberOfStuff ; i++){
//             printf("%lld\n\n",values[i]);
//         }
//         for(LL i = 0 ; i < numberOfStuff ; i++){
//             printf("%lld\n\n",Ratio[i]);
//         }

        for(LL i = 0 ; i <numberOfStuff ; i++){
            if(capacity<weights[i]){
                sum+=capacity*(values[i]/weights[i]);
                break;
//                printf("%d : capacity : %d\n",i,capacity);
            }
            else{
                sum+=values[i];
                capacity-=weights[i];
//                printf("%d full capa : sum : %d\n",i,sum);
            }
//            printf("final of %d : sum : %d\n",i,sum);
//            printf("final of %d : sum : %d\n",i,sum);
        }
        printf("%lld\n",sum);

//         printf("%lld\n",sack(capacity,values,weights,numberOfStuff,caculated));

     }


     return 0;;;
 }
