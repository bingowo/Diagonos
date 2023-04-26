#include<stdio.h>
#include<stdlib.h>
typedef unsigned long long ll;
int cmp(const void* a,const void* b)
{
    ll x=*(ll*)a;
    ll y=*(ll*)b;
    if(x>y) return -1;
    return 1;
}
ll ans[1000000]={0};
int main()
{
    ll n,m;
    scanf("%llu %llu",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%llu",&ans[i]);
    }
    qsort(ans,n,sizeof(ans[0]),cmp);
    ll minn=ans[0]*(m-1);
    for(int i=0;i<=n-m;i++)
    {
        ll temp=ans[i]*(m-1);
        for(int j=1;j<m;j++)
        {
            temp=temp-ans[i+j];
        }
        if(temp<minn) minn=temp;
    }
    printf("%llu",minn);
}
