#include <stdio.h>
int main()
{
    int n, i, max;
    printf("Enter the size of the arr: \n");
    scanf("%d", &n);
    printf("Enter the elements : \n");
    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    max = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    printf("Max element in the array is : %d", max);
    return 0;
}
