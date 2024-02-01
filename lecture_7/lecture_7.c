// cpu scheduling lect 7
#include <stdio.h>
#include <stdlib.h>

#define NUM 5 // 5 processes

int main()
{
	int burst_time[5];
	int wait_time = 0;
	int tun_around_time = 0;

	printf("Process\t Burst Time\tWait Time\tTurn Around Time\n");
	for (int i = 0; i < NUM; i++)
	{
		burst_time[i] = rand()%10;
		printf("%d\t%d\t\t%d\t\t\t%d\n", i, burst_time[i], wait_time, tun_around_time);
		avg_wait_time = avg_wait_time + wait_time;
		wait_tome = wait_time + burst_time[i];
	}

	printf("Average Wait Time: %d\n", avg_wait_time/NUM);




	return 0;
}