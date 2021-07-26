#include <stdio.h>
#include <math.h>
/*The function to calculate the resultant area,perimeter 
and diagonal in each newline. */
void cal(float l, float b)
{
    float area;
    float perimeter;
    float diagonal;
    
    /*Algorithm*/
    area=(l)*(b);
    perimeter=2*(l+b);
    diagonal=sqrt((pow(l,2))+(pow(b,2)));
    
    printf("\nThe area of the rectangle whose length and breadth are %f,%f is %f",l,b,area);
    printf("\nThe perimeter of the rectangle whose length and breadth are %f,%f is %f",l,b,perimeter);
    printf("\nThe diagonal length of the rectangle whose length and breadth are %f,%f is%f",l,b,diagonal);
    
}

//The driver code
int main(void)
{
    float l,b;
    
    printf("Enter the length and breadth of rectangle: \n");
    scanf("%f %f",&l,&b);
    
    cal(l,b);
    
    return(0);

}