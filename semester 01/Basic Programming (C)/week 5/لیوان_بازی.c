#include <stdio.h>

int main() {
    int moves;
    char state,first,sec;
    scanf("%d %c ",&moves,&state);
    for(int i=0;i<moves;i++){
        scanf("%c %c ",&first,&sec);
        if(first == state)
            state = sec;
        else if(sec == state)
            state = first;
    }
    printf("%c",state);
    
    return 0;;;
}