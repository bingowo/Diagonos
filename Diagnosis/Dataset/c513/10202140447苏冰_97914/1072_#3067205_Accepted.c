#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void path(long long x,long long y,int k)
{
    if(k)
    {
        long long d=(1LL<<(k-1));
        if(llabs(x)>llabs(y))
        {
            if(x>0)
            {
                path(x-d,y,k-1);
                printf("E");
            }
            else
            {
                path(x+d,y,k-1);
                printf("W");
            }
        }
        else
        {
            if(y>0)
            {
                path(x,y-d,k-1);
                printf("N");
            }
            else
            {
                path(x,y+d,k-1);
                printf("S");
            }
        }
    }
}
int main()
{
    long long x,y;
    long long dis;
    scanf("%lld%lld",&x,&y);
    dis=llabs(x)+llabs(y);
    if(dis==0) printf("0\n");
    else if(dis%2==0) printf("-1\n");
    else
    {
        int ans=0;
        long long k=1;
        long long cnt=0;
        while(cnt<dis)
        {
            cnt+=k;
            k*=2;
            ans++;
        }
        printf("%d\n",ans);
        path(x,y,ans);
    }
}
