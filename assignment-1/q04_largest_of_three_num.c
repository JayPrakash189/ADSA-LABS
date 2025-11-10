#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Enter any three numbers : \n");
    scanf("%d %d %d", &a, &b, &c);
    int largest = 0;
    if (largest < a)
    {
        largest = a;
    }
    if (largest < b)
    {
        largest = b;
    }
    if (largest < c)
    {
        largest = c;
    }
    printf("Largest number is %d", largest);

    return 0;
}