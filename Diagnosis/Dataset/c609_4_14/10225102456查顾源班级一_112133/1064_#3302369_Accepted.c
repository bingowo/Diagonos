#include <stdio.h>

long long f(long long x,long long y)
{
   long long t=0;
   long long min=y;
   long long max=x;
   while(max%min)
   {long long num=max/min;
   t+=min*4*num;
   long long temp=min;
   min=max%temp;
   max=temp;}
   t+=max*4;
   return t;
}


int main()
{
   long long x;
   long long y;
   scanf("%lld%lld",&x,&y);
   long long n=0;
   n=f(x,y);
   printf("%lld",n);
    return 0;
}
