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

void deleteValue(int value)
{
    struct Node *temp = head;
    while (temp && temp->data != value)
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
    insert(30);
    insert(20);
    insert(10);
    display();
    deleteValue(20);
    display();
    return 0;
}
