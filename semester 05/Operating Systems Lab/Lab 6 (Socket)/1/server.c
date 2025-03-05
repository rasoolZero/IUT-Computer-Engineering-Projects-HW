#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
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

int getFileSize(FILE* file){
    fseek(file,0,SEEK_END);
    int size = ftell(file);
    rewind(file);
    return size;
}

char * openFile(char * fileAddress,int * fileSize){
    FILE* file = fopen(fileAddress,"r");
    *fileSize = getFileSize(file);
    char * data = (char *)calloc(*fileSize,1);
    fread(data,1,*fileSize,file);
    fclose(file);
    return data;
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
        char fileAddress[BUFFSIZE];
        int fileSize;
        puts("getting file address");
        read(clientSocket,fileAddress,BUFFSIZE);
        char * fileData = openFile(fileAddress,&fileSize);
        puts("sending file data");
        write(clientSocket,&fileSize,sizeof(fileSize));
        write(clientSocket,fileData,fileSize);
        free(fileData);
    }
}

int main(){
    int serverSocket = createSocket();
    bindSocketTCP(serverSocket);
    runServer(serverSocket);
    return 0;
}

