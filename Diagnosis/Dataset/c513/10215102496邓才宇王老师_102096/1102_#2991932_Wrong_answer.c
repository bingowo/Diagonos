#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
   long long int n;
   scanf("%lld",&n);
   long long int m=sqrt(n);
   long long int abs=n-m*m;
   int x,y;
   if(m%2==0)
   {
       if(abs<=m)
       {
           x=-m/2+abs;
           y=-m/2;
       }
       else
       {
           x=m/2;
           y=-m/2+abs-m;
       }
   }
   else
   {
       if(abs<=m)
       {
           x=m/2-abs;
           y=m/2+1;
       }
       else
       {
           x=m/2-m;
           y=m/2+1-abs+m;
       }
   }
   printf("(%d,%d)",x,y);
}
