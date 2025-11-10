#include <stdio.h>
#include <stdlib.h>

struct student
{
    int id;
    char name[20];
};

int main()
{
    int n = 3;
    struct student *arr1 = (struct student *)malloc(n * sizeof(struct student));
    struct student *arr2 = (struct student *)calloc(n, sizeof(struct student));

    printf("Using malloc: id[0] = %d\n", arr1[0].id); // Garbage
    printf("Using calloc: id[0] = %d\n", arr2[0].id); // Zero

    free(arr1);
    free(arr2);
    return 0;
}
