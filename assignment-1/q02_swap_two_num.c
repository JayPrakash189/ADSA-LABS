#include <stdio.h>

int main()
{
    int a, b;
    printf("Enter first number : ");
    scanf("%d", &a);
    printf("Enter second number : ");
    scanf("%d", &b);
    printf("Current values of a is %d and b is %d \n", a, b);
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("Current values of a is %d and b is %d", a, b);
    return 0;
}