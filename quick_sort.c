/**
 * @file quick_sort.c
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

// utility function to swap two elements
void swap(int *a, int *b)
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
}

/*this function takes the first element as pivot,
places the pivot element at its correct position
in sorted array, and places all smaller elements
(smaller than pivot) to left of pivot and all
greater elements to right of pivot*/
int partition(int *arr, int l, int r)
{
    int pivot = arr[l]; // pivot element
    int i = l + 1;      // left pointer at the second element of the array
    int j = r;          // right pointer at the last element of the array

    while (i < j)
    {
        // move left while element is lesser than pivot
        while (arr[i] <= pivot)
            i++;

        // move right while element is greater than pivot
        while (arr[j] > pivot)
            j--;

        if (i < j)
            // if the left pointer value is greater than right pointer value, swap the values at these locations
            swap(&arr[i], &arr[j]);
    }

    // right pointer is the final position for the pivot
    swap(&arr[l], &arr[j]);
    return j;
}

// function to implement quick sort
void quickSort(int *arr, int l, int r)
{
    if (l < r)
    {
        // partitioning index
        int pi = partition(arr, l, r);

        // separately sort elements before and after partition
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

// utility function to display the array
void printArray(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// main driver function
int main(void)
{
    int *arr, i, n;

    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}