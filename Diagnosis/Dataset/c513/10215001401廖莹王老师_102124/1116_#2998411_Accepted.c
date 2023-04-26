#include <stdio.h>
#include <stdlib.h>
long long abss(long long x)
{
    long long j=0;
    if(x>=0)j=x;
    else j=-x;
    return j;
}
long long  zou(long long x,long long y)
{
   long long k1=abss(x)+abss(y);
   long long l1=1,l2=1,i=1;
   if(k1%2==0)return -1;
   else if(k1==0)return 0;
   else
   {
       while(l2<k1)
       {
           l1=l1*2;l2=l2+l1;
           i++;
       }
       return i;
   }
}
int main()
{
    long long x,y,step=0;

    scanf("%lld %lld",&x,&y);
    if(x==0 && y==0)printf("0");
    else
    {
        step=zou(x,y);
    if(step==-1)printf("-1");
    else
    {
    printf("%lld\n",step);
    }
    }


    return 0;
}
