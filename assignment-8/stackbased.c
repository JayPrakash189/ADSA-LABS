#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAXN 100
#define STACK_SIZE 1000

typedef struct
{
    int l, r;
    int stage; /* 0 = descend, 1 = merge */
} Frame;

typedef struct
{
    Frame data[STACK_SIZE];
    int top;
} Stack;

void push(Stack *s, Frame f)
{
    if (s->top >= STACK_SIZE)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[s->top++] = f;
    printf("PUSH: [%d, %d], stage=%d\n", f.l, f.r, f.stage);
}

Frame pop(Stack *s)
{
    if (s->top <= 0)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    Frame f = s->data[--s->top];
    printf("POP : [%d, %d], stage=%d\n", f.l, f.r, f.stage);
    return f;
}

int is_empty(Stack *s)
{
    return s->top == 0;
}

/* merge a[l..mid] and a[mid+1..r] into a using temp */
void merge_range(int a[], int l, int mid, int r, int temp[])
{
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= r)
        temp[k++] = a[j++];
    for (i = l; i <= r; ++i)
        a[i] = temp[i];
}

void print_array(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (i)
            printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

/* stack-based simulation of merge process */
void merge_sort_stack(int a[], int n)
{
    if (n <= 1)
        return;
    int *temp = (int *)malloc(sizeof(int) * n);
    if (!temp)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    Stack st;
    st.top = 0;
    push(&st, (Frame){0, n - 1, 0});

    while (!is_empty(&st))
    {
        Frame f = pop(&st);
        int l = f.l, r = f.r;
        if (f.stage == 0)
        {
            if (l < r)
            {
                /* push a frame to merge after children finish */
                push(&st, (Frame){l, r, 1});
                int mid = (l + r) / 2;
                /* push right then left so left is processed first (LIFO) */
                push(&st, (Frame){mid + 1, r, 0});
                push(&st, (Frame){l, mid, 0});
            }
            else
            {
                /* single element - nothing to do */
            }
        }
        else
        { /* stage == 1: children are processed, perform merge */
            int mid = (l + r) / 2;
            printf("MERGE: [%d, %d] with mid=%d\n", l, r, mid);
            merge_range(a, l, mid, r, temp);
            printf("Array after merge [%d..%d]: ", l, r);
            for (int i = l; i <= r; ++i)
            {
                if (i > l)
                    printf(" ");
                printf("%d", a[i]);
            }
            printf("\n");
        }
    }

    free(temp);
}

int main(void)
{
    int n;
    int a[MAXN];

    printf("Enter number of elements (max %d): ", MAXN);
    if (scanf("%d", &n) != 1)
        return 0;
    if (n < 0 || n > MAXN)
    {
        printf("Invalid n\n");
        return 0;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    printf("Initial array: ");
    print_array(a, n);

    merge_sort_stack(a, n);

    printf("Sorted array: ");
    print_array(a, n);

    printf("Press any key to exit...\n");
    getch();
    return 0;
}