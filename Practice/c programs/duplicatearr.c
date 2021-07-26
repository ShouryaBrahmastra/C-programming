/*The program to find duplicate elements in an array*/
#include<stdio.h>
int main()
{
 int i, j, k, n, num, flag=0;
 int a[50];
 printf("\n enter size:");
 scanf("%d",&n);
 printf("\n enter array elements:");
 for(i=0; i<n; i++)
 scanf("%d",&a[i]);
 num=n;
 for(i=0;i<n-1;i++)
 {
 for(j=i+1; j<n; j++)
 {
 if(a[i]==a[j])
 {
 n=n-1;
 for(k=j; k<n; k++)
 a[k]=a[k+1]; // shifting
 flag=1;
 j=j-1;
}
 }
}

 if(flag==1)
 {
printf("\n no of duplicates:%d\n", num-n);
for(i=0; i<n; i++)
printf("%d ",a[i]);
 }
 return 0;
}
