#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define SIZE 8
int stride;
int A[SIZE];
void setupNumbers(){
	puts("numbers: ");
	for(int i=0;i<SIZE;i++){
		A[i] = rand() % 150;
		printf("%d ", A[i]);
	}
	puts("");
}

void * findMin(void * args){
	int t = (int) args;
	if(A[t]>A[stride+t])
		A[t]=A[stride+t];
	return NULL;
}



void runThreads(){
	while(stride!=0){
		pthread_t threads[stride];
		for(int i=0;i<stride;i++)
			pthread_create(threads+i,NULL,findMin,(void *) i);
		for(int i=0;i<stride;i++)
			pthread_join(threads[i],0);
		stride/=2;
	}
}

int main()
{
	srand(100);
	setupNumbers();
	stride = SIZE/2;
	runThreads();
	printf("minimumm is %d\n",A[0]);
    return 0;
}
