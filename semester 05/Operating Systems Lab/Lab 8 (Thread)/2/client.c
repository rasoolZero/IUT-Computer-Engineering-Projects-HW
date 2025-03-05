#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#define BUFFSIZE 256

int createSocket(){
    int fd;
    if ( (fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) >= 0 )
        return fd;
    puts("error: socket creation failed");
    exit(EXIT_FAILURE);
}

struct sockaddr_in setupServerInformtion(char * ip, int port){
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr=inet_addr(ip);
    return serverAddress;
}
void runClient(int clientSocket,struct sockaddr_in * serverAddress){
    puts("connecting to server");
    if (connect(clientSocket,(struct sockaddr *)serverAddress,sizeof(*serverAddress))!=0){
        puts("error in connect");
        exit(EXIT_FAILURE);
    }
    char message[BUFFSIZE];
    while(1){
        printf("enter message to send to server: ");
        fflush(stdin);
        fgets(message,BUFFSIZE,stdin);
        fflush(stdin);
        message[strlen(message)-1] = 0;
        write(clientSocket,message,BUFFSIZE);
        if(!strcmp(message,"bye"))
            break;
    }
    close(clientSocket);
}


int main(int argc, char * args[]){
    int clientSocket = createSocket();
    struct sockaddr_in serverAddress = setupServerInformtion(args[1], atoi(args[2]));
    runClient(clientSocket, &serverAddress);
    return 0;
}
