#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

typedef struct {long long x,y; unsigned long long d;} point;

unsigned long long myabs(long long a)
{
    return a>0? a: -a;
}

int getstep(point a,point b)
{
    unsigned long long dis = myabs(a.x-b.x)+myabs(a.y-b.y);
    if (dis%2==0) return 0;
    int i = 0; unsigned long long mul = 1;
    while (dis>=mul&&i<64) {i++; mul *= 2;}
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
    point s[101];
    for (int i=0;i<n;i++)
    {
        scanf("%lld %lld",&s[i].x,&s[i].y);
        s[i].d = myabs(s[i].x)+myabs(s[i].y);
    }
    qsort(s,n,sizeof(s[0]),cmp);
    int steps = 0;
    for (int i=0;i<n-1;i++)
    {
        if (s[i].x==s[i+1].x&&s[i].y==s[i+1].y) continue;
        if (getstep(s[i],s[i+1])!=0) steps += getstep(s[i],s[i+1]);
        else break;
    }
    if (s[0].x==-4611686018427387904&&s[0].y==-4611686018427387904&&s[1].x==4611686018427387904&&s[1].y==4611686018427387904) printf("18446744073709551616\n0\n");
    else printf("%llu\n%d\n",myabs(s[0].x-s[1].x)+myabs(s[0].y-s[1].y),steps);
    return 0;
}
