#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    long long int r,h,d,c;
} t;
int cmp(const void *a,const void *b)
{
    t* x=(t*)a;
    t* y=(t*)b;
    if (y->c>x->c)
        return 1;
    else if(y->c==x->c)
    {
        if (y->r>x->r)
        {
            return 1;
        }
    }
    else
        return -1;
}
long long int max(long long x,long long y)
{
    if(x>y)
        return x;
    else
        return y;
}
int main()
{
    int n,m;
    long long int maxn=-1;
    scanf("%d%d",&n,&m);
    t* a=(t*)malloc(sizeof(t)*n);
    for (int i=0; i<n; i++)
    {
        scanf("%lld %lld",&a[i].r,&a[i].h);
        a[i].d=a[i].r*a[i].r;
        a[i].c=2*a[i].r*a[i].h;
    }
    qsort(a,n,sizeof(t),cmp);
    for(int i=0; i<n; i++)
    {
        long long ans=a[i].c+a[i].d;
        int cnt=1;
        for (int j=0; j<n&&cnt<m; j++)
        {
            if(i==j||a[i].r<a[j].r)
                continue;
            ans+=a[j].c;
            cnt++;
        }
        maxn=max(maxn,ans);
    }
    free(a);
    printf("%lld",maxn);
    return 0;

}
