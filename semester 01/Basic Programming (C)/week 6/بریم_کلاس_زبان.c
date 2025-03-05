#include <stdio.h>
#include <stdlib.h>
int to2(int x){
    int result = 1;
    while(x>0){
        result*=2;
        x--;
    }
    return result;
}

int main()
{
    int counter = 0;
    char input[21]={0};
    scanf("%s",input);

    for(int i = 0 ; i < 20 ;i++ ){
        char c = input[i];
        if(c=='L' || c=='F' || c=='D' || c=='T')
            counter++;
    }

    printf("%d",to2(counter));
    return 0;
}
