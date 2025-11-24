#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = q->rear = NULL;
}

int isEmpty(Queue *q)
{
    return q->front == NULL;
}

void enqueue(Queue *q, int val)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    n->data = val;
    n->next = NULL;
    if (q->rear)
        q->rear->next = n;
    q->rear = n;
    if (!q->front)
        q->front = n;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        fprintf(stderr, "Attempt to dequeue from empty queue\n");
        exit(EXIT_FAILURE);
    }
    Node *t = q->front;
    int v = t->data;
    q->front = t->next;
    if (!q->front)
        q->rear = NULL;
    free(t);
    return v;
}

int peek(Queue *q)
{
    if (isEmpty(q))
    {
        fprintf(stderr, "Attempt to peek into empty queue\n");
        exit(EXIT_FAILURE);
    }
    return q->front->data;
}

Queue mergeQueues(Queue *a, Queue *b)
{
    Queue res;
    initQueue(&res);
    while (!isEmpty(a) && !isEmpty(b))
    {
        if (peek(a) <= peek(b))
        {
            enqueue(&res, dequeue(a));
        }
        else
        {
            enqueue(&res, dequeue(b));
        }
    }
    while (!isEmpty(a))
        enqueue(&res, dequeue(a));
    while (!isEmpty(b))
        enqueue(&res, dequeue(b));
    return res;
}

void printQueue(Queue *q)
{
    Node *cur = q->front;
    printf("[");
    while (cur)
    {
        printf("%d", cur->data);
        cur = cur->next;
        if (cur)
            printf(", ");
    }
    printf("]\n");
}

void freeQueue(Queue *q)
{
    while (!isEmpty(q))
        dequeue(q);
}

int main(void)
{
    Queue q1, q2, merged;
    initQueue(&q1);
    initQueue(&q2);

    int n1, n2, i, val;

    printf("Enter number of elements in first sorted queue: ");
    if (scanf("%d", &n1) != 1 || n1 < 0)
        return 0;
    printf("Enter %d integers in non-decreasing order:\n", n1);
    for (i = 0; i < n1; ++i)
    {
        if (scanf("%d", &val) != 1)
            return 0;
        enqueue(&q1, val);
    }

    printf("Enter number of elements in second sorted queue: ");
    if (scanf("%d", &n2) != 1 || n2 < 0)
        return 0;
    printf("Enter %d integers in non-decreasing order:\n", n2);
    for (i = 0; i < n2; ++i)
    {
        if (scanf("%d", &val) != 1)
            return 0;
        enqueue(&q2, val);
    }

    merged = mergeQueues(&q1, &q2);

    printf("Merged sorted queue: ");
    printQueue(&merged);

    freeQueue(&merged);
    printf("Press any key to exit...\n");
    getch();
    return 0;
}