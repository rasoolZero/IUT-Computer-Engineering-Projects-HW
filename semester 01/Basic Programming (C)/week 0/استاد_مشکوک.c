#include <stdio.h>
#include <math.h>

int main()
{
    printf("\n");

    float a,b,c;

    scanf("%f\n%f\n%f",&a,&b,&c);

    if(a==0 && b==0){
        printf("IMPOSSIBLE");
        return 0;
    }

    if(a==0){
        float x = -(c/b);
        if(x==-0)
            x=0;
        printf("%.3f" , x);
        return 0;
    }
    if(b==0){
        float delta = -(4*a*c);
        if(delta<0){
            printf("IMPOSSIBLE");
        }
        else if(delta == 0){
            float x = 0.000;
            printf("%.3f" , x);
        }
        else{
            float x1 = (sqrt(delta))  /  (2*a);
            float x2 = (-1*sqrt(delta))  /  (2*a);
            if(x1<x2){
                printf("%.3f\n%.3f",x1,x2);
            }
            else{
                printf("%.3f\n%.3f",x2,x1);
            }
        }
        return 0;
    }


    float delta = (b*b)-(4*a*c);

    if(delta<0){
        printf("IMPOSSIBLE");
        return 0;
    }
    else if(delta == 0){
        float x = (-1*b)/(2*a);
        printf("%.3f" , x);
        return 0;
    }
    else{
        float x1 = (-b+sqrt(delta))  /  (2*a);
        float x2 = (-b-sqrt(delta))  /  (2*a);
        if(x1<x2){
            printf("%.3f\n%.3f",x1,x2);
            return 0;
        }
        else{
            printf("%.3f\n%.3f",x2,x1);
            return 0;
        }
    }
        return 0;
}
