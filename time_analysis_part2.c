/**
 * @file time_analysis_part2.c
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
#include <time.h>

long long int *generate(long long int n)
{
    long long int *arr = (long long int *)malloc(n * sizeof(long long int));
    for (long long int i = 1; i <= n; i++)
        arr[i] = rand() % n;

    return arr;
}

void bubble_sort(long long int *arr, long long int n)
{
    for (long long int i = 0; i < n - 1; i++)
    {
        for (long long int j = 0; j < (n - 1 - i); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                long long int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void merge(long long int *arr, long long int l, long long int m, long long int r)
{
    long long int i, j, k;
    long long int n1 = m + 1 - l;
    int n2 = r - m;

    long long int left[n1], right[n2];

    for (i = 0; i < n1; i++)
        left[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];

        else
            arr[k++] = right[j++];
    }

    while (i < n1)
        arr[k++] = left[i++];

    while (j < n2)
        arr[k++] = right[j++];
}

void merge_sort(long long int *arr, long long int l, long long int r)
{
    if (l < r)
    {
        long long int m = (l + (r - 1)) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main(void)
{
    printf("The program is running....\n");
    FILE *fptr;
    fptr = fopen("plot.txt", "w");
    fputs("Input Size \t Bubble Sort \t Merge Sort\n", fptr);
    fclose(fptr);

    for (long long int n = 20000; n <= 100000; n += 20000)
    {
        time_t start, end;
        double tim[3];

        long long int *arrb = generate(n);
        long long int *arrm = arrb;

        // for bubble sort
        start = time(NULL);
        bubble_sort(arrb, n);
        end = time(NULL);
        tim[0] = (double)(end - start);

        // for merge sort
        start = time(NULL);
        merge_sort(arrm, 0, n - 1);
        end = time(NULL);
        tim[1] = (double)(end - start);

        FILE *fptr;
        fptr = fopen("plot.txt", "a+");

        fprintf(fptr, "%lld \t  %lf \t  %lf\n", n, tim[0], tim[1]);
        fclose(fptr);
    }

    printf("The program has ended!!\n");
    return 0;
}