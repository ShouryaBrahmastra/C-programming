/*A program to create a simple calculator 
using user defined functions in c programming*/

#include <stdio.h>

/*This function is used to add two numbers*/
int add(int num1, int num2) 
{
    return(num1 + num2);
}

/*This function is used to substract two numbers*/
int sub(int num1, int num2) 
{
    return(num1 - num2);
}

/*This function is used to multiply two numbers*/
int multi(int num1, int num2)   
{
    return(num1 * num2);
}

/*This function is used to divide first numbers from the second number*/
int divide(int num1, int num2)  
{
    return(num1 / num2);
}

/*This function is used to find the remainder of two numbers*/
int rem(int num1, int num2) 
{
    return(num1 % num2);
}

//The driver code
int main(void)
{
    int num1 , num2;
    char ch;
    
    printf("  Enter first number: "); //asking the user for the first input
    scanf("%d",&num1);
    printf("  Enter second number: "); //asking the user for the second input
    scanf("%d",&num2);
    
    printf("\n  Please enter your choice: \n  2Choose operation you want to perform ( +,-,x,/,% ):  ");
    scanf(" %c",&ch);
    
    switch(ch)
    {
        case '+':   printf("\n  Result: %d %c %d = %d\n",num1,ch,num2,add(num1,num2));
                    break;
        case '-':   printf("\n  Result: %d %c %d = %d\n",num1,ch,num2,sub(num1,num2));
                    break;
        case 'x':   printf("\n  Result: %d %c %d = %d\n",num1,ch,num2,multi(num1,num2));
                    break;
        case '/':   printf("\n  Result: %d %c %d = %d\n",num1,ch,num2,divide(num1,num2));
                    break;
        case '%':   printf("\n  Result: %d %c %d = %d\n",num1,ch,num2,rem(num1,num2));
                    break;
        default:
                    printf("\n  Invalid operation.\n");

    }
  
    return 0;
}
