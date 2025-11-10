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

int detectLoop()
{
    struct Node *slow = head;
    struct Node *fast = head;
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }
    return 0;
}

int main()
{
    append(1);
    append(2);
    append(3);
    append(4);
    append(5);

    // Create loop manually
    head->next->next->next->next->next = head->next;

    if (detectLoop())
        printf("Loop detected in the linked list.\n");
    else
        printf("No loop found.\n");

    return 0;
}
