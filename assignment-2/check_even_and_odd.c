// // Program A

// #include <stdio.h>
// int main()
// {
//     int numbers[] = {10, 23, 45, 66, 77, 88};
//     int size = sizeof(numbers) / sizeof(numbers[0]);
//     for (int i = 0; i < size; i++)
//     {
//         if (numbers[i] % 2 == 0)
//         {
//             printf("%d is Even\n", numbers[i]);
//         }
//         else
//         {
//             printf("%d is Odd\n", numbers[i]);
//         }
//     }
//     return 0;
// }

//  Program B
#include <stdio.h>
int main()
{
    int numbers[] = {10, 23, 45, 66, 77, 88};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < size; i++)
    {
        if (numbers[i] & 1)
            printf("%d is Odd\n", numbers[i]);
        else
            printf("%d is Even\n", numbers[i]);
    }
    return 0;
}
