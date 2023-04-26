#include<stdio.h>
#include<stdlib.h>

long long r[1001];
long long h[1001];
long long s[1001];


int cmp(const void* a,const void* b)
{
    int x=*(int*)a;
    int y=*(int*)b;
    if(r[y]>r[x])return 1;
    else if(r[y]==r[x])return 0;
    else if(r[y]<r[x])return -1;
}

int cmp1(const void* a,const void* b)
{
    long long x=*(long long*)a;
    long long y=*(long long*)b;
    if(y>x)return 1;
    else if(y==x)return 0;
    else if(y<x)return -1;
}

int main()
{
    int n,m;
    int num[1001];
    long long ans=0,tem=0;
    long long ts[1001];
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&r[i],&h[i]);
        num[i]=i;
        s[i]=2*r[i]*h[i];
    }
    qsort(num,n,sizeof(num[0]),cmp);
    for(int i=0;i<(n-m+1);i++)
    {
        tem=s[num[i]]+r[num[i]]*r[num[i]];
        if(m>1){
        for(int j=0;j<n-i-1;j++)ts[j]=s[num[j+i+1]];
        qsort(ts,n-i-1,sizeof(ts[0]),cmp1);
        for(int j=0;j<(m-1);j++)tem+=ts[j];
        }
        if(ans<tem)ans=tem;
    }
    
    printf("%lld",ans);
    return 0;
}