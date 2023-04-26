#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point{
        long long int x;
        long long int y;
};

struct point o;

int main()
{
    long long int judge(struct point a,struct point b);
    int cmp(const void *a1,const void *b1);
    long long int man(struct point a,struct point b);
    int n;
    long long int ans0;
    struct point o;
    o.x=0;
    o.y=0;
    struct point a[100];
    scanf("%d",&n);
    for(int z=0;z<n;z++)
    {
        scanf("%lld %lld",&a[z].x,&a[z].y);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    ans0=man(a[0],a[1]);
    printf("%lld\n",ans0);

    long long int sum=0;
    for(int z=0;z<n-1;z++)
    {
        if(judge(a[z],a[z+1])==0) break;
        sum+=judge(a[z],a[z+1]);
    }
    printf("%lld",sum);
    return 0;
}

long long int man(struct point a,struct point b)
{
    long long ans;
    long long x0,y0;
    x0=(a.x-b.x>0)?(a.x-b.x):(b.x-a.x);
    y0=(a.y-b.y>0)?(a.y-b.y):(b.y-a.y);
    return x0+y0;
}

int cmp(const void *a1,const void *b1)
{
    struct point o;
    o.x=0;
    o.y=0;
    long long man(struct point a,struct point b);
    struct point a=*(struct point*)a1;
    struct point b=*(struct point*)b1;
    if(man(a,o)>man(b,o)) return -1;
    else if(man(a,o)<man(b,o)) return 1;
    else
    {
        if(a.x>b.x) return 1;
        else if(a.x<b.x) return -1;
        else{
            if(a.y>b.y) return 1;
            else if(a.y<b.y) return -1;
        }
    }
}

long long int judge(struct point a,struct point b)
{
    long long man(struct point a,struct point b);
    long long int l;
    long long int sum=0;
    long long int sum1=0;
    l=man(a,b);
    long long int step;
    int flag=0;
    int j=0;
    if(l%2==1) flag=1;
    else if(l%2==0) return 0;
    long long int sq=1;
    if(flag==1)
    {
        while(1)
        {
            if(j!=0) sq*=2;
            sum+=sq;
            if(l>=sum1&&l<=sum) step=j+1;break;
            sum1+=sq;
            j++;
        }
    }
    return step;
}
