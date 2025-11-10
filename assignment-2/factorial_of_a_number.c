
// // Program A
// #include <stdio.h>
// int factorial(int n)
// {
//     int result = 1;
//     for (int i = 2; i <= n; ++i)
//     {
//         result *= i;
//     }
//     return result;
// }

// int main()
// {
//     int n;
//     printf("Enter a number: ");
//     scanf("%d", &n);

//     if (n < 0)
//     {
//         printf("Factorial is not defined for negative numbers.\n");
//     }
//     else
//     {
//         printf("Factorial of %d is %d\n", n, factorial(n));
//     }
//     return 0;
// }

// Program B
#include <stdio.h>
int factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("Factorial is not defined for negative numbers.\n");
    }
    else
    {
        printf("Factorial of %d is %d\n", num, factorial(num));
    }
    return 0;
}
