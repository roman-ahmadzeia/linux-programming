  // creating threads
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void * show_even(void * args)
{
	int *end = (int *)args;
	for (int i = 0; i < *end; i++){
		printf("Thread 1: %d\n", i);
	}


	// printf("Other Thread: %lu\n", pthread_self());


}

void * show_odd(void * args)
{
	int *end = (int *)args;
	for (int i = 1; i < *end; i= i+2){
		printf("Thread 2: %d\n", i);
	}


	// printf("Other Thread: %lu\n", pthread_self());


}

int main(int args, char * argv[])
{
	int end = atoi(argv[1]);

	printf("Main Thread: %lu\n", pthread_self());

	pthread_attr_t attr;

	pthread_attr_init(&attr);
	pthread_attr_setstacksize(&attr, 15000);
	pthread_t tid[2];

	pthread_create(&tid[0], NULL, show_even, &end);
	printf("\n");
	pthread_create(&tid[1], NULL, show_odd, &end);

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);

	return 0;
}