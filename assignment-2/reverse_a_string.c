#include <stdio.h>
#include <string.h>

// // Function to reverse a string in-place using two-pointer technique
// void reverseString(char *str)
// {
//     int left = 0;
//     int right = strlen(str) - 1;
//     while (left < right)
//     {
//         // Swap characters
//         char temp = str[left];
//         str[left] = str[right];
//         str[right] = temp;
//         left++;
//         right--;
//     }
// }

// int main()
// {
//     char username[100];
//     printf("Enter username: ");
//     scanf("%99s", username);
//     reverseString(username);
//     printf("Reversed username: %s\n", username);
//     return 0;
// }

// Program B
#include <stdio.h>
#include <string.h>

void reverse_string(const char *input, char *output)
{
    size_t len = strlen(input);
    for (size_t i = 0; i < len; ++i)
    {
        output[i] = input[len - 1 - i];
    }
    output[len] = '\0';
}

int main()
{
    char username[] = "ADSA LAB";
    char reversed[sizeof(username)];

    reverse_string(username, reversed);

    printf("Original: %s\n", username);
    printf("Reversed: %s\n", reversed);

    return 0;
}
