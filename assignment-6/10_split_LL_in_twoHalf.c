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

void splitList(struct Node *last, struct Node **firstHalf, struct Node **secondHalf)
{
    if (!last)
        return;
    struct Node *slow = last->next, *fast = last->next;
    while (fast->next != last->next && fast->next->next != last->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    *firstHalf = last->next;
    *secondHalf = slow->next;
    slow->next = *firstHalf;

    struct Node *temp = *secondHalf;
    while (temp->next != last->next)
        temp = temp->next;
    temp->next = *secondHalf;
}

void display(struct Node *last)
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
    for (int i = 10; i <= 60; i += 10)
        insertEnd(i);

    struct Node *head1 = NULL, *head2 = NULL;
    splitList(last, &head1, &head2);

    printf("First half: ");
    display(head1);
    printf("Second half: ");
    display(head2);
    return 0;
}
