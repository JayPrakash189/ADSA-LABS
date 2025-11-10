#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL, *rear = NULL;

void enqueue(int val)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (rear == NULL)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued\n", val);
}

void dequeue()
{
    if (front == NULL)
        printf("Queue Underflow!\n");
    else
    {
        printf("%d dequeued\n", front->data);
        struct Node *temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        free(temp);
    }
}

void display()
{
    if (front == NULL)
        printf("Queue empty\n");
    else
    {
        struct Node *temp = front;
        printf("Queue: ");
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
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
