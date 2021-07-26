#include<stdio.h>
#include<stdlib.h>

int main()
{
int num1,num2,i,flag,j;
printf("\n enter two range : ");
scanf("%d %d",&num1,&num2);
if(num2<2)
{
printf("\n there is no prime number in the range");
return (0);
}
if(num1%2==0)
{
num1++;
}
for(i=num1;i<=num2;i=i+2)
{
flag=0;
for(j=2;j<=i/2;j++)
{
if(i%j==0)
{
flag=1;
break;
}
}
if(flag==0)
printf("%d  ",i);
}

return (0);
}
