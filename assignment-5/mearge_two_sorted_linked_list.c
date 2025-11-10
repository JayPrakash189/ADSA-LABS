#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *merge(struct Node *l1, struct Node *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    if (l1->data < l2->data)
    {
        l1->next = merge(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

struct Node *append(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
        return newNode;
    struct Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *list1 = NULL, *list2 = NULL;
    list1 = append(list1, 1);
    list1 = append(list1, 3);
    list1 = append(list1, 5);
    printf("Display Sorted List 1:\n");
    display(list1);

    list2 = append(list2, 2);
    list2 = append(list2, 4);
    list2 = append(list2, 6);
    printf("Display Sorted List 2:\n");
    display(list2);

    struct Node *merged = merge(list1, list2);
    printf("Merged Sorted List:\n");
    display(merged);
    return 0;
}
