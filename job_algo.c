/**
 * @file job_algo.c
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

#define min(x, y) x < y ? x : y
#define max(x, y) x > y ? x : y

typedef struct job
{
    char id;
    int deadline;
    int profit;
} job;

// utility function to merge the divided array
void merge(job *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m + 1 - l;
    int n2 = r - m;
    job left[n1], right[n2];
    for (i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (left[i].profit >= right[j].profit)
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < n1)
        arr[k++] = left[i++];

    while (j < n2)
        arr[k++] = right[j++];
}

// function to implement merge sort
void merge_sort(job *arr, int l, int r)
{
    if (l < r)
    {
        int m = (l + (r - 1)) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void jobSequencing(job *jobs, int n)
{
    int i, j, k, max_profit;

    // free time slots
    int *timeslot = (int *)malloc(n * sizeof(int));

    // filled time slots
    int filledTimeSlot = 0;

    // find maximum deadline value
    int dmax = 0;
    for (i = 0; i < n; i++)
        dmax = max(dmax, jobs[i].deadline);

    // free time slots initially set to -1 [-1 denotes EMPTY]
    for (i = 1; i <= dmax; i++)
        timeslot[i] = -1;

    printf("\nMaximum Deadline = %d\n", dmax);

    for (i = 1; i <= n; i++)
    {
        k = min(dmax, jobs[i - 1].deadline);
        while (k >= 1)
        {
            if (timeslot[k] == -1)
            {
                timeslot[k] = i - 1;
                filledTimeSlot++;
                break;
            }
            k--;
        }

        // if all time slots are filled then stop
        if (filledTimeSlot == dmax)
            break;
    }

    // required jobs
    printf("\nFollowing is maximum profit sequence of jobs:-\n");
    for (i = 1; i <= dmax; i++)
    {
        printf("%c", jobs[timeslot[i]].id);
        if (i < dmax)
            printf(" --> ");
    }

    // required profit
    max_profit = 0;
    for (i = 1; i <= dmax; i++)
    {
        max_profit += jobs[timeslot[i]].profit;
    }
    printf("\n\nMaximum Profit = %d\n", max_profit);
}

// driver code
int main(void)
{
    int i, j, n;

    printf("Enter the number of jobs:-\n");
    scanf("%d", &n);

    job *jobs, temp;
    jobs = (job *)malloc(n * sizeof(job));

    printf("Enter the jobs in the sequence of Job ID, Deadline and Profit:-\n");
    for (i = 0; i < n; i++)
        scanf("\n%c%d%d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);

    // sort the jobs profit wise in descending order
    merge_sort(jobs, 0, n);

    printf("\nJob\tDeadline\tProfit\n");
    for (i = 0; i < n; i++)
        printf("%c\t%d\t%d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);

    jobSequencing(jobs, n);

    return 0;
}
