#include <stdio.h>
#include <math.h>
/*The function to calculate the resultant area,perimeter 
and diagonal in each newline. */
void cal(float s)
{
    float area;
    float perimeter;
    float diagonal;
    
    /*Algorithm*/
    area=(s)*(s);
    perimeter=4*s;
    diagonal=(s)*(sqrt(2));
    
    printf("\nThe area of the square with sides %f is %f",s,area);
    printf("\nThe perimeter of the square with sides %f is %f",s,perimeter);
    printf("\nThe diagonal length of the square with sides %f  is %f",s,diagonal);
    
}

//The driver code
int main(void)
{
    float s;
    
    printf("Enter the length of one side of a square: \n");
    scanf("%f",&s);
    
    cal(s);
    
    return(0);

}