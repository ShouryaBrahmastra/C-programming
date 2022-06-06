/**
 * @file lcs_part2.c
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

int **a;
char *lcs;

int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

void LCS(char s1[], char s2[], int m, int n)
{
    int i, j, index;
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                a[i][j] = 0;
            else
            {
                if (s1[i - 1] == s2[j - 1])
                    a[i][j] = 1 + a[i - 1][j - 1];
                else
                    a[i][j] = max(a[i][j - 1], a[i - 1][j]);
            }
        }
    }
    index = a[m][n];
    lcs = (char *)malloc((index + 1) * sizeof(char));

    lcs[index] = '\0';
    i = m;
    j = n;
    while (i > 0 && j > 0 && index > 0)
    {
        while (a[i][j] == a[i][j - 1])
        {
            j--;
        }
        while (a[i][j] == a[i - 1][j])
            i--;
        index--;
        lcs[index] = s1[i - 1];
        i--;
        j--;
    }
    printf("%s\n", lcs);

    return;
}

int main(void)
{
    int m, n, i, j, p;
    char *s1, *s2;
    printf("ENTER THE SIZE OF THE 1st STRING :\t");
    scanf("%d", &m);

    s1 = (char *)malloc(m * sizeof(char));
    printf("ENTER THE 1st STRING :\t");
    getchar();

    for (i = 0; i < m; i++)
        scanf("%c", &s1[i]);
    printf("ENTER THE SIZE OF THE 2ND STRING :\t");
    scanf("%d", &n);

    s2 = (char *)malloc(n * sizeof(char));
    printf("ENTER THE 2st STRING :\t");
    getchar();

    for (i = 0; i < n; i++)
        scanf("%c", &s2[i]);
    a = (int **)malloc((m + 1) * sizeof(int *));

    for (i = 0; i < m + 1; i++)
        a[i] = (int *)malloc((n + 1) * sizeof(int));

    LCS(s1, s2, m, n);

    printf("\nThe longest string size is =%d\n", a[m][n]);

    printf("\n");
}
