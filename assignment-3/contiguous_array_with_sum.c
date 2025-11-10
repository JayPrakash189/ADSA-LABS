#include <stdio.h>

int main()
{
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n <= 0)
        return 0;
    int arr[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    int S;
    printf("Enter target sum S: ");
    scanf("%d", &S);

    int found = 0;
    for (int i = 0; i < n && !found; ++i)
    {
        int sum = 0;
        for (int j = i; j < n; ++j)
        {
            sum += arr[j];
            if (sum == S)
            {
                printf("Subarray found from index %d to %d (0-based)\n", i, j);
                found = 1;
                break;
            }
        }
    }
    if (!found)
        printf("No contiguous subarray with sum %d\n", S);
    return 0;
}
