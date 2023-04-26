#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

typedef struct {long long x,y,d;} point;

int getstep(point a,point b)
{
    long long dis = abs(a.x-b.x)+abs(a.y-b.y);
    if (dis%2==0) return 0;
    int i = 0, mul = 1;
    while (dis-mul>=0) {i++; mul <<= 1;}
    return i;
}

int cmp(const void* a,const void* b)
{
    point* c = (point*)a; point* d = (point*)b;
    if (c->d!=d->d) return (c->d>=d->d)?-1:1;
    if (c->x!=d->x) return (c->x>=d->x)?1:-1;
    return (c->y>=d->y)?1:-1;
}

main()
{
    int n;
    scanf("%d",&n);
    point* s = (point*)malloc(2*n*sizeof(point));
    for (int i=0;i<n;i++)
    {
        scanf("%lld %lld",&s[i].x,&s[i].y);
        s[i].d = abs(s[i].x)+abs(s[i].y);
    }
    qsort(s,n,sizeof(s[0]),cmp);
    int steps = 0;
    for (int i=0;i<n-1;i++)
    {
        if (getstep(s[i],s[i+1])!=0) steps += getstep(s[i],s[i+1]);
        else break;
    }
    printf("%lld\n%d\n",abs(s[0].x-s[1].x)+abs(s[0].y-s[1].y),steps);
    return 0;
}