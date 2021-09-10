/*  Conditional operator
    The conditional operators in C language are known by two more names
    Ternary Operator
    ? : Operator
    It is actually the if condition that we use in C language decision making,
    but using conditional operator, we turn the if condition statement into a short and simple operator.
    The syntax of a conditional operator is :
    expression 1 ? expression 2: expression 3
*/

/*
    Suppose if we are not using the conditional operator and if we are using the "if" condition
    for finding the largest amongst the 3 numbers that must be user input then the code will be:

    #include<stdio.h>

    int main(void)
    {
        double n1, n2, n3;

            printf("Enter three different numbers:"); // Taking 3 numbers from the users
            scanf("%lf %lf %lf", &n1, &n2, &n3);

                // if n1 is greater than both n2 and n3, n1 is the largest
                if (n1 >= n2 && n1 >= n3)
                    printf("%.2f is the largest number.", n1);
                // if n2 is greater than both n1 and n3, n2 is the largest
                if (n2 >= n1 && n2 >= n3)
                    printf("%.2f is the largest number.", n2);
                // if n3 is greater than both n1 and n2, n3 is the largest
                if (n3 >= n1 && n3 >= n2)
                    printf("%.2f is the largest number.", n3);
        return 0;
    }
    
    Now if we are using the Conditional or the Ternary Operator then:-
*/

# include <stdio.h>
# include <conio.h>

void main() // program execution starts from here
{
    int a, b, c, big ; //variable declaration

    printf("Enter three numbers : ") ; //asking user to enter 3 numbers
    scanf("%d %d %d", &a, &b, &c) ; //reading user entered 3 numbers

    //Ternary operator code logic to find the biggest number
    big = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c) ;

    printf("\nThe biggest number is : %d", big) ; //printing biggest number
    getch();
}