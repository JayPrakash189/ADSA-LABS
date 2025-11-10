

#include <stdio.h>
#include <stdlib.h>

struct student
{
    int roll;
    char name[20];
};

int main()
{
    int n, extra;
    printf("Enter initial number of students: ");
    scanf("%d", &n);

    struct student *S = (struct student *)malloc(n * sizeof(struct student));

    for (int i = 0; i < n; i++)
    {
        printf("Enter Roll and Name of student %d: ", i + 1);
        scanf("%d %s", &S[i].roll, S[i].name);
    }

    printf("\nEnter number of extra students: ");
    scanf("%d", &extra);

    S = (struct student *)realloc(S, (n + extra) * sizeof(struct student));

    for (int i = n; i < n + extra; i++)
    {
        printf("Enter Roll and Name of student %d: ", i + 1);
        scanf("%d %s", &S[i].roll, S[i].name);
    }

    printf("\n--- All Students ---\n");
    for (int i = 0; i < n + extra; i++)
    {
        printf("Roll: %d, Name: %s\n", S[i].roll, S[i].name);
    }

    free(S);
    return 0;
}
