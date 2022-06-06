/**
 * @file heap_sort.c
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

int size;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr, int size, int i)
{
    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
    }
}

void buildHeap(int *arr, int size)
{
    int start = (size / 2) - 1;
    int i;

    for (i = start; i >= 0; i--)
        heapify(arr, size, i);
}

void heapSort(int *arr, int size)
{
    int i;

    // build heap (rearrange array)
    buildHeap(arr, size);

    // one by one extract an element from heap
    for (i = size - 1; i > 0; i--)
    {
        // move current root to end
        swap(&arr[0], &arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void printHeap(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void)
{
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    int i;

    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    heapSort(arr, size);
    printHeap(arr, size);

    return 0;
}