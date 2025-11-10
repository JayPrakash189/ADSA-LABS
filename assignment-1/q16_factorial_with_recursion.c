#include <stdio.h>

int factorial(int num)
{
    // base case is importent
    if (num == 0 || num == 1)
    {
        return 1;
    }
    return num * factorial(num - 1);
}

int main()
{
    int num;
    printf("Enter any positive number : \n");
    scanf("%d", &num);
    if (num < 0)
    {
        printf("Number can not ber negative.");
    }
    else
    {

        printf("Entered number is : %d\n", num);
        int result = factorial(num);
        printf("Factorial is : %d", result);
    }
    return 0;
}