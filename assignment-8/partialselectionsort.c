#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Partial selection sort: sorts only the first k smallest elements in ascending order */
void partial_selection_sort(int arr[], int n, int k)
{
    if (k <= 0 || n <= 0)
        return;
    if (k > n)
        k = n;

    for (int i = 0; i < k; ++i)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
        {
            int tmp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = tmp;
        }
    }
}

void print_array(const int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d%c", arr[i], (i + 1 < n) ? ' ' : '\n');
    }
}

int main(void)
{
    int n, k;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid size.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integer elements:\n", n);
    for (int i = 0; i < n; ++i)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid input.\n");
            free(arr);
            return 1;
        }
    }

    printf("Enter k (number of smallest elements to sort): ");
    if (scanf("%d", &k) != 1)
    {
        printf("Invalid k.\n");
        free(arr);
        return 1;
    }

    printf("Before partial sort:\n");
    print_array(arr, n);

    partial_selection_sort(arr, n, k);

    printf("After partial sort (first %d elements are the k smallest in ascending order):\n", k < 0 ? 0 : (k > n ? n : k));
    print_array(arr, n);

    free(arr);

    printf("Press any key to exit...\n");
    getch();
    return 0;
}