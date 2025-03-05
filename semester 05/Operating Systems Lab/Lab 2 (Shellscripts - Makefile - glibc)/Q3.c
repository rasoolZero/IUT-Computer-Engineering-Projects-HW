 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	int v1,v2;
	char prefix[256]={};
	char fileAddress[1024]={};
	char command[3000]={};
	puts("please enter v1:");
	scanf("%d",&v1);
	puts("please enter v2:");
	scanf("%d",&v2);
	getchar();
	puts("please enter prefix[maximum 255 character]:");
	fgets(prefix, 256, stdin);
	prefix[strlen(prefix)-1]=0;
	puts("please enter file address[maximum 1023 character]:");
	fgets(fileAddress, 1024, stdin);
	fileAddress[strlen(fileAddress)-1]=0;
	for(int i=v1;i<=v2;i++){
		sprintf(command,"useradd -m %s-%d",prefix,i);
//		puts(command);
		system(command);
		sprintf(command,"cp %s /home/%s-%d/",fileAddress,prefix,i);
//		puts(command);
		system(command);
		printf("user %s-%d added and %s has been copied to its home directory\n",prefix,i,fileAddress);
	}
	return 0;

}
