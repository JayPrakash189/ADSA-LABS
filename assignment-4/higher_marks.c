#include <stdio.h>

struct student
{
    int roll;
    char name[20];
    int marks;
};

int main()
{
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct student S[n];
    int highest = -1, index = -1;

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Roll, Name, Marks of student %d: ", i + 1);
        scanf("%d %s %d", &S[i].roll, S[i].name, &S[i].marks);

        if (S[i].marks > highest)
        {
            highest = S[i].marks;
            index = i;
        }
    }

    printf("\nHighest Marks = %d by %s (Roll %d)\n",
           S[index].marks, S[index].name, S[index].roll);

    return 0;
}
