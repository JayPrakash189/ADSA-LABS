// 1. Implement a doubly linked list with basic operations: insert at beginning, insert at end,
// delete a node, and display the list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

void insertAtBeginning(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head)
        head->prev = newNode;
    head = newNode;
}

void insertAtEnd(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (!head)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(int data)
{
    struct Node *temp = head;
    while (temp && temp->data != data)
        temp = temp->next;
    if (!temp)
        return;

    if (temp->prev)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;

    free(temp);
}

void display()
{
    struct Node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    display();
    deleteNode(20);
    display();
    return 0;
}
