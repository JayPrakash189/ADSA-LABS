#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[100];
    int rollNumber;
    float marks;
} Student;

int main()
{
    int n;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0)
        return 0;
    Student students[n];

    for (int i = 0; i < n; ++i)
    {
        printf("Student %d name: ", i + 1);
        scanf(" "); // eat whitespace
        fgets(students[i].name, sizeof(students[i].name), stdin);
        // strip newline
        size_t len = strlen(students[i].name);
        if (len && students[i].name[len - 1] == '\n')
            students[i].name[len - 1] = '\0';

        printf("Roll number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    int idx = 0;
    for (int i = 1; i < n; ++i)
    {
        if (students[i].marks > students[idx].marks)
            idx = i;
    }

    printf("Top student:\nName: %s\nRoll: %d\nMarks: %.2f\n",
           students[idx].name, students[idx].rollNumber, students[idx].marks);
    return 0;
}
