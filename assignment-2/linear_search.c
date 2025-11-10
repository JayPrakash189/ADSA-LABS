
// // Program A

// #include <stdio.h>

// int linear_search(int arr[], int size, int target)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] == target)
//             return i;
//     }
//     return -1;
// }

// int main()
// {
//     int customer_ids[] = {101, 205, 309, 412, 523};
//     int n = sizeof(customer_ids) / sizeof(customer_ids[0]);
//     int target = 309;

//     int index = linear_search(customer_ids, n, target);

//     if (index != -1)
//         printf("Customer ID %d found at index %d.\n", target, index);
//     else
//         printf("Customer ID %d not found.\n", target);

//     return 0;
// }

//  Program B
#include <stdio.h>

int linear_search_sentinel(int arr[], int n, int key)
{
    int last = arr[n - 1];
    arr[n - 1] = key; // Set sentinel

    int i = 0;
    while (arr[i] != key)
    {
        i++;
    }

    arr[n - 1] = last; // Restore last element

    if (i < n - 1 || arr[n - 1] == key)
        return i; // Found at index i
    else
        return -1; // Not found
}
int main()
{
    int customers[] = {101, 203, 305, 407, 509};
    int n = sizeof(customers) / sizeof(customers[0]);
    int key = 305;

    int index = linear_search_sentinel(customers, n, key);

    if (index != -1)
        printf("Customer ID %d found at index %d.\n", key, index);
    else
        printf("Customer ID %d not found.\n", key);

    return 0;
}
