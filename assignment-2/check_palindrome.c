// // Code A
// #include <stdio.h>
// #include <string.h>

// int isPalindromeStr(int num)
// {
//     char str[20];
//     sprintf(str, "%d", num);
//     int left = 0;
//     int right = strlen(str) - 1;

//     while (left < right)
//     {
//         if (str[left] != str[right])
//         {
//             return 0;
//         }
//         left++;
//         right--;
//     }
//     return 1;
// }

// int main()
// {
//     int number;
//     printf("Enter a number: ");
//     scanf("%d", &number);

//     if (isPalindromeStr(number))
//         printf("%d is a palindrome\n", number);
//     else
//         printf("%d is not a palindrome\n", number);
//     return 0;
// }

// Code B
#include <stdio.h>

int isPalindrome(int num)
{
    if (num < 0)
        return 0;

    int original = num;
    int reverse = 0;

    while (num != 0)
    {
        int digit = num % 10;
        reverse = reverse * 10 + digit;
        num /= 10;
    }

    return original == reverse;
}
int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (isPalindrome(number))
        printf("%d is a palindrome\n", number);
    else
        printf("%d is not a palindrome\n", number);
    return 0;
}
