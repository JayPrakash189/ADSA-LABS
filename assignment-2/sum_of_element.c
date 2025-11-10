#include <stdio.h>
// iterative method
#include <stdio.h>

int main_1()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    printf("Sum = %d\n", sum);
    return 0;
}

// recursive method
int sumArray(int arr[], int n)
{
    if (n == 0)
        return 0;
    return arr[n - 1] + sumArray(arr, n - 1);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Sum = %d\n", sumArray(arr, n));
    return 0;
}
