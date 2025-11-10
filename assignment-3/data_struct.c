#include <stdio.h>

typedef struct
{
    int day;
    int month;
    int year;
} Date;

int compareDates(const Date *a, const Date *b)
{
    if (a->year != b->year)
        return (a->year < b->year) ? -1 : 1;
    if (a->month != b->month)
        return (a->month < b->month) ? -1 : 1;
    if (a->day != b->day)
        return (a->day < b->day) ? -1 : 1;
    return 0;
}

int main()
{
    Date d1, d2;
    printf("Enter date1 (day month year): ");
    scanf("%d %d %d", &d1.day, &d1.month, &d1.year);
    printf("Enter date2 (day month year): ");
    scanf("%d %d %d", &d2.day, &d2.month, &d2.year);

    int cmp = compareDates(&d1, &d2);
    if (cmp < 0)
        printf("Date1 is earlier.\n");
    else if (cmp > 0)
        printf("Date2 is earlier.\n");
    else
        printf("Both dates are the same.\n");
    return 0;
}
