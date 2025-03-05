#include "types.h"
#include "stat.h"
#include "user.h"

void __attribute__((optimize("O0"))) childProcess(){
    int pid = getpid();
    printf(1,"child (PID:%d) is alive\n",pid);
    unsigned long long sum=0;
    for(int i=0;i<1000000;i++)
        for(int j=0;j<1000000;j++)
            sum+=(i+j);
    printf(1,"child (PID:%d) is done\n",pid);
    exit();
}

int main(){
    int ppid=getpid();
    printf(1,"Parent (PID:%d) running\n",ppid);
    for(int i=0;i<5;i++){
        int pid = fork();
        if(pid==0)
            childProcess();
    }
    for(int i=0;i<5;i++)
        wait();
    printf(1,"## parent exiting\n");
    exit();
}
