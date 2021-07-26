#include <stdio.h>

int main()
{
    int i,t,n,f;
    int a[100];
    printf("Enter size of array: ");
    scanf("%d",&n);

    printf("Enter the elements:-  ");
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }


    for(i=0;i<n;i++)
    {
    t+=a[i];
    }

    printf("Average: %d",t/n);
    return (0);

}
