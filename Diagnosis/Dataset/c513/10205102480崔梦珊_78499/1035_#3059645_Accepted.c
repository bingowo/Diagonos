#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef unsigned long long ll;
struct zz
{
    ll r;
    ll h;
    ll d;
    ll c;
    ll v;
};

int cmp(const void* a,const void* b)
{
    struct zz* x=(struct zz*)a;
    struct zz* y=(struct zz*)b;
    if(y->c<x->c) return -1;
    else
    {
        return 1;
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    struct zz ans[1001];
    /*for(int i=0;i<1001;i++)
    {
        ans[i].r=0;
        ans[i].h=0;
        ans[i].d=0;
        ans[i].c=0;
        ans[i].v=0;
    }*/
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&ans[i].r,&ans[i].h);
        ans[i].d=pow(ans[i].r,2);
        ans[i].c=ans[i].r*2*ans[i].h;
        ans[i].v=ans[i].d+ans[i].c;
    }
    qsort(ans,n,sizeof(ans[0]),cmp);
    ll maxn=0;
    for(int i=0;i<n;i++)
    {
        ll temp=ans[i].v;
        int count1=1;
        for(int j=0;j<n&&count1<m;j++)
        {
            if(i==j||ans[i].r<ans[j].r)    continue;
            temp+=ans[j].c;
            count1++;
        }
        if(count1==m)
        {
            if(temp>=maxn)
            {
                maxn=temp;
            }
        }
    }
    printf("%lld",maxn);
}
