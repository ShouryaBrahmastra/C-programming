/**
 * @file floyd_warshall.c
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
#include <limits.h>

#define INF 9999
#define min(a, b) a < b ? a : b

// utility function to find all pair shortest path using Floyd-Warshall algorithm
void floydWarshall(int **cost, int n)
{
    int i, j, k;

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]); // calculate the shortest path taking into account the intermediate vertex
        }
    }

    printf("\nAll-Pair Shortest Path\n");
    printf("----------------------\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (cost[i][j] == INF)
                printf("INF ");

            else
                printf("%d ", cost[i][j]);
        }

        printf("\n");
    }
}

// driver code
int main(void)
{
    int i, j, n, **cost, **sdist;

    printf("Enter the number of vertices:-\n");
    scanf("%d", &n);

    cost = (int **)malloc(n * sizeof(int *));
    sdist = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        cost[i] = (int *)malloc(n * sizeof(int));
        sdist[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the cost matrix (To enter INFINITY input 9999):-\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            sdist[i][j] = cost[i][j];
        }
    }

    floydWarshall(sdist, n);

    return 0;
}
