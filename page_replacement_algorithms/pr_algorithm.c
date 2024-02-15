#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SIZE 5

int isPagehit(int *page_frames, int page)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (page_frames[i] == page)
		{
			return 1; // a hit
		}
	}
	return 0; // a fault

}

int main()
{

	int page_frames[SIZE];
	int pages[SIZE] = {1,2,3,1,1};
	int pageFault = 0;
	int index = 0;

	memset(page_frames, -1, sizeof(page_frames)); //intializes all the elements in an array with 1 number.
	
	for (int i = 0; i < SIZE; i++)
	{
		if (!isPagehit(page_frames, pages[i]))
		{
			pageFault++;
			printf("Page Fault occured for Page %d\n", pages[i]);
			printf("Total Faults: %d\n", pageFault);
			page_frames[index] = pages[i];
			index++;

		}
		else
		{
			printf("No page fault. Page already in memory\n");
			for (int j = 0; j < SIZE; j++)
			{
				printf("%d\t", page_frames[j]);
			}
				printf("\n");
		}
	}

	return 0;
}