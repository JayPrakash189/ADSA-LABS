#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack and Queue
char stack[MAX];
char queue[MAX];
int top = -1, front = 0, rear = -1;

void push(char c)
{
    stack[++top] = c;
}
void enqueue(char c)
{
    queue[++rear] = c;
}
int isPalindrome(char str[])
{
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        if (isalnum(str[i]))
        {
            char c = tolower(str[i]);
            push(c);
            enqueue(c);
        }
    }

    for (int i = 0; i <= rear; i++)
    {
        if (stack[top--] != queue[i])
            return 0;
    }
    return 1;
}

int main()
{
    char str[MAX];

    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline

    if (isPalindrome(str))
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}
