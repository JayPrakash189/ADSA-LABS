#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

void insertAtPos(int data, int pos)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    if (pos == 1)
    {
        newNode->next = head;
        if (head)
            head->prev = newNode;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp; i++)
        temp = temp->next;
    if (!temp)
        return;

    newNode->next = temp->next;
    if (temp->next)
        temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
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
    insertAtPos(10, 1);
    insertAtPos(20, 2);
    insertAtPos(15, 2);
    insertAtPos(15, 1);
    display();
    return 0;
}
