/*  Continue Statement in C
    When you want to skip to the next iteration but remain in the loop, you should use the continue statement. 
*/

#include <stdio.h> 
//The driver code
int main(void) 
{       
    int nb = 7;       
        while (nb > 0) 
        {                               
            nb--;               
            if (nb == 5)                    
            continue;              
            printf("\n%d ", nb);        
        } 
    return (0);
} 