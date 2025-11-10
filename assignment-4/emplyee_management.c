#include <stdio.h>
#include <stdlib.h> // For malloc() and free()

struct employee
{
    int id;
    char name[20];
};

int main()
{
    // struct employee a;
    int emp_size;

    printf("---Emplyee management system---\n");
    printf("Enter the number of Employee : \n");
    scanf("%d", &emp_size);

    struct employee *E = (struct employee *)malloc(emp_size * sizeof(struct employee));
    if (E == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < emp_size; i++)
    {
        printf("\nEnter Employee %d Id: ", i + 1);
        scanf("%d", &E[i].id);

        printf("Enter Employee %d Name: ", i + 1);
        scanf("%s", E[i].name);
    }

    printf("\n--- Employee Details ---\n");
    for (int i = 0; i < emp_size; i++)
    {
        printf("Employee %d: Id = %d, Name = %s\n", i + 1, E[i].id, E[i].name);
    }

    free(E);
    return 0;
}