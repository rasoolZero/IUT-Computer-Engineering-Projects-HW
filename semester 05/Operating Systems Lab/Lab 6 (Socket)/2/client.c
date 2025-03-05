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

struct sockaddr_in setupServerInformtion(){
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(6000);
    serverAddress.sin_addr.s_addr=inet_addr("127.0.0.1");
    return serverAddress;
}

twoNumbers prepareNumbers(){
    twoNumbers data;
    data.a=rand()%10000;
    data.b=rand()%10000;
    printf("numbers to send are : %d , %d\n",data.a,data.b);
    return data;
}

void runClient(int clientSocket,struct sockaddr_in * serverAddress){
    twoNumbers dataToSend = prepareNumbers();
    int result,addressSize = sizeof(*serverAddress);
    puts("sending message to server");
    sendto(clientSocket,&dataToSend,sizeof(dataToSend),MSG_CONFIRM,(const struct sockaddr *)serverAddress,addressSize);
    puts("waiting for respond");
    recvfrom(clientSocket,&result,sizeof(result),MSG_WAITALL,(struct sockaddr *)serverAddress,&addressSize);
    printf("result recieved: %d\n",result);
}


int main(){
    srand(getpid());
    int clientSocket = createSocket();
    struct sockaddr_in serverAddress = setupServerInformtion();
    runClient(clientSocket,&serverAddress);
    return 0;
}
