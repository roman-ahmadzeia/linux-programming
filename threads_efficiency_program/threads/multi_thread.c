#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
void * child_function(void * args)
{
	int *num = (int *)args;
	unsigned long long *sum = (unsigned long long *)malloc(sizeof(unsigned long long));
	*sum = 0;
	printf("CHILD THREAD 1: %lu\n", pthread_self());
	for (int i = 0; i <= *num; i++)
	{
		*sum += i;
	}
	pthread_exit((void*)sum);
}

void *child2_function(void *args)
{
    int *num = (int *)args;
    unsigned long long *sum_even = (unsigned long long *)malloc(sizeof(unsigned long long));
    *sum_even = 0;
    printf("CHILD THREAD 2: %lu\n", pthread_self());
    for (int i = 2; i <= *num; i += 2)
    {
        *sum_even += i;
    }

    pthread_exit((void *)sum_even);
}

int main(int argc, char * argv[])
{

	int input = atoi(argv[1]);

	printf("PARENT THREAD: %lu\n",pthread_self());

	pthread_t child_t1;
	pthread_t child_t2;
	unsigned long long* sum;
	unsigned long long* sum_even;



	pthread_create(&child_t1, NULL, child_function, &input);

	pthread_create(&child_t2, NULL, child2_function, &input);

	pthread_join(child_t1,(void **)&sum);
	pthread_join(child_t2,(void **)&sum_even);


	printf("Sum of all numbers with Thread 1: %lld\n", *sum);
    printf("Sum of all numbers with Thread 2: %lld\n", *sum_even);

    printf("Child Thread 1 / Child Thread 2 = %.2f\n", (double)*sum / (double)*sum_even);



    free(sum);
    free(sum_even);

    return 0;
}
