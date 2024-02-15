#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
// 100821974 - roman ahmad zeia

void * child_function(void * args)
{
	int *num = (int *)args;

	int *result = malloc(*num * sizeof(int)); 

	printf("I am a child thread with id: %lu\n", pthread_self());
	printf("\n");

	for (int i = 0; i < *num; ++i) {
        result[i] = i;
        printf("Inserted %d into the array with Child Thread \n", i);
    }

    pthread_exit((void*)result);

}



int main(int args, char * argv[])
{
	int num = atoi(argv[1]);

	printf("I am a parent thread: %lu\n", pthread_self());

	pthread_t child_t;

	pthread_create(&child_t, NULL, child_function, &num);

	void* result;
	pthread_join(child_t, &result);
	printf("\n");
	printf("Displaying array with parent thread\n");

	for (int i = 0; i < num; ++i) {
        printf("Element at index: %d = %d\n", i,  ((int*)result)[i]);
    }

    free(result);


	return 0;

}
