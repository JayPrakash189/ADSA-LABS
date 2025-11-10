#include <stdio.h>

int main()
{
    int n = 8;
    printf("Enter series length n : \n");
    scanf("%d", &n);
    int int0 = 0;
    int int1 = 1;
    for (int i = 0; i < n; i++)
    {
        if (i < 2)
        {
            printf("%d ", i);
        }
        if (i >= 2)
        {
            int current = int0 + int1;
            int0 = int1;
            int1 = current;
            printf("%d ", current);
        }
    }

    return 0;
}