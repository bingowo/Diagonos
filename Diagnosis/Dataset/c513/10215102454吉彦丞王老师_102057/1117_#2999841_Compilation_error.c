#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long int max(long long a,long long b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
struct data
{
    long long int x;
    long long int y;
    long long int distance;
}
int cmp(const void *pa,const void *pb)
{
    struct data a,b;
    a=*((struct data *)pa);
    b=*((struct data *)pb);
    if(a.distance==b.distnce)
    {
        if(a.x==b.x)
        {
            return a.y-b.y>=0?1:-1;
        }
        else
        {
            return a.x-b.x>=0?1:-1;
        }
    }
    else
    {
        return a.distance-b.distance>=0:1:-1;
    }
}
int main()
{
    int x0,y0;
    scanf("%d%d",&x0,&y0);
    int number;
    scanf("%d",&number);
    struct data p[number];
    for(int i=0;i<number;i++)
    {
        scanf("%lld%lld",&p[i].x,&p[i].y);
        p[i].distance=max(abs(p[i].x-x0),abs(p[i].y-y0));
    }
    qsort(p,number,sizeof(p[0]),cmp);
    printf("%lld\n",p[0].distance);
    printf("%lld %lld",p[0].x,p[0].y);
    return 0;
}