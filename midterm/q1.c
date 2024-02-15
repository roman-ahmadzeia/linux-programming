


#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t rw_mutex, mutex;

//setting up global variables
int bank_balance = 0;


int main()
{
	pthread_t child_1, child_2;

	sem_init(&rw_mutex, 0, 1);

	sem_init(&mutex, 0, 1);


		pthread_create(&child_1, NULL, NULL, NULL);
		pthread_create(&child_2, NULL, NULL, NULL);



		pthread_join(child_1, NULL);
		pthread_join(child_2, NULL);

	return 0;
}
