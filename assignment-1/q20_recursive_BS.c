#include <stdio.h>

void sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int search(int arr[], int l, int r, int x)
{
    if (l > r)
        return -1;
    int mid = (l + r) / 2;
    if (arr[mid] == x)
        return mid;
    if (arr[mid] > x)
        return search(arr, l, mid - 1, x);
    return search(arr, mid + 1, r, x);
}
int main()
{
    int n, x, i;
    printf("Enter number of books: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d book IDs in sorted order if possible:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sort(arr, n);
    printf("Entered %d book IDs in sorted order:\n");

    printf("Enter book ID to search: ");
    scanf("%d", &x);
    int res = search(arr, 0, n - 1, x);
    if (res == -1)
        printf("No ID of book Found");
    else
        printf("Found Id is at position/Index %d", res);
    return 0;
}
