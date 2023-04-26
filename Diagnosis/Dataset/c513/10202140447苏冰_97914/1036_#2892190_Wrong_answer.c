#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct SSS
{
    long long x;
    long long y;
    long long dis;
}sss;
int cmp(const void*_a,const void*_b)
{
    sss* a=(sss*)_a;
    sss* b=(sss*)_b;
    if((a->dis)!=(b->dis))
        return((a->dis)>(b->dis)?-1:1);
    else if((a->x)!=(b->x))
        return ((a->x)>(b->x)?1:-1);
    else
        return((a->y)>(b->y)?1:-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    sss s[110];
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&s[i].x,&s[i].y);
        s[i].dis=abs(s[i].x)+abs(s[i].y);
    }
    qsort(s,n,sizeof(s[0]),cmp);
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        long long k=1;
        int x=0;
        long long cnt=0;
        long long cn=(long long)abs(s[i].x-s[i+1].x)+(long long)abs(s[i].y-s[i+1].y);
        while(cnt<cn)
        {
            cnt+=k;
            k*=2;
            x++;
        }
        if((cnt-cn)%2!=0) break;
        ans+=x;
    }
    printf("%d\n",abs(s[0].x-s[1].x)+abs(s[0].y-s[1].y));
    printf("%d",ans);
    return 0;
}
