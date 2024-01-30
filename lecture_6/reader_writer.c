#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t rw_mutex, mutex;

int data = 0;
int read_count = 0;

void * reader_function(void * thread)
{
	sem_wait(mutex);
	read_count++;

	if (read_count == 1){
		sem_wait(&rw_mutex);
	}

	sem_post(&mutex);

	// Critical Section
		printf("Data read by Thread %d is %d\n", *t, data);
		sleep(1);

		read_count --;

		if (read_count == 0){
		sem_post(&rw_mutex);
	}

}


void * writer_function(void * thread)
{
	int *t = (int *)thread;
	sem_wait(&rw_mutex);

	// Critical Section
	data ++;
	printf("Data written by Thread %d is %d\n", *t, data);
	sleep(1);

	sem_post(&rw_mutex);
}


int main()
{
	pthread_t readers[5], writers[5];

	int readers_ids[5], writers_ids[5];

	for (int i = 0; i < 5; i++)
	{
		writers_ids[i] = i;
		readers_ids[i] = i;
		pthread_create(&writers[i], NULL, writer_function, &writers_ids[i]);
		pthread_create(&readers[i], NULL, reader_function, &readers_ids[i]);

	}

	for (int i = 0; i < 5; i++)
	{
		pthread_join(writers[i], NULL);
		pthread_join(readers[i], NULL);
	}


	return 0;
}
