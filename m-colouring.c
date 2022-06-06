/**
 * @file m-colouring.c
 * @author https://github.com/ShouryaBrahmastra
 * @brief
 * @version 0.1
 * @date 2022-06-06
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

int count = 0, flag = 0; // global variables

void nextValue(int **graph, int *x, int m, int n, int k)
{
    int j;
    while (1)
    {
        x[k] = (x[k] + 1) % (m + 1);

        if (x[k] == 0)
            return;

        for (j = 1; j <= n; j++)
        {
            if (graph[k][j] == 1 && x[k] == x[j])
                break;
        }

        if (j == (n + 1))
            return;
    }
}

// utility function to find chromatic number and possible graph colouring solutions
void graphColoring(int **graph, int *x, int m, int n, int k)
{
    int i;
    while (1)
    {
        nextValue(graph, x, m, n, k);
        if (x[k] == 0)
            return;

        if (k == n)
        {
            flag = 1;

            for (i = 1; i <= n; i++)
                printf("%d ", x[i]);
            printf("\n");

            count++;
        }

        else
            graphColoring(graph, x, m, n, k + 1);
    }
}

// driver code
int main(void)
{
    int i, j, m, n, **graph, *x;
    printf("Enter the number of vertices:-\n");
    scanf("%d", &n);

    x = (int *)malloc((n + 1) * sizeof(int));
    graph = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i < (n + 1); i++)
        graph[i] = (int *)malloc((n + 1) * sizeof(int));

    printf("Enter the Adjacency Matrix:-\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            scanf("%d", &graph[i][j]);
    }

    printf("\nPossible Solutions\n");
    printf("------------------\n");
    for (m = 1; m <= n; m++)
    {
        if (flag == 1)
            break;

        graphColoring(graph, x, m, n, 1);
    }

    printf("\nThe chromatic number = %d", m - 1);
    printf("\nThe total number of solutions = %d", count);

    return 0;
}