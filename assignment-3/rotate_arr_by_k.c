#include <stdio.h>

void reverse(int arr[], int l, int r)
{
    while (l < r)
    {
        int t = arr[l];
        arr[l] = arr[r];
        arr[r] = t;
        l++;
        r--;
    }
}

int main()
{
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n <= 0)
        return 0;
    int arr[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    int k;
    printf("Enter k: ");
    scanf("%d", &k);
    k = k % n; // normalize

    // reverse whole, reverse first k, reverse remaining
    reverse(arr, 0, n - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);

    printf("Rotated array:\n");
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
