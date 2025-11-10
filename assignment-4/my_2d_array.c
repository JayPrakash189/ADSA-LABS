#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int rows;
    int cols;
    int **data;
};

int main()
{
    struct Matrix m;
    printf("Enter rows and cols: ");
    scanf("%d %d", &m.rows, &m.cols);

    // Allocate memory for row pointers
    m.data = (int **)malloc(m.rows * sizeof(int *));
    if (m.data == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Allocate memory for each row
    for (int i = 0; i < m.rows; i++)
    {
        m.data[i] = (int *)malloc(m.cols * sizeof(int));
        if (m.data[i] == NULL)
        {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }

    printf("Enter elements:\n");
    for (int i = 0; i < m.rows; i++)
    {
        for (int j = 0; j < m.cols; j++)
        {
            scanf("%d", &m.data[i][j]);
        }
    }

    printf("\nMatrix:\n");
    for (int i = 0; i < m.rows; i++)
    {
        for (int j = 0; j < m.cols; j++)
        {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < m.rows; i++)
    {
        free(m.data[i]);
    }
    // Free memory
    for (int i = 0; i < m.rows; i++)
    {
        free(m.data[i]);
    }
    free(m.data);

    return 0;
}