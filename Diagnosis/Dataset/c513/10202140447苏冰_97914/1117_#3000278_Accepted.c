#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
    long long x,y;
    long long dis;
}sss;
int cmp(const void*_a,const void*_b)
{
    sss* a=(sss*)_a;
    sss* b=(sss*)_b;
    if(a->dis!=b->dis) return (a->dis)>(b->dis)?1:-1;
    else if(a->x!=(b->x)) return (a->x)>(b->x)?1:-1;
    else return (a->y)>(b->y)?1:-1;
}
int main()
{
    long long x,y;
    scanf("%lld%lld",&x,&y);
    int n;
    scanf("%d",&n);
    sss s[1000001];
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&s[i].x,&s[i].y);
        s[i].dis=llabs(x-s[i].x)>llabs(y-s[i].y)?llabs(x-s[i].x):llabs(y-s[i].y);
    }
    qsort(s,n,sizeof(sss),cmp);
    printf("%lld\n%lld %lld\n",s[0].dis,s[0].x,s[0].y);
    return 0;
}
