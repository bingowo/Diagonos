#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,start,min,t,count;
void cnt(int p,int m);
int main()
{
   int cas;
   scanf("%d",&cas);
   while(cas--)
   {
       count=0;
       scanf("%d%d%d%d",&n,&start,&min,&t);
       cnt(start,min);
       printf("%d\n",count);
   }
}
void cnt(int p,int m)
{
    if(m<=0)
    {
        if(p==t)count++;
        return;
    }
    if(p==1)cnt(2,m-1);
    else if(p==n)cnt(n-1,m-1);
    else
    {
        cnt(p+1,m-1);
        cnt(p-1,m-1);
    }
}
