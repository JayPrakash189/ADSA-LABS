#include <stdio.h>

int main()
{
    int n, i;
    long long fact = 1;
    printf("Enter the digits :\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        fact *= i;
    }
    printf("Factorial is : %lld", fact);
    return 0;
}
