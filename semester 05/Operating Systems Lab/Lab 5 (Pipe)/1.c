#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#define MAXCHILD 6
#define MAXIMUM 100
void sendNumber(int pipe,int pid){
    int number=rand()%11;
    printf("child %d sending %d\n",pid,number);
    write(pipe,&number,sizeof(number));
}
void childProcess(int fd[2]){
    int pid=getpid();
    close(fd[0]);
    srand(pid);
    while(1){
        sendNumber(fd[1],pid);
        sleep(rand()%3+1);
    }
}

void readNumber(int pipe,int * total){
    int number;
    if(read(pipe,&number,sizeof(number))<=0)
        return;
    (*total)+=number;
    printf("parent reading %d, total:%d\n",number,*total);
}

void killChildren(int children[MAXCHILD]){
    for(int i=0;i<MAXCHILD;i++)
        kill(children[i],SIGKILL);
}
void parentProcess(int fd[2],int children[MAXCHILD]){
    close(fd[1]);
    int total=0;
    while(total<MAXIMUM)
        readNumber(fd[0],&total);
    printf("total:%d, killing children\n",total);
    killChildren(children);
}
int main(){
    int fd[2]={};
    int children[MAXCHILD]={};
    pipe(fd);
    for(int i=0;i<MAXCHILD;i++)
        if((children[i]=fork())==0)
            childProcess(fd);
    parentProcess(fd,children);
    return 0;
}
