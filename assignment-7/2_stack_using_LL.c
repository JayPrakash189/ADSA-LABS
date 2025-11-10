#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;

void push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed\n", value);
}

void pop()
{
    if (top == NULL)
        printf("Stack Underflow!\n");
    else
    {
        printf("%d popped\n", top->data);
        struct Node *temp = top;
        top = top->next;
        free(temp);
    }
}

void peek()
{
    if (top == NULL)
        printf("Stack is empty\n");
    else
        printf("Top element: %d\n", top->data);
}

void display()
{
    struct Node *temp = top;
    if (!temp)
        printf("Stack empty\n");
    else
    {
        printf("Stack: ");
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid\n");
        }
    }
}
