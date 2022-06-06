/**
 * @file n_queens.c
 * @author https://github.com/ShouryaBrahmastra
 * @brief
 * First we are taking input from the user of the number
 * of queens to be used and then we are assigning the user
 * defined function NQUEENS. In this function we are checking
 * the valid positions to be placed in the matrix that satisfy
 * the 3 conditions :-
 * 1.)Not in the same row
 * 2.)Not in the same column
 * 3.)As well as not in the same diagonal
 *
 * Input:-
 * 4
 *
 * Output:-
 * 2 4 1 3
 * 3 1 4 2
 *
 * @version 0.1
 * @date 2022-06-06
 *
 * @copyright Copyright (c) 2022
 *
 */

// Here variable i is the column and j is the row

#include <stdio.h>
#include <stdlib.h>

// array to store column position of each queen in each row
int *x;

/* function to check whether the kth queen can be placed at ith
 * column without conflicting with the previous j queens
 */
int isValid(int k, int i)
{
    int j;
    // for checking the conditions
    for (j = 1; j < k; j++)
    {
        if (x[j] == i || (abs(x[j] - i) == abs(j - k)))
            return 0;
    }

    return 1;
}

/*function to print all the possible solutions to place N queens
  using brute force
*/
void printSolution(int n)
{
    int i;
    // displays the x[i]th column where the ith queen is placed
    for (i = 1; i <= n; i++)
        printf("%d ", x[i]);
    printf("\n");
}

// function to solve N-Queen problem using backtracking
void NQUEENS(int k, int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        if (isValid(k, i))
        {
            x[k] = i;
            if (k == n)
                printSolution(n);

            else
                NQUEENS(k + 1, n);
        }
    }
}

// Driver code
int main(void)
{
    int n;
    // taking the input form the user
    scanf("%d", &n);

    // dynamic memory allocation
    x = (int *)malloc(n * sizeof(int));

    NQUEENS(1, n);

    return 0;
}
