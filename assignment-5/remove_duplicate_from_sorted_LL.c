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

void removeDuplicates()
{
    struct Node *current = head;
    while (current && current->next)
    {
        if (current->data == current->next->data)
        {
            struct Node *dup = current->next;
            current->next = dup->next;
            free(dup);
        }
        else
        {
            current = current->next;
        }
    }
}

int main()
{
    append(1);
    append(1);
    append(2);
    append(3);
    append(3);
    append(4);

    printf("Original list:\n");
    display();

    removeDuplicates();
    printf("After removing duplicates:\n");
    display();

    return 0;
}
