#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a,const void* b)
{
    long long x=*(long long*)a;
    long long y=*(long long*)b;
    if(x>y) return 1;
    return -1;
}
long long ans[100001];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<=n;i++)
    {
        scanf("%lld",&ans[i]);
    }
    qsort(ans,n,sizeof(ans[0]),cmp);
    long long res=ans[m-1]*(m-1);
    for(int i=0;i<m-1;i++)
    {
        res=res-ans[i];
    }
    long long temp=res;
    for(int i=m;i<n;i++)
    {
        temp=temp+(ans[i]-ans[i-1])*(m-1)+ans[i-m];
        temp=temp-ans[i-1];
        if(temp<res) res=temp;
    }
    printf("%lld",res);
}
