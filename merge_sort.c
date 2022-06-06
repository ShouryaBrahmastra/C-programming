/**
 * @file merge_sort.c
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

// merge the two sorted halves
void merge(int *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // create temp arrays
    int *left = (int *)malloc(n1 * sizeof(int));
    int *right = (int *)malloc(n2 * sizeof(int));

    // copy data to temp arrays
    for (i = 0; i < n1; i++)
        left[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    // merge temp arrays back into arr
    i = 0; // initial index of first subarray
    j = 0; // initial index of second subarray
    k = l; // initial index of merged subarray

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }

        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // copy remaining elements of left[], if any
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    // copy remaining elements of right[], if any
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        // find the middle point to divide the array into two halves
        int m = (l + (r - 1)) / 2;

        // sort the first half
        mergeSort(arr, l, m);

        // sort the second half
        mergeSort(arr, m + 1, r);

        // merge the two sorted halves
        merge(arr, l, m, r);
    }
}

void printArray(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void)
{
    int *arr, n, i;
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n);
    printArray(arr, n);

    return 0;
}