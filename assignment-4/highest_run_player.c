#include <stdio.h>

struct player
{
    char name[20];
    int runs;
    int wickets;
};

int main()
{
    int n;
    printf("Enter number of players: ");
    scanf("%d", &n);

    struct player P[n];
    int maxRuns = -1, index = -1;

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Name, Runs, Wickets of player %d: ", i + 1);
        scanf("%s %d %d", P[i].name, &P[i].runs, &P[i].wickets);

        if (P[i].runs > maxRuns)
        {
            maxRuns = P[i].runs;
            index = i;
        }
    }

    printf("\nPlayer with highest runs: %s (%d runs)\n",
           P[index].name, P[index].runs);

    return 0;
}
