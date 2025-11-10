#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
};
struct Node *top = NULL;

void push(char c)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = c;
    newNode->next = top;
    top = newNode;
}

char pop()
{
    if (top == NULL)
        return '\0';
    char c = top->data;
    struct Node *temp = top;
    top = top->next;
    free(temp);
    return c;
}

int isBalanced(char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (top == NULL)
                return 0;
            char c = pop();
            if ((exp[i] == ')' && c != '(') ||
                (exp[i] == '}' && c != '{') ||
                (exp[i] == ']' && c != '['))
                return 0;
        }
    }
    return top == NULL;
}

int main()
{
    char exp[100];
    printf("Enter expression: ");
    gets(exp);
    if (isBalanced(exp))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}
