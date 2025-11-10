#include <stdio.h>
int digitSum(int n)
{
    if (n == 0)
        return 0;
    return n % 10 + digitSum(n / 10);
}
int main()
{
    int n;
    printf("Enter a number : \n");
    scanf("%d", &n);
    printf("Digit sum of the number is : %d", digitSum(n));
    return 0;
}
