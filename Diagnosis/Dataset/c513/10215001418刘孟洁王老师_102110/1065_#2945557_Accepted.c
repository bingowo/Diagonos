#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct{int aa,tt;}subway;

int main()
{
   int a,n,m,x,t,i;
   subway ps[27],px[27],sum[27];
   scanf("%d%d%d%d",&a,&n,&m,&x);
   ps[1].aa = 1;ps[1].tt = 0;
   ps[2].aa = 0;ps[2].tt = 1;
   for(i = 3; i <= n; i++)
   {
       ps[i].aa = ps[i-1].aa + ps[i-2].aa;
       ps[i].tt = ps[i-1].tt + ps[i-2].tt;
    }
    px[1].aa = 0;px[1].tt = 0;
   px[2].aa = 0;px[2].tt = 1;
   for(i = 3; i <= n; i++)px[i] = ps[i-1];
   sum[1].aa = 1;sum[1].tt = 0;
   sum[2].aa = 1;sum[2].tt = 0;
   for(i = 3; i <= n; i++)
   {
       sum[i].aa = sum[i-1].aa + ps[i].aa - px[i].aa;
       sum[i].tt = sum[i-1].tt + ps[i].tt - px[i].tt;
    }
   t = (m-sum[n-1].aa*a)/sum[n-1].tt;
   printf("%d\n",sum[x].aa*a+sum[x].tt*t);
   //printf("%d",t);
    return 0;
}