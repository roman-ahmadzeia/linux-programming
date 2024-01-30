#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void show_even(int start, int end){
	for(int i = start; i < end; i++){
		if (i%2 == 0){
			printf("parent - %d\n", i);
		}
	}
}


void show_odd(int start, int end){
	for(int i = start; i < end; i++){
		if (i%2 != 0){
			printf("child - %d\n", i);
		}
	}
}
int main(int args, char * argv[])
{
	int start = atoi(argv[1]);
    int end = atoi(argv[2]);


	int i = fork();
	if (i>0)
	{
		show_even(start, end);
	}
	else if (i == 0){
		show_odd(start, end);
	}
	return 0;
}