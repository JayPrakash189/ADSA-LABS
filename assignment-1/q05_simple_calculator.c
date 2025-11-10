#include <stdio.h>

int main()
{
    double a, b;
    int c;
    printf("Enter first number : ");
    scanf("%lf", &a);
    printf("Enter second number : ");
    scanf("%lf", &b);

    printf("Enter the operation : 1. +, 2. -, 3. *, 4. /\n");
    scanf("%d", &c);

    switch (c)
    {
    case 1:
        printf("Sum is : %lf\n", a + b);
        break;
    case 2:
        printf("Substraction is : %lf\n", a - b);
        break;
    case 3:
        printf("Multiplication is : %lf\n", a * b);
        break;
    case 4:
        if (b != 0)
            printf("Division is : %lf\n", a / b);
        else
            printf("Error: Division by zero not allowed.\n");
        break;

    default:
        printf("Invalid operator, Enter the currect operator : 1. +, 2. -, 3. /, 4. *.");
    }

    return 0;
}