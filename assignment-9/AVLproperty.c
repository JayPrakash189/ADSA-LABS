#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int height(struct Node *root)
{
    if (!root)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int isBalanced(struct Node *root)
{
    if (!root)
        return 1;
    int lh = height(root->left);
    int rh = height(root->right);
    int bf = lh - rh;
    printf("Node %d -> Balance Factor: %d\n", root->data, bf);
    if (bf < -1 || bf > 1)
        return 0;
    return isBalanced(root->left) && isBalanced(root->right);
}

struct Node *createNode(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main()
{

    struct Node *root = createNode(30);
    root->left = createNode(20);
    root->right = createNode(40);
    root->left->left = createNode(10);

    if (isBalanced(root))
        printf("Tree is height-balanced (AVL).\n");
    else
        printf("Tree is NOT height-balanced.\n");

    getch();
    return 0;
}