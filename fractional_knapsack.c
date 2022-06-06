/**
 * @file fractional_knapsack.c
 * @author https://github.com/ShouryaBrahmastra
 * @brief
 *
 * Given a set of items, each with a weight and a value. Determine the number of each item to include
 * in a Knapsack bag so that the total weight is less than a given capacity and the total profit is
 * as large as possible. In the input section, the first line gives the value of number of items N.
 * In the next N consecutive lines, the weight of the individual items followed by the corresponding
 * profit is given in each line. The N+1 line contains the maximum capacity of the bag. In the output
 * section, for each of the item, if the item is selected then it can be represented by 1.00 or if
 * partially selected the represented by that ratio and if it is not selected the represented
 * by 0.00. All the presence of the items are represented in a single line followed by the maximum
 * profit earned by the arrangement. All the representation of decimal values should be 2 values
 * after decimal point.
 *
 * @version 0.1
 * @date 2022-06-06
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

// structure to store the weight and price of the item
typedef struct Item
{
    double w;
    double price;
    double pricew;
} it;

// utility function to merge the divided array
void merge(it *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    it left[n1], right[n2];
    for (i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (left[i].pricew >= right[j].pricew)
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < n1)
        arr[k++] = left[i++];

    while (j < n2)
        arr[k++] = right[j++];
}

// function of merge sort
void merge_sort(it *arr, int l, int r)
{
    if (l < r)
    {
        int m = (l + (r - 1)) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// function to implement Knapsack algorithm
void knapSack(it *arr, int n, double m)
{
    // array to store amount of each item selected
    double *x = (double *)malloc(n * sizeof(double));
    double profit = 0.0;
    int i;

    for (i = 0; i < n; i++)
        x[i] = 0.0;

    for (i = 0; i < n; i++)
    {

        if (arr[i].w <= m)
        {
            x[i] = 1.0;
            m -= arr[i].w;
        }

        else
        {
            x[i] = m / arr[i].w;
            break;
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%0.2lf ", x[i]);
        // calculate maximum profit
        profit += (x[i] * arr[i].price);
    }
    printf("\n%.2lf\n", profit);
}

// driver code
int main(void)
{
    int n, i;
    double m;

    // user defined total number of items
    scanf("%d", &n);

    it *arr = (it *)malloc(n * sizeof(it));

    for (i = 0; i < n; i++)
    {
        // accepting the weight and value of each item
        scanf("%lf%lf", &arr[i].w, &arr[i].price);
    }

    // accepting the maximum capacity
    scanf("%lf", &m);

    // calculating the price to weight ratio of each item
    for (i = 0; i < n; i++)
        arr[i].pricew = arr[i].price / arr[i].w;

    // sorting the items in descending order of price to weight ratio
    merge_sort(arr, 0, n - 1);
    // calling knapsack function to display maximum profit
    knapSack(arr, n, m);

    return 0;
}

// Output:-
// 7
// 2 10
// 3 5
// 5 15
// 7 7
// 1 6
// 4 18
// 1 3
// 15
// 1.00 1.00 1.00 1.00 1.00 0.67 0.00
// 55.33
