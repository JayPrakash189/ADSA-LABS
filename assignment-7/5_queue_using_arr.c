#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue(int val)
{
    if (rear == MAX - 1)
        printf("Queue Overflow!\n");
    else
    {
        if (front == -1)
            front = 0;
        queue[++rear] = val;
        printf("%d enqueued\n", val);
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
        printf("Queue Underflow!\n");
    else
        printf("%d dequeued\n", queue[front++]);
}

void display()
{
    if (front == -1 || front > rear)
        printf("Queue empty\n");
    else
    {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
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
            exit(0);
        default:
            printf("Invalid\n");
        }
    }
}
