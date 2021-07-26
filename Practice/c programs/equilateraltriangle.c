#include <stdio.h>
#include <math.h>

void cal(float a)
{
    float area,height;
    
    /*Algorithm*/
    height= ((sqrt(3))/2)*(a);
    area= ((sqrt(3))/4)*(pow(a,2));
    
    printf("\nThe height of the equilateral triangle with side %f is : %f\n",a,height);
    printf("The area of the equilateral triangle with side %f is : %f",a,area);
}

//the driver code
int main(void)
{
    float a;
    
    printf("Please Enter the side of the triangle: ");
    scanf("%f",&a);
    
    cal(a);
    return 0;
}