// Implement Pascal's triangle

  #include <stdio.h>

  long factorial(int n)
  {
     int i;
     long result=1;
 
     for(i=1;i<=n;i++)
       result=result*i;
 
     return result;
  }
   
//the driver code
  int main(void)
  {
    int i,lines,j;
 
    printf("\nEnter no of lines:");
    scanf("%d",&lines);
 
        for(i=0;i<lines;i++)
        {
        for(j=0;j<=(lines-i-2);j++)
            printf(" ");
    
        for(j=0;j<=i;j++)
            printf("%ld ",factorial(i)/(factorial(j)*factorial(i-j)));
    
        printf("\n");
        }
 
    return 0;
  }