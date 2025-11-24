#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data, height;
    struct Node *left;
    struct Node *right;
};

int max(int a, int b) { return a > b ? a : b; }

int height(struct Node *root)
{
    return root ? root->height : 0;
}

int getBalance(struct Node *root)
{
    return root ? height(root->left) - height(root->right) : 0;
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    printf("Right Rotation performed on %d\n", y->data);
    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    printf("Left Rotation performed on %d\n", x->data);
    return y;
}

struct Node *insert(struct Node *node, int key)
{
    if (!node)
    {
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->data = key;
        newNode->left = newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    printf("Node %d -> Balance Factor: %d\n", node->data, balance);

    if (balance > 1 && key < node->left->data)
        return rightRotate(node);
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);
    if (balance > 1 && key > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorder(struct Node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{

    struct Node *root = NULL;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Inorder traversal of AVL Tree: ");
    inorder(root);
    getch();
    return 0;
}