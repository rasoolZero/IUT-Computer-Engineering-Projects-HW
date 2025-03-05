#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    long long int x ,tmpX ,rightSide = 0;

    scanf("%lld",&x);
    int lastDigit=x%10;
    rightSide=lastDigit;
    int digit=0;
    tmpX=x/10;
    int isPos = 0;
    int numberOfDigits=1;

    while(tmpX>0){


        digit = tmpX%10;
        tmpX=tmpX/10;
        if(digit<lastDigit){
            isPos = 1;
            break;
        }
        lastDigit = digit;
        long long int powered = 1;
        for(int i = 0 ; i < numberOfDigits ; i++){
            powered*=10;
        }
        rightSide += lastDigit*powered;
        numberOfDigits++;
    }
//    printf("right side : %lld" , rightSide);
//    printf("digit : %d" , digit);

    if(!isPos){
        printf("0");
        return 0 ;
    }
    long long int rightTemp = rightSide;
    int recordToSwap=10;
    while(rightTemp != 0){
        int digitToCheck = rightTemp%10;
        rightTemp/=10;
        if(digitToCheck>digit){
            if(digitToCheck < recordToSwap){
                recordToSwap = digitToCheck;
            }
        }
        else{
            continue;
        }
    }

//    printf("recordToSwap : %d\n" , recordToSwap);

    long long int leftSide = x;
    leftSide = x - rightSide;
    long long int powered = 1;
    for(int i = 0 ; i < numberOfDigits ; i++){
        powered*=10;
    }
    leftSide-= digit*powered;


    long long int newRightSide = 0;
    rightTemp = rightSide;
    int isSwaped=0;
    int NOD = 0;
    while(rightTemp != 0){

        int digitToCheck = rightTemp%10;
        rightTemp/=10;

        powered = 1;
        for(int i = 0 ; i < NOD ; i++){
            powered*=10;
        }

        if(digitToCheck == recordToSwap && (!isSwaped)){
            newRightSide += digit * powered;
            isSwaped = 1;
        }
        else{
            newRightSide += digitToCheck * powered;
        }

        NOD++;
    }





    long long int number = newRightSide;
    long long int sorted = 0;
    long long int digits = 10;
    long long int sortedDigits = 1;
    int first = 1;

    while (number > 0) {
        int digit = number % 10;

        if (!first) {

            int tmp = sorted;
            int toDivide = 1;
            for (int i = 0; i < sortedDigits; i++) {
                int tmpDigit = tmp % 10;
                if (digit >= tmpDigit) {
                    sorted = sorted/toDivide*toDivide*10 + digit*toDivide + sorted % toDivide;
                    break;
                } else if (i == sortedDigits-1) {
                    sorted = digit * digits + sorted;
                }
                tmp /= 10;
                toDivide *= 10;
            }
            digits *= 10;
            sortedDigits += 1;
        } else {
            sorted = digit;
        }

        first = 0;
        number = number / 10;
    }
    long long int sortedNewRightSide = sorted;






    powered = 1;
    for(int i = 0 ; i < numberOfDigits ; i++){
        powered*=10;
    }
    long long int finalResult = leftSide + recordToSwap*powered + sortedNewRightSide;
    printf("%lld" , finalResult);




    return 0;;;
}
