#include<stdio.h>

long long cmp(const void *q1,const void *q2)
{
    long long *p1=(long long *)q1;
    long long *p2=(long long *)q2;
    if(*p1>*p2) return 1;
    else return -1;
}

int main()
{
    int n;
    scanf("%d",&n);
    long long L[100010]={0};
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&L[i]);
    }
    qsort(L,n,sizeof(long long),cmp);
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=(L[2*i+1]-L[2*i]);
    }
    printf("%lld",ans);
    return 0;
}
