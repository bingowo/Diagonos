#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
int main()
{
   long long x,y;
   scanf("%lld %lld",&x,&y);
   long long ans=0;long long m=0;
    while(x!=y)
   {
       m=x>y?y:x;
       ans+=m*4;
       if(m==x) y-=m;
       else if(m==y) x-=m;
   }
   ans+=4*x;
   printf("%lld",ans);
    return 0;
}
