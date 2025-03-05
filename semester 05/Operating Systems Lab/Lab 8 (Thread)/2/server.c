#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <pthread.h>
#define MAXCLIENT 5
#define BUFFSIZE 256
int createSocket(){
    int fd;
    if ( (fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) >= 0 )
        return fd;
    puts("error: socket creation failed");
    exit(EXIT_FAILURE);
}
void bindSocketTCP(int serverSocket){
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(6000);
    serverAddress.sin_addr.s_addr=inet_addr("127.0.0.1");
    if ( bind(serverSocket, (const struct sockaddr *)&serverAddress,sizeof(serverAddress)) >= 0 )
        return;
    puts("error: bind failed");
    exit(EXIT_FAILURE);
}

void * serverThread(void * args){
    int clientSocket = (int) args;
    while(1){
        char message[BUFFSIZE];
        read(clientSocket,message,BUFFSIZE);
        printf("message recieved: %s\n",message);
        if(!strcmp(message,"bye"))
            break;
    }
    close(clientSocket);
    return 0;
}

void runServer(int serverSocket){
    puts("listening");
    listen(serverSocket,MAXCLIENT);
    struct sockaddr_in clientAddress;
    int clientSocket,addressSize=sizeof(clientAddress);
    while(1){
        puts("waiting for client");
        clientSocket = accept(serverSocket,(struct sockaddr *)& clientAddress,&addressSize);
        if(clientSocket<0){
            puts("error: accpet");
            continue;
        }
        pthread_t thread;
        pthread_create(&thread,NULL,serverThread,(void *)clientSocket);
    }
}

int main(){
    int serverSocket = createSocket();
    bindSocketTCP(serverSocket);
    runServer(serverSocket);
    return 0;
}

