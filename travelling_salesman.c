/**
 * @file travelling_salesman.c
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

int min_cost = 0; // to store the minimum travel cost

// utility function to find the next place to visit via best effective path
int least(int **cost, int *visited, int n, int a)
{
    int i, c = INT_MAX;
    int min = INT_MAX, kmin;

    for (i = 0; i < n; i++)
    {
        if (cost[a][i] != 0 && visited[i] == 0)
        {
            if (cost[a][i] + cost[i][a] < min)
            {
                min = cost[i][0] + cost[a][i];
                kmin = cost[a][i];
                c = i;
            }
        }
    }

    if (min != INT_MAX)
        min_cost += kmin;

    return c;
}

// utility function to compute the best cost-effective path for the salesman to travel at minimum travel cost
void minCost(int **cost, int *visited, int n, int a)
{
    int i, b;

    visited[a] = 1; // marking the place already visited
    printf("%d---->", a + 1);
    b = least(cost, visited, n, a);

    if (b == INT_MAX)
    {
        b = 0;
        printf("%d", b + 1);
        min_cost += cost[a][b];
        return;
    }

    minCost(cost, visited, n, b);
}

// driver code
int main(void)
{
    int n, i, j;
    scanf("%d", &n); // number of places that the salesman has to visit

    int **cost = (int **)malloc(n * sizeof(int *)); // the cost matrix
    for (i = 0; i < n; i++)
        cost[i] = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]); // accepting the cost matrix
    }

    int *visited = (int *)malloc(n * sizeof(int)); // array to store the places already visited by the salesman
    for (i = 0; i < n; i++)
        visited[i] = 0;

    minCost(cost, visited, n, 0);
    printf("\n%d\n", min_cost);
    return 0;
}