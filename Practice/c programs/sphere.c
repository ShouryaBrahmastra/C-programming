#include <stdio.h>
#include <math.h>

/*This function  is to take the diameter of the sphere and
to find the circumference and surface area of that sphere
using user-defined function.*/
void cal(float dia)
{
    float ra;
    float circumference;
    float s_a;
    
    /*Algorithm to calculate the circumference 
    and surface area  of the sphere*/
    ra=(dia/2);
    circumference=2*3.14*ra;
    s_a=4*3.14*(pow(ra,2));
    
    printf("\nThe circumference of the sphere with diameter %f is %f \n",dia,circumference); 
    printf("The the surface area of the sphere with diameter %f is %f \n",dia,s_a); //displaying 
    
}

int main(void)
{
    float dia;
    
    printf("Enter the diameter of the sphere: ");
    scanf("%f",&dia);  //taking the diameter of the sphere from user  
    
    cal(dia);
    return(0);
}