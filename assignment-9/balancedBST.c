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

struct Node *buildBST(int arr[], int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    struct Node *root = malloc(sizeof(struct Node));
    root->data = arr[mid];
    root->left = buildBST(arr, start, mid - 1);
    root->right = buildBST(arr, mid + 1, end);
    return root;
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

    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node *root = buildBST(arr, 0, n - 1);
    printf("Level-order traversal of balanced BST:\n");
    levelOrder(root);
    getch();
    return 0;
}