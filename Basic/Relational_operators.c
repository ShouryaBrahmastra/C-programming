/*  Relational operators
    The following table shows all relation operators supported by C.
    Operator                                    Description
      ==                                Check if two operand are equal.
      !=                                Check if two operand are not equal.
      >                                 Check if operand on the left is greater-than operand on the right.
      <                                 Check operand on the left is smaller-than right operand.
      >=                                Check left operand is greater-than or equal to right operand.
      <=                                Check if operand on left is smaller-than or equal to right operand.


*/

#include<stdio.h>

//The driver code
int main(void)
{
    int a,b;

    printf("  Enter first number: "); //asking the user for the first input
    scanf("%d",&a);
    printf("  Enter second number: "); //asking the user for the second input
    scanf("%d",&b);

    if(a == b)
    {
        printf("The value of a is equal to b");
    }
    else if(a>b)
    (
        printf("The value of a is greater-than b")
    );
    else if(a<b)
    {
        printf("The value of a is smaller-than b");
    }
    else if (a>=b)
    {
        printf("The value of a is either greater-than or equal to b");
    }
    else if(a<=b)
    {
        printf("The value of a is either smaller-than or equal to b");
    }    
    /*Put in the first to see the difference*/
    else if(a!=b)
    {
        printf("The value of a is not equal to b");
    }

    return (0);    
}