#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a,const void* b)
{
    long long x=*(long long*)a;
    long long y=*(long long*)b;
    if(x>y) return -1;
    return 1;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long ans[100000];
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&ans[i]);
    }
    qsort(ans,n,sizeof(ans[0]),cmp);
    long long minn=ans[0]*(m-1);
    for(int i=0;i<=n-m;i++)
    {
        long long temp=ans[i]*(m-1);
        for(int j=1;j<=m;j++)
        {
            temp=temp-ans[i+j];
        }
        if(temp<minn) minn=temp;
    }
    printf("%lld",minn);
}
