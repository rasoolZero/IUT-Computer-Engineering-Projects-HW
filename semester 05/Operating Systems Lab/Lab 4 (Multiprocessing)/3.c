#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/time.h>
#include <errno.h>
#include <time.h>

char * getExecutablePath(){
    static char path[1024];
    printf("Enter path to the executable (e.g. /bin/ls) [1024 chars]:");
    fflush(stdin);
    fgets(path,1024,stdin);
    path[strlen(path)-1]=0;
    fflush(stdin);
    return path;
}
char * getArguments(){
    static char args[1024];
    printf("Enter arguments[1024 chars]:");
    fflush(stdin);
    fgets(args,1024,stdin);
    args[strlen(args)-1]=0;
    fflush(stdin);
    return args;
}
char ** stringToArray(char * arguments,char * execPath){
    static char * args[128];
    args[0] = (char *) calloc(strlen(execPath)+1,1);
    strcpy(args[0],execPath);
    char * token;
    int index = 1;
    token = strtok(arguments," ");
    while(token && index<128){
        args[index] = (char *) calloc(strlen(token)+1,1);
        strcpy(args[index],token);
        token = strtok(NULL," ");
        index++;
    }
    args[index]=NULL;
}
char ** prepareArguments(){
    char * exe = getExecutablePath();
    char * args = getArguments();
    return stringToArray(args,exe);
}
void freeArgArray(char * args[]){
    for(int i=0;args[i];i++)
        free(args[i]);
}
void childProcess(char * argsArray[]){
    if(execv(argsArray[0],argsArray)==-1){ //execution was not successful
        printf("ERROR : %s\n",strerror(errno));
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
void calculateAndPrintTime(const struct timeval start,char * path){
    struct timeval end;
    gettimeofday(&end,NULL);
    char tmbuf1[64],tmbuf2[64];
    long long int executionTime = (end.tv_sec-start.tv_sec)*1000+(end.tv_usec-start.tv_usec)/1000;
    struct tm * nowtm = localtime(&start.tv_sec);
    strftime(tmbuf1, 64, "%Y-%m-%d", nowtm);
    strftime(tmbuf2, 64, "%H:%M", nowtm);
    puts("----------------------------------------------------------");
    printf("## %-20s %-20s %-20s %-20s\n","Date","Time","Exec Time(msec)","Path");
    printf("## %-20s %-20s %-20lld %-20s\n",tmbuf1,tmbuf2,executionTime,path);
    puts("----------------------------------------------------------");
}
void logTime(int starting,char * path){
    static struct timeval start;
    if(starting)
        gettimeofday(&start,NULL);
    else
        calculateAndPrintTime(start,path);
}
void loop(){
    char ** argsArray = prepareArguments();
    logTime(1,NULL);
    if(fork()==0)
        childProcess(argsArray);
    wait(NULL);
    logTime(0,argsArray[0]);
    freeArgArray(argsArray);
}
int main(){
    while(1)
        loop();
	return 0;
}
