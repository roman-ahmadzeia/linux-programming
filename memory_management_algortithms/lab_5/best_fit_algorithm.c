#include <stdio.h>
#include <stdlib.h>
// 100821974 - Roman Ahmad Zeia
#define PROCESS_SIZE 5 // defines global size of 5 for process size

struct Process{ // Process class / structure
	int pid;
	int proc_size;
};

void best_fit(int* blocks, struct Process* processes, int allocations[]); // initialize function

int main()
{
	struct Process proc[PROCESS_SIZE] = { // create array of processes
		{1,212}, {2,417},{3,112}, {4,426}, {5,80}
	};

	int memory_blocks[PROCESS_SIZE] = {100,500,200,300,600}; // create memory blocks
	int allocations[PROCESS_SIZE] = {-1, -1, -1, -1, -1}; // create allocations (empty at first)

	best_fit(memory_blocks, proc, allocations); // call function to apply algorithm

	printf("Process ID\t\tProcess Size\t\tBlock\n"); 
	for (int i = 0; i < PROCESS_SIZE; i++) // show allocations
	{
		printf("%d\t\t\t%d\t\t\t%d\n",proc[i].pid,proc[i].proc_size, allocations[i]+1); // +1 so it shows correct block since it counts 01234 not 12345
	}

	return 0;

}
// best fit algorithm in a function
void best_fit(int* blocks, struct Process* processes, int allocations[])
{
    for (int i = 0; i < PROCESS_SIZE; i++)
    {
        int best_index = -1;
        for (int j = 0; j < PROCESS_SIZE; j++)
        {
            if (blocks[j] >= processes[i].proc_size)
            {
                if (best_index == -1 || blocks[j] < blocks[best_index])
                {
                    best_index = j;
                }
            }
        }
        if (best_index != -1)
        {
            allocations[i] = best_index;
            blocks[best_index] -= processes[i].proc_size;
        }
    }
}


