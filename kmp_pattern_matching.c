/**
 * @file kmp_pattern_matching.c
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

void prefixSuffixArray(char *pat, int M, int *pps)
{
    int length = 0, i = 1;
    pps[0] = 0;

    while (i < M)
    {
        if (pat[i] == pat[length])
        {
            length++;
            pps[i] = length;
            i++;
        }

        else
        {
            if (length != 0)
                length = pps[length - 1];
            else
            {
                pps[i] = 0;
                i++;
            }
        }
    }
}

// utility function to find pattern using KMP Algorithm
void KMPAlgo(char *text, char *pattern, int N, int M)
{
    int i, j;
    int *pps = (int *)malloc(M * sizeof(int));
    prefixSuffixArray(pattern, M, pps);

    i = 0, j = 0;
    while (i < N)
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            printf("Found pattern at index %d\n", i - j);
            j = pps[j - 1];
        }

        else if (i < N && pattern[j] != text[i])
        {
            if (j != 0)
                j = pps[j - 1];
            else
                i = i + 1;
        }
    }
}

// driver code
int main(void)
{
    char *text, *pattern;
    int M, N;

    printf("Enter the length of the text:-\n");
    scanf("%d", &N);
    text = (char *)malloc(N * sizeof(char));
    getchar();
    printf("Enter the text:-\n");
    scanf("%s", text);

    printf("Enter the length of the pattern:-\n");
    scanf("%d", &M);
    pattern = (char *)malloc(M * sizeof(char));
    getchar();
    printf("Enter the pattern:-\n");
    scanf("%s", pattern);

    printf("The pattern is found in the text at the following index:-\n");
    KMPAlgo(text, pattern, N, M);

    return 0;
}