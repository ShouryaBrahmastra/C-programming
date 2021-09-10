/*  Break Statement in C
    The break statement is used mainly in in the switch statement. 
    It is also useful for immediately stopping a loop. 

    We consider the following  program which introduces a break to exit a while loop:
*/

#include <stdio.h> 
//The driver code
int main(void) 
{       
    int num = 5;       
        while (num > 0) 
        {             
            if (num == 3)                     
            break;             
            printf("\n%d ", num); 
            num--;      
        } 
    return (0);
} 