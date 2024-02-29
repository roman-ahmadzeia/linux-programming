// 100821974 - roman ahmad zeia
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 4 
#define QUEUE_SIZE 3 

int front = -1;
int rear = -1; 
int pageFrames[SIZE];
int pageFaults = 0;

bool isEmpty() // checks if empty
{
    return rear == -1;
}

bool isFull() // checks if queue is full
{
    return rear == QUEUE_SIZE - 1;
}

int dequeue() // dequeue function
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    int item = pageFrames[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    return item;
}

void enqueue(int item) // function to add page to queue
{
    if (isEmpty())
    {
        front = 0;
    }
    rear++;
    pageFrames[rear] = item;
    printf("%d inserted into the queue\n", item);

    if (isFull())
    {
        int removedPage = dequeue();
        printf("%d removed from the queue\n", removedPage);
    }
}


bool isPageHit(int pageNumber) // check if page is a hit or fault
{
    for (int i = front; i <= rear; i++)
    {
        if (pageFrames[i] == pageNumber)
        {
            return true;
        }
    }
    return false;
}

void managePageFrames(int pageNumber) // manages the functionality of queueing
{
    if (!isPageHit(pageNumber))
    {
        enqueue(pageNumber);
    }
}


int main() // main method
{
    int pages[SIZE] = {1, 2, 3, 4}; // case 1
    memset(pageFrames, -1, sizeof(pageFrames));
    for (int i = 0; i<SIZE; i++)
    {
        if (!isPageHit(pages[i]))
        {
            pageFaults++;
            managePageFrames(pages[i]);
        }
    }
    
    printf("\nTotal number of page faults: %d\n", pageFaults);
    return 0;
}
