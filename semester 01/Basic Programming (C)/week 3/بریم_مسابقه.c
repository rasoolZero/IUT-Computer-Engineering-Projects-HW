#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int p,q,r,s,t,u;

        while(scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u) != EOF){
////            if( p*exp(0)+q*sin(0)+r*cos(0)+s*tan(0)+t*pow(0,2)+u < 0 || p*exp(-1)+q*sin(1)+r*cos(1)+s*tan(1)+t*pow(1,2)+u > 0  ){
////                printf("No solution\n");
////                continue;
////            }
            double first = 0;
            double last = 1;
            double x = (first+last)/2.0;
            double minToCheck =p*exp(-first)+q*sin(first)+r*cos(first)+s*tan(first)+t*pow(first,2)+u;
            double maxToCheck =p*exp(-last)+q*sin(last)+r*cos(last)+s*tan(last)+t*pow(last,2)+u;
            if(maxToCheck<minToCheck){
                double tmp = minToCheck;
                minToCheck = maxToCheck;
                maxToCheck = tmp;
            }
            if( 0 < minToCheck || 0 > maxToCheck ){
                printf("No solution\n");
                continue;
            }

            for (int i = 0 ; i < 100 ; i++) {
                double toFind = p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*pow(x,2)+u;
                if (toFind > 0)
                    first = x;
                else
                    last = x;

                x = (first+last)/2;
            }
            printf("%0.4lf\n",x);
//            if (first > last)
                // NOT FOUND!!;



        }
    return 0;;;
}
