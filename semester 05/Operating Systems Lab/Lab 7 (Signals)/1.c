#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#define MAX_TRY 5
void handler(int signo){
    static int counter=0;
    if(signo==SIGINT){
        counter++;
        printf(" # SIGINT recieved,counter: %d\n",counter);
        if(counter>=MAX_TRY)
            exit(0);
    }
}
void setupHandler(){
    struct sigaction action = {};
    action.sa_handler = handler;
    sigaction(SIGINT,(struct sigaction *) &action,NULL);
}
int main(){
    setupHandler();
    while(1);
    return 0;
}
