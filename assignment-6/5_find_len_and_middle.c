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

void findLengthAndMiddle()
{
    int length = 0;
    struct Node *temp = head;
    while (temp)
    {
        length++;
        temp = temp->next;
    }

    int mid = length / 2 + 1;
    temp = head;
    for (int i = 1; i < mid; i++)
        temp = temp->next;
    printf("Length: %d, Middle: %d\n", length, temp->data);
}

int main()
{
    insert(50);
    insert(40);
    insert(30);
    insert(20);
    insert(10);
    findLengthAndMiddle();
    return 0;
}
