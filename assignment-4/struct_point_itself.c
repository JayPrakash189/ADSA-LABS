#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next; // Pointer to itself
};

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->next = NULL;

    printf("Node data: %d\n", head->data);

    free(head);
    return 0;
}
