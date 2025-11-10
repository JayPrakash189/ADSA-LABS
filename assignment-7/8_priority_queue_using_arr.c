#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct item
{
    int data;
    int priority;
};

struct PriorityQueue
{
    struct item arr[MAX];
    int size;
};

void enqueue(struct PriorityQueue *pq, int data, int priority)
{
    if (pq->size == MAX)
    {
        printf("Queue is full\n");
        return;
    }
    pq->arr[pq->size].data = data;
    pq->arr[pq->size].priority = priority;
    pq->size++;
}

void dequeue(struct PriorityQueue *pq)
{
    if (pq->size == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    int highestPriorityIndex = 0;
    for (int i = 1; i < pq->size; i++)
    {
        if (pq->arr[i].priority > pq->arr[highestPriorityIndex].priority)
            highestPriorityIndex = i;
    }

    printf("Dequeued element: %d (Priority %d)\n",
           pq->arr[highestPriorityIndex].data,
           pq->arr[highestPriorityIndex].priority);

    // Shift elements
    for (int i = highestPriorityIndex; i < pq->size - 1; i++)
    {
        pq->arr[i] = pq->arr[i + 1];
    }
    pq->size--;
}

// Function to display queue
void display(struct PriorityQueue *pq)
{
    if (pq->size == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Priority Queue Elements:\n");
    for (int i = 0; i < pq->size; i++)
    {
        printf("Data: %d, Priority: %d\n", pq->arr[i].data, pq->arr[i].priority);
    }
}

int main()
{
    struct PriorityQueue pq;
    pq.size = 0;

    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 5);
    enqueue(&pq, 30, 1);
    display(&pq);

    dequeue(&pq);
    display(&pq);

    return 0;
}
