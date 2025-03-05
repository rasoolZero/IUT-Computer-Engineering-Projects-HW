#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <signal.h>
#define MAXCHILD 5
#define MAXIMUM 100
int fd;
pid_t ppid;
pid_t children[MAXCHILD];
void setupPipe(){
    if (mkfifo("2.pipe", 0777) == -1) {
        puts("mkfifo error");
        exit(EXIT_FAILURE);
    }
    fd=open("2.pipe",O_RDWR);
    if(fd<0){
        puts("opening pipe error");
        exit(EXIT_FAILURE);
    }
}

void readNumberFromPipeAndUpdateTotal(int * total){
    int number;
    read(fd,&number,sizeof(number));
    *total+=number;
    printf("parent read %d , total: %d\n",number,*total);
}

void killChildrenAndClose(){
    for(int i=0;i<MAXCHILD;i++)
        kill(children[i],SIGKILL);
    close(fd);
    system("rm 2.pipe > /dev/null");
    exit(0);
}

void handler(int signo){
    static int total=0;
    if(signo==SIGUSR1)
        readNumberFromPipeAndUpdateTotal(&total);
    if(total>=MAXIMUM)
        killChildrenAndClose();
}

void sleepAndSendNumberToParent(int t,int i){
    printf("child %d sleeping for %d seconds\n",i,t);
    sleep(t);
    write(fd,&t,sizeof(t));
    printf("child %d writing %d and signaling parent\n",i,t);
    kill(ppid,SIGUSR1);
}

void childProcess(int i){
    srand(getpid());
    while(1)
        sleepAndSendNumberToParent(rand()%10,i);
}

void setupHandler(){
    struct sigaction action = {};
    action.sa_handler = handler;
    sigaction(SIGUSR1,(struct sigaction *) &action,NULL);
}

int main(){
    setupPipe();
    ppid = getpid();
    setupHandler();
    for(int i=0;i<MAXCHILD;i++)
        if((children[i]=fork())==0)
            childProcess(i);
    while(1);
    return 0;
}
