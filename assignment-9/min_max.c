#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int isBST(struct Node *root, int min, int max)
{
    if (!root)
        return 1;
    if (root->data <= min || root->data >= max)
        return 0;
    return isBST(root->left, min, root->data) &&
           isBST(root->right, root->data, max);
}

int main()
{
    struct Node *root = createNode(20);
    root->left = createNode(10);
    root->right = createNode(30);
    root->left->left = createNode(5);
    root->left->right = createNode(15);

    if (isBST(root, INT_MIN, INT_MAX))
        printf("Tree is a BST\n");
    else
        printf("Tree is NOT a BST\n");

    getch();
    return 0;
}