#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void print_array(int a[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        if (i)
            putchar(' ');
        printf("%d", a[i]);
    }
    putchar('\n');
}

void selection_sort(int a[], int l, int r)
{
    int i, j, min_idx, tmp;
    for (i = l; i <= r; ++i)
    {
        min_idx = i;
        for (j = i + 1; j <= r; ++j)
            if (a[j] < a[min_idx])
                min_idx = j;
        if (min_idx != i)
        {
            tmp = a[i];
            a[i] = a[min_idx];
            a[min_idx] = tmp;
        }
    }
}

/* Merge procedure merging two adjacent sorted runs a[l..m] and a[m+1..r] */
void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    int i, j, k;

    for (i = 0; i < n1; ++i)
        L[i] = a[l + i];
    for (j = 0; j < n2; ++j)
        R[j] = a[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }
    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];

    free(L);
    free(R);
}

int min(int a, int b) { return (a < b) ? a : b; }

int main(void)
{
    int n, chunk;
    int i;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid size\n");
        return 1;
    }

    int *a = (int *)malloc(n * sizeof(int));
    if (!a)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    printf("Enter chunk size (positive integer): ");
    if (scanf("%d", &chunk) != 1 || chunk <= 0)
        chunk = 1;

    printf("\nOriginal array:\n");
    print_array(a, n);

    /* Sort each chunk with selection sort */
    for (i = 0; i < n; i += chunk)
    {
        int l = i;
        int r = min(i + chunk - 1, n - 1);
        selection_sort(a, l, r);
    }

    printf("\nArray after sorting each chunk of size %d:\n", chunk);
    print_array(a, n);

    /* Iteratively merge runs of length 'chunk', doubling run size each pass */
    int run = chunk;
    while (run < n)
    {
        for (i = 0; i < n; i += 2 * run)
        {
            int l = i;
            int m = min(i + run - 1, n - 1);
            int r = min(i + 2 * run - 1, n - 1);
            if (m < r)
                merge(a, l, m, r);
        }
        run *= 2;
    }

    printf("\nFinal merged (fully sorted) array:\n");
    print_array(a, n);

    free(a);
    printf("\nPress any key to exit...");
    getch();
    return 0;
}