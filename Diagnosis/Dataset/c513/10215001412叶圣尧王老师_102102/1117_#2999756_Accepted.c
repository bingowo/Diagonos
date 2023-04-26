#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int main()
{
    long long x0,y0,x,y,dis,dis1,x1,y1;int n,i,j;
    scanf("%lld %lld",&x0,&y0);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld",&x,&y);
        if(i==0)
        {
            x1=x;y1=y;dis1=llabs(x-x0)>llabs(y-y0)? llabs(x-x0):llabs(y-y0);
        }
        else
        {
            dis=llabs(x-x0)>llabs(y-y0)? llabs(x-x0):llabs(y-y0);
            if(dis<dis1)
            {
                dis1=dis;
                x1=x;y1=y;
            }
            else if(dis==dis1)
            {
                if(x<x1){x1=x;y1=y;}
                else if(x==x1)
                    if(y<y1)y1=y;
            }
        }
    }
    printf("%lld\n",dis1);
    printf("%lld %lld",x1,y1);
}