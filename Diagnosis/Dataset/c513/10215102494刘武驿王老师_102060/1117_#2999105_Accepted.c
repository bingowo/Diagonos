#include<stdio.h>
#include<stdlib.h>
long long int max(long long int a,long long int b)
{
    if(a<0) a=-a;
    if(b<0) b=-b;
    return a>b? a:b;
}
int main()
{
    long long int x,y,x1,y1,n,dis=10000000000000000,resx,resy;
    scanf("%lld %lld",&x,&y);
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&x1,&y1);
        if(max(x1-x,y1-y)<=dis)
        {
            if(dis==max(x1-x,y1-y))
            {
                if(x1<resx)
                {
                    resx=x1;
                    resy=y1;
                    dis=max(x1-x,y1-y);
                    continue;
                }
                if(x1==resx&&y1<resy)
                {
                    resx=x1;
                    resy=y1;
                    dis=max(x1-x,y1-y);
                    continue;
                }
                continue;
            }
            resx=x1;
            resy=y1;
            dis=max(x1-x,y1-y);
        }
    }
    printf("%lld\n%lld %lld",dis,resx,resy);
}