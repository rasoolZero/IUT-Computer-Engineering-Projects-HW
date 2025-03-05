#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <string.h>
int childCount;

typedef struct message{
    long long int Central;
    int ID;
    int newValue;
}message;
int parentToChild[10][2];
int childToParent[2];

void childProcess(int id){
    message m={};
    for(int i=0;i<childCount;i++){
        close(parentToChild[i][1]);
    }
    close(childToParent[0]);
    long long central;
    srand(getpid());
    while(1){
        read(parentToChild[id][0],&central,sizeof(central));
        int newValue = rand()%10;
        central*=10;
        central+=newValue;
        m.Central = central;
        m.ID=id;
        m.newValue=newValue;
        write(childToParent[1],&m,sizeof(m));
    }
}

void parentProcess(int children[]){
    for(int i=0;i<childCount;i++){
        close(parentToChild[i][0]);
    }
    close(childToParent[1]);
    long long central=1;
    while(1){
        for(int i=0;i<childCount;i++){
            write(parentToChild[i][1],&central,sizeof(central));
        }
        message m;
        for(int i=0;i<childCount;i++){
            read(childToParent[0],&m,sizeof(m));
            //printf("player %d played, added %d to the central value and the new central value is %lld\n",m.ID,m.newValue,m.Central);
            if(i==0){
                central=m.Central;
                printf("player %d played, added %d to the central value and the new central value is %lld\n",m.ID,m.newValue,m.Central);
                if(central%3==0){
                    printf("player %d won the game and central value is %lld\n",m.ID,m.Central);
                    for(int i=0;i<childCount;i++)
                        kill(children[i],SIGKILL);
                    exit(0);
                }
            }
        }
    }
}

int main(int argc, char * argv[]){
    if(argc==1){
        puts("please enter number of players");
        return 1;
    }
    childCount = atoi(argv[1]);
    for(int i=0;i<childCount;i++){
        pipe(parentToChild[i]);
    }
    pipe(childToParent);
    pid_t children[childCount];
    for(int i=0;i<childCount;i++){
        children[i]=fork();
        if(children[i]==0)
            childProcess(i);
    }
    parentProcess(children);
    
}
