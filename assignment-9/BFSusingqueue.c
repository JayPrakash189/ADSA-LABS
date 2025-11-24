#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 100

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *queue[MAX];
int front = -1, rear = -1;

void enqueue(struct Node *node)
{
    if (rear < MAX - 1)
        queue[++rear] = node;
}

struct Node *dequeue()
{
    if (front < rear)
        return queue[++front];
    return NULL;
}

struct Node *createNode(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void levelOrder(struct Node *root)
{
    if (!root)
        return;
    enqueue(root);
    while (front < rear)
    {
        struct Node *temp = dequeue();
        printf("%d ", temp->data);
        if (temp->left)
            enqueue(temp->left);
        if (temp->right)
            enqueue(temp->right);
    }
}

int main()
{

    struct Node *root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);

    printf("Level-order traversal: ");
    levelOrder(root);
    getch();
    return 0;
}