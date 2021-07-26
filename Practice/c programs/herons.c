#include<stdio.h>
#include<math.h>
int main()
{
float s, a,b,c,area;
printf("\nenter values of a and b and c: ");
scanf("%f%f%f",&a,&b,&c);
s=(a+b+c)/2;
area=sqrt(s*(s-a)*(s-b)*(s-c));
printf("\narea of triangle is:%f ",area);
return 0;
}
