#include <stdio.h>

struct date
{
    int day;
    int month;
    int year;
};

struct student
{
    int roll;
    char name[20];
    struct date dob; // Nested structure
};

int main()
{
    struct student s;

    printf("Enter roll: ");
    scanf("%d", &s.roll);
    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Enter date of birth (dd mm yyyy): ");
    scanf("%d %d %d", &s.dob.day, &s.dob.month, &s.dob.year);

    printf("\nStudent Details:\n");
    printf("Roll: %d, Name: %s, DOB: %02d-%02d-%04d\n",
           s.roll, s.name, s.dob.day, s.dob.month, s.dob.year);

    return 0;
}
