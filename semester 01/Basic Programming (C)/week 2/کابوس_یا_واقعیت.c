#include <stdio.h>
#include <stdlib.h>

int main()
{
    double input;
    long long int n,tmp,r;
    long long int reversed = 0 ;

    scanf("%lf", &input);

    n=(long long int)input;
    tmp = n;


    if(n==input){
        while(n != 0)
        {
            r = n%10;
            reversed = reversed*10 + r;
            n /= 10;
        }
        if(reversed == tmp)
            puts("You will be safe");
        else
            puts("You will die");
    }


    else{
        double decimalSection = input - n ;


        while(n != 0)
        {
            r = n%10;
            reversed = reversed*10 + r;
            n /= 10;
        }

        double floated = (double)reversed;


        while((int)floated > 0){
            floated = floated / 10.0;
        }


//        printf("%lf\n" , decimalSection);
//        printf("%lf\n" , floated);

        if((float)decimalSection == (float)floated)
            puts("You will be safe");
        else
            puts("You will die");





    }
    return 0;
}
