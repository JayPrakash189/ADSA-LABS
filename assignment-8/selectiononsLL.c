#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *newNode(int val)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (!node)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->data = val;
    node->next = NULL;
    return node;
}

void append(struct Node **head_ref, int val)
{
    struct Node *node = newNode(val);
    if (*head_ref == NULL)
    {
        *head_ref = node;
        return;
    }
    struct Node *cur = *head_ref;
    while (cur->next)
        cur = cur->next;
    cur->next = node;
}

void printList(struct Node *head)
{
    struct Node *cur = head;
    while (cur)
    {
        printf("%d", cur->data);
        if (cur->next)
            printf(" -> ");
        cur = cur->next;
    }
    printf("\n");
}

void swapNodes(struct Node **head_ref, struct Node *prevX, struct Node *x, struct Node *prevY, struct Node *y)
{
    if (x == y)
        return;

    //  Adjacent nodes: x before y
    if (prevY == x)
    {
        if (prevX)
            prevX->next = y;
        else
            *head_ref = y;
        x->next = y->next;
        y->next = x;
        return;
    }

    /* Adjacent nodes: y before x (not expected in current usage but handle anyway) */
    if (prevX == y)
    {
        if (prevY)
            prevY->next = x;
        else
            *head_ref = x;
        y->next = x->next;
        x->next = y;
        return;
    }

    /* Non-adjacent nodes */
    if (prevX)
        prevX->next = y;
    else
        *head_ref = y;

    if (prevY)
        prevY->next = x;
    else
        *head_ref = x;

    struct Node *tmp = x->next;
    x->next = y->next;
    y->next = tmp;
}

/* Selection sort by swapping nodes (not data) */
void selectionSort(struct Node **head_ref)
{
    if (!head_ref || !*head_ref)
        return;

    struct Node *prev_i = NULL;
    struct Node *i = *head_ref;

    while (i)
    {
        /* find minimum node from i to end */
        struct Node *min = i;
        struct Node *prev_min = prev_i;

        struct Node *prev_j = i;
        struct Node *j = i->next;
        while (j)
        {
            if (j->data < min->data)
            {
                min = j;
                prev_min = prev_j;
            }
            prev_j = j;
            j = j->next;
        }

        if (min != i)
        {
            /* swap nodes i and min */
            swapNodes(head_ref, prev_i, i, prev_min, min);
            /* after swap, min is at position of i */
            prev_i = min;
            i = min->next;
        }
        else
        {
            prev_i = i;
            i = i->next;
        }
    }
}

int main(void)
{
    struct Node *head = NULL;
    int n, x;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i)
    {
        if (scanf("%d", &x) != 1)
        {
            printf("Invalid input\n");
            return 1;
        }
        append(&head, x);
    }

    printf("Original list:\n");
    printList(head);

    selectionSort(&head);

    printf("Sorted list (ascending):\n");
    printList(head);

    printf("Press any key to exit...\n");
    getch();
    return 0;
}