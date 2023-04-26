#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{long long x,y,len;}point;

int cmp(const void*a,const void*b)
{
    point c = *(point*)a;
    point d = *(point*)b;
    if(c.len < d.len)return 1;
    else if(c.len > d.len)return -1;
    else if(c.x < d.x)return -1;
    else if(c.x > d.x)return 1;
    else if(c.y < d.y)return -1;
    else return 1;
}
int main()
{
    int cas,i;
    long long d,distance,r,ans;
    point *s;
    scanf("%d",&cas);
    s = (point*)malloc(cas*sizeof(point));
    for(i = 0; i < cas; i++)
    {
        scanf("%lld %lld",&s[i].x,&s[i].y);
        s[i].len = llabs(s[i].x) + llabs(s[i].y);
    }
    qsort(s,cas,sizeof(s[0]),cmp);
    distance = llabs(s[0].x - s[1].x) + llabs(s[0].y - s[1].y);
    printf("%lld\n",distance);
    for(i = 1,ans = 0; i < cas; i++)
    {
        d = llabs(s[i].x - s[i-1].x) + llabs(s[i].y - s[i-1].y);
        if(d%2 == 0)break;
        else
        {
            for(r = 1; r < 63; r++)
            {
                if(pow(2,r-1) <= d&&pow(2,r) >= d)break;
            }
            ans += r;
        }
    }
    printf("%lld",ans);
    return 0;
}
