#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>

int createSocket(){
    int fd;
    if ( (fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) >= 0 )
        return fd;
    puts("error: socket creation failed");
    exit(EXIT_FAILURE);
}

struct sockaddr_in setupServerInformtion(){
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(6000);
    serverAddress.sin_addr.s_addr=inet_addr("127.0.0.1");
    return serverAddress;
}
char * getData(int clientSocket,int * fileSize){
    char fileAddress[] = "test.txt";
    puts("sending file address to server");
    write(clientSocket,fileAddress,sizeof(fileAddress));
    puts("getting data from server");
    read(clientSocket,fileSize,sizeof(*fileSize));
    char * data = (char *)calloc(*fileSize,1);
    read(clientSocket,data,*fileSize);
    return data;
}
void createAndWriteFile(char * data,int fileSize){
    puts("creating and writing client_cpy file");
    FILE * file = fopen("client_cpy","w");
    fwrite(data,1,fileSize,file);
    fclose(file);
}
void runClient(int clientSocket,struct sockaddr_in * serverAddress){
    puts("connecting to server");
    if (connect(clientSocket,(struct sockaddr *)serverAddress,sizeof(*serverAddress))!=0){
        puts("error in connect");
        exit(EXIT_FAILURE);
    }
    int fileSize;
    char * data = getData(clientSocket,&fileSize);
    createAndWriteFile(data,fileSize);
    free(data);
}


int main(){
    int clientSocket = createSocket();
    struct sockaddr_in serverAddress = setupServerInformtion();
    runClient(clientSocket, &serverAddress);

    return 0;
}
