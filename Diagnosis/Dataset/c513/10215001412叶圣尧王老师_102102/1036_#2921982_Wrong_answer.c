#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct st
{
    long long int x;
    long long int y;
    long long int d;
};

int cmp(const void*a,const void*b)
{
    struct st*c=(struct st*)a;
    struct st*e=(struct st*)b;
    if(c->d!=e->d)return e->d-c->d;
    else if(c->x!=e->x)return c->x-e->x;
    else return c->y-e->y;
}

long long confer(long long x1,long long y1)
{
    int m=0;
    while(x1!=0||y1!=0)
    {
        if(x1%2==1&&y1%2==0)
        {
            if(((x1+1)/2+y1/2)%2==1)x1++;
            else x1--;
            x1/=2;y1/=2;m++;
        }
        else if(x1%2==0&&y1%2==1)
        {
            if(((y1+1)/2+x1/2)%2==1)y1++;
            else y1--;
            x1/=2;y1/=2;m++;
        }
        else break;
    }
    return m;
}

int main()
{
    int n,t,i;scanf("%d",&n);struct st k[n];
    for(t=0;t<n;t++)
    {
        scanf("%lld %lld",&k[t].x,&k[t].y);
        k[t].d=labs(k[t].x)+labs(k[t].y);
    }
    qsort(k,n,sizeof(struct st),cmp);
    printf("%lld\n",labs(k[0].x-k[1].x)+labs(k[0].y-k[1].y));
    long long x1,y1,step=0;
    for(i=0;i<n-1;i++)
    {
        x1=labs(k[i].x-k[i].x);
        y1=labs(k[i].y-k[i].y);
        step=confer(x1,y1);
    }
    printf("%lld",step);
}