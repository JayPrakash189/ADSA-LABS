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

void findMiddle()
{
    struct Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow)
        printf("Middle element: %d\n", slow->data);
}

int main()
{
    append(10);
    append(20);
    append(30);
    append(40);
    append(50);
    findMiddle();
    return 0;
}
