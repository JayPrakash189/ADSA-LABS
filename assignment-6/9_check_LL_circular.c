#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int isCircular(struct Node *head)
{
    if (!head)
        return 1;
    struct Node *temp = head->next;
    while (temp && temp != head)
        temp = temp->next;
    return (temp == head);
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = head; // circular

    if (isCircular(head))
        printf("List is circular\n");
    else
        printf("List is not circular\n");

    return 0;
}
