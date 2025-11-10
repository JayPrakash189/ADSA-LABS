#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct Deque
{
    int arr[SIZE];
    int front, rear;
};

void initDeque(struct Deque *dq)
{
    dq->front = -1;
    dq->rear = -1;
}

int isFull(struct Deque *dq)
{
    return ((dq->front == 0 && dq->rear == SIZE - 1) || (dq->front == dq->rear + 1));
}

int isEmpty(struct Deque *dq)
{
    return (dq->front == -1);
}

void insertFront(struct Deque *dq, int item)
{
    if (isFull(dq))
    {
        printf("Deque is full\n");
        return;
    }
    if (dq->front == -1)
    {
        dq->front = dq->rear = 0;
    }
    else if (dq->front == 0)
    {
        dq->front = SIZE - 1;
    }
    else
    {
        dq->front--;
    }
    dq->arr[dq->front] = item;
}

void insertRear(struct Deque *dq, int item)
{
    if (isFull(dq))
    {
        printf("Deque is full\n");
        return;
    }
    if (dq->front == -1)
    {
        dq->front = dq->rear = 0;
    }
    else if (dq->rear == SIZE - 1)
    {
        dq->rear = 0;
    }
    else
    {
        dq->rear++;
    }
    dq->arr[dq->rear] = item;
}

void deleteFront(struct Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted from front: %d\n", dq->arr[dq->front]);
    if (dq->front == dq->rear)
    {
        dq->front = dq->rear = -1;
    }
    else if (dq->front == SIZE - 1)
    {
        dq->front = 0;
    }
    else
    {
        dq->front++;
    }
}

void deleteRear(struct Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted from rear: %d\n", dq->arr[dq->rear]);
    if (dq->front == dq->rear)
    {
        dq->front = dq->rear = -1;
    }
    else if (dq->rear == 0)
    {
        dq->rear = SIZE - 1;
    }
    else
    {
        dq->rear--;
    }
}

void display(struct Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    int i = dq->front;
    while (1)
    {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main()
{
    struct Deque dq;
    initDeque(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    display(&dq);

    deleteRear(&dq);
    deleteFront(&dq);
    display(&dq);

    return 0;
}
