/**
 * @file dijkstras_algo.c
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

// utility function to implement Dijkstra's Shortest Path Algorithm
void dijkstra(int **cost, int n, int start)
{
    int *dist, *pred, *visited, c, min_dist, next, i, j;

    dist = (int *)malloc(n * sizeof(int));
    pred = (int *)malloc(n * sizeof(int));
    visited = (int *)malloc(n * sizeof(int));

    cost = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        cost[i] = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        dist[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    dist[start] = 0;
    visited[start] = 1;
    c = 1;

    while (c < (n - 1))
    {
        min_dist = INF;

        for (i = 0; i < n; i++)
        {
            if (dist[i] < min_dist && !visited[i])
            {
                min_dist = dist[i];
                next = i;
            }
        }

        visited[next] = 1;
        for (i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (min_dist + cost[next][i] < dist[i])
                {
                    dist[i] = min_dist + cost[next][i];
                    pred[i] = next;
                }
            }
            c++;
        }

        for (i = 0; i < n; i++)
        {
            if (i != start)
                printf("\nDistance from source to %d: %d", i + 1, dist[i]);
        }
    }
}

// driver code
int main(void)
{
    int n, i, j, start;
    printf("Enter the number of vertices:-\n");
    scanf("%d", &n);

    int **cost = (int **)malloc(n * sizeof(int *));

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

    printf("\nSingle Source Shortest Path\n");
    printf("---------------------------\n");
    dijkstra(cost, n, start - 1);

    return 0;
}