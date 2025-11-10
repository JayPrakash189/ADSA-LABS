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
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void display()
{
    struct Node *temp = head;
    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteAtBeginning()
{
    if (head)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteAtEnd()
{
    if (!head)
        return;
    if (!head->next)
    {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next->next)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(int pos)
{
    if (pos == 1)
    {
        deleteAtBeginning();
        return;
    }
    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
}

int main()
{
    append(10);
    append(20);
    append(30);
    append(40);
    append(50);

    printf("Original list:\n");
    display();

    deleteAtBeginning();
    display();

    deleteAtEnd();
    display();

    deleteAtPosition(2);
    display();

    return 0;
}
