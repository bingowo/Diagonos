#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int T,i,n;
   scanf("%d",&T);
   for(i=0;i<T;i++)
   {
       scanf("%d",&n);
       int count=0;
       if(n<5)count=0;
       while(n>=5)
       {
           n/=5;
           count+=n;
       }
       printf("case #%d:\n%d\n",i,count);
   }
   return 0;
}