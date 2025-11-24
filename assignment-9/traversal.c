#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 100

// Define structure for tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Queue for level-order insertion
struct Node *queue[MAX];
int front = -1, rear = -1;

void enqueue(struct Node *node)
{
    if (rear < MAX - 1)
    {
        queue[++rear] = node;
    }
}

struct Node *dequeue()
{
    if (front < rear)
    {
        return queue[++front];
    }
    return NULL;
}

// Create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Level-order insertion
struct Node *buildTree(int n)
{
    struct Node *root = NULL, *temp;
    int data;

    if (n <= 0)
        return NULL;

    printf("Enter data for root node: ");
    scanf("%d", &data);
    root = createNode(data);
    enqueue(root);

    for (int i = 1; i < n; i++)
    {
        temp = queue[front + 1]; // Peek front
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        struct Node *newNode = createNode(data);

        if (!temp->left)
        {
            temp->left = newNode;
        }
        else if (!temp->right)
        {
            temp->right = newNode;
            dequeue(); // Remove node after both children are filled
        }
        enqueue(newNode);
    }

    return root;
}

// Traversals
void preorder(struct Node *root)
{
    if (root)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
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

void postorder(struct Node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct Node *root = NULL;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    root = buildTree(n);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    getch(); // Wait for key press
    return 0;
}