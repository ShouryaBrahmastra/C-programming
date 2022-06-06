/**
 * @file longest_common_subsequence.c
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
#include <string.h>

// max function
#define max(a, b) a > b ? a : b

// utility function to find the longest common subsequence and its length
void lcsAlgo(char *a, char *b, int m, int n)
{
    int i, j, **table;

    table = (int **)malloc((m + 1) * sizeof(int *));
    for (i = 0; i <= m; i++)
        table[i] = (int *)malloc((n + 1) * sizeof(int));

    // filling the first row and first columns with 0's
    for (i = 0; i <= m; i++)
        table[i][0] = 0;
    for (j = 0; j <= n; j++)
        table[0][j] = 0;

    // filling up the table from bottom-up
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
                table[i][j] = table[i - 1][j - 1] + 1;

            else
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }

    int index = table[m][n];
    char *lcs = (char *)malloc((index + 1) * sizeof(char));
    lcs[index] = '\0';

    i = m, j = n;

    // retracing the table to find the LCS
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcs[index - 1] = a[i - 1];
            i--;
            j--;
            index--;
        }

        else if (table[i - 1][j] > table[i][j - 1])
            i--;
        else
            j--;
    }

    printf("Sequence 1: %s\nSequence 2: %s\n", a, b);
    printf("LCS: %s\n", lcs);
    printf("Length of LCS = %ld\n", strlen(lcs));
}

// driver code
int main(void)
{
    char *a, *b;
    int m, n;

    printf("Enter the length of the 1st string:-\n");
    scanf("%d", &m);
    a = (char *)malloc(m * sizeof(char));
    getchar();
    printf("Enter the 1st string:-\n");
    scanf("%s", a);

    printf("Enter the length of the 2nd string:-\n");
    scanf("%d", &n);
    b = (char *)malloc(n * sizeof(char));
    getchar();
    printf("Enter the 2nd string:-\n");
    scanf("%s", b);

    lcsAlgo(a, b, m, n);

    return 0;
}