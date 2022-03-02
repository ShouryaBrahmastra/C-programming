/**
 * @file prims_algo.c
 * @author https://github.com/ShouryaBrahmastra
 * @brief
 *
 * You are given a graph. Your task is to find the Minimum Spanning Tree
 * from the graph using Prim’s algorithm.
 *
 * In the input section, the first line provides you the number of vertices of the graph N.
 * The costs of edges corresponding to a vertex with other connected vertices are provided through a
 * square matrix NxN in the next consecutive N lines.
 * In the output section, the information about the selected edges with their corresponding weight will
 * be displayed followed by the total minimum cost.
 *
 * Sample input:
 *
 * 5
 *
 *           0 0 3 0 0
 *
 *           0 0 10 4 0
 *
 *           3 10 0 2 6
 *
 *           0 4 2 0 1
 *
 *           0 0 6 1 0
 *
 *           Sample output:
 *
 *          3 1 4
 *
 *          0 2 3
 *
 *          2 3 2
 *
 *          3 4 1
 *
 *          10
 * @version 0.1
 * @date 2022-03-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

const int N = 999999;

/* create prim() method for constructing and printing the MST.
The g[verti][verti] is an adjacency matrix that defines the graph for MST.*/
void prim(int verti, int g[][verti])
// void prim(int verti, int g[][])
{
    /* create array of size equal to total number of verti for storing the MST*/
    int parent[verti];
    /* create mw[verti] array for selecting an edge having mini weight*/
    int mw[verti];
    int mst[verti];
    int count, edge, v, tw = 0; /*Here 'v' is the vertex, tw = total weight*/
    for (int i = 0; i < verti; i++)
    {
        mw[i] = N;
        mst[i] = 0;
    }
    mw[0] = 0;      /*It select as first vertex*/
    parent[0] = -1; /* set first value of parent[] array to -1 to make it root of MST*/
    for (count = 0; count < verti - 1; count++)
    {
        /*select the vertex having mini weight and that is not added in the MST yet from the set of verti*/
        edge = mini_span(verti, mw, mst);
        mst[edge] = 1;
        for (v = 0; v < verti; v++)
            if (g[edge][v] && mst[v] == 0 && g[edge][v] < mw[v])
                parent[v] = edge, mw[v] = g[edge][v];
    }
    /*Print the constructed mini spanning tree*/
    for (int i = 1; i < verti; i++)
    {
        printf("%d %d %d\n", parent[i], i, g[i][parent[i]]);
        tw += g[i][parent[i]];
    }
    printf("%d\n", tw);
}

/* create mini_span() method for finding the vertex that has mini key-value and that is not added in MST yet */
int mini_span(int verti, int mw[], int mst[])
{
    int mini = N, min, i;
    /*iterate over all verti to find the vertex with mini key-value*/
    for (i = 0; i < verti; i++)
        if (mst[i] == 0 && mw[i] < mini)
            mini = mw[i], min = i;
    return min;
}

// driver code
int main(void)
{
    int verti;
    scanf("%d", &verti);
    // n -= 1;
    int arr[verti][verti];
    for (int i = 0; i < verti; i++)
    {
        for (int j = 0; j < verti; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    prim(verti, arr);
    return 0;
}