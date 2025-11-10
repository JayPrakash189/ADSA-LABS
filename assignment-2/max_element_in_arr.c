
// // Program A
// #include <stdio.h>
// int find_max(int arr[], int n)
// {
//     int max = arr[0];
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] > max)
//         {
//             max = arr[i];
//         }
//     }
//     return max;
// }
// int main()
// {
//     int temperatures[7] = {23, 27, 21, 30, 25, 28, 26};
//     int max_temp = find_max(temperatures, 7);
//     printf("Maximum temperature of the week: %d\n", max_temp);
//     return 0;
// }

// Program B
#include <stdio.h>
int main()
{
    int temps[] = {23, 29, 21, 25, 30, 27, 24};
    int n = sizeof(temps) / sizeof(temps[0]);

    for (int i = 1; i < n; i++)
    {
        int key = temps[i];
        int j = i - 1;
        while (j >= 0 && temps[j] > key)
        {
            temps[j + 1] = temps[j];
            j--;
        }
        temps[j + 1] = key;
    }
    int max_temp = temps[n - 1];
    printf("Maximum temperature: %d\n", max_temp);
    return 0;
}
