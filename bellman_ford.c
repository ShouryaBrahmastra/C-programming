/**
 * @file bellman_ford.c
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
#define INF 9999

// utility function to find single source shortest path using Bellman-Ford's Algorithm
void bellmanFord(int **cost, int n, int start)
{
    int i, u, v, k, *dist, *parent, flag = 1;
    dist = (int *)malloc(n * sizeof(int));
    parent = (int *)malloc(n * sizeof(int));

    // initialize single source
    for (i = 0; i < n; i++)
    {
        dist[i] = INF;
        parent[i] = 0;
    }

    dist[start] = 0;

    for (i = 0; i < n - 1; i++)
    {
        for (u = 0; u < n; u++)
        {
            for (v = 0; v < n; v++)
            {
                if (cost[u][v] != INF)
                {
                    // perform relaxation of edge
                    if (dist[u] + cost[u][v] < dist[v])
                    {
                        dist[v] = dist[u] + cost[u][v];
                        parent[v] = u;
                    }
                }
            }
        }
    }

    for (u = 0; u < n; u++)
    {
        for (v = 0; v < n; v++)
        {
            if (dist[u] + cost[u][v] < dist[v])
                flag = 0;
        }
    }

    if (flag)
    {
        printf("\nSingle Source Shortest Path\n");
        printf("---------------------------\n");
        printf("Vertex \tcost \tParent\n");
        for (i = 0; i < n; i++)
            printf("%d \t%d \t%d\n", i + 1, dist[i], parent[i]);
    }

    else
        printf("Single Source Shortest Path is not possible for this graph. Negative Weight cycle is present.\n");
}

// driver code
int main(void)
{
    int i, j, n, start, **cost;
    printf("Enter the number of vertices:-\n");
    scanf("%d", &n);

    cost = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        cost[i] = (int *)malloc(n * sizeof(int));

    printf("Enter the cost matrix:-\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Enter the starting vertex:-\n");
    scanf("%d", &start);

    bellmanFord(cost, n, start - 1);

    return 0;
}