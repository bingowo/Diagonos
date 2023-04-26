#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
unsigned long long f(int n)
{
    if(n<=0) return 0;
    if(n==1 || n==2) return 1;
    long long ans=0,a=0,b=1,c=1;
    for(int i=3;i<=n;i++)
    {
        ans=a+b+c;
        a=b;
        b=c;
        c=ans;
    }
    return ans;
}
int main()
{
   int T;
   scanf("%d",&T);
   for(int cas=0;cas<T;cas++)
   {
       int n;
       scanf("%d",&n);
       printf("case #%d:\n",cas);
       printf("%llu\n",f(n));
   }
    return 0;
}
