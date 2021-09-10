/*  For loop in c
    A for loop is a more efficient loop structure in 'C' programming. 
    The general structure of for loop syntax in C is as follows : 

    for (initial  value; condition; incrementation or decrementation )  
    {   
        statements; 
    }

    The initial  value of the for loop is performed only once.
    The condition is a Boolean expression that tests and compares the counter to a 
    fixed value after each iteration, stopping the for loop when false is returned.  

    The incrementation/decrementation increases (or decreases) the counter by a set value. 

    Following program illustrates  the for loop in C programming example: 
*/

#include<stdio.h> 
//The driver Code
int main(void) 
{       
    int number;      
    for(number=1;number<=10;number++) //for loop to print 1-10 numbers      
    {            
        printf("\n%d ",number); //to print the number      
    }      
    return 0; 
} 

/* Code Explanation
    We have declared a variable  of an int data type to store values. 

    In for loop, in the initialization  part, we have assigned value 1 to the variable number. 
    In the condition part, we have specified our condition and then the increment part. 

    In the body of a loop, we have a print function to print the numbers on a new line in the console. 
    We have the value one stored in number, after the first iteration the value will be incremented, and it will
    become 2. Now the variable  number has the value 2. The condition will  be rechecked and since the condition
    is true loop will  be executed, and it will  print two on the screen. This loop will  keep on executing until 
    the value of the variable  becomes 10. After that, the loop will  be terminated, and a series of 1-10 will  
    be printed on the screen. 
*/