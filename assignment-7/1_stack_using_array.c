#include <stdio.h>
#include <stdlib.h>

// void print(const char s[30])
// {
//     for (int i = 0; s[i] != '\0'; i++)
//     {
//         printf("%c", s[i]);
//     }
//     printf("\n");
// }

// int main()
// {
//     char c[] = "avinash";
//     print("avinash");
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

// simple push fun
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow! Cannot push %d\n", value);
    }
    else
    {
        stack[++top] = value;
        printf("%d pushed to stack.\n", value);
    }
}

// popping funtion
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! No elements to pop.\n");
    }
    else
    {
        printf("%d popped from stack.\n", stack[top--]);
    }
}

// display
void display()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Main function
int main()
{
    int choice, value;
    while (1)
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
