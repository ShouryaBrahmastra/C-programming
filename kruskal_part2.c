/**
 * @file kruskal_part2.c
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
struct edge
{
    int i;
    int j;
    int wt;
};
void sort(struct edge *id, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (id[j].wt > id[j + 1].wt)
            {
                struct edge temp = id[j];
                id[j] = id[j + 1];
                id[j + 1] = temp;
            }
        }
    }
}
int findPar(int u, int *parent)
{

    if (u == parent[u])
    {
        return u;
    }

    return parent[u] = findPar(parent[u], parent);
}
void unionn(int u, int v, int *parent, int *rank)
{

    int i = findPar(u, parent);
    int j = findPar(v, parent);

    if (rank[i] < rank[j])
    {
        parent[i] = j;
    }

    else if (rank[i] > rank[j])
    {
        parent[j] = i;
    }

    else
    {
        parent[i] = j;
        rank[j]++;
    }
}
int main()
{
    int n, x = 0, k = 0;
    scanf("%d", &n);

    struct edge *id = (struct edge *)malloc((n * n) * sizeof(struct edge));

    struct edge *ans = (struct edge *)malloc((n * n) * sizeof(struct edge));

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &x);

            if (x != 0)
            {
                id[k].i = i;
                id[k].j = j;
                id[k].wt = x;
                k++;
            }
        }
    }

    sort(id, k);

    int *parent = (int *)malloc((n + 1) * sizeof(int));

    int *rank = (int *)malloc((n + 1) * sizeof(int));

    for (int i = 1; i <= n; i++)
    {

        parent[i] = i;
        rank[i] = 0;
    }

    int l = 0, cost = 0;
    for (int i = 0; i < k; i++)
    {

        if (findPar(id[i].i, parent) != findPar(id[i].j, parent))
        {
            cost += id[i].wt;
            ans[l].i = id[i].i;
            ans[l].j = id[i].j;
            ans[l].wt = id[i].wt;
            l++;
            unionn(id[i].i, id[i].j, parent, rank);
        }
    }

    printf("\n");

    for (int i = 0; i < l; i++)
    {
        printf("%d %d %d\n", ans[i].i, ans[i].j, ans[i].wt);
    }
    printf("%d\n", cost);
    return 0;
}
