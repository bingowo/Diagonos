#include <stdio.h>
#include <stdlib.h>



long long r=2333;

int main()
{
  long long a[4];
   long long n;
   int T;int i=0;
   scanf("%d",&T);
   while(T>0)
   {
       scanf("%ld",&n);
        long long p=n;
       while(p){
        a[i]=p%r;
        p=p/r;
        i++;
       }
       i=i-1;
       while(i>=0){
        if(i==0)
        printf("%ld\n",a[i]);
        else printf("%ld ",a[i]);
        i--;
       }
       i=0;
       T--;
   }
   return 0;
}


