#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    printf("Enter number of strings: ");
    scanf("%d", &n);
    char s[200][201]; // up to 200 strings of length 200
    for (int i = 0; i < n; ++i)
    {
        scanf(" ");
        fgets(s[i], sizeof(s[i]), stdin);
        size_t len = strlen(s[i]);
        if (len && s[i][len - 1] == '\n')
            s[i][len - 1] = 0;
    }
    if (n == 0)
    {
        printf("\n");
        return 0;
    }

    // Use first string as reference
    int L = strlen(s[0]);
    int prefixLen = L;
    for (int i = 1; i < n; ++i)
    {
        int j = 0;
        while (j < prefixLen && j < (int)strlen(s[i]) && s[0][j] == s[i][j])
            j++;
        prefixLen = j;
        if (prefixLen == 0)
            break;
    }

    if (prefixLen == 0)
        printf("\"\n"); // empty
    else
    {
        char prefix[201];
        strncpy(prefix, s[0], prefixLen);
        prefix[prefixLen] = '\0';
        printf("Longest common prefix: %s\n", prefix);
    }
    return 0;
}
