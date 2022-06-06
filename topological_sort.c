/**
 * @file topological_sort.c
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

void topologicalSort(int **mat, int n)
{
    int i, j, k, *indeg, *flag, count = 0;
    indeg = (int *)malloc(n * sizeof(int));
    flag = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        indeg[i] = 0;
        flag[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            indeg[i] = indeg[i] + mat[j][i];
    }

    printf("\nThe topological order is:-\n");

    while (count < n)
    {
        for (k = 0; k < n; k++)
        {
            if ((indeg[k] == 0) && (flag[k] == 0))
            {
                printf("%d ", (k + 1));
                flag[k] = 1;
            }

            for (i = 0; i < n; i++)
            {
                if (mat[i][k] == 1)
                    indeg[k]--;
            }
        }
        count++;
    }
}

// driver code
int main(void)
{
    int i, j, n, **mat;

    printf("Enter the number of vertices:-\n");
    scanf("%d", &n);

    mat = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        mat[i] = (int *)malloc(n * sizeof(int));

    printf("Enter the Adjacency matrix:-\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);
    }

    topologicalSort(mat, n);

    return 0;
}