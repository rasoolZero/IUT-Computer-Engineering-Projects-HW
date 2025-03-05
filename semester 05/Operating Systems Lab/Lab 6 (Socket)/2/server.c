#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>


typedef struct twoNumbers{
    int a;
    int b;
}twoNumbers;

int createSocket(){
    int fd;
    if ( (fd = socket(AF_INET, SOCK_DGRAM, 0)) >= 0 )
        return fd;
    puts("error: socket creation failed");
    exit(EXIT_FAILURE);
}
void bindSocketUDP(int serverSocket){
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(6000);
    serverAddress.sin_addr.s_addr=inet_addr("127.0.0.1");
    if ( bind(serverSocket, (const struct sockaddr *)&serverAddress,sizeof(serverAddress)) >= 0 )
        return;
    puts("error: bind failed");
    exit(EXIT_FAILURE);
}

void runServer(int serverSocket){
    struct sockaddr_in clientAddress;
    twoNumbers dataRecieved;
    while(1){
        puts("waiting for client message");
        int addressLength = sizeof(clientAddress);
        recvfrom(serverSocket,&dataRecieved,sizeof(dataRecieved),MSG_WAITALL,(struct sockaddr*)&clientAddress,&addressLength);
        int result = dataRecieved.a+dataRecieved.b;
        puts("result sent to client");
        sendto(serverSocket,&result,sizeof(result),MSG_CONFIRM,(struct sockaddr*)&clientAddress,addressLength);
    }
}

int main(){
    int serverSocket = createSocket();
    bindSocketUDP(serverSocket);
    runServer(serverSocket);
    return 0;
}
