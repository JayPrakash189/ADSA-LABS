#include <stdio.h>
int main()
{
    int n, count = 0;
    printf("Enter any number : \n");
    scanf("%d", &n);
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    printf("Digit count is : %d", count);
    return 0;
}
