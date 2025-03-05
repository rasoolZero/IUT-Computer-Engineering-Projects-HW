#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#define MAXCHILD 5
#define PIPE 2.pipe
int fd;
void setupPipe(){
    if (mkfifo("PIPE", 0777) == -1) {
        puts("mkfifo error");
        puts(strerror(errno));
        exit(EXIT_FAILURE);
    }
    fd=open("PIPE",O_RDWR);
    if(fd<0){
        puts("open pipe in parent error");
        puts(strerror(errno));
        exit(EXIT_FAILURE);
    }
    int number=MAXCHILD-1;
    write(fd,&number,sizeof(number));
}
void childStartUp(int id){
    srand(getpid());
    int timeToSleep=rand()%10+1;
    printf("child %d starts, sleeping for %d\n",id,timeToSleep);
    sleep(timeToSleep);
}
int getAndUpdateSyncNumber(int id){
    int number;
    if(read(fd,&number,sizeof(number))<0){
        puts(strerror(errno));
        return -1;
    }
    printf("child %d pipevalue: %d\n",id,number);
    if(number==id && number)
        number--;
    write(fd,&number,sizeof(number));
    return number;
}
void childProcess(int id){
    childStartUp(id);
    while(getAndUpdateSyncNumber(id))
        sleep(1);
    printf("child %d reached the point\n",id);
    exit(EXIT_SUCCESS);
}
int main(){
    setupPipe();
    for(int i=0;i<MAXCHILD;i++)
        if(fork()==0)
            childProcess(i);
    for(int i=0;i<MAXCHILD;i++)
        wait(0);
    close(fd);
    puts("The program finished successfully");
    system("rm PIPE > /dev/null");
    return 0;
}
