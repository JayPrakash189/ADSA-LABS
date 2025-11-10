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

void deleteValue(int value)
{
    if (!last)
        return;
    struct Node *temp = last->next, *prev = last;
    do
    {
        if (temp->data == value)
        {
            if (temp == last && temp->next == last)
            {
                free(temp);
                last = NULL;
                return;
            }
            if (temp == last)
                last = prev;
            prev->next = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != last->next);
}

void display()
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
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    display();
    deleteValue(20);
    display();
    return 0;
}
