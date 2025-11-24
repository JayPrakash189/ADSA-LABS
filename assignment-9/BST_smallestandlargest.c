#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *insert(struct Node *root, int data)
{
    if (!root)
    {
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void kthSmallest(struct Node *root, int k, int *count, int *result)
{
    if (!root || *count >= k)
        return;
    kthSmallest(root->left, k, count, result);
    (*count)++;
    if (*count == k)
        *result = root->data;
    kthSmallest(root->right, k, count, result);
}

void kthLargest(struct Node *root, int k, int *count, int *result)
{
    if (!root || *count >= k)
        return;
    kthLargest(root->right, k, count, result);
    (*count)++;
    if (*count == k)
        *result = root->data;
    kthLargest(root->left, k, count, result);
}

int main()
{

    struct Node *root = NULL;
    int n, val, k, count = 0, result = -1;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Enter k for k-th smallest: ");
    scanf("%d", &k);
    kthSmallest(root, k, &count, &result);
    printf("k-th smallest: %d\n", result);

    count = 0;
    result = -1;
    printf("Enter k for k-th largest: ");
    scanf("%d", &k);
    kthLargest(root, k, &count, &result);
    printf("k-th largest: %d\n", result);

    getch();
    return 0;
}