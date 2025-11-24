#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *create_list(int n)
{
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; ++i)
    {
        int val;
        printf(" Enter element %d: ", i + 1);
        if (scanf("%d", &val) != 1)
        {
            printf(" Invalid input.\n");
            exit(EXIT_FAILURE);
        }
        Node *p = (Node *)malloc(sizeof(Node));
        if (!p)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        p->data = val;
        p->next = NULL;
        if (!head)
            head = tail = p;
        else
        {
            tail->next = p;
            tail = p;
        }
    }
    return head;
}

void print_list(const char *label, Node *head)
{
    printf("%s", label);
    if (!head)
    {
        printf(" (empty)\n");
        return;
    }
    for (Node *p = head; p; p = p->next)
    {
        if (p != head)
            printf(" -> ");
        printf("%d", p->data);
    }
    printf("\n");
}

/* Merge two sorted lists a and b into one sorted list in-place.
    Returns head of the merged list. */
Node *merge_sorted_lists(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;

    Node *head = NULL, *tail = NULL;

    /* Initialize head to the smaller first node */
    if (a->data <= b->data)
    {
        head = tail = a;
        a = a->next;
    }
    else
    {
        head = tail = b;
        b = b->next;
    }

    /* Merge by splicing nodes from a or b */
    while (a && b)
    {
        if (a->data <= b->data)
        {
            tail->next = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    /* Attach remaining nodes */
    tail->next = (a) ? a : b;
    return head;
}

void free_list(Node *head)
{
    Node *p;
    while (head)
    {
        p = head;
        head = head->next;
        free(p);
    }
}

int main(void)
{
    int n1, n2;
    printf("Create first sorted list\nEnter number of elements: ");
    if (scanf("%d", &n1) != 1 || n1 < 0)
    {
        printf("Invalid count.\n");
        return 1;
    }
    Node *l1 = create_list(n1);

    printf("\nCreate second sorted list\nEnter number of elements: ");
    if (scanf("%d", &n2) != 1 || n2 < 0)
    {
        printf("Invalid count.\n");
        free_list(l1);
        return 1;
    }
    Node *l2 = create_list(n2);

    print_list("\nList 1: ", l1);
    print_list("List 2: ", l2);

    Node *merged = merge_sorted_lists(l1, l2);
    print_list("\nMerged list: ", merged);

    free_list(merged);

    printf("\nPress any key to exit...");
    getch();
    return 0;
}