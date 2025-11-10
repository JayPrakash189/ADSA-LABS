#include <stdio.h>
#include <string.h>

struct student
{
    int roll;
    char name[20];
};

int main()
{
    struct student s1 = {1, "Avi"};
    struct student s2 = {1, "Avi"};

    if (s1.roll == s2.roll && strcmp(s1.name, s2.name) == 0)
    {
        printf("Both students are same\n");
    }
    else
    {
        printf("Students are different\n");
    }
    return 0;
}
