#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *last = NULL;

void insertEnd(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (!last)
    {
        last = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void insertAfter(int value, int data)
{
    if (!last)
        return;
    struct Node *temp = last->next;
    do
    {
        if (temp->data == value)
        {
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
            if (temp == last)
                last = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != last->next);
}

void display()
{
    if (!last)
        return;
    struct Node *temp = last->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

int main()
{
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertAfter(20, 25);
    display();
    return 0;
}
