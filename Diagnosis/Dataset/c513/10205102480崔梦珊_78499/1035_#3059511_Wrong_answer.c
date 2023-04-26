#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct zz
{
    long long r;
    long long h;
    long long d;
    long long c;
    long long v;
};

int cmp(const void* a,const void* b)
{
    struct zz* x=(struct zz*)a;
    struct zz* y=(struct zz*)b;
    return y->c-x->c;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    struct zz ans[1001];
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&ans[i].r,&ans[i].h);
        ans[i].d=pow(ans[i].r,2);
        ans[i].c=ans[i].r*2*ans[i].h;
        ans[i].v=ans[i].d+ans[i].c;
    }
    qsort(ans,n,sizeof(ans[0]),cmp);
    long long maxn=0;
    for(int i=0;i<n;i++)
    {
        long long res=ans[i].c+ans[i].d;
        int count1=1;
        for(int j=0;j<n&&count1<m;j++)
        {
            if(i==j||ans[i].r<ans[j].r)    continue;
            res+=ans[j].c;
            count1++;
        }
        if(count1==m)
        {
        if(res>maxn)
        {
            maxn=res;
        }
        }
    }
    printf("%lld",maxn);
}
