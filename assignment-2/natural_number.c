
// // Program A
// #include <stdio.h>
// int main()
// {
//     int n;
//     printf("Enter n: ");
//     scanf("%d", &n);

//     for (int i = 1; i <= n; i++)
//     {
//         printf("%d ", i);
//     }
//     printf("\n");
//     return 0;
// }

// Program B
#include <stdio.h>
void print_natural_numbers_recursion(int n)
{
    if (n == 0)
        return;
    print_natural_numbers_recursion(n - 1);
    printf("%d ", n);
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    printf("Using recursion: ");
    print_natural_numbers_recursion(n);
    printf("\n");

    return 0;
}
