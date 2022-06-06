/**
 * @file sum_of_subset.c
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

int flag = 0;
// utility function to display the solutions
void printSolution(int *set, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", set[i]);
    printf("\n");
}

// utility function to find sum of subsets
void subset_sum(int *set, int *temp, int n, int size, int sum, int it, int M)
{
    int i;

    if (M == sum)
    {
        printSolution(temp, size);
        subset_sum(set, temp, n, size - 1, sum - set[it], it + 1, M);
        flag = 1;
    }

    else
    {
        for (i = it; i < n; i++)
        {
            temp[size] = set[i];
            subset_sum(set, temp, n, size + 1, sum + set[i], i + 1, M);
        }
    }
}

// utility function to generate subsets whose sum equals the given target sum
void generateSubsets(int *set, int n, int M)
{
    int *temp = (int *)malloc(n * sizeof(int));
    subset_sum(set, temp, n, 0, 0, 0, M);
    free(temp);
}

int main(void)
{
    int i, *set, n, M;
    printf("Enter the number of components:-\n");
    scanf("%d", &n);

    set = (int *)malloc(n * sizeof(int));
    printf("Enter the components:-\n");
    for (i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter the target sum:-\n");
    scanf("%d", &M);

    printf("\nPossible Solution Subsets\n");
    printf("-------------------------\n");
    generateSubsets(set, n, M);

    if (flag == 0)
        printf("\nThere is no subset that add up to the given target sum\n");
    return 0;
}