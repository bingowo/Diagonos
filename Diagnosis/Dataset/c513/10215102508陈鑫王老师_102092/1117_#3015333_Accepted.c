#include<stdio.h>
#include<stdlib.h>
typedef long long int lli;
typedef struct
{
    lli x;
    lli y;
    lli ret;
}point;
lli abslli(lli a)
{
    return a<0?-a:a;
}
lli ma(lli x,lli y,lli x0,lli y0)
{
    lli x1=abslli(x-x0);
    lli y1=abslli(y-y0);
    return x1>y1?x1:y1;
}
int cmp(const void *a,const void*b)
{
    point*x=(point*)a;
    point*y=(point*)b;
    if(x->ret!=y->ret)
    {
        return x->ret<y->ret?-1:1;
    }
    else if(x->x!=y->x)
    {
        return x->x<y->x?-1:1;
    }
    else
        return x->y<y->y?-1:1;
}
int main()
{
    lli x0,y0;
    scanf("%lld %lld",&x0,&y0);
    int n;
    scanf("%d",&n);
    point ans[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&ans[i].x,&ans[i].y);
        ans[i].ret=ma(ans[i].x,ans[i].y,x0,y0);
    }
    qsort(ans,n,sizeof(ans[0]),cmp);
    printf("%lld\n",ans[0].ret);
    printf("%lld %lld",ans[0].x,ans[0].y);
    return 0;
}
