#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void *q1,const void *q2)
{
    return *(long long *)q2-*(long long *)q1;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    long long a[100001]={0};
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(long long),cmp);
    long long b[100000]={0};
    for(int i=0;i<n-1;i++)
    {
        b[i]=a[i]-a[i+1];
    }
    long long s=0;
    for(int i=0;i<m-1;i++)
    {
        s+=b[i]*(m-i-1);
    }
    long long min=s;
    for(int i=0;i<n-m;i++)
    {
        s-=b[i]*(m-1);
        s+=(a[i+1]-a[i+m]);
        if(s<min) min=s;
    }
    printf("%lld",min);
    return 0;
}

