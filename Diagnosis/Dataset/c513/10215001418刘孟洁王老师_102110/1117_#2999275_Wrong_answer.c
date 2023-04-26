#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{long long x,y,distance;}point;

int cmp(const void*a,const void*b)
{
    point c = *(point*)a;
    point d = *(point*)b;
    if(c.distance < d.distance)return -1;
    else if(c.distance < d.distance)return 1;
    else if(c.x < d.x)return -1;
    else if(c.x > d.x)return 1;
    else if(c.y < d.y)return -1;
    else return 1;
}

int main()
{
    int i,n;
    long long x0,y0,dx,dy;
    point *s;
    scanf("%lld%lld",&x0,&y0);
    scanf("%d",&n);
    s = (point*)malloc(n*sizeof(point));
    for(i = 0; i < n; i++)
    {
        scanf("%lld%lld",&s[i].x,&s[i].y);
        dx = llabs(s[i].x-x0);
        dy = llabs(s[i].y-y0);
        s[i].distance = dx > dy? dx: dy;
    }
    qsort(s,n,sizeof(s[0]),cmp);
    printf("%lld\n%lld %lld\n",s[0].distance,s[0].x,s[0].y);
    return 0;
}
