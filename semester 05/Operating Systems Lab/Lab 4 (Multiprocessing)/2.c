#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/time.h>
#define MAXCHILD 4
#define SECONDS 1000

void sleepCPUabuser(unsigned int seconds){
    struct timeval start,now;
    gettimeofday(&start,NULL);
    while(1){
        gettimeofday(&now,NULL);
        int elapsed = now.tv_sec - start.tv_sec;
        if(elapsed >= seconds)
            return;
    }
}
int waitForSometime(){
    int secondsToWait = rand()%SECONDS+1;
    //sleep(secondsToWait);
    sleepCPUabuser(secondsToWait);
    return secondsToWait;
}
void childProcess(){
    srand(getpid());
    printf("### message from child %d, waited for %d seconds\n",getpid(),waitForSometime());
    exit(EXIT_SUCCESS);
}
void createNewChild(pid_t * child){
    *child = fork();
    if(*child == 0) // this is a child process
        childProcess();
}
void checkForDeadChild(pid_t * child){
    int childStatus = waitpid(*child,NULL,WNOHANG);
    printf("PID:%d\t",*child);
    if(childStatus == 0){// child is still alive
        puts("alive");
        return;
    }
    puts("dead, creaing new child");
    createNewChild(child);
    
}
void checkChild(pid_t * child){
    if((*child)==0)
        createNewChild(child);
    checkForDeadChild(child);
}
void loop(){
    static pid_t childs[MAXCHILD] = {};
    for(int i=0;i<MAXCHILD;i++){
        printf("# Checking child number %d\t",i);
        checkChild(childs+i);
    }
    puts("");
    sleep(5);
}
int main(){
    while(1)
        loop();
    return 0;
}
