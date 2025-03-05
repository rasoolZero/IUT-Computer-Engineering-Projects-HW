#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void childProcess(){
    printf("message from child %d\n",getpid());
    exit(EXIT_SUCCESS);
}
void loop(){
    pid_t pid = fork();
    if(pid==0)
        childProcess();
    else
        wait(NULL);
    sleep(2);
}
int main(){
    while(1)
        loop();
    
    return 0;
}
