#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000005

typedef struct{long long x,y,dist;}point;

long long Max(long long a,long long b){return a>b?a:b;}

long long llabs(long long a)
{
    return a>0?a:-a;
}

long long Dis(point a,point b)
{
    return Max(llabs(a.x-b.x),llabs(a.y-b.y));
}

int cmp(const void* a,const void* b)
{
    point* pa=(point*)a;
    point* pb=(point*)b;
    if(pa->dist!=pb->dist)return pa->dist>pb->dist?1:-1;
    else if(pa->x!=pb->x)return pa->x>pb->x?1:-1;
    else if(pa->y!=pb->y)return pa->y>pb->y?1:-1;
}

int main()
{
    point org;point p[N];
    scanf("%lld %lld",&org.x,&org.y);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lld %lld",&p[i].x,&p[i].y);
        p[i].dist=Dis(org,p[i]);
    }
    qsort(p,n,sizeof(p[0]),cmp);
    printf("%lld\n%lld %lld\n",p[0].dist,p[0].x,p[0].y);
    return 0;
}
