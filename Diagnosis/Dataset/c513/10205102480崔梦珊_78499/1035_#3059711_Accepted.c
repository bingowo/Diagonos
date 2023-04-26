#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef unsigned long long ll;
struct z
{
    ll r;
    ll h;
    ll d;
    ll c;
    ll v;
};
int cmp(const void* a,const void* b)
{
    struct z* x=(struct z*)a;
    struct z* y=(struct z*)b;
    if(x->c>y->c)return -1;
    return 1;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    struct z ans[1001];
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&ans[i].r,&ans[i].h);
        ans[i].d=ans[i].r*ans[i].r;
        ans[i].c=ans[i].r*ans[i].h*2;
        ans[i].v=ans[i].c+ans[i].d;
    }
    qsort(ans,n,sizeof(ans[0]),cmp);
    ll maxn=0;
    for(int i=0;i<n;i++)
    {
        ll res=ans[i].v;
        ll cnt=1;
        for(int j=0;j<n&&cnt<m;j++)
        {
            if(i==j||ans[i].r<ans[j].r) continue;
            res=res+ans[j].c;
            cnt++;
        }
        if(cnt==m)
        {
            if(maxn<res) maxn=res;
        }
    }
    printf("%lld",maxn);
}
