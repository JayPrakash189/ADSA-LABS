#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    int i, count = 0;
    printf("Enter any string/word of upto 100 chars : \n");
    scanf("%s", s);
    for (i = 0; s[i]; i++)
    {
        char c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            count++;
    }
    printf("Found vowel count is : %d", count);
    return 0;
}
