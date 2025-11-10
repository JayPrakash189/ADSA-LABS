#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    char name[100];
    double salary;
    char department[50];
} Employee;

int main()
{
    int n;
    printf("Enter number of employees: ");
    if (scanf("%d", &n) != 1 || n <= 0)
        return 0;
    Employee emps[n];

    for (int i = 0; i < n; ++i)
    {
        printf("Employee %d id: ", i + 1);
        scanf("%d", &emps[i].id);
        printf("Name: ");
        scanf(" ");
        fgets(emps[i].name, sizeof(emps[i].name), stdin);
        size_t len = strlen(emps[i].name);
        if (len && emps[i].name[len - 1] == '\n')
            emps[i].name[len - 1] = 0;
        printf("Salary: ");
        scanf("%lf", &emps[i].salary);
        printf("Department: ");
        scanf(" ");
        fgets(emps[i].department, sizeof(emps[i].department), stdin);
        len = strlen(emps[i].department);
        if (len && emps[i].department[len - 1] == '\n')
            emps[i].department[len - 1] = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        if (strcmp(emps[i].department, "IT") == 0 || strcmp(emps[i].department, "it") == 0)
        {
            emps[i].salary *= 1.10; // increase by 10%
        }
    }

    printf("Updated employees:\n");
    for (int i = 0; i < n; ++i)
    {
        printf("ID:%d Name:%s Dept:%s Salary:%.2f\n", emps[i].id, emps[i].name, emps[i].department, emps[i].salary);
    }
    return 0;
}
