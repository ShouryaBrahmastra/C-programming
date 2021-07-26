#include <stdio.h>
#include <math.h>

/*This function  is to take the diameter of the circle and
to find the circumference and area of that circle
using user-defined function.*/
void cal(float dia)
{
    float ra;
    float circumference;
    float area;
    
    /*Algorithm to calculate the circumference 
    and surface area  of the sphere*/
    ra=(dia/2);
    circumference=2*3.14*ra;
    area=3.14*(pow(ra,2));
    
    printf("\nThe circumference of the circle with diameter %f is %f \n",dia,circumference); 
    printf("The the area of the circle with diameter %f is %f \n",dia,area); //displaying 
    
}

int main(void)
{
    float dia;
    
    printf("Enter the diameter of the circle: ");
    scanf("%f",&dia);  //taking the diameter of the sphere from user  
    
    cal(dia);
    return(0);
}