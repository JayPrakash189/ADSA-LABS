#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
        return 0;

    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    int largest = INT_MIN, second = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > largest)
        {
            second = largest;
            largest = arr[i];
        }
        else if (arr[i] > second && arr[i] < largest)
        {
            second = arr[i];
        }
    }

    if (second == INT_MIN)
    {
        printf("No second largest (all elements equal or only one element).\n");
    }
    else
    {
        printf("Second largest element: %d\n", second);
    }
    return 0;
}
