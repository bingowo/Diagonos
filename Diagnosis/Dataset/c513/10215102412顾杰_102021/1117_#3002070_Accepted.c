#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
//#include "myh.h"
long long max(long long x,long long y)
{
    return x>y?x:y;
}
int main()
{
    long long ans[3]={1e16,0,0},x,y,x0,y0,n,i;
    scanf("%lld%lld%lld",&x0,&y0,&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&x,&y);
        long long t=max(llabs(x-x0),llabs(y-y0));
        if(t>=ans[0])
            {if(t==ans[0])
                if(x<ans[1]||(x==ans[1]&&y<ans[2])){ans[1]=x;ans[2]=y;}}
        else {ans[0]=t;ans[1]=x;ans[2]=y;}
    }
    printf("%lld\n%lld %lld",ans[0],ans[1],ans[2]);
}
