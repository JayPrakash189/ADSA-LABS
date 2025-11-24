#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (i)
            putchar(' ');
        printf("%d", arr[i]);
    }
    putchar('\n');
}

void selectionSortWithProgress(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if (minIdx != i)
        {
            int tmp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = tmp;
        }
        printf("After iteration %d: ", i + 1);
        printArray(arr, n);
    }
}

int main(void)
{
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        fprintf(stderr, "Invalid size\n");
        return 1;
    }

    int *arr = malloc(sizeof(int) * n);
    if (!arr)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            fprintf(stderr, "Invalid input\n");
            free(arr);
            return 1;
        }
    }

    printf("Initial array: ");
    printArray(arr, n);

    selectionSortWithProgress(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    free(arr);
    printf("Press any key to exit...\n");
    getch(); /* waits for a keypress (conio.h) */
    return 0;
}