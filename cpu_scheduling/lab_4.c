//100821974 - Roman Ahmad Zeia
#include <stdio.h>
#include <stdlib.h>


#define NUM_OF_PROCESSES 5

struct Process
{
	int pid;
	int burst_time;
	int priority;
};


int priority_sort(const void *a, const void *b);


int main()
{


	struct Process proc[NUM_OF_PROCESSES] = {
		{1,10,3},{2,1,1},{3,2,4}, {4,1,5},{5,5,2}
	};

	int wait_time[NUM_OF_PROCESSES];
	int turn_around_time[NUM_OF_PROCESSES];

	printf("LAB - 4 ROMAN AHMAD ZEIA\n\n");
	printf("Before Sorting \n\n");
	printf("Process ID\tBurst Time\tPriority\n");
	for (int i = 0; i < NUM_OF_PROCESSES; i++)
	{
		printf("%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].priority);

	}

	printf("\n");
	printf("After Sorting \n\n");

	qsort(proc, NUM_OF_PROCESSES, sizeof(struct Process), priority_sort);

	wait_time[0] = 0, turn_around_time[0] = proc[0].burst_time;
	float average_time = 0;

	for (int i = 1; i < NUM_OF_PROCESSES; i++)
	{
		wait_time[i] = wait_time[i-1] + proc[i-1].burst_time;
		turn_around_time[i] = wait_time[i] + proc[i].burst_time;
		average_time += wait_time[i];
	}

	printf("Process ID\t Burst Time\tPriority\tWait Time \tTurn Around Time\n");
	for (int i = 0; i < NUM_OF_PROCESSES; i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].priority, wait_time[i],turn_around_time[i]);

	}

	printf("Average Wait time: %.2f\n", average_time/5);

	return 0;

}

int priority_sort(const void *a, const void *b)
{
	const struct Process *processA = (const struct Process *)a;
    const struct Process *processB = (const struct Process *)b;
    return (processA->priority - processB->priority);

}
