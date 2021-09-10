/*  Arithmetic operators
    C supports all the basic arithmetic operators. The following table shows all the basic arithmetic operators.
    Operator                                 Description
       +                                  adds two operands
       -                           subtract second operands from first
       *                                multiply two operand
       /                            divide numerator by denominator
       %                                remainder of division
       ++                   Increment operator - increases integer value by one  
       --                   Decrement operator - decreases integer value by one

*/

#include<stdio.h>

/*Function Prototype*/
int add(int a, int b);
int sub(int a, int b);
int multi(int a, int b);
int divide(int a, int b);
int rem(int a, int b);


//The driver code
int main(void)
{
    int a,b;
    int choice;
    char ch;

    printf("  Enter first number: "); //asking the user for the first input
    scanf("%d",&a);
    printf("  Enter second number: "); //asking the user for the second input
    scanf("%d",&b);

       do{            
            printf("\n Press 1 to add two numbers.");
            printf("\n Press 2 to subtract two numbers.");
            printf("\n Press 3 to multiply two numbers.");
            printf("\n Press 4 to divide two numbers.");
            printf("\n Press 5 to find the remainder of the two numbers.");
            printf("\n  Please enter your choice: \n ");
            scanf(" %d",&choice);
            
                    switch(choice)
                    {
                        case 1: printf("\n  Result: %d %c %d = %d\n",a,choice,b,add(a,b));
                                    break;
                        case 2: printf("\n  Result: %d %c %d = %d\n",a,choice,b,sub(a,b));
                                    break;
                        case 3: printf("\n  Result: %d %c %d = %d\n",a,choice,b,multi(a,b));
                                    break;
                        case 4: if (b == 0)
                                {
                                    printf("\n Denominator cannot be zero");
                                }
                                else
                                {
                                printf("\n  Result: %d %c %d = %d\n",a,choice,b,divide(a,b));
                                    break;
                                }
                        case 5: printf("\n  Result: %d %c %d = %d\n",a,choice,b,rem(a,b));
                                    break;
                        default:  printf("\n  Invalid operation.\n");
                    }
                    printf("\n Do you want to continue? (Press y/n)");
                    scanf(" %c",&ch);
            }while(ch == 'y' || ch == 'Y');
    return (0);
}

/*Function Definition*/
int add(int a, int b)
{
    return(a+b);
}

int sub(int a, int b)
{
    return(a-b);
}

int multi(int a, int b)
{
    return(a*b);
}

int divide(int a, int b)
{
    return(a/b);
}

int rem(int a, int b)
{
    return(a%b);
}