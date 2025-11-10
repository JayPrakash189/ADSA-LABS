#include <stdio.h>
int main()
{
    int unitsCosumed;
    int bill = 0;
    printf("Enter the total units consumed : \n");
    scanf("%d", &unitsCosumed);
    if (unitsCosumed <= 100)
        bill = unitsCosumed * 5;
    else if (unitsCosumed <= 200)
        bill = 100 * 5 + (unitsCosumed - 100) * 7;
    else
        bill = 100 * 5 + 100 * 7 + (unitsCosumed - 200) * 10;
    printf("Total electric bill is Rs %d.", bill);
    return 0;
}
