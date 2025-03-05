#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#define SIZE 10
#define THREADS 4
int A[SIZE];
int B[SIZE];
int product;
int itemsPerThread;
sem_t sem1;

void setupNumbers(int * arr){
	puts("numbers: ");
	for(int i=0;i<SIZE;i++){
		arr[i] = rand() % 10;
		printf("%d ", arr[i]);
	}
	puts("");
}

void * routine(void * args){
	int threadIndex = (int) args;
	int startIndex = threadIndex*itemsPerThread;
	int endIndex = threadIndex==THREADS-1?SIZE:(threadIndex+1)*itemsPerThread;
	int sum=0;
	for(int i=startIndex;i<endIndex;i++)
		sum+=A[i]*B[i];
	sem_wait(&sem1);
	product+=sum;
	sem_post(&sem1);
	return NULL;
}

void calculateProduct(){
	product = 0;
	itemsPerThread = SIZE/THREADS;
	pthread_t threads[THREADS];
	for(int i=0;i<THREADS;i++)
		pthread_create(threads+i,NULL,routine,(void *)i);
	for(int i=0;i<THREADS;i++)
		pthread_join(threads[i],NULL);
	printf("product: %d\n",product);
}

int main()
{
	sem_init(&sem1,0,1);
	setupNumbers(A);
	setupNumbers(B);
	calculateProduct();
	sem_destroy(&sem1);
    return 0;
}
