#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

void insert(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    if (head)
        head->prev = newNode;
    head = newNode;
}

void reverse()
{
    struct Node *temp = NULL, *current = head;
    while (current)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp)
        head = temp->prev;
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
    insert(10);
    insert(20);
    insert(30);
    display();
    reverse();
    display();
    return 0;
}
