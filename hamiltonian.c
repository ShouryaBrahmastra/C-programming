/**
 * @file hamiltonian.c
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

// Number of vertices in the graph
#define V 5

// utility function to print solution
void printSolution(int *path, int n)
{
    int i;
    printf("\nSolution Exists. Following is one Hamiltonian Cycle:-\n");
    for (i = 0; i < n; i++)
        printf(" %d ", path[i]);

    // print the first vertex again to show the complete cycle
    printf(" %d", path[0]);
    printf("\n");
}

// utility function to check if the vertex v can be added at index 'pos' in the Hamiltonian Cycle constructed so far
int isValid(int v, int **graph, int *path, int pos)
{
    int i;
    // check if this vertex is an adjacent vertex of the previously added vertex
    if (graph[path[pos - 1]][v] == 0)
        return 0;

    // check if the vertex has already been included.
    for (i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;
    return 1;
}

// recursive utility function to solve hamiltonian cycle problem
int hamCycleUtil(int **graph, int n, int *path, int pos)
{
    int v;
    // base case: If all vertices are included in Hamiltonian Cycle
    if (pos == n)
    {
        // and if there is an edge from the last included vertex to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1)
            return 1;
        else
            return 0;
    }

    // try different vertices as a next candidate in Hamiltonian Cycle except starting point
    for (v = 1; v < n; v++)
    {
        // check if this vertex can be added to Hamiltonian Cycle
        if (isValid(v, graph, path, pos))
        {
            path[pos] = v;

            // recur to construct rest of the path
            if (hamCycleUtil(graph, n, path, pos + 1) == 1)
                return 1;

            // if adding vertex v doesn't lead to a solution, then remove it
            path[pos] = -1;
        }
    }

    // if no vertex can be added to Hamiltonian Cycle constructed so far, then return false
    return 0;
}

// function to solve the Hamiltonian Cycle problem using Backtracking
int hamCycleAlgo(int **graph, int n)
{
    int i;
    int *path = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        path[i] = -1;

    // put vertex 0 as the first vertex in the path. If there is a Hamiltonian Cycle, then the path can be started from any point of the cycle as the graph is undirected
    path[0] = 0;
    if (hamCycleUtil(graph, n, path, 1) == 0)
    {
        printf("\nSolution does not exist. No Hamiltonian Cycle is present.");
        return 0;
    }

    printSolution(path, n);
    return 0;
}

// driver program to test above function
int main(void)
{
    int i, j, n, **graph;
    printf("Enter the number of vertices:-\n");
    scanf("%d", &n);

    graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        graph[i] = (int *)malloc(n * sizeof(int));

    printf("Enter the Adjacency Matrix:-\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    hamCycleAlgo(graph, n);

    return 0;
}
