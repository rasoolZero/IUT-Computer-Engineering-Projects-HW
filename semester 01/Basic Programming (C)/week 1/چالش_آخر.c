#include <stdio.h>
#include <stdlib.h>

int main()
{

    long long int a , b , c , d ,e;
    long long int tmp;
    scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);

    if(a>b){
        tmp = b;
        b=a;
        a = tmp;
    }
    if(b>c){
        tmp = c;
        c=b;
        b = tmp;
    }
    if(c>d){
        tmp = d;
        d=c;
        c = tmp;
    }
    if(d>e){
        tmp = e;
        e=d;
        d = tmp;
    }
    if(a>b){
        tmp = b;
        b=a;
        a = tmp;
    }
    if(b>c){
        tmp = c;
        c=b;
        b = tmp;
    }
    if(c>d){
        tmp = d;
        d=c;
        c = tmp;
    }
    if(d>e){
        tmp = e;
        e=d;
        d = tmp;
    }
    if(a>b){
        tmp = b;
        b=a;
        a = tmp;
    }
    if(b>c){
        tmp = c;
        c=b;
        b = tmp;
    }
    if(c>d){
        tmp = d;
        d=c;
        c = tmp;
    }
    if(d>e){
        tmp = e;
        e=d;
        d = tmp;
    }

//    printf("%d\n%d\n%d\n%d\n%d\n",a,b,c,d,e);


    int numUnique=5;

    if(a == b)
        numUnique--;
    if(b == c)
        numUnique--;
    if(c == d)
        numUnique--;
    if(d == e)
        numUnique--;

    if( numUnique%2==0 ){
        printf("NULL");
    }
    else{
//        if(a==b){
//            if(b==c){
//                printf("%d",d);
//            }
//            else if(c==d){
//                printf("%d",c);
//            }
//            else{
//                printf("%d",c);
//            }
//        }
//        else if(b==c){
//            printf("%d",b);
//        }
//        else{
//            printf("%d",c);
//        }
        if(b==c){
            printf("%lld",d);
        }
        else{
            printf("%lld",c);
        }
    }


    return 0;
}
