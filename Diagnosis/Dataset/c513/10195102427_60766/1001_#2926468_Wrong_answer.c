#include<stdio.h>
int main()
{
 int i=0,j,n,b,m,r;
 char a[1000];
 while(scanf("%d%d",&n,&r)!=EOF)
 {
     if (n< 0) 
       {
         printf("-");
         n=n-2*n;
       }
    while(n!=0)
    {
       ++i;
       b=n/r;
       a[i]=n%r;
       n=b;
    }
    for(j=i;j>0;j--)
   {
       if(a[j]>=10&&a[j]<=16)
       {
           if(j!=1)
           printf("%c",a[j]+55);
           else
           printf("%c\n",a[j]+55);
           i=0;
      }
      else
     {
         if(j!=1)
         printf("%d",a[j]);
         else
         printf("%d\n",a[j]);
         i=0;
     }
   }
 }
 return 0;
}
