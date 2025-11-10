// A) Code:
#include <stdio.h>
int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("a = %d, b = %d\n", a, b);
    return 0;
}

// // Code B
// #include <stdio.h>
// int main()
// {
//     int a, b;
//     printf("Enter two numbers: ");
//     scanf("%d %d", &a, &b);
//     a = a ^ b;
//     b = a ^ b;
//     a = a ^ b;
//     printf("After swap: a = %d, b = %d\n", a, b);
//     return 0;
// }
