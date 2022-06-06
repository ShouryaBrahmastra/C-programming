/**
 * @file bin_packing_algo.c
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

// returns minimum number of bins required
int minimizeBin(int *wt, int n, int c)
{
    int ans = 0, i;

    // array to store remaining space in bins
    int *bin_rem = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        // find the best bin that can accomodate wt[i]
        int j;

        // initialize minimum space left and index of best bin
        int min = c + 1, bi = 0;

        for (j = 0; j < ans; j++)
        {
            if (bin_rem[j] >= wt[i] && bin_rem[j] - wt[i] < min)
            {
                bi = j;
                min = bin_rem[j] = wt[i];
            }
        }

        // if no bin could accomodate wt[i], create new bin
        if (min == c + 1)
        {
            bin_rem[ans] = c - wt[i];
            ans++;
        }

        else // assign the item to best bin
            bin_rem[bi] -= wt[i];
    }

    return ans;
}

// driver code
int main(void)
{
    int n, i;
    int m;
    scanf("%d", &n); // accepting total number of items

    int *wt = (int *)malloc(n * sizeof(int)); // creating an array to store weights

    for (i = 0; i < n; i++)
        scanf("%d", &wt[i]); // accepting the weight of each item

    scanf("%d", &m); // accepting the maximum capacity of each bin

    printf("%d\n", minimizeBin(wt, n, m)); // calling minimizeBin function to display minimum bins used

    return 0;
}
