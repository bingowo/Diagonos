#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long x;
long long y;

struct point{
        long long x;
        long long y;
};



long long distance(struct point ten)
{
    long long xd=abs(ten.x-x);
    long long yd=abs(ten.y-y);
    return xd>yd? xd:yd;
}

int main()
{
    scanf("%d %d",&x,&y);
    struct point goal[1000001];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld %lld",&goal[i].x, &goal[i].y);
    long long resd=distance(goal[0]);
    long long resx=goal[0].x;
    long long resy=goal[0].y;
    for(int i=1;i<n;i++)
    {
        if(distance(goal[i])<resd)
        {
            resd=distance(goal[i]);
            resx=goal[i].x;
            resy=goal[i].y;
        }
        else if(distance(goal[i])==resd&&goal[i].x<resx)
        {
            resx=goal[i].x;
            resy=goal[i].y;
        }
        else if(distance(goal[i])==resd&&goal[i].x==resx&&goal[i].y<resy)
        {
            resx=goal[i].x;
            resy=goal[i].y;
        }
    }
    printf("%lld\n",resd);
    printf("%lld %lld",resx,resy);
    return 0;
}
