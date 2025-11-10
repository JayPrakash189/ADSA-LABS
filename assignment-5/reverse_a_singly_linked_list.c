#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void append(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void display()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverseIterative()
{
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

struct Node *reverseRecursive(struct Node *node)
{
    if (node == NULL || node->next == NULL)
    {
        head = node;
        return node;
    }
    struct Node *rest = reverseRecursive(node->next);
    node->next->next = node;
    node->next = NULL;
    return rest;
}

int main()
{
    append(1);
    append(2);
    append(3);
    append(4);
    append(5);

    printf("Original list:\n");
    display();

    reverseIterative();
    printf("Reversed (Iterative):\n");
    display();

    reverseRecursive(head);
    printf("Reversed again (Recursive):\n");
    display();

    return 0;
}
