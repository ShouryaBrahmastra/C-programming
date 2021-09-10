/*  Do-While loop in C 
    A do...while loop in C is similar to the while loop except that the condition is always 
    executed after the body of a loop. It  is also called  an exit-controlled loop.

    Syntax of do...while loop in C programming language is as follows: 
    do
    {    
        statements; 
    }while(expression); 

    As we saw in a while loop, the body is executed if and only if the condition is true. 
    In some cases, we have to execute a bod y of the loop at least once even if the condition is false. 
    This type of operation can be achieved by using a do -while loop. 

    In the do-while loop, the body of a loop is always executed at least once. After the body 
    is executed, then it checks the condit ion. If the condition is true, then it will again 
    execute the body of a loop otherwise control is transferred out of the loop. 
    Similar to the while loop, once the control goes out of the loop the statements which are immediately after the loop is executed. 

    An example of do..while loop: 
*/

#include<stdio.h> 
//The driver code
int main(void) 
{         
    int num=1; //initializing  the variable 
        do           
        //do-while loop        
        {              
            printf("\n%d ",2*num);              
            num++; //incrementing operation       
        }while(num<=10);       
    return 0; 
} 

/* Code Explanation
    First, we have initialized  a variable  'num' with value 1. Then we have written a do-while loop. 
    In a loop, we have a print function that will  print the series by multiplying the value of num with 2. 
    After each increment, the value of num will  increase by 1, and it will  be printed on the screen. 

    Initially, the value of num is 1. In a body of a loop, the print function will be executed in this way:
     2*num where num=1, then 2*1=2 hence the value two will be printed. This will  go on until the value of 
     num becomes 10. After that loop will be terminated and a statem ent which is immediately after the loop 
     will be executed. In this case return 0. 

*/