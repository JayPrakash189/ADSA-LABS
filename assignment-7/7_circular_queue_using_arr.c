#include <stdio.h>
#define SIZE 5 // Define maximum size of the circular queue

int queue[SIZE];
int front = -1, rear = -1;

int isFull()
{
    return ((rear + 1) % SIZE == front);
}

int isEmpty()
{
    return (front == -1);
}

void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue is FULL! Cannot insert %d\n", value);
    }
    else
    {
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % SIZE;
        }
        queue[rear] = value;
        printf("%d enqueued to queue.\n", value);
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is EMPTY! Cannot dequeue.\n");
    }
    else
    {
        printf("%d dequeued from queue.\n", queue[front]);
        if (front == rear)
        {
            // Queue becomes empty
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is EMPTY!\n");
    }
    else
    {
        printf("Queue elements: ");
        int i = front;
        while (1)
        {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

void next(int c)
{
    if (isEmpty())
    {
        printf("Queue is EMPTY! No next element.\n");
    }
    else
    {
        printf("Next element (front): %d\n", queue[(front + c) % SIZE]);
    }
}

int main()
{
    int choice, value;
    int count;

    printf("Circular Queue Implementation (Array)\n");
    printf("---------------GAME ON---------------------\n");

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Next Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        count++;

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            next(count);
            break;
        case 5:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
