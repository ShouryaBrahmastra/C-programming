/**
 * @file time_complexity.c
 * @author https://github.com/ShouryaBrahmastra
 * @brief
 *
 * Divide and Conquer → Complexity Analysis 1.
 *
 * Implement Bubble Sort, Merge Sort and Quick Sort algorithms to sort a set of randomly generated integers.
 *
 * (a) Input should be generated randomly using pseudo-random function and these numbers
 * should be stored in a plain text file.
 *
 * (b) Calculate actual time consumption of the sorting techniques for different input size (i.e.
 * number of integers 20000, 40000, 60000, 80000 and 100000) and write it in a file.
 * (c) Plot a graph of time consumption with respect to varying number of inputs.
 *
 * @version 0.1
 * @date 2022-06-06
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int arr[], int p, int q, int r)
{

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// function to find the partition position
int partition(int array[], int low, int high)
{

    int pivot = array[high];

    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {

            i++;

            // swap element at i with element at j
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);

    // return the partition point
    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}

// perform the bubble sort
void bubbleSort(int array[], int size)
{

    for (int step = 0; step < size - 1; ++step)
    {

        for (int i = 0; i < size - step - 1; ++i)
        {

            if (array[i] > array[i + 1])
            {

                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

// function to print array elements
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i - 1;
    }
}

int main(void)
{

    time_t initBubble, finalBubble, initMerge, finalMerge;
    FILE *bPtr, *mPtr;

    bPtr = fopen("sort.dat", "w");

    int t = 5, n = 20000;
    fprintf(bPtr, "Size BubbleSort MergeSort\n");

    while (t--)
    {
        int *arr1, *arr2;
        arr1 = (int *)malloc(n * sizeof(int));
        arr2 = (int *)malloc(n * sizeof(int));

        array(arr1, n);
        array(arr2, n);

        initBubble = clock();

        bubbleSort(arr1, n);

        finalBubble = clock();
        initMerge = clock();
        mergeSort(arr2, 0, n - 1);
        finalMerge = clock();
        fprintf(bPtr, "%d %ld %ld\n", n, finalBubble - initBubble, finalMerge - initMerge);
        n += 20000;
    }

    fclose(bPtr);

    return 0;
}