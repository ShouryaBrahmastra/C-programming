/*  Logical operators
    C language supports following 3 logical operators. Suppose a = 1 and b = 0,
    Operator                    Description                 Example  
       &&                       Logical AND            (a && b) is false
       ||                       Logical OR             (a || b) is true
       !                        Logical NOT              (!a) is false
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

            if (a || b)
            {
                printf("Either a is condidered or b id considered");
            }
            else if(a && b)
            {
                printf("Both are taken");
            }
            else if(!a)
            {
                printf("a is not equal to b");
            }
    return(0);
}