
// Program A
#include <stdio.h>
#include <ctype.h>

int count_vowels(const char *str)
{
    int count = 0;
    while (*str)
    {
        char c = tolower((unsigned char)*str);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count++;
        str++;
    }
    return count;
}

int main()
{
    char comment[256];
    printf("Enter a comment: ");
    if (fgets(comment, sizeof(comment), stdin))
    {
        int vowels = count_vowels(comment);
        printf("Number of vowels: %d\n", vowels);
    }
    return 0;
}

// // B) Code:
// #include <stdio.h>
// #include <string.h>

// int count_vowels(const char *str)
// {
//     // Lookup table for vowels
//     const unsigned char is_vowel[256] = {
//         ['a'] = 1, ['e'] = 1, ['i'] = 1, ['o'] = 1, ['u'] = 1, ['A'] = 1, ['E'] = 1, ['I'] = 1, ['O'] = 1, ['U'] = 1};
//     int count = 0;
//     while (*str)
//     {
//         if (is_vowel[(unsigned char)*str])
//             count++;
//         str++;
//     }
//     return count;
// }

// int main()
// {
//     char comment[1024];
//     printf("Enter a comment: ");
//     if (fgets(comment, sizeof(comment), stdin))
//     {
//         comment[strcspn(comment, "\n")] = 0; // Remove newline
//         printf("Number of vowels: %d\n", count_vowels(comment));
//     }
//     return 0;
// }
